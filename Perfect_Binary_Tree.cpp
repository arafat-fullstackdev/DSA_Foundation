#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// level order
Node *level_Order(const vector<int> &value)
{
    if (value.empty())
    {
        return NULL;
    }
    Node *root = new Node(value[0]);
    queue<Node *> q;
    q.push(root);

    for (size_t i = 1; i < value.size(); i++)
    {
        Node *present = q.front();
        q.pop();

        if (value[i] != -1)
        {
            present->left = new Node(value[i]);
            q.push(present->left);
        }

        if (++i < value.size() && value[i] != -1)
        {
            present->right = new Node(value[i]);
            q.push(present->right);
        }
    }

    return root;
}
boot is_perfect(Node *root, int dep, int level = 0)
{
    if (!root)
    {
        return true;
    }
    // leaf node
    if (!root->left && !root->right)
    {
        return level + 1 == dep;
    }
    // internal node
    if (!root->left || root->right)
    {
        return false;
    }

    return is_perfect(root->left, dep, level + 1) && is_perfect(root->right, dep, level + 1);
}

// max node
int max_dep(Node *node)
{
    if (!node)
    {
        return 0;
    }
    return max(max_dep(node->left), max_dep(node->right)) + 1;
}

int main()
{
    string input;
    getline(cin, input);
    stringstream ss(input);
    vector<int> value;
    int value;

    while (ss >> value)
    {
        value.push_back(value);
    }

    Node *root = level_Order(value);
    int dep = max_dep(root);

    cout << (is_perfect(root, dep) ? "YES" : "NO") << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *left;
//     Node *right;

//     Node(int val) : data(val), left(NULL), right(NULL) {}
// };

// // Level order insertion of nodes
// Node *level_Order(const vector<int> &values)
// {
//     if (values.empty())
//     {
//         return NULL;
//     }
//     Node *root = new Node(values[0]);
//     queue<Node *> q;
//     q.push(root);

//     for (size_t i = 1; i < values.size(); i++)
//     {
//         Node *present = q.front();
//         q.pop();

//         if (values[i] != -1)
//         {
//             present->left = new Node(values[i]);
//             q.push(present->left);
//         }

//         if (++i < values.size() && values[i] != -1)
//         {
//             present->right = new Node(values[i]);
//             q.push(present->right);
//         }
//     }

//     return root;
// }

// // Check if the tree is perfect
// bool is_perfect(Node *root, int depth, int level = 0)
// {
//     if (!root)
//     {
//         return true;
//     }

//     // Leaf node
//     if (!root->left && !root->right)
//     {
//         return level + 1 == depth;
//     }

//     // If one child is missing
//     if (!root->left || !root->right)
//     {
//         return false;
//     }

//     return is_perfect(root->left, depth, level + 1) && is_perfect(root->right, depth, level + 1);
// }

// // Find the maximum depth of the tree
// int max_dep(Node *node)
// {
//     if (!node)
//     {
//         return 0;
//     }
//     return max(max_dep(node->left), max_dep(node->right)) + 1;
// }

// int main()
// {
//     string input;
//     getline(cin, input);
//     stringstream ss(input);
//     vector<int> values; // Change the name to avoid conflict
//     int value;

//     while (ss >> value)
//     {
//         values.push_back(value);
//     }

//     Node *root = level_Order(values);
//     int dep = max_dep(root);

//     cout << (is_perfect(root, dep) ? "YES" : "NO") << endl;

//     return 0;
// }
