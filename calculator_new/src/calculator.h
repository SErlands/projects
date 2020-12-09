#ifndef CALCULATOR_H // include guard
#define CALCULATOR_H

#include "tree.h"
#include <string>

class Inter_face{
    private:
        std::string input_string;
        Tree_node** root_arr;
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

        void print_root_arr();

        void create_tree(int i, std::string expr);
        void evaluate_tree_node();
        void delete_tree_node();
        void print_tree_node();
};

class Tree_node;



#endif
