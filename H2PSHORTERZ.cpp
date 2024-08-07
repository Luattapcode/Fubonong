/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define TASK data
using namespace std;
namespace sub1
{
	const int N=1e6+5;
	ll n,q;
	ll p[N];
	ll P[N][17];
	vector <ll> g[N];
	ll h[N];
	ll dem=0;
	void doc()
	{
		cin>>n>>q;
		fr(i,1,n-1)
		{
			ll u,v;
			cin>>u>>v;
			g[u].pb(v);
			g[v].pb(u);
		}
	}
	void dfs(ll x,ll p)
	{
		dem++;
		h[x]=dem;
		for(auto v:g[x])
		{
			if(v==p) continue;
			dfs(v,x);
		}
	}
	void dfs(ll x)
	{
		for(auto v:g[x])
		{
			if(v==p[x]) continue;
			h[v]=h[x]+1;
			p[v]=x;
			dfs(v);
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
	else return p[u];
}
ll dist(ll x,ll y)
{
	return h[x]+h[y]-2*h[LCA(x,y)];
}
	void xuly()
	{
	dfs(1);
	p[1]=1;
	fr(i,1,n) P[i][0]=p[i];
	fr(j,1,log2(n))
	{
		fr(i,1,n)
		{
			P[i][j]=P[P[i][j-1]][j-1];
		}
	}
	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		ll cnt=0;
		fr(i,1,n-1)
		{
			fr(j,i+1,n)
			{
				ll kc=dist(i,j);
				ll mx=dist(i,x);
				ll my=dist(i,y);
				ll nx=dist(j,x);
				ll ny=dist(j,y);
				ll res=0;
				if(mx+ny+1<kc) res=1;
				if(my+nx+1<kc) res=1;
				if(res==1) cnt++;
			}
		}
	}
	}
}
namespace sub2
{
	void doc()
	{

	}
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
//	freopen(TASK".INP", "r", stdin);
//	freopen(TASK".OUT", "w", stdout);
	sub1::doc();
	time();
}
/*
	Name of problem:H2PSHORTER
	Copyright: Luattapcode 
	Author: Huynh Quoc Luat
	Description: LCA 
*/









