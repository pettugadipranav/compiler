%{
#include<bits/stdc++.h>
#include "sym_table.h"
using namespace std;
char *arr;
int ret_no;
extern int yylex(void);
extern int yylineno;
void yyerror(const char *s);
extern FILE* yyin;
extern FILE *token_fp;
extern FILE *cpp_fp;
extern int l_no;
list <args> argmnt_list;
list <pair<short int, bool>> argmnt_chck_list; 
pair<short int,bool> return_type;
int scope=0;
char *global_int = string_to_char("");
char *global_double = string_to_char("");
char *global_cint = string_to_char("");
char *global_cdouble = string_to_char("");
int main_check=0;
int p_check=0;
%}

%union {
    
    char* name;
    bool type;
    short int datatype;
    struct {
        bool ret_type_bool;
        short int ret_datatype;
    } ret_type;
    struct{
        char* arg_name;
        bool arg_type_bool;
    }arg_name_type;
    struct{
        char* name1;
        short int datatype;
        bool arr_type;
    }datatype_arg;
    struct{
        short int data_type;
        bool type;
        char * name;
    } exp_rhs_attr;
    struct{
        short int data_type;
        bool type;
        char * name;
    } exp_lhs_attr;
    struct{
        short int data_type;
        bool type;
        char*name;
    } assign_rhs_attr;
        struct {
        short int data_type;
        char *name;
    } pred_struct;
    struct {
        bool ret_type_bool;
        short int ret_datatype;
        char *name;        
    } d_type_arg;
}
%token REAL_DEC IMAG_DEC ITER PRINT UNTIL RETURN REM NEQ OR NEG AND
%token INT CINT CDOUBLE  DOUBLE STR  BIN VOID
%token CHOICE ALT DEFAULT
%token <name> ID STRING
%token SEMICOL COMMA COLON QUOTE ACCESS_OP2
%token GT LT EQ NE INC DEC ASSIGN LE GE
%token <name> INT_NUM DOUBLE_NUM ARITH_OP MINUS
%token INN_PROD IMAG_INC REAL_INC
%token OPEN_CIR_PAR CLOSE_CIR_PAR OPEN_CURLY_PAR CLOSE_CURLY_PAR OPEN_SQUARE_PAR CLOSE_SQUARE_PAR
%left ARITH_OP GT LT EQ NE GE LE AND OR NEG MINUS
%type <type> data_type_arr
%type <datatype> data_type
%type <name> func_name
%type <d_type_arg> d_type
%type <datatype_arg> T
%type <arg_name_type> L
%type <datatype_arg> int_id_type
%type <datatype_arg> double_id_type
%type <exp_rhs_attr> exp_rhs
%type <exp_rhs_attr> all_exp_rhs fn_args
%type <exp_rhs_attr> fn_call
%type <datatype> assign_stmt 
%type <datatype> inc_stmt_lhs
%type <datatype> print_fn
%type <pred_struct> predicate
%type <exp_lhs_attr> exp_lhs
%type <assign_rhs_attr> assign_rhs
%type <name> int_part
%type <name> double_part
%type <name> cint_part
%type <name> cdouble_part
%type <name> argument print_arg
%%
program : func_stmt program
        | /*Epsilon*/
        ;
stmts : stmt_types stmts
      | /* Epsilon */
      ;
stmt_types : assign_stmt SEMICOL 
           | decl_stmt SEMICOL
           | if_stmt
           | for_stmt 
           | while_stmt 
           | return_stmt SEMICOL  
           | void_fn_calls SEMICOL    
           | inc_stmt SEMICOL{fprintf(cpp_fp,";");}
           | print_fn SEMICOL 
           ;

func_stmt : func_info OPEN_CURLY_PAR stmts CLOSE_CURLY_PAR {
                                                            delete_loc_sym_tab_map();
                                                            delete_loc_sym_tab_map();
                                                            scope=0;
                                                            fprintf(cpp_fp,"}\n");
                                                            }
          ;
func_info:func_name d_type COLON OPEN_CIR_PAR argument CLOSE_CIR_PAR{ 
                                                                        if(!search_fn_sym_tab($1)){ 
                                                                                if(string($1)=="main"){
                                                                                    if($<d_type_arg.ret_datatype>2!=1){
                                                                                      yyerror("main function must return int");
                                                                                    }
                                                                                    else if($<d_type_arg.ret_type_bool>2!=false){
                                                                                      yyerror("main function must return int");
                                                                                    }
                                                                                    else if(argmnt_list.size()!=0){
                                                                                      yyerror("main should not have parameters");
                                                                                    }
                                                                                    main_check=1;
                                                                                    // cout<<"main_checkkerrrrrrrr insert"<<main_check<<endl;
                                                                                }    
                                                                                // cout<<scope<<"scope"<<endl;                                                                          
                                                                                return_type.first=$2.ret_datatype;
                                                                                return_type.second=$2.ret_type_bool;
                                                                                insert_fn_sym_tab($1,return_type,argmnt_list);
                                                                                scope++;
                                                                                create_loc_sym_tab_map();
                                                                                insert_param_into_loc(argmnt_list);
                                                                                argmnt_list.clear();
                                                                                scope++;
                                                                                create_loc_sym_tab_map();
                                                                        }
                                                                        else{
                                                                                yyerror("Function already declared");
                                                                        }
                                                                        fprintf(cpp_fp,"%s %s(%s) {\n",$<d_type_arg.name>2, $1, $5);

                                                                    }   
                                                                    
        ;
func_name: ID  {$$=$1;}
     ;
d_type : data_type data_type_arr { $<d_type_arg.ret_type_bool>$=$2;
                                   $<d_type_arg.ret_datatype>$=$1;
                                   char *dtype;
                                        if($1 == 0)
                                        dtype = string_to_char("void ");
                                        else if($1 == 1)
                                        dtype = string_to_char("int ");
                                        else if($1 == 2)
                                        dtype = string_to_char("pair<int, int> ");
                                        else if($1 == 3)
                                        dtype = string_to_char("double ");
                                        else if($1 == 4)
                                        dtype = string_to_char("pair<double,double> ");
                                    if($2 == true){
                                        char*temp1=string_to_char("*");
                                        $<d_type_arg.name>$=concater(dtype,temp1);
                                    }
                                    else{
                                        $<d_type_arg.name>$=dtype;
                                    }
                              }
       ;

data_type :VOID{$$=0;  }| INT {$$=1; } | CINT {$$=2; } | DOUBLE {$$=3; } | CDOUBLE {$$=4; }
          ;
data_type_arr : OPEN_SQUARE_PAR CLOSE_SQUARE_PAR {$$=true;}
              | /* epsilon*/ {$$=false;}
              ;

if_stmt_scope1 : CHOICE OPEN_CIR_PAR exp_rhs CLOSE_CIR_PAR OPEN_CURLY_PAR { 
                                            scope++;
                                            create_loc_sym_tab_map(); 
                                            cout<<"qwerty===="<<$<exp_rhs_attr.name>3<<endl;
                                            fprintf(cpp_fp,"if(%s) {\n",$<exp_rhs_attr.name>3);
                                        }
               ;
elseif_stmt_scope1 : ALT OPEN_CIR_PAR exp_rhs CLOSE_CIR_PAR OPEN_CURLY_PAR{ 
                                            scope++;
                                            create_loc_sym_tab_map(); 

                                            fprintf(cpp_fp,"else if(%s) {\n",$<exp_rhs_attr.name>3);
                                        }
               ;
if_body: stmts CLOSE_CURLY_PAR{ scope--; delete_loc_sym_tab_map(); fprintf(cpp_fp,"}");}
            ;
if_stmt :  if_stmt_scope1 if_body elif_stmt {  }
        |  if_stmt_scope1 if_body elif_stmt else_stmt stmts CLOSE_CURLY_PAR {delete_loc_sym_tab_map();scope--;
                                                                                        fprintf(cpp_fp,"}");}
        // | CHOICE OPEN_CIR_PAR predicate CLOSE_CIR_PAR OPEN_CURLY_PAR stmt_types CLOSE_CURLY_PAR elif_stmt
        ;
/* special case of else if statements */
elif_stmt : elseif_stmt_scope1 if_body elif_stmt //{delete_loc_sym_tab_map();}// delete_loc_sym_tab_map(); }
          | /* Epsilon */
          ;
else_stmt : DEFAULT OPEN_CURLY_PAR { scope++; create_loc_sym_tab_map(); 
                                    fprintf(cpp_fp,"else{\n");}
           ;
           /*roh */
inc_stmt : inc_stmt_lhs inc_stmt_rhs {if($1!=2 && $1!=4) yyerror("invalid operation");}
         | inc_stmt_lhs INC {if($1!=1 && $1!=3 && $1!=5) yyerror("invalid operation");  fprintf(cpp_fp,"++");}
         | inc_stmt_lhs DEC {if($1!=1 && $1!=3 && $1!=5) yyerror("invalid operation");  fprintf(cpp_fp,"--");}
         ;
inc_stmt_rhs : REAL_INC {fprintf(cpp_fp,".first++");}
            | IMAG_INC {fprintf(cpp_fp,".second++");}
            | REAL_DEC {fprintf(cpp_fp,".first--");}
            | IMAG_DEC {fprintf(cpp_fp,".second--");}
             ;
inc_stmt_lhs:ID { args* sp;
                sp=search_id_loc_sym_tab($1,scope);
                if(!sp) yyerror("variable not declared");
                  if(sp->dat_type.second == 0){
                        $$=sp->dat_type.first;
                  }
                  else yyerror("invalid operation");
                //   $<exp_rhs_attr.type>$=false;
                fprintf(cpp_fp,"%s",$1);
                }
            | ID OPEN_SQUARE_PAR exp_rhs CLOSE_SQUARE_PAR { 
                                                        if($<exp_rhs_attr.data_type>3==1 || $<exp_rhs_attr.data_type>3==5){
                                                            args* sp=new args;
                                                            sp=search_id_loc_sym_tab($1,scope);
                                                            if(!sp) yyerror("variable not declared");
                                                            else{
                                                                if(sp->dat_type.second == 0){
                                                                $$=sp->dat_type.first;
                                                                }
                                                                else yyerror("invalid operation");
                                                            }
                                                        }
                                                        else yyerror("Array index must be integer");
                                                        fprintf(cpp_fp,"%s[%s]",$1,$<exp_rhs_attr.name>3);
                                                        }
            ;

all_exp_rhs : exp_rhs { $<exp_rhs_attr.data_type>$=$<exp_rhs_attr.data_type>1;
                        $<exp_rhs_attr.type>$=$<exp_rhs_attr.type>1;
                        $<exp_rhs_attr.name>$=$<exp_rhs_attr.name>1;
                        }
            | MINUS exp_rhs { $<exp_rhs_attr.data_type>$=$<exp_rhs_attr.data_type>2;
                        $<exp_rhs_attr.type>$=$<exp_rhs_attr.type>2;
                        char*temporary=string_to_char("-");
                        $<exp_rhs_attr.name>$=concater(temporary,$<exp_rhs_attr.name>2);
                        }
            ;

for_stmt: iter
        ;
while_stmt: until
          ;
decl_stmt : var_decl {/*Note above 4 are wrtitten for testing only*/}
          ;
void_fn_calls : fn_call{fprintf(cpp_fp,"%s;",$<exp_rhs_attr.name>1);}
              ;
// assign_g: ASSIGN {fprintf(cpp_fp,"=");}
//         ;
/* */
assign_stmt : exp_lhs ASSIGN assign_rhs{
                                        if(!comp_assign_checker($<exp_lhs_attr.data_type>1,$<assign_rhs_attr.data_type>3,$<exp_lhs_attr.type>1,$<assign_rhs_attr.type>3)){
                                                yyerror("Type mismatch");
                                        }
                                        else{
                                                fprintf(cpp_fp,"%s",$<exp_lhs_attr.name>1);
                                                fprintf(cpp_fp," = ");
                                                fprintf(cpp_fp,"%s;",$<assign_rhs_attr.name>3);
                                        }
                                        }
            ;

exp_lhs : ID { args* sp=new args;
               sp=search_id_loc_sym_tab($1,scope);
               if(!sp) yyerror("variable not declared");
               $<exp_lhs_attr.data_type>$=sp->dat_type.first;
               $<exp_lhs_attr.type>$=sp->dat_type.second;
                $<exp_lhs_attr.name>$=$1;
                // fprintf(cpp_fp,"%s",$1);
                
             }
        | ID OPEN_SQUARE_PAR exp_rhs CLOSE_SQUARE_PAR{ args* sp=new args;
                if($<exp_rhs_attr.data_type>3   !=1){
                        yyerror("Array index must be integer");
                }
                sp=search_id_loc_sym_tab($1,scope);
                if(!sp) yyerror("variable not declared");
                $<exp_lhs_attr.data_type>$=sp->dat_type.first;
                $<exp_lhs_attr.type>$=false;
                char*temporary1=string_to_char("[");
                char*temporary2=string_to_char("]");
                $<exp_lhs_attr.name>$=concater($1,temporary1,$<exp_rhs_attr.name>3,temporary2);
                // fprintf(cpp_fp,"]");
                
             }
        ;
assign_rhs : exp_rhs {$<assign_rhs_attr.data_type>$=$<exp_rhs_attr.data_type>1;
                        $<assign_rhs_attr.type>$=$<exp_rhs_attr.type>1;
                        // fprintf(cpp_fp,"%s",$<exp_rhs_attr.name>1);
                        // fprintf(cpp_fp,"hello");
                        // cout<<"qwerty-=-=-=-"<<$<exp_rhs_attr.name>1<<endl;
                        $<assign_rhs_attr.name>$=$<exp_rhs_attr.name>1;
                        // string a($<exp_rhs_attr.name>1);
                        // cout<<"YES"<<(int)a[0]<<endl;
                        }
           | MINUS exp_rhs {$<assign_rhs_attr.data_type>$=$<exp_rhs_attr.data_type>2;
                        $<assign_rhs_attr.type>$=$<exp_rhs_attr.type>2;
                        char *temp=string_to_char("-");
                        $<assign_rhs_attr.name>$=concater(temp,$<exp_rhs_attr.name>2);
                        }
           ;
        
return_stmt : RETURN exp_rhs{if($<exp_rhs_attr.data_type>2==return_type.first && $<exp_rhs_attr.type>2 == return_type.second){}
                             else{
                                        yyerror("return type mismatch");
                             }  
                             fprintf(cpp_fp,"return %s;",$<exp_rhs_attr.name>2);
                              }
            |RETURN{if(return_type.first==0 && return_type.second==false){}
                    else{
                        yyerror("return type mismatch");
                    }
                    fprintf(cpp_fp,"return;");
                    }
            ;

predicate : exp_rhs GT exp_rhs {
                                    if($<exp_rhs_attr.type>1==true) yyerror("Expected ID but found array");
                                    else {
                                        if(only_real_comp($<exp_rhs_attr.data_type>1,$<exp_rhs_attr.data_type>3)){
                                            $<pred_struct.data_type>$=5;
                                            char*tempy=string_to_char(">");
                                            $<pred_struct.name>$=concater($<exp_rhs_attr.name>1,tempy,$<exp_rhs_attr.name>3);
                                        }
                                        else{
                                            yyerror("Invalid datatypes for comparison, expected both to be real numbers but found complex numbers");
                                        }
                                    }
                                    }
          | exp_rhs LT exp_rhs{
                                    if($<exp_rhs_attr.type>1==true) yyerror("Expected ID but found array");
                                    else {
                                        if(only_real_comp($<exp_rhs_attr.data_type>1,$<exp_rhs_attr.data_type>3)){
                                            $<pred_struct.data_type>$=5;
                                            char*tempy=string_to_char("<");
                                            $<pred_struct.name>$=concater($<exp_rhs_attr.name>1,tempy,$<exp_rhs_attr.name>3);
                                        }
                                        else{
                                            yyerror("Invalid datatypes for comparison, expected both to be real numbers but found complex numbers");
                                        }
                                    }
                                    }
          | exp_rhs EQ exp_rhs{
                                    if($<exp_rhs_attr.type>1==true) yyerror("Expected ID but found array");
                                    else {
                                        if(same_type_comp($<exp_rhs_attr.data_type>1,$<exp_rhs_attr.data_type>3)){
                                            $<pred_struct.data_type>$=5;
                                            char*tempy=string_to_char("==");
                                            $<pred_struct.name>$=concater($<exp_rhs_attr.name>1,tempy,$<exp_rhs_attr.name>3);
                                        }
                                        else{
                                            yyerror("Invalid datatypes for comparison, expected both to be real numbers or both complex numbers");
                                        }
                                    }
                                    }
          | exp_rhs NE exp_rhs{
                                    if($<exp_rhs_attr.type>1==true) yyerror("Expected ID but found array");
                                    else {
                                        if(same_type_comp($<exp_rhs_attr.data_type>1,$<exp_rhs_attr.data_type>3)){
                                            $<pred_struct.data_type>$=5;
                                            char*tempy=string_to_char("!=");
                                            $<pred_struct.name>$=concater($<exp_rhs_attr.name>1,tempy,$<exp_rhs_attr.name>3);
                                        }
                                        else{
                                            yyerror("Invalid datatypes for comparison, expected both to be real numbers or both complex numbers");
                                        }
                                    }
                                    }
          | exp_rhs GE exp_rhs{     
                                    if($<exp_rhs_attr.type>1==true) yyerror("Expected ID but found array");
                                    else {
                                        if(only_real_comp($<exp_rhs_attr.data_type>1,$<exp_rhs_attr.data_type>3)){
                                            $<pred_struct.data_type>$=5;
                                            char*tempy=string_to_char(">=");
                                            $<pred_struct.name>$=concater($<exp_rhs_attr.name>1,tempy,$<exp_rhs_attr.name>3);
                                        }
                                        else{
                                            yyerror("Invalid datatypes for comparison, expected both to be real numbers but found complex numbers");
                                        }
                                    }
                                    }
          | exp_rhs LE exp_rhs{
                                    if($<exp_rhs_attr.type>1==true) yyerror("Expected ID but found array");
                                    else {
                                        if(only_real_comp($<exp_rhs_attr.data_type>1,$<exp_rhs_attr.data_type>3)){
                                            $<pred_struct.data_type>$=5;

                                            char*tempy=string_to_char("<=");
                                            $<pred_struct.name>$=concater($<exp_rhs_attr.name>1,tempy,$<exp_rhs_attr.name>3);
                                        }
                                        else{
                                            yyerror("Invalid datatypes for comparison, expected both to be real numbers but found complex numbers");
                                        }
                                    }
                                    }
          | exp_rhs AND exp_rhs{
                                    if($<exp_rhs_attr.type>1==true) yyerror("Expected ID but found array");
                                    else {
                                        if(same_type_comp($<exp_rhs_attr.data_type>1,$<exp_rhs_attr.data_type>3)){
                                            $<pred_struct.data_type>$=5;
                                            char*tempy=string_to_char("&&");
                                            $<pred_struct.name>$=concater($<exp_rhs_attr.name>1,tempy,$<exp_rhs_attr.name>3);
                                        }
                                        else{
                                            yyerror("Invalid datatypes for comparison, expected both to be real numbers or both complex numbers");
                                        }
                                    }
                                    }
          | exp_rhs OR exp_rhs{
                                    if($<exp_rhs_attr.type>1==true) yyerror("Expected ID but found array");
                                    else {
                                        if(same_type_comp($<exp_rhs_attr.data_type>1,$<exp_rhs_attr.data_type>3)){
                                            $<pred_struct.data_type>$=5;
                                            char*tempy=string_to_char("||");
                                            $<pred_struct.name>$=concater($<exp_rhs_attr.name>1,tempy,$<exp_rhs_attr.name>3);
                                        }
                                        else{
                                            yyerror("Invalid datatypes for comparison, expected both to be real numbers or both complex numbers");
                                        }
                                    }
                                    }
          | NEG exp_rhs{
                                    if($<exp_rhs_attr.type>1==true) yyerror("Expected ID but found array");
                                    else {
                                        $<pred_struct.data_type>$=$<exp_rhs_attr.data_type>2;
                                        char*tempy=string_to_char("!");
                                        $<pred_struct.name>$=concater(tempy,$<exp_rhs_attr.name>2);
                                    }
                                    }
          ;

exp_rhs : OPEN_CIR_PAR exp_rhs CLOSE_CIR_PAR {$<exp_rhs_attr.data_type>$=$<exp_rhs_attr.data_type>2;
                                                $<exp_rhs_attr.type>$=$<exp_rhs_attr.type>2;
                                                char*temp1=string_to_char("(");
                                                char*temp2=string_to_char(")");
                                                $<exp_rhs_attr.name>$=concater(temp1, $<exp_rhs_attr.name>2,temp2);
                                                }
        | OPEN_CIR_PAR MINUS exp_rhs CLOSE_CIR_PAR {$<exp_rhs_attr.data_type>$=$<exp_rhs_attr.data_type>3;
                                                $<exp_rhs_attr.type>$=$<exp_rhs_attr.type>3;
                                                char*temp1=string_to_char("(");
                                                char*temp2=string_to_char(")");
                                                $<exp_rhs_attr.name>$=concater(temp1,$2, $<exp_rhs_attr.name>3,temp2);
                                                }
        | exp_rhs ARITH_OP exp_rhs {
                                        if($<exp_rhs_attr.data_type>1==0 || $<exp_rhs_attr.data_type>1==6 || $<exp_rhs_attr.data_type>3==0 || $<exp_rhs_attr.data_type>3==6)
                                        {
                                            yyerror("invalid operation");
                                        }
                                        else if($<exp_rhs_attr.type>1==1 || $<exp_rhs_attr.type>3==1){
                                            yyerror("invalid operation");
                                        }
                                        else{
                                            if($<exp_rhs_attr.data_type>1==4 || $<exp_rhs_attr.data_type>3==4)
                                            {
                                                $<exp_rhs_attr.data_type>$=4;
                                            }
                                            else if(($<exp_rhs_attr.data_type>1==2 && $<exp_rhs_attr.data_type>3==3)||($<exp_rhs_attr.data_type>1==3 && $<exp_rhs_attr.data_type>3==2)){
                                                $<exp_rhs_attr.data_type>$=4;
                                            }
                                            else if(($<exp_rhs_attr.data_type>1==2)||($<exp_rhs_attr.data_type>3==2)){
                                                $<exp_rhs_attr.data_type>$=2;
                                            }
                                            else if(($<exp_rhs_attr.data_type>1==3)||($<exp_rhs_attr.data_type>3==3)){
                                                $<exp_rhs_attr.data_type>$=3;
                                            }    
                                            else{
                                                $<exp_rhs_attr.data_type>$=1;
                                            }

                                        }
                                        $<exp_rhs_attr.name>$=concater($<exp_rhs_attr.name>1,$2,$<exp_rhs_attr.name>3);
                                        $<exp_rhs_attr.type>$=false;
                                        // cout<<$<exp_rhs_attr.name>$<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
                                }
        | exp_rhs MINUS exp_rhs {       cout<<$<exp_rhs_attr.name>1<<" asas "<<$<exp_rhs_attr.name>3<<endl;
                                        if($<exp_rhs_attr.data_type>1==0 || $<exp_rhs_attr.data_type>1==6 || $<exp_rhs_attr.data_type>3==0 || $<exp_rhs_attr.data_type>3==6)
                                        {
                                            yyerror("invalid operation");
                                        }
                                        else if($<exp_rhs_attr.type>1==1 || $<exp_rhs_attr.type>3==1){
                                            yyerror("invalid operation");
                                        }
                                        else{
                                            if($<exp_rhs_attr.data_type>1==4 || $<exp_rhs_attr.data_type>3==4)
                                            {
                                                $<exp_rhs_attr.data_type>$=4;
                                            }
                                            else if(($<exp_rhs_attr.data_type>1==2 && $<exp_rhs_attr.data_type>3==3)||($<exp_rhs_attr.data_type>1==3 && $<exp_rhs_attr.data_type>3==2)){
                                                $<exp_rhs_attr.data_type>$=4;
                                            }
                                            else if(($<exp_rhs_attr.data_type>1==2)||($<exp_rhs_attr.data_type>3==2)){
                                                $<exp_rhs_attr.data_type>$=2;
                                            }
                                            else if(($<exp_rhs_attr.data_type>1==3)||($<exp_rhs_attr.data_type>3==3)){
                                                $<exp_rhs_attr.data_type>$=3;
                                            }    
                                            else{
                                                $<exp_rhs_attr.data_type>$=1;
                                            }
                                        }
                                        $<exp_rhs_attr.name>$=concater($<exp_rhs_attr.name>1,$2,$<exp_rhs_attr.name>3);
                                        // cout<<"string of the nation"<<$<exp_rhs_attr.name>$<<endl;
                                        // cout<<$<exp_rhs_attr.name>$<<"[[[[[]]]]]"<<endl;
                                        $<exp_rhs_attr.type>$=false;
                                    }
        | predicate {$<exp_rhs_attr.data_type>$=5;
                        $<exp_rhs_attr.type>$=false;
                        $<exp_rhs_attr.name>$=$<pred_struct.name>1;
                        cout<<"checkking error"<<$<exp_rhs_attr.name>$<<endl;
                        }
        | ID { 
                // cout<<$1<<"-=-"<<endl;
                args* sp=new args;
                sp=search_id_loc_sym_tab($1,scope);
                // cout << "++++++ "<<sp<<endl;
                if(!sp) yyerror("variable not declared");
                $<exp_rhs_attr.data_type>$=sp->dat_type.first;
                $<exp_rhs_attr.type>$=sp->dat_type.second;
                // fprintf(cpp_fp,"%s",$1);
                $<exp_rhs_attr.name>$=$1;
                }
        | INT_NUM {$<exp_rhs_attr.data_type>$=1;
                        $<exp_rhs_attr.type>$=false;
                        // fprintf(cpp_fp,"%s",$1);
                        $<exp_rhs_attr.name>$=$1;
                        }
        
        | DOUBLE_NUM {$<exp_rhs_attr.data_type>$=3; 
                        $<exp_rhs_attr.type>$=false;
                        // fprintf(cpp_fp,"%s",$1);
                        $<exp_rhs_attr.name>$=$1;
                        }
        | fn_call {$<exp_rhs_attr.data_type>$=$<exp_rhs_attr.data_type>1;
                        $<exp_rhs_attr.type>$=$<exp_rhs_attr.type>1;
                        $<exp_rhs_attr.name>$=$<exp_rhs_attr.name>1;
                        }
        | ID INC {  args* sp;
                sp=search_id_loc_sym_tab($1,scope);
                  if(sp->dat_type.second == 0){
                        $<exp_rhs_attr.data_type>$=sp->dat_type.first;
                  }
                  else yyerror("invalid operation");
                  $<exp_rhs_attr.type>$=false; 
                //   fprintf(cpp_fp,"%s++",$1);
                    char*temporary=string_to_char("+");
                    $<exp_rhs_attr.name>$=concater($1,temporary,temporary);
                  }

        | ID DEC {args* sp;
                sp=search_id_loc_sym_tab($1,scope);
                  if(sp->dat_type.second == 0){
                        $<exp_rhs_attr.data_type>$=sp->dat_type.first;
                  }
                  else yyerror("invalid operation");
                  $<exp_rhs_attr.type>$=false;
                    char*temporary=string_to_char("-");
                    $<exp_rhs_attr.name>$=concater($1,temporary,temporary);
                  }
        | INT_NUM INC {$<exp_rhs_attr.data_type>$=1;
                        $<exp_rhs_attr.type>$=false;
                        char*temporary=string_to_char("+");
                        $<exp_rhs_attr.name>$=concater($1,temporary,temporary);
                        
                        }
        | INT_NUM DEC {$<exp_rhs_attr.data_type>$=1;
                        $<exp_rhs_attr.type>$=false;
                        char*temporary=string_to_char("-");
                        $<exp_rhs_attr.name>$=concater($1,temporary,temporary);
                        }
        | DOUBLE_NUM INC {$<exp_rhs_attr.data_type>$=3;
                            $<exp_rhs_attr.type>$=false;
                        char*temporary=string_to_char("+");
                        $<exp_rhs_attr.name>$=concater($1,temporary,temporary);
                            }
        | DOUBLE_NUM DEC {$<exp_rhs_attr.data_type>$=3;
                        $<exp_rhs_attr.type>$=false;
                        char*temporary=string_to_char("-");
                        $<exp_rhs_attr.name>$=concater($1,temporary,temporary);
                        }
        | ID OPEN_SQUARE_PAR exp_rhs CLOSE_SQUARE_PAR { //cout<<$1<<"-=--"<<scope<<endl;
                                                        if($<exp_rhs_attr.data_type>3!=1){
                                                            yyerror("Not integer");
                                                        }
                                                        args* sp;
                                                        sp=search_id_loc_sym_tab($1,scope);
                                                        if(sp->dat_type.second == 1){
                                                            $<exp_rhs_attr.data_type>$=sp->dat_type.first;
                                                        }
                                                        else yyerror("invalid operation");
                                                        $<exp_rhs_attr.type>$=false;
                                                        char*temporary1=string_to_char("[");
                                                        char*temporary2=string_to_char("]");
                                                        $<exp_rhs_attr.name>$=concater($1,temporary1,$<exp_rhs_attr.name>3,temporary2);
                                                        }
        | OPEN_CIR_PAR exp_rhs COMMA exp_rhs CLOSE_CIR_PAR {if($<exp_rhs_attr.data_type>2 != 6 && $<exp_rhs_attr.data_type>4 != 6){
                                                              if(($<exp_rhs_attr.data_type>2 == 3 || $<exp_rhs_attr.data_type>2 == 4) || ($<exp_rhs_attr.data_type>4 == 3 || $<exp_rhs_attr.data_type>4 == 4)) $<exp_rhs_attr.data_type>$ = 4;
                                                              else $<exp_rhs_attr.data_type>$ = 2;
                                                            }
                                                            else{
                                                                yyerror("invalid operation");
                                                            }
                                                            $<exp_rhs_attr.type>$=false;
                                                            char*temporary1=string_to_char("{");
                                                            char*temporary2=string_to_char(",");
                                                            char*temporary3=string_to_char("}");
                                                            $<exp_rhs_attr.name>$=concater(temporary1,$<exp_rhs_attr.name>2,temporary2,$<exp_rhs_attr.name>4,temporary3);

                                                            }
        
        ;

fn_call : ID OPEN_CIR_PAR fn_args CLOSE_CIR_PAR{
                                                pair<short int,bool>temp;
                                                temp=check_func_call ($1,argmnt_chck_list);
                                                
                                                if(temp.first==-1){
                                                        yyerror("function not declared");
                                                }
                                                else if(temp.first==-2){
                                                        yyerror("arguments not matched");
                                                }
                                                else{
                                                        $<exp_rhs_attr.data_type>$=temp.first;
                                                        $<exp_rhs_attr.type>$=temp.second;
                                                }
                                                argmnt_chck_list.clear();

                                                char*temporary1=string_to_char("(");
                                                char*temporary2=string_to_char(")");
                                                $<exp_rhs_attr.name>$=concater($1,temporary1,$<exp_rhs_attr.name>3,temporary2);
                                                }
        
        ;
fn_args : all_exp_rhs COMMA fn_args{pair<short int,bool> temp;
                    temp.first=$<exp_rhs_attr.data_type>1;
                    temp.second=$<exp_rhs_attr.type>1;
                    // cout<<temp.first<<"qwerty"<<temp.second<<endl;
                    argmnt_chck_list.push_back(temp);
                    char *temporary=string_to_char(",");
                    $<exp_rhs_attr.name>$=concater($<exp_rhs_attr.name>1,temporary,$<exp_rhs_attr.name>3);
                    }
        | all_exp_rhs{pair<short int,bool> temp;
                    temp.first=$<exp_rhs_attr.data_type>1;
                    temp.second=$<exp_rhs_attr.type>1;
                    // cout<<temp.first<<"qwerty"<<temp.second<<endl;
                    argmnt_chck_list.push_back(temp);
                    $<exp_rhs_attr.name>$=$<exp_rhs_attr.name>1;
                    }
                
        | /* Epsilon */{char*temporary=string_to_char(")");
                         temporary[0]=' ';
                        $<exp_rhs_attr.name>$=temporary;}
        
        ;

iter_fir_stmt: decl_stmt
             |assign_stmt
             |inc_stmt{fprintf(cpp_fp,";");}
             |/*epsilon*/{fprintf(cpp_fp,";");}
             ;
iter_sec_stmt:exp_rhs{fprintf(cpp_fp,"%s;",$<exp_rhs_attr.name>1);}
             |/*epsilon*/{fprintf(cpp_fp,";");}
             ;
iter_thir_stmt:assign_stmt{fprintf(cpp_fp,"){");}
              |inc_stmt {fprintf(cpp_fp,"){");}
              |/*epsilon*/{fprintf(cpp_fp,"){");}
              ;

iter_header:ITER {create_loc_sym_tab_map();scope++;
                    fprintf(cpp_fp,"for(");}
          ;

until_header:UNTIL OPEN_CIR_PAR exp_rhs CLOSE_CIR_PAR {fprintf(cpp_fp,"while(%s){",$<exp_rhs_attr.name>3);
                                                        create_loc_sym_tab_map();scope++;}
             ;
iter:iter_header OPEN_CIR_PAR iter_fir_stmt SEMICOL iter_sec_stmt SEMICOL iter_thir_stmt CLOSE_CIR_PAR OPEN_CURLY_PAR stmts CLOSE_CURLY_PAR {fprintf(cpp_fp,"}");
                                                                                                                                            delete_loc_sym_tab_map();scope--;}
    ;
until: until_header OPEN_CURLY_PAR stmts CLOSE_CURLY_PAR {fprintf(cpp_fp,"}");
                                                            delete_loc_sym_tab_map();scope--;}
     ;

print_arg : all_exp_rhs{fprintf(cpp_fp,"%s",$<exp_rhs_attr.name>1);}
          | STRING{fprintf(cpp_fp,"%s",$1);}
          | print_arg COMMA STRING{fprintf(cpp_fp,"<<%s",$3);}
          | print_arg COMMA all_exp_rhs{fprintf(cpp_fp,"<<%s",$<exp_rhs_attr.name>3);}
          ;
print_fn : print_header CLOSE_CIR_PAR {$$=0; fprintf(cpp_fp,"<<endl;");}
         ;
print_header: PRINT OPEN_CIR_PAR print_arg
            ;

var_decl : real_decl 
         | comp_decl
         ;

real_decl : INT int_part { fprintf(cpp_fp,"int %s;", $2); 
                            /* for printing complex number declarations */
                            fprintf(cpp_fp,"%s\n",global_int);
                            char *global_int = string_to_char("");
                        } 
          | DOUBLE double_part { fprintf(cpp_fp,"double %s;", $2);
                                /* for printing complex number declarations */
                                fprintf(cpp_fp,"%s\n",global_double);
                                char *global_double = string_to_char("");
                              }
          ;

int_part : int_id_type { $$ = $<datatype_arg.name1>1; }
         | int_id_type COMMA int_part { char*temporary1=string_to_char(", ");
                                        $$ = concater($<datatype_arg.name1>1, temporary1, $3); }
         ;
int_id_type : ID { 
                   if(search_loc_sym_tab_scope($1,scope)){
                          yyerror("Variable already declared");
                     }
                     else{
                        char a[3] = "No";
                          insert_loc_sym_tab($1,1,false,true,scope,0,"No");
                   }
                  $<datatype_arg.name1>$ = $1;
                 }
            | ID ASSIGN all_exp_rhs { 
                         if(search_loc_sym_tab_scope($1,scope)){
                                yyerror("Variable already declared");
                        }
                        else{
                                if(($<exp_rhs_attr.data_type>3 == 1 || $<exp_rhs_attr.data_type>3 == 3 || $<exp_rhs_attr.data_type>3 == 5 ) && $<exp_rhs_attr.type>3 == false)
                                {
                                   insert_loc_sym_tab($1,1,false,true,scope,0,"No");
                                }
                                else {
                                        yyerror("Invalid assignment");
                                }
                         }
                         char*temporary1=string_to_char(" = ");                                        
                         $<datatype_arg.name1>$ = concater($1, temporary1, $<exp_rhs_attr.name>3);                                                      
                         
            }
            | ID OPEN_SQUARE_PAR exp_rhs CLOSE_SQUARE_PAR { 
                                if((($<exp_rhs_attr.data_type>3 == 1 || $<exp_rhs_attr.data_type>3 == 5)) && $<exp_rhs_attr.type>3==false){
                                        if(search_loc_sym_tab_scope($1,scope)){
                                            // cout<<"qwertyu"<<endl;
                                            yyerror("Variable already declared");
                                    }
                                    else{
                                            // cout<<"qwertyu"<<endl;
                                            insert_loc_sym_tab($1,1,true,true,scope,0,"No");
                                    }
                                }
                                else{
                                        yyerror("Array index must be integer");
                                }
                                char*temporary1=string_to_char("*");
                                $<datatype_arg.name1>$ = concater(temporary1, $1);

                                int n = atoi($<exp_rhs_attr.name>3);
                                int length = snprintf(nullptr, 0, "\n%s = new int(%d);", $1, n); 
                                char* temporary = (char*)malloc(length + 1);
                                snprintf(temporary, length + 1, "\n%s = new int(%d);", $1, n);
                                global_int = concater(global_int, temporary);      
            }
            | ID OPEN_CIR_PAR all_exp_rhs CLOSE_CIR_PAR OPEN_SQUARE_PAR exp_rhs CLOSE_SQUARE_PAR {
                                if(($<exp_rhs_attr.data_type>3 == 1 || $<exp_rhs_attr.data_type>3 == 3 || $<exp_rhs_attr.data_type>3 == 5) && $<exp_rhs_attr.type>3==false){
                                    if(($<exp_rhs_attr.data_type>6 == 1 || $<exp_rhs_attr.data_type>6 == 5) && $<exp_rhs_attr.type>6==false){
                                        if(search_loc_sym_tab_scope($1,scope)){
                                                yyerror("Variable already declared");
                                        }
                                        else{
                                                insert_loc_sym_tab($1,1,true,true,scope,0,"No");
                                        }
                                    }
                                    else{
                                            yyerror("Array index must be integer");
                                    }
                                }
                                else{
                                        yyerror("Initialization value must be integer");
                                } 

                                char*temporary1=string_to_char("*");
                                $<datatype_arg.name1>$ = concater(temporary1, $1);

                                int n = atoi($<exp_rhs_attr.name>6);
                                int length = snprintf(nullptr, 0, "\n%s = new int(%d);\nfor(int i = 0; i < %d; i++){\n%s[i] = %s;\n}\n", $1, n, n, $1, $<exp_rhs_attr.name>3); 
                                char* temporary = (char*)malloc(length + 1);
                                snprintf(temporary, length + 1, "\n%s = new int(%d);\nfor(int i = 0; i < %d; i++){\n%s[i] = %s;\n}\n", $1, n, n, $1, $<exp_rhs_attr.name>3);
                                global_int = concater(global_int, temporary);                    
            }                   
            ;
double_part : double_id_type { $$ = $<datatype_arg.name1>1; }
            | double_id_type COMMA double_part { char*temporary1=string_to_char(", ");
                                                 $$ = concater($<datatype_arg.name1>1, temporary1, $3); }
            ;
double_id_type : ID {
                        if(search_loc_sym_tab_scope($1,scope)){
                               yyerror("Variable already declared");
                          }
                          else{
                             char a[3] = "No";
                             insert_loc_sym_tab($1,3,false,true,scope,0,"No");
                        }  
                        $<datatype_arg.name1>$ = $1;      
                        }
               | ID ASSIGN all_exp_rhs { 
                                     if(search_loc_sym_tab_scope($1,scope)){
                                             yyerror("Variable already declared");
                                     }
                                     else{  
                                            if(($<exp_rhs_attr.data_type>3 == 1 || $<exp_rhs_attr.data_type>3 == 3 || $<exp_rhs_attr.data_type>3 == 5) && $<exp_rhs_attr.type>3 == false)
                                             {
                                                insert_loc_sym_tab($1,3,false,true,scope,0,"No");
                                             }
                                             else {
                                                     
                                                     yyerror("Invalid assignment");
                                             }
                                     }
                                     char*temporary1=string_to_char(" = ");                                        
                                     $<datatype_arg.name1>$ = concater($1, temporary1, $<exp_rhs_attr.name>3);
                                }
               | ID OPEN_SQUARE_PAR exp_rhs CLOSE_SQUARE_PAR {
                        if(($<exp_rhs_attr.data_type>3 == 1 || $<exp_rhs_attr.data_type>3 == 5) && $<exp_rhs_attr.type>3==false){
                            if(search_loc_sym_tab_scope($1,scope)){
                                    yyerror("Variable already declared");
                            }
                            else{
                                    insert_loc_sym_tab($1,3,true,true,scope,0,"No");
                            }
                        }
                        char*temporary1=string_to_char("*");
                        $<datatype_arg.name1>$ = concater(temporary1, $1);

                        int n = atoi($<exp_rhs_attr.name>3);
                        int length = snprintf(nullptr, 0, "\n%s = new double(%d);", $1, n); 
                        char* temporary = (char*)malloc(length + 1);
                        snprintf(temporary, length + 1, "\n%s = new double(%d);", $1, n);
                        global_double = concater(global_double, temporary); 

               }
               | ID OPEN_CIR_PAR all_exp_rhs CLOSE_CIR_PAR OPEN_SQUARE_PAR exp_rhs CLOSE_SQUARE_PAR {
                            if(($<exp_rhs_attr.data_type>3 == 1 || $<exp_rhs_attr.data_type>3 == 3 || $<exp_rhs_attr.data_type>3 == 5) && $<exp_rhs_attr.type>3==false){
                                if(($<exp_rhs_attr.data_type>6 == 1 || $<exp_rhs_attr.data_type>6 == 5) && $<exp_rhs_attr.type>6==false){
                                    if(search_loc_sym_tab_scope($1,scope)){
                                        yyerror("Variable already declared");
                                    }
                                    else{
                                        insert_loc_sym_tab($1,3,true,true,scope,0,"No");
                                    }
                                }
                                else{
                                        yyerror("Array index must be integer");
                                }
                            }
                            else{
                                    yyerror("Initialization value must be integer or real");
                                }
                                char*temporary1=string_to_char("*");
                                $<datatype_arg.name1>$ = concater(temporary1, $1);

                                int n = atoi($<exp_rhs_attr.name>6);
                                int length = snprintf(nullptr, 0, "\n%s = new double(%d);\nfor(int i = 0; i < %d; i++){\n%s[i] = %s;\n}\n", $1, n, n, $1, $<exp_rhs_attr.name>3); 
                                char* temporary = (char*)malloc(length + 1);
                                snprintf(temporary, length + 1, "\n%s = new double(%d);\nfor(int i = 0; i < %d; i++){\n%s[i] = %s;\n}\n", $1, n, n, $1, $<exp_rhs_attr.name>3);
                                global_double = concater(global_double, temporary);  
                }
               ;
comp_decl : CINT cint_part { fprintf(cpp_fp,"pair<int, int> %s;", $2); 
                            /* for printing complex number declarations */
                            fprintf(cpp_fp,"%s\n",global_cint);
                            global_cint = string_to_char("");
                        }
          | CDOUBLE cdouble_part { fprintf(cpp_fp,"pair<double, double> %s;", $2); 
                            /* for printing complex number declarations */
                            fprintf(cpp_fp,"%s\n",global_cdouble);
                            global_cdouble = string_to_char("");
                        }
          ;
cint_part : cint_id_type { $$ = $<datatype_arg.name1>1; }
          | cint_id_type COMMA cint_part { char*temporary1=string_to_char(", ");
                                            $$ = concater($<datatype_arg.name1>1, temporary1, $3); }
          ;
cint_id_type : ID {
                   if(search_loc_sym_tab_scope($1,scope)){
                          yyerror("Variable already declared");
                     }
                     else{
                        char a[3] = "No";
                        insert_loc_sym_tab($1,2,false,true,scope,0,"No");
                   }   
                   $<datatype_arg.name1>$ = $1; 
                }
             | ID OPEN_CIR_PAR all_exp_rhs CLOSE_CIR_PAR {
                if(($<exp_rhs_attr.data_type>3 == 1 || $<exp_rhs_attr.data_type>3 == 3 || $<exp_rhs_attr.data_type>3 == 5) && $<exp_rhs_attr.type>3==false){
                   if(search_loc_sym_tab_scope($1,scope)){
                          yyerror("Variable already declared");
                     }
                     else{
                        char a[3] = "No";
                        insert_loc_sym_tab($1,2,false,true,scope,0,"No");
                   } 
                }
                else{
                        yyerror("Initialization value must be integer");
                }
                char*temporary1=string_to_char(" {0,");
                char*temporary2=string_to_char("}");
                $<datatype_arg.name1>$ = concater($1, temporary1, $<exp_rhs_attr.name>3, temporary2); 
             }
             | ID OPEN_CIR_PAR all_exp_rhs COMMA all_exp_rhs CLOSE_CIR_PAR {
                   if(($<exp_rhs_attr.data_type>3 == 1 || $<exp_rhs_attr.data_type>3 == 3 || $<exp_rhs_attr.data_type>3 == 5) && $<exp_rhs_attr.type>3==false){
                    if(($<exp_rhs_attr.data_type>5 == 1 || $<exp_rhs_attr.data_type>5 == 3 || $<exp_rhs_attr.data_type>5 == 5) && $<exp_rhs_attr.type>5==false){
                        if(search_loc_sym_tab_scope($1,scope)){
                                yyerror("Variable already declared");
                            }
                            else{
                                char a[3] = "No";
                                insert_loc_sym_tab($1,2,false,true,scope,0,"No");
                        }
                    }
                    else{
                            yyerror("Initialization value must be integer");
                    }
                   } 
                     else{
                            yyerror("Initialization value must be integer");
                     }
                    char*temporary1=string_to_char(" {");
                    char*temporary2=string_to_char(", ");
                    char*temporary3=string_to_char("}");
                    char*temporary4 = concater($1, temporary1, $<exp_rhs_attr.name>3, temporary2);
                    $<datatype_arg.name1>$ = concater(temporary4, $<exp_rhs_attr.name>5, temporary3);
             }          
             | ID OPEN_SQUARE_PAR exp_rhs CLOSE_SQUARE_PAR {
                if(($<exp_rhs_attr.data_type>3 == 1 || $<exp_rhs_attr.data_type>3 == 5) && $<exp_rhs_attr.type>3==false){
                    if(search_loc_sym_tab_scope($1,scope)){
                            yyerror("Variable already declared");
                    }
                    else{
                            insert_loc_sym_tab($1,2,true,true,scope,0,"No");
                    }
                }
                else{
                        yyerror("Array index must be integer");
                } 
                char*temporary1=string_to_char("*");
                $<datatype_arg.name1>$ = concater(temporary1, $1);

                int n = atoi($<exp_rhs_attr.name>3);
                int length = snprintf(nullptr, 0, "\n%s = new pair<int, int>[%d];", $1, n); 
                char* temporary = (char*)malloc(length + 1);
                snprintf(temporary, length + 1, "\n%s = new pair<int, int>[%d];", $1, n);
                global_cint = concater(global_cint, temporary);  
             }
             | ID OPEN_CIR_PAR all_exp_rhs CLOSE_CIR_PAR OPEN_SQUARE_PAR exp_rhs CLOSE_SQUARE_PAR {
                if(($<exp_rhs_attr.data_type>3 == 1 || $<exp_rhs_attr.data_type>3 == 3 || $<exp_rhs_attr.data_type>3 == 5) && $<exp_rhs_attr.type>3==false){
                    if(($<exp_rhs_attr.data_type>6 == 1 || $<exp_rhs_attr.data_type>6 == 5) && $<exp_rhs_attr.type>6==false){
                                if(search_loc_sym_tab_scope($1,scope)){
                                        yyerror("Variable already declared");
                                }
                                else{
                                        insert_loc_sym_tab($1,2,true,true,scope,0,"No");
                                }     
                    }
                    else{
                            yyerror("Array index must be integer");
                    }
                }  
                else{
                        yyerror("Initialization value must be integer");
                }    
                char*temporary1=string_to_char("*");
                $<datatype_arg.name1>$ = concater(temporary1, $1);

                int n = atoi($<exp_rhs_attr.name>6);
                int length = snprintf(nullptr, 0, "\n%s = new pair<int, int>[%d];\nfor(int i = 0; i < %d; i++){\n%s[i] = {0, %s};\n}\n", $1, n, n, $1, $<exp_rhs_attr.name>3); 
                char* temporary = (char*)malloc(length + 1);
                snprintf(temporary, length + 1, "\n%s = new pair<int, int>[%d];\nfor(int i = 0; i < %d; i++){\n%s[i] = {0, %s};\n}\n", $1, n, n, $1, $<exp_rhs_attr.name>3);
                global_cint = concater(global_cint, temporary);
             }
             | ID OPEN_CIR_PAR all_exp_rhs COMMA all_exp_rhs CLOSE_CIR_PAR OPEN_SQUARE_PAR exp_rhs CLOSE_SQUARE_PAR {
                    if(($<exp_rhs_attr.data_type>3 == 1 || $<exp_rhs_attr.data_type>3 == 3 || $<exp_rhs_attr.data_type>3 == 5) && $<exp_rhs_attr.type>3==false){
                        if(($<exp_rhs_attr.data_type>5 == 1 || $<exp_rhs_attr.data_type>5 == 5 || $<exp_rhs_attr.data_type>5 == 3) && $<exp_rhs_attr.type>5==false){
                            if(($<exp_rhs_attr.data_type>8 == 1 || $<exp_rhs_attr.data_type>8 == 5) && $<exp_rhs_attr.type>8==false){
                                if(search_loc_sym_tab_scope($1,scope)){
                                        yyerror("Variable already declared");
                                }
                                else{
                                        insert_loc_sym_tab($1,2,true,true,scope,0,"No");
                                }
                            }
                            else{
                                    yyerror("Array index must be integer");
                            }
                        }
                        else{
                                yyerror("Initialization value must be integer");
                        }
                    }
                    else{
                            yyerror("Initialization value must be integer");
                    }
                    char*temporary1=string_to_char("*");
                    $<datatype_arg.name1>$ = concater(temporary1, $1);

                    int n = atoi($<exp_rhs_attr.name>8);
                    int length = snprintf(nullptr, 0, "\n%s = new pair<int, int>[%d];\nfor(int i = 0; i < %d; i++){\n%s[i] = {%s, %s};\n}\n", $1, n, n, $1, $<exp_rhs_attr.name>3, $<exp_rhs_attr.name>5); 
                    char* temporary = (char*)malloc(length + 1);
                    snprintf(temporary, length + 1, "\n%s = new pair<int, int>[%d];\nfor(int i = 0; i < %d; i++){\n%s[i] = {%s, %s};\n}\n", $1, n, n, $1, $<exp_rhs_attr.name>3, $<exp_rhs_attr.name>5);
                    global_cint = concater(global_cint, temporary);
             }
             | ID ASSIGN all_exp_rhs { 
                                     if(search_loc_sym_tab_scope($1,scope)){
                                             yyerror("Variable already declared");
                                     }
                                     else{   
                                            if(($<exp_rhs_attr.data_type>3 == 2) && $<exp_rhs_attr.type>3 == false)
                                             {
                                                insert_loc_sym_tab($1,2,false,true,scope,0,"No");
                                             }
                                             else {   
                                                yyerror("Invalid assignment");
                                             }
                                     }
                                    char*temporary1=string_to_char(" = ");                                        
                                    $<datatype_arg.name1>$ = concater($1, temporary1, $<exp_rhs_attr.name>3);
                                }

             ;
cdouble_part : cdouble_id_type { $$ = $<datatype_arg.name1>1; }
            | cdouble_id_type COMMA cdouble_part { char*temporary1=string_to_char(", ");
                                                   $$ = concater($<datatype_arg.name1>1, temporary1, $3); }
            ;
cdouble_id_type : ID {
                   if(search_loc_sym_tab_scope($1,scope)){
                          yyerror("Variable already declared");
                     }
                     else{
                        char a[3] = "No";
                        insert_loc_sym_tab($1,4,false,true,scope,0,"No");
                   }  
                   $<datatype_arg.name1>$ = $1;   
                }
                | ID OPEN_CIR_PAR all_exp_rhs CLOSE_CIR_PAR {
                    if(($<exp_rhs_attr.data_type>3 == 1 || $<exp_rhs_attr.data_type>3 == 3 || $<exp_rhs_attr.data_type>3 == 5) && $<exp_rhs_attr.type>3==false){
                        if(search_loc_sym_tab_scope($1,scope)){
                                yyerror("Variable already declared");
                            }
                            else{
                                char a[3] = "No";
                                insert_loc_sym_tab($1,4,false,true,scope,0,"No");
                        }
                    }
                    else{
                            yyerror("Initialization value must be integer or real");
                    }
                    char*temporary1=string_to_char(" {0,");
                    char*temporary2=string_to_char("}");
                    $<datatype_arg.name1>$ = concater($1, temporary1, $<exp_rhs_attr.name>3, temporary2); 
                }
                | ID OPEN_CIR_PAR all_exp_rhs COMMA all_exp_rhs CLOSE_CIR_PAR {
                    if(($<exp_rhs_attr.data_type>3 == 1 || $<exp_rhs_attr.data_type>3 == 3 || $<exp_rhs_attr.data_type>3 == 5) && $<exp_rhs_attr.type>3==false){
                        if(($<exp_rhs_attr.data_type>5 == 1 || $<exp_rhs_attr.data_type>5 == 3 || $<exp_rhs_attr.data_type>5 == 5) && $<exp_rhs_attr.type>5==false){
                            if(search_loc_sym_tab_scope($1,scope)){
                                    yyerror("Variable already declared");
                                }
                                else{
                                    char a[3] = "No";
                                    insert_loc_sym_tab($1,4,false,true,scope,0,"No");
                            }
                        }
                        else{
                                yyerror("Initialization value must be integer or real");
                        }
                    }
                    else{
                            yyerror("Initialization value must be integer or real");
                    }
                    char*temporary1=string_to_char(" {");
                    char*temporary2=string_to_char(", ");
                    char*temporary3=string_to_char("}");
                    char*temporary4 = concater($1, temporary1, $<exp_rhs_attr.name>3, temporary2);
                    $<datatype_arg.name1>$ = concater(temporary4, $<exp_rhs_attr.name>5, temporary3);
                }
                | ID OPEN_SQUARE_PAR exp_rhs CLOSE_SQUARE_PAR {
                    if(($<exp_rhs_attr.data_type>3 == 1 || $<exp_rhs_attr.data_type>3 == 5) && $<exp_rhs_attr.type>3==false){
                        if(search_loc_sym_tab_scope($1,scope)){
                                yyerror("Variable already declared");
                            }
                            else{
                                char a[3] = "No";
                                insert_loc_sym_tab($1,4,true,true,scope,0,"No");
                        }
                    }
                    else{
                            yyerror("Array index must be integer");
                    }
                    char*temporary1=string_to_char("*");
                    $<datatype_arg.name1>$ = concater(temporary1, $1);

                    int n = atoi($<exp_rhs_attr.name>3);
                    int length = snprintf(nullptr, 0, "\n%s = new pair<double, double>[%d];", $1, n); 
                    char* temporary = (char*)malloc(length + 1);
                    snprintf(temporary, length + 1, "\n%s = new pair<double, double>[%d];", $1, n);
                    global_cdouble = concater(global_cdouble, temporary); 
                }
                | ID OPEN_CIR_PAR all_exp_rhs CLOSE_CIR_PAR OPEN_SQUARE_PAR exp_rhs CLOSE_SQUARE_PAR {
                    if(($<exp_rhs_attr.data_type>3 == 1 || $<exp_rhs_attr.data_type>3 == 3 || $<exp_rhs_attr.data_type>3 == 5) && $<exp_rhs_attr.type>3==false){
                       if(($<exp_rhs_attr.data_type>6 == 1 || $<exp_rhs_attr.data_type>6 == 5) && $<exp_rhs_attr.type>6==false){ 
                            if(search_loc_sym_tab_scope($1,scope)){
                                yyerror("Variable already declared");
                            }
                            else{
                            char a[3] = "No";
                            insert_loc_sym_tab($1,4,true,true,scope,0,"No");
                            }
                       }
                          else{
                             yyerror("Array index must be integer");
                          }
                    }
                    else{
                            yyerror("Initialization value must be integer or real");
                    }
                    char*temporary1=string_to_char("*");
                    $<datatype_arg.name1>$ = concater(temporary1, $1);

                    int n = atoi($<exp_rhs_attr.name>6);
                    int length = snprintf(nullptr, 0, "\n%s = new pair<double, double>[%d];\nfor(int i = 0; i < %d; i++){\n%s[i] = {0, %s};\n}\n", $1, n, n, $1, $<exp_rhs_attr.name>3); 
                    char* temporary = (char*)malloc(length + 1);
                    snprintf(temporary, length + 1, "\n%s = new pair<double, double>[%d];\nfor(int i = 0; i < %d; i++){\n%s[i] = {0, %s};\n}\n", $1, n, n, $1, $<exp_rhs_attr.name>3);
                    global_cdouble = concater(global_cdouble, temporary);
                }
                | ID OPEN_CIR_PAR all_exp_rhs COMMA all_exp_rhs CLOSE_CIR_PAR OPEN_SQUARE_PAR exp_rhs CLOSE_SQUARE_PAR {
                  if(($<exp_rhs_attr.data_type>3 == 1 || $<exp_rhs_attr.data_type>3 == 3 || $<exp_rhs_attr.data_type>3 == 5) && $<exp_rhs_attr.type>3==false){
                        if(($<exp_rhs_attr.data_type>5 == 1 || $<exp_rhs_attr.data_type>5 == 3 || $<exp_rhs_attr.data_type>5 == 5) && $<exp_rhs_attr.type>5==false){
                            if(($<exp_rhs_attr.data_type>8 == 1 || $<exp_rhs_attr.data_type>8 == 5) && $<exp_rhs_attr.type>8==false){
                                if(search_loc_sym_tab_scope($1,scope)){
                                    yyerror("Variable already declared");
                                }
                                else{
                                    char a[3] = "No";
                                    insert_loc_sym_tab($1,4,true,true,scope,0,"No");
                                }
                            }
                            else{
                                    yyerror("Array index must be integer");
                            }
                        }
                        else{
                                yyerror("Initialization value must be integer or real");
                        }
                  }
                    else{
                                yyerror("Initialization value must be integer or real");
                    }
                    char*temporary1=string_to_char("*");
                    $<datatype_arg.name1>$ = concater(temporary1, $1);

                    int n = atoi($<exp_rhs_attr.name>8);
                    int length = snprintf(nullptr, 0, "\n%s = new pair<double, double>[%d];\nfor(int i = 0; i < %d; i++){\n%s[i] = {%s, %s};\n}\n", $1, n, n, $1, $<exp_rhs_attr.name>3, $<exp_rhs_attr.name>5); 
                    char* temporary = (char*)malloc(length + 1);
                    snprintf(temporary, length + 1, "\n%s = new pair<double, double>[%d];\nfor(int i = 0; i < %d; i++){\n%s[i] = {%s, %s};\n}\n", $1, n, n, $1, $<exp_rhs_attr.name>3, $<exp_rhs_attr.name>5);
                    global_cdouble = concater(global_cdouble, temporary);    
                }
                | ID ASSIGN all_exp_rhs { 
                                     if(search_loc_sym_tab_scope($1,scope)){
                                             yyerror("Variable already declared");
                                     }
                                     else{   
                                             if(($<exp_rhs_attr.data_type>3 == 2 || $<exp_rhs_attr.data_type>3 == 4) && $<exp_rhs_attr.type>3 == false)
                                             {
                                                insert_loc_sym_tab($1,4,false,true,scope,0,"No");
                                             }
                                             else {
                                                     
                                                yyerror("Invalid assignment");
                                             }
                                     }
                                    char*temporary1=string_to_char(" = ");                                        
                                    $<datatype_arg.name1>$ = concater($1, temporary1, $<exp_rhs_attr.name>3);
                                }
                ;

argument : argument_list { $$ = $<arg_name_type.arg_name>1; }
         | argument_list COMMA argument { char*temporary1=string_to_char(", ");
                                            $$ = concater($<arg_name_type.arg_name>1, temporary1, $3);  }
         ;
argument_list : T L{    args arg_attr;
                            arg_attr.name=$<arg_name_type.arg_name>2;
                            arg_attr.dat_type.first=$<datatype_arg.datatype>1;
                            arg_attr.dat_type.second=$<arg_name_type.arg_type_bool>2;
                            argmnt_list.push_back(arg_attr);
                            char *x;
                            if($<arg_name_type.arg_type_bool>2==0){
                                x=string_to_char("");
                            }
                            else{
                                x=string_to_char("*");
                            }
                            $<arg_name_type.arg_name>$=concater($<datatype_arg.name1>1, x, $<arg_name_type.arg_name>2);
                            }
         |{$<arg_name_type.arg_name>$=string_to_char("");}
         ;
        //  datatype_arg
T : INT{$<datatype_arg.datatype>$=1; $<datatype_arg.name1>$=string_to_char("int ");}
 |  CINT {$<datatype_arg.datatype>$=2; $<datatype_arg.name1>$=string_to_char("pair<int, int> ");}
 |  DOUBLE {$<datatype_arg.datatype>$=3; $<datatype_arg.name1>$=string_to_char("double "); }
 |  CDOUBLE {$<datatype_arg.datatype>$=4;  $<datatype_arg.name1>$ = string_to_char("pair<double, double> ");}
 ;
L : ID {$<arg_name_type.arg_name>$=$1;
        $<arg_name_type.arg_type_bool>$=0;}
  | ID OPEN_SQUARE_PAR CLOSE_SQUARE_PAR{$<arg_name_type.arg_name>$=$1;
        $<arg_name_type.arg_type_bool>$=1;}
  ;

int main(int argc,char** argv)
{
    // if(argc==0) return 0;
  ret_no=0;
  arr=(char *)calloc(1000,sizeof(char));
  int t;
  init_inbuilt();
//   #include <bits/stdc++.h>
// #include "inbuilt_functions.cpp"
// using namespace std;
  // printf("Enter test case number: ");
  // scanf("%d",&t);
//   yyparse();
//   return 0;
  char input_file[100];
  int i;
  for(i=0;i<strlen(argv[1]);i++)
  {
    input_file[i]=argv[1][i];
  }
  input_file[i]='\0';
  l_no=1;
  yyin = fopen(input_file, "r"); //open input file
  token_fp=convert_str(input_file); //open token file
  cpp_fp=cpp_convert_str(input_file);//open token file
fprintf(cpp_fp,"#include <bits/stdc++.h>\n#include \"../inbuilt_functions.cpp\"\nusing namespace std;\n");
  if(yyin==NULL||token_fp==NULL||cpp_fp==NULL) 
  {
      printf("Error opening file s\n");
      return 0;
  }


//   fprintf(token_fp,"Name: Yoligi Govinda Rohith\nID: CS21BTECH11062\nInput file: public_test_%d.clike\n",t);
  yyparse();
  if(main_check!=1)yyerror("main function not declared");
  printf("Syntactically correct!\n");
  fclose(token_fp);
  fclose(cpp_fp);
  return 0;
}
void yyerror(const char * s)
{  
 fprintf (cpp_fp, "\ninvalid statement\n");
 fprintf (stderr, "error: %s ,At line no : %d\n", s,l_no);
 exit(0);
}
