#include <bits/stdc++.h>
using namespace std;
const int  M = 1e9+7;
#define endl  "\n"

// void Ssort(vector<int>&vec){

// 	int n = vec.size();
// 	for(int i=0;i<n;i++){
// 		for(int j=i+1;j<n;j++){
// 			if(vec[j] < vec[i]){
// 				swap(vec[i],vec[j]);
// 			}
// 		}
// 	}
// }

int find_pos(vector<int>vec,int x){

	int min_idx;

	if(x == vec.size()-1){
		return;
	}

	min_idx = find_pos(vec,x+1);

	if(vec[x] < vec[min_idx]){
		min_idx = x;
	}

	return min_idx;
}

void recsort(vector<int>&vec,int pos){

	if(pos == vec.size()-1){
		return;
	}

	int min_idx = find_pos(vec,pos);

	if(pos != min_idx){
		swap(vec[pos],vec[min_idx]);
	}

	recsort(vec,pos+1);

}




int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);

freopen("output.txt","w",stdout);
#endif

vector<int>vec = {4,2,1,3,8,5,9,6};

recsort(vec,0);

for(auto it:vec){
	cout<<it<<" ";
}















































return 0;
}


