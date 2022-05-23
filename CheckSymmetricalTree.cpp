#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

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

//Symmetric Binary Tree (symmetric around its center)
/*Usecase1 Input Tree:
        1
      /   \
     2     2
    / \   / \
   3   4 4   3

Output: Tree is Symmetrical
*/

/*Usecase2 Input Tree:
        1
      /   \
     2     3
    / \     \
   4   5     7
      /
     6

Output: Tree is not Symmetrical
*/

//TC: O(N)
//SC: O(N) (for skewed tree)
bool traverseTree(Node* root1, Node* root2)
{
    if((root1 == nullptr) || (root2 == nullptr))
        return (root1 == root2);

    return ((root1->data == root2->data)
            && traverseTree(root1->left, root2->right)
            && traverseTree(root1->right, root2->left));
}

bool isSymmetricalTree(Node* root)
{
    if(root == nullptr)
        return true;

    return traverseTree(root->left, root->right);
}

//Driver function
int main()
{
    //Usecase1
    Node* root1 = new Node(3);

    root1->left = new Node(2);
    root1->left->left = new Node(3);
    root1->left->right = new Node(4);

    root1->right = new Node(2);
    root1->right->left = new Node(4);
    root1->right->right = new Node(3);

    //Usecase2
    Node* root2 = new Node(1);

    root2->left = new Node(2);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->left->right->left = new Node(6);

    root2->right = new Node(3);
    root2->right->right = new Node(7);

    cout<<"Usecase1: ";
    if(isSymmetricalTree(root1))
        cout<< "Tree is Symmetrical"<<endl;
    else
        cout<< "Tree is not Symmetrical"<<endl;

    cout<<"Usecase2: ";
    if(isSymmetricalTree(root2))
        cout<< "Tree is Symmetrical"<<endl;
    else
        cout<< "Tree is not Symmetrical"<<endl;

    return 0;
}
