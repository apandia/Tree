#include <iostream>
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

//Maximum width of binary tree
/*
Input Tree1:
         1
        / \
       2   3
          / \
         4   5

Output: 4

Input Tree2:
         1
        / \
       2   3
      /     \
     4       5

Output: 4

Input Tree3:
         1
        / \
       2   3
      /     \
     4       5
      \     /
       6   7
Output: 6

Input Tree4:
         1
        / \
       2   3
      /     \
     4       5
    /       /
   6       7
Output: 7

Input Tree5:
         1
        / \
       2   3
      /     \
     4       5
    /         \
   6           7
Output: 8
*/

//TC: O(N)
//SC: O(N) (for queue)
int maximumWIdthBinaryTree(Node* root)
{
    int maxWidth = 0;

    if(root == nullptr)
        return maxWidth;

    queue<pair<Node*, int>> q; //pair of node and node index
    q.push({root, 0});

    while(!q.empty())
    {
        int size = q.size();
        int min = q.front().second;
        int first, last;

        for(int i = 0; i < size; i++)
        {
            long currId = q.front().second - min;//int will give runtime error
            Node* current = q.front().first;

            q.pop();

            if(i == 0)
                first = currId;

            if(i == size-1)
                last = currId;

            if(current->left)
                q.push({current->left, 2*currId+1});

            if(current->right)
                q.push({current->right, 2*currId+2});
        }

        maxWidth = max(maxWidth, last-first+1);

    }

    return maxWidth;
}

//Driver function
int main()
{
    Node* root1 = new Node(1);

    root1->left = new Node(2);

    root1->right = new Node(3);
    root1->right->left = new Node(4);
    root1->right->right = new Node(5);

    Node* root2 = new Node(1);

    root2->left = new Node(2);
    root2->left->left = new Node(4);

    root2->right = new Node(3);
    root2->right->right = new Node(5);

    Node* root3 = new Node(1);

    root3->left = new Node(2);
    root3->left->left = new Node(4);
    root3->left->left->right = new Node(6);

    root3->right = new Node(3);
    root3->right->right = new Node(5);
    root3->right->right->left = new Node(7);

    Node* root4 = new Node(1);

    root4->left = new Node(2);
    root4->left->left = new Node(4);
    root4->left->left->left = new Node(6);

    root4->right = new Node(3);
    root4->right->right = new Node(5);
    root4->right->right->left = new Node(7);

    Node* root5 = new Node(1);

    root5->left = new Node(2);
    root5->left->left = new Node(4);
    root5->left->left->left = new Node(6);

    root5->right = new Node(3);
    root5->right->right = new Node(5);
    root5->right->right->right = new Node(7);


    cout<<"Maximum width of tree1 = "<<maximumWIdthBinaryTree(root1)<<endl;
    cout<<"Maximum width of tree2 = "<<maximumWIdthBinaryTree(root2)<<endl;
    cout<<"Maximum width of tree3 = "<<maximumWIdthBinaryTree(root3)<<endl;
    cout<<"Maximum width of tree4 = "<<maximumWIdthBinaryTree(root4)<<endl;
    cout<<"Maximum width of tree5 = "<<maximumWIdthBinaryTree(root5)<<endl;

    return 0;
}
