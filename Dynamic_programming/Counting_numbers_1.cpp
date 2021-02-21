#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstring>
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

ll nx[20][10][2][2];

ll solve(string& num,int n,int x,bool leading_zeros,bool tight){
  if(n==0){
    return 1;
  }
  if(x!=-1 && nx[n][x][leading_zeros][tight]!=-1){
    return nx[n][x][leading_zeros][tight];
  }
  int lb = 0;
  int ub = tight ? (num[num.length()-n]-'0') :9;
  ll answer = 0;
  for(ll dig=lb;dig<=ub;dig++){
    if(dig==x && leading_zeros==0){
      continue;
    }
    answer = answer+solve(num,n-1,dig,(leading_zeros & dig==0),tight & (dig==ub));
  }
  return nx[n][x][leading_zeros][tight] = answer;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll a,b;
  cin>>a>>b;
  string A = to_string(a-1);
  string B = to_string(b);
  memset(nx,-1,sizeof(nx));
  ll res1 = solve(B,B.length(),-1,1,1);
  memset(nx,-1,sizeof(nx));
  ll res2 = solve(A,A.length(),-1,1,1);
  ll res = res1-res2;
  cout<<res<<endl;
  return 0;
}