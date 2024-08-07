/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define TASK data
using namespace std;
/*Khai Bao*/
const long long inf=1e18;
const int N=1e5+5;
ll n;
ll in[N];
ll out[N];
ll a[N];
int q;
ll dem=0;
vector <ll> g[N];
/*END*/
void doc()
{
	cin>>n>>q;
	fr(i,1,n)
	{
		cin>>a[i];
	}
	fr(i,1,n-1) 
	{
		ll x,y;
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
}
namespace sub1
{
	ll bit[4*N];
	void dfs(ll x,ll p)
	{    
		in[x]=++dem;
		for(auto v:g[x])
		{
			if(v==p) continue;
			dfs(v,x);
		}
		out[x]=++dem;
	}
	void up(int u,int v)
	{
		int idx=u;
		while(idx<=2*n)
		{
			bit[idx]+=v;
			idx+=(idx & (-idx));
		}
	}
	ll get(int u)
	{
		int idx=u;
		ll ans=0;
		while(idx>0)
		{
			ans+=bit[idx];
			idx-=(idx & (-idx));
		}
		return ans;
	}
	ll getrange(ll l,ll r)
	{
		if(l>r) return 0;
		return get(r)-get(l-1);
	}
	void xuly()
	{
		dfs(1,0);
		fr(i,1,n) up(in[i],a[i]),up(out[i],-a[i]);
		fr(i,1,q)
		{
			char t;
			int x;
			cin>>t;
			cin>>x;
			if(t=='2')
			{
				cout<<getrange(in[x],out[x])<<'\n';
			}
			int y;
				cin>>y;
				up(in[x],-a[s]+x);
				up(out[x],a[s]-x);
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
