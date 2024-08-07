/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define fi first
#define se second
#define TASK "nkleague"
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
const int N=1e3+5;
char a[N][N];
bool cmp(int x,int y)
{
	return a[x][y]=='1';
}
ll b[1000005];
int n;
/*END*/
void doc()
{
	cin>>n;
	fr(i,1,n)
	{
		fr(j,1,n)
		{
			cin>>a[i][j];
		}
	}
}
namespace sub1
{
	void xuly()
	{
		fr(i,1,n)
		{
			b[i]=i;
		}
		sort(b+1,b+n+1,cmp);
		fr(i,1,n) cout<<b[i]<<" ";
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


















