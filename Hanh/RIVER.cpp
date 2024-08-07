	#include <bits/stdc++.h>// chat nhi phan ket qua
	#define ll long long
	#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
	#define fr(i,a,b) for(int i=a;i<=b;i++)
	#define frd(i,a,b) for(int i=a;i>=b;i--)
	#define pb push_back
	using namespace std;
	ll m,n,k;
	ll d[1000004];
	void doc()
	{
		cin>>n>>m>>k;
	}
	ll lt(ll x,ll y)
	{
		if(y==0) return 1;
		if(y==1) return x;
		ll p=lt(x,y/2);
		if(y%2==0) return p*p;
		else return p*p*x;
	}
	int check(ll x)
	{
		ll cnt=0;
		ll ans=0;
		fr(i,0,n-1)
		{
			if(ans+d[i]<=x)
			{
				ans+=d[i];
			}
			else
			{
				cnt++;
				ans=d[i];
			}
		}
		if(ans>0) cnt++;
		return cnt<=k;
	}
	void xuly()
	{
		ll sum=0;
		fr(i,0,n-1)
		{
			d[i]=1+(lt((i),2)%m);
		}
		fr(i,0,n-1) sum+=d[i];
		ll l=*max_element(d,d+n+1);
		ll r=sum;
		while(l+1<r)
		{
			ll mid=(l+r)/2;
			if(check(mid)) r=mid;
			else l=mid;
		}
		if(check(l)) cout<<l;
		else cout<<r;
	}
	void time()
	{
		cerr<< endl<<"Time: "<<clock()<<"ms"<<endl;
	}
	main()
	{
		ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
		freopen("RIVER.INP", "r", stdin);
		freopen("RIVER.OUT", "w", stdout);
		doc();
		xuly();
		time();
	}
	

