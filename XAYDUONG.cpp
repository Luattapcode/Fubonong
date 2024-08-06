/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define fi first
#define se second
#define TASK "XAYDUONG"
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
struct bg{
	ll x;
	ll y;
};
vector <bg> g[N];
int f[N];
vector <int> v;
int lu[N];
int parent[N];
int h[N];
int post1[N];
int post2[N];
int distance[N];
int dp[N];
int P[N][LO];
int n,m;
struct bg1{
	int x;
	int y;
	int z;
	int t;
};
vector <bg1> query;
/*END*/
void doc()
{
	cin>>n>>m;
}
namespace sub1
{
	void dfs(int x,int p)
	{
		for(auto l:g[x])
		{
			int id=l.x;
			int ts=l.y;
			if(id==p) continue;
			dp[id]=dp[x]+ts;
			h[id]=h[x]+1;
			parent[id]=x;
			dfs(id,x);
		}
	}
	int goc(int x)
	{
		while(f[x]>0) x=f[x];
		return x;
	}
	void hn(int r1,int r2)
	{
		int t=f[r1]+f[r2];
		if(abs(f[r1])>abs(f[r2]))
		{
			f[r1]=t;
			f[r2]=r1;
		}
		else 
		{
			f[r1]=r2;
			f[r2]=t;
		}
	}
	ll LCA(ll u,ll v)
	{
	if(h[u]<h[v]) swap(u,v);
	frd(j,log2(n),0)
	{
		if(h[P[u][j]]>0 and h[P[u][j]]>=h[v]) u=P[u][j];
	}
	frd(j,log2(n),0)
	{
		if(P[u][j]!=P[v][j])
		{
			v=P[v][j];
			u=P[u][j];
		}
	}
	if(u==v) return u;
	else return parent[u];
	}
	void xuly()
	{
		int ok=0;
		int dem=0;
		fr(i,1,n) f[i]=-1;
		fr(i,1,m)
		{
			int x;
			int y,z,t;
			cin>>x;
			if(x==1)
			{
				cin>>y>>z>>t;
				int r1=goc(y);
				int r2=goc(z);
				if(r1!=r2)
				{
					hn(r1,r2);
					g[y].pb({z,t});
					g[z].pb({y,t});
				}
			}
			else 
			{
				cin>>y;
				v.pb(y);
			}
		}
		dfs(1,0);
		int res=0;
		int pos1=0;
		int pos2=0;
		fr(i,1,n)
		{
			if(maximize(res,dp[i]))
			{
				pos1=i;
			}
		}
		fr(i,1,n) dp[i]=0;
		dfs(pos1,0);
		res=0;
		fr(i,1,n)
		{
			if(maximize(res,dp[i]))
			{
				pos2=i;
			}
		}
		fr(i,1,n) lu[i]=dp[i];
		fr(i,1,n) dp[i]=0;
		dfs(pos2,0);
		for(auto l:v)
		{
			cout<<max(dp[l],lu[l]);
			cout<<'\n';
		}
	}
	int dist(int u,int v)
	{
		return dp[u]+dp[v]-2*dp[LCA(u,v)];
	}
	void sub2()
	{
		fr(i,1,n) f[i]=-1;
		fr(i,1,m)
		{
			int x,y,z,t;
			cin>>x;
			if(x==1)
			{
				cin>>y>>z>>t;
				query.pb({x,y,z,t});
				int r1=goc(y);
				int r2=goc(z);
				if(r1!=r2)
				{
					hn(r1,r2);
					g[y].pb({z,t});
					g[z].pb({y,t});
				}
			}
			else 
			{
				cin>>y;
				query.pb({x,y,0,0});
			}
		}
		parent[1]=1;
		dfs(1,0);
		fr(i,1,n) P[i][0]=parent[i];
		fr(j,1,log2(n))
		{
			fr(i,1,n)
			{
				P[i][j]=P[P[i][j-1]][j-1];
			}
		}
		fr(i,1,n) g[i].clear();
		fr(i,1,n) f[i]=-1;
		fr(i,1,n)
		{
			post1[i]=post2[i]=i;
		}
		fr(i,0,query.size()-1)
		{
			int x=query[i].x;
			if(x==1)
			{
				int y=query[i].y;
				int z=query[i].z;
				int t=query[i].t;
				int r1=goc(y);
				int r2=goc(z);
				int vt1,vt2;
				if(r1!=r2)
				{
					g[y].pb({z,t});
					g[z].pb({y,t});
					int distxy=dist(post1[goc(y)],post2[goc(y)]);
					int distzt=dist(post1[goc(z)],post2[goc(z)]);
					int distmax1=0;
					int distmax2=0;
					if(dist(y,post1[goc(y)])>dist(y,post2[goc(y)]))
					{
						vt1=post1[goc(y)];
						distmax1=dist(y,post1[goc(y)]);
					}
					else 
					{
						vt1=post2[goc(y)];
						distmax1=dist(y,post2[goc(y)]);
					}
					if(dist(z,post1[goc(z)])>dist(z,post2[goc(z)]))
					{
						vt2=post1[goc(z)];
						distmax2=dist(z,post1[goc(z)]);
					}
					else 
					{
						vt2=post2[goc(z)];
						distmax2=dist(z,post2[goc(z)]);
					}
					if(distxy>distzt and distxy>distmax1+distmax2+t)
					{
						int l1=post1[goc(y)];
						int l2=post2[goc(y)];
						hn(r1,r2);
						post1[goc(y)]=l1;
						post2[goc(y)]=l2;
					}
					else if(distzt>distxy and distzt>distmax1+distmax2+t)
					{
						int l1=post1[goc(z)];
						int l2=post2[goc(z)];
						hn(r1,r2);
						post1[goc(z)]=l1;
						post2[goc(z)]=l2;
					}
					else 
					{
						hn(r1,r2);
						post1[goc(y)]=vt1;
						post2[goc(y)]=vt2;
					}
				}
			}
			else 
			{
				int y=query[i].y;
				cout<<max(dist(post1[goc(y)],y),dist(post2[goc(y)],y));
				cout<<'\n';
			}
		}
	}
}
namespace sub2
{
	void xuly()
	{
		
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
	sub1::sub2();
	time();
}



















