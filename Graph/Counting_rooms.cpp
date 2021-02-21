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

const int sz = 1e3+10;

void solve_helper(int n,int m,int i,int j,bool arr[][sz]){
	if(i<0 || i>=n || j<0 || j>=m || arr[i][j]==0){
		return;
	}
	arr[i][j] = 0;
	solve_helper(n,m,i-1,j,arr);
	solve_helper(n,m,i+1,j,arr);
	solve_helper(n,m,i,j-1,arr);
	solve_helper(n,m,i,j+1,arr);
	return;
}

void solve(int n,int m,bool arr[][sz]){
	int rooms = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==1){
				rooms++;
				solve_helper(n,m,i,j,arr);
			}
		}
	}
	cout<<rooms<<endl;
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;
  cin>>n>>m;
  bool arr[sz][sz];
  for(int i=0;i<n;i++){
  	string temp;
  	cin>>temp;
  	for(int j=0;j<n;j++){
  		if(temp[j]=='.'){
  			arr[i][j] = 1;
  		}else if(temp[j]=='#'){
  			arr[i][j] = 0;
  		}
  	}
  }
  solve(n,m,arr);
  return 0;
}