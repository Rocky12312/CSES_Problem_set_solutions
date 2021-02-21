#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
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
 
void solve_helper(int idx,int n,vector<vector<int>>& v,int color[],bool& op_team){
	for(auto j:v[idx]){
		if(color[j]==color[idx]){
			op_team = true;
			return;
		}else{
			if(color[j]==-1){
				color[j] = 1-color[idx];
				solve_helper(j,n,v,color,op_team);
			}
		}
	}
	return;
}
 
void solve(int n,int m,vector<vector<int>>& v){
	int color[n+1];
	bool op_team = false;
	for(int i=0;i<n+1;i++){
		color[i] = -1;
	}
	for(int i=1;i<n+1;i++){
		if(color[i]==-1){
			color[i] = 0;
			solve_helper(i,n,v,color,op_team);
		}
	}
	if(op_team == true){
		cout<<"IMPOSSIBLE"<<endl;
		return;
	}
	for(int i=1;i<n+1;i++){
		if(color[i]==0){
			cout<<2<<" ";
		}else if(color[i]==1){
			cout<<1<<" ";
		}
	}
	cout<<endl;
	return;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;
  cin>>n>>m;
  vector<vector<int>> v(n+1);
  int a,b;
  for(int i=0;i<m;i++){
  	cin>>a>>b;
  	v[a].push_back(b);
  	v[b].push_back(a);
  }
  solve(n,m,v);
  return 0;
}