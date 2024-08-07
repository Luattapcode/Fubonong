/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define TASK "xor"
using namespace std;
/*Khai Bao*/
const long long inf=1e18;
const int LO=17;
const int CH=27;
ll a,n;
/*END*/
void doc()
{
	cin>>a>>n;
}
namespace sub1
{
	void xuly()
	{
		fr(i,0,3e7)
		{
			if(( a xor i)%n==0)
			{
				cout<<i;
				return;
			}
		}
	}
}
namespace sub2
{
	// a xor b= c
	// a xor c=b
	void xuly()
	{
		ll d=a-a%n;
		ll ans=inf;
		fr(i,-1e2,1e2)
		{
			if(d+i*n>=0) ans=min(ans,(d+i*n) xor a);
		}
		cout<<ans;
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
	sub2::xuly();
	time();
}
/*
	Name of problem:
	Copyright: Luattapcode
	Author: Huynh Quoc Luat
*/















