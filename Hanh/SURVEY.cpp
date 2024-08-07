/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define TASK "survey"
using namespace std;
/*Khai Bao*/
const long long inf=1e18;
const int LO=17;
const int CH=27;
const int N=1e5;
ll p[N];
ll c[N];
ll n;
double f[N];
/*END*/
void doc()
{
	cin>>n;
	fr(i,1,n)
	{
		cin>>p[i];
	}
	fr(i,1,n)
	{
		cin>>c[i];
	}
}
namespace sub1
{
	void xuly()
	{
		fr(i,1,n)
		{
			f[i]=(double)c[i]/p[i];
		}
		ll res=-inf;
		ll res1=0;
		fr(i,1,n)
		{
			if(f[i]>res)
			{
				res1=i;res=f[i];
			}
		}
		cout<<1;
		cout<<'\n';
		cout<<res1;
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
	freopen(TASK".INP", "r", stdin);
	freopen(TASK".OUT", "w", stdout);
	doc();
	sub1::xuly();
	time();
}
/*
	Name of problem:
	Copyright: Luattapcode
	Author: Huynh Quoc Luat
*/















