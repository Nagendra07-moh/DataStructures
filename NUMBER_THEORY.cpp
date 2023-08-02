#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n){
	if(n == 1){
		return false;
	}

	for(int i=2;i*i <= n;i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}	
/*.........................................................................................................................*/
// vector<int> vis(1000001,1);   GENERATE ALL THE PRIME NUMBERS UPTO N;

void seive(int n){
vector<int> vis(n,1);

vis[0] = 0;

vis[1] = 0;

int size = vis.size()-1;

for(int i=2;i * i <= size; i++){

	if(vis[i]){

		for(int j = i*i;j<=size;j+=i){

			vis[j] = 0;
		}
	}
}

for(int i=0;i<n;i++){
	if(vis[i]){
		cout<<i<<" ";
	}
}
 
}

/*.........................................................................................................................*/
												/*BINARY EXPONENTIATION*/
int power(int base,int p){
	int ans =1;

	while(p){
		if(p & 1){
			ans  = ans * base;
			p -= 1;
		}else{
			base = base * base;
			p = p/2;
		}
	}
	return ans;
}
/*.........................................................................................................................*/
							// MICRO AND PRIME//
vector<long long >vec(1000000,1);
vector<long long >pp(1000000,0);

void sieve(){
	int maxN = 1000000;
	vec[0] = vec[1] = 0;

	for(long long i= 2;i * i<=maxN;i++){
		if(vec[i] == 1){
			for(long long j = i*i;j<=maxN;j += i){
				vec[j] = 0;
			}
		}
	}
	
	int cnt =0;

	for(int i=0;i<=maxN;i++){
			if(vec[i] == 1){
				cnt++;
			}

			if(vec[cnt] == 1){
				pp[i] = 1;
			}else{
				pp[i] = 0;
			}
	}
}
/*..........................................................................................................................*/				
									//PRIME FACTORISATION WITH SIEVE ALGO//
// vector<long long> vec(1000000,-1);

// void seive_for_prime_factor(){
// int maxN =1000000;
// vec[0] =0;

// for(int i=2;i<maxN;i++){
// 	if(vec[i] == -1){

// 		for(int j = i*i;j<=maxN;j+=i){
// 			if(vec[j] = -1){
// 				vec[j] = i;
// 			}
// 		}
// 	}
// }

//all those  elements in vec which carry -1 are the prime numbers //
 

// }
/*...........................................................................................................................*/
												//MATRIX EXPONENTIATION(not working....)

// vector<vector<int>> vec(int N,vector<int>(N,0));
// vector<vector<int>> I(int N,vector<int>(N,0));


// void print(vector<vector<int>> vec , int dim){
// 	for(int i=0;i<dim;i++){
// 		for(auto it: vec[i]){
// 			cout<<it<<" ";
// 		}
// 		cout<<endl;
// 	}
// }

// void mul(vector<vector<int>> &vec,vector<vector<int>> &B,int dim){
// 	vector<vector<int>> res(dim+1,vector<int>(dim+1,0));


// 	for(int i=0;i<dim;i++){
// 		for(int j = 0;j<dim;j++){
// 			res[i][j] = 0;
// 			for(int k =0;k<dim;k++){                              // CODE FOR  MATRIX MULTIPLICATION//
// 				res[i][j] += vec[i][k] * B[k][j];
// 			}
// 		}
// 	}

// 	for(int i =0;i<dim;i++){
// 		for(int j =0;j<dim;j++){
// 			vec[i][j] = res[i][j];
// 		}
// 	}


// }



// void power(vector<vector<int>> & vec,int dim,int N){
// for(int i=0;i<dim;i++){
// 	for(int j=0;j<N;j++){
// 		if(i == j){
// 			I[i][j] = 1; 
// 		}else{															//creation of a identity matrix/
// 			I[i][j] = 0;
// 		}
// 	}


// 	for(int i=0;i<N;i++){
// 		mul(I,vec,dim);           // it is the main multiplication(calculation) part//
// 	}


// 	for(int i=0;i<dim;i++){
// 		for(int j=0;j<dim;j++){
// 			vec[i][j] = I[i][j];
// 		}
// 	}

// }
// }
/*..........................................................................................................................*/

//INSIDE MAIN();
/*

int t;
cin>>t;
while(t--){
	int dim, n;
	cin>>dim,n;
	for(int i=1;i<=dim;i++){
		for(int j=1;j<=dim;j++){
			cin>>vec[i][j];
		}
	}

	power(vec,dim,n);

	print(vec,dim);

}


*/

/*...................................................................................................................*/
//  GCD

int gcd(int a,int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b,a%b);
	}
}


int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif




































	return 0;
}