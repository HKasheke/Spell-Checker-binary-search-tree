#include <fstream>
#include "binary_search_tree.h"

void BinarySearchTree::insert(const int num, const std::string& data) {
    insert(num, _root, data);
}

void BinarySearchTree::insert(const int num, NodePtr& node, const std::string& data) {
    if (node == nullptr) {
        // insert node at bottom of tree
        node = std::make_unique<Node>(num, data);
    } else if (num < node->_node_num) {
        // insert to the left of the root node
        insert(num, node->_left, data);
    } else if (num > node->_node_num) {
        // insert to the right of the root node
        insert(num, node->_right, data);
    }
}

void BinarySearchTree::read_file_into_tree(const std::string& file_name) {
    std::ifstream file_stream(file_name);
    std::string word;
    std::vector<std::string> words;

    while (file_stream >> word) {
        words.push_back(word);
    }
    file_stream.close();
    words.shrink_to_fit();

    build_balanced_tree(words);
}

void BinarySearchTree::print_tree(std::ostream& output, const NodePtr& node, const int indent) {
    if (node != nullptr) {
        print_tree(output, node->_right, indent + 8);
        output << std::setw(indent) << node->_data << std::endl;
        print_tree(output, node->_left, indent + 8);
    }
}

void BinarySearchTree::build_balanced_tree(const std::vector<std::string>& words) {
    _root = nullptr;

    //pass word vector and values for start and end to recursive tree balancer
    build_balanced_tree_helper(words, 0, words.size() - 1);
}

void BinarySearchTree::build_balanced_tree_helper(const std::vector<std::string>& words, int start, int end) {
    if (start > end) {
        return;
    }

    // assign mid to middle of the substring we're working with
    int mid = start + (end - start) / 2;

    insert(mid + 1, words[mid]);

    // Recursively construct the left subtree
    build_balanced_tree_helper(words, start, mid - 1);

    // Recursively construct the right subtree
    build_balanced_tree_helper(words, mid + 1, end);
}

std::ostream& operator<<(std::ostream& os, BinarySearchTree& tree) {
    tree.print_tree(os, tree._root, 0);
    return os;
}

bool BinarySearchTree::search(const std::string& word) const {
    std::string lowered_word;

    // lowering word to beccause dictionary is all in lowercase
    for (const char c : word) {
        lowered_word += static_cast<char> (tolower(c));
    }

    return search_helper(_root, lowered_word);
}

bool BinarySearchTree::search_helper(const NodePtr& node, const std::string& word) {
    // Base case: reached the end of a branch without finding the word
    if (node == nullptr) {
        return false;
    }

    // Check if current node contains the word
    if (node->_data == word) {
        return true;
    }

    // Binary search logic - compare strings lexicographically (alphabetically)
    if (word < node->_data) {
        // Search left subtree
        return search_helper(node->_left, word);
    } else {
        // Search right subtree
        return search_helper(node->_right, word);
    }
}

void BinarySearchTree::tree_to_file(const std::string& output_file_name, BinarySearchTree& tree) {
    std::ofstream file_stream(output_file_name);

    //passing our file ostream to print, to print to a file
    tree.print_tree(file_stream, tree._root, 0);

}