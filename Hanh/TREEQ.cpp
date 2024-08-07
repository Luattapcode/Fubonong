#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
using namespace std;
namespace sub1
{
	ll n;
	ll q;
	const int N=1e5+5;
	vector <ll> g[N];
	ll p[N];
	ll P[N][17];
	ll h[N];
	void doc()
	{
		cin>>n;
		fr(i,1,n-1)
		{
			ll u,v;
			cin>>u>>v;
			g[u].pb(v);
			g[v].pb(u);
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
	void dfs(ll x)
	{
		for(auto v:g[x])
		{
			if(v==p[x]) continue;
			p[v]=x;
			h[v]=h[x]+1;
			dfs(v);
		}
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
	cin>>q;
	while(q--)
	{
		ll x,y,u,v,val;
		cin>>x>>y>>u>>v>>val;
		ll res=0;
		if(dist(u,v)%2==val%2 and dist(u,v)<=val ) res=1;
		if((dist(u,x)+dist(v,y)+1)%2==val%2 and dist(u,x)+dist(v,y)+1<=val  ) res=1;
		if((dist(u,y)+dist(v,x)+1)%2==val%2 and dist(u,y)+dist(v,x)+1<=val ) res=1;
		cout<<res;
		cout<<'\n';
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
	cerr<< endl<<"Time: "<<clock()<<"ms"<<endl;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen(".INP", "r", stdin);
	//freopen(".OUT", "w", stdout);
	sub1::doc();
	sub1::xuly();
	time();
}






