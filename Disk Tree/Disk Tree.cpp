#include <stdio.h>

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class treenode {
   private:
    char name[9];
    vector<treenode*> ptr;

   public:
    treenode();
}

class tree {
   private:
    treenode* root;
    map<int, treenode*> tree_map;

   public:
    tree();
    ~tree();
}

int main() {
    int n;
    cin >> n;

    char* input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        char name[9];
        int index = 0;
        while (input[index] != '\0') {
            while (input[index] != '/') {
                name[index] = input[index];
            }
        }
    }
    return 0;
}