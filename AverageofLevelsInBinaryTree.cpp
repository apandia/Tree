#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

/* Find average of each level in BT
      3
    /   \
   9     20
        / \
       15  7

output: [3 14.5 11]

Example2:
      1
    /   \
   2     3
  / \   / \
 4   5 6   7

 Output: [ 1 2.5 5.5]
*/

//TC: O(N)
//SC: O(N)
vector<double> averageOfLevels(TreeNode* root)
{
    vector<double> result;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        double sum = 0;

        for(int counter = 0; counter < size; counter++)
        {
            TreeNode* current = q.front();
            q.pop();

            sum += current->data;

            if(current->left)
            {
                q.push(current->left);
            }

            if(current->right)
            {
                q.push(current->right);
            }
        }

        result.push_back(sum/size);
    }

    return result;
}

int main()
{
    TreeNode* root1 = new TreeNode(3);

    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);

    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    vector<double> levelAverage = averageOfLevels(root1);
    for(auto value : levelAverage)
    {
        cout<<value<<" ";
    }

    cout<<endl;

    TreeNode* root2 = new TreeNode(1);

    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);

    root2->right = new TreeNode(3);
    root2->right->left = new TreeNode(6);
    root2->right->right = new TreeNode(7);

    levelAverage = averageOfLevels(root2);
    for(auto value : levelAverage)
    {
        cout<<value<<" ";
    }

    cout<<endl;


    return 0;
}
