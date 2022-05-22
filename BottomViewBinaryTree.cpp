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

//Bottom View Of Binary Tree
/*Usecase1 Input Tree:
        3
      /   \
     2     4
    / \   /
   0   5 2

Output: 0 2 2 4
*/

/*Usecase2 Input Tree:
        1
      /   \
     2     3
    / \     \
   4   5     7
      /
     6

Output: 4 6 5 3 7
*/

/*Usecase3 Input Tree:
       1
      / \
     2   3
      \
       4
        \
         5

Output: 2 4 5
*/

//Use iterative approach over recursive approach for bottom view.
//Refer top view implementation for the detail reason:
//https://github.com/apandia/Tree/blob/main/TopViewBinaryTree.cpp

//TC: O(N)
//SC: O(2N) ~ O(N)  (one queue and one map is used)
vector<int> bottomViewBinaryTree(Node* root)
{
    vector<int> ans;
    if(root == nullptr)
        return ans;

    //map key is vertical level, value is first valu in that level
    map<int, int> m;

    queue<pair<Node*, int>> q;//pair of Node and level

    q.push({root, 0});

    while(!q.empty())
    {
        auto it = q.front();
        q.pop();

        Node* curr = it.first;
        int vLevel = it.second;

        m[vLevel] = curr->data;

        if(curr->left)
            q.push({curr->left, vLevel-1});

        if(curr->right)
            q.push({curr->right, vLevel+1});
    }

    for(auto it : m)
    {
        ans.push_back(it.second);
    }

    return ans;
}

//Driver function
int main()
{
    //Usecase1
    Node* root1 = new Node(3);

    root1->left = new Node(2);
    root1->left->left = new Node(0);
    root1->left->right = new Node(5);

    root1->right = new Node(4);
    root1->right->left = new Node(2);

    //Usecase2
    Node* root2 = new Node(1);

    root2->left = new Node(2);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->left->right->left = new Node(6);

    root2->right = new Node(3);
    root2->right->right = new Node(7);

    //Usecase3
    Node* root3 = new Node(1);

    root3->left = new Node(2);
    root3->left->right = new Node(4);
    root3->left->right->right = new Node(5);

    root3->right = new Node(3);

    cout<<"Usecase1 Tree Top View: ";
    vector<int> tvr1 = bottomViewBinaryTree(root1);

    for(int i = 0; i< tvr1.size(); i++)
    {
        cout<<tvr1[i]<<" ";
    }
    cout<<endl;

    cout<<"Usecase2 Tree Top View: ";
    vector<int> tvr2 = bottomViewBinaryTree(root2);

    for(int i = 0; i< tvr2.size(); i++)
    {
        cout<<tvr2[i]<<" ";
    }
    cout<<endl;

    cout<<"Usecase3 Tree Bottom View: ";
    vector<int> tvi = bottomViewBinaryTree(root3);

    for(int i = 0; i< tvi.size(); i++)
    {
        cout<<tvi[i]<<" ";
    }
    cout<<endl;

    return 0;
}
