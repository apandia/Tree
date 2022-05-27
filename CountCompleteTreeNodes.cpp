#include <iostream>

using namespace std;

class Node {

public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

// Count number of nodes in complete tree
// According to Wikipedia, every level, except possibly the last, is completely filled
// in a complete binary tree, and all nodes in the last level are as far left as possible.
// It can have between 1 and 2h nodes inclusive at the last level h.
/*
Input Tree:
          1
        /   \
       /     \
      2       3
     / \     /
    /   \   /
   4     5 6

OutPut: 6
*/

//TC: (log(N))^2    Log(N) for traversing complete tree x log(N) for finding left/right height
//SC: O(H) ~ O(log N) and h=log N for complete tree
int leftHeight(Node* node)
{
    int leftHeight = 0;

    while(node){
        leftHeight++;
        node = node->left;
    }

    return leftHeight;
}

int rightHeight(Node* node)
{
    int rightHeight = 0;

    while(node){
        rightHeight++;
        node = node->right;
    }

    return rightHeight;
}

int countNodes(Node* root)
{
    if(root == nullptr)
        return 0;

    int lh = leftHeight(root);
    int rh = rightHeight(root);

    if(lh == rh)
        return ((1<<lh)-1);

    return 1 + countNodes(root->left) + countNodes(root->right);
}

//Driver function
int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->left->right = new Node(5);

    root->right = new Node(3);
    root->right->left = new Node(6);

    cout << "Number of nodes in tree = : "<<countNodes(root)<<endl;

    return 0;
}
