#include "tree.h"
#include "string_handling.h"
#include <ostream>
#include <string>
#include <iostream>
#include <sstream>


void choose_node_type(Tree_node* node, std::string expr){

    int oper_place = find_first_oper(expr); 

    if (oper_place==0) {
        node = new Leaf(expr);
    }else {
        switch (expr[oper_place]) {
            case '+':
                node = new Addition(
                        expr.substr(0,oper_place),
                        expr.substr(oper_place + 1, expr.length()));
                break;
            default:
                std::cout<<"ERROR can't handle operator: <" <<
                    expr[oper_place] << "> yet" << std::endl;
                break;
        }
    }
    return;
}
// TREE_NODE ------------------------------------------------------------------
Tree_node::Tree_node(){

    this->left_node = NULL;
    this->right_node = NULL;
    return;
}

Tree_node::Tree_node(std::string left_expr, std::string right_expr){
    
    choose_node_type(this->left_node, left_expr);
    choose_node_type(this->right_node,  right_expr);
    return;
}

void Tree_node::print_tree(){
    std::cout << " Entering new node " << std::endl;
    if (left_node != NULL) {
        this->left_node->print_tree();
    }
    std::cout<<this->print_str;
    if (right_node != NULL) {
        this->right_node->print_tree();
    }
    return;
}
// EQUAL ----------------------------------------------------------------------
Equal::Equal(std::string expr):Tree_node(){
    int equal_place = find_first_equal(expr);

    if(equal_place == 0){
        std::cout << "ERROR: No equal sign in equation" << std::endl;
        this->print_str = "";
        choose_node_type(this->right_node, expr);
    }else {
        this->print_str = "=";
        choose_node_type(this->left_node, 
                expr.substr(0,equal_place));
        choose_node_type(this->right_node, 
                expr.substr(equal_place + 1, expr.length()));
    }
    return;
}
    
// LEAF ----------------------------------------------------------------------- 
Leaf::Leaf(std::string expr):Tree_node(){
    this->print_str = expr;
    std::cout<<"creating value node :" << this->print_str << std::endl;
    std::stringstream(expr) >> value;
    return;
}
// ADDITION -------------------------------------------------------------------
Addition::Addition(std::string left_expr, std::string right_expr):
    Tree_node(left_expr, right_expr)
{
    std::cout<<"createing + node"<<std::endl;
    this->print_str = "+";
    return;
}
