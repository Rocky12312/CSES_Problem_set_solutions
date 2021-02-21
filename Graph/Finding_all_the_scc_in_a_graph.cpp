#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<unordered_map>
#pragma GCC optimize("Ofast")	
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define INT_MAX +2147483647
#define INT_MIN -2147483648
#define ulmax 4294967295
#define llmin -9223372036854775808
#define llmax 9223372036854775807
#define ullmax 18446744073709551615 
using namespace std;
const int sz = 100000;

void solve_helper(int node,int arr[],vector<vector<int>>& v,int disc[],int low[],stack<int>& stk,bool present_in_stack[]){
	static int time = 0;
	disc[node] = time;
	low[node] = time;
	time+=1;
	present_in_stack[node] = true;
	stk.push(node);
	for(int j=0;j<v[node].size();j++){
		if(arr[v[node][j]]==1 && disc[v[node][j]]==-1){
			solve_helper(v[node][j],arr,v,disc,low,stk,present_in_stack);
			low[node] = min(low[node],low[v[node][j]]);
		}else if(present_in_stack[v[node][j]]==true){
			low[node] = min(low[node],disc[v[node][j]]);
		}
	}
	if(low[node]==disc[node]){
		cout<<"One of the scc is : ";
		while(stk.top()!=node){
			cout<<stk.top()<<" ";
			present_in_stack[stk.top()]=false;
			stk.pop();
		}
		cout<<stk.top()<<endl;
		present_in_stack[stk.top()]=false;
		stk.pop();
	}
	return;
}

void solve(int arr[],vector<vector<int>>& v){
	int disc[sz];
	int low[sz];
	stack<int> stk;
	bool present_in_stack[sz];
	memset(disc,-1,sizeof(disc));
	memset(low,-1,sizeof(low)); 
	for(int i=0;i<sz;i++){
		if(arr[i]==1 && disc[i]==-1){
			solve_helper(i,arr,v,disc,low,stk,present_in_stack);
		}
	}
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;cin>>n;
  vector<vector<int>> v(1000);
  int arr[sz];
  memset(arr,0,sizeof(arr));
  int a,b;
  for(int i=0;i<n;i++){
  	cin>>a>>b;
  	arr[a]=1;
  	arr[b]=1;
  	v[a].push_back(b);
  }
  solve(arr,v);
  return 0;
  
}