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

ll comp(ll a,ll b){
	if(a>b){
		return b;
	}
	return a;
}

void solve(ll n,ll k) { 
    ll P[n + 1][k + 1]; 
    for (int i = 0; i <= n; i++) { 
        for (int j = 0; j<=comp(i,k);j++) { 
            if (j == 0) 
                P[i][j] = 1; 
            else
                P[i][j] = P[i-1][j]+(j*P[i-1][j-1]); 
            P[i][j+1] = 0; 
        } 
    } 
    cout<<P[n][k]<<endl;
    return; 
} 

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n,k;
  cin>>n>>k;
  solve(n,k);
  return 0;
}
