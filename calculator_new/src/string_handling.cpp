#include "string_handling.h"

#include <string>
#include <iostream>
#include <algorithm>

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
        || c == '9'
        || c == '0')
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

// Return true if c is a supported primary operator
bool is_prim_oper(char c)
{
    c = tolower(c);
    if (c == '*'
        || c == '/')
        return true;
    return false;
}

// Return true if c is a supported secondary operator
bool is_secd_oper(char c)
{
    c = tolower(c);
    if (c == '+'
        || c == '-')
        return true;
    return false;
}

bool is_command(std::string input_str)
{
    input_str.erase(std::remove_if(input_str.begin(), input_str.end(), isspace), input_str.end());
    if(input_str.length() == 1){
        char c = input_str[0];
        if (c == 'h'
                || c == 'i'
                || c == 'p'
                || c == 'd'
                || c == 'q')
            return true;
    }
    return false;
}


// Returns true if input is a correct expresion
bool is_expr(std::string expr){
    bool prev_space = false;
    bool prev_int = false;
    bool prev_oper = false;

    for(unsigned int i = 0; i < expr.length(); i++){
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
        }else if(is_oper(expr[i]) || expr[i] == '='){
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
    if (prev_int && !prev_oper) {
        return true;
    }else if (!prev_oper) {
        std::cout<<"Expresion can't end on a operator"<<std::endl;
        return false;
    }
    std::cout<<"Unknown Error: input problem"<<std::endl;
    return false; 
}

// Finds the first operator and return its place
// If no operator is found, returns zero
int find_first_oper(std::string expr){
    for (unsigned int i = 0; i<expr.length(); i++) {
        if (is_oper(expr[i])) {
            return i;
        }
    }
    return 0;
}

// Finds the first equal sign and return its place
// If no operator is found, returns zero
int find_first_equal(std::string expr){
    for (unsigned int i = 0; i<expr.length(); i++) {
        if (expr[i] == '=') {
            return i;
        }
    }
    return 0;
}

// Finds the first primary operator and return its place
// If no operator is found, returns zero
int find_first_prim(std::string expr){
    for (unsigned int i = 0; i<expr.length(); i++) {
        if (is_prim_oper(expr[i])) {
            return i;
        }
    }
    return 0;
}

// Finds the first secondary operator and return its place
// If no operator is found, returns zero
int find_first_secd(std::string expr){
    for (unsigned int i = 0; i<expr.length(); i++) {
        if (is_secd_oper(expr[i])) {
            return i;
        }
    }
    return 0;
}

