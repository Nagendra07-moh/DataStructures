#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MOD = 1000000007;
void find(int ind,vector<int>ds,int sum,int tar,vector<int>vec,int n){
	if(ind == n){
		if(sum == tar){
			for(auto it:ds) cout<<it<<" ";
				cout<<endl;
		}
		return;
	}
	ds.push_back(vec[ind]);
	sum += vec[ind];
	find(ind+1,ds,sum, tar, vec,n);
	ds.pop_back();
	sum-=vec[ind];
	find(ind+1,ds,sum, tar, vec,n);
	
}


int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

vector<int>vec = {1,2,1};
int n = 3;
int tar = 3;
vector<int>ds;
find(0,ds,0,tar,vec,n);

















return 0;
}


