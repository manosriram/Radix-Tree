#ifndef SPLIT
#define SPLIT
#include "./baseInclude.hpp"
#include "./isLast.hpp"
#include "./moveChildNodes.hpp"

RadixNode *splitNodes(RadixNode *&root, string left, uint32_t pos) {
    bool hasChildren = false;
    if (!isLastNode(root))
        hasChildren = true;

    string right;
    uint32_t rI, lI;
    right = root->word.substr(pos);
    root->word = root->word.substr(0, pos);

    rI = right[0] - 'a';
    lI = left[0] - 'a';
    RadixNode *leftChild, *rightChild;

    if (hasChildren && !root->EOS) {
        leftChild = new RadixNode(left, true);
        rightChild = new RadixNode(right, false);
    } else {
        leftChild = new RadixNode(left, true);
        rightChild = new RadixNode(right, true);
    }

    moveChildNodes(root, rightChild);

    root->children[lI] = leftChild;
    root->children[rI] = rightChild;
    return root;
}

#endif