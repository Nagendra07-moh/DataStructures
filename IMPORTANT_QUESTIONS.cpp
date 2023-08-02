#include <bits/stdc++.h>
using namespace std;

sort(vec.begin(), vec.end(),
            [](auto &a, auto &b) -> bool {
                return a[1] < b[1]; 
            });

/*..................................................................................................................*/
					// ADD TWO LARGE STRINGS OF NUMBERS//
string add_str(string a, string b){
	// b always be larger
	//a always be smaller
	if(b.length()<a.length()){
		swap(a,b);
	}
	string ans = "";
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());

	int carry=0;

	for(int i=0;i<a.length();i++){
		int sum = 0;

		sum += (a[i] - '0')+(b[i] - '0') + carry;

		ans.push_back(sum%10 + '0');

		carry = sum/10;

	}


	for(int i=a.length();i<b.length();i++){
		int sum =0;
		sum += carry + (b[i] -'0');

		ans.push_back(sum%10 + '0');

		carry = sum/10;


	}


	if(carry){
		ans.push_back(carry - '0');
	}
	reverse(ans.begin(),ans.end());
	return  ans;
}
					 
/*..................................................................................................................*/
							/*MAXIMUM SUBARRAY SUM EQUALS K (variable sliding window)*/
int solve(vector<int>vec,int k){
	int n = vec.size();
	int i=0;int j = 0;
	int max_sum = -1;
	int sum = 0;

	while(j<n){
		sum+=vec[j];
		if(sum == k){
			max_sum = max(max_sum,j-i+1);
		}else if(sum > k){
			sum-= vec[i];
			i++;
		}
		j++;
	}
	return max_sum;

}
/*.................................................................................................................*/

vector<int>vec = {5,6,7,8,9};	/*1 2 6 8 11 */
int n = vec.size();
int x = 4;
unordered_map<int,int>mp;

mp[0] = 0;
int sum =0;
for(int i=0;i<vec.size();i++){
	sum += vec[i];
	mp[sum] = i;
	vec[i] = sum;
}
sum = sum - x;

int ans;
int maxi = 0;
for(int i=0;i<n;i++){
	if(mp.count(vec[i]-sum)){
		if((vec[i] - sum) == 0){
			maxi = max(maxi,i - mp[vec[i] - sum] +1);
		}else{
			maxi = max(maxi,i - mp[vec[i] - sum]);

		}
	}
}
if(maxi){
	if(sum == 0){
		cout<<n<<endl;
	}else{
		cout<<-1<<endl;
	}
}else{
	cout<<n-maxi;
}

/*---------------------------------------------------------------------------------------------------------------*/
bool compare(vector<int> v1 , vector<int> v2){
	return v1[1]>v2[1];
}



vector<vector<int>> vec = {{5,10},{2,5},{4,7},{3,9}};
int x =10;
int ans =0;
sort(vec.begin(),vec.end(),compare);

int i=0;
while(x > 0 && i<vec.size()){
	if(vec[i][0] <= x){
		x -= vec[i][0];
		ans +=  vec[i][0] * vec[i][1];
	}else{
		int left = x;
		x -= left;
		ans +=  left * vec[i][1];
	}
	i++;
}

cout<<ans<<endl;

/*_________________________________________________________________________________________________________________*/
	GRAPHS ---->  797. All Paths From Source to Target


void find(int node, vector<vector<int>>vec,vector<int> &vis,vector<vector<int>> & ans,vector<int> &temp){
temp.push_back(node);
if(node == vec.size()-1){
	ans.push_back(temp);
	temp.pop_back();
	return;
}
vis[node] =1;

for(auto it: vec[node]){
	if(!vis[it]){
		find(it,vec,vis,ans,temp);
	}
}



vis[node] = 0;
temp.pop_back();
}

vector<vector<int>> solve(vector<vector<int>> vec,int n){
	vector<vector<int>> ans;
	vector<int> vis(n,0);
	vector<int> temp;
	find(0,vec,vis,ans,temp);

	return ans;

}
/*__________________________________________________________________________________________________________________*/


								/*128. Longest Consecutive Sequence*/ LEETCODE




class Solution {
public:
    int longestConsecutive(vector<int>& vec) {
        if(vec.empty()){
            return 0;
        }
        
        unordered_set<int> st;

        for(auto it:vec){
            st.insert(it); 
        }

        int maxi = 0;

        for(int i=0;i<vec.size();i++){
            if(st.find(vec[i] - 1) != st.end()){
                continue;
            }else{
                int count = 0;
                int x = vec[i];
                while(st.find(x) != st.end()){
                    count++;
                    x++;
                }

                maxi =  max(maxi,count);
                count = 0;
            }
        }
        return maxi;
    }
};


/*----------------------------------------------------------------------------------------------------------------*/


			// /* 733. Flood Fill*/ LEETCODE


void dfs(vector<vector<int>> &vec,int sr,int sc,int color,int row,int col,int source){
	if(sr<0 || sr>=row || sc<0 || sc>=col){
		return;
	}else if(vec[sr][sc] != source){
		return;
	}

	vec[sr][sc] = color;

	dfs(vec,sr+1,sc,color,row,col,source);
	dfs(vec,sr-1,sc,color,row,col,source);
	dfs(vec,sr,sc+1,color,row,col,source);
	dfs(vec,sr,sc-1,color,row,col,source);

}

vector<vector<int>> vec = {{1,1,1},{1,1,0},{1,0,1}};
	int sr = 1;
	int sc =1;
	int color = 2;

	int source = vec[sr][sc];
	int row = vec.size();
	int col = vec[0].size();


	dfs(vec,sr,sc,color,row,col,source);

for(int i=0;i<vec.size();i++){
	for(auto it:vec[i]){
		cout<<it<<" ";
	}
	cout<<endl;
}

/*................................................................................................................*/
									// /*200. Number of Islands*/LEETCODE


void dfs(vector<vector<string>> &vec,int row, int col, int r,int c){
	
	if(r<0 || r>=row || c<0 || c>=0 ||vec[r][c] != "1"){
		return;
	}
	vec[r][c] = "2";

	dfs(vec,row,col,r+1,c);
	dfs(vec,row,col,r,c+1);
	dfs(vec,row,col,r-1,c);  
	dfs(vec,row,col,r,c-1);
}



vector<vector<string>> vec = {{"1","1","1","1","0"},{"1","1","0","1","0"},{"1","1","0","0","0"},{"0","0","0","0","0"}};

int row = vec.size();
int col = vec[0].size();
		
int count =0;
for(int i=0;i<row;i++){
	for(int j=0;j<col;j++){
		if(vec[i][j] == "1"){
			dfs(vec,row,col,i,j);
			count +=1;
		}
	}
	
}



cout<<count<<endl;

/*................................................................................................................*/



// vector<vector<int>> vec = {{6,7,8},{5,4,9},{},{8},{4},{},{1,9,2,3},{7},{6,5},{2,3,1}};
vector<vector<int>> vec = {{1,3},{3,0,1},{2},{0}};

vector<int> vis(vec.size(),0);


vis[0] = 1;


queue<int> q;

for(auto it:vec[0]){
	q.push(it);
}

while(!q.empty()){
	int node = q.front();
	q.pop();
	vis[node] = 1;
	for(auto it: vec[node]){
		if(!vis[it]){
			q.push(it);
			vis[it] = 1;
		}
	}
}

bool flag  =  true;

for(auto it: vis){
	cout<<it<<" ";
}


/*___________________________________________________________________________________________________________________	*/



							/*2131. Longest Palindrome by Concatenating Two Letter Words*/


 string reverseString(string copy){

	reverse(copy.begin(), copy.end());
	return copy;
 } 

 vector<string> vec  = {"cc","ll","xx"};
unordered_map<string,int> mp;


for(int i=0;i<vec.size();i++){
	mp[vec[i]]++;
}



int ans =0;
int count =0;

for(auto it : mp){
	if(it.first[0] == it.first[1]){
		ans += (it.second / 2) *2;
		count += it.second % 2;
		continue;
	}

	auto rev = reverseString(it.first);

	if(mp.find(rev) != mp.end()){
		ans += min(mp[rev],it.second);
	}
}

if(count){
	ans+=1;
}

cout<<2 * ans<<endl;

/*....................................................................................................................*/

									/*ARMY TRANING*/ CODECHEF

int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<ll>vec;
    ll total =0;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        vec.push_back(x);
        total += x;
    }

    sort(vec.begin(),vec.end(),greater<int>());

    ll sum = 0;

    ll ans =0;

    for(int i=0;i<n;i++){
        ans = max(ans,sum * (( 1000 * (n-i)) -(total - sum)));
        sum += vec[i];
    }

    cout<<ans<<endl;

}


//TC->
/*
4
2
500 500
3
500 500 500
4
100 800 300 500
4
300 700 800 200

d/*__________________________________________________________________________________________________________________*/

											/*97. Interleaving String*/LEETCODE




class Solution {
  unordered_map<string,bool>  mem;
    
    bool check(string s1,string s2,string s3, int l1,int l2 ,int l3, int p1, int p2 , int p3){
        
        if(p3 == l3){
            if(p2 == l2 && p3 == l3){
                return true;
            }else{
                return false;
            }
        }
        string key = to_string(p1) + "*" + to_string(p2) + "*" + to_string(p3);
        if(mem.find(key) != mem.end()){
            return mem[key];
        }
        
        if(p1 == l1){
            return mem[key] == s2[p2] == s3[p3]? check(s1,s2,s3,l1,l2,l3,p1,p2+1,p3+1):false;   
        }
        if(p2 == l2){
            return mem[key] == s1[p1] == s3[p3]? check(s1,s2,s3,l1,l2,l3,p1+1,p2,p3+1):false;
        }
        
        bool one =  false,two = false;
        if(s1[p1] == s3[p3]){
            one = check(s1,s2,s3,l1,l2,l3,p1+1,p2,p3+1);
        }
        if(s2[p2] == s3[p3]){
            two = check(s1,s2,s3,l1,l2,l3,p1,p2+1,p3+1);
        }
        return mem[key] = one || two;
        
    }
    
   
    
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
        
        return check(s1,s2,s3,l1,l2,l3,0,0,0);
        
    }
};

/*_________________________________________________________________________________________________________________________________*/


						/* graph count no. of disconnected components in a graph*/

vector<vector<int>>vec = {{1,0,0},{0,1,0},{0,0,1}};
int n = vec.size();
vector<int> vis(n,0);
vector<int> adj[n];
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		if(j != i && vec[i][j] != 0){

			adj[i].push_back(j);
		}
	}
}

int count = 0;
for(int i=0;i<n;i++){
	if(!vis[i]){
		count++;

		queue<int> q;
		q.push(i);
		vis[i] = 1;

		while(!q.empty()){
			int node = q.front();
			q.pop();

			for(auto it:adj[node]){
				if(!vis[it]){
					q.push(it);
					vis[it] = 1;
				}
			}
		}
	}
}

cout<<count<<endl;

/*________________________________________________________________________________________________________________________*/

								/*Minimum steps to reach target by a Knight (BFS)*/

struct Node{
	int x, y, dis;

	Node(int x,int y,int dis = 0): x(x), y(y), dis(dis) {}
		
};


bool is_under_bndry(int x,int y,int n){
	if((x>= 0 &&  x<n) &&(y>=0 && y<n)){
		return true;
	}
	return false;
}


int find_sortest_path(Node start,Node end,int n){
	
	vector<vector<int>>vis(n,vector<int>(n,0));

	vector<int> row = {2, 2, -2, -2, 1, 1, -1, -1 };
	vector<int> col = {-1, 1, 1, -1, 2, -2, 2, -2};

	queue<Node> q;

	q.push(start);

	while(!q.empty()){

		Node node = q.front();
		q.pop();


		int x = node.x;
		int y = node.y;
		int dis = node.dis;

		if(x == end.x && y == end.y){
			return dis;
		}

		if(vis[x][y] == 0 ){

			vis[x][y] = 1;


			for(int i=0;i<8;i++){
				int x1 = x + row[i];
				int y1 = y + col[i];

				if(is_under_bndry(x1,y1,n)){
					q.push{x1,y1,dis+1};
				}

			}
		}
	}
	return 0;
}

/*.....................................................................................................................................*/
//CODEFORCES (Codeforces Round #806 (Div. 4)) solved 3 problems

#include <bits/stdc++.h>
using namespace std;
int cal(char c){
	if(c  == 'D'){
		return 1;
	}
	return -1;
}

void  form_the_ans(vector<int> &vec, vector<pair<int,string>> moves,int n){

	for(int t=0;t<n;t++){
		int x = vec[t];

		int z = moves[t].first;

		string s = moves[t].second;
		for(int i = 0;i<z;i++){
			x += cal(s[i]);
		}
		vec[t] = (10 -(10 - x)%10)%10;
	}

}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

int t;
cin>>t;
while(t--){
	int n;
	cin>>n;
	vector<int>vec;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		vec.push_back(x);
	}
	vector<pair<int,string>> moves(n);

	for(int i=0;i<n;i++){
		int x;
		string pr;
		cin>>x>>pr;
		moves[i].first = x;
		moves[i].second = pr;
	}
	form_the_ans(vec,moves,n);


	for(auto it: vec){
		cout<<it<<" ";
	}
	cout<<endl;

}

	return 0;
}
								//.................................//

#include <bits/stdc++.h>
using namespace std;





int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif



int t;
cin>>t;
while(t--){
	int n;
	cin>>n;
	vector<string> vec(n);
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		vec[i] = s;
	}

	unordered_map<string,int> mp;

	for(auto it:vec){
		mp[it] = 0;
	}

	for(int i=0;i<n;i++){
		string x = vec[i];
		for(auto it:vec){
			string y = it;
			if(mp.find(x+y) != mp.end()){
				mp[x+y] = 1;
			}
		}

	}

	string ans ="";

	for(int i=0;i<n;i++){
		if(mp[vec[i]]==1){
			ans +='1';
		}else{
			ans +='0';
		}
	}
	cout<<ans<<endl;
}

	return 0;
}


//tc
// 3
// 5
// abab
// ab
// abc
// abacb
// c
// 3
// x
// xx 	
// xxx
// 8
// codeforc
// es
// codes
// cod
// forc
// forces
// e
// code

//ans

// 10100
// 011
// 10100101
// .....................................................................................................................//k








































































































































































































































































































































































































































































