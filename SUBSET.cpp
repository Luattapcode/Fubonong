#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define boxanglua ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
using namespace std;
ll n,s;
ll a[1000005];
ll f[1000005];
void doc()
{
	cin>>n>>s;
	fr(i,1,n) cin>>a[i];
}
void xuly()
{
	ll res=1e18;
	fr(i,1,n)
	{
		frd(j,s,a[i])
		{
			f[j]=max(f[j],f[j-a[i]]);
		}
		f[a[i]]=i;
		if(f[s]!=0)
		{
			res=min(res,i-f[s]+1);
		}
	}
	if(res==1e18) cout<<-1;
	else cout<<res;
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

