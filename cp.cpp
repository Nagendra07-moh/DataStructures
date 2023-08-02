#include <bits/stdc++.h>
using namespace std;
									/*SUBSET SUM 2 BRUTE FORCE(sum of all the unique subsets)//SUBSET II LEETCODE*/
void SUBSET_SUM_BRUTE(int ind,vector<int>vec,set<vector<int>>&ans,vector<int>temp){
	if(ind == vec.size()){
		ans.insert(temp);
		return;
	}

	temp.push_back(vec[ind]);
	SUBSET_SUM_BRUTE(ind+1,vec,ans,temp);
	temp.pop_back();
	SUBSET_SUM_BRUTE(ind+1,vec,ans,temp);
}
										/*SUBSET SUM 2 OPTIMAL(sum of all the unique subsets)// SUBSET II LEETCODE*/
void SUBSET_SUM_OPTIMAL(int ind,vector<int>vec,vector<vector<int>>&ans,vector<int>temp){
	if(ind == vec.size()){
		ans.push_back(temp);
	}
	for(int i =ind;i<vec.size();i++){
		if(i>ind && vec[i] == vec[i-1]) continue;
		temp.push_back(vec[i]);
		SUBSET_SUM_OPTIMAL(i+1,vec,ans,temp);
		temp.pop_back();
	}

}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

vector<int>vec = {1,2,2};
vector<vector<int>>ans;
vector<int>temp;
SUBSET_SUM_OPTIMAL(0,vec,ans,temp);

for(int i=0;i<ans.size();i++){
	for(auto it:ans[i]){
		cout<<it<<" ";
	}
	cout<<endl;
}























return 0;
}