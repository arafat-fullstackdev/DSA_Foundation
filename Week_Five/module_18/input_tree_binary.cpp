#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    // Define Constructor
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* input_tree()
{
    int val;
    cin >> val;
    Node *root;

    if (val == -1)
    {
        root = NULL;
    }
    else
    {
        root = new Node(val);
    }
    queue<Node *> q;
    if (root)
    {
        q.push(root);
    }
    while (!q.empty())
    {
        // 1st out node
        Node *p = q.front();
        q.pop();

        // 2nd all process
        int l, r;
        cin >> l >> r;
        Node *myLeft;
        Node *myRight;
        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);
        if (r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);

        p->left = myLeft;
        p->right = myRight;

        // 3rd children push
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }

    return root;
}

// void level_order(Node *root)
// {
//     queue<Node>
// }
// make recursive function
void order_level(Node *root)
{
    if(root == NULL) 
    {
        cout<< "Tree Blank"<<endl;
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        // 1st ber kore ana
        // f = room or space keep node from push in line
        // front() = head
        // q.pop() = Node out
        Node *f = q.front();
        q.pop();

        // 2nd jabotioyo kaj ja ace
        cout << f->val << " ";

        // 3rd tar children
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    };
};

int main()
{
    Node* root = input_tree();
    order_level(root);

    return 0;
}

//10 20 60 30 60 70 -1 -1 40
//-1 -1 -1 -1 80 -1 -1 -1