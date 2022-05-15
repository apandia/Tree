#include<iostream>
#include <queue>
#include <map>
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
        1
       / \
      2   3
       \   \
        4   5
       /
      6
*/

//Right Side View: 1 3 5 6
//Additinal Comment: Recursive approach is preferred as space complexity might
//be less in as chances of skewed tree is very less and also code is shorter

//Iterative Approach1 : using queue and vector
//TC - O(N)
//SC - O(number of leaf node)
//So the number of leaf nodes are high i.e then higher space complexity
vector<int> getRightView(Node* root)
{
   vector<int> ans;

    if (root == nullptr)
        return ans;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        vector<int> cln;

        for(int i =0; i < size; i++)
        {
            Node* curr = q.front();
            q.pop();

            cln.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

        ans.push_back(cln.back());
    }

    return ans;
}

//Iterative Approach2: Using queue and map, print values inside the function
//map will store level wise data in sorted manner
void getRightSideView(Node* root)
{
     if (root == nullptr)
         return;

     queue<pair<Node*, int>> q; //Pair of node and level
     q.push({root, 0});

     map<int, int> m;//map for level(key) and node value(data)

     while(!q.empty())
     {
         auto it = q.front();
         q.pop();

         Node* current = it.first;
         int level = it.second;

         if(!m.count(level)){
             m[level] = current->data;
         }

         if(current->right != nullptr)
             q.push({current->right, level+1});

         if(current->left != nullptr)
             q.push({current->left, level+1});
     }

     for(auto val : m){
         cout<<val.second<<" ";
     }
     cout<<endl;
}

//Recursive Approach : Using reverse preorder traversal i.e Root, Right, Left
//Normal preorder traversal: Root Left Right
//TC - O(N)
//SC - O(H)
//Space complexity in case of skewed tree will be O(N)
void getRightSideView(Node* root, int level, vector<int>& ans)
{
    if(root == nullptr)
        return;

    if(ans.size() == level){
        ans.push_back(root->data);
    }

    getRightSideView(root->right, level+1, ans);
    getRightSideView(root->left, level+1, ans);
}

vector<int> rightSideView(Node* root)
{
    vector<int> ans;

    getRightSideView(root, 0, ans);

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

    cout<<"RightView Iterative Approach1= ";
    vector<int> lo = getRightView(root);

    for(int j = 0; j < lo.size(); j++ )
    {
        cout<<lo[j]<< " ";
    }
    cout<<endl;

    cout<<"RightView Iterative Approach2= ";
    getRightSideView(root);

    cout<<"RightView Recursive= ";
    vector<int> rsv = rightSideView(root);

    for(int j = 0; j < rsv.size(); j++ )
    {
        cout<<rsv[j]<< " ";
    }
    cout<<endl;

    return 0;
}
