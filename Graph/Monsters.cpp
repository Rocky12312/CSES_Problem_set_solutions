/*#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
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
const int sz = 10000;
using namespace std;

struct node{
	int a;
	int b;
};

bool is_valid(int n,int m,int x,int y,bool cannot_visit[][sz],bool visit[][sz]){
	if(x<0 || x>=n || y<0 || y>=m || cannot_visit[x][y]==0 || visit[x][y]==true){
		return false;
	}
	return true;
}

void solve(int n,int m,char arr[][sz],char temp_arr[][sz],bool cannot_visit[][sz],bool visit[][sz],int x_idx,int y_idx){
	queue<node> q;
	q.push({x_idx,y_idx});
	while(q.empty()==false){
		node temp = q.front();
		q.pop();
		if(temp.a == 0 || temp.a == n || temp.b ==0 || temp.b == m){
			cout<<"YES"<<endl;
			string res;
			while(temp.a!=x_idx || temp.b!=y_idx){
				res = res+temp_arr[temp.a][temp.b];
				if(temp_arr[temp.a][temp.b]=='U'){
					temp.a++;
				}else if(temp_arr[temp.a][temp.b]=='D'){
					temp.a--;
				}else if(temp_arr[temp.a][temp.b]=='R'){
					temp.b--;
				}else if(temp_arr[temp.a][temp.b]=='L'){
					temp.b++;
				}
			}
			reverse(res.begin(),res.end());
			cout<<res.size()<<endl;
			cout<<res<<endl;
			exit(0);
		}
		if(is_valid(n,m,temp.a+1,temp.b,cannot_visit,visit)){
			visit[temp.a+1][temp.b] = true;
			temp_arr[temp.a+1][temp.b] = 'U';
			q.push({temp.a+1,temp.b});
		}
		if(is_valid(n,m,temp.a-1,temp.b,cannot_visit,visit)){
			visit[temp.a-1][temp.b] = true;
			temp_arr[temp.a-1][temp.b] = 'L';
			q.push({temp.a-1,temp.b});
		}
		if(is_valid(n,m,temp.a,temp.b+1,cannot_visit,visit)){
			visit[temp.a][temp.b+1] = true;
			temp_arr[temp.a][temp.b+1] = 'R';
			q.push({temp.a,temp.b+1});
		}
		if(is_valid(n,m,temp.a,temp.b-1,cannot_visit,visit)){
			visit[temp.a][temp.b-1] = true;
			temp_arr[temp.a][temp.b-1] = 'L';
			q.push({temp.a,temp.b-1});
		}
	}
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;
  cin>>n>>m;
  char arr[sz][sz];
  char temp_arr[sz][sz];
  bool cannot_visit[sz][sz];
  bool visit[sz][sz];
  string s;
  int x_idx=-1;
  int y_idx=-1;
  for(int i=0;i<n;i++){
  	cin>>s;
  	for(int j=0;j<m;j++){
  		if(s[j]=='#' || s[j]=='M'){
  			cannot_visit[i][j] = 0;
  		}else{
  			cannot_visit[i][j] = 1;
  		}
  		if(s[j]=='A'){
  			x_idx = i;
  			y_idx = j;
  		}
  		arr[i][j] = s[j];
  	}
  }
  for(int i=0;i<n;i++){
  	for(int j=0;j<m;j++){
  		visit[i][j] = false;
  		if((i+1<n && arr[i+1][j]=='M') || (i-1>=0 && arr[i-1][j]=='M') || (j+1<m && arr[i][j+1]=='M') || (j-1>=0 && arr[i][j-1]=='M')){
  			cannot_visit[i][j] = 0;
  		}
  	}
  }
  solve(n,m,arr,temp_arr,cannot_visit,visit,x_idx,y_idx);
  cout<<"NO"<<endl;
  return 0;
}*/


#include<bits/stdc++.h>
using namespace std;
 
#define ff first
#define ss second
#define int long long
#define pb push_back
#define pii pair< int,int >
#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
 
const int nax = 1e3+10;
char c[nax][nax];
int n, m;
 
struct node
{
    int x,y,d;
    bool operator!=( node const &p1 ) const{
        return !(p1.x == x && p1.y == y && p1.d == d);
    }
};
 
bool ok(int x,int y)
{
    if( x >= 0 && x<n && y>=0 && y<m)
        return 1;
    return 0;
}
bool check(node p )
{
    int mx = p.d;
    p.d = 0;
    queue< node > q;
    q.push(p);
    bool vis[n][m];
    memset(vis,0,sizeof(vis));
    
    while( !q.empty() )
    {
        p = q.front();
        q.pop();
        vis[p.x][p.y] = 1;
        if( p.d == mx ) continue;
        if( ok(p.x-1,p.y) && !vis[p.x-1][p.y] )
        {
            if( c[p.x-1][p.y] == 'M' ) return 0;
            if( c[p.x-1][p.y] == '.' ) q.push( {p.x-1,p.y,p.d+1});
        }
        
        if( ok(p.x,p.y-1) && !vis[p.x][p.y-1] )
        {
            if( c[p.x][p.y-1] == 'M' ) return 0;
            if( c[p.x][p.y-1] == '.' ) q.push( {p.x,p.y-1,p.d+1});
        }
        
        if( ok(p.x+1,p.y) && !vis[p.x+1][p.y] )
        {
            if( c[p.x+1][p.y] == 'M' ) return 0;
            if( c[p.x+1][p.y] == '.' ) q.push( {p.x+1,p.y,p.d+1});
        }
        
        if( ok(p.x,p.y+1) && !vis[p.x][p.y+1] )
        {
            if( c[p.x][p.y+1] == 'M' ) return 0;
            if( c[p.x][p.y+1] == '.' ) q.push( {p.x,p.y+1,p.d+1});
        }
    }
    return 1;
}
signed main()
{
    fast;
    cin >> n >> m;
    node st;
    for(int i=0; i<n; i++ )
    {
        for(int j=0;j<m; j++ )
        {
            cin >> c[i][j]; 
            if( c[i][j] == 'A' ) 
                st.x = i , st.y = j , st.d = 0;
        }
    }
    //cout << st.x << " " << st.y << " " << st.d << "\n";
    queue< node > q;
    q.push(st);
    bool vis[n][m];
    pii par[n][m];
    memset(vis,0,sizeof(vis));
    while( !q.empty() )
    {
        node p = q.front();
        //cout << p.x << " " << p.y << " " << p.d << "\n";
        q.pop();
        vis[p.x][p.y] = 1;
        
        if( (p.x == 0 || p.y == 0 || p.x == n-1 || p.y == m-1 ) && check( p ) ) 
        {
            cout << "YES\n" << p.d << "\n";
            stack<char> s;
         
            while( p != st )
            {
                pii cur = { p.x,  p.y };
                if( p.x > par[p.x][p.y].ff ) s.push('D');
                else if( p.x < par[p.x][p.y].ff ) s.push('U');
                else if( p.y > par[p.x][p.y].ss ) s.push('R');
                else  s.push('L');
                p.x = par[cur.ff][cur.ss].ff;
                p.y = par[cur.ff][cur.ss].ss;
                p.d--;
            }
            while( !s.empty() )
            {
                cout << s.top() ;
                s.pop();
            }
            return 0;
        }
        
        if( ok(p.x-1,p.y) && !vis[p.x-1][p.y] )
        {
            //if( c[p.x-1][p.y] == 'M' ) return 0;
            if( c[p.x-1][p.y] == '.' ) q.push( {p.x-1,p.y,p.d+1}), par[p.x-1][p.y] = {p.x,p.y};
        }
        
        if( ok(p.x,p.y-1) && !vis[p.x][p.y-1] )
        {
            //if( c[p.x][p.y-1] == 'M' ) return 0;
            if( c[p.x][p.y-1] == '.' ) q.push( {p.x,p.y-1,p.d+1}), par[p.x][p.y-1] = {p.x,p.y};
        }
        
        if( ok(p.x+1,p.y) && !vis[p.x+1][p.y] )
        {
            //if( c[p.x+1][p.y] == 'M' ) return 0;
            if( c[p.x+1][p.y] == '.' ) q.push( {p.x+1,p.y,p.d+1}), par[p.x+1][p.y] = {p.x,p.y};
        }
        
        if( ok(p.x,p.y+1) && !vis[p.x][p.y+1] )
        {
            //if( c[p.x][p.y+1] == 'M' ) return 0;
            if( c[p.x][p.y+1] == '.' ) q.push( {p.x,p.y+1,p.d+1}), par[p.x][p.y+1] = {p.x,p.y};
        }
    }
    cout << "NO";
}
