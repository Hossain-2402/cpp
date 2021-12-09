#include<bits\stdc++.h>
using namespace std;


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


void b_sort(vector<int> v){
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

int main(){
	vector<int> v = {1,2,3,4,5,6,7,8,9,10};


	vector<int> numbers = {2,1,4,3,5,6,7,0,9};

	int n = 2;
	// cout << endl;
	// cin >> n;
	// cout << endl;
	binearySearch(v,n);

	print_List(numbers);
	b_sort(numbers);



}