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



map<Node*,int> position;

int main(){
	

	Node *four = new Node(4);
	Node *eight = new Node(8);
	Node *ten = new Node(10);
	Node *twelve = new Node(12);
	Node *fourteen = new Node(14);
	Node *twenty = new Node(20);
	Node *twentytwo = new Node(22);

	vector<Node*> levelOrder = {twenty,eight,twentytwo,four,twelve,ten,fourteen};	
	for(int i=0;i<levelOrder.size();i++){
		position[levelOrder[i]] = i;
	}

	vector<Node*> inOrder = {four,eight,ten,twelve,fourteen};


	int index = INT_MAX;
	Node *root = NULL;
	int pos = 0;
	for(int i=0;i<inOrder.size();i++){
		if(position[inOrder[i]] < index){ 
			root = inOrder[i]; 
			index = position[inOrder[i]];
		}
	}

	cout << nl << " " << root->data << nl;

}