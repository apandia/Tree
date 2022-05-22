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
    if(root == nullptr)
        return;

    if(!m.count(level))
        m[level] = root->data;

    traverseTree(root->left, level-1, m);
    traverseTree(root->right, level+1, m);
}

vector<int> treeTopView(Node* root)
{
    vector<int> result;

    map<int, int> m;

    traverseTree(root, 0, m);

    for(auto it : m)
    {
        result.push_back(it.second);
    }

    return result;
}

//TC: O(N)
//SC: O(2N) ~ O(N)  (one queue and one map is used)
vector<int> treeTopViewIterative(Node* root)
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

        if(!m.count(vLevel))
        {
            m[vLevel] = curr->data;
        }

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
    Node* root = new Node(3);

    root->left = new Node(2);
    root->left->left = new Node(0);
    root->left->right = new Node(5);

    root->right = new Node(4);
    root->right->left = new Node(2);

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

    cout<<"Tree Top View (Recursive): ";
    vector<int> tvr = treeTopView(root3);

    for(int i = 0; i< tvr.size(); i++)
    {
        cout<<tvr[i]<<" ";
    }
    cout<<endl;

    cout<<"Tree Top View (Iterative): ";
    vector<int> tvi = treeTopViewIterative(root3);

    for(int i = 0; i< tvi.size(); i++)
    {
        cout<<tvi[i]<<" ";
    }
    cout<<endl;

    return 0;
}
