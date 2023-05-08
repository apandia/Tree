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

/*Usecase3 Input Tree: (Incorrect value)
       1
      / \
     2   3
      \
       4
        \
         5
Output: 2 1 3
Actual output: 2 1 5
*/

/* Recursive implementation fails for usecase 3.(It gives output as 2,1,5)
 * Reason: say we use below preorder traversal (root, left, right), then 5
 * will be traversed first and will be store in the map. when we come to
 * traverse 3, it will find that 5 is already added for that level(level 1)
 * and it will not add 3.So the output with recursive approach will be 2,1,5
 * instead of expected 2,1,3.
 * So use iterative approach over recursive approach for top view.
 */
 //TC: O(N)
 //SC: O(N)
void traverseTree(Node* root, int level, map<int, int>& m)
{
    if (root == nullptr)
        return;

    if (!m.count(level))
    {
        m[level] = root->data;
    }

    traverseTree(root->left, level - 1, m);
    traverseTree(root->right, level + 1, m);
}

vector<int> treeTopView(Node* root)
{
    vector<int> result;
    map<int, int> m;

    traverseTree(root, 0, m);

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

    cout << "Usecase1: Tree Top View (Recursive): ";
    vector<int> tvr = treeTopView(root1);

    for (auto node : tvr)
    {
        cout << node << " ";
    }
    cout << endl;

    cout << "Usecase2: Tree Top View (Recursive): ";
    tvr = treeTopView(root2);

    for (auto node : tvr)
    {
        cout << node << " ";
    }
    cout << endl;

    cout << "Usecase3: Tree Top View (Recursive): ";
    tvr = treeTopView(root3);

    for (auto node : tvr)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}