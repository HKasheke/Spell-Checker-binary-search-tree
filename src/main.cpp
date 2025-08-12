#include "binary_search_tree.h"
#include "spell_checker.h"

int main(int argc, char *argv[]) {
    const std::string MISPELLED_FILE_NAME = "../tests/test.txt";
    const std::string DICTIONARY_FILE_NAME = "../tests/dictionary.txt";
    const std::string OUTPUT_TREE_FILE = "../tests/output.txt";

    SpellChecker spell_checker;
    BinarySearchTree bst;

    // function to take the files, parse out just the words, spellcheck them and output tree to file.
    spell_checker.check_words(MISPELLED_FILE_NAME, DICTIONARY_FILE_NAME, bst, OUTPUT_TREE_FILE);

    return 0;
}