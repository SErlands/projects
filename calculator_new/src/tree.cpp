#include "tree.h"
#include "string_handling.h"
#include <ostream>
#include <string>
#include <iostream>
#include <sstream>


Tree_node* choose_node_type(std::string expr){

    int oper_place = find_first_oper(expr); 

    if (oper_place==0) {
        return new Leaf(expr);
    }else {
        switch (expr[oper_place]) {
            case '+':
                return new Addition(
                        expr.substr(0,oper_place),
                        expr.substr(oper_place + 1, expr.length()));
                break;
            case '-':
                return new Subtraction(
                        expr.substr(0,oper_place),
                        expr.substr(oper_place + 1, expr.length()));
                break;
            default:
                std::cout<<"ERROR can't handle operator: <" <<
                    expr[oper_place] << "> yet" << std::endl;
                return nullptr;
                break;
        }
    }
    return nullptr;
}
// TREE_NODE ------------------------------------------------------------------
Tree_node::Tree_node(){

    this->left_node = nullptr;
    this->right_node = nullptr;
    return;
}

Tree_node::Tree_node(std::string left_expr, std::string right_expr){
    
    this->left_node = choose_node_type(left_expr);
    this->right_node = choose_node_type(right_expr);
    return;
}

Tree_node::~Tree_node(){
    return;
}

void Tree_node::print_tree(){
    if (left_node != nullptr) {
        this->left_node->print_tree();
    }
    std::cout<<this->print_str;
    if (right_node != nullptr) {
        this->right_node->print_tree();
    }
    return;
}

double Tree_node::evaluate(){
    std::cout<<"ERROR: evaluate from baseclass should never be called"
        <<std::endl;
    return 0;
}

// EQUAL ----------------------------------------------------------------------
Equal::Equal(std::string expr):Tree_node(){
    int equal_place = find_first_equal(expr);

    if(equal_place == 0){
        std::cout << "ERROR: No equal sign in equation" << std::endl;
        this->print_str = "";
        right_node = choose_node_type(expr);
    }else {
        this->print_str = "=";
        left_node = choose_node_type(expr.substr(0,equal_place));
        right_node = choose_node_type(expr.substr(equal_place + 1, expr.length()));
    }
    return;
}

Equal::~Equal(){
    if(left_node != nullptr){
        delete left_node;
        left_node = nullptr;
    }
    delete right_node;
    right_node = nullptr;
    std::cout<<"Equal deleted"<<std::endl;
    return;
}

double Equal::evaluate(){

    std::cout<<" calculating : = "<<std::endl;

    double right_value = this->right_node->evaluate();
    double left_value;
    if(left_node != nullptr){
        left_value = this->left_node->evaluate();
        std::cout<<left_value<<" = "<<right_value<<std::endl;
    }else{
        left_value = 0;
        std::cout<<right_value<<std::endl;
    }

    return right_value;
}
    
// LEAF ----------------------------------------------------------------------- 
Leaf::Leaf(std::string expr):Tree_node(){
    this->print_str = expr;
    std::cout<<"creating node : " << this->print_str << std::endl;
    std::stringstream(expr) >> value;
    return;
}

Leaf::~Leaf(){
    std::cout<<"Leaf destructor called"<<std::endl;
    left_node = nullptr;
    right_node = nullptr;
    return;
}

double Leaf::evaluate(){
    std::cout<<" calculating : "<<value<<std::endl;
    return value;
}

// OPERATOR -------------------------------------------------------------------                                  
Operator::Operator(std::string left_expr, std::string right_expr):
    Tree_node(left_expr, right_expr)
{
    return;
}

Operator::~Operator(){
    delete left_node;
    left_node = nullptr; 
    delete right_node;
    right_node = nullptr;
    std::cout<<"Operator destructor called"<<std::endl;
    return;
}

double Operator::evaluate(){
    std::cout<<"ERROR: evaluate from operator baseclass should never be called"
        <<std::endl;
    return 0;
}
// ADDITION -------------------------------------------------------------------
Addition::Addition(std::string left_expr, std::string right_expr):
    Operator(left_expr, right_expr)
{
    std::cout<<"createing node: +"<<std::endl;
    this->print_str = "+";
    return;
}

double Addition::evaluate(){

    std::cout<<" calculating : +"<<std::endl;

    double left_value = this->left_node->evaluate();
    double right_value = this->right_node->evaluate();
    return left_value + right_value;
}

// SUBTRACTION ----------------------------------------------------------------
Subtraction::Subtraction(std::string left_expr, std::string right_expr):
    Operator(left_expr, right_expr)
{
    std::cout<<"createing node: +"<<std::endl;
    this->print_str = "-";
    return;
}

double Subtraction::evaluate(){

    std::cout<<" calculating : -"<<std::endl;

    double left_value = this->left_node->evaluate();
    double right_value = this->right_node->evaluate();
    return left_value - right_value;
}

