#ifndef IS_LAST
#define IS_LAST
#include "baseInclude.hpp"

bool isLeafNode(RadixNode *root) {
    for (uint32_t t = 0; t < 26; t++) {
        if (root->children[t])
            return false;
    }
    return true;
}

#endif