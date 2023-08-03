#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int  MOD = 1e9+7;





int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

string s = "(ed(et(oc))el)";
int n = s.size();

stack<string>st;

string curr = "";
for(int i=0;i<n;i++){
	if(s[i] == '('){
		st.push(curr);
		curr = "";
	}else if(s[i] == ')'){
		reverse(curr.begin(),curr.end());
		curr = st.top()+curr;
		st.pop();
	}else{
		curr+=s[i];
	}
} 

cout<<curr;



































return 0;
}