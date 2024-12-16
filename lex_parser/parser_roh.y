%{
#include <stdio.h>
#include <ctype.h>
char *arr;
int l_no=1;
FILE *parsed_fp;
int ret_no;
%}

%token ID_T 
%token CONST_T
%token STR_T
%token CHAR_T
%token COMP_OP
%token NEG_OP
%token UNARY_OP
%token ARTH_OP
%token TF_TOKEN
%token RETURN_TOKEN
%token SCOPE_TOKEN
%token CLASS_TOKEN
%token DECLARE_TOKEN
%token EXPR_TOKEN
%token CALL_TOKEN
%token THIS_TOKEN
%token LOOP_WHILE
%token IF_TOKEN
%token ELSE_TOKEN
%token ARROW_TOKEN
%token DTYPE_TOKEN
%token EQ_TOKEN
%token DO_TOKEN
%token FOR_TOKEN
%token SEMI_TOKEN
%token COMMA_TOKEN
%token OPARAN_TOKEN
%token CPARAN_TOKEN
%token OSQ_TOKEN
%token CSQ_TOKEN
%token OBRACE_TOKEN
%token CBRACE_TOKEN
%token VOID_TOKEN
%left COMP_OP
%right NEG_OP

%%
program : type
        | 
        ;
type    : CLASS_TOKEN class_decl program 
        | SCOPE_TOKEN func_decl program
        ;
cust_dtype : DTYPE_TOKEN 
           | VOID_TOKEN 
           ;
/*Function declaration here*/
fn_foo: cust_dtype ID_T fn_name OPARAN_TOKEN params CPARAN_TOKEN {fprintf(parsed_fp," : function definiton");ret_no=0;}
      ;
func_decl: fn_foo OBRACE_TOKEN stmts CBRACE_TOKEN {
        if(ret_no==0) yyerror("Atleast one return statement expected");
}
        ; 
/*Optional square paranthesis*/
fn_name : OSQ_TOKEN CONST_T CSQ_TOKEN  
        | /*Epsilon*/ 
        ;
/*Parameters list*/
params : params_list 
       | /*Epsilon*/ 
       ;
params_list : params_decl param_temp 
            ;
params_decl : DTYPE_TOKEN ID_T  
            | ID_T ID_T /*This thing to call class */  
            ;
param_temp :  COMMA_TOKEN params_list  
            | /*Epsilon*/  
            ;
/*CFG for grammar*/
stmts : stmt_types stmts 
      | /*Epsilon*/ 
      | OPARAN_TOKEN stmts CPARAN_TOKEN 
      ;
/*CFG for identifying id_list(x,y,z)*/
id_list : ID_T COMMA_TOKEN id_list  
        | OPARAN_TOKEN id_list CPARAN_TOKEN  
        | ID_T SEMI_TOKEN
        ;
/*CFG for all type of statements*/
stmt_types : decl_stmt  {fprintf(parsed_fp," : declaration statement");}
           | EXPR_TOKEN expr_stmt  {fprintf(parsed_fp," : expression statement");}
           | cond_stmt  
           | loop_stmt  
           | for_loop_stmt 
           | ret_stmt {fprintf(parsed_fp," : return statement");ret_no++;}
           | unary_stmt SEMI_TOKEN  {fprintf(parsed_fp," : call statement");}
           | CALL_TOKEN fn_call_stmt SEMI_TOKEN  {fprintf(parsed_fp," : call statement");}
           | CALL_TOKEN class_call_stmt SEMI_TOKEN  {fprintf(parsed_fp," : call statement with object");}
           ;
/*Declaration statements*/
decl_stmt: DECLARE_TOKEN DTYPE_TOKEN id_list 
         | DECLARE_TOKEN ID_T id_list 
         ;
/*Expression statements*/
expr_stmt: ID_T EQ_TOKEN exp_rhs SEMI_TOKEN
         ;
call_params : exp_rhs COMMA_TOKEN call_params 
            | exp_rhs CPARAN_TOKEN 
            ;
fn_tempy : call_params
         | CPARAN_TOKEN
         ;
/*Function call statements*/
fn_call_stmt : ID_T  fn_name OPARAN_TOKEN fn_tempy 
             ; 
if_this : THIS_TOKEN
        | ID_T
        ;

/*class calling statements*/
class_call_stmt: if_this ARROW_TOKEN ID_T fn_name OPARAN_TOKEN fn_tempy
               ; 

/*conditional statements*/
if_foo : IF_TOKEN OPARAN_TOKEN predicate CPARAN_TOKEN  {fprintf(parsed_fp," : conditional statement");}
       ;
else_foo : ELSE_TOKEN  {fprintf(parsed_fp," : conditional statement");}
         ;
cond_stmt : if_foo DO_TOKEN OBRACE_TOKEN stmts CBRACE_TOKEN else_foo OBRACE_TOKEN stmts CBRACE_TOKEN
          | if_foo DO_TOKEN OBRACE_TOKEN stmts CBRACE_TOKEN
          ;

/*loop statements*/
loop_foo : LOOP_WHILE OPARAN_TOKEN exp_rhs CPARAN_TOKEN {fprintf(parsed_fp," : loop");}
        ;
loop_stmt: loop_foo DO_TOKEN OBRACE_TOKEN stmts CBRACE_TOKEN
         ;

cust_unary : unary_stmt
           | /*Epsilon*/
           ;
in_for : in_for_fpart SEMI_TOKEN predicate SEMI_TOKEN cust_unary 
       ;
in_for_fpart: EXPR_TOKEN ID_T EQ_TOKEN exp_rhs 
            | /*Epsilon*/
            | OPARAN_TOKEN in_for_fpart CPARAN_TOKEN
            ;
/*predicate statements*/
predicate : NEG_OP exp_rhs 
          | exp_rhs COMP_OP exp_rhs
          | OPARAN_TOKEN predicate CPARAN_TOKEN
          | predicate COMP_OP predicate
          | /*Epsilon*/
          ;
/*For loop statements*/
for_foo : FOR_TOKEN OPARAN_TOKEN in_for CPARAN_TOKEN {fprintf(parsed_fp," : loop");}
        ;       
for_loop_stmt : for_foo OBRACE_TOKEN stmts CBRACE_TOKEN
         ;

/*Return statements*/
ret_stmt : RETURN_TOKEN ret_type SEMI_TOKEN 
         ;
ret_type : VOID_TOKEN
         | exp_rhs
         ;
unary_stmt : UNARY_OP OPARAN_TOKEN exp_rhs CPARAN_TOKEN
           | NEG_OP exp_rhs
           | OPARAN_TOKEN unary_stmt CPARAN_TOKEN
           ;
            
/*Identifying the RHS side of an expression*/
exp_rhs : OPARAN_TOKEN exp_rhs CPARAN_TOKEN 
        | ARTH_OP OPARAN_TOKEN exp_rhs COMMA_TOKEN exp_rhs CPARAN_TOKEN 
        | UNARY_OP OPARAN_TOKEN exp_rhs CPARAN_TOKEN
        | NEG_OP exp_rhs 
        | exp_rhs COMP_OP exp_rhs
        | ID_T
        | CONST_T
        | STR_T
        | CHAR_T
        | TF_TOKEN
        | fn_call_stmt 
        | class_call_stmt
        ;
/*Class declaration here*/
class_foo : ID_T fn_name {fprintf(parsed_fp," : class definition");}
          ;
class_decl : class_foo OBRACE_TOKEN body CBRACE_TOKEN
           ;
body : body class_fun
     | stmts class_fun
     ;
class_fun : SCOPE_TOKEN func_decl
          |
          ;
          
%%
#include "lex.yy.c"

void yyerror(char * s)
/* yacc error handler */
{  
 fprintf (parsed_fp, "\ninvalid statement\n");
 fprintf (stderr, "Error: %s ,At line no : %d\n", s,l_no);
 exit(0);
}
  
int main()
{
  ret_no=0;
  arr=(char *)calloc(1000,sizeof(char));
  int t;
  printf("Enter test case number: ");
  scanf("%d",&t);
  char input_file[100];
  char token_file[100];
  char parsed_file[100];
  sprintf(input_file,"./TPP/public_test_%d.clike",t);
  sprintf(token_file,"./TPP/TPPO/seq_tokens_%d.txt",t);
  sprintf(parsed_file,"./TPP/TPPO/parser_%d.parsed",t);
  yyin = fopen(input_file, "r"); //open input file
  token_fp=fopen(token_file,"w"); //open token file
  parsed_fp=fopen(parsed_file,"w"); //open token file
  if(yyin==NULL||token_fp==NULL||parsed_fp==NULL) 
  {
      printf("Error opening file s\n");
      return 0;
  }
  fprintf(token_fp,"Name: Yoligi Govinda Rohith\nID: CS21BTECH11062\nInput file: public_test_%d.clike\n",t);
  yyparse();
//   printf("Syntactically correct!\n");
  fclose(token_fp);
  fclose(parsed_fp);
  return 0;
}
