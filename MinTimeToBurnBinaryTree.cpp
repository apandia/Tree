#include <iostream>
#include <vector>
#include <unordered_map>
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

// Minimum time taken to BURN Binary Tree
/*
Input Tree:
         1
        / \
       /   \
      2     3
     /     / \
    /     /   \
   4     5     6
    \
     \
      7

Input: node=2
OutPut: 3 (max time is 3 for path 1->3->6, 1->3->5)

Input: node=7
OutPut: 5 (max time is 5 for path 7->4->2->1->3->5, 7->4->2->1->3->6)

*/

/* Time Complexity:
 * markParents TC = O(N)
 * while loop to traverse(BFS Traversal) nodes at distance k , worst case TC = O(N)
 * Unorder map TC = O(1)
 */
/* Space Complexity:
 * parentMap = O(N)
 * queue q = O(N)
 * visited = O(N)
 */
//TC: O(N)
//SC: O(N) overall complexity
//Driver function
void markParents(Node* root, unordered_map<Node*, Node*>& parentMap)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* current = q.front();
        q.pop();

        if(current && current->left){
            q.push(current->left);
            parentMap[current->left] = current;
        }

        if(current && current->right){
            q.push(current->right);
            parentMap[current->right] = current;
        }
    }
}

int minTimeToBurnBinaryTree(Node* root, Node* source)
{
    int minTime = 0;

    if(root == nullptr)
        return minTime;

    unordered_map<Node*, Node*> parentMap;
    markParents(root, parentMap);

    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    q.push(source);

    visited[source] = true;

    while(!q.empty())
    {
        int size = q.size();
        bool nodeBurned = false;

        for(int i = 0; i < size; i++)
        {
            Node* temp = q.front();
            q.pop();

            if(temp->left && !visited[temp->left])
            {
                visited[temp->left] = true;
                q.push(temp->left);
                nodeBurned = true;
            }

            if(temp->right && !visited[temp->right])
            {
                visited[temp->right] = true;
                q.push(temp->right);
                nodeBurned = true;
            }

            if(parentMap[temp] && !visited[parentMap[temp]])
            {
                visited[parentMap[temp]] = true;
                q.push(parentMap[temp]);
                nodeBurned = true;
            }
        }

        if(nodeBurned)
            minTime++;

    }

    return minTime;
}

int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->left->right = new Node(7);

    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    int minTime = minTimeToBurnBinaryTree(root, root->left);

    cout << "Min time to Burn BT from node[2] = : "<<minTime<<endl;

    minTime = minTimeToBurnBinaryTree(root, root->left->left->right);

    cout << "Min time to Burn BT from node[7] = : "<<minTime<<endl;

    return 0;
}
