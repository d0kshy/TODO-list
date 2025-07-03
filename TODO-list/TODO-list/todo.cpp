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

std::ofstream outf("TODO-list.txt");
std::vector<Task> list;

void addTaskFunc(){
    char option = 'y';
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (option == 'y' || option == 'Y') {
        std::cout << "\n\tNew task: ";
        std::string task;
        std::getline(std::cin, task);
        outf << "[ ] " << task << '\n';
        
        Task newTask = {task};
        list.push_back(newTask);

        std::cout << "\nAdd another one? (y/n)\n\t- Your choice: ";
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
    }
    
}

void showTasksFunc(){
    std::cout << "*Show the list of tasks*\n";
}

void finishTaskFunc(){
    std::cout << "*Finish the task*\n";
}

void deleteTaskFunc() {
    std::cout << "*Select a task*\n";
}

