#include<iostream>
#include<algorithm>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken -9999999
using namespace std;

void solve(int n,int x,int arr[]){
    int count = 0;
    sort(arr,arr+n);
    int i=0;
    int j=n-1;
    while(i<j){
        int child_sum = arr[i]+arr[j];
        if(child_sum>x){
            if(arr[j]<=x){
                count++;
            }
            j--;
        }else if(child_sum<=x){
            count++;
            i++;
            j--;
        }
    }
    if(i==j){
        if(arr[i]<=x){
            count++;
        }
    }
    cout<<count<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    solve(n,x,arr);
    return 0;
}