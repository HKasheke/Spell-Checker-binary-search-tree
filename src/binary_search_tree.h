#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iomanip>
#include <iostream>
#include <vector>
#include <memory>

class BinarySearchTree {
    struct Node;

    using NodePtr = std::unique_ptr<Node>;

    struct Node {
        int _node_num {-1};
        std::string _data;
        NodePtr _left {nullptr};
        NodePtr _right {nullptr};
    };

    NodePtr _root {nullptr};

public:
    void insert(int num, const std::string& data);
    static void insert(int num, NodePtr& node, const std::string& data);
    void remove(int num);
    void print_tree(std::ostream& output, const NodePtr& node, const int indent);
    void read_file_into_tree(const std::string& file_name);
    void build_balanced_tree(const std::vector<std::string>& words);
    void build_balanced_tree_helper(const std::vector<std::string>& words, int start, int end);
    int search_tree(std::vector<std::string> words_to_check, BinarySearchTree& tree);
    [[nodiscard]] bool search(const std::string& word) const;
    static bool search_helper(const NodePtr& node, const std::string& word);
    void tree_to_file(const std::string& output_file_name, BinarySearchTree& tree);
    friend std::ostream& operator<<(std::ostream& os, BinarySearchTree& tree);
};

#endif //BINARY_SEARCH_TREE_H
