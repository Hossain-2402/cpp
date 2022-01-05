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

void printHeap(Node *heap[],int heap_size){
	cout << nl;
	for(int i=0;i<heap_size;i++){
		if(heap[i] == NULL) cout << " NULL";

		else cout << " " << heap[i]->data;
	}
	cout << nl;
}

void maxHeap(Node *heap[];int heap_size;int index){
	int leftIndex = index * 2;
	int rightIndex = index * 2 + 1;

	int largestIndex;

	if(leftIndex < heap_size && heap[leftIndex] > heap[index]) largestIndex = leftIndex;

	else largestIndex = index;

	if(rightIndex < heap_size && heap[rightIndex] > heap[largestIndex]) largestIndex = rightIndex;

	if(largestIndex == index) return;

	Node *temp = heap[largestIndex];
	heap[largestIndex] = heap[index];
	heap[index] = temp;

	maxHeap(heap,heap_size,largest);
}

void buildMaxHeap(Node *heap,int heap_size){
	int index = heap_size-1;
	for(int i=(index/2);i>0;i=i/2) {
		maxHeap(heap,heap_size,i);
	}
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

	printHeap(heap,heap_size);

}
