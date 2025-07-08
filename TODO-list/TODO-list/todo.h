//
//  todo.h
//  TODO-list
//
//  Created by Daria Kurnosova on 02/07/2025.
//

#ifndef TODO_H
#define TODO_H
#include <iostream>
#include <string>
#include <vector>

struct Task{
    int n = 0;
    std::string description;
    bool complete = false;
};
extern std::vector<Task> list;

void addTaskFunc();
void showTasksFunc();
void finishTaskFunc();
void deleteTaskFunc();

#endif
