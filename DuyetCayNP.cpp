#include<iostream>
using namespace std;

struct Node
{
	int info;
	Node* left;
	Node* right;
};
typedef Node* Tree;
Tree root;

Node* TaoNut(int x)
{
	Node* n = new Node;
	n->info = x;
	n->left = n->right = NULL;
	return n;
}

void DuyetNLR(Tree t)
{
	if (t != NULL)
	{
		cout<<t->info;
		DuyetNLR(t->left);
		DuyetNLR(t->right);
	}
}

void DuyetLNR(Tree t)
{
	if (t != NULL)
	{
		DuyetLNR(t->left);
		cout<<t->info;
		DuyetLNR(t->right);
	}
}

void DuyetLRN(Tree t)
{
	if (t != NULL)
	{
		DuyetLRN(t->left);
		DuyetLRN(t->right);
		cout<<t->info;
	}
}
int main()
{
	root = TaoNut(3);
	root->left = TaoNut(6);
	root->right = TaoNut(8);
	root->right->right = TaoNut(7);
	
	DuyetNLR(root);
	cout<<endl;
	DuyetLNR(root);
	cout<<endl;
	DuyetLRN(root);
	
}



