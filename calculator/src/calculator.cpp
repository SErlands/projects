#include "calculator.h"

#include <iostream>
#include <ostream>
#include <string>

Inter_face::Inter_face(){}

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
    input_string = str_tmp;
}

void Inter_face::print_input(){
    std::cout << "Your input was: " << input_string 
        << std::endl;
    return;
}

// Return true if char is space
bool is_space(char c)
{
    c = tolower(c);
    if (c == ' ')
        return true;
    return false;
}

// Return true if char is int
bool is_int(char c)
{
    c = tolower(c);
    if (c == '1'
        || c == '2'
        || c == '3'
        || c == '4'
        || c == '5'
        || c == '6'
        || c == '7'
        || c == '8'
        || c == '9')
        return true;
    return false;
}

// Return true if char is a supported operator
bool is_oper(char c)
{
    c = tolower(c);
    if (c == '+'
        || c == '-'
        || c == '*'
        || c == '/')
        return true;
    return false;
}

// Returns true if input is a correct expresion
bool Inter_face::is_expr(std::string expr){
    bool prev_space = false;
    bool prev_int = false;
    bool prev_oper = false;

    for(int i = 0; i < expr.length(); i++){
        if(is_int(expr[i])){
            if (prev_space && prev_int && !prev_oper) {
                std::cout << 
                    "ERROR: Needs operators between numbers" 
                    << std::endl;
                return false;
            }
            prev_int = true;
            prev_space = false;
            prev_oper = false;

        }else if (is_space(expr[i])) {
            expr.erase(1,1);
            prev_space = true;
        }else if(is_oper(expr[i])){
            if (prev_int && !prev_oper) {
                prev_oper = true;
            }else {
                std::cout<<
                    "ERROR: Can't have two operator without a number inbetween" 
                    << std::endl;
                return false;
            }

        }else {
            return false;
        }
    }
    return true;
}


