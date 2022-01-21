#include<bits\stdc++.h>
using namespace std;

const string nl = "\n";


bool solve(vector<vector<int>> v){

	int H = v.size();
	int W = v[0].size();

	int left = 0;
	int top = 0;
	int right = W-1;
	int bottom = H-1;

	map<int,bool> visited;

	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			int element = v[i][j];
			visited[element] = false;
		}
	}

	while(left <= right && top <= bottom){
		for(int i=left;i<W;i++){
			if(!visited[v[top][i]]) cout << " " << v[top][i]; visited[v[top][i]] = true; continue;
			break;
		}
		top ++;

		for(int i=top;i<H;i++){
			if(!visited[v[i][right]]) cout << " " << v[i][right]; visited[v[i][right]] = true; continue;
			break;
		}
		right --;

		for(int i=right;i>=left;i--){
			if(!visited[v[bottom][i]]) cout << " " << v[bottom][i]; visited[v[bottom][i]] = true; continue;
			break;
		}
		bottom --;

		for(int i=bottom;i>=top;i--){
			if(!visited[v[i][left]]) cout << " " << v[i][left]; visited[v[i][left]] = true; continue;
			break;	
		}
		left ++;
	}

}

int main(){

		vector<vector<int>> v = {
			{1,2,3},
			{4,5,6},
			{7,8,9}
		};

		solve(v);

}

