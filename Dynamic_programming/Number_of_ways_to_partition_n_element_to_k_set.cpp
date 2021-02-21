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
const int sz = 1000;

void solve(ll n,ll k){
  ll nx[n+1][k+1];
  for(int i=0;i<n+1;i++){
    nx[i][0] = 0;
  }
  for(int j=0;j<k+1;j++){
    nx[0][j] = 0;
  }
  for(int i=1;i<n+1;i++){
    for(int j=1;j<k+1;j++){
      if(j==1 || j==i){
        nx[i][j] = 1;
      }else{
        nx[i][j] = j*nx[i-1][j]+nx[i-1][j-1];
      }
    }
  }
  cout<<nx[n][k]<<endl;
  return;
}

/*ll solve_recursive(ll n,ll k){
	if(n==0 || k==0 || k>n){
		return 0;
	}
	if(k==1 || k==n){
		return 1;
	}
	return k*solve(n-1,k)+solve(n-1,k-1);
}*/

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n;
  ll k;
  cin>>n>>k;
  solve(n,k);
  return 0;
}
