#ifndef TREE_H // include guard
#define TREE_H

#include <string>



class Tree_node{
    protected:
        Tree_node* left_node;
        Tree_node* right_node;
        std::string print_str;
    public:

        Tree_node();
        Tree_node(std::string input_string);
        Tree_node(std::string left_expr, std::string right_node); 
        void print_tree();
        double evaluate();

};

class Equal: public Tree_node{
    private:
    public:
        Equal(std::string expr);
};

class Leaf: public Tree_node {
    private:
        double value;
    public:
        Leaf(std::string expr);
};

class Addition: public Tree_node {
    private:
    public: 
        Addition(std::string left_expr,std::string right_expr);
};

#endif
