#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define boxanglua ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
using namespace std;
ll m,n;
ll p[1000005];
ll ok;
ll check[1000005];
ll dd[1000005];
ll sm=1e9+7;
vector <ll> a[1000005];
ll dem[1000005];
ll f[1000005];//goi f[i] la so sach di  den dc 1-i
void doc()
{
	cin>>n>>m;
	fr(i,1,m)
	{
		ll x,y;
		cin>>x>>y;
		a[y].pb(x);
	}
	dd[1]=1;
	f[1]=1;
}
ll dfs(ll u,ll p)
{
	if(dd[u]) return f[u];
	dd[u]=1;
	for(auto v:a[u])
	{
		if(v==p) continue;
		dfs(v,u);
		f[u]=(f[u]+f[v])%sm;
	}
	return f[u];
}
void xuly()
{
	cout<<dfs(n,0);
}
void time()
{
	cerr<< endl<<"Time: "<<clock()<<"ms"<<endl;
}
main()
{
	boxanglua
	//freopen(".INP", "r", stdin);
	//freopen(".OUT", "w", stdout);
	doc();
	xuly();
	time();
}
