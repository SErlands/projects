#ifndef TREE_H // include guard
#define TREE_H

#include "calculator.h"
#include <string>



class Tree_node{
    private:
        Tree_node* left_node;
        Tree_node* right_node;

    public:
        void set_left(std::string expresion);
        void set_right(std::string expresion);

        Tree_node(std::string left_expr, 
                std::string middle_expr, std::string right_expr); 

};


class additon: public Tree_node {
    public: 
        void evaluate();
};

#endif
