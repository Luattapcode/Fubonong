/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define TASK "PITLAND"
#define openfile if(fopen(TASK".inp","r")) {freopen(TASK".inp", "r", stdin); freopen(TASK".out", "w", stdout);}
using namespace std;
/*Khai Bao*/
const long long inf=1e18;
const int LO=17;
const int CH=27;
const int N=1e5+5;
struct bg{
	ll x;
	ll y;
	ll z;
};
int n,m;
bool cmp(bg u,bg v)
{
	return u.z>v.z;
}
bool check[N];
int h[N];
int t[N][LO+2];
vector <bg> g[N];
int mi[N][LO+2];
bg e[N];
int f[N];
/*END*/
void doc()
{
	cin>>n>>m;
	fr(i,1,m)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		e[i]={x,y,z};
	}
	sort(e+1,e+m+1,cmp);
}
namespace sub1
{
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
	int goc(int x)
	{
		while(f[x]>0) x=f[x];
		return x;
	}
	int lcadodaicanh(int u,int v)
	{
		int x=1e9;
		if(h[u]<h[v]) swap(u,v);
		frd(j,log2(n),0)
		{
			if(h[t[u][j]]>=h[v] and h[t[u][j]]>0)
			{
				x=min(x,mi[u][j]);
				u=t[u][j];
			}
		}
		if(u==v) return x;
		frd(j,log2(n),0)
		{
			if(t[u][j]!=t[v][j])
			{
				x=min({x,mi[u][j],mi[v][j]});
				u=t[u][j];
				v=t[v][j];
			}
		}
		if(u!=v) return min({x,mi[u][0],mi[v][0]});
		return x; 
	}
	void dfs(int x,int p)
	{
		for(auto v:g[x])
		{
			int id=v.x;
			int ts=v.y;
			if(id==p) continue;
			t[id][0]=x;
			h[id]=h[x]+1;
			mi[id][0]=ts;
			dfs(id,x);
		}
	}
	void xuly()
	{
		fr(i,1,n) f[i]=-1;
		int sl=0;
		fr(i,1,m)
		{
			int r1=goc(e[i].x);
			int r2=goc(e[i].y);
			if(r1!=r2)
			{
				hn(r1,r2);
				check[i]=1;
				g[e[i].x].pb({e[i].y,e[i].z,e[i].x});
				g[e[i].y].pb({e[i].x,e[i].z,e[i].y});
				sl++;
			}
			if(sl==n-1) break;
		}
		t[1][0]=1;
		mi[1][0]=1e9;
		fr(i,1,n) h[i]=1;
		fr(i,1,n)
		{
			fr(j,0,log2(n))
			{
				mi[i][j]=1e9;
			}
		}
		dfs(1,0);
		fr(j,1,log2(n))
		{
			fr(i,1,n)
			{
				t[i][j]=t[t[i][j-1]][j-1];
				mi[i][j]=min(mi[i][j-1],mi[t[i][j-1]][j-1]);
			}
		}
		int res=0;
		fr(i,1,m)
		{
			if(check[i]) continue;
			int x=lcadodaicanh(e[i].x,e[i].y);
			res+=abs(x-e[i].z);
		}
		cout<<res;
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
	sub1::xuly();
	time();
}
/*
	Name of problem:
	Copyright: Luattapcode
	Author: Huynh Quoc Luat
*/

















