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


/* Build binary tree from inorder and preorder traversal
inorder =  [9,3,15,20,7]
preorder = [3,9,20,15,7]

Output Tree:
         3
        / \
       9   20
          / \
         15  7
*/

//TC: O(N) ( O(1) for unorder map )
//SC: O(N) (O(N) for usage of map and O(N) for recursion stack space)
Node* buildTreeRecursive(vector<int>& preorder, int preStart, int preEnd,
                         vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inorderMap)
{
    if(preStart > preEnd || inStart > inEnd)
        return nullptr;

    Node* root = new Node(preorder[preStart]);

    int rootIndexInorderTree = inorderMap[root->data];
    int numbersOnLeft = rootIndexInorderTree - inStart;

    root->left = buildTreeRecursive(preorder, preStart+1, preStart+numbersOnLeft,
                                    inorder, inStart, rootIndexInorderTree-1, inorderMap);

    root->right = buildTreeRecursive(preorder, preStart+numbersOnLeft+1, preEnd,
                                    inorder, rootIndexInorderTree+1, inEnd, inorderMap);

    return root;
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    if(preorder.size() != inorder.size())
        return nullptr;
    
    unordered_map<int, int> inorderMap;

    for(int i = 0; i < inorder.size(); i++)
    {
        inorderMap[inorder[i]] = i;
    }

    Node* root = buildTreeRecursive(preorder, 0, preorder.size()-1,
                                    inorder, 0, inorder.size()-1, inorderMap);

    return root;
}

void inorderPrint(Node* root)
{
    if(root ==nullptr)
        return;

    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

void preorderPrint(Node* root)
{
    if(root ==nullptr)
        return;

    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

//Driver function
int main()
{
    vector<int> inorder = {9,3,15,20,7};
    vector<int> preorder = {3,9,20,15,7};

    Node* root = buildTree(preorder, inorder);

    cout<<"Inorder traversal of tree = ";
    inorderPrint(root);
    cout<<endl;

    cout<<"Preorder traversal of tree = ";
    preorderPrint(root);
    cout<<endl;

    return 0;
}
