#include<bits\stdc++.h>
using namespace std;

const string nl = "\n";
typedef vector<int> v;
int heap_size = 1;

struct Node {
	int data;
	Node *left;
	Node *right;
	Node(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

	
void BFS(Node *root){
	queue<Node*> q;
	q.push(root);
	cout << nl;
	while(!q.empty()){
		int n = q.size();
		for(int i=0;i<n;i++){
			Node *current_node = q.front();
			q.pop();
			heap_size ++;
			cout << " " << current_node->data;
			if(current_node->left != NULL){
				q.push(current_node->left);
			}
			if(current_node->right != NULL){
				q.push(current_node->right);
			}
		}
		cout << nl;
	}
}

void create_max_heap(Node *root,int heap_size){
	Node* heap[heap_size];
	queue<Node*> q;
	q.push(root);
	int index = 1;
	heap[0] = NULL;
	heap[index] = root;
	while(!q.empty()){
		int n = q.size();
		for(int i=0;i<n;i++){
			Node *current_node = q.front();
			if(heap[index]->data != current_node->data) continue;

			heap[index*2] = current_node->left;
			heap[index*2+1] = current_node->right;
			index ++;

			q.pop();
			if(current_node->left != NULL){
				q.push(current_node->left);
			}
			if(current_node->right != NULL){
				q.push(current_node->right);
			}
		}
	}
	cout << nl;
	for(int i=0;i<heap_size;i++){
		if(heap[i] == NULL) cout << " " << "NULL";

		else cout << " " << heap[i]->data;
	}
	cout << nl;
}


int main(){

	Node *root = new Node(27);
	root->left = new Node(14);
	root->left->left = new Node(10);
	root->left->right = new Node(11);
	root->right = new Node(20);
	root->right->left = new Node(15);
	root->right->right = new Node(8);

	BFS(root);

	create_max_heap(root,heap_size);


}