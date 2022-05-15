#include <iostream>
#include <vector>
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

/*Boundary Traversal Of Binary Tree
Input Tree:
        1
       / \
      2   3
       \   \
        4   5
       /   / \
      6   7   8
*/
//Output: 1 2 4 6 7 8 5 3

bool isLeafNode(Node* node)
{
    return ((node->left == nullptr) && (node->right == nullptr));
}

void addLeftBoundary(Node* root, vector<int>& ans)
{
    Node* curr = root->left;

    while(curr)
    {
        if(!isLeafNode(curr))
            ans.push_back(curr->data);

        if(curr->left != nullptr)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void addLeafNodes(Node* root, vector<int>& ans)
{
    if(isLeafNode(root))
    {
        ans.push_back(root->data);
        return;
    }

    if(root->left !=nullptr)
        addLeafNodes(root->left, ans);

    if(root->right !=nullptr)
        addLeafNodes(root->right, ans);
}

void addRightBoundary(Node* root, vector<int>& ans)
{
    Node* curr = root->right;
    vector<int> tmp;

    while(curr)
    {
        if(!isLeafNode(curr))
            tmp.push_back(curr->data);

        if(curr->right != nullptr)
            curr = curr->right;
        else
            curr = curr->left;
    }

    for(int i = tmp.size()-1; i >= 0; i--)
        ans.push_back(tmp[i]);
}

//Approach :
//1. Add left subtree exluding leaf - O(H)
//2. Add leaf nodes using preorder traversal - O(N)
//3. Add right subtree excluding leaf in reverse order - O(H)
//TC: O(H) + O(N) + O(H) ~ O(N)
//SX: O(N)
vector<int> boundaryTraversal(Node* root)
{
    vector<int> ans;

    if(root == nullptr)
        return ans;

    if(!isLeafNode(root))
        ans.push_back(root->data);

    addLeftBoundary(root, ans);
    addLeafNodes(root, ans);
    addRightBoundary(root, ans);

    return ans;
}

//Driver function
int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->left->right = new Node(4);
    root->left->right->left = new Node(6);

    root->right = new Node(3);
    root->right->right = new Node(5);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(8);

    cout<<"Boundary Traversal: ";
    vector<int> bt = boundaryTraversal(root);
    for(auto val: bt)
        cout<< val << " ";

    cout<<endl;

    return 0;
}
