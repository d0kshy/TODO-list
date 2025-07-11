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
#include <algorithm>



// A vector saving all tasks through structure.
std::vector<Task> list;

//
// Function adds new tasks to created earlier .txt file.
void addTaskFunc(){
    char option = 'y';
    
    // Ignoring '\n' symbol for proper code functionality.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    int i = 1;
    std::ifstream inFile("TODO-list.txt");
    
    std::string line;
    while (std::getline(inFile, line)) {
        if (line.find(". [") != std::string::npos) {
            i++;
        }
    }
    inFile.close();
    
    while (option == 'y' || option == 'Y') {

        std::cout << "\n\tNew task: ";
        std::string task;
        std::getline(std::cin, task);
                
        // Creating new object using structure.
        Task newTask = {i, task};
        list.push_back(newTask);
        
        i++;
        
        std::cout << "\nAdd another one? (y/n)\n\t- Your choice: ";
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
 
    }
    
    // Function is creating a .txt file.
    std::ofstream outf("TODO-list.txt", std::ios::app);
    // outf << "   TODO-list:\n";
    
    // Writes users input to the file.
    for (const auto& task : list) {
        outf << task.n << ". [ ] " << task.description << '\n';
    }
    list.clear();
}

//
// Function shows all tasks from created earlier .txt file.
void showTasksFunc(){
    char option = 'y';
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       
    // ifstream for reading the .txt file
    std::ifstream inf("TODO-list.txt");
        
    while (inf) {
        std::string strInput;
        getline(inf, strInput);
        std::cout << strInput << std::endl;
    }

}

//
// Function finishes tasks that were added earlier to the .txt file.
void finishTaskFunc(){
    char option = 'y';
    
    while (option == 'y' || option == 'Y') {
        
            int taskNumber;
            std::cout << "\nEnter the task number to mark as finished: ";
            std::cin >> taskNumber;

            std::ifstream inf("TODO-list.txt");


            std::vector<std::string> lines;
            std::string line;

            while (getline(inf, line)) {
                lines.push_back(line);
            }
            inf.close();

            // Modify the correct task line
            for (auto& l : lines) {
                if (l.find(std::to_string(taskNumber) + ". [ ]") != std::string::npos) {
                    size_t pos = l.find("[ ]");
                    if (pos != std::string::npos)
                        l.replace(pos, 3, "[x]");
                    break;
                }
            }

            // Rewrite file
            std::ofstream outf("TODO-list.txt");
            for (const auto& l : lines)
                outf << l << '\n';

            std::cout << "\tTask " << taskNumber << " marked as complete in file.\n";
        

        std::cout << "\nContinue? (y/n)\n\t- Your choice: ";
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

//
// Function deletes tasks from created earlier .txt file.
void deleteTaskFunc() {
    char option = 'y';
    std::cout << "*Select a task*\n";
}
