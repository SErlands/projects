#ifndef STRING_HANDLING_H // include guard
#define STRING_HANDLING_H

#include <string>

bool is_int(char c);

bool is_oper(char c);

bool is_space(char c);

bool is_expr(std::string expr);

bool is_command(std::string input_str);

int find_first_oper(std::string expr);

int find_first_equal(std::string expr);

int find_first_prim(std::string expr);

int find_first_secd(std::string expr);

#endif
