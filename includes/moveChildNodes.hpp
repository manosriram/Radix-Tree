#ifndef MV_CHLD_ND
#define MV_CHLD_ND
#include "baseInclude.hpp"

void moveChildNodes(RadixNode *&root, RadixNode *&target) {
    root->EOS = false;
    for (uint32_t t = 0; t < 26; t++) {
        if (root->children[t]) {
            target->children[t] = root->children[t];

            root->children[t] = nullptr;
        }
    }
    return;
}

#endif