/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define TASK "social-distancing"
using namespace std;
/*Khai Bao*/
const long long inf=1e18;
const int LO=17;
const int CH=27;
const int N=1e5+5;
const int D=1e3+5;
struct bg{
	ll x;
	ll y;
};
ll demx[D];
ll demy[D];
ll demxy[D][D];
ll d,n;
bg a[N];
/*END*/
void doc()
{
	cin>>d>>n;
	fr(i,1,n)
	{
		cin>>a[i].x>>a[i].y;
	}
}	
namespace sub1
{
	void xuly()
	{
		fr(i,1,n)
		{
			ll tx=(a[i].x%d+d)%d;
			ll ty=(a[i].y%d+d)%d;
			demx[tx]++;
			demy[ty]++;
			demxy[tx][ty]++;
		}
		ll res=inf;
		fr(i,0,d-1)
		{
			fr(j,0,d-1)
			{
				res=min(res,demx[i]+demy[j]-demxy[i][j]);
			}
		}
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















