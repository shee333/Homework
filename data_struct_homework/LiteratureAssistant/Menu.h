#ifndef MENU_H
#define MENU_H

#include "ACAutomaton.h"
#include <iostream>
#include <fstream>
#include <string>

class Menu {
public:
    Menu();
    void displayMenu();
private:
    ACAutomaton automaton;
    void addPatterns();
    void searchText();
    void searchFile();
};

#endif
