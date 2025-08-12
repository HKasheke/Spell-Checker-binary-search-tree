#ifndef SPELL_CHECKER_H
#define SPELL_CHECKER_H

#include "binary_search_tree.h"
#include <vector>

class SpellChecker {
public:
    void check_words (const std::string& file_to_correct, const std::string& dictionary_file_name, BinarySearchTree& tree, const std::string& out_tree_file);
    static void read_file(const std::string& file_name, std::vector<std::string>& file_data);
    static std::string check_if_word(const std::string& word_to_check);
    static void spell_check_word(const std::string& word, const BinarySearchTree& tree);
};

#endif //SPELL_CHECKER_H
