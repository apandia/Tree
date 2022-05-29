#include <iostream>
#include <string>
#include <sstream>
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

//Serialize and Desrialize Binary Tree
/*
Input Tree:
         1
        / \
       2   3
          / \
         4   5
*/

//TC: O(N) (level order traversal)
//SC: O(N)
Node* deserializeTree(string str)
{
    if(str.size() == 0)
        return nullptr;

    stringstream ss(str);
    string token;

    getline(ss, token, ',');

    Node* root = new Node(stoi(token));

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* curr = q.front();
        q.pop();

        //get token for left node
        getline(ss, token, ',');
        if(token == "*")
        {
            curr->left = nullptr;
        }
        else
        {
            curr->left = new Node(stoi(token));
            q.push(curr->left);
        }

        //get token for right node
        getline(ss, token, ',');
        if(token == "*")
        {
            curr->right = nullptr;
        }
        else
        {
            curr->right = new Node(stoi(token));
            q.push(curr->right);
        }
    }

    return root;
}

string serializeTree(Node* root)
{
    string s = "";

    if(root == nullptr)
        return s;

    queue<Node*> q;
    q.push((root));

    while(!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            Node* current = q.front();
            q.pop();

            if (current == nullptr) {
                s.append("*,");
            }
            else
            {
                s.append(to_string(current->data) + ',');
            }

            if (current != nullptr) {
                q.push(current->left);
                q.push(current->right);
            }
        }
    }

    return s;
}

void levelOrderPrint(Node* root)
{
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            Node* current = q.front();
            q.pop();

            if (current->left != nullptr) {
                q.push(current->left);
            }

            if (current->right != nullptr) {
                q.push(current->right);
            }

            cout << current->data << " ";
        }

        cout << endl;
    }
}

//Driver function
int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);

    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    string serializedString = serializeTree(root);
    cout<<"Serialized String = "<<serializedString<<endl;

    Node* deserializedNode = deserializeTree(serializedString);
    if(deserializedNode != nullptr)
    {
        cout<<"Level order print = "<<endl;
        levelOrderPrint(deserializedNode);
    }

    return 0;
}
