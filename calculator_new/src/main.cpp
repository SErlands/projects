#include <iostream>

#include "calculator.h"

int main(){
    // Setup
    Inter_face prog; 
    prog.welcome_message();
    prog.help_message();
    // main loop
    while(!prog.quit()){
        prog.get_command();
    }

    prog.end_message();
    
    return 0;

}
