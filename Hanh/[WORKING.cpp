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
	ll n;
	struct bg{
		ll x;
		ll y;
	};
	bool cmp(bg u,bg v)
	{
		return u.x<v.x;
	}
	bg a[N];
	ll f[N];
	void doc()
	{
		cin>>n;
		fr(i,1,n) cin>>a[i].x>>a[i].y;
		sort(a+1,a+n+1,cmp);
	}
	void xuly()
	{
		f[1]=a[1].y-a[1].x;
		fr(i,2,n)
		{
			fr(j,1,i-1)
			{
				if(a[i].y<a[j].y) f[i]=max(f[i],f[j]);
				else if(a[i].x<=a[j].y and a[j].y<a[i].y) f[i]=max(f[i],f[j]+a[i].y-a[j].y);
				else if(a[i].x>=a[j].y) f[i]=max(f[i],f[j]+a[i].y-a[i].x);
			}
		}
		fr(i,1,n) cout<<f[i]<<" ";
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







