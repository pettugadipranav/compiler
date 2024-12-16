
#include "sym_table.h"
#include <bits/stdc++.h>
using namespace std;
vector<unordered_map<string, loc_Sym_tab>> loc_sym_tab;
unordered_map<string, Fn_Symbol> fn_sym_tab;
void create_loc_sym_tab_map() // creates local symbol table
{
    cout << "create_loc_sym_tab_map" << endl;
    unordered_map<string, loc_Sym_tab> temp;
    loc_sym_tab.push_back(temp);
    // cout<<"vectorsize-"<<loc_sym_tab.size()<<endl;
}
void delete_loc_sym_tab_map() // deletes local symbol table
{
    cout << "delete_loc_sym_tab_map" << endl;
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
args *search_id_loc_sym_tab(string name, int scope_no) // searches the name in the local symbol table in each and every scope.
{
    cout << "search_id_loc_sym_tab--" << name << scope_no << endl;
    args *temp = new args;
    //  print_loc_sym_tab();

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
bool comp_assign_checker(short int first, short int second, bool third, bool fourth) 
{
    cout << first << "-" << second << "-" << third << "-" << fourth << endl;
    if (third != fourth)
    {
        // cout<<"qwertyuiop"<<endl;
        return false;
    }
    if (first == 1 || first == 3 || first == 5)
    {
        if (second == 1 || second == 3 || second == 5)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return true;
}
FILE *convert_str(char *strc)
{
    string str1(strc);

    if (str1.size() >= 6)
    {
        str1.resize(str1.size() - 6);
    }

    str1 += "_token.txt";

    const char *cstr = str1.c_str();
    cout << cstr << endl;
    FILE *fp = fopen(cstr, "w");
    return fp;
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
