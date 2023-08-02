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
	int n,k,x;
	cin>>n>>k>>x;
	if(((n%2 !=0) && x == 1)|| (x ==1 && k == 1) ){
		cout<<"NO"<<endl;
	}else{
		if(k >= n){
			cout<<"YES"<<endl;
			cout<<1<<endl;
			cout<<n<<endl;
		}else if(x != 1){
			int sum = 0;
			cout<<"YES"<<endl;
			cout<<n<<endl;
			while(sum != n){
				cout<<1<<" ";
				sum+=1;
			}
			cout<<endl;
		}else if((n%k == 0)){
			int rem = n/k;
			cout<<"YES"<<endl;
			cout<<rem<<endl;
			for(int i=0;i<rem;i++){
				cout<<k<<" ";
			}
			cout<<endl;
		}else{
			int times = n/k;
			vector<int>ans;
			int sum = 0;
			for(int i=0;i<times;i++){
				ans.push_back(k);
				sum+=k;
			}

			while(sum != n){
				ans.push_back(1);
			}
			cout<<"YES"<<endl;
			cout<<ans.size()<<endl;
			for(auto it:ans){
				cout<<it<<" ";
			}
			cout<<endl;

		}

	}
}



















return 0;
}


