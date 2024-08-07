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
	const int N=1e5+5;
	vector <int> g[N];
	int n;
	ll t[4*N];
	int root;
	ll res=0;
	void doc()
	{
		cin>>n;
		cin>>root;
		fr(i,1,n-1)
		{
			ll u,v;
			cin>>u>>v;
			g[u].pb(v);
			g[v].pb(u);
		}
	}
	void update(ll k,ll l,ll r,ll v,ll val)
	{
		if(v>r or v<l) return;
		if(l==r)
		{
			t[k]+=val;
			return;
		}
		ll mid=(l+r)/2;
		update(2*k,l,mid,v,val);
		update(2*k+1,mid+1,r,v,val);
		t[k]=t[2*k]+t[2*k+1];
	}
	ll get(ll k,ll l,ll r,ll u,ll v)
	{	
	if(v<l or u>r) return 0;
	if(u<=l and v>=r) return t[k];
	ll mid=(l+r)/2;
	ll m1=get(2*k,l,mid,u,v);
	ll m2=get(2*k+1,mid+1,r,u,v);
	return m1+m2;
	}
	void dfs(ll x,ll p)
	{
		update(1,1,n,x,1);
		for(auto v:g[x])
		{
			if(v==p) continue;
			res+=get(1,1,n,1,v-1);
			dfs(v,x);
		}
		update(1,1,n,x,-1);
	}
	void xuly()
	{
		dfs(root,0);
		cout<<res;
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
	//freopen(TASK".INP", "r", stdin);
	//freopen(TASK".OUT", "w", stdout);
	sub1::doc();
	sub1::xuly();
	time();
}







