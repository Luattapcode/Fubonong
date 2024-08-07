#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
using namespace std;
ll n;
ll m;
ll A[1000005];
struct bg{
	ll x;
	ll y;
};
struct cmp{
	bool operator()(bg u,bg v)
	{
		return u.x>v.x;
	}
};
vector <bg> a[1000005];
ll check[1000005];
ll f[100005];
ll res[100005];
void doc()
{
	cin>>n;
	fr(i,1,n)
	{
		cin>>A[i];
	}
	cin>>m;
	fr(i,1,m)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		a[x].pb({y,z});
		a[y].pb({x,z});
	}
}
void dij(ll x)
{
	priority_queue <bg,vector<bg>,cmp> h;
	fr(i,1,n) f[i]=1e18;
	f[x]=0;
	res[x]=A[x];
	h.push({f[x],x});
	while(!h.empty())
	{
		ll id=h.top().y;
		h.pop();
		if(check[id]==1) continue;
		check[id]=1;
		for(auto v:a[id])
		{
			ll ke=v.x;
			ll ts=v.y;
			if(f[ke]>f[id]+ts and check[ke]==0)
			{
				f[ke]=f[id]+ts;
				res[ke]=res[id]+A[ke];
				h.push({f[ke],ke});
			}
			else if(f[ke]==f[id]+ts)
			{
				res[ke]=max(res[ke],res[id]+A[ke]);
			}
		}
	}
}
void xuly()
{
	dij(1);
	if(f[n]==1e18) cout<<"impossible";
	else cout<<f[n]<<" "<<res[n];
}
void time()
{
	cerr<< endl<<"Time: "<<clock()<<"ms"<<endl;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("QUANHO.INP", "r", stdin);
	freopen("QUANHO.OUT", "w", stdout);
	doc();
	xuly();
	time();
}


