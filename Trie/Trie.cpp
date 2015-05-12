#include "Trie.h"
#include <cctype>

namespace Mouse
{

    void Trie::insert_word(std::string s)
    {
        for (auto c : s)
            if (!isalpha(c))
                return ;

        Trie_node *curr_node = root;

        for (std::string::size_type i = 0; i < s.size(); i++) {
            int branch = tolower(s[i]) - 'a';
            if (curr_node->children[branch] == nullptr)
                curr_node->children[branch] = new Trie_node;

            curr_node = curr_node->children[branch];
            curr_node->prefix_count++;
        }
        curr_node->word_count++;
    }

    void Trie::delete_word(std::string s)
    {
        if (search_word(s) == false)
            return ;

        Trie_node *curr_node = root;

        for (std::string::size_type i = 0; i < s.size(); i++) {
            int branch = tolower(s[i]) - 'a';

            curr_node = curr_node->children[branch];
            curr_node->prefix_count--;
        }
        curr_node->word_count--;
    }

    bool Trie::search_word(std::string s)
    {
        Trie_node *curr_node = root;

        for (std::string::size_type i = 0; i < s.size(); i++) {
            if (!isalpha(s[i]))
                return false;

            int branch = tolower(s[i]) - 'a';
            if (curr_node->children[branch] == nullptr)
                return false;

            curr_node = curr_node->children[branch];
        }
    
        if (curr_node->word_count > 0)
            return true;
        else
            return false;
    }

    int Trie::search_word_count(std::string s) 
    {
        Trie_node *curr_node = root;

        for (std::string::size_type i = 0; i < s.size(); i++) {
            if (!isalpha(s[i]))
                return 0;

            int branch = tolower(s[i]) - 'a';
            if (curr_node->children[branch] == nullptr)
                return 0;

            curr_node = curr_node->children[branch];
        }
    
        return curr_node->word_count;
    }


    bool Trie::search_prefix(std::string prefix)
    {
        Trie_node *curr_node = root;

        for (std::string::size_type i = 0; i < prefix.size(); i++) {
            if (!isalpha(prefix[i]))
                return false;

            int branch = tolower(prefix[i]) - 'a';
            if (curr_node->children[branch] == nullptr)
                return false;

            curr_node = curr_node->children[branch];
        }
    
        return true;
    }

    int Trie::search_prefix_count(std::string prefix)
    {
        Trie_node *curr_node = root;

        for (std::string::size_type i = 0; i < prefix.size(); i++) {
            if (!isalpha(prefix[i]))
                return 0;

            int branch = tolower(prefix[i]) - 'a';
            if (curr_node->children[branch] == nullptr)
                return 0;

            curr_node = curr_node->children[branch];
        }
    
        return curr_node->prefix_count;
    }
}

