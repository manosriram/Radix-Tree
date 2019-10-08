#ifndef CUT_POSITION
#define CUT_POSITION
#include "radixStructure.hpp"

uint32_t getCutPosition(RadixNode *crawl, string key) {
    uint32_t index = 0;
    while ((index < crawl->word.length()) && (index < key.length()) && (crawl->word[index] == key[index])) {
        ++index;
    }
    return index;
}

#endif