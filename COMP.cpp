#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define boxanglua ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
using namespace std;
ll n;
ll a[1000005];
ll res=1;
ll ma=-1e9;
void doc()
{
	cin>>n;
	fr(i,1,n)
	{
		cin>>a[i];
		res=res*a[i];
		ma=max(ma,a[i]);
	}
}
ll bcnn(ll a,ll b)
{
	ll x=__gcd(a,b);
	return a*b/x;
}
void xuly()
{
	ll res=bcnn(a[1],a[2]);
	fr(i,3,n)
	{
		res=bcnn(res,a[i]);
	}
	cout<<res;
	cout<<'\n';
	fr(i,1,n)
	{
		cout<<res/a[i]<<" ";
	}
}
void time()
{
	cerr<< endl<<"Time: "<<clock()<<"ms"<<endl;
}
main()
{
	boxanglua
	//freopen(".INP", "r", stdin);
	//freopen(".OUT", "w", stdout);
	doc();
	xuly();
	time();
}

