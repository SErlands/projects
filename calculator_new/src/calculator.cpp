#include "calculator.h"
#include "string_handling.h"
#include "tree.h"

#include <iostream>
#include <ostream>
#include <algorithm>
#include <string>

Inter_face::Inter_face(){
    this->root_arr = new Tree_node*[10];
    this->quit_program = false;
}

Inter_face::~Inter_face(){

    for(int i=0; i<=9; i++){
        if(this->root_arr[i] != nullptr)
            delete this->root_arr[i];
    }

    delete[] this->root_arr;
    return;
}

void Inter_face::welcome_message(){
    std::cout << "Welcome to this calculator!" << std::endl;
    return;
}

void Inter_face::end_message(){
    std::cout<<"Thank you for using this calculator"<<std::endl;
    return;
}

void Inter_face::help_message(){
    std::cout<<"+----- Command list -----+"<<std::endl;
    std::cout<<"+ 'h' commandlist        +"<<std::endl;
    std::cout<<"+ 'i' input equation     +"<<std::endl;
    std::cout<<"+ 'p' print equations    +"<<std::endl;
    std::cout<<"+ 'c' evaluate equation  +"<<std::endl;
    std::cout<<"+ 'd' delete equation    +"<<std::endl;
    std::cout<<"+ 'q' quit program       +"<<std::endl;
    std::cout<<"+------------------------+"<<std::endl;
    std::cout<<""<<std::endl;
}

bool Inter_face::quit(){
    return this->quit_program;
}

void Inter_face::get_command(){
    std::cout<<"Enter input: ";
    std::cin>>this->input_string;

    char c = input_string[0];
    
    switch (c) {
        case 'h' : this->help_message();
                   break;
        case 'i' : this->get_equation();
                   break;
        case 'p' : this->print_root_arr(); 
                   break;
        case 'c' : this->evaluate_tree_node();
                   break;
        case 'd' : this->delete_tree_node();
                   break;
        case 'q' : this->quit_program = true;
                   break;
        default  : std::cout<<"Invalid command, please try agiain"<<std::endl;
                   std::cout<<"Enter 'h' for help\n"<<std::endl;
                   break;
    }
    return;
}

void Inter_face::get_equation(){
    std::string str_tmp;

    std::cout<<"Enter where to store equation (0-9): "<<std::flush;
    int reg = get_reg_from_input();
    if(reg == 11)
        return;

    std::cout<<"Please enter expresion: "<<std::flush;
    std::cin>>str_tmp;
    if(!is_expr(str_tmp)){
        std::cout<<"Invalid input"<<std::endl;
        return;
    }
    str_tmp.erase(std::remove_if(str_tmp.begin(), str_tmp.end(), isspace), str_tmp.end());
    this->create_tree(reg, str_tmp);
    return;
}

void Inter_face::print_root_arr(){
    std::cout<<"+----- Current stored equations -----"<<std::endl;
    for(int i=0; i<=9; i++){
        std::cout<<"+ "<< i <<": ";
        if(this->root_arr[i] != nullptr)
            this->root_arr[i]->print_tree();
        std::cout<<std::endl;
    }
    std::cout<<"+------------------------------------"<<std::endl;
}

void Inter_face::create_tree(int i, std::string expr){
    this->root_arr[i] = new Equal(expr);
    return;
}

void Inter_face::evaluate_tree_node(){

    std::cout<<"Enter which equation to evaluate (0-9): "<<std::flush;
    int reg = get_reg_from_input();
    if(reg == 11)
        return;

    std::cout<<"Calculating..."<<std::endl;
    double result = root_arr[reg]->evaluate();
    std::cout<<"Result = "<< result<<std::endl;
    return;
}

void Inter_face::delete_tree_node(){

    std::cout<<"Enter which equation to delete (0-9): "<<std::flush;
    int reg = get_reg_from_input();
    if(reg == 11)
        return;

    delete this->root_arr[reg];
    return;
}

void Inter_face::print_tree_node(){

    std::cout<<"Enter which equation to print (0-9): "<<std::flush;
    int reg = get_reg_from_input();
    if(reg == 11)
        return;

    std::cout<<"Current equation is: ";
    this->root_arr[reg]->print_tree();
    std::cout<<std::endl;
    return;
}
