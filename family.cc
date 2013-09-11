//
//  family.cc
//  A3Q3
//
//  Created by Sun Renchen on 2013-06-17.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#include "family.h"
#include <string>
#include <iostream>
using namespace std;
FTree* Root;
FTree::FTree()
{
    name = "";
    numChildren = 0;
    Left_Child = NULL;
    Right_bro = NULL;
    //Root = NULL;
    for (int i = 0; i < maxChildren; i++)
        children[i] = NULL;
}

FTree* Add_Topmost(const string& name)
{
    FTree* people = new FTree();
    people->name = name;
    if (Root == NULL)
        Root = people;
    else
    {
        people->Left_Child = Root;
        people->children[people->numChildren++] = Root;
        Root = people;
    }
    return people;
}

FTree* Find_Child_Helper(const string& name, FTree* temp)
{
    if (temp == NULL)
        return NULL;
    else if (temp->name == name)
        return temp;
    FTree* Child = NULL;
    if ((Child = Find_Child_Helper(name, temp->Left_Child)) != NULL)
        return Child;
    else
        return Find_Child_Helper(name, temp->Right_bro);
}

FTree* Find_Child(const string& name)
{
    FTree* temp = Root;
    return Find_Child_Helper(name, temp);
}

FTree* Add_Child_Helper(const string& name1, const string& name2)
{
    FTree* Father = Find_Child(name1);
    if (Father == NULL)
        return NULL;
    if (Father->numChildren == 10)
        return NULL;
    FTree* people = new FTree();
    people->name = name2;
    if (Father->numChildren == 0)
        Father->Left_Child = people;
    else
        Father->children[Father->numChildren - 1]->Right_bro = people;
    Father->children[Father->numChildren++] = people;
    return people;
}
void Add_Child(const string& name1,const string& name2)
{
    if (!Add_Child_Helper(name1, name2))
        cout << "Failed" << endl;
}

FTree* Find_Father_Helper(const string& name, FTree* temp)
{
    if (temp == NULL)
        return NULL;
    for (int i = 0; i < temp->numChildren; i++)
        if (temp->children[i]->name == name)
            return temp;
    FTree* Father = NULL;
    if ((Father = Find_Father_Helper(name, temp->Left_Child)) != NULL)
        return Father;
    else
        return Find_Father_Helper(name, temp->Right_bro);
}

FTree* Find_Father(const string& name)
{
    FTree* temp = Root;
    return Find_Father_Helper(name, temp);
}

int Find_Route_Helper(const string& name, const string& original)
{
    if (Find_Child(name) == NULL)
    {
        cout << "Not found" << endl;
        return 0;
    }
    FTree* temp;
    if ((temp = Find_Father(name)) == NULL)
        return 1;
    else
    {
        Find_Route_Helper(temp->name, original);
        cout << temp->name << ",";
        return 1;
    }
}

void Find_Route(const string& name)
{
    if (Find_Route_Helper(name, name))
        cout << name << endl;
    else
        return;
}

void Erase(const string& name)
{
    FTree* Child;
    FTree* Father;
    if ((Child = Find_Child(name)) == NULL)
        return;
    Father = Find_Father(Child->name);
    if (Father == NULL)
    {
        delete Child;
        Root = NULL;
        return;
    }
    if (Father->numChildren == 1)
    {
        delete Father->children[--Father->numChildren ];
        Father->children[Father->numChildren] = NULL;
        return;
    }
    for (int i = 0; i < Father->numChildren; i++)
    {
        if (Father->children[i]->name == name)
        {
            FTree* temp = Father->children[i];
            for (int j = i; j < Father->numChildren; j++)
                Father->children[j] = Father->children[j + 1];
            if (i != 0)
                Father->children[i - 1]->Right_bro = Father->children[i];
            else
                Father->Left_Child = Father->children[0];
            Father->numChildren--;
            delete temp;
            temp = NULL;
        }
    }
}

void Print_Tree_Helper(FTree* Head)
{
    if(Head == NULL)
        return;
    if (Head->numChildren !=0)
    {
        cout << Head->name << " is parent of ";
        for (int i = 0; i < Head->numChildren - 1; i++)
            cout << Head->children[i]->name <<",";
        cout << Head->children[Head->numChildren - 1]->name << endl;
    }
    Print_Tree_Helper(Head->Left_Child);
    Print_Tree_Helper(Head->Right_bro);
}

void Print_Tree()
{
    FTree* temp = Root;
    Print_Tree_Helper(temp);
}

FTree* ReturnRoot()
{
    return Root;
}

FTree::~FTree()
{
    //cout << "Destructor called..." << endl;
    name = "";
    Left_Child = NULL;
    Right_bro = NULL;
    for (int i = 0; i < numChildren; i++)
    {
        delete children[i];
        children[i] = NULL;
    }
    //delete this;
    numChildren = 0;
}