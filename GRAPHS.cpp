using namespace std;
							//	 FUNCTION TO MAKE THE GRAPH....................	
void make_graph(vector<int> &adj[],int u,int v){
	adj[u].push_back(v);
	adj[v].push_back(u);

}
/*.......................................................................................................................*/
								//FUNCTION TO PRINT A GRAPH......................
void print_graph(vector<int> adj[],int n){	
	for(int i=0;i<n;i++){
		cout<<i<<"->";
		for(auto it:adj[i]){
			cout<<it<<" ";
		}
 		cout<<endl;
	}
}
/*.......................................................................................................................*/
							// BREADTH_FIRST_SEARCH OF GRAPH.......................
vector<int> bfsOfGraph(int v,vector<int> adj[]){
	vector<int> bfs;
	vector<int> vis(v+1,0);

	for(int i=1;i<=v;i++){
		if(!vis[i]){

				queue<int> q;
				q.push(i);
				vis[i] =1;
				while(!q.empty()){
					int node = q.front();
					q.pop();
					bfs.push_back(node);

					for(auto it: adj[node]){
						if(!vis[it]){
							q.push(itis_possible);
							vis[it] = 1;
						}
					}
				}

		}
	}

	return bfs;
}
/*.......................................................................................................................*/
							//DEPTH_FIRST_SEATRCH IN GRAPH.................................
void dfs(int node,vector<int> &vis,vector<int> adj[],vector<int> &ans){
	ans.push_back(node);
	vis[node] = 1;

	for(auto it:adj[node]){
		if(!vis[it]){
			dfs(it,vis,adj,ans);
		}
	}
}


vector<int> dfsOfGraph(int n,vector<int> adj[]){
	vector<int> ans;
	vector<int>vis(n+1,0);

	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i,vis,adj,ans);
		}
	}
	return ans;
}
/*.......................................................................................................................*/
                                //DETECT A CYCLE IN GRPH USING BFS//
bool find_cycle(int n,vector<int> &vis,vector<int> adj[], int v){
	queue<pair<int,int>>q;
	vis[n] = 1;
	q.push({n,-1});

	while(!q.empty()){
		auto tp = q.front();

		int node = tp.first;	 
		int prev =tp.second;

		// int node = q.top().first;
		// int prev = q.top().second;

		q.pop();

		for(auto it:adj[node]){
			if(!vis[it]){
				vis[it] =1;
				q.push({it,node});
			}else if(prev != it){
				return true;
			}
		}
	}
	return  false;
}

bool detect_cycle_bfs(int v,vector<int>adj[]){
	vector<int>vis(v+1,0);

	for(int i=1;i<=v;i++){
		if(!vis[i]){
			if(find_cycle(i,vis,adj,v)){
				return true;
			}

		}
	}
	return false;
}
/*.........................................................................................................................*/
							// DETECT CYCLE IN A GRAPH BY USING DFS TRAVERSAL//
bool find_the_cycle(int node,int prev,vector<int> &vis,vector<int> adj[]){
	vis[node] = 1;

	for(auto it:adj[node]){
		if(!vis[it]){
			if(find_the_cycle(it,node,vis,adj)){
				return true;
			}
		}else if(it != prev){
				return true;
		 }
	}
return false;
}

bool detect_cycle_dfs(
	 int v,vector<int> adj[]){

	vector<int>vis(v+1,0);

	for(int i=1;i<=v;i++){
		if(!vis[i]){
			if(find_the_cycle(i,-1,vis,adj)){
				return true;
			}
		}
	}
	return false;
}
/*..........................................................................................................................*/
											//BIPERTITE GRAPH BFS//
											
bool bipratre_bfs(int i,vector<int> adj[],int color[]){
	queue<int>q;
	q.push(i);
	color[i] = 1;

	while(!q.empty()){
		int node = q.front();
		q.pop();

		for(auto it:adj[node]){
			if(color[it] == -1){
				q.push(it);
				color[it] =1 - color[node];
			}else if(color[it]  == color[node]){
				return false;
			}
		}
	}
	return true;
}


bool check_bipertite_bfs(vector<int> adj[],int n){
	int color[n];
	memset(color,-1,sizeof color);	
	for(int i=0;i<n;i++){
		if(color[i] == -1){
			if(bipratre_bfs(i,adj,color) == false){
				return false;
			}
		}
	}
	return true;
}
/*...........................................................................................................................*/
									// BIPERTITE GRAPH DFS//

bool bipratre_dfs(int node,vector<int> adj[],int color[]){
	if(color[node] == -1) color[node] = 1;		//just to initiate the vis for the fist element//

	for(auto it:adj[node]){
		if(color[it] == -1){
			color[it] = 1 - color[node];
			if(!bipratre_dfs(it,adj,color)){
				return false;
			}

		}else if(color[it] == color[node]){
			return false;
		}
	}
	return true;

}



bool check_bipertite_dfs(int n,vector<int> adj[]){
	int color[n];
	memset(color,-1,sizeof color);
	for(int i=0;i<n;i++){
		if(color[i] == -1){
			if(!bipratre_dfs(i,adj,color)){
				return false;
			}
		}
	}
	return true;
}
/*.................................................................................................................*/
						//	DETECT A CYCLE IN A DIRECTED(DIRECTED) GRAPH USING DFS....
bool directedBfs_detect_cycle(int node,int vis[],int dfsVis[],vector<int> adj[]){
	vis[node] = 1;
	dfsVis[node] = 1;
	
	for(auto it:adj[node]){
		if(!vis[it]){
			if(directedBfs_detect_cycle(it,vis,dfsVis,adj)){
				return true; 			//(so no recursion calls further) if it detects a cycle//
			}
		}else if(dfsVis[it]){
			return true;
		}
	}
	dfsVis[node] = 0;
	return false;
}

bool check_cycle_in_directed_graph(vector<int> adj[],int n){
	int vis[n];
	int dfsVis[n];
	memset(vis,0,sizeof vis);
	memset(dfsVis,0,sizeof dfsVis);

	for(int i=1;i<=n;i++){			// for 1 based indexing //
		if(!vis[i]){
			if(directedBfs_detect_cycle(i,vis,dfsVis,adj)){
				return true;		//if it detect cycle it will return true....// 
			}
		}
	}
	return false; 				// if it didn't detect a cycle it will gona return false.....//
}



/*.................................................................................................................*/
								/*TOPOLOGICAL SORTING USING DFS*/
void topo(int node,vector<int>adj[] ,stack<int> &st,vector<int> &vis){
	vis[node] = 1;

	for(auto it:adj[node]){
		if(!vis[it]){
			topo(it,adj,st,vis);
		}
	}
	st.push(node);
}



vector<int> topoSort(int n,vector<int> adj[]){
	stack<int> st;
	vector<int> vis(n,0);
	for(int i=0;i<n;i++){				//FOR 0  BASED INDEXING//
		if(!vis[i]){
			topo(i,adj,st,vis);
		}
	}
	vector<int> ans;

	while(!st.empty()){
		int tp = st.top();
		st.pop();
		ans.push_back(tp);
	}

	return ans;

}





/*.................................................................................................................*/
									//TOPOLOGICAL SORT USING BFS//
vector<int> Topo(int n,vector<int> adj[]){
queue<int>q;

vector<int>indegree(n,0);
for(int i=0;i<n;i++){
	for(auto it:adj[i]){
		indegree[it]++;
	}
}

for(int i=0;i<n;i++){
	if(indegree[i] == 0){
		q.push(i);
	}
}
vector<int>ans;

while(!q.empty()){
	int node = q.front();
	q.pop();
	ans.push_back(node);
	for(auto it:adj[node]){
		indegree[it]--;
		if(indegree[it] == 0){
			q.push(it);
		}
	}
}
return ans;
}
/*...........................................................................................................................*/
					//DETECT A CYCLE IN A DIRECTED GRAPH (USING KAHN'S ALGO)
bool det_clc_directed_graph_bfs(int n, vector<int> adj[]){
	queue<int>q;

	vector<int> indegree(n,0);

	for(int i=0;i<n;i++){
		for(auto it:adj[i]){
			indegree[it]++;
		}
	}

	for(int i=0;i<n;i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}
	int cnt = 0;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		cnt++;
		for(auto  it:adj[node]){
			indegree[it]--;
			if(indegree[it] == 0){
				q.push(it);
			}
		}
	}
	if(cnt == n ) return  false;  // it means there is no loop or a cycle//
	return true;   // it means there is a cycle//
}
/*...........................................................................................................................*/
						//SHORTEST DISTANCE FROM SOURCE TO EVERY OTHER NODE/ DIJSTRA ALGO /
vector<int> Dijstra_for_sortest_dis_of_weighted_graph_one_src(vector<pair<int,int>> adj[], int n,int source){
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
	vector<int> distTo(n-1,INT_MAX);//1-indexed array for calculating shortest paths
	distTo[source] = 0;
	pq.push(make_pair(0,source));	// (dist,source)
	while( !pq.empty() ){
		int prev = pq.top().second;
		int dist = pq.top().first;
		pq.pop();
		vector<pair<int,int> >::iterator it;
		for(auto it:adj[prev]){
			int next = it.first;
			int nextDist = it.second;
			if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}	
}

return distTo;
}

/*...........................................................................................................................*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first

void print_graph(int n,vector<pair<int,int>>adj[]){

	for(int i=0;i<n;i++){
		cout<<i<<"->";
		for(auto it:adj[i]){
			cout<<"("<<it.first<<","<<it.second<<")";
		}
		cout<<endl;
	}
}


int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

//RED = 1, BLUE = 0;
vector<vector<int>> vecRed = {{0,1},{1,2}};

vector<vector<int>>vecBlue = {};

int n = 3;


vector<vector<int>>vis(101,vector<int>(2,0));


vector<int> adjR[101],adjB[101];

for(auto it:vecRed){
	adjR[it[0]].push_back(it[1]);
}

for(auto it:vecBlue){
	adjB[it[0]].push_back(it[1]);
}

vector<int>ans(n,INT_MAX);
int cost = 0;
queue<pair<int,int>>q;			//PAIR<NODE,COLOR>

q.push({0,0});
q.push({0,1});
vis[0][0] == vis[0][1] == 1;

while(!q.empty()){
	int s = q.size();

	for(int i=0;i<s;i++){
		auto it = q.front();
		q.pop();

		int node = it.first;
		int color = it.second;

		ans[node]  = min(ans[node],cost);

		if(color == 1){
			for(auto it:adjB[node]){
				if(!vis[it][0]){
					vis[it][0] = 1;
					q.push({it,0});
				}
			}
		}else{
			for(auto it:adjR[node]){
				if(!vis[it][1]){
					vis[it][1] = 1;

					q.push({it,1});
				}
			}
		}
	}
	cost++;
}

for(int i =0;i<n;i++){
	if(ans[i] == INT_MAX){
		ans[i] = -1;
	}
}

for(auto it:ans){
	cout<<it<<" ";
}



	return 0;
}


	



/*.......................................................................................................................*/
													//01 MATRIX

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MOD = 1000000007;



int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif


//01 MATRIX

vector<vector<int>>vec = {{0,0,0},{0,1,0},{1,1,1}};

int n = vec.size();
int m = vec[0].size();

vector<vector<int>>vis(n,vector<int>(m,-1));


vector<vector<int>>ans(n,vector<int>(m,0));


queue<pair<pair<int,int>,int>>q;


for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		if(vec[i][j] == 0){
			q.push({{i,j},0});
			vis[i][j] = 1;
		}
	}
}
vector<int>row = {-1,0,0,1};
vector<int>col = {0,-1,1,0};

while(!q.empty()){
	int x = q.front().first.first;
	int y = q.front().first.second;
	int dis =q.front().second;
	q.pop();
	ans[x][y] = dis;

	for(int i=0;i<4;i++){
		int nx = x+row[i];
		int ny = y+col[i];

		if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny] == -1){
			vis[nx][ny] = 1;
			q.push({{nx,ny},dis+1});
		}
	}
}



for(int i=0;i<n;i++){
	for(auto it:ans[i]){
		cout<<it<<" ";
	}
	cout<<endl;
}



return 0;
}


/*.......................................................................................................................*/

#include <bits/stdc++.h>
using namespace std;
const int  M = 1e9+7;
void dfs(int r,int c,vector<vector<char>>vec,vector<vector<int>>&vis,vector<int>drow,vector<int>dcol,int row,int col){
	vis[r][c] = 1;

	for(int i=0;i<4;i++){
		int nrow = r + drow[i];
		int ncol = c + dcol[i];

		if(nrow>=0 && nrow<row && ncol>=0 && ncol < col && !vis[nrow][ncol] && vec[nrow][ncol] == 'O'){
			dfs(nrow,ncol,vec,vis,drow,dcol,row,col);
		}
	}


	
}



int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif



vector<vector<char>>vec = {{'X', 'X', 'X', 'X'}, 
					       {'X', 'O', 'X', 'X'}, 
					       {'X', 'O', 'O', 'X'}, 
					       {'X', 'O', 'X', 'X'}, 
					       {'X', 'X', 'O', 'O'}};

int n = vec.size();
int m = vec[0].size();
vector<vector<int>>vis(n,vector<int>(m,0));
vector<int>drow = {-1,1,0,0};
vector<int>dcol = {0,0,-1,1};

for(int j=0;j<m;j++){
	//for first row

	if(!vis[0][j] && vec[0][j] == 'O'){
		dfs(0,j,vec,vis,drow,dcol,n,m);
	}

	//for  the last row

	if(!vis[n-1][j] && vec[n-1][j] == 'O'){
		dfs(n-1,j,vec,vis,drow,dcol,n,m);
	}

}

for(int i=0;i<n;i++){
	//for first col

	if(!vis[i][0] && vec[i][0] == 'O'){
		dfs(i,0,vec,vis,drow,dcol,n,m);
	}


	//for the last col

	if(!vis[i][m-1] && vec[i][m-1] == 'O'){
		dfs(i,m-1,vec,vis,drow,dcol,n,m);
	}


}


for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		if(!vis[i][j] && vec[i][j] == 'O'){
			vec[i][j] = 'X';
		}
	}
}


//for output

for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		cout<<vec[i][j]<<" ";
	}
	cout<<endl;
}


























	return 0;
}


//................................................................................................................. 




int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

int n,m;
cin>>n>>m;

vector<int> adj[n+1];

for(int i=0;i<n+1;i++){
	int u , v;

	cin>>u>>v;

	make_graph(adj,u,v);
}

print_graph(adj,n);





/*
int n,m;
vector<int> adj[n+1];

for(int i = 0;i<m;i++){
    int v,u;
    cin>>v>>u;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
*/





/*
5 7
1 2 
2 4 
2 3
1 3
3 4
1 5
5 3
*/

/*
6 6
5 0
4 0
4 1
3 4
2 3
5 2
*/



// if(check_bipertite_bfs(adj,n)){
// 	cout<<"Yes"<<endl;
// }else{
// 	cout<<"NO"<<endl;
// }



	return 0;
}