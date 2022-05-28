#include <iostream>
#include<vector>
#include <unordered_map>
#include <map>

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

/* Build binary tree from inorder and postorder traversal

inorder =  [9,3,15,20,7]
postorder = [9,15,7,20,3]

Output Tree:
         3
        / \
       9   20
          / \
         15  7
*/

//TC: O(N) ( O(1) for unorder map )
//SC: O(N) (O(N) for usage of map and O(N) for recursion stack space)
Node* buildTreeRecursive(vector<int>& postorder, int postorderStart, int postorderEnd,
                         vector<int>& inorder, int inorderStart, int inorderEnd, unordered_map<int, int>& inorderMap)
{
    if(postorderStart > postorderEnd || inorderStart > inorderEnd)
        return nullptr;

    Node* root = new Node(postorder[postorderEnd]);

    int rootIndexInorderTree = inorderMap[root->data];
    int numbersOnLeft = rootIndexInorderTree - inorderStart;

    root->left = buildTreeRecursive(postorder, postorderStart, postorderStart+numbersOnLeft-1,
                                    inorder, inorderStart, rootIndexInorderTree-1, inorderMap);

    root->right = buildTreeRecursive(postorder, postorderStart+numbersOnLeft, postorderEnd-1,
                                    inorder, rootIndexInorderTree+1, inorderEnd, inorderMap);

    return root;
}

Node* buildTree(vector<int>& postorder, vector<int>& inorder)
{
    if(postorder.size() != inorder.size())
        return nullptr;

    unordered_map<int, int> inorderMap;

    for(int i = 0; i < inorder.size(); i++)
    {
        inorderMap[inorder[i]] = i;
    }

    return buildTreeRecursive(postorder, 0, postorder.size()-1,
                                    inorder, 0, inorder.size()-1, inorderMap);
}

void inorderPrint(Node* root)
{
    if(root ==nullptr)
        return;

    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

void postorderPrint(Node* root)
{
    if(root ==nullptr)
        return;

    postorderPrint(root->left);
    postorderPrint(root->right);
    cout<<root->data<<" ";
}

//Driver function
int main()
{
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};

    Node* root = buildTree(postorder, inorder);

    cout<<"Inorder traversal of tree = ";
    inorderPrint(root);
    cout<<endl;

    cout<<"Postorder traversal of tree = ";
    postorderPrint(root);
    cout<<endl;

    return 0;
}
