#include "sym_table.h"
#include <bits/stdc++.h>
using namespace std;
vector<unordered_map<string, loc_Sym_tab>> loc_sym_tab;
unordered_map<string, Fn_Symbol> fn_sym_tab;

char * concater(char *a,char *b) {
    string s1(a);
    // cout<<"string checkking=====2"<<s1<<endl;
    string s2(b);
    string s3 = s1 + s2;
     char*s4 =(char*)malloc(sizeof(char)*(s1.size()+s2.size()+1));
    strcpy(s4,s3.c_str());
    // cout<<"string checkking=====2"<<s4<<endl;
    return s4;
}
char * concater(char *a,char *b,char *c) {
    string s1(a);
    // cout<<"string checkking======3"<<s1<<endl;
    string s2(b);
    string s3(c);
    string s4 = s1 + s2 + s3;
    char*s5 =(char*)malloc(sizeof(char)*(s1.size()+s2.size()+s3.size()+1));
    strcpy(s5,s4.c_str());
    // cout<<"string checkking======3"<<s5<<endl;
    return s5;
  
}

char * concater(char *a,char *b,char *c,char* d) {
    string s1(a);
    // cout<<"string checkking====4"<<s1<<endl;
    string s2(b);
    string s3(c);
    string s4(d);
    // cout<<"string checkking====4"<<s2<<endl;
    // cout<<"string checkking====4"<<s3<<endl;
    // cout<<"string checkking====4"<<s4<<endl;
    string s5 = s1 + s2 + s3 +s4;
    char*s6 =(char*)malloc(sizeof(char)*(s1.size()+s2.size()+s3.size()+s4.size()+1));
    strcpy(s6,s5.c_str());
    // cout<<"string checkking=====4"<<s6<<endl;

    return s6;
}

char * concater(char *a,char *b,char *c,char* d,char*e) {
    string s1(a);
    // cout<<"string checkking====5"<<s1<<endl;
    string s2(b);
    string s3(c);
    string s4(d);
    string s5(e);
    string s6 = s1 + s2 + s3 +s4+s5;
    char*s7 =(char*)malloc(sizeof(char)*(s1.size()+s2.size()+s3.size()+s4.size()+s5.size()+1));
    strcpy(s7,s6.c_str());
    // cout<<"string checkking=====5"<<s7<<endl;

    return s7;
}

char * string_to_char(string str)
{
    char *cstr = new char[str.length() + 1];
    strcpy(cstr, str.c_str());
    return cstr;
}

void fp_prnt(FILE* fp,char *str)
{
    fprintf(fp,"%s",str);
}

void create_loc_sym_tab_map() // creates local symbol table
{
    cout << "create_loc_sym_tab_map" << endl;
    unordered_map<string, loc_Sym_tab> temp;
    loc_sym_tab.push_back(temp);
    // cout<<"vectorsize-"<<loc_sym_tab.size()<<endl;
}
void delete_loc_sym_tab_map() // deletes local symbol table
{
    cout << "delete_loc_sym_tab_map"<< endl;
    loc_sym_tab.pop_back();
}
void print_loc_sym_tab() // for debugging
{
    int a = 0;
    cout << "print_loc_sym_tab" << endl;
    cout << "Name\tData Type\tType\tPar Var\tScope\tValue\n";
    for (auto i : loc_sym_tab)
    {
        cout << a << endl;
        cout << "loc_sym_tab" << endl;
        for (auto j : i)
        {
            cout << "name-" << j.first << "|-|" << j.second.name << "\t" << j.second.data_type << "\t" << j.second.type << "\t" << j.second.par_var << "\t" << j.second.scope << "\t" << endl;
        }
        a++;
    }
}

void insert_loc_sym_tab(string name, short int data_type, bool type, bool par_var, int scope, float float_val, string str_val) // inserting entry into the local symbol table for the respective scope
{
    cout << "insert_loc_sym_tab" << endl;
    // cout<<name<<"-"<<data_type<<"-"<<type<<"-"<<par_var<<"-"<<scope<<endl;
    // cout<<loc_sym_tab.size()<<endl;
    loc_Sym_tab temp;

    temp.name = name;
    temp.data_type = data_type;
    temp.type = type;       // type = 1 for array
    temp.par_var = par_var; // var = 1 for parameters
    temp.scope = scope;
    temp.val.float_val = float_val;
    temp.val.str_val = str_val;
    cout << "vector size=" << loc_sym_tab.size() << endl;
    loc_sym_tab[loc_sym_tab.size() - 1][name] = temp;

    cout << name << "-" << data_type << "-" << type << "-" << par_var << "-" << scope << endl;
}

void insert_fn_sym_tab(string fn_name, pair<short int, bool> ret_type, list<args> arg_list) // inserting entry into the function symbol table
{
    cout<<"size loc"<<loc_sym_tab.size()<<endl;
    print_loc_sym_tab();
    cout << "insert_fn_sym_tab" << endl;
    Fn_Symbol temp;
    temp.fn_name = fn_name;
    temp.ret_type = ret_type;
    temp.arg_list = arg_list;
    fn_sym_tab[fn_name] = temp;
}
void print_fn_sym_tab() // for debugging
{
    // cout<<"print_fn_sym_tab"<<endl;
    // cout<<"=-=---"<<endl;
    // cout<<"Fn Name\tret_type\tType\tArg List\n";
    for (auto i : fn_sym_tab)
    {
        cout << "name-" << i.second.fn_name << "\t"
             << "ret_type-" << i.second.ret_type.first << "\t"
             << "type-" << i.second.ret_type.second << "\t";
        for (auto j : i.second.arg_list)
        {
            cout << "arg_list="
                 << "arg_name-" << j.name << "\t"
                 << "arg_datatype-" << j.dat_type.first << "\t"
                 << "arg_type-" << j.dat_type.second << "\t";
            cout << "\n";
        }
        cout << "\n";
    }
}
bool search_loc_sym_tab_scope(string name, int scope_no) // searches for the entry in the local symbol table for the respective scope and then it checks wheather it is declared in the parameters local symbol table
{
    cout << "search_loc_sym_tab_scope" << name << "--" << scope_no << endl;
    // print_loc_sym_tab();
    cout<<"size checking"<<loc_sym_tab.size()<<endl;
    if (loc_sym_tab.size() == 0)
    {
        return false;
    }
    else if (loc_sym_tab[scope_no - 1].find(name) != loc_sym_tab[scope_no - 1].end())
    {
        return true;
    }
    else if (loc_sym_tab[0].find(name) != loc_sym_tab[0].end())
    {
        return true;
    }
    return false;
}

Fn_Symbol *search_fn_sym_tab(string fn_name) // searches wheather the name of the function is present in the function symbol table
{
    cout << "search_fn_sym_tab" << fn_name << endl;
    if (fn_sym_tab.find(fn_name) != fn_sym_tab.end())
    {
        return &fn_sym_tab[fn_name];
    }
    return NULL;
}

void insert_param_into_loc(list<args> argmnt_list) // inserts the parameters into the local symbol table
{
    cout << "insert_param_into_loc" << endl;
    for (auto i : argmnt_list)
    {
        insert_loc_sym_tab(i.name, i.dat_type.first, i.dat_type.second, 1, 1, 0, "");
    }
}
pair<short int, bool> check_func_call(string id, list<pair<short int, bool>> arg_list) // checks wheather the function arguements are matching with the function declaration
{  
    // cout <<arg_list<<endl;
    // print_fn_sym_tab();   
    cout << "check_func_call" << id<<endl;
    auto it = fn_sym_tab.find(id);
    if (it == fn_sym_tab.end())
    {
        return make_pair(-1, 0);
    }
    Fn_Symbol temp = it->second;
    if (temp.arg_list.size() != arg_list.size())
    {
        // cout<<arg_list.size()<<"qwertyuioplkjhgfa"<<temp.arg_list.size()<<endl;
        return {-2, 0};
    }
    reverse(arg_list.begin(), arg_list.end());
    auto it1 = temp.arg_list.begin();
    auto it2 = arg_list.begin();
    while (it1 != temp.arg_list.end())
    {
        // if(it1->dat_type!=*it2){
        //     return {-2,0};
        // }
        short int param_dat_type = it1->dat_type.first;
        short int arg_dat_type = it2->first;
        bool param_type = it1->dat_type.second;
        bool arg_type = it2->second;
        if (param_type != arg_type)
        {
            cout<< it1->name<<param_type<<"qwertyuiop"<<arg_type<<endl;

            return {-2, 0};
        }
        else
        {
            if (param_dat_type == 4 || param_dat_type == 2)
            {
                if ( arg_dat_type == 2 ||  arg_dat_type == 4 )
                {
                    return temp.ret_type;
                }
                else
                {
                    return {-2, 0};
                }
            }
            // else if (param_dat_type == 2)
            // {
            //     if (arg_dat_type == 1 || arg_dat_type == 2 || arg_dat_type == 5)
            //     {
            //         return temp.ret_type;
            //     }
            //     else
            //     {
            //         return {-2, 0};
            //     }
            // }
            else if (param_dat_type == 1 || param_dat_type == 3)
            {
                if (arg_dat_type == 1 || arg_dat_type == 3 || arg_dat_type == 5)
                {
                    return temp.ret_type;
                }
                else
                {
                    return {-2, 0};
                }
            }
            // else if (param_dat_type == 1)
            // {
            //     if (arg_dat_type == 1 || arg_dat_type == 5)
            //     {
            //         return temp.ret_type;
            //     }
            //     else
            //     {
            //         return {-2, 0};
            //     }
            // }
            // else if (param_dat_type == arg_dat_type)
            // {
            //     return temp.ret_type;
            // }
            // else
            // {
            //     return {-2, 0};
            // }
        }
        it1++;
        it2++;
    }
    return temp.ret_type;
}

args *search_id_loc_sym_tab(string name, int scope_no) // searches the name in the local symbol table in each and every scope.
{
    cout << "search_id_loc_sym_tab--" << name << scope_no << endl;
    args *temp = new args;
    // print_loc_sym_tab();

    while (scope_no > 0)
    {
        // cout<<"scope_no="<<scope_no<<endl;
        // cout<<"*************"<<endl;
        if (loc_sym_tab[scope_no - 1].find(name) != loc_sym_tab[scope_no - 1].end())
        {
            //     cout<<"*************"<<endl;
            temp->name = loc_sym_tab[scope_no - 1][name].name;
            temp->dat_type.first = loc_sym_tab[scope_no - 1][name].data_type;
            temp->dat_type.second = loc_sym_tab[scope_no - 1][name].type;
            return temp;
        }

        scope_no--;
    }
    // cout<<"Hello world"<<endl;
    return NULL;
}


bool only_real_comp(short int left, short int right)// checks wheather the comparision is between real numbers
{
    // applicable only for <,>,<=,>=
    if (left == 1 || left == 3 || left == 5)
    {
        // only int,double,bool
        if (right == 1 || right == 3 || right == 5)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

bool same_type_comp(short int left, short int right) // checks wheather the comparision is between same type
{
    if (only_real_comp(left, right))
        return true; // implies both are real numbers;
    if (left == right)
        return true;
    // left should be always more
    if (left == 4 || right == 2)
    {
        return true;
    }
    if (left == 2 || right == 4)
    {
        return true;
    }
    return false;
}

bool comp_assign_checker(short int first, short int second, bool third, bool fourth) 
{
    
    if(third!=fourth){
        return false;
    }
    if (only_real_comp(first, second)){
        cout<<"only real"<<endl;
        return true;
    } // implies both are real numbers;
    if (first == second){
        cout<<"both equal"<<endl;
        return true;
    }
    // left should be always more
    if (first == 4 && (second == 2|| second==4))
    {
        cout<<"left is 4 right2"<<endl;
        return true;
    }
    if (first == 2 &&  (second == 2|| second==4))
    {
        cout<<"left is 2 "<<endl;
        return true;
    }
    return false;
}

FILE *cpp_convert_str(char *strc)
{
    strc+=12;
    string str1(strc);
    cout<<str1<<" [[[[[[[[[[]]]]]]]]]] "<<endl;
    if (str1.size() >= 4)
    {
        str1.resize(str1.size() - 4);
    }

    str1 += ".cpp";
    str1 = "./code/" + str1;
    const char *cstr = str1.c_str();
    cout << cstr << endl;
    FILE *fp = fopen(cstr, "w");
    return fp;
}

FILE *convert_str(char *strc)
{
    strc+=12;
    string str1(strc);

    if (str1.size() >= 4)
    {
        str1.resize(str1.size() - 4);
    }

    str1 += "_token.txt";
    str1 = "./logs/" + str1;
    const char *cstr = str1.c_str();
    cout << cstr << endl;
    FILE *fp = fopen(cstr, "w");
    return fp;
}



// 1--> for int
// 2--> for double
// 3--> for cint (complex int)
// 4--> for cdouble (complex double)
// 5--> for bool
// 6--> for string
// 0--> for void
// bool data type true==> it is array
// bool data type false==> it is not an array
// clas components

// string fn_name;
//  pair<short int,bool> ret_type;
//  list <args> arg_list;

/* These are the functions insert function name, arguments and their datatypes, types in the func_sym_table */
void real_fn(Fn_Symbol exist)
{
    exist.fn_name = "real";
    exist.ret_type.first = 3;
    exist.ret_type.second = false;
    args temp;
    temp.name = "x";
    temp.dat_type.first = 4;
    temp.dat_type.second = false;
    exist.arg_list.push_back(temp);
    fn_sym_tab[exist.fn_name] = exist;
}

void img_fn(Fn_Symbol exist)
{
    exist.fn_name = "img";
    exist.ret_type.first = 3;
    exist.ret_type.second = false;
    args temp;
    temp.name = "x";
    temp.dat_type.first = 4;
    temp.dat_type.second = false;
    exist.arg_list.push_back(temp);
    fn_sym_tab[exist.fn_name] = exist;
}
void real_pow_fn(Fn_Symbol exist)
{
    exist.fn_name = "real_pow";
    exist.ret_type.first = 3;
    exist.ret_type.second = false;
    args temp1;
    temp1.name = "x";
    temp1.dat_type.first = 3;
    temp1.dat_type.second = false;
    exist.arg_list.push_back(temp1);
    args temp2;
    temp2.name = "y";
    temp2.dat_type.first = 3;
    temp2.dat_type.second = false;
    exist.arg_list.push_back(temp2);

    fn_sym_tab[exist.fn_name] = exist;
}
void complex_pow_fn(Fn_Symbol exist)
{
    exist.fn_name = "complex_pow";
    exist.ret_type.first = 4;
    exist.ret_type.second = false;
    args temp1;
    temp1.name = "x";
    temp1.dat_type.first = 4;
    temp1.dat_type.second = false;
    exist.arg_list.push_back(temp1);
    args temp2;
    temp2.name = "y";
    temp2.dat_type.first = 3;
    temp2.dat_type.second = false;
    exist.arg_list.push_back(temp2);

    fn_sym_tab[exist.fn_name] = exist;
}
void polar_fn(Fn_Symbol exist)
{
    exist.fn_name = "polar";
    exist.ret_type.first = 0;
    exist.ret_type.second = false;
    args temp;
    temp.name = "x";
    temp.dat_type.first = 4;
    temp.dat_type.second = false;
    exist.arg_list.push_back(temp);
    fn_sym_tab[exist.fn_name] = exist;
}
void conjugate_fn(Fn_Symbol exist)
{
    exist.fn_name = "conjugate";
    exist.ret_type.first = 4;
    exist.ret_type.second = false;
    args temp;
    temp.name = "x";
    temp.dat_type.first = 4;
    temp.dat_type.second = false;
    exist.arg_list.push_back(temp);
    fn_sym_tab[exist.fn_name] = exist;
}
void mod_fn(Fn_Symbol exist)
{
    exist.fn_name = "mod";
    exist.ret_type.first = 3;
    exist.ret_type.second = false;
    args temp;
    temp.name = "x";
    temp.dat_type.first = 4;
    temp.dat_type.second = false;
    exist.arg_list.push_back(temp);
    fn_sym_tab[exist.fn_name] = exist;
}
void arg_fn(Fn_Symbol exist)
{
    exist.fn_name = "arg";
    exist.ret_type.first = 3;
    exist.ret_type.second = false;
    args temp;
    temp.name = "x";
    temp.dat_type.first = 4;
    temp.dat_type.second = false;
    exist.arg_list.push_back(temp);
    fn_sym_tab[exist.fn_name] = exist;
}
void angle_fn(Fn_Symbol exist)
{
    exist.fn_name = "angle";
    exist.ret_type.first = 3;
    exist.ret_type.second = false;
    args temp;
    temp.name = "x";
    temp.dat_type.first = 4;
    temp.dat_type.second = false;
    exist.arg_list.push_back(temp);
    fn_sym_tab[exist.fn_name] = exist;
}
void dist_fn(Fn_Symbol exist)
{
    exist.fn_name = "dist";
    exist.ret_type.first = 3;
    exist.ret_type.second = false;
    args temp1;
    temp1.name = "x";
    temp1.dat_type.first = 4;
    temp1.dat_type.second = false;
    exist.arg_list.push_back(temp1);
    args temp2;
    temp2.name = "y";
    temp2.dat_type.first = 4;
    temp2.dat_type.second = false;
    exist.arg_list.push_back(temp2);
    fn_sym_tab[exist.fn_name] = exist;
}
void cprint_fn(Fn_Symbol exist)
{
    exist.fn_name = "cprint";
    exist.ret_type.first = 0;
    exist.ret_type.second = false;
    args temp;
    temp.name = "x";
    temp.dat_type.first = 4;
    temp.dat_type.second = false;
    exist.arg_list.push_back(temp);
    fn_sym_tab[exist.fn_name] = exist;
}
void rotate_fn(Fn_Symbol exist)
{
    exist.fn_name = "rotate";
    exist.ret_type.first = 4;
    exist.ret_type.second = false;
    args temp1;
    temp1.name = "x";
    temp1.dat_type.first = 4;
    temp1.dat_type.second = false;
    exist.arg_list.push_back(temp1);
    args temp2;
    temp2.name = "y";
    temp2.dat_type.first = 4;
    temp2.dat_type.second = false;
    exist.arg_list.push_back(temp2);
    args temp3;
    temp3.name = "z";
    temp3.dat_type.first = 3;
    temp3.dat_type.second = false;
    exist.arg_list.push_back(temp3);
    fn_sym_tab[exist.fn_name] = exist;
}
void get_line_fn(Fn_Symbol exist)
{
    exist.fn_name = "get_line";
    exist.ret_type.first = 0;
    exist.ret_type.second = false;
    args temp1;
    temp1.name = "x";
    temp1.dat_type.first = 4;
    temp1.dat_type.second = false;
    exist.arg_list.push_back(temp1);
    args temp2;
    temp2.name = "y";
    temp2.dat_type.first = 4;
    temp2.dat_type.second = false;
    exist.arg_list.push_back(temp2);
    fn_sym_tab[exist.fn_name] = exist;
}
void is_triangle_fn(Fn_Symbol exist)
{
    exist.fn_name = "is_triangle";
    exist.ret_type.first = 5;
    exist.ret_type.second = false;
    args temp1;
    temp1.name = "x";
    temp1.dat_type.first = 4;
    temp1.dat_type.second = false;
    exist.arg_list.push_back(temp1);
    args temp2;
    temp2.name = "y";
    temp2.dat_type.first = 4;
    temp2.dat_type.second = false;
    exist.arg_list.push_back(temp2);
    args temp3;
    temp3.name = "z";
    temp3.dat_type.first = 4;
    temp3.dat_type.second = false;
    exist.arg_list.push_back(temp3);
    fn_sym_tab[exist.fn_name] = exist;
}
void get_centroid_fn(Fn_Symbol exist)
{
    exist.fn_name = "get_centroid";
    exist.ret_type.first = 4;
    exist.ret_type.second = false;
    args temp1;
    temp1.name = "x";
    temp1.dat_type.first = 4;
    temp1.dat_type.second = false;
    exist.arg_list.push_back(temp1);
    args temp2;
    temp2.name = "y";
    temp2.dat_type.first = 4;
    temp2.dat_type.second = false;
    exist.arg_list.push_back(temp2);
    args temp3;
    temp3.name = "z";
    temp3.dat_type.first = 4;
    temp3.dat_type.second = false;
    exist.arg_list.push_back(temp3);
    fn_sym_tab[exist.fn_name] = exist;
}
void get_circumcenter_fn(Fn_Symbol exist)
{
    exist.fn_name = "get_circumcenter";
    exist.ret_type.first = 4;
    exist.ret_type.second = false;
    args temp1;
    temp1.name = "x";
    temp1.dat_type.first = 4;
    temp1.dat_type.second = false;
    exist.arg_list.push_back(temp1);
    args temp2;
    temp2.name = "y";
    temp2.dat_type.first = 4;
    temp2.dat_type.second = false;
    exist.arg_list.push_back(temp2);
    args temp3;
    temp3.name = "z";
    temp3.dat_type.first = 4;
    temp3.dat_type.second = false;
    exist.arg_list.push_back(temp3);
    fn_sym_tab[exist.fn_name] = exist;
}
void get_orthocenter_fn(Fn_Symbol exist)
{
    exist.fn_name = "get_orthocenter";
    exist.ret_type.first = 4;
    exist.ret_type.second = false;
    args temp1;
    temp1.name = "x";
    temp1.dat_type.first = 4;
    temp1.dat_type.second = false;
    exist.arg_list.push_back(temp1);
    args temp2;
    temp2.name = "y";
    temp2.dat_type.first = 4;
    temp2.dat_type.second = false;
    exist.arg_list.push_back(temp2);
    args temp3;
    temp3.name = "z";
    temp3.dat_type.first = 4;
    temp3.dat_type.second = false;
    exist.arg_list.push_back(temp3);
    fn_sym_tab[exist.fn_name] = exist;
}
void get_excenter_fn(Fn_Symbol exist)
{
    exist.fn_name = "get_excenter";
    exist.ret_type.first = 4;
    exist.ret_type.second = false;
    args temp1;
    temp1.name = "x";
    temp1.dat_type.first = 4;
    temp1.dat_type.second = false;
    exist.arg_list.push_back(temp1);
    args temp2;
    temp2.name = "y";
    temp2.dat_type.first = 4;
    temp2.dat_type.second = false;
    exist.arg_list.push_back(temp2);
    args temp3;
    temp3.name = "z";
    temp3.dat_type.first = 4;
    temp3.dat_type.second = false;
    exist.arg_list.push_back(temp3);
    fn_sym_tab[exist.fn_name] = exist;
}
void get_incenter_fn(Fn_Symbol exist)
{
    exist.fn_name = "get_incenter";
    exist.ret_type.first = 4;
    exist.ret_type.second = false;
    args temp1;
    temp1.name = "x";
    temp1.dat_type.first = 4;
    temp1.dat_type.second = false;
    exist.arg_list.push_back(temp1);
    args temp2;
    temp2.name = "y";
    temp2.dat_type.first = 4;
    temp2.dat_type.second = false;
    exist.arg_list.push_back(temp2);
    args temp3;
    temp3.name = "z";
    temp3.dat_type.first = 4;
    temp3.dat_type.second = false;
    exist.arg_list.push_back(temp3);
    fn_sym_tab[exist.fn_name] = exist;
}
void get_area_fn(Fn_Symbol exist)
{
    exist.fn_name = "get_area";
    exist.ret_type.first = 3;
    exist.ret_type.second = false;
    args temp1;
    temp1.name = "x";
    temp1.dat_type.first = 4;
    temp1.dat_type.second = false;
    exist.arg_list.push_back(temp1);
    args temp2;
    temp2.name = "y";
    temp2.dat_type.first = 4;
    temp2.dat_type.second = false;
    exist.arg_list.push_back(temp2);
    args temp3;
    temp3.name = "z";
    temp3.dat_type.first = 4;
    temp3.dat_type.second = false;
    exist.arg_list.push_back(temp3);
    fn_sym_tab[exist.fn_name] = exist;
}
void get_perimeter_fn(Fn_Symbol exist)
{
    exist.fn_name = "get_perimeter";
    exist.ret_type.first = 3;
    exist.ret_type.second = false;
    args temp1;
    temp1.name = "x";
    temp1.dat_type.first = 4;
    temp1.dat_type.second = false;
    exist.arg_list.push_back(temp1);
    args temp2;
    temp2.name = "y";
    temp2.dat_type.first = 4;
    temp2.dat_type.second = false;
    exist.arg_list.push_back(temp2);
    args temp3;
    temp3.name = "z";
    temp3.dat_type.first = 4;
    temp3.dat_type.second = false;
    exist.arg_list.push_back(temp3);
    fn_sym_tab[exist.fn_name] = exist;
}

void init_inbuilt()
{
    // for fn_sym_table
    Fn_Symbol exist;
    real_fn(exist);
    img_fn(exist);
    real_pow_fn(exist);
    complex_pow_fn(exist);
    polar_fn(exist);
    conjugate_fn(exist);
    mod_fn(exist);
    arg_fn(exist);
    angle_fn(exist);
    dist_fn(exist);
    cprint_fn(exist);
    rotate_fn(exist);
    get_line_fn(exist);
    is_triangle_fn(exist);
    get_centroid_fn(exist);
    get_circumcenter_fn(exist);
    get_orthocenter_fn(exist);
    get_excenter_fn(exist);
    get_incenter_fn(exist);
    get_area_fn(exist);
    get_perimeter_fn(exist);
}

// for inbuilt functions list