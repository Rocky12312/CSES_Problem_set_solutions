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

void solve(string s){
	int n = s.length();
	int* arr_odd = new int[n];
	int left = 0;
	int right = -1;
	for(int i=0;i<n;i++){
		int k;
		if(i>right){
			k = 1;
		}else{
			k = min(arr_odd[left+right-i],right-i+1);
		}
		while(i-k>=0 && i+k<n && s[i-k]==s[i+k]){
			k++;
		}
		arr_odd[i]=k--;
		if(i+k>right){
			left = i-k;
			right = i+k;
		}
	}
	int* arr_even = new int[n];
	left = 0;
	right = -1;
	for(int i=0;i<n;i++){
		int k;
		if(i>right){
			k = 0;
		}else{
			k = min(arr_even[left+right-i+1],right-i+1);
		}
		while(i-k-1>=0 && i+k<n && s[i-k-1]==s[i+k]){
			k++;
		}
		arr_even[i]=k--;
		if(i+k>right){
			left = i-k-1;
			right = i+k;
		}
	}	
	int l_pos = -1;
	int r_pos = -1;
	int len = -1;
	for(int i=0;i<n;i++){
		if(2*arr_odd[i]-1>=len){
			len = 2*arr_odd[i]-1;
			l_pos = i-(arr_odd[i]-1);
			r_pos = i+(arr_odd[i]-1);
		}
		if(2*arr_even[i]>=len){
			len = 2*arr_even[i];
			l_pos = i-1-(arr_even[i]-1);
			r_pos = i+(arr_even[i]-1);
		}
	}
	cout<<s.substr(l_pos,(r_pos-l_pos+1))<<endl;
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin>>s;
  solve(s);
  return 0;
  
}