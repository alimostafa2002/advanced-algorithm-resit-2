#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    int height;
    vector<Node*> children;
};

void computeElementAndHeight(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << "Node Value: " << root->value << " | Subtree Height: " << root->height << endl;

    for (Node* child : root->children) {
        computeElementAndHeight(child);
    }
}

int main() {
    Node* root = new Node{1, 0, {}};
    Node* child1 = new Node{2, 1, {}};
    Node* child2 = new Node{3, 1, {}};
    Node* grandchild1 = new Node{4, 2, {}};
    Node* grandchild2 = new Node{5, 2, {}};

    root->children.push_back(child1);
    root->children.push_back(child2);
    child1->children.push_back(grandchild1);
    child2->children.push_back(grandchild2);

    computeElementAndHeight(root);

    return 0;
}