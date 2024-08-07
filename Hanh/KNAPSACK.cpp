	#include <bits/stdc++.h>
	#define ll long long
	#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
	#define fr(i,a,b) for(int i=a;i<=b;i++)
	#define frd(i,a,b) for(int i=a;i>=b;i--)
	#define pb push_back
	using namespace std;
	ll f[3005][5005];
	ll m,n;
	ll a[1000005];
	ll b[1000005];
	void doc()
	{
		cin>>n>>m;
		fr(i,1,n) cin>>a[i];
		fr(i,1,n) cin>>b[i];
	}
	void xuly()
	{
		fr(i,1,n) f[i][0]=0;
		fr(i,1,m) f[0][i]=0;
		fr(i,1,n)
		{
			fr(j,0,m)
			{
				f[i][j]=f[i-1][j];
				if(j>=a[i])
				{
					f[i][j]=max(f[i-1][j],f[i-1][j-a[i]]+b[i]);
				}
			}
		}
		ll res=0;
		fr(i,0,n) res=max(res,f[i][m]);
		cout<<res;
	}
	void time()
	{
		cerr<< endl<<"Time: "<<clock()<<"ms"<<endl;
	}
	main()
	{
		ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
		freopen("KNAPSACK.INP", "r", stdin);
		freopen("KNAPSACK.OUT", "w", stdout);
		doc();
		xuly();
		time();
	}
	

