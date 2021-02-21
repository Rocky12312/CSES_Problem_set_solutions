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

int* generate_zarray(string s){
	int n = s.length();
	int* zarray = new int[n];
	zarray[0] = 0;
	int left = 0;
	int right = 0;
	for(int i=1;i<n;i++){
		if(i>right){
			left = i;
			right = i;
			while(right<n && s[right-left]==s[right]){
				right++;
			}
			zarray[i] = right-left;
			right--;
		}else{
			int hig_prev_match_idx = i-left;
			if(zarray[hig_prev_match_idx]<(right-i+1)){
				zarray[i] = zarray[hig_prev_match_idx];
			}else{
				left = i;
				while(right<n && s[right-left]==s[right]){
					right++;
				}
				zarray[i] = right-left;
				right--;
			}
		}
	}
	return zarray;
}

void solve(string txt,string patt){
	int* arr = generate_zarray(patt+'$'+txt);
	int len = txt.length()+1+patt.length();
	for(int i=0;i<len;i++){
		cout<<arr[i]<<endl;
	}
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string txt;
  string patt;
  cin>>txt>>patt;
  solve(txt,patt);
  return 0;
}
