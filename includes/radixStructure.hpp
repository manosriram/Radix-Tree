#ifndef Radix_
#define Radix_
#include "baseInclude.hpp"

namespace RAX {
class RadixNode {
   public:
    string word;
    bool EOS;
    RadixNode *children[26];

    RadixNode(string word, bool EOS) {
        this->word = word;
        this->EOS = EOS;
        for (uint32_t t = 0; t < 26; t++)
            this->children[t] = nullptr;
    }

    RadixNode() {
        for (uint32_t t = 0; t < 26; t++)
            this->children[t] = nullptr;

        this->EOS = false;
    }

    ~RadixNode() {
        for (uint32_t t = 0; t < 26; t++) {
            delete[] this->children[t];
            this->children[t] = nullptr;
        }
    }
};
}
#endif