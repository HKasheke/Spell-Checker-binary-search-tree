#include "binary_search_tree.h"
#include <fstream>
#include <iostream>
#include "spell_checker.h"

using std::string;

void SpellChecker::check_words (const string& file_to_correct, const string& dictionary_file_name, BinarySearchTree& tree, const string& out_tree_file){
    std::vector<string> file_data;
    std::vector<string> only_words;

    tree.read_file_into_tree(dictionary_file_name);

    // Reads whole file into vector
    read_file(file_to_correct, file_data);

    // Goes through all the data from the file and parses out whatever isn't a word
    for (const string& word : file_data) {
        string possible_word = check_if_word(word);
        if (!possible_word.empty()) {
            only_words.push_back(check_if_word(word));
        }
    }
    only_words.shrink_to_fit();

    // Go through vector containing only the words from the file, to see if they exist in the dictionary
    for (const string& word : only_words) {
        spell_check_word(word, tree);
    }

    tree.tree_to_file(out_tree_file, tree);
}

void SpellChecker::read_file(const string& file_name, std::vector<string>& file_data) {

    std::ifstream file_to_correct(file_name);

    if (file_to_correct.is_open()) {
        string word;
        while (file_to_correct >> word) {
            file_data.push_back(word);
        }
    }

    file_to_correct.close();
    file_data.shrink_to_fit();
}

string SpellChecker::check_if_word(const string& word_to_check) {
    // Step through every character and only build a word it's a letter
    string full_word;

    for (const char character : word_to_check) {
        if (std::isalpha(character)) {
           full_word += character;
        }
    }

    return full_word;
}

void SpellChecker::spell_check_word(const string& word, const BinarySearchTree& tree) {
    // checks if word exists in tree
    if (!tree.search(word)) {
        std::cout << "Misspelled word: " << word << std::endl;
    }
}

