#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
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

void solve(ll n){
	ll nx[n+1][n+1];
	nx[0][0] = 1;
	for(int i=1;i<n+1;i++){
		nx[i][0] = nx[i-1][i-1];
		for(int j=1;j<=i;j++){
			nx[i][j] = nx[i-1][j-1]+nx[i][j-1];
		}
	}
	cout<<nx[n][0]<<endl;
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n;
  cin>>n;
  solve(n);
  return 0;
}
