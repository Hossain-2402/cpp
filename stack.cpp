#include<bits\stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
	Node(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

Node* createMaxHeap(Node *heap[],int heap_size){
	Node *root = heap[1];
	for(int i=1;i<heap_size;i++){
		Node *current_node = heap[i];
		current_node->left = heap[i*2];
		current_node->right = heap[i*2+1];
	}
	return root;
} 

void BFS(Node *root){
	queue<Node *> q;
	q.push(root);
	cout << endl;
	while(!q.empty()){
		int n = q.size();
		for(int i=0;i<n;i++){
			Node *current_node = q.front();
			q.pop();
			cout << " " << current_node->data;
			if(current_node->left != NULL){
				q.push(current_node->left);
			}
			if(current_node->right != NULL){
				q.push(current_node->right);
			}
		}
		cout << endl;
	}
}


int main(){

	int heap_size = 8;

	Node *heap[heap_size];
	heap[0] = NULL;
	heap[1] = new Node(100);
	heap[2] = new Node(40);
	heap[3] = new Node(50);
	heap[4] = new Node(10);
	heap[5] = new Node(15);
	heap[6] = new Node(30);
	heap[7] = new Node(40);


	Node *root = createMaxHeap(heap,heap_size);

	BFS(root);

}


