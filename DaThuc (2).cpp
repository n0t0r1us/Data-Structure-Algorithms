#include <stdio.h>

struct Node
{
	int HeSo;
	int SoMu;
	Node* next;
};

Node* TaoNut(int hs, int sm)
{
	Node* p = new Node;
	p->HeSo = hs;
	p->SoMu = sm;
	p->next = NULL;
	return p;
}

void ChenCuoi(Node*&head, int hs, int sm)
{
	Node* n = TaoNut(hs, sm);
	if (head == NULL) head = n;
	else {
		Node* p = head;
		while (p->next != NULL)
			p = p->next;
		p->next = n;
	}
}

void In(Node*head)
{
	Node*p = head;
	while (p!= NULL)
	{
		if (p->HeSo != 0)
		{
			if (p->HeSo>0)
				printf("+%dx^%d", p->HeSo, p->SoMu);
			else 
				printf("%dx^%d", p->HeSo, p->SoMu);
		}
		p= p->next;
	}
}

int main()
{
	int hs, sm;
	Node*head = NULL;
    
    while(1)
	{
		scanf("%d%d", &hs, &sm);
		if (hs == 0 && sm == 0)
			break;
		ChenCuoi(head, hs, sm);
	}
	In(head);
    return 0;
}

