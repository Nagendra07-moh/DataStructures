	//FROG JUMP L-3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MOD = 1000000007;

int find(int ind,vector<int>vec,vector<int>&dp){
	if(ind == 0){
		return 0;
	}

	if(dp[ind] != -1){
		return  dp[ind];
	}

	int one = abs(vec[ind] - vec[ind-1]) + find(ind-1,vec,dp);

	int two  = INT_MAX;

	if(ind > 1){

	 two = abs(vec[ind] - vec[ind-2]) + find(ind-2,vec,dp);
	}


	return dp[ind] =  min(one,two);
}



int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif


int t;
cin>>t;
while(t--){
	int n;
	cin>>n;
	vector<int>vec;

	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		vec.push_back(x);
	}

	//MEMOIZATION
	// vector<int>dp(n,-1);
	// cout<<find(vec.size()-1,vec,dp)<<endl;

	//TABULATION

	vector<int>dp(n,0);

	dp[0] = 0;

	for(int ind =1;ind<n;ind++){

		int left = dp[ind-1] + abs(vec[ind] - vec[ind-1]);

		int right = INT_MAX;

		if(ind > 1){
			right = dp[ind-2] + abs(vec[ind] - vec[ind-2]);
		}

		dp[ind] = min(left,right);
	}

	cout<<dp[n-1]<<endl;
}


return 0;
}
//...............................................................................................................
//DP 4. Frog Jump with K Distance
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MOD = 1000000007;

int find(int ind,vector<int>vec,int k,vector<int>&dp){
	if(ind == 0){
		return 0;
	}
	if(dp[ind] != -1){
		return dp[ind];
	}
	int ms = INT_MAX;
	for(int j = 1;j <= k;j++){
		if(ind - j >= 0){

			int s = abs(vec[ind] - vec[ind-j]) + find(ind - j,vec,k,dp);

			ms  = min(ms,s);
		}
	}

	return dp[ind] = ms;


}


int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif


int n,k;
cin>>n>>k;
vector<int>vec;

for(int i=0;i<n;i++){
	int x;
	cin>>x;
	vec.push_back(x);
}
//MEMOIZATION

// vector<int>dp(n,-1);
// cout<<find(n-1,vec,k,dp);


//TABULATION

vector<int>dp(n,0);

dp[0] =0;

for(int ind=1;ind<n;ind++){
	int ms = INT_MAX;

	for(int j =1;j<=k;j++){
		if(ind - j >= 0){
			int s = dp[ind - j] + abs(vec[ind] - vec[ind -j ]);
			ms = min(ms,s); 
		}
	}
	dp[ind] = ms;
}

cout<<dp[n-1];



return 0;
}
//...............................................................................................................

//DP.7 NINJA TRANING


#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MOD = 1000000007;
int find(int ind,int last,vector<vector<int>>vec,vector<vector<int>>&dp){
	if(ind == 0){
		int maxi = INT_MIN;
		for(int i=0;i<3;i++){
			if(i != last){
				maxi = max(maxi,vec[0][i]);
			}
		}

		return maxi;
	}

	if(dp[ind][last] != -1){
		return dp[ind][last];
	}

	int maxi =INT_MIN;

	for(int i=0;i<3;i++){
		if(i != last){
			int points = vec[ind][i] + find(ind-1,i,vec,dp);
			maxi = max(points,maxi);
		}
	}

	return dp[ind][last] = maxi;
}



int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif


int t;
cin>>t;
while(t--){
	int n;
	cin>>n;
	vector<vector<int>>vec;

	for(int i=0;i<n;i++){
		int x,y,z;
		cin>>x>>y>>z;

		vec.push_back({x,y,z});
	}
	//MEMOIZATION
	// vector<vector<int>>dp(n,vector<int>(3,-1));
	// cout<<max(find(n-1,0,vec,dp),max(find(n-1,1,vec,dp),find(n-1,2,vec,dp)))<<endl;

	//TABULATION
	// vector<vector<int>>dp(n,vector<int>(4,0));

	vector<int>prev(4,0);

	prev[0] = max(vec[0][1],vec[0][2]);
	prev[1] = max(vec[0][0],vec[0][2]);
	prev[2] = max(vec[0][1],vec[0][2]);
	prev[3] = max(vec[0][0],max(vec[0][1],vec[0][2]));

	for(int ind =1;ind<n;ind++){
		vector<int>temp(4,0);
		for(int last = 0;last < 4;last++){
			temp[last] = 0;

			for(int i = 0;i<3;i++){
				if(i != last){
					int points = vec[ind][i] + prev[i];

					temp[last] = max(temp[last], points);

				}
			}
		}
		prev = temp;
	}

	cout<<prev[3]<<endl;
}

return 0;
}
//...................................................................................................................
//DP.8 UNIQUE PATHS 2
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MOD = 1000000007;

int find(int i,int j,vector<vector<int>>vec,vector<vector<int>>&dp){
	if(i == 0 && j == 0){
		return 1;
	}

	if(i<0 || j<0){
		return 0;
	}

	if(vec[i][j] == -1){
		return 0;
	}
	if(dp[i][j] != -1){
		return dp[i][j];
	}

	int up = find(i-1,j,vec,dp);

	int left =find(i,j-1,vec,dp);


	return dp[i][j] =  up + left;
}




int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif




int t;
cin>>t;
while(t--){
	int m,n;
	cin>>m>>n;

	vector<vector<int>>vec;

	for(int i=0;i<m;i++){
		vector<int>temp;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			temp.push_back(x);
		}
		vec.push_back(temp);
	}
	//MEMOIZATION
	// vector<vector<int>>dp(m,vector<int>(n,-1));
	// cout<<find(m-1,n-1,vec,dp)<<endl;

	//TABULATION
	int dp[m][n];

	for(int i=0;i<m;i++){
		for(int j =0;j<n;j++){
			if(vec[i][j] == -1) dp[i][j] = 0;

			if(i == 0 && j == 0) dp[i][j] = 1;
			else{
				int up  = 0;

				int left = 0;

				if(i>0) up = dp[i-1][j];
				if(j>0) left = dp[i][j-1];

				dp[i][j] = (left + up)%MOD;
			}

		}
	}

	cout<<dp[m-1][n-1]<<endl;


}



return 0;
}
//...................................................................................................................
//DP 10 MINIMUM PATH SUM IN GRID

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int  MOD = 1e9+7;
int find(int i,int j,vector<vector<int>>vec,vector<vector<int>>&dp){
	if(i == 0 && j == 0 ){
		return vec[i][j];
	}
	if(i < 0 || j < 0){
		return 1e9;
	}
	if(dp[i][j] != -1){
		return dp[i][j];
	}

	int left  = vec[i][j] + find(i-1,j,vec,dp);

	int up  = vec[i][j] + find(i,j-1,vec,dp);

	return  dp[i][j] = min(left,up);

}





int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

vector<vector<int>>vec = {{1,3,1},{1,5,1},{4,2,1}};
int n = vec.size();
int m = vec[0].size();

//MEMOIZATION

// vector<vector<int>>dp(n,vector<int>(m,-1));
// cout<<find(n-1,m-1,vec,dp);

//TABULATION

vector<vector<int>>dp(n,vector<int>(m,0));

for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		if(i == 0 && j == 0){
			dp[i][j] = vec[i][j];
		}else{
			int up = vec[i][j];

			if(i > 0){
				up += dp[i-1][j];
			}else{
				up += 1e9;
			}
			int left= vec[i][j];

			if(j > 0){
				left += dp[i][j-1];
			}else{
				left += 1e9;
			}
			dp[i][j]  = min(up,left);
		}
	}
}
cout<<dp[n-1][m-1];




return 0;
}
//...................................................................................................................
// DP 11. TRIANGLE
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int  MOD = 1e9+7;

int find(int i,int j,int n,vector<vector<int>>vec,vector<vector<int>>&dp){
	if(i == n-1){
		return vec[i][j];
	}
	if(dp[i][j] != -1){
		return dp[i][j];
	}

	int d = vec[i][j] + find(i+1,j,n,vec,dp);
	int dr = vec[i][j] + find(i+1,j+1,n,vec,dp);

	return dp[i][j] = min(d,dr);
}






int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

vector<vector<int>>vec = {{2},{3,4},{6,5,7},{4,1,8,3}};

int n = vec.size();

//MEMOIZATION
// vector<vector<int>>dp(n,vector<int>(n,-1));
// cout<<find(0,0,n,vec,dp);

//TABULATION
vector<vector<int>>dp(n,vector<int>(n,0));

for(int j=0;j<n;j++){
	dp[n-1][j] = vec[n-1][j];
}

for(int i = n-2;i>=0;i--){
	for(int j=i;j>=0;j--){
		int d = vec[i][j] + dp[i+1][j];

		int dr = vec[i][j] + dp[i+1][j+1];

		dp[i][j] = min(d,dr);
	}
}

cout<<dp[0][0];




return 0;
}

//...................................................................................................................
//DP 12


//...................................................................................................................
 3D DP (hard) CHERRY PICKUP (L -13)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MOD = 1000000007;

int find(int i,int j1,int j2, int row,int col ,vector<vector<int>> &vec,vector<vector<vector<int>>> &dp){
	//base for out of boundary

	if(j1 < 0 || j2 < 0 || j1 >= col || j2 >= col){
		return -1e8;
	}

	if(i == row -1){
		if(j1 == j2) return vec[i][j1];
		else return vec[i][j1] + vec[i][j2];
	}

	if(dp[i][j1][j2] != -1){
		return  dp[i][j1][j2];
	}
	int maxi = -1e8;
	for(int x=-1; x<= +1;x++){
		for(int y = -1;y<=+1;y++){
			int val = 0;
			if(j1 == j2){
				val += vec[i][j1];
			}else{
				val+= vec[i][j1] + vec[i][j2];
			}
			val += find(i+1,j1+x,j2+y,row,col,vec,dp);
			maxi = max(maxi,val);
		}
	}

	return dp[i][j1][j2] = maxi;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);	 
#endif
// CHERRY PICKUP

vector<vector<int>>vec ={{3,1,1},{2,5,1},{1,5,5},{2,1,1}};

int r = vec.size(); // for 

int c = vec[0].size();

vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));

cout<<find(0,0,c-1,r,c,vec,dp);



	return 0;
}

// .................................................................................................................
	L-14 SUBSET SUM EQUALS TO TARGET  //DP ON SUBSETS

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>dp(1e3+1,vector<int>(1e3+1,-1));
bool find_ans(int ind,vector<int>&vec,int target){
	if(target == 0){
		return true;
	}
	if(ind == 0){
		if(target == vec[0]){
			return true;
		}else{

			return false;
		}
	}
	if(dp[ind][target] != -1){
		return dp[ind][target];
	}


	bool not_take = find_ans(ind-1,vec,target); 

	bool take = false;

	if(target >= vec[ind]){
		take = find_ans(ind-1,vec,target - vec[ind]);
	}

	return	dp[ind][target] = (take || not_take);
}

bool find(vector<int>vec,int tar){

	vector<int>dp(vec.size(),-1);
	if(find_ans(vec.size()-1,vec,tar) == true){
		return true;
	}

	return false;


}


int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

int t;
cin>>t;
while(t--){
	int n,tar;
	cin>>n>>tar;
	vector<int>vec;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		vec.push_back(x);
	}
	if(find(vec,tar) == true){
		cout<<"TRUE"<<endl;
	}else{
		cout<<"FALSE"<<endl;
	}
}



	return 0;
}
								//CODE STUDIO SOLUION USING MEMOIZATION//.....................................




bool find(int ind,vector<int>&vec,int target,vector<vector<int>> &dp){
    if(target == 0){
        return true;
    }
    if(ind == 0){
        if(vec[0] == target){
            return true;
        }else{
            return false;
        }
      }
    if(dp[ind][target]!= -1){
        return dp[ind][target];
    }
    bool not_take = find(ind-1,vec,target,dp);
    bool  take = false;
    if(target >= vec[ind]){
        take = find(ind-1,vec,target - vec[ind],dp);
    }
    
    return dp[ind][target] = (take | not_take);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));    
    return  find(n-1,arr,k,dp);
}

						//TABULATION METHOD..................

bool subsetSumToK(int n, int k, vector<int> &vec) {
   vector<vector<bool>>dp(n+1,vector<bool>(k+1,0));
    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }
    
    dp[0][vec[0]] = true;
    
    for(int ind = 1;ind<=n;ind++){
        for(int tar =1;tar<=k;tar++){
            bool not_take = dp[ind-1][tar];
            bool take = false;
            if(tar >= vec[ind]){
                take = dp[ind-1][tar - vec[ind]];
            }
            dp[ind][tar] = (take | not_take);
        }
    }
    return dp[n-1][k];
    
    
}
//........................................................................................................
//Partition Equal Subset Sum
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MOD = 1000000007;

bool find(int ind,vector<int>vec,int tar,vector<vector<bool>>&dp){
	if(tar == 0){
		return true;
	}
	if(ind == 0){
		if(tar == vec[0]){
			return true;
		}else{
			return false;
		}
	}
	if(dp[ind][tar] != -1){
		return dp[ind][tar];
	}


	bool nt = find(ind-1,vec,tar,dp);

	bool t = false;

	if(tar >= vec[ind]){
		t = find(ind-1,vec,tar - vec[ind],dp);
	}

	return dp[ind][tar] = (t || nt);
}

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

int t;
cin>>t;
while(t--){
	int n;
	cin>>n;
	vector<int>vec;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		vec.push_back(x);
	}

	int sum = 0;

	for(auto it:vec){
		sum+=it;
	}

	int tar = sum/2;


	if(sum%2 == 0){

	vector<vector<bool>>dp(n+1,vector<bool>(tar+1,-1));

	cout<<find(n-1,vec,tar,dp)<<endl;
	}else{
		cout<<false<<endl;
	}

	

}

	


return 0;
}




//........................................................................................................
					// 2035. Partition Array Into Two Arrays to Minimize Sum Difference//


#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MOD = 1000000007;



int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif


vector<int>vec = {2,-1,0,4,-2,-9};

int n = vec.size();

int totSum = 0;

for(auto it:vec){
	totSum += it;
}
int k  = totSum;

vector<vector<bool>>dp(vec.size(),vector<bool>(k+1,false));

for(int i=0;i<n;i++){
	dp[i][0] = true;
}

if(vec[0] <= k){
	dp[0][k] = true;
}

for(int ind = 1;ind < n;ind++){
	for(int tar = 1;tar<=k;tar++){
		bool not_take = dp[ind-1][tar];
		bool take = false;
		if(vec[ind] <= k){
			take = dp[ind-1][tar - vec[ind]];
		}
		dp[ind][tar] = take || not_take;
	}
}


int mini = 1e9;

for(int i=0;i<=totSum;i++){
	if(dp[n-1][i] == true){
		int diff = abs(i - (totSum - i));
		mini = min(mini,diff);
	}
}

cout<<mini<<endl;


return 0;
}

//........................................................................................................
					//COUNT SUBSET WITH SUM K


#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MOD = 1000000007;

int find_ans(int ind ,vector<int>vec,int tar,vector<vector<int>>&dp){
	if(tar == 0){
		return 1;
	}
	if(ind == 0){
		if(vec[0] == tar){
			return 1;
		}else{
			return 0;
		}
	}

	if(dp[ind][tar] != -1){
		return dp[ind][tar];
	}


	int not_pick = find_ans(ind-1,vec,tar,dp);

	int pick = 0;

	if(vec[ind] <= tar){
		pick = find_ans(ind-1,vec,tar - vec[ind],dp);
	} 

	return dp[ind][tar] =  pick + not_pick;

}



void find(vector<int>&vec,int target){

vector<vector<int>>dp(vec.size(),vector<int>(target+1,-1));

cout<<find_ans(vec.size()-1,vec,target,dp)<<endl;

}



int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

int t;
cin>>t;
while(t--){
	int n,k;
	cin>>n>>k;
	vector<int>vec;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		vec.push_back(x);
	}

		// find(vec,k); //FOR MEMOIZATION//



	//FOR  TABULATION//

		vector<vector<int>>dp(n,vector<int>(k+1,0));

		for(int i=0;i<n;i++){
			dp[i][0] = 1;
		}
		if(vec[0] <= k){
			dp[0][vec[0]] = 1;
		}

		for(int ind = 1 ;ind<n;ind++){
			for(int tar =0;tar<= k;tar++){
				int not_pick = dp[ind-1][tar];
				int pick = 0;
				if(vec[ind] <= tar){
					pick = dp[ind-1][tar - vec[ind]];
				}

				dp[ind][tar] = pick + not_pick;
			}
		}

		cout<<dp[n-1][k]<<endl;

}


	

return 0;
}

// .................................................................................................................
//DP -18

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MOD = 1000000007;

int find(int ind,vector<int>vec,int tar,vector<vector<int>>&dp){
	if(tar == 0){
		return 1;
	}

	if(ind == 0){
		if(tar == vec[ind]){
			return 1;
		}else{
			return 0;
		}
	}

	if(dp[ind][tar] != -1){
		return dp[ind][tar];
	}

	int not_take = find(ind-1,vec,tar,dp);


	int take = 0;

	if(tar >= vec[ind]){
		take = find(ind-1,vec,tar-vec[ind],dp);
	}

	return  dp[ind][tar]  = (take + not_take)%MOD;
}





int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
//DP 18

int t;
cin>>t;

while(t--){
	int n,d;
	cin>>n>>d;

	vector<int>vec;

	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		vec.push_back(x);
	}

	int totalSum = 0;
	for(auto it:vec){
		totalSum += it;
	}

	if((totalSum - d) < 0 || (totalSum - d) % 2){
		cout<<"Not_Possible"<<endl;
	}else{

		vector<vector<int>>dp(n+1,vector<int>(((totalSum-d)/2)+1,-1));

		cout<<find(n-1,vec,(totalSum-d)/2,dp)<<endl;
	}

	
}

	
return 0;
}




// .................................................................................................................
										// 0/1 KNAPSACK PROBLEM



#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first

int find(int ind,int W,vector<int>&wt,vector<int>&val,vector<vector<int>>&dp){
	if(ind == 0){
		if(wt[0] <= W){
			return val[0];
		}
		return 0;
	}

	if(dp[ind][W] != -1){
		return dp[ind][W];
	}

	int not_take = 0 + find(ind-1,W,wt,val,dp);
	int take = INT_MIN;
	if(wt[ind] <= W){
		take = val[ind] + find(ind-1,W-wt[ind],wt,val,dp);
	} 

	return dp[ind][W] = max(take,not_take);
}



int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
//0/1 KNAPSACK


vector<int>w={4,5,1};
vector<int>val = {1,2,3};

int n = 3;
int W = 4;


//MEMOIZATION
// {
// vector<vector<int>>dp(n,vector<int>(W+1,-1));
// cout<<find(n-1,cap,w,val,dp);
// }

//TABULATION

vector<vector<int>>dp(n,vector<int>(W,0));

for(int i = w[0];i<=W;i++){
	dp[0][i] = val[0];
}

for(int ind =1 ;ind<n;ind++){
	for(int wt =0;wt<= W;wt++){
		int not_take = 0+dp[ind-1][wt];
		int take = INT_MIN;
		if(w[ind] <= wt){
			take = val[ind] + [ind-1][wt-wt[ind]];
		}
		dp[ind][wt] = max(take,not_take);
	}

}

cout<<dp[n-1][W];



	return 0;
}

// .................................................................................................................
					//TARGET SUM (leetcode)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first

int find(int ind,int tar,vector<int>&vec,vector<vector<int>>&dp){
vector<vector<int>>dp(n+1,vector<int>(cap+1,-1));

	cout<<find(n-1,Wi,Vi,cap,dp)<<endl; 
	if(ind == 0){
		if(tar == 0 || tar == vec[0]){
			return 1;
		}
		if(tar == 0 && vec[0] == 0){
			return 2;
		}
		return 0;
	}

	if(dp[ind][tar] != -1){
		return dp[ind][tar];
	}
	

	int not_pick = find(ind-1,tar,vec,dp);
	int pick = 0;
	if(vec[ind] <= tar){
		pick =  find(ind-1,tar- vec[ind],vec,dp);
	}

	return dp[ind][tar] = pick + not_pick;

}




int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

vector<int>vec = {1,0};
int n = vec.size();
int target  = 1;

int totalSum = 0;

for(auto it:vec){
	totalSum += it;
}

if((totalSum - target < 0)|| (totalSum - target) % 2){
	cout<<0<<endl;
}else{
int tar = (totalSum - target)/2;
vector<vector<int>>dp(n,vector<int>(target+1,-1));

cout<<find(n-1,tar,vec,dp)<<endl;
}


	return 0;
}

// .................................................................................................................
					//COIN CHANGE 2 (leetcode)


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first

int find(int ind,int tar,vector<int>vec,vector<vector<int>>&dp){
	if(ind == 0){
		if(tar % vec[0] == 0){
			return 1;
		}
		return 0;
	}
	if(dp[ind][tar] != -1){
		return dp[ind][tar];
	}

	int not_pick = find(ind-1,tar,vec,dp);

	int pick = 0;
	if(vec[ind] <= tar){
		pick = find(ind,tar-vec[ind],vec,dp);
	}
	return dp[ind][tar] = pick + not_pick;

}





int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

vector<int>vec ={1,2,5};
int target = 5;
int n = vec.size(); 

//MEMOIZATION
// vector<vector<int>>dp(n,vector<int>(target+1,-1));
// cout<<find(n-1,target,vec,dp);

//TABULATION

vector<vector<int>>dp(n,vector<int>(target,0));

for(int T=0;T<=target;T++){
	dp[0][T] = (T % vec[0] == 0);
}

for(int ind = 1;ind<n;ind++){
	for(int T =0;T<= target ;T++){
		int not_take = dp[ind-1][T];
		int take = 0;
		if(vec[ind] <= T){
			take = dp[ind][T - vec[ind]];
		}
		dp[ind][T] = not_take+take;
	}
}

cout<<dp[n-1][target];




	return 0;
}

//.................................................................................................................
					//UNBOUNDED 0/1 KNAPSACK 

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int  MOD = 1e9+7;

int find(int ind,int w,vector<int>&profit,vector<int>&weight,vector<vector<int>>&dp){

	if(ind == 0){
		return (w/weight[0]) *profit[0];
	}
	if(dp[ind][w] != -1){
		return dp[ind][w];
	} 
	int not_take = 0 + find(ind-1,w,profit,weight,dp);

	int take  = 0;
	if(weight[ind] <= w){
		take = profit[ind] + find(ind,w-weight[ind],profit,weight,dp);
	}

	return dp[ind][w] = max(take,not_take);

}


int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

int t;
cin>>t;
while(t--){
	int n,w;
	cin>>n>>w;
	vector<int>profit,weight;

	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		profit.push_back(x);
	}

	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		weight.push_back(x);
	}
		//MEMOIZATION//
	// vector<vector<int>>dp(n,vector<int>(w+1,-1));
	// cout<<find(n-1,w,profit,weight,dp)<<endl;


	//TABULATION


	vector<vector<int>>dp(n,vector<int>(w+1,0));
	for(int W=0;W<=w;W++){
		dp[0][W] = ((int)W/weight[0]) *profit[0];
	}

	for(int ind =1;ind<n;ind++){
		for(int W =0;W<=w;w++){
			int not_take = 0 + dp[ind-1][W];
			int take = 0;
			if(weight[ind] <= W){
				take = profit[ind]  + dp[ind][W-weight[ind]];
 			}
 			dp[ind][W] = max(take,not_take);

		}
	}

	cout<<dp[n-1][w]<<endl;


}




	return 0;
}

//.................................................................................................................
					//ROD CUTTING PROBLEM

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int  MOD = 1e9+7;
int find(int ind,int N,vector<int>&profit,vector<vector<int>>&dp){
	if(ind == 0){
		return N * profit[0];
	}
	if(dp[ind][N] != -1){
		return dp[ind][N];
	}
	int not_pick = 0 + find(ind-1,N,profit,dp);
	int pick =INT_MIN;
	int idx = ind + 1;
	if(idx <= N){
		pick = profit[ind] + find(ind,N - idx,profit,dp);
	}

	return dp[ind][N] =  max(pick,not_pick);
}



int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif


int t;
cin>>t;
while(t--){
	int n;
	cin>>n;
	vector<int>profit;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		profit.push_back(x);
	}
	// MEMOIZATION
	// vector<vector<int>>dp(n,vector<int>(n+1,-1));
	// cout<<find(n-1,n,profit,dp)<<endl;
	
	// TABULATION

	vector<vector<int>>dp(n,vector<int>(n+1,0));

	for(int N=0;N<=n;N++){
		dp[0][N] = N *profit[0];
	}

	for(int ind =1;ind <n;ind++){
		for(int N =0;N<=n;N++){
		int not_pick = 0 + dp[ind-1][N];
		int pick =INT_MIN;
		int idx = ind + 1;
		if(idx <= N){
			pick = profit[ind] + dp[ind][N - idx];
		}

		dp[ind][N] =  max(pick,not_pick);

		}
	}

	cout<<dp[n-1][n]<<endl;

}



	return 0;
}

//.................................................................................................................
//.................................................................................................................
											DP ON SUBSEQUENCES
//.................................................................................................................
//.................................................................................................................
//.................................................................................................................
											//LONGEST COMMON SUBSEQUENCES.......

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int  MOD = 1e9+7;

int find(int ind1,int ind2,string s1,string s2,vector<vector<int>>&dp){
	if(ind1 <0 || ind2 < 0){	
		return 0;
	}
	if(dp[ind1][ind2] != -1){
		return dp[ind1][ind2];
	}

	if(s1[ind1] == s2[ind2]){
		return 1 + find(ind1-1,ind2-1,s1,s2,dp);
	}
	return dp[ind1][ind2] = max(find(ind1-1,ind2,s1,s2,dp),find(ind1,ind2-1,s1,s2,dp));
}



int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif


string text1 = "fcvafurqjylclorwfoladwfqzkbebslwnmpmlkbezkxoncvwhstwzwpqxqtyxozkpgtgtsjobujezgrkvevklmludgtyrmjaxyputqbyxqvupojutsjwlwluzsbmvyxifqtglwvcnkfsfglwjwrmtyxmdgjifyjwrsnenuvsdedsbqdovwzsdghclcdexmtsbexwrszihcpibwpidixmpmxshwzmjgtadmtkxqfkrsdqjcrmxkbkfoncrcvoxuvcdytajgfwrcxivixanuzerebuzklyhezevonqdsrkzetsrgfgxibqpmfuxcrinetyzkvudghgrytsvwzkjulmhanankxqfihenuhmfsfkfepibkjmzybmlkzozmluvybyzsleludsxkpinizoraxonmhwtkfkhudizepyzijafqlepcbihofepmjqtgrsxorunshgpazovuhktatmlcfklafivivefyfubunszyvarcrkpsnglkduzaxqrerkvcnmrurkhkpargvcxefovwtapedaluhclmzynebczodwropwdenqxmrutuhehadyfspcpuxyzodifqdqzgbwhodcjonypyjwbwxepcpujerkrelunstebopkncdazexsbezmhynizsvarafwfmnclerafejgnizcbsrcvcnwrolofyzulcxaxqjqzunedidulspslebifinqrchyvapkzmzwbwjgbyrqhqpolwjijmzyduzerqnadapudmrazmzadstozytonuzarizszubkzkhenaxivytmjqjgvgzwpgxefatetoncjgjsdilmvgtgpgbibexwnexstipkjylalqnupexytkradwxmlmhsnmzuxcdkfkxyfgrmfqtajatgjctenqhkvyrgvapctqtyrufcdobibizihuhsrsterozotytubefutaxcjarknynetipehoduxyjstufwvkvwvwnuletybmrczgtmxctuny"; 
string text2 = "nohgdazargvalupetizezqpklktojqtqdivcpsfgjopaxwbkvujilqbclehulatshehmjqhyfkpcfwxovajkvankjkvevgdovazmbgtqfwvejczsnmbchkdibstklkxarwjqbqxwvixavkhylqvghqpifijohudenozotejoxavkfkzcdqnoxydynavwdylwhatslyrwlejwdwrmpevmtwpahatwlaxmjmdgrebmfyngdcbmbgjcvqpcbadujkxaxujudmbejcrevuvcdobolcbstifedcvmngnqhudixgzktcdqngxmruhcxqxypwhahobudelivgvynefkjqdyvalmvudcdivmhghqrelurodwdsvuzmjixgdexonwjczghalsjopixsrwjixuzmjgxydqnipelgrivkzkxgjchibgnqbknstspujwdydszohqjsfuzstyjgnwhsrebmlwzkzijgnmnczmrehspihspyfedabotwvwxwpspypctizyhcxypqzctwlspszonsrmnyvmhsvqtkbyhmhwjmvazaviruzqxmbczaxmtqjexmdudypovkjklynktahupanujylylgrajozobsbwpwtohkfsxeverqxylwdwtojoxydepybavwhgdehafurqtcxqhuhkdwxkdojipolctcvcrsvczcxedglgrejerqdgrsvsxgjodajatsnixutihwpivihadqdotsvyrkxehodybapwlsjexixgponcxifijchejoxgxebmbclczqvkfuzgxsbshqvgfcraxytaxeviryhexmvqjybizivyjanwxmpojgxgbyhcruvqpafwjslkbohqlknkdqjixsfsdurgbsvclmrcrcnulinqvcdqhcvwdaxgvafwravunurqvizqtozuxinytafopmhchmxsxgfanetmdcjalmrolejidylkjktunqhkxchyjmpkvsfgnybsjedmzkrkhwryzan" ;
int ind1 = text1.size();
int ind2 = text2.size();
vector<vector<int>>dp(ind1,vector<int>(ind2,-1));
cout<<find(ind1-1,ind2-1,text1,text2,dp);




	return 0;
}

//TABLUATION....


#include <bits/stdc++.h>
using namespace std;
const int  M = 1e9+7;


int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif


string  s1 = "abc", s2 = "abc";

int n = s1.size(),m = s2.size();

vector<vector<int>>dp(n+1,vector<int>(m+1,-1));


for(int i=0;i<=n;i++){
	dp[i][0] = 0;
} 

for(int j=0;j<=m;j++){
	dp[0][j] = 0;
}

for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){

		if(s1[i-1] == s2[j-1]){
			dp[i][j] = 1 + dp[i-1][j-1];
		}else{
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
}

cout<<dp[n][m];

//IF PRINTING THE STRING 

{
	int len = dp[n][m];

string ans = "";

for(int i=0;i<len;i++){
	ans +='@';
}
int ind = len-1;


int i = n,j=m;

while(i > 0 && j > 0){

	if(s1[i-1] == s2[j-1]){
		ans[ind] = s1[i-1];
		ind--;
		i--;
		j--;
	}else if(dp[i-1][j] > dp[i][j-1]){
		i--;
	}else{
		j--;
	}
}

cout<<ans;
}





	return 0;
}



//..........................................................................................................................

							              //LONGEST COMMON SUBSTRING.....
#include <bits/stdc++.h>
using namespace std;
const int  M = 1e9+7;


int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif


int t;
cin>>t;
while(t--){
	string s1,s2;
	cin>>s1>>s2;	

	int n = s1.size();
	int m = s2.size();

	vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

	for(int i=0;i<=n;i++){
		dp[i][0] = 0;
	}

	for(int j=0;j<=m;j++){
		dp[0][j] = 0;
	}

	int ans = INT_MIN;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
				ans = max(ans,dp[i][j]);
			}else{
				dp[i][j] = 0;
			}
		}
	}

	cout<<ans<<endl;

}



	return 0;
}

//.........................................................................................................................

					//1312. Minimum Insertion Steps to Make a String Palindrome

#include <bits/stdc++.h>
using namespace std;
const int  M = 1e9+7;

int find(int i,int j,string s1,string s2,vector<vector<int>>dp){
	if(i<0 || j<0){
		return 0;
	}

	if(dp[i][j] != -1){
		return  dp[i][j];
	}

	if(s1[i] == s2[j]){
		return  1 + find(i-1,j-1,s1,s2,dp);
	}

	return dp[i][j] = max(find(i-1,j,s1,s2,dp),find(i,j-1,s1,s2,dp));
}



int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

string s1 = "zzazz";
string s2 = s1;

reverse(s2.begin(),s2.end());


int n = s1.size();
int m = s2.size();


vector<vector<int>>dp(n,vector<int>(m,-1));
int LPS = find(n-1,m-1,s1,s2,dp);


cout<<n - LPS<<endl;


	return 0;
}

//MEMOIZATION

#include <bits/stdc++.h>
using namespace std;
const int  M = 1e9+7;





int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

string s1 = "mbadm";
string s2 = s1;

reverse(s2.begin(),s2.end());


int n = s1.size();
int m = s2.size();


vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

for(int i=0;i<=n;i++){
	dp[i][0] = 0;
}

for(int j=0;j<=m;j++){
	dp[0][j] = 0;
}

for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		if(s1[i-1] == s2[j-1]){
			dp[i][j] = 1 + dp[i-1][j-1];
		}else{
			dp[i][j]  = max(dp[i-1][j] , dp[i][j-1]);
		}
	}
}

int LPS = dp[n][m];

cout<<n-LPS;


	return 0;
}




//..........................................................................................................................
										//Minimum Number of Deletions and Insertions


class Solution {
 
    
    
public:
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
            
        }
        
        for(int j=0;j<=m;j++){
            dp[0][j] = 0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        int LCS  = dp[n][m];
        
        
        return n+m-2 * LCS;
    
       
    }
};


//..........................................................................................................................

										//PRINTING SORTEST COMMON SUPERSEQUENCE....



#include <bits/stdc++.h>
using namespace std;
const int  M = 1e9+7;

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

string s1 = "bbbaaaba", s2 ="bbababbb";

int n = s1.size();
int m = s2.size();

vector<vector<int>>dp(n+1,vector<int>(m+1,0));

for(int i=0;i<=n;i++){
	dp[i][0] = 0;
}

for(int j=0;j<=m;j++){
	dp[0][j] = 0;
}


for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		if(s1[i-1] == s2[j-1]){
			dp[i][j] = 1 + dp[i-1][j-1];
		}else{
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
}

string ans = "";

int i=n,j=m;

while(i>0 && j>0){

	if(s1[i-1] == s2[j-1]){
		ans += s1[i-1];
		i--;j--;
	}else if(dp[i-1][j] > dp[i][j-1]){
		ans += s1[i-1];
		i--;
	}else{
		ans+=s2[j-1];
		j--;
	}
}

while(i>0){
	ans+=s1[i-1];
	i--;
}

while(j>0){
	ans+=s2[j-1];
	j--;
}

reverse(ans.begin(),ans.end());

cout<<ans;
 

	return 0;
}

//..........................................................................................................................
									//DISTINCT SUBSEQUENCES

#include <bits/stdc++.h>
using namespace std;
const int  M = 1e9+7;

int find(int i,int j,string s1,string s2,vector<vector<int>>dp){
	if(j<0){
		return 1;
	}

	if(i<0){
		return 0;
	}

	if(dp[i][j] != -1){
		return dp[i][j];
	}



	if(s1[i] == s2[j]){
		return find(i-1,j-1,s1,s2,dp) + find(i-1,j,s1,s2,dp);
	}
	
	return dp[i][j] =  find(i-1,j,s1,s2,dp);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

string s1 = "rabbbit", s2 = "rabbit";

int n  =s1.size();
int m  =s2.size();
// vector<vector<int>>dp(n,vector<int>(m,-1));
// cout<<find(n-1,m-1,s1,s2,dp); 


//TABULATION.......

vector<vector<double>>dp(n+1,vector<double>(m+1,0));


for(int i=0;i<=n;i++){
	dp[i][0] = 1;
}

for(int j=1;j<=m;j++){
	dp[0][j] = 0;
}


for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		if(s1[i-1] == s2[j-1]){
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
		}else{
			dp[i][j] = dp[i-1][j];
		}
	}
}


cout<<(int)dp[n][m];




	return 0;
}

//..........................................................................................................................
							//EDIT DISTANCE....


#include <bits/stdc++.h>
using namespace std;
const int  M = 1e9+7;

int find(int i,int j,string s1,string s2,vector<vector<int>>dp){
	if(i == 0){
		return j;
	}
	if(j == 0){
		return i;
	}
	if(dp[i][j] != -1){
		return dp[i][j];
	}

	if(s1[i-1] == s2[j-1]){
		return 0 + find(i-1,j-1,s1,s2,dp);
	}

	return dp[i][j] = min( 1 + find(i,j-1,s1,s2,dp),min( (1 + find(i-1,j,s1,s2,dp)),(1 + find(i-1,j-1,s1,s2,dp))));
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif


string  s1 = "horse", s2 = "ros";

int n = s1.size();
int m = s2.size();

// vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
// cout<<find(n,m,s1,s2,dp);

//MEMOIZATION

vector<vector<int>>dp(n+1,vector<int>(m+1,0));


for(int i=0;i<=n;i++){
	dp[i][0] = i;
}

for(int j=0;j<=m;j++){
	dp[0][j] = j;
}


for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		if(s1[i-1] == s2[j-1]){
			dp[i][j] = dp[i-1][j-1];
		}else{
			dp[i][j] = 1 + min(dp[i][j-1],min( dp[i-1][j] ,dp[i-1][j-1]));
		}
	}
}

cout<<dp[n][m];



	return 0;
}

//..........................................................................................................................

//BUY AND SELL STOCK II

#include <bits/stdc++.h>
using namespace std;
const int  M = 1e9+7;

int find(int ind,vector<int>&vec,int buy,vector<vector<int>>&dp){
	if(ind == vec.size()){
		return 0;
	}
	if(dp[ind][buy] != -1){
		return  dp[ind][buy];
	}

	int profits = 0;

	
	if(buy){
		profits = max(-vec[ind]  + find(ind+1,vec,0,dp) , 0 + find(ind+1,vec,1,dp));

	}else{
		profits = max(vec[ind]  + find(ind+1,vec,1,dp) , 0 + find(ind+1,vec,0,dp));
		
	}


	return dp[ind][buy]  = profits;

}

int find(int ind , vector<int>vec,int buy,int cap,vector<vector<vector<int>>> &dp){
	if(cap == 0) return 0;
	if(ind == vec.size()) return 0;

	int profit = 0;

	if(dp[ind][buy][cap] != -1){
		return dp[ind][buy][cap] ;
	}

	if(buy){
		profit = max(-vec[ind] + find(ind+1,vec,0,cap,dp), 0 + find(ind+1,vec,1,cap,dp));
	}else{
		profit = max(vec[ind] + find(ind+1,vec,1,cap-1,dp), 0 + find(ind+1,vec,0,cap,dp));
	}

	return dp[ind][buy][cap] = profit;

}



int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif


vector<int>vec = {7,6,4,3,1};

int n = vec.size();

// vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
// cout<<find(0,vec,1,2,dp);


vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));


for(int ind = n-1;ind>=0;ind--){
	for(int buy = 0;buy<2;buy++){
		for(int cap = 1;cap<=2;cap++){
			if(buy){
				dp[ind][buy][cap]  = max(-vec[ind] + dp[ind+1][0][cap], 0 + dp[ind+1][1][cap]);
			}else{
				dp[ind][buy][cap] = max(vec[ind] + dp[ind+1][1][cap-1], 0 + dp[ind+1][0][cap]);
			}

		}
	}
}

cout<<dp[0][1][2]; 




	return 0;
}

//..........................................................................................................................
//buy and  sell stock IV.......

#include <bits/stdc++.h>
using namespace std;
const int  M = 1e9+7;

int find(int ind,int trans,vector<int>vec,int k,vector<vector<int>>&dp){
	if(ind == vec.size() || trans  == 2*k ){
		return 0;
	}
	if(dp[ind][trans] != -1){
		return dp[ind][trans]; 
	}

	if(trans % 2 == 0){
		return dp[ind][trans] = max(-vec[ind] + find(ind+1,trans+1,vec,k,dp),0 + find(ind+1,trans,vec,k,dp));
	}


	return  dp[ind][trans] = max(vec[ind] + find(ind+1,trans+1,vec,k,dp), 0 + find(ind+1,trans,vec,k,dp));

}




int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);

	freopen("output.txt","w",stdout);
#endif


vector<int>vec = {3,2,6,5,0,3};

int k = 2;

int n = vec.size();

vector<vector<int>>dp(n,vector<int>(2*k,-1));

cout<<find(0,0,vec,k,dp);





	return 0;
}
//.................................................................................................................

//BUY AND SELL STOCK WITH FEES

#include <bits/stdc++.h>
using namespace std;
const int  M = 1e9+7;

int find(int ind, int buy,vector<int>&vec,int &fee,vector<vector<int>>&dp){
	if(ind >= vec.size()) return 0;

	if(dp[ind][buy] != -1) return  dp[ind][buy];
	int profit = 0;

	if(buy == 0){

	return dp[ind][buy] =  max(-vec[ind]+ find(ind+1,1,vec,fee,dp), 0  + find(ind+1,0,vec,fee,dp));
	}

	return  dp[ind][buy] = max( (vec[ind]-fee)   + find(ind+1,0,vec,fee,dp), 0 + find(ind+1,1,vec,fee,dp));
}



int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);

	freopen("output.txt","w",stdout);
#endif

vector<int>vec = {1,3,2,8,4,9};
int n = vec.size();
int fee = 2;
vector<vector<int>>dp(n,vector<int>(2,-1));
cout<<find(0,0,vec,fee,dp);




	return 0;
}


//.....................................................................................................
//MATRIX CHAIN MULTIPLICATION/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int  MOD = 1e9+7;
int find(int i,int j,vector<int>&vec){
	if(i == j) return 0;

	int mini = 1e9;

	for(int k=i;k<j;k++){
		int steps = vec[i-1] * vec[k] * vec[j] + find(i,j,vec) + find(k+1,j,vec);

		if(steps < mini){
			mini = steps;
		}

	}

	return mini;				
}




int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif




int t;
cin>>t;
while(t--){
	int n;
	cin>>n;
	vector<int>vec;

	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		vec.push_back(x);
	}

	// cout<<find(1,n-1,vec)<<endl;

	//USING TABULATION....

	int dp[n][n];

	for(int i=0;i<n;i++){
		dp[i][i]  =	0;
	}
	for(int i=n-1;i>=1;i--){
		for(int j = i+1;j<n;j++){
			int mini = 1e9;

			for(int k=0;k<j;k++){
				int steps = vec[i-1] * vec[k] * vec[j] + dp[i][k] + dp[k+1][j];

				if(steps < mini){
					mini = steps; 
				}
			}
			dp[i][j] = mini;
		}
	}

cout<<dp[1][n-1]<<endl;
}


	return 0;
}
// ...........................................................................................................................






















									








