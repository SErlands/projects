#ifndef CALCULATOR_H // include guard
#define CALCULATOR_H

#include "tree.h"
#include <string>

class Inter_face{
    private:
        std::string input_string;
        Tree_node* root;
        bool quit_program;
    public:
        Inter_face();
        ~Inter_face();
        void welcome_message();
        void end_message();
        void help_message();
        bool quit();
        void get_command();
        void handle_command();
        void get_equation();

        void create_tree();
        void evaluate_tree();
        void delete_tree();
        void print_tree();
};

class Tree_node;



#endif
