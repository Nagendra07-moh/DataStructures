#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MOD = 1000000007;


// void find(int ind,vector<int>vec,int tot,int sum,bool &ans){
// 	if(ind == vec.size()){
// 		return;
// 	}
// 	sum +=vec[ind];
// 	tot -= vec[ind];

// 	if(sum == tot){
// 		ans = true;
// 		return;
// 	}
// 	find(ind+1,vec,tot,sum,ans);
// 	sum -= vec[ind];
// 	tot += vec[ind];
// 	find(ind+1,vec,tot,sum,ans);

// }

bool find(int ind,vector<int>vec,int sum,vector<vector<int>>&dp){
	if(sum == 0){
		return true;
	}else if(ind >= vec.size() || sum<0){
		return false;
	}

	if(dp[ind][sum] != -1){
		return dp[ind][sum];
	}

	return dp[ind][sum] = find(ind+1,vec,sum-vec[ind],dp) || find(ind+1,vec,sum,dp);
}


// bool canPartition(vector<int>& vec) {

// 	int sum = 0;
// 	for(auto it:vec){
// 		sum +=it;
// 	}

// 	if(sum & 1){
// 		return false;
// 	}
// 	vector<vector<int>>dp(sum/2+1,-1);

// 	return find(0,vec,sum/2,dp);

        
// }
// //////////////////////////////////////////////////////////////////////////////////////////////

bool solve(int ind,vector<int>&vec,int tar,int k,int sum,vector<bool>&vis){
	if(k == 1){
		return true;
	}

	if(ind>=vec.size()){
		return  false;
	} 

	if(sum == tar){
		return solve(0,vec,tar,k-1,0,vis);
	}

	for(int i=ind;i<vec.size();i++){
		if(vis[i] || (vec[i] + sum ) > tar){
			continue;
		}
		vis[i] = true;
		if(solve(ind+1,vec,tar,k,sum + vec[i],vis)){
			return true;
		}
		vis[i] = false;
	}

return false;
}

bool canPartitionKSubsets(vector<int>& vec, int k) {
 
 int sum = 0;
 for(auto it:vec){
 	sum += it;
 }

 if(sum/k != 0){
 	return false;
 }

 int tar = sum/k;
 sort(vec.begin(),vec.end(),greater<int>());
 vector<bool>vis(vec.size(),false);
 return solve(0,vec,tar,k,0,vis);

}



int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif


vector<int>vec = {4,3,2,3,5,2,1};
int k = 4;

cout<<canPartitionKSubsets(vec,k);










return 0;
}


