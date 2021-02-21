#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
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

bool check_all_digits_different(ll num){
  string s = to_string(num);
  for(int i=1;i<s.length();i++){
    if(s[i]==s[i-1]){
      return false;
    }
  }
  return true;
}

void solve(ll a,ll b){
  ll count_edges = 0;
  ll last_da = a%10;
  ll new_a = a+(10-last_da);
  for(ll i=a;i<new_a;i++){
    if(check_all_digits_different(i)){
      count_edges++;
    }
  }
  ll last_db = b%10;
  ll new_b = b-last_db;
  for(ll i=new_b+1;i<=b;i++){
    if(check_all_digits_different(i)){
      count_edges++;
    }
  }
  string snew_a = to_string(new_a);
  string snew_b = to_string(new_b);
  ll fd_a = snew_a[0];
  ll fd_b = snew_b[0];
  for(ll i=fd_a+1;i<=fd_b-1;i++){
    for(ll j=snew_a.length()-1;j<snew_b.length();j++){
      count_edges = count_edges+pow(9,j);
    }
  }
  ll num1 = fd_a;
  ll count_a = 9-(snew_a[1]-'0');
  for(ll i=2;i<snew_b.length();i++){
    count_a = count_a*9;
  }
  ll num2 = fd_b;
  ll count_b = (snew_b[1]-'0')+1;
  for(ll i=2;i<snew_b.length();i++){
    count_b = count_b*9;
  }
  count_edges = count_edges+count_a+count_b;
  cout<<count_edges<<endl;
  return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll a,b;
  cin>>a>>b;
  solve(a,b);
  return 0;
}