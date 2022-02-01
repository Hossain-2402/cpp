#include<bits\stdc++.h>
using namespace std;

const string nl = "\n";

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
void BFS(Node *root){
	queue<Node *> q;
	int counter = 1;
	q.push(root);
	while(!q.empty()){
		int n = q.size();
		for(int i=0;i<n;i++){
			Node *current_node = q.front();
			q.pop();
			cout << " " << current_node->data;
			if(current_node->left != NULL){
				q.push(current_node->left);
				counter ++;
			}
			if(current_node->right != NULL){
				q.push(current_node->right);
				counter ++;
			}
		}
		cout << nl;
	}
}
Node* makeTree(vector<int> nodes){
	vector<Node*> elements;
	elements.push_back(NULL);
	for(int i=1;i<nodes.size();i++){
		if(nodes[i] == 0) elements.push_back(NULL);
		else elements.push_back(new Node(nodes[i]));
	}
	for(int i=1;i<elements.size();i++){
		if(elements[i] == NULL) continue;

		if(i*2 < nodes.size()) elements[i]->left = elements[i*2];

		if(i*2+1 < nodes.size())elements[i]->right = elements[i*2+1];
	}
	cout << " " << elements[1]->right->left->left->left->data << nl << nl;
	return elements[1];
}


void solve(Node *root){

}


int main(){


	vector<int> v = {0,1,2,3,0,0,4,6,0,0,0,0,5,0,0,7,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,8};

	Node *root = makeTree(v);

	BFS(root);


}