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
extern FILE *parsed_fp;
extern int l_no;
list <args> argmnt_list;
list <pair<short int, bool>> argmnt_chck_list; 
pair<short int,bool> return_type;
int scope=0;
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
    } exp_rhs_attr;
    struct{
        short int data_type;
        bool type;
    } exp_lhs_attr;
    struct{
        short int data_type;
        bool type;
    } assign_rhs_attr;
}
%token REAL_DEC IMAG_DEC ITER PRINT UNTIL RETURN REM NEQ OR NEG AND
%token INT CINT CDOUBLE MINUS DOUBLE STR STRING BIN VOID
%token CHOICE ALT DEFAULT
%token <name> ID 
%token SEMICOL COMMA COLON QUOTE
%token GT LT EQ NE INC DEC ASSIGN LE GE
%token INT_NUM DOUBLE_NUM ARITH_OP ACCESS_OP1 ACCESS_OP2
%token INN_PROD IMAG_INC REAL_INC
%token OPEN_CIR_PAR CLOSE_CIR_PAR OPEN_CURLY_PAR CLOSE_CURLY_PAR OPEN_SQUARE_PAR CLOSE_SQUARE_PAR
%left ARITH_OP GT LT EQ NE GE LE AND OR NEG MINUS
%type <type> data_type_arr
%type <datatype> data_type
%type <name> func_name
%type <ret_type> d_type
%type <datatype> T
%type <arg_name_type> L
%type <datatype_arg> int_id_type
%type <exp_rhs_attr> exp_rhs
%type <exp_rhs_attr> all_exp_rhs
%type <exp_rhs_attr> fn_call
%type <datatype> assign_stmt 
%type <datatype> inc_stmt_lhs
%type <datatype> print_fn
%type <datatype> predicate
%type <exp_lhs_attr> exp_lhs
%type <assign_rhs_attr> assign_rhs

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
           | inc_stmt SEMICOL
           | print_fn SEMICOL 
           ;
  

func_stmt : func_info OPEN_CURLY_PAR stmts CLOSE_CURLY_PAR {
                                                            delete_loc_sym_tab_map();
                                                            delete_loc_sym_tab_map();
                                                            scope=0;
                                                            }
          ;
func_info:func_name d_type COLON OPEN_CIR_PAR argument CLOSE_CIR_PAR{ 
                                                                        if(!search_fn_sym_tab($1)){                                                                              
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
                                                                    }
        ;
func_name: ID  {$$=$1;}
     ;
d_type : data_type data_type_arr { $<ret_type.ret_type_bool>$=$2;
                                   $<ret_type.ret_datatype>$=$1;
                              }
       ;

data_type :VOID{$$=0;}| INT {$$=1; } | CINT {$$=2; } | DOUBLE {$$=3; } | CDOUBLE {$$=4; }
          ;
data_type_arr : OPEN_SQUARE_PAR CLOSE_SQUARE_PAR {$$=true;}
              | /* epsilon*/ {$$=false;}
              ;

/* if statement syntax */
if_stmt_scope1 : OPEN_CIR_PAR exp_rhs CLOSE_CIR_PAR { scope++; create_loc_sym_tab_map(); }
               ;
if_stmt : CHOICE if_stmt_scope1 OPEN_CURLY_PAR stmts CLOSE_CURLY_PAR elif_stmt { delete_loc_sym_tab_map();scope--; }
        | CHOICE if_stmt_scope1 OPEN_CURLY_PAR stmts CLOSE_CURLY_PAR elif_stmt else_stmt stmts CLOSE_CURLY_PAR {delete_loc_sym_tab_map();scope--;}
        // | CHOICE OPEN_CIR_PAR predicate CLOSE_CIR_PAR OPEN_CURLY_PAR stmt_types CLOSE_CURLY_PAR elif_stmt
        ;
/* special case of else if statements */
elif_stmt : ALT if_stmt_scope1 OPEN_CURLY_PAR stmts CLOSE_CURLY_PAR elif_stmt { delete_loc_sym_tab_map();scope--; }
          | /* Epsilon */
          ;
else_stmt : DEFAULT OPEN_CURLY_PAR { scope++; create_loc_sym_tab_map(); }
           ;

inc_stmt : inc_stmt_lhs inc_stmt_rhs {if($1!=2 && $1!=4) yyerror("invalid operation");}
         | inc_stmt_lhs INC {if($1!=1 && $1!=3 && $1!=5) yyerror("invalid operation");}
         | inc_stmt_lhs DEC {if($1!=1 && $1!=3 && $1!=5) yyerror("invalid operation");}
         ;
inc_stmt_rhs : REAL_INC | IMAG_INC | REAL_DEC | IMAG_DEC
             ;
inc_stmt_lhs:ID { args* sp;
                sp=search_id_loc_sym_tab($1,scope);
                if(!sp) yyerror("variable not declared");
                  if(sp->dat_type.second == 0){
                        $$=sp->dat_type.first;
                  }
                  else yyerror("invalid operation");
                //   $<exp_rhs_attr.type>$=false;
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
                                                        }
            ;

all_exp_rhs : exp_rhs { $<exp_rhs_attr.data_type>$=$<exp_rhs_attr.data_type>1;
                        $<exp_rhs_attr.type>$=$<exp_rhs_attr.type>1;
                        }
            | MINUS exp_rhs { $<exp_rhs_attr.data_type>$=$<exp_rhs_attr.data_type>2;
                        $<exp_rhs_attr.type>$=$<exp_rhs_attr.type>2;
                        }
            ;
for_stmt: iter
        ;
while_stmt: until
          ;
decl_stmt : var_decl {/*Note above 4 are wrtitten for testing only*/}
          ;
void_fn_calls : fn_call
              ;
return_stmt : RETURN exp_rhs{if($<exp_rhs_attr.data_type>2==return_type.first && $<exp_rhs_attr.type>2 == return_type.second){}
                             else{
                                        yyerror("return type mismatch");
                             }   }
            ;

assign_stmt : exp_lhs ASSIGN assign_rhs{
                                        if(!comp_assign_checker($<exp_lhs_attr.data_type>1,$<assign_rhs_attr.data_type>3,$<exp_lhs_attr.type>1,$<assign_rhs_attr.type>3)){
                                                yyerror("Type mismatch");
                                        }
                                        }
            ;
exp_lhs : ID { args* sp=new args;
               sp=search_id_loc_sym_tab($1,scope);
               if(!sp) yyerror("variable not declared");
               $<exp_lhs_attr.data_type>$=sp->dat_type.first;
               $<exp_lhs_attr.type>$=sp->dat_type.second;
             }
        | ID OPEN_SQUARE_PAR exp_rhs CLOSE_SQUARE_PAR{ args* sp=new args;
                if($<exp_rhs_attr.data_type>3!=1){
                        yyerror("Array index must be integer");
                }
                sp=search_id_loc_sym_tab($1,scope);
                if(!sp) yyerror("variable not declared");
                $<exp_lhs_attr.data_type>$=sp->dat_type.first;
                $<exp_lhs_attr.type>$=false;
             }
        ;
assign_rhs : exp_rhs {$<assign_rhs_attr.data_type>$=$<exp_rhs_attr.data_type>1;
                        $<assign_rhs_attr.type>$=$<exp_rhs_attr.type>1;
                        }
           | MINUS exp_rhs {$<assign_rhs_attr.data_type>$=$<exp_rhs_attr.data_type>2;
                        $<assign_rhs_attr.type>$=$<exp_rhs_attr.type>2;
                        }
           ;
        

predicate : exp_rhs GT exp_rhs {
                                    if($<exp_rhs_attr.type>1==true) yyerror("Expected ID but found array");
                                    else {
                                        if(only_real_comp($<exp_rhs_attr.data_type>1,$<exp_rhs_attr.data_type>3)){
                                            $$=5;
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
                                            $$=5;
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
                                            $$=5;
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
                                            $$=5;
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
                                            $$=5;
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
                                            $$=5;
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
                                            $$=5;
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
                                            $$=5;
                                        }
                                        else{
                                            yyerror("Invalid datatypes for comparison, expected both to be real numbers or both complex numbers");
                                        }
                                    }
                                    }
          | NEG exp_rhs{
                                    if($<exp_rhs_attr.type>1==true) yyerror("Expected ID but found array");
                                    else {
                                        $$=$<exp_rhs_attr.data_type>2;
                                    }
                                    }
          ;
exp_rhs : OPEN_CIR_PAR exp_rhs CLOSE_CIR_PAR {$<exp_rhs_attr.data_type>$=$<exp_rhs_attr.data_type>2;
                                                $<exp_rhs_attr.type>$=$<exp_rhs_attr.type>2;
                                                }
        | OPEN_CIR_PAR MINUS exp_rhs CLOSE_CIR_PAR {$<exp_rhs_attr.data_type>$=$<exp_rhs_attr.data_type>3;
                                                $<exp_rhs_attr.type>$=$<exp_rhs_attr.type>3;
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
                                        $<exp_rhs_attr.type>$=false;
                                }
        | exp_rhs MINUS exp_rhs {    
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
                                        $<exp_rhs_attr.type>$=false;
                                    }
        | predicate {$<exp_rhs_attr.data_type>$=5;
                        $<exp_rhs_attr.type>$=false;}
        | ID { 
                // cout<<$1<<"-=-"<<endl;
                args* sp=new args;
                sp=search_id_loc_sym_tab($1,scope);
                // cout << "++++++ "<<sp<<endl;
                if(!sp) yyerror("variable not declared");
                $<exp_rhs_attr.data_type>$=sp->dat_type.first;
                $<exp_rhs_attr.type>$=sp->dat_type.second;
                }
        | INT_NUM {$<exp_rhs_attr.data_type>$=1;
                        $<exp_rhs_attr.type>$=false;}
        
        | DOUBLE_NUM {$<exp_rhs_attr.data_type>$=3; 
                        $<exp_rhs_attr.type>$=false;}
        | fn_call {$<exp_rhs_attr.data_type>$=$<exp_rhs_attr.data_type>1;
                        $<exp_rhs_attr.type>$=$<exp_rhs_attr.type>1;}
        | ID INC {  args* sp;
                sp=search_id_loc_sym_tab($1,scope);
                  if(sp->dat_type.second == 0){
                        $<exp_rhs_attr.data_type>$=sp->dat_type.first;
                  }
                  else yyerror("invalid operation");
                  $<exp_rhs_attr.type>$=false; }

        | ID DEC {args* sp;
                sp=search_id_loc_sym_tab($1,scope);
                  if(sp->dat_type.second == 0){
                        $<exp_rhs_attr.data_type>$=sp->dat_type.first;
                  }
                  else yyerror("invalid operation");
                  $<exp_rhs_attr.type>$=false;}
        | INT_NUM INC {$<exp_rhs_attr.data_type>$=1;
                        $<exp_rhs_attr.type>$=false;}
        | INT_NUM DEC {$<exp_rhs_attr.data_type>$=1;
                        $<exp_rhs_attr.type>$=false;}
        | DOUBLE_NUM INC {$<exp_rhs_attr.data_type>$=3;
                            $<exp_rhs_attr.type>$=false;}
        | DOUBLE_NUM DEC {$<exp_rhs_attr.data_type>$=3;
                        $<exp_rhs_attr.type>$=false;}
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
                                                        }
        | OPEN_CIR_PAR exp_rhs COMMA exp_rhs CLOSE_CIR_PAR {if($<exp_rhs_attr.data_type>2 != 6 && $<exp_rhs_attr.data_type>4 != 6){
                                                              if(($<exp_rhs_attr.data_type>2 == 3 || $<exp_rhs_attr.data_type>2 == 4) || ($<exp_rhs_attr.data_type>4 == 3 || $<exp_rhs_attr.data_type>4 == 4)) $<exp_rhs_attr.data_type>$ = 4;
                                                              else $<exp_rhs_attr.data_type>$ = 2;
                                                            }
                                                            else{
                                                                yyerror("invalid operation");
                                                            }
                                                            $<exp_rhs_attr.type>$=false;
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
                                                }
        
        ;
fn_args : all_exp_rhs COMMA fn_args{pair<short int,bool> temp;
                    temp.first=$<exp_rhs_attr.data_type>1;
                    temp.second=$<exp_rhs_attr.type>1;
                    argmnt_chck_list.push_back(temp);
                    }
        | all_exp_rhs{pair<short int,bool> temp;
                    temp.first=$<exp_rhs_attr.data_type>1;
                    temp.second=$<exp_rhs_attr.type>1;
                    argmnt_chck_list.push_back(temp);
                    }
                
        | /* Epsilon */
        ;

iter_fir_stmt: decl_stmt
             |assign_stmt
             |inc_stmt
             |/*epsilon*/
             ;
iter_sec_stmt:predicate
             |/*epsilon*/
             ;
iter_thir_stmt:assign_stmt
              |inc_stmt 
              |/*epsilon*/
              ;

iter_header:ITER {create_loc_sym_tab_map();scope++;}
          ;

until_header:UNTIL OPEN_CIR_PAR exp_rhs CLOSE_CIR_PAR {create_loc_sym_tab_map();scope++;}
            ;
     ;
iter:iter_header OPEN_CIR_PAR iter_fir_stmt SEMICOL iter_sec_stmt SEMICOL iter_thir_stmt CLOSE_CIR_PAR OPEN_CURLY_PAR stmts CLOSE_CURLY_PAR {delete_loc_sym_tab_map();scope--;}
    ;
until: until_header OPEN_CURLY_PAR stmts CLOSE_CURLY_PAR {delete_loc_sym_tab_map();scope--;}
     ;
print_arg : all_exp_rhs
          | STRING
          | STRING COMMA print_arg
          | all_exp_rhs COMMA print_arg
          ;
print_fn : PRINT OPEN_CIR_PAR print_arg CLOSE_CIR_PAR {$$=0;}
         ;
var_decl : real_decl
         | comp_decl
         ;

real_decl : INT int_part
          | DOUBLE double_part
          ;
int_part : int_id_type
         | int_id_type COMMA int_part
         ;
int_id_type : ID { 
                   if(search_loc_sym_tab_scope($1,scope)){
                          yyerror("Variable already declared");
                     }
                     else{
                        char a[3] = "No";
                          insert_loc_sym_tab($1,1,false,true,scope,0,"No");
                   }
                 }
            | ID ASSIGN all_exp_rhs { 
                         if(search_loc_sym_tab_scope($1,scope)){
                                yyerror("Variable already declared");
                        }
                        else{
                                if(($<exp_rhs_attr.data_type>3 == 1 || $<exp_rhs_attr.data_type>3 == 5) && $<exp_rhs_attr.type>3 == false)
                                {
                                   insert_loc_sym_tab($1,1,false,true,scope,0,"No");
                                }
                                else {
                                        yyerror("Invalid assignment");
                                }
                         }
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
                                
            }
            | ID OPEN_CIR_PAR all_exp_rhs CLOSE_CIR_PAR OPEN_SQUARE_PAR exp_rhs CLOSE_SQUARE_PAR {
                                if(($<exp_rhs_attr.data_type>3 == 1 || $<exp_rhs_attr.data_type>3 == 5) && $<exp_rhs_attr.type>3==false){
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
            }                   
            ;
double_part : double_id_type
            | double_id_type COMMA double_part
            ;
double_id_type : ID {
                        if(search_loc_sym_tab_scope($1,scope)){
                               yyerror("Variable already declared");
                          }
                          else{
                             char a[3] = "No";
                             insert_loc_sym_tab($1,3,false,true,scope,0,"No");
                        }        
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
                                }
               ;
comp_decl : CINT cint_part
          | CDOUBLE cdouble_part
          ;
cint_part : cint_id_type
          | cint_id_type COMMA cint_part
          ;
cint_id_type : ID {
                   if(search_loc_sym_tab_scope($1,scope)){
                          yyerror("Variable already declared");
                     }
                     else{
                        char a[3] = "No";
                        insert_loc_sym_tab($1,2,false,true,scope,0,"No");
                   }       
                }
             | ID OPEN_CIR_PAR all_exp_rhs CLOSE_CIR_PAR {
                if(($<exp_rhs_attr.data_type>3 == 1 || $<exp_rhs_attr.data_type>3 == 5) && $<exp_rhs_attr.type>3==false){
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
             | ID OPEN_CIR_PAR all_exp_rhs COMMA all_exp_rhs CLOSE_CIR_PAR {
                   if(($<exp_rhs_attr.data_type>3 == 1 || $<exp_rhs_attr.data_type>3 == 5) && $<exp_rhs_attr.type>3==false){
                    if(($<exp_rhs_attr.data_type>5 == 1 || $<exp_rhs_attr.data_type>5 == 5) && $<exp_rhs_attr.type>5==false){
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
             }
             | ID OPEN_CIR_PAR all_exp_rhs CLOSE_CIR_PAR OPEN_SQUARE_PAR exp_rhs CLOSE_SQUARE_PAR {
                if(($<exp_rhs_attr.data_type>3 == 1 || $<exp_rhs_attr.data_type>3 == 5) && $<exp_rhs_attr.type>3==false){
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
             }
             | ID OPEN_CIR_PAR all_exp_rhs COMMA all_exp_rhs CLOSE_CIR_PAR OPEN_SQUARE_PAR exp_rhs CLOSE_SQUARE_PAR {
                    if(($<exp_rhs_attr.data_type>3 == 1 || $<exp_rhs_attr.data_type>3 == 5) && $<exp_rhs_attr.type>3==false){
                        if(($<exp_rhs_attr.data_type>5 == 1 || $<exp_rhs_attr.data_type>5 == 5) && $<exp_rhs_attr.type>5==false){
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
             }
             | ID ASSIGN all_exp_rhs { 
                                     if(search_loc_sym_tab_scope($1,scope)){
                                             yyerror("Variable already declared");
                                     }
                                     else{   
                                            if(($<exp_rhs_attr.data_type>3 == 1 || $<exp_rhs_attr.data_type>3 == 2 || $<exp_rhs_attr.data_type>3 == 5) && $<exp_rhs_attr.type>3 == false)
                                             {
                                                insert_loc_sym_tab($1,2,false,true,scope,0,"No");
                                             }
                                             else {   
                                                yyerror("Invalid assignment");
                                             }
                                     }
                                }
             ;
cdouble_part : cdouble_id_type
            | cdouble_id_type COMMA cdouble_part
            ;
cdouble_id_type : ID {
                   if(search_loc_sym_tab_scope($1,scope)){
                          yyerror("Variable already declared");
                     }
                     else{
                        char a[3] = "No";
                        insert_loc_sym_tab($1,4,false,true,scope,0,"No");
                   }         
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
                }
                | ID ASSIGN all_exp_rhs { 
                                     if(search_loc_sym_tab_scope($1,scope)){
                                             yyerror("Variable already declared");
                                     }
                                     else{   
                                             if($<exp_rhs_attr.data_type>3 != 6 && $<exp_rhs_attr.type>3 == false)
                                             {
                                                insert_loc_sym_tab($1,4,false,true,scope,0,"No");
                                             }
                                             else {
                                                     
                                                yyerror("Invalid assignment");
                                             }
                                     }
                                }
                ;

/*for function*/
argument : argument_list 
         | argument_list COMMA argument
         ;
argument_list : T L{    args arg_attr;
                            arg_attr.name=$<arg_name_type.arg_name>2;
                            arg_attr.dat_type.first=$1;
                            arg_attr.dat_type.second=$<arg_name_type.arg_type_bool>2;
                            
        argmnt_list.push_back(arg_attr);}
         |
         ;
T : INT{$$=1;}
 | CINT {$$=2;}
 | DOUBLE {$$=3;}
 | CDOUBLE {$$=4;}
 ;
L : ID {$<arg_name_type.arg_name>$=$1;
        $<arg_name_type.arg_type_bool>$=0;}
  | ID OPEN_SQUARE_PAR CLOSE_SQUARE_PAR{$<arg_name_type.arg_name>$=$1;
        $<arg_name_type.arg_type_bool>$=1;}
  ;

%%
  
int main(int argc,char** argv)
{
    // if(argc==0) return 0;
  ret_no=0;
  arr=(char *)calloc(1000,sizeof(char));
  int t;
  init_inbuilt();
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
  char parsed_file[100];
  l_no=1;
//   scanf("%s",input_file);
//   cout<<"HEllo bissj________________ "<<input_file<<"sinnss"<<endl;
//   sprintf(input_file,"./testcases/");
  sprintf(parsed_file,"./parser.txt");
  yyin = fopen(input_file, "r"); //open input file
  token_fp=convert_str(input_file); //open token file
  parsed_fp=fopen(parsed_file,"w"); //open token file
  if(yyin==NULL||token_fp==NULL||parsed_fp==NULL) 
  {
      printf("Error opening file s\n");
      return 0;
  }
//   fprintf(token_fp,"Name: Yoligi Govinda Rohith\nID: CS21BTECH11062\nInput file: public_test_%d.clike\n",t);
  yyparse();
  printf("Syntactically correct!\n");
  fclose(token_fp);
  fclose(parsed_fp);
  return 0;
}
void yyerror(const char * s)
{  
 fprintf (parsed_fp, "\ninvalid statement\n");
 fprintf (stderr, "error: %s ,At line no : %d\n", s,l_no);
 exit(0);
}
