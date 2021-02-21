#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken 9999999
using namespace std;

 
int count_ways(int n, int m) {  
	int count[n + 1]; 
	count[0] = 0; 
	for (int i = 1; i <= n; i++) { 
		if (i > 2) 
			count[i] = count[i - 1] + count[i - 2]; 
		else if (i < 2 || i == 1) 
			count[i] = 1; 
		else
			count[i] = 2; 
	}
	return count[n]; 
} 

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int res = count_ways(n,m);
    cout<<res<<endl;
	return 0; 
} 
