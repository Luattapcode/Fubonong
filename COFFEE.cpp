#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
using namespace std;
struct bg{
	ll x;
	ll y;
	ll z;
};
ll n;
ll p[1000005];
ll P[100005][25];
ll f[1000005];
ll h[1000005];
ll cx[1000005];
ll cy[1000005];
ll bx[1000005];
ll by[1000005];
vector <bg> a[1000005];
void doc()
{
	cin>>n;
	fr(i,1,n-1)
	{
		ll x,y,z,t;
		cin>>x>>y>>z>>t;
		a[x].pb({y,z,t});
		a[y].pb({x,z,t});
	}
}
void dfs(ll x)
{
	for(auto v:a[x])
	{
		ll id=v.x;
		if(id==p[x]) continue;
		p[id]=x;
		h[id]=h[x]+1;
		cx[id]=v.y;
		cy[id]=v.z;
		dfs(id);
	}
}
void dfs2(ll x,ll p)
{
	for(auto v:a[x])
	{
		ll id=v.x;
		if(id==p) continue;
		dfs2(id,x);
		f[x]+=f[id];
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
	fr(i,1,n-1)
	{
		f[i]++;
		f[i+1]++;
		f[LCA(i,i+1)]-=2;
	}
	dfs2(1,1);
	ll res=0;
	fr(i,2,n)
	{
		res+=min(cx[i]*f[i],cy[i]);
	}
	cout<<res;
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
	doc();
	xuly();
	time();
}


