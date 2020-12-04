#ifndef TREE_H // include guard
#define TREE_H

#include <string>



class Tree_node{
    private:
        Tree_node* left_node;
        Tree_node* right_node;
        std::string print_str;
    public:

        Tree_node();
        Tree_node(std::string left_expr, std::string right_node); 
        void print_tree();

};


class Leaf: public Tree_node {
    private:
        double value;
        public:
        Leaf(std::string expr);
        void evaluate();

};

class Addition: public Tree_node {
    private:
        char value;
    public: 
        Addition(std::string left_expr,std::string right_expr);
        void evaluate();
        
};

#endif
