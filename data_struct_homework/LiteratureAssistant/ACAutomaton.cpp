#include "ACAutomaton.h"

ACAutomaton::ACAutomaton() {
    root = new Node();
}

void ACAutomaton::insert(const std::string& pattern) {
    Node* node = root;
    for (char c : pattern) {
        if (node->children.find(c) == node->children.end()) {
            node->children[c] = new Node();
        }
        node = node->children[c];
    }
    node->output.push_back(patterns.size());
    patterns.push_back(pattern);
}

void ACAutomaton::finalize() {
    buildFailureLinks();
}

void ACAutomaton::buildFailureLinks() {
    std::queue<Node*> q;
    root->fail = root;
    for (auto& child : root->children) {
        child.second->fail = root;
        q.push(child.second);
    }

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        for (auto& child : current->children) {
            Node* fail = current->fail;
            while (fail != root && fail->children.find(child.first) == fail->children.end()) {
                fail = fail->fail;
            }
            if (fail->children.find(child.first) != fail->children.end()) {
                child.second->fail = fail->children[child.first];
            } else {
                child.second->fail = root;
            }

            for (int index : child.second->fail->output) {
                child.second->output.push_back(index);
            }

            q.push(child.second);
        }
    }
}

std::unordered_map<std::string, std::vector<int>> ACAutomaton::search(const std::string& text) {
    std::unordered_map<std::string, std::vector<int>> result;
    Node* node = root;

    for (int i = 0; i < text.size(); ++i) {
        while (node != root && node->children.find(text[i]) == node->children.end()) {
            node = node->fail;
        }
        if (node->children.find(text[i]) != node->children.end()) {
            node = node->children[text[i]];
        }

        for (int index : node->output) {
            result[patterns[index]].push_back(i - patterns[index].size() + 1);
        }
    }

    return result;
}


