//STRING HASHING   Polynomial hash
#include<bits/stdc++.h>
// #define llint long long int
using namespace std;

const int  p = 31,mod  = 1e9+7;


int poly_hash(string s){

	int hash = 0;

	int p_power =1;

	for(int i=0;i<s.size();i++){
		hash += s[i] - 'a' + 1 * p_power;
		p_power *= p;

		hash = hash%mod;
		p_power = p_power%mod;
	}




	return hash;
}

int powr(int a , int b){
	int res = 1;

	while(b){
		if(b & 1) res *= a;
		b/=2;
		a *=a;

		a%=mod;
		res %=mod; 
	}
	return res;

}

int inv(int x){
	return  powr(x,mod-2); 
}


int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif




string text = "ababbabaaaabababb";
string pat = "abab ";


int pat_hash = poly_hash(pat);
 
int text_hash = poly_hash(text.substr(0,pat.size()));


if(pat_hash == text_hash){
	cout<<0<<endl;
}

int n = text.size();
int m = pat.size();

for(int i=1;i + m <=n;i++){
	//removing the prev occurence

	text_hash = (text_hash - ((text[i-1]- 'a' + 1) +mod)%mod);

	text_hash = (text_hash * inv(p)) % mod; 

	text_hash = (text_hash + (text[i + m-1] - 'a' + 1) *powr(p,m-1)) % mod;

	if(text_hash == pat_hash){
		cout<<i<<endl;
	}


}















































	return 0;
}

//...........................................................................................................................