#include <bits/stdc++.h>
using namespace std;
int power(int a,int b){
	if(b == 0) return 1;

	int X = power(a,b/2);

	if(b%2 == 0) return X * X;
	else return X * X * a;  
}
int power ( int a , int b ) {
int ans = 1 ;
while ( b > 0 ) {
if ( b % 2 == 1 ) {
		ans = ans * a ;
	}
	b = b >> 1 ;	
	a = a * a ;
  }
}
return ans ;



					/*TO PRINT ALL THE SUBSEQUENECS OF AN ARRAY*/
void SOLVE(int ind,vector<int> vec,vector<vector<int>>&ans,vector<int>temp){
	if(ind == vec.size()){
		ans.push_back(temp);
		return;
	}

	temp.push_back(vec[ind]);
	SOLVE(ind+1,vec,ans,temp);
	temp.pop_back();
	SOLVE(ind+1,vec,ans,temp);
}

void FIND_SUBSEQUENCE_SUM_EQLS_K(int ind,vector<int>vec,int& ans,int temp,int n,int k ){
	if(ind == vec.size()){
		if(temp == k){
			cout<<temp<<endl;
			ans++;
		}
		return;
	}
	temp+=vec[ind];
	FIND_SUBSEQUENCE_SUM_EQLS_K(ind+1,vec,ans,temp,n,k);
	temp-=vec[ind];
	FIND_SUBSEQUENCE_SUM_EQLS_K(ind+1,vec,ans,temp,n,k);

}
						//TECHNIQUE TO PRINT ONLY ONE ANSWER//
bool FIND_ANY_SUBSIQUENCE_eqls_k(int ind ,vector<int>vec,vector<int> temp,int k,int sum){
	if(ind == vec.size()){
		if(sum == k){
			for(auto it:temp){
				cout<<it<<" ";
				return  true;
			}
		}
		return false;
	}
	temp.push_back(vec[ind]);
	sum += vec[ind];
	if(FIND_ANY_SUBSIQUENCE_eqls_k(ind+1,vec,temp,k,sum) == true){
		return true;
	}
	temp.pop_back();
	sum-= vec[ind];
	if(FIND_ANY_SUBSIQUENCE_eqls_k(ind+1,vec,temp,k,sum) == true){
		return true;
	}
	return false;
}
					/*GENERATE ALL THE SUBARRAYS USING RECURSION*/
void GENERATE_ALL_SUBSETS(vector<int>vec,int start,int end,vector<vector<int>>&ans){
	if(end == vec.size()){
		return;
	}else if(start > end){
		GENERATE_ALL_SUBSETS(vec,start,end+1,ans);
	}
	vector<int>temp;
	for(int i=start;i<end;i++){
		temp.push_back(vec[i]);
		temp.push_back(vec[end]);
		ans.push_back(temp);
		GENERATE_ALL_SUBSETS(vec,start+1,end,ans);

	}
}
								/*COMBNATION SUM(pick any index n number of times)*/
void COMBINATION_SUM(int ind,vector<int>vec,vector<vector<int>>&ans,vector<int>temp,int target){
	if(ind == vec.size()){
		if(target == 0){
			ans.push_back(temp);
		}
		return;
		
	}
	if(vec[ind]<=target){
		temp.push_back(vec[ind]);
		COMBINATION_SUM(ind,vec,ans,temp,target-vec[ind]);
		temp.pop_back();
	}
	COMBINATION_SUM(ind+1,vec,ans,temp,target);

}	

						/*COMBINATION SUM 2 (sum of all unique elements in lexographical sorted order)*/
/*sort the input  array before*/						
void COMBINATION_SUM_2(int ind,vector<int>vec,vector<vector<int>>&ans,vector<int>temp,int target){

		if(target == 0){
			ans.push_back(temp);
			return;
		}
				
	for(int i=ind;i<vec.size();i++){
		if(i>ind && vec[i] == vec[i-1]) continue;
		if(vec[i]>target) break;
		temp.push_back(vec[i]);
		COMBINATION_SUM_2(i+1,vec,ans,temp,target- vec[i]);
		temp.pop_back();
	}
	return; 
		
}
										/*SUBSET SUM gfg(sort the ans array afterwords)*/
void SUBSET_SUM(int ind,vector<int>vec,vector<int>&ans,int sum){
	if(ind == vec.size()){
		ans.push_back(sum);
		return;
	}
	sum+=vec[ind];
	SUBSET_SUM(ind+1,vec,ans,sum);
	sum-=vec[ind];
	SUBSET_SUM(ind+1,vec,ans,sum);

}



int main(){ 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif














	return 0;
}