#include<iostream>
#include<stack>
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

/*Binary Tree Traversal
Input:
      1
    /   \
   2     3
  / \   / \
 4   5 6   7
          / \
         8   9
*/

//Preorder Traversal Output : (Root Left Right) 1 2 4 5 3 6 7 8 9
//Inorder Traversal Output  : (Left Root Right) 4 2 5 1 6 3 8 7 9
//Postorder Traversal Output: (Left Right Root) 4 5 2 6 8 9 7 3 1
/** Complexity:
  * TC: O(N)
  * SC: O(N)
 **/
void treeTraversal(Node* root)
{
    if(root == nullptr)
        return;

    vector<int> pre, in, post;

    stack<pair<Node*, int>> st;
    st.push({root, 1});

    while(!st.empty())
    {
        auto it = st.top();
        st.pop();

        if(it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left != nullptr){
                st.push({it.first->left, 1});
            }
        }
        else if(it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right != nullptr){
                st.push({it.first->right, 1});
            }
        }
        else if(it.second == 3)
        {
            post.push_back(it.first->data);
        }

    }

    cout << "Preorder Traversal: ";
    for (int i = 0; i < pre.size(); i++)
    {
        cout << pre[i] << " ";
    }
    cout<<endl<<endl;

    cout << "Inorder Traversal: ";
    for (int i = 0; i < in.size(); i++)
    {
        cout << in[i] << " ";
    }
    cout<<endl<<endl;

    cout << "Postorder Traversal: ";
    for (int i = 0; i < post.size(); i++)
    {
        cout << post[i] << " ";
    }
    cout<<endl<<endl;

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

    treeTraversal(root);

    return 0;
}
