#ifndef CALCULATOR_H // include guard
#define CALCULATOR_H

#include "tree.h"
#include <string>

class Inter_face{
    private:
        std::string input_string;
        Tree_node* root;
    public:
        Inter_face();
        void welcome_message();
        void get_input();
        void print_input();
        void create_tree();
        void evaluate_tree();
        void delete_tree();
};

class Tree_node;



#endif
