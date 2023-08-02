#include <bits/stdc++.h>
using namespace std;
							/*MAXIMUM SUBARRAY SUM EQUALS K (variable sliding window)*/
int solve(vector<int>vec,int k){
	int n = vec.size();
	int i=0;int j = 0;
	int max_sum = -1;
	int sum = 0;

	while(j<n){
		sum+=vec[j];
		if(sum == k){
			max_sum = max(max_sum,j-i+1);
		}else if(sum > k){
			sum-= vec[i];
			i++;
		}
		j++;
	}
	return max_sum;

}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

vector<int>vec = {5,6,7,8,9};	/*1 2 6 8 11 */
int n = vec.size();
int x = 4;
unordered_map<int,int>mp;

mp[0] = 0;
int sum =0;
for(int i=0;i<vec.size();i++){
	sum += vec[i];
	mp[sum] = i;
	vec[i] = sum;
}
sum = sum - x;

int ans;
int maxi = 0;
for(int i=0;i<n;i++){
	if(mp.count(vec[i]-sum)){
		if((vec[i] - sum) == 0){
			maxi = max(maxi,i - mp[vec[i] - sum] +1);
		}else{
			maxi = max(maxi,i - mp[vec[i] - sum]);

		}
	}
}
if(maxi){
	cout<<n-maxi<<endl;
}else{
	cout<<-1;
}




































return 0;
}