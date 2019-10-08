<h2 align="center"> Implementation of Radix-Tree</h2>

![Radix Tree](https://upload.wikimedia.org/wikipedia/commons/thumb/a/ae/Patricia_trie.svg/1280px-Patricia_trie.svg.png)

**Usage**

```cpp

Insert(word, node);  // Insert a word into node.

isLeafNode(node);  // Check if Node is Lead or Not.

Traverse(node);  // Traverse the Tree starting from node.

```

**Example**

```cpp
#include "Radix.hpp"
using namespace RAX;

int main() {

    RadixNode *root = new RadixNode();

    Insert("romane", root);
    Insert("romanus", root);
    Insert("romulus", root);
    Insert("rubens", root);
    Insert("ruber", root);
    Insert("rubicon", root);
    Insert("rubicundus", root);
    
    Traverse(root);
}
```

**Output**
```
romane
romanus
romulus
rubens
ruber
rubicon
rubicundus
```
