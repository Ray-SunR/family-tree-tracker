//
//  main.cpp
//  A3Q3
//
//  Created by Sun Renchen on 2013-06-17.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#include <iostream>
#include "family.h"
#include <string>
using namespace std;
int main(int argc, const char * argv[])
{
    /*Add_Topmost("B");
    Add_Topmost("A");
    Add_Child("A", "C");
    Add_Child("A", "D");
    Add_Child("C", "E");
    Add_Child("E", "F");
    Add_Child("F", "G");
    Add_Child("E", "I");
    Add_Child("E", "H");
    Find_Route("G");
    Add_Child("V", "A");
    Find_Route("V");
    Print_Tree();
    Erase("C");
    Erase("B");
    Add_Child("A","B");
    Add_Child("B","C");
    Add_Child("B","E");
    Print_Tree();
    Erase("C");
    Add_Child("B", "C");
    Print_Tree();*/
    char command;
    string name;
    string name1;
    while (cin >> command)
    {
        switch (command) {
            case '!':
                cin >> name;
                Add_Topmost(name);
                break;
            case '+':
                cin >> name;
                cin >> name1;
                Add_Child(name, name1);
                break;
            case '?':
                cin >> name;
                Find_Route(name);
                break;
            case '*':
                cin >> name;
                Erase(name);
                break;
            case 'p':
                Print_Tree();
                break;
            default:
                break;
        }
    }
    FTree* temp = ReturnRoot();
    if (temp != NULL)
        delete temp;
    return 0;
}

