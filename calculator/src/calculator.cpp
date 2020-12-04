#include "calculator.h"
#include "string_handling.h"
#include "tree.h"

#include <iostream>
#include <ostream>
#include <algorithm>
#include <string>

Inter_face::Inter_face(){
    this->root = NULL;
}

void Inter_face::welcome_message(){
    std::cout << "Hello World!" << std::endl;
    return;
}

void Inter_face::get_input(){
    std::string str_tmp;
    std::cout << "Please enter expresion: " << std::flush;
    std::getline(std::cin, str_tmp);
    if(!is_expr(str_tmp)){
        std::cout<<"Invalid input"<<std::endl;
        return;
    }
    str_tmp.erase(std::remove_if(str_tmp.begin(), str_tmp.end(), isspace), str_tmp.end());
    input_string = str_tmp;
}

void Inter_face::print_input(){
    std::cout << "Your input was: " << input_string 
        << std::endl;
    std::cout << "Current tree is: ";
    this->root->print_tree();
    std::cout<<std::endl;
    return;
}

void Inter_face::create_tree(){
    this->root = new Tree_node(input_string);
    return;
}
