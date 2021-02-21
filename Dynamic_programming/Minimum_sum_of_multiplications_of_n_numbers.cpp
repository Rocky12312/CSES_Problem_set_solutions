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
const int sz = 1e3;

int find_sum(int i,int j,int arr[]){
	int sum = 0;
	for(int p=i;p<=j;p++){
		sum = (sum+arr[p])%100;
	}
	return sum;
}

int solve(int i,int j,int arr[],int nx[][sz]){
	if(nx[i][j]!=-1){
		return nx[i][j];
	}
	if(i==j){
		return 0;
	}
	int res = INT_MAX;
	for(int k=i;k<j;k++){
		int left;
		int right;
		if(nx[i][k]!=-1){
			left = nx[i][k];
		}else{
			left = solve(i,k,arr,nx);
			nx[i][k] = left;
		}
		if(nx[k+1][j]!=-1){
			right = nx[k+1][j];
		}else{
			right = solve(k+1,j,arr,nx);
			nx[k+1][j] = right;
		}
		int lr_sum = find_sum(i,k,arr);
		int rr_sum = find_sum(k+1,j,arr);
		res = min(res,left+right+lr_sum*rr_sum);
	}
	return nx[i][j] = res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
  	cin>>arr[i];
  }
  int nx[sz][sz];
  for(int i=0;i<sz;i++){
  	for(int j=0;j<sz;j++){
  		if(i==j){
  			nx[i][j] = 0;
  		}else{
  			nx[i][j] = -1;
  		}
  	}
  }
  int res = solve(0,n-1,arr,nx);
  cout<<res<<endl;
  return 0;
}
