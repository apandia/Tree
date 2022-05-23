#include <iostream>
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

//Root to node path
/*
Input Tree:
         1
        / \
       2   3
          / \
         4   5
        / \
       6   7
          /
         8

Output: Path to 8 = 1->3->4->7->8
Output: Path to 6 = 1->3->4->6
Output: Path to 9 = Path does not exist
*/

//TC: O(N)
//SC: O(H) (O(N) for skewed tree)
bool traverseTree(Node* curr, vector<int>& result, int val)
{
    if(curr == nullptr)
        return false;

    //1. Push the node value in vector
    result.push_back(curr->data);

    //2. If node value equals required value return true
    if(curr->data == val)
        return true;

    //3. traverse on left and right subtree and return true if any of the subtree return true
    if(traverseTree(curr->left, result, val) || traverseTree(curr->right, result, val))
        return true;

    //4. Expected value is not found in the path. Pop the last element from vector and return false
    result.pop_back();
    return false;
}

vector<int> rootToNodePath(Node* root, int  value)
{
    vector<int> ans;

    bool pathFound = traverseTree(root, ans, value);

    return ans;
}

//Driver function
int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);

    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    root->right->left->left = new Node(6);
    root->right->left->right = new Node(7);

    root->right->left->right->left = new Node(8);

    cout<<"Path from root to node 8 is = ";
    vector<int> path = rootToNodePath(root, 8);

    for(auto value : path){
        cout<<value<<" ";
    }
    cout<<endl;

    cout<<"Path from root to node 6 is = ";
    path = rootToNodePath(root, 6);

    for(auto value : path){
        cout<<value<<" ";
    }
    cout<<endl;

    cout<<"Path from root to node 9 is = ";
    path = rootToNodePath(root, 9);

    if(path.size() == 0)
        cout<<"Path does not exist"<<endl;

    for(auto value : path){
        cout<<value<<" ";
    }
    cout<<endl;

    return 0;
}
