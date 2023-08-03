#include <bits/stdc++.h>
using namespace std;

struct segmenttree{
	int n;
	vector<int> st;
	void intit(int n){
		this->n = n;
		st.resize(4*n,0); 
	}

	void  build(int start,int end,int node,vector<int> &v){
		//base case//
		if(start == end){
			st[node] =v[start]; 
		}

		int mid = (start + end)/2;
		//left sub-tree//
		build(start,mid,2*node+1,v);
		//right sub-tree//
		build(mid+1,end,2*node+2,v);
		st[node] = st[node*2+1] + st[node*2+2];

	}

	void build(vector<int> &v){
		build(0,v.size()-1,0,v);
	}
};



 	

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif


vector<int>vec = {1,2,3,4,5,6,7,8};

segmenttree tree;

tree.intit(vec.size());

tree.build(vec);

cout<<tree.st[0];

















 



	return 0;
}