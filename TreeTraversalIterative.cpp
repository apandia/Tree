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

//Preorder Traversal Output: (Root Left Right) 1 2 4 5 3 6 7 8 9
/** Complexity:
  * TC: O(N)
  * SC: O(H) where H is height of the tree
  * Worst case space complexity (there is only one node in right tree) = O(N)
  *       1
  *      / \
  *     2   3
  *    / \
  *   4   5
  *  / \
  * 6   7
  * Best case space complexity (balanced tree) =
 **/
vector<int> preorderTraversalIterative(Node* root)
{
    cout << "Preorder Traversal: ";

    vector<int> preOrder;

    if(root == nullptr)
        return preOrder;

    stack<Node*> st;
    st.push(root);

    while(!st.empty())
    {
        Node* curr = st.top();
        st.pop();

        cout<<curr->data<<" ";
        preOrder.push_back(curr->data);

        if(curr->right)
            st.push(curr->right);

        if(curr->left)
            st.push(curr->left);
    }

    cout<<endl;

    return preOrder;
}

//Inorder Traversal Output: (Left Root Right) 4 2 5 1 6 3 8 7 9
/** Complexity:
  * TC: O(N)
  * SC: O(H) where H is height of the tree
  * Worst case space complexity (skewed tree with only left node) = O(N)
  * as all left node will be pusged to the stack
  *       1
  *      /
  *     2
  *    /
  *   3
  *  /
  * 4
  * Best case space complexity (balanced tree) =
 **/
vector<int> inorderTraversalIterative(Node* root)
{
    cout << "Inorder Traversal: ";

    vector<int> inOrder;

    if(root == nullptr)
        return inOrder;

    stack<Node*> st;
    Node* curr = root;

    while(true)
    {
        if(curr){
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            if(st.empty())
                break;

            curr = st.top();
            st.pop();

            cout<<curr->data<<" ";
            inOrder.push_back(curr->data);

            curr = curr->right;
        }
    }

    cout<<endl;

    return inOrder;
}

//Postorder Traversal Output: (Left Right Root) 4 5 2 6 8 9 7 3 1
/** Complexity:
  * TC: O(N)
  * SC: O(2N) as 2 stacks are used
 **/
vector<int> postorderTraversalIterative1(Node* root)
{
    cout << "Postorder Traversal_1: ";

    vector<int> postOrder;

    if(root == nullptr)
        return postOrder;

    stack<Node*> st1, st2;
    st1.push(root);

    while(!st1.empty())
    {
        Node* curr = st1.top();//to reduce space for one pointer it can also be root = st1.top();
        st1.pop();

        st2.push(curr);

        if(curr->left)
            st1.push(curr->left);

        if(curr->right)
            st1.push(curr->right);
    }

    while(!st2.empty())
    {
        cout<<st2.top()->data<<" ";
        postOrder.push_back(st2.top()->data);

        st2.pop();
    }

    cout<<endl;

    return postOrder;
}

//Postorder Traversal Output: (Left Right Root) 4 5 2 6 8 9 7 3 1
/** Complexity:
  * TC: O(2N)
  * Consider below tree:
  * 1
  *  \
  *   2
  *    \
  *     3
  *      \
  *       4
  * To insert all element O(N) and then to move back in parent chain using
  * inner while loop another O(N) complexity will be used so in total 2N
  * SC: O(N)
 **/
vector<int> postorderTraversalIterative2(Node* root)
{
    cout << "Postorder Traversal_2: ";

    vector<int> postOrder;

    if(root == nullptr)
        return postOrder;

    Node* curr = root;
    stack<Node*> st;

    while((curr != nullptr) || !st.empty())
    {
        if(curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            Node* temp = st.top()->right;
            if(temp == nullptr)
            {
                temp = st.top();
                st.pop();
                cout<<temp->data<<" ";
                postOrder.push_back(temp->data);

                while(!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    cout<<temp->data<<" ";
                    postOrder.push_back(temp->data);
                }
            }
            else
            {
                curr = temp;
            }
        }
    }

    cout<<endl;

    return postOrder;
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

    vector<int> pre =  preorderTraversalIterative(root);

    cout << "Preorder Traversal: ";
    for (int i = 0; i < pre.size(); i++)
    {
        cout << pre[i] << " ";
    }
    cout<<endl<<endl;

    vector<int> in =  inorderTraversalIterative(root);

    cout << "Inorder Traversal: ";
    for (int i = 0; i < in.size(); i++)
    {
        cout << in[i] << " ";
    }
    cout<<endl<<endl;

    vector<int> post1 =  postorderTraversalIterative1(root);

    cout << "Postorder Traversal_1: ";
    for (int i = 0; i < post1.size(); i++)
    {
        cout << post1[i] << " ";
    }
    cout<<endl<<endl;

    vector<int> post2 =  postorderTraversalIterative2(root);

    cout << "Postorder Traversal_2: ";
    for (int i = 0; i < post2.size(); i++)
    {
        cout << post2[i] << " ";
    }
    cout<<endl<<endl;

    return 0;
}
