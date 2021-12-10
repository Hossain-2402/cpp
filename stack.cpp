#include<bits\stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *next;
};

vector<int> v;
 
void prepend(Node **head,int new_data){
	Node *new_node = (Node*) malloc(sizeof(Node));
	new_node->data = new_data;
	new_node->next = (*head);
	(*head) = new_node; 
}
void append(Node **head,int new_data){
	Node *new_node = (Node*) malloc(sizeof(Node));
	Node *last_element = *head;
	
	new_node->data = new_data;
	new_node->next = NULL;

	if(*head == NULL){
		*head = new_node;
		return;
	}
	while(last_element->next != NULL){
		last_element = last_element->next;
	}
	last_element->next = new_node;  
	return;
}
bool search(Node *node,int info){
	while(node != NULL){
		if(node->data == info){
			return true;
		}
		node = node->next;
	}
	return false;
}
void printTheLinkedList(Node *node){
	while(node != NULL){
		cout << " " << node->data;
		v.push_back(node->data);
		node = node->next;
	}
}
void reverse(){ 
	int left = 0;
	int right = v.size() - 1;
	while(left < right){
		int temp = v[left];
		v[left] = v[right];
		v[right] = temp;
		left++;
		right--;
	}
	for(int i=0;i<=(v.size() - 1);i++){
		cout << " " << v[i];
	}
}
void sortIt(){
	for(int i=0;i<=(v.size() - 1);i++){
		int largest = i;
		for(int j=i+1;j<=(v.size() - 1);j++){
			if(v[j] > v[largest]){
				largest = j;
			}
		}
		if(largest != i){
			int temp = v[largest];
			v[largest] = v[i];
			v[i] = temp;
		}
	}
	for(int i=0;i<=(v.size() - 1);i++){
		cout << " " << v[i];
	}
}

int main(){
	Node *head = NULL;
	append(&head,2);
	append(&head,5);
	append(&head,4);
	append(&head,3);
	append(&head,7);
	append(&head,6);
	append(&head,10);
	append(&head,9);
	append(&head,8);
	prepend(&head,1);
	
	cout << endl ;
	printTheLinkedList(head);
	cout << endl ;

	bool searching = search(head,10);
	if(searching == 1){
		cout << endl << " TRUE" << endl;
	}
	else{
		cout << endl << " FALSE" << endl;
	}

	cout << endl;
	reverse();
	cout << endl;


	cout << endl;
	sortIt();
	cout << endl;
}


/*


	pointer soters the [address] of another variable


	int var = 10;
	int *addr_var = &var;
	int *address = &adr_var;
	int **address = &address

*/
