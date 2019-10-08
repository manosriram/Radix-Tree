#ifndef SRCH_WRD
#define SRCH_WRD
#include "baseInclude.hpp"
#include "isLeafNode.hpp"

string suffix;
bool Find(RadixNode *root, string word) {
    static uint32_t cnt, pos;
    if (root->EOS && (suffix == word))
        return true;

    if (isLeafNode(root))
        return false;

    for (uint32_t t = 0; t < 26; t++) {
        if (root->children[t]) {
            pos = suffix.length();
            suffix += root->children[t]->word;
            if (Find(root->children[t], word))
                return true;
            suffix = suffix.substr(0, suffix.length() - root->children[t]->word.length());
        }
    }
    return (root->EOS && (suffix == word));
}

#endif