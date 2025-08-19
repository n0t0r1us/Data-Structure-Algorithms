#include <iostream> 

using namespace std;
struct Node{
	int data;
	Node* next;
	
};
void insertHead(Node*& head, int value){
	Node* newNode = new Node;
	newNode -> data = value;
	newNode -> next = head;
	head = newNode;
} 
bool tangDan(Node* head){
	Node* curr = head;
	while (curr != NULL && curr -> next != NULL){
		if(curr -> data > curr -> next -> data){
			return false;
		}
		curr = curr -> next;
	}
	return true;
}
int main(){
	int n;
	cin >> n;
	Node* head = NULL;
	for (int i = 0; i < n; i++){
		int value;
		cin>>value;
		insertHead(head, value);
	}
	if (tangDan(head)){
		cout << "YES";
	} else{
		cout << "NO";
	}

	return 0;
}
