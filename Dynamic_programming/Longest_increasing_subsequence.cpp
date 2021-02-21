#include<iostream>
#include<algorithm>
#include<vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken 9999999
#define INT_MAX +2147483647
#define INT_MIN -2147483648
using namespace std;

void solve(int n,int arr[]){
	vector<int> v;
	for(int i=0;i<n;i++){
		auto it = lower_bound(v.begin(),v.end(),arr[i]);
		if(it==v.end()){
			v.push_back(arr[i]);
		}else{
			*it = arr[i];
		}
	}
	cout<<v.size()<<endl;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    solve(n,arr);
    return 0;
}