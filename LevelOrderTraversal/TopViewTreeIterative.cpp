#include <iostream>
#include <vector>
#include <map>
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

//Top View Of Binary Tree
/*Usecase1 Input Tree:
        3
      /   \
     2     4
    / \   /
   0   5 2
Output: 0 2 3 4
*/

/*Usecase2 Input Tree:
        1
      /   \
     2     3
    / \     \
   4   5     7
      /
     6
Output: 4 2 1 3 7
*/

/*Usecase3 Input Tree:
       1
      / \
     2   3
      \
       4
        \
         5
Output: 2 1 3
*/

// Iterative approach solves the problem with recursive approach.
// Please refer "https://github.com/apandia/Tree/blob/main/LevelOrderTraversal/TopViewTreeRecursive.cpp" for issue with recursive approach.
//TC: O(N)
//SC: O(2N) ~ O(N)  (one queue and one map is used)
vector<int> treeTopView(Node* root)
{
    vector<int> result;

    if (root == nullptr)
        return result;

    map<int, int> m;

    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        Node* curr = it.first;
        int level = it.second;

        if (!m.count(level))
        {
            m[level] = curr->data;
        }

        if (curr->left)
            q.push({ curr->left, level - 1 });

        if (curr->right)
            q.push({ curr->right, level + 1 });
    }


    for (auto it : m)
    {
        result.push_back(it.second);
    }

    return result;
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

    cout << "Usecase1: Tree Top View (Iterative): ";
    vector<int> tvr = treeTopView(root1);

    for (auto node : tvr)
    {
        cout << node << " ";
    }
    cout << endl;

    cout << "Usecase2: Tree Top View (Iterative): ";
    tvr = treeTopView(root2);

    for (auto node : tvr)
    {
        cout << node << " ";
    }
    cout << endl;

    cout << "Usecase3: Tree Top View (Iterative): ";
    tvr = treeTopView(root3);

    for (auto node : tvr)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}