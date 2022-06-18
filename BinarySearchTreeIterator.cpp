#include <iostream>
#include <stack>

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

// Binary Search Tree Iterator
/*
Input Tree:
                    7
                   / \
                  3   15
                     /  \
                    9   20

Output:
bSTIterator.next() = 3
bSTIterator.next() = 7
bSTIterator.hasNext() = True
bSTIterator.next() = 9
bSTIterator.hasNext() = True
bSTIterator.next() = 15
bSTIterator.hasNext() = True
bSTIterator.next() = 20
bSTIterator.hasNext() = False
*/

//Simple brute force solution is to have all the nodes stored in a vector using inorder traversal and
//basedon that implement next() and hasNext(). TC will be O(1) for next() and hasNext() but SC will be
//O(N) as all elements will be store in inorder format.

//Here we are pushing only some elements to stack. and lets say N elements are pushed
//and thre are N next() call, then the time complexity will be O(N/N) = O(1)

//TC: O(1)
//SC: O(H)

class BSTIterator{
public:
    BSTIterator(Node* root)
    {
        pushAllLeftNodes(root);
    }

    bool hasNext()
    {
        return !bstStack.empty();
    }

    int next()
    {
        Node* node = bstStack.top();
        bstStack.pop();

        pushAllLeftNodes(node->right);
        return node->data;
    }

private:
    void pushAllLeftNodes(Node* root)
    {
        while(root)
        {
            bstStack.push(root);
            root = root->left;
        }
    }

private:
    stack<Node*> bstStack;
};

//Driver function
int main()
{
    Node* root = new Node(7);

    root->left = new Node(3);

    root->right = new Node(15);
    root->right->left = new Node(9);
    root->right->right = new Node(20);

    BSTIterator* obj = new BSTIterator(root);
    cout<<"bSTIterator.next() = "<<obj->next()<<endl;
    cout<<"bSTIterator.next() = "<<obj->next()<<endl;
    if(obj->hasNext())
        cout<<"bSTIterator.hasNext() = True"<<endl;
    else
        cout<<"bSTIterator.hasNext() = False"<<endl;

    cout<<"bSTIterator.next() = "<<obj->next()<<endl;
    if(obj->hasNext())
        cout<<"bSTIterator.hasNext() = True"<<endl;
    else
        cout<<"bSTIterator.hasNext() = False"<<endl;

    cout<<"bSTIterator.next() = "<<obj->next()<<endl;
    if(obj->hasNext())
        cout<<"bSTIterator.hasNext() = True"<<endl;
    else
        cout<<"bSTIterator.hasNext() = False"<<endl;

    cout<<"bSTIterator.next() = "<<obj->next()<<endl;
    if(obj->hasNext())
        cout<<"bSTIterator.hasNext() = True"<<endl;
    else
        cout<<"bSTIterator.hasNext() = False"<<endl;

    return 0;
}
