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

// ----------------------------------------------------------------------------------------------------

bool SISRA2(vector<int>&vec,int tar){
    int n = vec.size();
    int low = 0,high = vec.size()-1;
    while(low<=high){
        int mid = (low+ high)/2;

        if(vec[mid] == tar){
            return true;
        }
        if(vec[low] == vec[mid] && vec[mid] == vec[high]){
            low++;
            high--;
            continue;
        }

        if(vec[low] <= vec[mid]){
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

    return false;

}

// ----------------------------------------------------------------------------------------------------

int MISRA(vector<int>&vec){
    int n = vec.size();
    int low = 0;
    int high = vec.size()-1;

    if(vec[low] < vec[high]){
        return vec[0];
    }

    int mid;

    while(low<=high){
        mid = (low+high)/2;
        if(vec[mid] == vec[high]){
            high--;
        }else if(vec[mid] > vec[high]){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }

    return vec[mid];
}

int findMin(vector<int>&vec){
    int n  = vec.size();
    int low = 0;
    int high = n-1;
    int mini = INT_MAX;
    while(low<=high){
       int mid = (low+high)/2;
        if(vec[low] <= vec[high]){
            mini = min(vec[low],mini);
            break;
        }
        if(vec[low] <= vec[mid]){
            mini = min(vec[low],mini);
            low = mid+1;
        }else{
            mini = min(vec[mid],mini);
            high = mid-1;
        }
    }

    return mini;
}


// ----------------------------------------------------------------------------------------------------


int RC(vector<int>&vec){
    int n  = vec.size();
    int low = 0;
    int high = n-1;
    int mini = INT_MAX;
    int ind = -1;
    while(low<=high){
       int mid = (low+high)/2;
        if(vec[low] <= vec[high]){
            mini = min(vec[low],mini);
            ind = low;
            break;
        }
        if(vec[low] <= vec[mid]){
            mini = min(vec[low],mini);
            ind = low;
            low = mid+1;
        }else{
            mini = min(vec[mid],mini);
            ind = high;
            high = mid-1;
        }
    }

    return ind;
    
}


// ----------------------------------------------------------------------------------------------------

int FSESA(vector<int>vec){
    int n = vec.size();
    if(n == 1) return vec[0];
    if(vec[0] != vec[1]) return vec[0];
    if(vec[n-1] != vec[n-2]) return vec[n-1];

    int low =1;
    int high = n-2;

    while(low<=high){
        int mid = (low+high)/2;

        if(vec[mid-1] != vec[mid] && vec[mid] != vec[mid+1]){
            return vec[mid];
        }else if ((mid%2 == 1 && vec[mid-1] == vec[mid]) || (mid%2 == 0 && vec[mid] == vec[mid+1])){
            low = mid+1;
        }else{
            high = mid-1;
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

// vector<int>vec= {4,5,6,7,0,1,2};
// int tar = 0;

// vector<int>vec = {3,1};
// int tar = 1;
// cout<<SISRA(vec,tar)<<endl;


// SEARCH IN SORTED ROTATED ARRAY-2


// vector<int>vec = {1,1,1,1,1,1,1,1,1,13,1,1,1,1,1,1,1,1,1,1,1,1};

// int tar = 13;

// cout<<SISRA2(vec,tar);


// MINIMUM IN SORTED ROTATED ARRAY

// vector<int>vec = {11,13,15,17};
// int n = vec.size();

// cout<<MISRA(vec)<<endl;

// FIND OUT HOW MANY TIMES ARRAY HAS BEEN ROTATED (Rotation Count)(CODING NINJAS)
// 11 12 15 2 5 6 8 - >3
// vector<int>vec ={11, 12 ,15, 2 ,5 ,6 ,8}; // ->2

// cout<<RC(vec);


// FIND THE SINGLE ELEMENT IN SORTED ARRAY 

// vector<int>vec = {3,3,7,7,10,11,11};
// int n = vec.size();

// cout<<FSESA(vec);



return 0;
}


