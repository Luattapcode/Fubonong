/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define fi first
#define se second
#define TASK "standard"
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
const int N=3030;
int r,c,h,w;
int a[N][N];
/*END*/
void doc()
{
	cin>>r>>c>>h>>w;
	fr(i,1,r)
	{
		fr(j,1,c)
		{
			cin>>a[i][j];
		}
	}
}
namespace sub1
{
	void xuly()
	{
		cout<<r*c;
	}
}
namespace sub2
{
	void xuly()
	{	
		cout<<(r*c+1)/2;
	}
}
namespace subfull
{
	ll sum[N][N];
	int getsum(int x,int y,int u,int v)
	{
		return sum[u][v]-sum[x-1][v]-sum[u][y-1]+sum[x-1][y-1];
	}
	bool check(int x)
	{
		fr(i,1,r)
		{
			fr(j,1,c)
			{
				sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(a[i][j]>=x?1 :-1);
			}
		}
		fr(i,1,r-h+1)
		{
			fr(j,1,c-w+1)
			{
				if(getsum(i,j,i+h-1,j+w-1)>0) return 1;
			}
		}
		return 0;
	}
	int solve(void)
	{
		int l=1;
		int cuoi=r*c;
		while(1)
		{
			if(l==cuoi) return cuoi;
			if(cuoi-l==1) return check(cuoi)? cuoi:l;
			int mid=(l+cuoi)>>1;
			if(check(mid)) l=mid;
			else cuoi=mid-1;
		} 
	}
	void xuly()
	{
		cout<<solve();
	}
}
void time()
{
	cerr<< endl<<"Luattapcode: "<<clock()<<"ms"<<endl;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	doc();
	subfull::xuly();
}
//code full:	https://ideone.com/l5CFuu


















