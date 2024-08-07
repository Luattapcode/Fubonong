#include <bits/stdc++.h>
	#define ll long long
	#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
	#define boxanglua ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	#define fr(i,a,b) for(int i=a;i<=b;i++)
	#define frd(i,a,b) for(int i=a;i>=b;i--)
	#define pb push_back
	using namespace std;
	ll n,k;
	ll a[1000005];
	ll ma=1e18;
	void doc()
	{
		cin>>n>>k;
		fr(i,1,n) cin>>a[i];
		sort(a+1,a+n+1);
		fr(i,2,n)
		{
			ma=min(ma,a[i]-a[i-1]);
		}
	}
	bool check(ll x)
	{
		ll cnt=0;
		fr(i,2,n)
		{
			ll p=a[i]-a[i-1];
			if(p%x==0) cnt+=p/x-1;
			else cnt+=p/x;
		}
		if(cnt<=k) return 1;
		else return 0;
	}
	void xuly()
	{
		ll d=1;
		ll c=1e18;
		while(d+1<c)
		{
			ll mid=(d+c)/2;
			if(check(mid)==1) c=mid;
			else d=mid;
		}
		if(check(d))
		{
			cout<<d;
			return;
		}
		else cout<<c;
	}
	int main()
	{
		boxanglua
		openfile;
		doc();
		xuly();
	}
