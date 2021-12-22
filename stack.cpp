#include<bits\stdc++.h>
using namespace std;

void find_matrix(vector<int> rowSums,vector<int> colSums){
	int n = rowSums.size();
	int col_index = 0;
	vector<vector<int>> res(n,vector<int>(n));
	for(int i=0;i<n;i++){
		int row_index = 0;
		for(int j=0;j<n;j++){
			int row = rowSums[row_index];
			int col = colSums[col_index];
			int val = ((row < col) ? row : col);

			res[i][j] = val;

			int new_row_val = row-val;
			int temp = new_row_val;
			new_row_val = rowSums[row_index];
			rowSums[row_index] = temp;

			int new_col_val = col-val;
			temp = new_col_val;
			new_col_val = colSums[col_index];
			colSums[col_index] = temp;

			row_index ++;
		}
		col_index ++;
	}

	cout << endl;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << " " << res[i][j];
		}
		cout << endl;
	}

	cout << endl;
}

int main(){

	vector<int> rowSums = {8,6,8};
	vector<int> colSums = {5,7,10};

	find_matrix(rowSums,colSums);


}
