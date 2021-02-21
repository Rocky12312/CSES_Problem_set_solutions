#include<iostream>
#include<algorithm>
#include<vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken 9999999
using namespace std;

void solve(int n,int arr[]){
	int sum = 0;
	for(int i=0;i<n;i++){
		sum = sum+arr[i];
	}
	if(sum%2!=0){
		cout<<0<<endl;
		return;
	}
	int par = sum/2;
	int nx[n+1][par+1];
	for(int i=0;i<n+1;i++){
		for(int j=0;j<par+1;j++){
			if(i==0){
				nx[i][j] = 0;
			}else if(j==0){
				nx[i][j] = 1;
			}
		}
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<par+1;j++){
			if(arr[i-1]<=j){
				nx[i][j] = nx[i-1][j] + nx[i-1][j-arr[i-1]];
				nx[i][j] = nx[i][j]%Mod;
			}else{
				nx[i][j] = nx[i-1][j];
				nx[i][j] = nx[i][j]%Mod;
			}
		}
	}
	cout<<nx[n][par]<<endl;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
    	arr[i] = i+1;
    }
    solve(n,arr);
    return 0;
}


/*#include<iostream>
using namespace std;
int mod=1000000007;

int main()
{
    int n;
    cin>>n;
    int sum=n*(n+1)/2;
    if((sum%2)!=0)
    {
        cout<<0;
    }
    else
    {
        int t=(sum/2);
        long long dp[n+1][t+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=t;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=0;
                }
                else if(i==0)
                {
                    dp[i][j]=0;
                }
                else if(j==0)
                {
                    dp[i][j]=1;
                }
                else if(j>=i)
                {
                    dp[i][j]=((dp[i-1][j])+(dp[i-1][j-i]));
                    dp[i][j] = dp[i][j]%mod;
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                    dp[i][j] = dp[i][j]%mod;
                }
            }
        }
        cout<<(dp[n][t]/2);
        
        
    }
}*/