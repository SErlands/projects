#include "tree.h"
#include "string_handling.h"
#include <ostream>
#include <string>
#include <iostream>
#include <sstream>

Tree_node::Tree_node(){

    this->left_node = NULL;
    this->right_node = NULL;
}

Tree_node::Tree_node(std::string left_expr, std::string right_expr){
    
    int left_oper_place = find_first_oper(left_expr); 
    int right_oper_place = find_first_oper(right_expr); 

    if (left_oper_place==0) {
        this->left_node = new Leaf(left_expr);
    }else {
        switch (left_expr[left_oper_place]) {
            case '+':
                this->left_node = new Addition(
                        left_expr.substr(0,left_oper_place),
                        left_expr.substr(left_oper_place + 1, left_expr.length()));
                break;
            default:
                std::cout<<"ERROR can't handle operator: " <<
                    right_expr[right_oper_place] << std::endl;
                break;
        }
    }

    if (right_oper_place==0) {
        this->left_node = new Leaf(left_expr);
    }else {
        switch (right_expr[right_oper_place]) {
            case '+':
                this->right_node = new Addition(
                        right_expr.substr(0,right_oper_place),
                        right_expr.substr(right_oper_place + 1, right_expr.length()));
                break;
            default:
                std::cout<<"ERROR can't handle operator: " <<
                    right_expr[right_oper_place] << std::endl;
                break;
        }
                
    }
    return;
}

void Tree_node::print_tree(){

    if (left_node != NULL) {
        left_node->print_tree();
    }
    std::cout<<this->print_str;
    if (right_node != NULL) {
        right_node->print_tree();
    }
    return;
}

Leaf::Leaf(std::string expr):Tree_node(){
    std::stringstream(expr) >> value;
}

Addition::Addition(std::string left_expr, std::string right_expr):
    Tree_node(left_expr, right_expr)
{
    this->print_str = "+";
}
