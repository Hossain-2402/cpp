#include<bits\stdc++.h>
using namespace std;


bool isAlienSorted(vector<string> words,string order){
	map<char,int> map;
	int index = 1;
	for(int i=0;i<order.size();i++){
		char a = order[i];
		map[a] = index;
		index ++;
	}
	int length_1 = words[0].size();
	int length_2 = words[1].size();
	int length = length_1;
	
	for(int i=0;i<length;i++){
		string word_1 = words[0];
		string word_2 = words[1];
		if(map[word_1[i]] > map[word_2[i]]) {
			cout << map[word_1[i]] << " " << map[word_2[i]] << endl;
			return false;
		}
		continue;
	}
	return true;
}

int main(){

	vector<string> words = {"hello", "leetcode"};
	string order = "hlabocdefgijkmnpqrstuvwxyz";

	bool res = isAlienSorted(words,order);
	cout <<  endl << " " << res << endl;

}