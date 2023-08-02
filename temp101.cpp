#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int  MOD = 1e9+7;

int find(int i,int j,vector<vector<int>>vec){
	if(j<0 || j >= vec[0].size()){
		return -1e8;
	}
	if(i == 0)  return vec[0][j];

	int u = vec[i][j] + find(i-1,j,vec);
	int ul= vec[i][j] + find(i-1,j-1,vec);
	int ur = vec[i][j] + find(i-1,j+1,vec);

	return max(u,max(ul,ur));
}





int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

vector<vector<int>>vec = {{2,1,3},{6,5,4},{7,8,9}};

int n = vec.size();

int m = vec[0].size(); 


int ans = INT_MIN;

for(int j=0;j<m;j++){
	ans = max(ans,find(n-1,j,vec));
}

cout<<ans;























return 0;
}


