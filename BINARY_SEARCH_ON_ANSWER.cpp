#include <bits/stdc++.h>
using namespace std;
bool all_is_pos(vector<int>vec,int val,int students){
	int stud = 1;
	int page=0;

	for(int i=0;i<vec.size();i++){
		if(vec[i]>val){
			return false;
		}
		if((vec[i]+page) > val){
			stud++;
			page += vec[i];
			if(stud > students){
				return false;
			}
		}
		page += vec[i];
	}
	return true;

}

int allocate_Books(vector<int>vec,int students){
	if(vec.size()<students){
		return -1;
	}
	int low  = 0;
	int high =0;
	for(int i=0;i<vec.size();i++){
		high += vec[i];
	}
	int ans = -1;
	while(low<=high){
		int mid = (low+high)/2;
		if(all_is_pos(vec,mid,students)){
			ans = mid;
			high = mid-1;
		}else{
			low = mid+1;
		}
	}
	return ans;
}

/*...............................................................................................................*/

									/*1283. Find the Smallest Divisor Given a Threshold*/
int blackbox(vector<int>vec,int x ){
	int ans =0;

	for(int i=0;i<vec.size();i++){
		ans = (vec[i]/x);
		if(vec [i] % x != 0){
			ans += 1;
		}

	}

	return ans;
}


int solve(vector<int>vec,int thrushold){
	int low = 1;
	int high = *max_element(vec.begin(),vec.end());

	int ans = high;

	while(low<=high){
		int mid = (high+low)/2;
		if(blackbox(vec,mid)<=thrushold){
			ans = mid;
			high = mid -1;
		}else{
			low = mid+1;
		}
	}
	return ans;
}

/*..................................................................................................................................................*/
int bb(vector<int>vec,int mid , int m){

	int count =1;
	int sum =0;

	for(int i=0;i<vec.size();i++){
		if(vec[i] > mid){
			return false;
		}

		if(vec[i]+sum > mid){
			count++;
			sum = vec[i];
		}else{
			sum += vec[i];
		}
	}
	return count <= m;
}

int split_array(vector<int> vec,int m){
	int low = 0;


	int high = 0;
	for(auto it:vec){
		high+=it;
		if(it > low){
			low = it;
		}
	}
	int ans = high;
	while(low<=high){
		int mid = (low+high)/2;
		if(bb(vec,mid,m) == false){
			low = mid+1;
		}else{
			ans = mid;
			high = mid-1;
		}

	}
	return ans;
}	
/*................................................................................................................*/
											//CHOLOCATE DIVISION 
bool divide(vector<int> vec,int limit,int k){
	int count = 0;

	int sum = 0;
	for(int i=0;i<vec.size();i++){
		sum += vec[i];


		if(sum >= limit){
			count++;
			sum = 0;
		}
	}
	return count >= k;		
}

int cholocate_div(vector<int> vec, int k){
	int low =1;

	int high =0;
	for(auto it:vec){
		high += it;
	}
	int ans = 1;
	while(low<=high){
		int mid = (high+low)/2;

		if(divide(vec,mid,k) == false){
			high = mid-1;
		}else{
			ans = mid;
			low = mid+1;
		}
	}

	return ans;
}



/*................................................................................................................*/





int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif




/*vector<int>vec = {1,2,5,9};

int thrushold = 6;

cout<<solve(vec,thrushold);*/



/*vector<int>vec = {12,34,67,90};
int students = 2;

cout<<allocate_Books(vec,students);*/




vector<int> vec = {1,2,3,4,5,6,7,8,9};
int k =5;

cout<<(vec,k);







 



	return 0;
}