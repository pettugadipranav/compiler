# Command to run
flex lexer.l
yacc parser.y -d -v
gcc  y.tab.c -ll
./a.out < input.txt

# Note : Prohibited
You can intiliase like cint a(3) --> a=3i
but a= (3) is invalid
but a= (3,4) is valid ==>a=3+4i
for pure complex intialise a=(0,3) ->a=3i

TBD:
check exp_rhs for a=(3,true or fale) //what to do here??

stmt_types : assign_stmt SEMICOL
           | decl_stmt SEMICOL
           | if_stmt SEMICOL
           | for_stmt 
           | while_stmt 
           | return_stmt SEMICOL      
           ;

predicate : exp_rhs GT exp_rhs
          | exp_rhs LT exp_rhs
          | exp_rhs EQ exp_rhs
          | exp_rhs NE exp_rhs
          | exp_rhs GE exp_rhs
          | exp_rhs LE exp_rhs
          | exp_rhs AND exp_rhs
          | exp_rhs OR exp_rhs
          | NEG predicate
          | OPEN_CIR_PAR predicate CLOSE_CIR_PAR
          ;
S : temp S
  | /*Epsilon*/
  ;
temp :  
        | REAL
        | IMG
        | POW
        | POLAR
        | CONJUGATE
        | MOD
        | ARG
        | ANGLE
        | DIST
        | CPRINT
        | ROTATE
        | GET_LINE
        | IS_TRIANGLE
        | GET_CENTROID
        | GET_CIRCUMCENTER
        | GET_ORTHOCENTER
        | GET_INCENTER
        | GET_EXCENTER
        | GET_AREA
        | GET_PERIMETER