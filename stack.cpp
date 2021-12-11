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

void in_order_traversal(Node *root){
	stack<Node *> s;
	Node *current_node = root;
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

void BFS(Node *root){
	queue<Node *> q;
	if(root == NULL){
		return;
	} 
	q.push(root);
	vector<vector<int>> nums;
	while(!q.empty()){
		int size = q.size();
		vector<int> num;
		for(int i=0;i<size;i++){
			Node *current_node = q.front();
			q.pop();
			num.push_back(current_node->data);
			if(current_node->left != NULL){
				q.push(current_node->left);
			}
			if(current_node->right != NULL){
				q.push(current_node->right);
			}
		}
		nums.push_back(num);
	}
	for(int i=0;i<nums.size();i++){
		vector<int> v = nums[i]; 
		for(int j=0;j<v.size();j++){
			cout  << " " << nums[i][j];
		}
		cout << endl;
	}
}

void DFS(Node *root){
	if(root == NULL){
		return ;
	}
	DFS(root->left);
	cout << " " << root->data;
	DFS(root->right);
}

void insert(Node *node,int data){
	Node *new_node = new Node(data);
	queue<Node *> q;
	if(node == NULL){
		return ;
	}
	q.push(node);
	bool inserted = false;
	while(!q.empty()){
		int size = q.size();
		for(int i=0;i<size;i++){
			Node *current_node = q.front();
			q.pop();
			if(current_node->left != NULL){
				q.push(current_node->left);
			}
			else{
				if(inserted == false){
					current_node->left = new_node;
					inserted = true;
				}
			}
			if(current_node->right != NULL){
				q.push(current_node->right);
			}
			else{
				if(inserted == false){
					current_node->right = new_node;
					inserted = true;
				}
			}
		}
	}
}


int main(){
	Node *root  = new Node(1);
	root->left = new Node(2);
	root->left->left = new Node(4);
	root->left->left->left = new Node(8);
	root->left->left->right = new Node(9);
	root->left->right = new Node(5);
	root->left->right->left = new Node(10);
	root->left->right->right = new Node(11);
	root->right = new Node(3);
	root->right->left = new Node(6);
	root->right->left->left = new Node(12);
	root->right->left->right = new Node(13);
	root->right->right = new Node(7);
	root->right->right->right = new Node(15);

	cout << endl << " Non_recursive INORDER_TRAVERSAL : " << endl <<endl;
	in_order_traversal(root);
	cout << endl << endl << endl << " BFS (Breadth First Search) : " << endl <<endl;
	BFS(root);
	cout << endl <<  endl << endl << " DFS (Depth First Search) : " << endl <<endl;
	DFS(root);
	cout << endl << endl << endl;
	insert(root,14);
	cout << endl << endl << endl << " After Insertion : " << endl <<endl;
	BFS(root);

}
