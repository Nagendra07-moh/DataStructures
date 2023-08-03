#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MOD = 1000000007;

bool find(vector<int>vec){
	int n = vec.size();
	set<int>mp;	

	sort(vec.begin(),vec.end());

	for(int i=0;i<vec.size()-1;i++){
		mp.insert(vec[i+1] - vec[i]);
	}
	if(mp.size()>1){
		return false;
	}
	return true;

}




int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif


vector<int>vec = {1,2,4};

cout<<find(vec);


















return 0;
}


