								//NEXT GREATER ELEMENT(TO RIGHT) USING STACK
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int  MOD = 1e9+7;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

vector<int>arr = {1,3,0,0,1,2,4};

vector<int>ans;

stack<int>st;

int n = arr.size();

for(int i=n-1;i>=0;i--){
	if(st.empty()){

		ans.push_back(-1);
		
	}else if(st.size() > 0 && st.top() > arr[i]){
		
		ans.push_back(st.top());

	}else if(st.size() > 0 && st.top() <= arr[i]){

		while(st.size() > 0 && st.top() <= arr[i]){
		
			st.pop();
		}
		if(st.empty()){
			ans.push_back(-1);
		}else{
			ans.push_back(st.top());
		}

	}
	
	st.push(arr[i]);
	
}

reverse(ans.begin(),ans.end());

for(auto it:ans){
	cout<<it<<" ";
}
		


return 0;
}
// ....................................................................................................
								//NEXT GREATER ELEMENT TO LEFT
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int  MOD = 1e9+7;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

vector<int>vec = {1,3,2,4};

vector<int>ans;

stack<int>st;

int n = vec.size();


for(int i =0;i<n;i++){
	if(st.empty()){
		ans.push_back(-1);
	}else if(st.size() > 0  && st.top() > vec[i]){
		ans.push_back(st.top());
	}else if(st.size() > 0  && st.top() <= vec[i]){
		while(st.size() > 0  && st.top() <= vec[i]){
			st.pop();
		}

		if(st.empty()){
			ans.push_back(-1);
		}else{
			ans.push_back(st.top());
		}
	}

	st.push(vec[i]);
}

for(auto it:ans){
	cout<<it<<" ";
}



return 0;
}




// ....................................................................................................
							//NEXT SMALLEST ELEMENT TO LEFT
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int  MOD = 1e9+7;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

vector<int>vec = {4,5,2,10,8};

vector<int>ans;

stack<int>st;

int n = vec.size();


for(int i =0;i<n;i++){
	if(st.empty()){
		ans.push_back(-1);
	}else if(st.size() > 0  && st.top() < vec[i]){
		ans.push_back(st.top());
	}else if(st.size() > 0  && st.top() >= vec[i]){
		while(st.size() > 0  && st.top() >= vec[i]){
			st.pop();
		}

		if(st.empty()){
			ans.push_back(-1);
		}else{
			ans.push_back(st.top());
		}
	}

	st.push(vec[i]);
}

for(auto it:ans){
	cout<<it<<" ";
}



return 0;
}







// ....................................................................................................
