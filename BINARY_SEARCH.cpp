#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MOD = 1000000007;

int SISRA(vector<int>&vec,int tar){
    int n = vec.size();
    int low = 0,high = vec.size()-1;
    int mid;
    while(low<=high){
        mid = (low+high)/2;
        if(vec[mid] == tar){
            return mid;
        }else if(vec[low] < vec[mid]){
            if(vec[low] <= tar && tar <= vec[mid]){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }else{
            if(vec[mid] <= tar && tar <= vec[high]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
    }

    return -1;

}










int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
// SEARCH IN SORTED ROTATED ARRAY-1

vector<int>vec= {4,5,6,7,0,1,2};
int tar = 0;

cout<<SISRA(vec,tar)<<endl;












return 0;
}


