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
//Log N operation for each map(2 numbers), multiset and in total N elements
//SC: O(N)
void traverseTree(Node* root, int column, int row, map<int, map<int, multiset<int>>>& m)
{
    if(root == nullptr)
        return;

    m[column][row].insert(root->data);

    traverseTree(root->left, column-1, row+1, m);
    traverseTree(root->right, column+1, row+1, m);
}

vector<vector<int>> verticalOrderTraversal(Node* root)
{
    vector<vector<int>> result;

    map<int, map<int, multiset<int>>> m;

    traverseTree(root, 0, 0, m);

    for(auto it1 : m)
    {
        vector<int> tmp;
        for (auto it2 : it1.second)
        {
            for (auto it3 : it2.second)
            {
                tmp.push_back(it3);
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

    cout<<"Vertical Order Traversal: ";
    vector<vector<int>> vot = verticalOrderTraversal(root);

    cout<<"[";
    for(int i = 0; i< vot.size(); i++)
    {
        cout<<"[";
        for(int j = 0; j < vot[i].size(); j++)
        {
            cout<<vot[i][j];
            if(j < vot[i].size()-1)
                cout<<", ";
        }
        cout<<"]";
        if(i < vot.size()-1)
            cout<<", ";
    }
    cout<<"]"<<endl;

    return 0;
}
