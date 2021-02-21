#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
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

//Jump game O(n^2)
void solve(int n,ll arr[]){
	if(arr[0]==0){
		cout<<"Can't reach"<<endl;
		return;
	}
	ll min_jmp[n];
	for(int i=0;i<n;i++){
		min_jmp[i] = INT_MAX;
	}
	min_jmp[0] = 0;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(min_jmp[j]!=INT_MAX && (arr[j]>=(i-j)) && (min_jmp[i]>1+min_jmp[j])){
				min_jmp[i] = min_jmp[j]+1;
				break;
			}
		}
	}
	cout<<min_jmp[n-1]<<endl;
	return;
}

//https://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/
void solve1(int n,int arr[]){
	if(arr[0]==0){
		cout<<"Can't reach"<<endl;
		return;
	}
	int max_reach = arr[0];
	int min_jmps = 1;
	int steps_rem = arr[0];
	for(int i=1;i<n;i++){
		if(i==n-1){
			cout<<min_jmps<<endl;
			return;
		}
		max_reach = max(max_reach,i+arr[i]);
		steps_rem--;
		if(steps_rem==0){
			min_jmps++;
			if(max_reach<=i){
				cout<<"Can't reach"<<endl;
				return;
			}
			steps_rem = max_reach-i;
		}
	}
	cout<<"Can't reach"<<endl;
	return;
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
  solve(n,arr);
  return 0;
}
