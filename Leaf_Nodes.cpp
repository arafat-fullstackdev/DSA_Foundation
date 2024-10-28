#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printNodeLeft(Node *root, vector<int>& level)
{
    if(!root)
    return;

    if(!root-> left && !root->right)
    {
       level.push_back(root->data);
        
    }else{
    
        printNodeLeft(root->left, level);
        printNodeLeft(root->right, level);
    }
}

int main(){

    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right = new Node(30);
    root->right->right = new Node(60);
    
    vector<int> level;
    printNodeLeft(root, level);

    //Decending Node
    sort(level.rbegin(), level.rend());
    for (size_t i = 0; i < level.size(); i++)
    {
        if(i>0){
            cout<< " ";
        }
        cout<<level[i];
    }
    cout<<endl;
    return 0;
}