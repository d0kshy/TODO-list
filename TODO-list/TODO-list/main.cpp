//
//  main.cpp
//  TODO-list
//
//  Created by Daria Kurnosova on 02/07/2025.
//

#include <iostream>
#include "todo.h"

int main(int argc, const char * argv[]) {
    int option{};
    char quit = ' ';
    std::cout << "WELCOME TO THE CONSOLE TODO-LIST.\n";
    
    while (option != 5) {
        
        std::cout << "Choose your option:\n\t1. Add task.\n\t2. Show all tasks.\n\t3. Finish task.\n\t4. Delete task.\n\t5. Save&Quit.\n\t- Your choice: ";
        std::cin >> option;
        
        switch (option) {
            case 1: addTaskFunc();
                break;
            case 2: showTasksFunc();
                break;
            case 3: finishTaskFunc();
                break;
            case 4: deleteTaskFunc();
                break;
        }
        
        std::cout << "Do you want to continue? (y/n)\n\t- Your choice: ";
        std::cin >> quit;
        
        if (quit == 'n' || quit == 'N'){
            break;
        }
    }
    return 0;
}
