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
			if(top<0) return INT_MAX;
			int a = arr[top--];
			return a;
		}
		int peek(){
			if(top<0) return INT_MAX;
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


void BFS(Node_2 *root){
		queue<Node_2 *> q;
		int counter = 1;
		q.push(root);
		vector<vector<int>> height;
		while(!q.empty()){
			int n = q.size();
			vector<int> width;
			for(int i=0;i<n;i++){
				Node_2 *current_node = q.front();
				q.pop();
				width.push_back(current_node->data);
				if(current_node->left != NULL){
					q.push(current_node->left);
					counter ++;
				}
				if(current_node->right != NULL){
					q.push(current_node->right);
					counter ++;
				}
			}
			height.push_back(width);
		}


		for(int i=0;i<height.size();i++){
			vector<int> temp = height[i];
			for(int j=0;j<temp.size();j++){
				cout << " " << temp[j];
			}
			cout << endl;
		}

}

void DFS(Node_2 *root){
	if(root == NULL){
		return ;
	}
	DFS(root->left);
	cout << " " << root->data;
	DFS(root->right);
}

void invert_bineary_tree(Node_2 *root){
	if(root == NULL){
		return ;
	}
	Node_2 *temp = root->left;
	root->left = root->right;
	root->right = temp;
	invert_bineary_tree(root->left);
	invert_bineary_tree(root->right);
}


int pertition(int v[],int left,int right){
	int pivot = v[right];
	int i = left - 1;
	for(int j=left;j<right;j++){
		if(v[j] > pivot) continue;
		i ++;
		int temp = v[i];
		v[i] = v[j];
		v[j] = temp;
	} 
	int temp = v[i+1];
	v[i+1] = v[right];
	v[right] = temp;

	return (i+1);
}

void quickSort(int v[],int left,int right){
	if(left < right){
		int p = pertition(v,left,right);

		quickSort(v,left,p-1);
		quickSort(v,p+1,right);
	}
}

void insert_node_to_BST(Node_2 *root,int new_data){
	if(root->data > new_data){
		if(root->left == NULL){
			Node_2 *new_node = new Node_2(new_data);
			root->left = new_node;
			return ;
		}
		insert_node_to_BST(root->left,new_data);
	}
	if(root->data < new_data){
		if(root->right == NULL){
			Node_2 *new_node = new Node_2(new_data);
			root->right = new_node;
			return ;
		}
		insert_node_to_BST(root->right,new_data);
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




	// Node_2 *root  = new Node_2(1);
	// root->left = new Node_2(2);
	// root->left->left = new Node_2(4);
	// root->left->left->left = new Node_2(6);
	// root->right = new Node_2(3);
	// root->right->right = new Node_2(5);
	// root->right->right->right = new Node_2(7);

	Node_2 *root = new Node_2(27);
	root->left = new Node_2(14);
	root->left->left = new Node_2(10);
	root->left->right = new Node_2(19);
	root->right = new Node_2(35);
	root->right->left = new Node_2(31);
	root->right->right = new Node_2(42);



	cout << endl << "In order :"  << endl;

	in_order_traversal(root);
	cout << endl << endl;
	BFS(root);
	cout << endl;
	DFS(root);
	cout << endl << endl;
	
	// invert_bineary_tree(root);
	inOrderTraversal(root);

	cout << endl << "The new tree : " << endl;

	cout << endl << endl;

	BFS(root);
	cout << endl;

	insert_node_to_BST(root,13);

	BFS(root);

	cout << endl;

}

