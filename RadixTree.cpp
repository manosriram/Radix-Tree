#include <iostream>
#include <memory>
#define trace(x) cerr << x << endl;
using namespace std;

class RadixNode {
   public:
    string word;
    bool EOS;
    RadixNode *children[26];

    RadixNode(string word, bool END) {
        this->word = word;
        this->EOS = END;
        for (int t = 0; t < 26; t++)
            this->children[t] = nullptr;
    }

    RadixNode() {
        for (int t = 0; t < 26; t++)
            this->children[t] = nullptr;

        this->EOS = false;
    }

    ~RadixNode() {
        for (int t = 0; t < 26; t++) {
            delete[] this->children[t];
            this->children[t] = nullptr;
        }
    }
};

int getCutPosition(RadixNode *crawl, string key) {
    int index = 0;
    while ((index < crawl->word.length()) && (index < key.length()) && (crawl->word[index] == key[index])) {
        ++index;
    }
    return index;
}

bool isLastNode(RadixNode *root) {
    for (int t = 0; t < 26; t++) {
        if (root->children[t])
            return false;
    }
    return true;
}

RadixNode *moveChildNodes(RadixNode *root) {

}

RadixNode *splitNodes(RadixNode *root, string left, int pos) {
    root->EOS = false;
    bool hasChildren = false;
    if (!isLastNode(root))
        hasChildren = true;

    string right;
    int rI, lI;
    // cout << root->word << endl;
    right = root->word.substr(pos, root->word.length());
    root->word = root->word.substr(0, pos);

    rI = right[0] - 'a';
    lI = left[0] - 'a';
    RadixNode *leftChild, *rightChild;

    if (hasChildren) {
        leftChild = new RadixNode(right, false);
        rightChild = new RadixNode(left, true);
    } else {
        leftChild = new RadixNode(left, true);
        rightChild = new RadixNode(right, true);
    }

    /*
    moveChildNodes(rightChild);
    removeRootChildren(root);
    */

    root->children[lI] = leftChild;
    root->children[rI] = rightChild;
    return root;
}

void Insert(string key, RadixNode *&root) {
    int pos;
    RadixNode *crawl = root;
    int ind = key[0] - 'a';

    if (crawl->children[ind]) {
        crawl = crawl->children[ind];
        pos = getCutPosition(crawl, key);
        key = key.substr(pos, key.length());
        if (pos < crawl->word.length()) {
            crawl = splitNodes(crawl, key, pos);
        } else {
            Insert(key, crawl);
        }
    } else {
        crawl->children[ind] = new RadixNode(key, true);
    }
    return;
}

string suff, pref;
static int cnt;
void Traverse(RadixNode *root) {
    if (root->EOS) {
        cout << suff << " ";
        suff = suff.substr(0, suff.length() - root->word.length());
    }

    if (isLastNode(root))
        return;

    for (int t = 0; t < 26; t++) {
        if (root->children[t]) {
            suff += root->children[t]->word;
            Traverse(root->children[t]);
        }
    }
}

int main() {
    // trace("Entered Main!");
    RadixNode *root = new RadixNode();
    Insert("tester", root);
    Insert("tested", root);
    Insert("tesla", root);
    // Insert("teslut", root);

    // Insert("teslum", root);

    // Traverse(root);
    int it = 't' - 'a';
    // int it2 = 't' - 'a';
    root = root->children[it];
    cout << root->word << endl;
    // cout << root->word;
    // return 1;
    // cout << root->word << " ";
    for (int t = 0; t < 26; t++) {
        if (root->children[t]) {
            cout << root->children[t]->word << " ";
        }
    }

    // cout << root->children[it]->word << endl;
    cout << endl;
}