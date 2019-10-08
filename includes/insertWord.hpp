#ifndef INS_WRD
#define INS_WRD
#include "baseInclude.hpp"

RadixNode *Insert(string key, RadixNode *&root) {
    if (key.length() == 0)
        return root;

    uint32_t pos;
    RadixNode *crawl = root;
    uint32_t ind = key[0] - 'a';
    if (crawl->children[ind]) {
        crawl = crawl->children[ind];
        pos = getCutPosition(crawl, key);
        key = key.substr(pos);

        if (pos < crawl->word.length()) {
            crawl = splitNodes(crawl, key, pos);
        } else {
            Insert(key, crawl);
        }
        if (key.length() == 0)
            crawl->EOS = true;
    } else {
        crawl->children[ind] = new RadixNode(key, true);
    }
    return crawl;
}

#endif