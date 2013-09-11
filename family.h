#ifndef __FAMILY_H__
#define __FAMILY_H__
#include <string>

struct FTree;
const int maxChildren = 10;
struct FTree {
    FTree();
    ~FTree();
  std::string name;
  int numChildren;
  FTree *children[maxChildren];
    static FTree* Root;
    FTree* Left_Child;
    FTree* Right_bro;
    //FTree* Root;
};
FTree* Add_Topmost(const std::string& name);
FTree* Add_Child_Helper(const std::string& name1, const std::string& name2);
void Add_Child(const std::string& name1, const std::string& name2);
FTree* Find_Child(const std::string& name);
FTree* Find_Father(const std::string& name);
void Find_Route(const std::string& name);
int Find_Route_Helper(const std::string& name,const std::string& original);
void Erase(const std::string& name);
void Print_Tree();
FTree* ReturnRoot();
#endif
