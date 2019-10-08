#ifndef TRV_TREE
#define TRV_TREE
#include "baseInclude.hpp"
#include "isLeafNode.hpp"

string suff;
static uint32_t cnt, pos;
void Traverse(RadixNode *root) {
    if (root->EOS) {
        cout << suff << " ";
        cout << endl;
    }

    if (isLeafNode(root))
        return;

    for (uint32_t t = 0; t < 26; t++) {
        if (root->children[t]) {
            pos = suff.length();
            suff += root->children[t]->word;
            Traverse(root->children[t]);
            suff = suff.substr(0, suff.length() - root->children[t]->word.length());
        }
    }
    return;
}

#endif