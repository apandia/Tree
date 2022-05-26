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

// All nodes at distance K from a specific node
/*
Input Tree1:
           3
        /    \
       /      \
      5        1
     / \      / \
    /   \    /   \
   6     2  0     8
        / \
       /   \
      7     4

Input: node=5, k=2
OutPut: 7 4 1

Input: node=3, k=2
OutPut: 6 2 0 8

Input Tree2:
         0
        / \
       2   1
          /
         3
Input: node=3, k=3
OutPut: 2
*/

/* Time Complexity:
 * markParents TC = O(N)
 * while loop to traverse nodes at distance k , worst case TC = O(N)
 * Unorder map TC = O(1)
 */
/* Space Complexity:
 * parentMap = O(N)
 * queue q = O(N)
 * visited = O(N)
 */
//TC: O(N)
//SC: O(N) overall complexity
void markParents(Node* root, unordered_map<Node*, Node*>& parentMap)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* curr = q.front();
        q.pop();

        if(curr && curr->left){
            parentMap[curr->left] = curr;
            q.push(curr->left);
        }

        if(curr && curr->right){
            parentMap[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

vector<int> nodesAtDistanceK(Node* root, Node* target, int k)
{
    vector<int> result;

    if(root == nullptr)
        return result;

    unordered_map<Node*, Node*> parentMap; //key-> node, value-> parent

    markParents(root, parentMap);

    unordered_map<Node*, bool> visited;
    queue<Node*> q;

    q.push(target);
    visited[target] = true;

    int currDistance = 0;

    while(!q.empty())
    {
        if(currDistance == k)
            break;

        currDistance++;

        int size = q.size();
        for(int i =0; i < size; i++)
        {
            Node* current = q.front();
            q.pop();

            if(current->left && !visited[current->left])
            {
                q.push(current->left);
                visited[current->left] = true;
            }

            if(current->right && !visited[current->right])
            {
                q.push(current->right);
                visited[current->right] = true;
            }

            if(parentMap[current] && !visited[parentMap[current]])
            {
                q.push(parentMap[current]);
                visited[parentMap[current]] = true;
            }
        }
    }

    while(!q.empty())
    {
        Node* currNode = q.front();
        q.pop();

        result.push_back(currNode->data);
    }

    return result;
}

//Driver function
int main()
{
    Node* root1 = new Node(3);

    root1->left = new Node(5);
    root1->left->left = new Node(6);
    root1->left->right = new Node(2);
    root1->left->right->left = new Node(7);
    root1->left->right->right = new Node(4);

    root1->right = new Node(1);
    root1->right->left = new Node(0);
    root1->right->right = new Node(8);

    vector<int> nodes = nodesAtDistanceK(root1, root1->left, 2);

    cout << "Nodes at distance 2 from node[5] = : ";
    for(auto node : nodes)
        cout << node <<" ";

    cout<<endl;

    nodes = nodesAtDistanceK(root1, root1, 2);

    cout << "Nodes at distance 2 from root node[3] = : ";
    for(auto node : nodes)
        cout << node <<" ";

    cout<<endl;

    Node* root2 = new Node(0);

    root2->left = new Node(2);

    root2->right = new Node(1);
    root2->right->left = new Node(3);

    nodes = nodesAtDistanceK(root2, root2->right->left, 3);

    cout << "Nodes at distance 3 from node[3] = : ";
    for(auto node : nodes)
        cout << node <<" ";

    cout<<endl;

    return 0;
}
