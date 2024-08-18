#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int value;
    vector<TreeNode*> children;

    TreeNode(int val) : value(val) {}
};

bool areIsomorphic(TreeNode* T1, TreeNode* T2) {
    if (T1 == nullptr && T2 == nullptr) {
        return true;
    }
    if (T1 == nullptr || T2 == nullptr) {
        return false;
    }
    if (T1->children.size() != T2->children.size()) {
        return false;
    }
    for (size_t i = 0; i < T1->children.size(); ++i) {
        if (!areIsomorphic(T1->children[i], T2->children[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    TreeNode* T1 = new TreeNode(1);
    T1->children.push_back(new TreeNode(2));
    T1->children.push_back(new TreeNode(3));

    TreeNode* T2 = new TreeNode(1);
    T2->children.push_back(new TreeNode(2));
    T2->children.push_back(new TreeNode(3));

    if (areIsomorphic(T1, T2)) {
        cout << "The trees are isomorphic." << endl;
    } else {
        cout << "The trees are not isomorphic." << endl;
    }

    // Clean up memory
    delete T1->children[0];
    delete T1->children[1];
    delete T1;
    delete T2->children[0];
    delete T2->children[1];
    delete T2;

    return 0;
}
