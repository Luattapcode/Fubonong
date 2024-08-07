#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define boxanglua ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
using namespace std;
ll m,n,r;
vector <ll> a[1000005];
ll b[1000005];
set <ll> s[1000005];
//goi s[u] chua tat ca mau cua cay s[u]
ll f[1000005];//foi f[u] la do dai cua cay goc u
void doc()
{
	cin>>n;
	fr(i,1,n-1)
	{
		ll u,v;
		cin>>u>>v;
		a[u].pb(v);	
		a[v].pb(u);
	}
		fr(i,1,n)
	{
		cin>>b[i];
	}
}
void dfs(ll u,ll p)
{
	s[u].insert(b[u]);
	for(auto v:a[u])
	{
		if(v==p) continue;
		dfs(v,u);
		if(s[v].size()>s[u].size())
		{
			s[u].swap(s[v]);
		}
		for(auto k:s[v])
		{
			s[u].insert(k);
		}
	}
	f[u]=s[u].size();
}
void xuly()
{
	dfs(1,0);
	fr(i,1,n) cout<<f[i]<<" ";
}
void time()
{
    cerr<< endl<<"Time: "<<clock()<<"ms"<<endl;
}
int main()
{
	boxanglua
	//freopen(".INP", "r", stdin);
	//freopen(".OUT", "w", stdout);
	doc();
	xuly();
	time();
}		
