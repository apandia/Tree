#include<iostream>
#include<stack>
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

/*Binary Tree
Input:
       -10
       /  \
      9   20
         /  \
        15   7
*/

//Max Path Sum : 42 (15->20->7)

int getPathSum(Node* root, int& maxSum)
{
    if(root == nullptr)
        return 0;

    int leftPathSum = getPathSum(root->left, maxSum);
    int rightPathSum = getPathSum(root->right, maxSum);

    maxSum = max(maxSum, leftPathSum + rightPathSum + root->data);

    return root->data + max(leftPathSum, rightPathSum);

}

int maxPathSum(Node* root)
{
    int maxPathSum = INT_MIN;

    getPathSum(root, maxPathSum);

    return maxPathSum;
}

//Driver function
int main()
{
    Node* root = new Node(-10);

    root->left = new Node(9);

    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout<<"Max path Sum = "<<maxPathSum(root)<<endl;

    return 0;
}
