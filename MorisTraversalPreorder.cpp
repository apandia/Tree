#include <iostream>
#include <string>
#include <sstream>
#include <queue>

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

// Morris Traversal Inorder
/* Morris Algorithm
 * 1. Set the current node = root. if current->leftNode = null
 *      1.1 No left node, the current is a root itself. print node, move right
 * 2. if left node available:
 *      2.1 find rightmost node in left tree
 *          2.1.1 if right pointer of rightmost node is null(i.e. pointing to current/root node)
 *              2.1.1.1 point to current node (root for that tree)
 *              2.1.1.2 print node
 *              2.1.1.3 make current = current->left
 *          2.1.2 if right most node already pointing to current/root node
 *              2.1.2.1 remove the thread
 *              2.1.2.2 move to right
 */

/*
Input Tree:
         1
        / \
       2   3
          / \
         4   5
              \
               6

Output (Inorder): 1 2 3 4 5 6
*/

// For finding the right most node, the traversla will be equivalent to rughtbranch length
// and its time complexity will be amortized (N) and it will run for N in total and not for
// individual node.
// O(N) for traversing all nodes
// Amortized time is the way to express the time complexity when an algorithm has the very
// bad time complexity only once in a while besides the time complexity that happens most of time

//TC: delta/ammortized (N) + O(N) ~ O(N)
//SC: O(1)
void morrisTraversalInorder(Node* root)
{
    Node* curr = root;
    while(curr != nullptr)
    {
        if(curr->left == nullptr)
        {
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else
        {
            Node* rightmostNodeLeftSubTree = curr->left;
            while(rightmostNodeLeftSubTree->right && rightmostNodeLeftSubTree->right != curr)
            {
                rightmostNodeLeftSubTree = rightmostNodeLeftSubTree->right;
            }

            if(rightmostNodeLeftSubTree->right == nullptr)
            {
                rightmostNodeLeftSubTree->right = curr;
                cout<<curr->data<<" ";
                curr = curr->left;
            }
            else
            {
                rightmostNodeLeftSubTree->right = nullptr;
                curr = curr->right;
            }
        }
    }
    cout<<endl;
}

//Driver function
int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);

    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->right->right = new Node(6);

    cout<<"Morris Traversal Preorder = ";
    morrisTraversalInorder(root);

    return 0;
}
