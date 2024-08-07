#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
using namespace std;
ll n,q;
ll A[1000005];
vector <ll> a[1000005];
ll mi[1000005];
ll s[1000005];
ll p[1000005];
void doc()
{
	cin>>n>>q;
	fr(i,1,n) cin>>A[i];
	fr(i,1,n-1)
	{
		ll u,v;
		cin>>u>>v;
		a[u].pb(v);
		a[v].pb(u);
	}
}
void minn(ll x)
{
	mi[x]=A[x];
	for(auto v:a[x])
	{
		if(v==p[x]) continue;
		minn(v);
		mi[x]=min(mi[v],mi[x]);
	}
}
void sum(ll x)
{
	s[x]=A[x];
	for(auto v:a[x])
	{
		if(v==p[x]) continue;
		sum(v);
		s[x]+=s[v];
	}
}
void xuly()
{
	minn(1);
	sum(1);
	while(q--)
	{
		string s;
		ll u, v;
		cin>>s;
		if(s=="CHANGE")
		{
			cin>>u>>v;
			A[u]=v;
			minn(1);
			sum(1);
		}
		else if(s=="SUM")
		{
			cin>>u;
			cout<<s[u];
		}
		else 
		{
			cin>>u;
			cout<<mi[u];;
		}
		cout<<'\n';
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
	doc();
	xuly();
	time();
}


