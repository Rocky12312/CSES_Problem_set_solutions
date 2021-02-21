#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
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

void solve(int n,int m){
	int nx[n+1];
	memset(nx,0,sizeof(nx));
	nx[0] = 1;
	for(int i=0;i<n+1;i++){
		for(int j=m;j<=i;j++){
			nx[i] += nx[i-j];
		}
	}
	cout<<nx[n]<<endl;
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;cin>>n;
  int m;cin>>m;
  solve(n,m);
  return 0;
}

