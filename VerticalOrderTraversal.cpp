#include <iostream>
#include <vector>
#include <map>
#include <set>
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

/*Boundary Traversal Of Binary Tree (CM)
Input Tree:
        1
       / \
      2   3
     / \   \
    4  11   6
           / \
          7   8
         /
        9
*/
//Output:
//Level[-21: 4
//Level[-1]: 2
//Level[0] : 1 11 9 (for sorted values i.e. 1 9 11, use multiset.)
//Level[1] : 3 7
//Level[2] : 6
//Level[3] : 8

//Note: here sorting is considered only based on values and not based on row and column position
//For problem based on rows and column sorting refer: https://github.com/apandia/Leetcode/blob/main/Tree/LC987_VerticalOrderTraversal.cpp

//TC: O(N)
//SC: O(N)

//void traverseTree(Node* root, int level, map<int, vector<int>>& ans)
void traverseTree(Node* root, int level, map<int, multiset<int>>& ans)
{
    if(root == nullptr)
        return;

    //ans[level].push_back(root->data);
    ans[level].insert(root->data);

    traverseTree(root->left, level-1, ans);
    traverseTree(root->right, level+1, ans);
}

void verticalOrderTraversal(Node* root)
{
    //map<int, vector<int>> m;
    map<int, multiset<int>> m;

    traverseTree(root, 0, m);

    cout<<"----------"<<endl;
    for(auto it : m){
        auto key = it.first;
        //vector<int> data = it.second;
        multiset<int> data = it.second;

        cout<<"Level["<<key<<"] = ";
        for(auto val : data){
            cout<<val<< " ";
        }
        cout<<endl;
    }
    cout<<"----------"<<endl;
}


//Driver function
int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(11);

    root->right = new Node(3);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    root->right->right->left->left = new Node(9);
    root->right->right->right = new Node(8);

    cout<<"Vertical Order Traversal: ";
    verticalOrderTraversal(root);

    return 0;
}
