#ifndef SYM_TABLE_H
#define SYM_TABLE_H

#include<bits/stdc++.h>
using namespace std;
// #include "sym.h"
// loc_Sym_tab
class args {
    public:
        string name;
        pair<short int ,bool> dat_type;
        // short int int/float/double/cdouble 
        //bool is_arr
} ;
class Fn_Symbol{
    public: 
    string fn_name;
    pair<short int,bool> ret_type;
    list <args> arg_list;
};
class loc_Sym_tab{
    public: 
    string name;
    short int data_type;
    bool type;  // type = 1 for array
    bool par_var; // par_var = 1 for parameters
    int scope;
    struct value{
        float float_val;
        string str_val;
    }val;
};
void insert_loc_sym_tab(string name,short int data_type,bool type,bool par_var,int scope,float float_val,string str_val);
void print_loc_sym_tab();
void insert_fn_sym_tab(string fn_name,pair<short int,bool> ret_type,list <args> arg_list);
void print_fn_sym_tab();
bool search_loc_sym_tab_scope(string name,int scope_no);
Fn_Symbol* search_fn_sym_tab(string fn_name);
pair<short int,bool> check_func_call (string id,list<pair<short int,bool>> arg_list);
args* search_id_loc_sym_tab(string name,int scope_no);
void create_loc_sym_tab_map();
void insert_param_into_loc(list <args> argmnt_list);
void delete_loc_sym_tab_map();
bool comp_assign_checker(short int first, short int second,bool third,bool fourth);
bool only_real_comp(short int left,short int right);
bool same_type_comp(short int left,short int right) ;
void init_inbuilt ();
FILE * convert_str (char * strc);
FILE *cpp_convert_str(char *strc);
void print_loc_sym_tab_map();
char * concater(char *a,char *b);
char * concater(char *a,char *b,char *c) ;
char * concater(char *a,char *b,char *c,char* d);
char * concater(char *a,char *b,char *c,char* d,char*e);
char * string_to_char(string str);
// unordered_map<string,loc_Sym_tab> loc_sym_tab;
// unordered_map<string,Fn_Symbol> fn_sym_tab;

#endif