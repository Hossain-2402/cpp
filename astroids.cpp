#include<bits\stdc++.h>
using namespace std;

const string nl = "\n";

void findAstroids(vector<int> v){
	int i = 0;
	stack<int> s;
	while(i < v.size()){
		int ast = v[i];

		if(ast > 0){
			s.push(ast);
			i++;
		}

		else{
			while(!s.empty() && s.top() > 0 && s.top() < abs(ast)) s.pop();

			if(s.empty() || s.top() < 0) s.push(ast);

		 	else if(s.top() == abs(ast)) s.pop();

		 	i++;
		}
	}

	cout << nl;
	for(stack<int> t=s;!t.empty();t.pop()) cout << " " << t.top();
	cout << nl;
}

int main(){
	vector<int> v = {5,-10,5};
	findAstroids(v);
}
