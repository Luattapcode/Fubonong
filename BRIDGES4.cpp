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
	const int N=1e6+5;
	ll f[N];
	ll n,m;
	ll sc=0;
	void doc()
	{
		cin>>n>>m;
		fr(i,0,n-1) f[i]=-1;
	}
	ll goc(ll x)
	{
		while(f[x]>0) x=f[x];
		return x;
	}
	void hn(ll r1,ll r2)
	{
		int t=f[r1]+f[r2];
		if(abs(f[r1])>abs(f[r2]))
		{
			f[r1]=t;
			f[r2]=r1;
		}
		else 
		{
			f[r1]=r2;
			f[r2]=t;
		}
	}
	void xuly()
	{
		fr(i,1,m)
		{
			ll u,v;
			cin>>u>>v;
			ll r1=goc(u);
			ll r2=goc(v);
			if(r1!=r2)
			{
				hn(r1,r2);
				sc++;
			}
			ll mi=*min_element(f,f+n);
			if(abs(mi)==n) 
			{
				cout<<i;
				return;
			}
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
/*
	Name of problem:
	Copyright:
	Author:
	Description:
*/









