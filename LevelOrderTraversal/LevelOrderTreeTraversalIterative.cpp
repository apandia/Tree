#include<iostream>
#include<queue>
#include <vector>

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

/*Level Order Traversal Input
      1
    /   \
   2     3
  / \   / \
 4   5 6   7

output:
1
2 3
4 5 6 7
*/
//TC: O(N)
//SC: O(N)
vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> ans;

    if (root == nullptr)
        return ans;

    queue<Node*> q;
    q.push(root);

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

    cout << "Levelorder Traversal Print: " << endl;
    vector<vector<int>> lo =  levelOrder(root);

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
