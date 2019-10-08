#include "Radix.hpp"
using namespace RAX;

int main() {

    RadixNode *root = new RadixNode();

    Insert("romane", root);
    Insert("romanus", root);
    Insert("romulus", root);
    Insert("rubens", root);
    Insert("ruber", root);
    Insert("rubicon", root);
    Insert("rubicundus", root);
    
    Traverse(root);
    cout << endl;
    cout << Find(root, "ruber") << endl;
}