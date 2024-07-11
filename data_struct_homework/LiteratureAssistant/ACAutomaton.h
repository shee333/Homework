#ifndef ACAUTOMATON_H
#define ACAUTOMATON_H

#include <string>
#include <unordered_map>
#include <vector>
#include <queue>

class ACAutomaton {
public:
    ACAutomaton();
    void insert(const std::string& pattern);
    std::unordered_map<std::string, std::vector<int>> search(const std::string& text);
    void finalize();
private:
    struct Node {
        std::unordered_map<char, Node*> children;
        Node* fail;
        std::vector<int> output;
        Node() : fail(nullptr) {}
    };

    Node* root;
    std::vector<std::string> patterns;

    void buildFailureLinks();
};

#endif
