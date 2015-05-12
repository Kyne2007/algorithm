#ifndef MOUSE_TRIE_H_
#define MOUSE_TRIE_H_

#include <vector>
#include <string>

namespace Mouse
{
    struct Trie_node
    {
        Trie_node() : children(26, nullptr), prefix_count(0), word_count(0) {}

        std::vector<Trie_node *> children;
        int prefix_count;
        int word_count;
    };

    class Trie
    {
        public:
            Trie() : root(new Trie_node) {}

            void insert_word(std::string s);
            void delete_word(std::string s);

            bool search_word(std::string s);
            int search_word_count(std::string s);

            bool search_prefix(std::string prefix);
            int search_prefix_count(std::string prefix);

        private:
            Trie_node *root;
    };
}

#endif
