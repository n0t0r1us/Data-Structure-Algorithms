#include<iostream>
#include<cmath>
using namespace std;

struct Node
{
	int info;
	Node *next;
};

Node *head = NULL;

Node* TaoNut(int x)
{
	Node* n = new Node;
	n->info = x;
	n->next = NULL;
	return n;
}

void ChenDau(Node* &head, int x)
{
	Node* p = TaoNut(x);
	p->next = head;
	head = p;
}

void Duyet(Node *head)
{
	Node *p = head;
	while (p != NULL)
	{
		cout<<p->info;
		p = p->next;
	}
}

int main()
{
	head = NULL;
	
	ChenDau(head, 3);
	ChenDau(head, 5);
	ChenDau(head, 7);
		
	Duyet(head);
}
