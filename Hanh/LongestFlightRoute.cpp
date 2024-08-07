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
	vector <ll> g[N];
	ll n;
	ll in[N];
	ll l[N];
	ll p[N];
	bool check[N];
	ll m;
	queue <ll> q;
	void doc()
	{
		cin>>n>>m;
		fr(i,1,m)
		{
			int u,v;
			cin>>u>>v;
			g[u].pb(v);
			in[v]++;
		}
	}
	void dfs(ll x,ll p)
	{
		check[x]=1;
		for(auto v:g[x])
		{
			if(v==p) continue;
			if(check[v]==1) continue;
			dfs(v,x);
		}
	}
	void xuly()
	{
		fr(i,1,n)
		{
			if(in[i]==1) continue;
			q.push(i);
		}
		dfs(1,0);
		if(check[n]==0)
		{
			cout<< "IMPOSSIBLE";
			return;
		}
		fr(i,2,n)
		{
			l[i]=-1;
		}
		while(!q.empty())
		{
			ll u=q.front();
			q.pop();
			for(auto v:g[u])
			{
				if(l[u]!=-1 and l[v]<l[u]+1)
				{
					l[v]=l[u]+1;
					p[v]=u;
				}
				in[v]--;
				if(in[v]==0) q.push(v);
			}
		}
		ll k=l[n]-l[1];
		cout<<k+1	;
		cout<<'\n';
		ll u=n;
		vector <ll> v;
		while(u!=1)
		{
			v.pb(u);
			u=p[u];
		}
		v.pb(1);
		sort(v.begin(),v.end());
		for(auto r:v)
		{
			cout<<r<<" ";
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
	//freopen(TASK".INP", "r", stdin);
	//freopen(TASK".OUT", "w", stdout);
	sub1::doc();
	sub1::xuly();
	time();
}







