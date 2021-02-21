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

void solve(int n,int insertion_time,int removal_time,int copy_time){
	int nx[n+2];
	for(int i=0;i<n+1;i++){
		nx[i] = 99999;
	}
	nx[0] = 0;
	nx[1] = insertion_time;
	for(int i=2;i<=n;i++){
		if(nx[i]>nx[i-1]+1){
			nx[i] = 1+nx[i-1];
		}
		if((i+1%2)==0){
			nx[i+1] = copy_time+nx[i+1-(i+1)/2];
			if(removal_time+nx[i+1]<nx[i]){
				nx[i] = removal_time+nx[i+1];
			}
		}
		if(i%2==0){
			if(nx[i-(i/2)]+copy_time<nx[i]){
				nx[i] = nx[i-(i/2)]+copy_time;
			}
		}
	}
	cout<<nx[n]<<endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;cin>>n;
  int insertion_time,removal_time,copy_time;
  cin>>insertion_time>>removal_time>>copy_time;
  solve(n,insertion_time,removal_time,copy_time);
  return 0;
}

