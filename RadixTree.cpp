#include "incALL.hpp"
using namespace RAX;

int main() {

    RadixNode *root = new RadixNode();

    Insert("test", root);
    Insert("team", root);
    Insert("toast", root);
    Insert("toat", root);
    Insert("ttt", root);

    Traverse(root);
}