#include "Trie.h"
#include <iostream>
using namespace std;
using namespace Mouse;

int main(int argc, char *argv[])
{
    Trie trie;
    trie.insert_word("hello");
    trie.insert_word("hello");
    trie.insert_word("he");
    trie.insert_word("hell");
    trie.insert_word("helloworld");

    cout << trie.search_word("hello") << endl;
    cout << trie.search_word_count("hello") << endl;
    cout << trie.search_word("hell") << endl;
    cout << trie.search_word("helloaa") << endl;

    return 0;
}
