/*#include<iostream>
#include<algorithm>
#include<vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken -9999999
using namespace std;

void solve(int n,int& count){
	if(n<0){
		return;
	}
	if(n == 0){
		count = count+1;
		return;
	}
	for(int i=1;i<=6;i++){
		solve(n-i,count);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int count = 0;
    solve(n,count);
    cout<<count<<endl;
    return 0;
}*/

/*#include <bits/stdc++.h>
using namespace std;

int main() {
  int mod = 1e9+7;
  int n;
  cin >> n;
  vector<int> dp(n+1,0);
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 6 && i-j >= 0; j++) {
      (dp[i] += dp[i-j]) %= mod;
    }
  }
  cout << dp[n] << endl;
}*/

#include<iostream>
#include<algorithm>
#include<vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken -9999999
using namespace std;

void solve(int x,int arr[]){
  int nx[x+1];
  for(int i=0;i<x+1;i++){
    nx[i] = 0;
  }
  nx[0] = 1;
  for(int i=1;i<x+1;i++){
    for(int j=0;j<6;j++){
      if(i>=arr[j]){
        nx[i] = nx[i]+nx[i-arr[j]];
        nx[i] = nx[i]%Mod;
      }
    }
  }
  cout<<nx[x]<<endl;
  return;
}

int main(){
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int x;
  cin>>x;
  int arr[6];
  for(int i=0;i<6;i++){
    arr[i] = i+1;
  }
  solve(x,arr);
  return 0;
}
