/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define fi first
#define se second
#define TASK "CAR"
#define openfile if(fopen(TASK".inp","r")) {freopen(TASK".inp", "r", stdin); freopen(TASK".out", "w", stdout);}
using namespace std;
template <class X, class Y>
	bool minimize(X &x, const Y &y) {
		if (x > y) {
			x = y;
			return true;
		} else return false;
	}

template <class X, class Y>
	bool maximize(X &x, const Y &y) {
		if (x < y) {
			x = y;
			return true;
		} else return false;
	}
/*Author: Huynh Quoc Luat*/
/*Khai Bao*/
const long long inf=1e18;
const int LO=17;
const int CH=27;
const int N=2e5+5;
int n,k,s,t;
struct bg{
	int x;
	int y;
};
int sum[N];
bg b[N];
int a[N];
/*END*/
void doc()
{
	cin>>n>>k>>s>>t;
	fr(i,1,n)
	{
		cin>>b[i].x>>b[i].y;
	}
	fr(i,1,k)
	{
		cin>>a[i];
	}
	sort(a+1,a+k+1);
	a[0]=0;
	a[k+1]=s;
}
namespace sub1
{
	bool check(int x)
	{
		int bag=x;
		int time=0;
		fr(i,1,k+1)
		{
			int dist=a[i]-a[i-1];
			if(dist>x) return 0;
			time+=2*dist-min(x-dist,dist);
		}
		return time<=t;
	}
	void xuly()
	{
		int d=1;
		int c=1e10;
		while(d+1<c)
		{
			int mid=(d+c)>>1;
			if(check(mid)) c=mid;
			else d=mid;
		}
		int res=-1;
		if(check(d)) res=d;
		else if(check(c)) res=c;
		if(res==-1)
		{
			cout<<-1;
			return;
		}
		else 
		{
			int ans=1e9;
			fr(i,1,n)
			{
				if(b[i].y>=res) ans=min(ans,b[i].x);
			}
			cout<<ans;
		}
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
	openfile
	//freopen(TASK".INP", "r", stdin);
	//freopen(TASK".OUT", "w", stdout);
	doc();
	sub1::xuly();
	time();
}



















