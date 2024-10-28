#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Node
{
public:
	int data;
	Node *left;
	Node *right;
};

Node *newNode(int data)
{
	Node *node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

void level_order(Node *root, int &sum)
{
	// Base case
	if (root == NULL)
		return;

	// //calculate sum
	// if(root->left !=NULL || root->right !=NULL)
	// {
	// 	sum+= root->data;
	// }
	queue<Node *> q;
	q.push(root);

	while (!q.empty())
	{
		Node *pres = q.front();
		q.pop();

		// sum += pres->data;
		// add only leaf node

		// if(pres->left !=NULL && pres->right !=NULL)
		// {
		//   sum+= pres->data;
		// }

		// sum non leaf-node
		if (pres->left != NULL || pres->right != NULL)
		{
			sum += pres->data;
		}

		// Add all Node
		// sum+= pres->data;
		if (pres->left != NULL)
			q.push(pres->left);
		if (pres->right != NULL)
			q.push(pres->right);

		// if(pres->right !=NULL) q.push(pres->right);
	}

	// if root is not null and child is also not null
}

int main()
{

	Node *root = newNode(10);
	root->left = newNode(20);
	root->right = newNode(30);
	root->left->left = newNode(40);
	root->left->right = newNode(50);
	root->right->right = newNode(60);

	int sum = 0;

	level_order(root, sum);
	cout << sum << endl;

	return 0;
}