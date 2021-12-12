#include<bits\stdc++.h>
using namespace std;

#define MAX 100

void linearSearch(vector<int> v,int a){
	int n = v.size();
	for(int i=0;i<n;i++){
		int element = v[i];
		if(element != a){
			continue;
		}
		cout << endl << " Found " << a << " " << endl;
	}	
}


void binearySearch(vector<int> v,int a){
	int n = v.size();
	bool broken = false;
	int left = 0;
	int right = n-1;
	while(left <= right){
		int mid = (right+left) / 2;
		int element = v[mid];
		if(element == a){
			cout << endl << " Found " << a << " " << endl;
			broken = true;
			break;
		}
		else if(element < a ){
			left = mid+1;
		}
		else{
			right = mid-1;
		}
	}
	if(broken == false){
		cout << endl << " Did not find " << endl;
	}
}

void print_List(vector<int> v){
	int n = v.size();
	cout << endl;
	for(int i=0;i<n;i++){
		cout << v[i] << " ";
	}
	cout << endl;
}


void selection_sort(vector<int> v){
	int n = v.size();
	for(int i=0;i<n;i++){
		int min = i;
		for(int j=i+1;j<n;j++){
			if(v[j] < v[i]){
				min = j;
			}
		}
		int temp = v[i];
		v[i] = v[min];
		v[min] = temp;
	}
	print_List(v);
}


void bubble_sort(vector<int> v){
	int n = v.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(v[j] > v[j+1]){
				int temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
			}
		}
	}
	print_List(v);
}

class Stack{
	int top;
	public:
		int arr[MAX];
		Stack(){
			top = -1;
		}
		void push(int a){
			if(top > (MAX-1)) return ;
			arr[++top] = a;
		}
		int pop(){
			if(top<0) return (MAX + 1);
			int a = arr[top--];
			return a;
		}
		int peek(){
			if(top<0) return (MAX + 1);
			int a = arr[top];
			return a;
		}
		bool isEmpty(){
			if(top < 0) return true;
			return false;
		}
		int size(){
			return (top);
		}
};  



struct Node{
	int data;
	Node *next;
};

void prepend(Node **head,int new_data){
	Node *new_node = (Node*) malloc(sizeof(Node));
	new_node->data = new_data;
	new_node->next = *head;
	*head = new_node;
}
void append(Node **head,int new_data){
	Node *new_node = (Node*) malloc(sizeof(Node));
	new_node->data = new_data;
	new_node->next = NULL;

	if(*head == NULL){
		*head = new_node;
	}

	Node *last_element = *head;
	while(last_element->next != NULL){
		last_element = last_element->next;
	}
	last_element->next = new_node;
}
void printLinkedList(Node *node){
	cout << endl << endl;
	while(node != NULL){
		cout << " " << node->data;
		node = node->next;
	}

	cout << endl;
}

void reverseLinkedList(Node **head){
	Node *prev = NULL;
	Node *current_node = *head;	
	while(current_node != NULL){
		Node *next = current_node->next;
		current_node->next = prev;
		prev = current_node;
		current_node = next; 
	}
	(*head) = prev;
}

struct Node_2{
	int data;
	Node_2 *left;
	Node_2 *right;
	Node_2(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

void inOrderTraversal(Node_2 *root){
	if(root == NULL){
		return;
	}
	inOrderTraversal(root->left);
	cout << " " << root->data;
	inOrderTraversal(root->right);
}

void in_order_traversal(Node_2 *root){
	stack<Node_2 *> s;
	Node_2 *current_node = root;
	while(current_node != NULL || s.empty() == false){
		while(current_node != NULL){
			s.push(current_node);
			current_node = current_node->left;
		}
		current_node = s.top();
		s.pop();
		cout << " " << current_node->data;
		current_node = current_node->right;
	}
}


int main(){
	vector<int> v = {1,2,3,4,5,6,7,8,9,10};


	vector<int> numbers_1 = {2,1,4,3,5,6,7,0,9};
	vector<int> numbers = {2,1,0};
	int n = 2;
	binearySearch(v,n);

	print_List(numbers);
	bubble_sort(numbers);
	selection_sort(numbers);

	class Stack s;
	cout << endl;
	s.push(10);
	s.push(20);
	s.push(30);
	cout << s.pop() << endl << endl << s.size() << endl;

	Node *head = NULL;

	prepend(&head,1);
	append(&head,2);
	append(&head,3);
	prepend(&head,0);

	printLinkedList(head);

	reverseLinkedList(&head);
	printLinkedList(head);




	Node_2 *root  = new Node_2(1);
	root->left = new Node_2(2);
	root->right = new Node_2(3);

	cout << endl;

	in_order_traversal(root);
	
	cout << endl;
}
