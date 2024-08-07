#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
using namespace std;
const int N=2e5+5;
ll a[N];
ll n,k;
void doc()
{
	cin>>n>>k;
	fr(i,1,n) cin>>a[i];
	ll res=0;
	fr(i,1,n) res+=a[i];
	double k=res/n;
	fr(i,1,n) a[i]=abs(a[i]-k);
}
void xuly()
{
	sort(a+1,a+n+1);
	cout<<a[n-k+1]-a[n-k]<<'\n';
}
void time()
{
	cerr<< endl<<"Time: "<<clock()<<"ms"<<endl;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen(".INP", "r", stdin);
	//freopen(".OUT", "w", stdout);
	ll t;
	cin>>t;
	while(t--)
	{
	doc();
	xuly();
}
	time();
}




