#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MOD = 1000000007;

                                   //WELCOME TO THE BINARY  SEARCH  WORLD
// ....................................................................................................
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

// ----------------------------------------------------------------------------------------------------


int findPeak(vector<int>vec){
    int n = vec.size();

    int low = 0;
    int high = n-1;
    int mid;
    while(low<= high){
        mid = (low+high)/2;

        if((mid ==0 || vec[mid] >= vec[mid-1])&&(mid == n-1 || vec[mid] >= vec[mid+1])){
            return mid;
        }else if(mid>0 && vec[mid-1] >= vec[mid]){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }

    return  -1;
}

// ----------------------------------------------------------------------------------------------------

int sqrt(int n){
    int low = 1;
    int high = n;

    int ans = 1;
    while(low<=high){
        int mid = (low+high)/2;

        if((mid*mid)<=n){
            ans =  mid;
            low = mid+1;

        }else{
            high = mid-1;
        }
    }

    return ans;
}
// -------------------------------------------------------------------------------------------------------


int findBrute(int bph,vector<int>vec){
    int count = 0;

    for( auto it:vec){
        if(it%bph != 0){
            count += (it/bph)+1;
        }else{
            count += it/bph;
        }
    }
    return count;
}

int bruteForce(vector<int>vec,int h){
    int ans = 0;
    int maxi =*max_element(vec.begin(),vec.end());
    for(int i=1;i<=maxi;i++){
        int tot = findBrute(i,vec);
        // cout<<tot<<"-> "<<i<<endl;
        if(tot <= h){
            ans = i;
            break;
        }
    }

    return ans;

}

// -------------------------------------------------------------------------------------------------------

int calcH(int hrs,vector<int>&vec){
    int ans = 0;
    int n = vec.size();
    for(int i=0;i<n;i++){
        ans += ceil((double)vec[i] / (double)hrs);
    }
    return ans;
}

int BSOA(vector<int>vec,int h){
    int low = 1;
    int high = *max_element(vec.begin(),vec.end());
    // int ans = INT_MAX;
    while(low <= high){
        int mid = (low+high)/2;
        int total = calcH(mid,vec);
        if(total <= h){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }

    return low;

}
// -------------------------------------------------------------------------------------------------------

int MNODMB_Nieve(vector<int>&vec,int k, int m ){
    int n = vec.size();
    if(n < (m*k)){
        return -1;
    }

    int ans = INT_MIN;
    priority_queue<int,vector<int>,greater<int>>pq;
    int sum = 0;
    for(int i=0;i<k;i++){
        sum += vec[i];
    }
    pq.push(sum);

    for(int i=k;i<n;i++){
        sum  += vec[i] - vec[i-k];
        pq.push(sum);
    }

    while(m--){
        ans = max(ans,pq.top());
        pq.pop();
    }



    return ans;
}




// -------------------------------------------------------------------------------------------------------




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

// FIND THE PEAK ELEMENT OF THE ARRAY



//FIND SQRT USING BINARY SEARCH ON ANSWER

// cout<<sqrt(25)<<endl;   // (O) log n :- TC



// COCO EATING BANANAS LEETCODE

// vector<int>vec ={30,11,23,4,20};
// int h =5;

//cout<<bruteForce(vec,h); // This is brute force approac

// cout<<BSOA(vec,h)<<endl;

// 1482. Minimum Number of Days to Make m Bouquets

vector<int>vec = {7,7,7,7,12,7,7};
int m =2;
int k=3;

cout<<MNODMB_Nieve(vec,k,m)<<endl;




return 0;
}


