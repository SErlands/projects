#ifndef TREE_H // include guard
#define TREE_H

#include <string>


// TREE_NODE ------------------------------------------------------------------
class Tree_node{
    protected:
        Tree_node* left_node;
        Tree_node* right_node;
        std::string print_str;
    public:

        Tree_node();
        Tree_node(std::string input_string);
        Tree_node(std::string left_expr, std::string right_node); 
        virtual ~Tree_node();

        void print_tree();
        virtual double evaluate();

};

// EQUAL ----------------------------------------------------------------------  
class Equal: public Tree_node{
    private:
    public:
        Equal(std::string expr);
        ~Equal();

        double evaluate();
};

// LEAF -----------------------------------------------------------------------
class Leaf: public Tree_node {
    private:
        double value;
    public:
        Leaf(std::string expr);
        ~Leaf();

        double evaluate();
};

// OPERATOR -------------------------------------------------------------------
class Operator: public Tree_node {
    private:
    public:
        Operator(std::string left_expr, std::string right_expr);
        ~Operator();

        virtual double evaluate();
};

// ADDITION -------------------------------------------------------------------
class Addition: public Operator {
    private:
    public: 
        Addition(std::string left_expr,std::string right_expr);

        double evaluate();
};

// SUBTRACTION ----------------------------------------------------------------
class Subtraction: public Operator {
    private:
    public: 
        Subtraction(std::string left_expr,std::string right_expr);

        double evaluate();
};
#endif
