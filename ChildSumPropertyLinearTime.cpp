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

// Chils sum property - Value of node should be sum of value of child nodes
// nodeVal = leftNodeVal+rightNodeVal
// Only increment operation is allowed and no decrement operation allowed
/*
 * 1. If the child data is less, increment the child data to node data while moving down
 * 2. While coming up, set the node data to sum of child nodes
 */
/*
Input Tree1:
          40                                150
        /     \                           /     \
       /       \                         /       \
      10       20        ------>        80       70 (40 --> 70)
     /  \      / \                     /  \     /  \
    /    \    /   \                   /    \   /    \
   2      5  30   40                 40    40 30     40

Inorder traversal:
2 10 5 40 30 20 40                   40 80 40 150 30 70 40
*/

/*
Input Tree2:
          50                               200
        /    \                           /     \
       /      \                         /       \
      7        2        ------>        100     100
     / \      / \                     /  \     /  \
    /   \    /   \                   /    \   /    \
   3     5  1    30                 50     50 50     50

Inorder traversal:
3 7 5 50 1 2 30                     50 100 50 200 50 100 50
*/

//TC: O(N)
//SC: O(H) O(N) for skewed tree
void changeBinaryTree(Node* root)
{
    if(root == nullptr)
        return;

    int childNodeValue = 0;

    if(root->left)
        childNodeValue += root->left->data;

    if(root->right)
        childNodeValue += root->right->data;

    if(childNodeValue >= root->data){
        root->data = childNodeValue;
    } else {
        if(root->left)
            root->left->data = root->data;

        if(root->right)
            root->right->data = root->data;
    }

    changeBinaryTree(root->left);
    changeBinaryTree(root->right);

    int childTotal = 0;
    if(root->left)
        childTotal += root->left->data;
    if(root->right)
        childTotal += root->right->data;

    //If node is not leaf node
    if(root->left!=nullptr && root->right != nullptr)
        root->data = childTotal;
}

void printInorder(Node* root)
{
    if(root == nullptr)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

//Driver function
int main()
{
    Node *root1 = new Node(40);

    root1->left = new Node(10);
    root1->left->left = new Node(2);
    root1->left->right = new Node(5);

    root1->right = new Node(20);
    root1->right->left = new Node(30);
    root1->right->right = new Node(40);

    cout << "\nTree1 before conversion (Inorder traversal): ";
    printInorder(root1);
    cout << endl;

    changeBinaryTree(root1);

    cout << "\nTree1 after conversion (Inorder traversal): ";
    printInorder(root1);
    cout << endl;

    Node *root2 = new Node(50);

    root2->left = new Node(7);
    root2->left->left = new Node(3);
    root2->left->right = new Node(5);

    root2->right = new Node(2);
    root2->right->left = new Node(1);
    root2->right->right = new Node(30);

    cout << "\nTree2 before conversion (Inorder traversal): ";
    printInorder(root2);
    cout << endl;

    changeBinaryTree(root2);

    cout << "\nTree2 after conversion (Inorder traversal): ";
    printInorder(root2);
    cout << endl;

    return 0;
}
