/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define TASK "roadfees"
#define openfile if(fopen(TASK".inp","r")) {freopen(TASK".inp", "r", stdin); freopen(TASK".out", "w", stdout);}
using namespace std;
/*Khai Bao*/
const long long inf=1e18;
const int LO=17;
const int CH=27;
const int N=2e5+5;
int f[N];
int n;
struct bg{
	int x;
	int y;
	int z;
};
ll ma=inf;
ll mi=-1e18;
bg a[N];
vector <int> ve;
unordered_map<int,int> mp;
vector <bg> g[N];	
/*END*/
void doc()
{
	cin>>n;
	fr(i,1,n) 
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
		ve.pb(a[i].x);
		ve.pb(a[i].y);
	}
	sort(ve.begin(),ve.end());
	ve.resize(unique(ve.begin(),ve.end())-ve.begin());
	fr(i,0,ve.size()-1) mp[ve[i]]=i+1;
	fr(i,1,n)
	{
		g[mp[a[i].x]].pb({mp[a[i].y],a[i].z});
		g[mp[a[i].y]].pb({mp[a[i].x],a[i].z});
	}
}
namespace sub1
{
	void dfs(ll x,ll p)
	{
		for(auto v:g[x])
		{
			int id=v.x;
			int ts=v.y;
			if(id==p) continue;
			f[x]+=ts;
			dfs(id,x);
			if(f[id]+ts>=0) f[x]+=f[id];
			else 
			{
				if(ts<0) f[x]-=ts;
			}
		}
	}
	void xuly()
	{
		int res=0;
		dfs(1,0);
		fr(i,1,ve.size()) res=max(res,f[i]);
		cout<<res;
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
	openfile
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

















