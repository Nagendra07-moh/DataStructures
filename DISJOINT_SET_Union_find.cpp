//it is for the initiaization of the main array (which cointains value i at index i)//
void  init(vetor<int> &vec,int n){
	for(int i=0;i<n;i++){
		vec[i] = i;
	}
}

//THE FIND FUNCTION WILL TELL WETHER THE ELEMENTS ARE CONNECTED(EIHER DIRECTLY OR IN-DIRECTLY) TO EACH OTHER//

bool find(vector<int> vec,int n,int a ,int b){
	// return (vec[a] == vec[b]);

	if(vec[a] == vec[b]){
		return true;
	}
	return false;
}

//CHANGE ALL THE ENTRIE TO VEC[A] TO VEC[B];


void update_the_new_parent(vector<int> &vec,int n,int a,int b){
	int temp  = vec[a];

	for(int i=0;i<n;i++){													//0(n^2)//
		if(vec[i] == temp){
			vec[i] = vec[a];	
		}
	}
}

......................................................................................................................................


//MODDED UNION

int Find_root(vector<int> &vec,int a) {

	while(vec[a] == a){
		a = vec[a];
	}

	return a;
}



bool Union(vector<int> &vec,int n,int a, int b){

	int root_a = find(vec,a);
	int root_b = find(vec,b);

	if(root_b == root_a){
		return true;
	}

	return false;

} 


.......................................................................................................................................

																TREE_BALANCING=>

In TREE BALANCING we maintain another array/vector which stores/tracks the size/rank of the connected components......................

In  Union using TREE BALANCING we tend to join ROOT_OF lower rank/size component to ROOT_OF higher 
rank/size component and increment the size/rank of the MAIN root(in which the other component is being connected)...................
(IT MEANS COMPONENT WITH HIGH NUMBER OF ELEMENTS  WILL DOMINATE OVER THE ELEMENT WITH LOWER NUMBER OF COMPONENTS)....................



WE COULD IMPLEMENT TREE BALANCING BY SLIGHTLY MODIFING THE INITILISATION FUNCTION.....................................................


vector<int> size(10000000); 	WE CAN TAKE A GLOBAL VARIABLE TO STORE THE SIZE OF EACH ROOT  ELEMENNT...............



void init(vector<int> &vec, int n){


	for(int i=0;i<vec.size();i++){
		vec[i] = i;
		size[i] = 1;					INTIONALLY THE SIZE OF EVERY INDIVISUAL IS SET TO BE 1;
	}
}


FIND FUNCTION WILL BE SAME AS IT IS...
BUT THE UNION FUNCTION WILL BE SLIGHTLY MODIFIED............................size



void Waighted-Union(vector<int> &vec, int n,int a ,int b){
	int root_a = find(vec,a);
	int root_b = find(vec,b);

	if(size[root_a] < size[root_b]){
		vec[root_b] = vec[root_a];
		siz[root_b] += size[root_a];
	}else{
		vec[root_b] = vec[root_a];
		vec[root_b] += vec[root_a];
	}

		
}
/*............................................................................................................................*/
								//WAIGHTED UNION WITH PATH COMPRESSION 

vector<int> size(1000000);

vector<int>vec(10000000);


void init_v2(){

	for(int i=0;i<vec.size();i++){
		vec[i] = i;
	}
	for(int i=0;i<size.size();i++){
		size[i] = 1;
	}
}

	
int root_with_path_compression(int i){

	while(vec[i] != i){
		vec[i] = vec[vec[i]];
		i = vec[i];

	}

	return i;
}


void Waighted-Union(vector<int> &vec, int n,int a ,int b){
	int root_a = root_with_path_compression(a);
	int root_b = root_with_path_compression(b);

	if(size[root_a] < size[root_b]){
		vec[root_a] = vec[root_b];
		siz[root_b] += size[root_a];
	}else{
		vec[root_b] = vec[root_a];
		vec[root_a] += vec[root_b];
	}
}




		


