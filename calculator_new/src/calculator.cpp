#include "calculator.h"
#include "string_handling.h"
#include "tree.h"

#include <iostream>
#include <ostream>
#include <algorithm>
#include <string>

Inter_face::Inter_face(){
    this->root = nullptr;
    this->quit_program = false;
}

Inter_face::~Inter_face(){
    this->delete_tree();
    this->root = nullptr;
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
                   this->create_tree();
                   break;
        case 'p' : this->print_tree(); 
                   break;
        case 'c' : this->evaluate_tree();
                   break;
        case 'd' : this->delete_tree();
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
    std::cout<<"Please enter expresion: "<<std::flush;
    std::cin>>str_tmp;
    if(!is_expr(str_tmp)){
        std::cout<<"Invalid input"<<std::endl;
        return;
    }
    str_tmp.erase(std::remove_if(str_tmp.begin(), str_tmp.end(), isspace), str_tmp.end());
    input_string = str_tmp;
}

void Inter_face::create_tree(){
    root = new Equal(input_string);
    return;
}

void Inter_face::evaluate_tree(){
    std::cout<<"Calculating tree..."<<std::endl;
    double result = root->evaluate();
    std::cout<<"Result = "<< result<<std::endl;
    return;
}

void Inter_face::delete_tree(){
    delete this->root;
    return;
}

void Inter_face::print_tree(){
    std::cout<<"Current equation is: ";
    this->root->print_tree();
    std::cout<<std::endl;
    return;
}
