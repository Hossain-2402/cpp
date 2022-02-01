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
	return elements[1];
}




vector<int> inOrder;
map<Node*,Node*> parent;
void inOrderTraversal(Node *root){
	if(root == NULL){
		return;
	}
	inOrderTraversal(root->left);
	inOrder.push_back(root->data);
	inOrderTraversal(root->right);
}
void set_parent(Node *root){
	queue<Node *> q;
	q.push(root);
	while(!q.empty()){
		int n = q.size();
		for(int i=0;i<n;i++){
			Node *current_node = q.front();
			q.pop();
			if(current_node->left != NULL){
				q.push(current_node->left);
				parent[current_node->left] = current_node;
			}
			if(current_node->right != NULL){
				q.push(current_node->right);
				parent[current_node->right] = current_node;
			}
		}
	}
}

void solve(Node *root,Node *node_1,Node *node_2){
	inOrderTraversal(root);
	set_parent(root);

	map<int,int> position;
	for(int i=0;i<inOrder.size();i++){
		position[inOrder[i]] = i ;
	}


	Node *current_node = node_1;
	int res = current_node->data;

	while(current_node->data != node_2->data){
		if(current_node->left == NULL && current_node->right == NULL){
			current_node = parent[current_node];
			res+=current_node->data;
			continue;
		}
		if(parent[current_node] != NULL && current_node->left != NULL && current_node->right != NULL){
			Node *one = parent[current_node];
			Node *two = current_node->left;
			Node *three = current_node->right;

			int target = position[node_2->data];

			int one_index = abs(target-position[one->data]);
			int two_index = abs(target-position[two->data]);
			int three_index = abs(target-position[three->data]);

			
			int ans = min(one_index,two_index);
			ans = min(ans,three_index);

			if(ans == one_index){
				current_node = one;
				res+=current_node->data;
			}
			else if(ans == two_index){
				current_node = two;
				res+=current_node->data;
			}
			else{
				current_node = three;
				res+=current_node->data;
			}
			continue;
		}
		if(parent[current_node] == NULL || current_node->left == NULL || current_node->right == NULL){
			if(parent[current_node] == NULL){
				Node *two = current_node->left;
				Node *three = current_node->right;

				int target = position[node_2->data];

				int two_index = abs(target-position[two->data]);
				int three_index = abs(target-position[three->data]);

				int ans = min(two_index,three_index);

				if(ans == two_index){
					current_node = two;
					res+=current_node->data;
				}
				else{
					current_node = three;
					res+=current_node->data;
				}
				continue;
			}
			continue;
			if(current_node->left == NULL){
				Node *one = parent[current_node];
				Node *three = current_node->right;

				int target = position[node_2->data];

				int one_index = abs(target-position[one->data]);
				int three_index = abs(target-position[three->data]);

				int ans = min(one_index,three_index);

				if(ans == one_index){
					current_node = one;
					res+=current_node->data;
				}
				else{
					current_node = three;
					res+=current_node->data;
				}
				continue;
			}
			continue;
			if(current_node->right == NULL){
					Node *one = parent[current_node];
					Node *two = current_node->left;

					int target = position[node_2->data];

					int one_index = abs(target-position[one->data]);
					int two_index = abs(target-position[two->data]);

					int ans = min(one_index,two_index);

					if(ans == one_index){
						current_node = one;
						res+=current_node->data;
					}
					else{
						current_node = two;
						res+=current_node->data;
					}
					continue;
				}
				continue;	
		}
	}
	cout << " " << res;
}


int main(){


	vector<int> v = {0,1,2,3,8,7,4,6,0,0,0,0,0,0,12,5};

	Node *root = makeTree(v);

	BFS(root);
	cout << " The nodes are " << root->left->left->data << " , " << root->right->right->right->data << nl << " The sum is :"; 
	solve(root,root->left->left,root->right->right->right);


}