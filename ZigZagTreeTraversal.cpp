#include<iostream>
#include<queue>
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

/*Zigzag Order Traversal
Input:
      1
    /   \
   2     3
  / \   / \
 4   5 6   7
          / \
         8   9
Output:
1
3 2
4 5 6 7
9 8
*/
//TC: O(N)
//SC: O(N)
vector<vector<int>> zigZagTraversal(Node *root)
{
    vector<vector<int>> ans;

    if (root == nullptr)
        return ans;

    queue<Node*> q;
    q.push(root);
    int currentLevel = 0;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> currLevelData;

        for (int counter = 0; counter < size; counter++)
        {
            Node* current = q.front();
            q.pop();

            if (current->left != nullptr) {
                q.push(current->left);
            }

            if (current->right != nullptr) {
                q.push(current->right);
            }

            currLevelData.push_back(current->data);
            //cout << current->data << " ";
        }

        //cout << endl;

        if(currentLevel %2 != 0 )
        {
            reverse(currLevelData.begin(), currLevelData.end());
        }

        currentLevel++;

        ans.push_back(currLevelData);
    }

    return ans;
}

//Driver function
int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(9);

    cout << "ZigZag Traversal: " << endl;
    vector<vector<int>> lo =  zigZagTraversal(root);

    for (int i = 0; i < lo.size(); i++)
    {
        vector<int> level = lo[i];
        for (int j = 0; j < level.size(); j++)
        {
            cout << level[j] << " ";
        }
        cout << endl;
    }


    return 0;
}
