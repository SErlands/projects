#ifndef CALCULATOR_H // include guard
#define CALCULATOR_H

#include <string>

class Inter_face{
    private:
        std::string input_string;
        bool is_expr(std::string expr);
    public:
        Inter_face();
        void welcome_message();
        void get_input();
        void print_input();
};

class Tree_node;



#endif
