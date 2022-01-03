#include<bits\stdc++.h>
using namespace std;

#define FOR(n) for(int i=1;i<n;i++)
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


void max_heap(Node *heap[],int heap_size,int index){
	int left_node = index * 2;
	int right_node = index * 2 + 1;
	int largest;

	if(left_node < heap_size && heap[left_node] > heap[index]) largest = left_node;

	else largest = index; 

	if(right_node < heap_size && heap[right_node] > heap[largest]) largest = right_node;

	if(largest == index) return;

	Node *temp = heap[largest];
	heap[largest] = heap[index];
	heap[index] = temp;

	max_heap(heap,heap_size,largest);
}

int main(){


	int heap_size = 8;

	Node *heap[heap_size];
	heap[0] = NULL;
	heap[1] = new Node(20);
	heap[2] = new Node(40);
	heap[3] = new Node(50);
	heap[4] = new Node(10);
	heap[5] = new Node(15);
	heap[6] = new Node(30);
	heap[7] = new Node(40);

	max_heap(heap,heap_size,1);

	cout << nl;
	FOR(heap_size) cout << " " << heap[i]->data;
	cout << nl;

}


        // 20
        // 40      50
        // 10      15      30      40