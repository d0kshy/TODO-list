//
//  todo.cpp
//  TODO-list
//
//  Created by Daria Kurnosova on 02/07/2025.
//

#include "todo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>



// A vector saving all tasks through structure.
std::vector<Task> list;

//
// Function adds new tasks to created earlier .txt file.
void addTaskFunc(){
    char option = 'y';
    
    // Ignoring '\n' symbol for proper code functionality.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (option == 'y' || option == 'Y') {
        std::cout << "\n\tNew task: ";
        std::string task;
        std::getline(std::cin, task);
                
        // Creating new object using structure.
        Task newTask = {task};
        list.push_back(newTask);

        std::cout << "\nAdd another one? (y/n)\n\t- Your choice: ";
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    // Function is creating a .txt file.
    std::ofstream outf("TODO-list.txt", std::ios::app);
    
    // Writes users input to the file.
    for (const auto& task : list) {
        outf << "[ ] " << task.description << '\n';
    }
    
    list.clear();
}

//
// Function shows all tasks from created earlier .txt file.
void showTasksFunc(){
    char option = 'y';
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "*Show the list of tasks*\n";
    while (option == 'n' || option == 'N') {
        
        // ifstream for reading the .txt file
        std::ifstream inf("TODO-list.txt");
        
        while (inf)
            {
                std::string strInput;
                inf >> strInput;
                std::cout << strInput << std::endl;
            }
        
        std::cout << "\nGo back to the menu? (y/n)\n\t- Your choice: ";
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
}

//
// Function finishes tasks that were added earlier to the .txt file.
void finishTaskFunc(){
    char option = 'y';
    std::cout << "*Finish the task*\n";
}

//
// Function deletes tasks from created earlier .txt file.
void deleteTaskFunc() {
    char option = 'y';
    std::cout << "*Select a task*\n";
}

