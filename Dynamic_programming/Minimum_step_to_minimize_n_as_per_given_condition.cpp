#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<unordered_map>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define int_ran_lag_num 99999
#define Mod 1000000007
#define INT_MAX +2147483647
#define INT_MIN -2147483648
#define ulmax 4294967295
#define llmin -9223372036854775808
#define llmax 9223372036854775807
#define ullmax 18446744073709551615 
using namespace std;
const int sz = 1e6;

int solve(int n,int nx[]){
	if(nx[n]!=-1){
		return nx[n];
	}
	if(n<=0){
		return int_ran_lag_num;
	}
	if(n==1){
		return 0;
	}
	int res = INT_MAX;
	if(n%2==0){
		res = min(res,1+solve(n/2,nx));
	}
	if(n%3==0){
		res = min(res,1+solve(n/3,nx));
	}
	res = min(res,1+solve(n-1,nx));
	return nx[n] = res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;cin>>n;
  int nx[sz];
  memset(nx,-1,sizeof(nx));
  int res = solve(n,nx);
  cout<<res<<endl;
  return 0;
}

