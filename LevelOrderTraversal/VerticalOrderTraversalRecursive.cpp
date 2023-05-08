#include <iostream>
#include <vector>
#include <map>
#include <set>

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

/*Vertical Traversal Of Binary Tree
Input Tree:
        3
      /   \
     2     4
    / \   /
   0   5 2
*/
//Output: [[0], [2], [3, 2, 5], [4]]
//Note: only 2 and 5 are sorted as they are at same level.

//TC: O(LOG N * LOG N * LOG N * N) ~ O(N Log^3 N)
//Log N operation for each map(2 numbers inner and outer), multiset. Each operation is performed for total of N elements
//SC: O(N)
void traverseTree(Node* root, int verticle, int level, map<int, map<int, multiset<int>>>& m)
{
    if (root == nullptr)
        return;

    m[verticle][level].insert(root->data);

    traverseTree(root->left, verticle-1, level+1, m);
    traverseTree(root->right, verticle + 1, level + 1, m);

}

vector<vector<int>> verticalOrderTraversal(Node* root)
{
    vector<vector<int>> result;
    map<int, map<int, multiset<int>>> m;

    traverseTree(root, 0, 0, m);

    for (auto itrOutMap : m)
    {
        vector<int> tmp;
        for (auto itrInnerMap : itrOutMap.second)
        {
            for (auto node : itrInnerMap.second)
            {
                tmp.push_back(node);
            }
        }
        result.push_back(tmp);
    }

    return result;
}

//Driver function
int main()
{
    Node* root = new Node(3);

    root->left = new Node(2);
    root->left->left = new Node(0);
    root->left->right = new Node(5);

    root->right = new Node(4);
    root->right->left = new Node(2);

    cout << "Vertical Order Traversal (Recursive): "<<endl;
    vector<vector<int>> vot = verticalOrderTraversal(root);

    for (auto level : vot)
    {
        cout << "[";
        for (auto node : level)
        {
                cout << node << " ";
        }
        cout << "] ";

    }
    cout << endl;

    return 0;
}