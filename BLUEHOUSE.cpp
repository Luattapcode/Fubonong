/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define fi first
#define se second
#define TASK "BLUEHOUSE"
#define openfile if(fopen(TASK".inp","r")) {freopen(TASK".inp", "r", stdin); freopen(TASK".out", "w", stdout);}
using namespace std;
template <class X, class Y>
	bool minimize(X &x, const Y &y) {
		if (x > y) {
			x = y;
			return true;
		} else return false;
	}

template <class X, class Y>
	bool maximize(X &x, const Y &y) {
		if (x < y) {
			x = y;
			return true;
		} else return false;
	}
/*Author: Huynh Quoc Luat*/
/*Khai Bao*/
const long long inf=1e18;
const int LO=17;
const int CH=27;
const int N=1e5+5;
int n,m;
stack <int> st;
int cnt=0;
vector <int> g[N];
int low[N];
int num[N];
int p[N];
bool check[N];
int cau=0;
int lt=0;
int out[N];
struct bg{
	int x;
	int y;
};
bg a[N];
int tp[N];
/*END*/
void doc()
{
	cin>>n>>m;
	fr(i,1,m)
	{
		cin>>a[i].x>>a[i].y;
		g[a[i].x].pb(a[i].y);
		g[a[i].y].pb(a[i].x);
	}
}
namespace sub1
{
	void dfs(int x)
	{
		low[x]=num[x]=++cnt;
		for(auto v:g[x])
		{
			if(v==p[x]) continue;
			if(num[v]!=0) low[x]=min(low[x],num[v]);
			else 
			{
				p[v]=x;
				dfs(v);
				if(low[v]>num[x])
				{
					cau++;
				}
				low[x]=min(low[x],low[v]);
			}
		}
	}
	void xuly()
	{
		fr(i,1,n)
		{
			if(!num[i]) dfs(i);
		}
		if(cau==1)
		{
			cout<<1;
			return;
		}
		else 
		{
			if(cau%2==0) cout<<cau/2;
			else cout<<cau/2+1;
			return;
		}
	}
}
namespace sub2
{
	void tarjan(int x)
	{
		st.push(x);
		low[x]=num[x]=++cnt;
		for(auto v:g[x])
		{
			if(v==p[x]) continue;
			if(check[v]) continue;
			if(num[v]!=0) low[x]=min(low[x],num[v]);
			else 
			{
				p[v]=x;
				tarjan(v);
				low[x]=min(low[x],low[v]);
			}
		}
		int k;
		if(low[x]==num[x])
		{
			lt++;
			do{
				k=st.top();
				st.pop();
				check[k]=1;
				tp[k]=lt;
			} while(k!=x);
		}
	}
	void dfs(int x,int p)
	{
		for(auto v:g[x])
		{
			if(v==p) continue;
			out[v]++;
			out[x]++;
			dfs(v,x);
		}
	}
	void xuly()
	{
		fr(i,1,n) if(!num[i]) tarjan(i);
		fr(i,1,n) g[i].clear();
		fr(i,1,m)
		{
			int r1=tp[a[i].x];
			int r2=tp[a[i].y];
			if(r1!=r2)
			{
				g[r1].pb(r2);
				g[r2].pb(r1);
			}
		}
		dfs(1,0);
		int res=0;
		fr(i,1,lt)
		{
			res+=(out[i]==1);
		}
		cout<<res/2 +(res%2==0?0:1);
	}
}
void time()
{
	cerr<< endl<<"Luattapcode: "<<clock()<<"ms"<<endl;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	openfile
	//freopen(TASK".INP", "r", stdin);
	//freopen(TASK".OUT", "w", stdout);
	doc();
	sub2::xuly();
	time();
}



















