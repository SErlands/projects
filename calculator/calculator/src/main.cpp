#include <iostream>

#include "calculator.h"




int main(){
    // Setup
    Inter_face prog; 
    // main loop
    prog.welcome_message();
    prog.get_input();
    prog.create_tree();
    prog.print_input();
    prog.evaluate_tree();
    
    return 0;

}
