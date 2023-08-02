#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MOD = 1000000007;


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

	int ans = INT_MAX;
	int median = vec[1]*3;
	int mean = vec[0] + vec[1] + vec[2];
	int ans = abs(median - mean);
	sort(vec.begin(),vec.end());
	for(int i=0;i<n-1;i++){
		median = 3* vec[i];
		for(int j=0;j<i;j++){
			mean = vec[i] + vec[j];
			int temp =median - mean;
			it(temp <vec[i]){
				continue;

			}else if(temp == vec[i]){
				ans = min(ans,abs(median -mean - vec[i+1]));
				continue;
			}

			int pos  = lower_bount(all(vec),temp) - vec.begin();
			if(pos != n || pos<=i){
				ans=min(ans,abs(mean- median + vec[pos]));
				pos--;
			}
			if(pos > i){
				ans = min(ans,abs(mean -median + vec[pos]));
			}
		}
	}

	cout<<ans<<endl;
}















return 0;
}


