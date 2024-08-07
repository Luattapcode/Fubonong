/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define fi first
#define se second
#define TASK "COLTAB"
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
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }
/* Author: Huynh Quoc Luat */
/*Khai Bao*/
const long long inf=1e18;
const int LO=17;
const int CH=27;
const int N=1e3+5;
int n,m;
int a[N][N];
int s[N][N];
//void add(int &x,const int &y){x+=y;if(x>=sm)x-=sm};
//void sub(int &x,const int &y){x-=y;if(x<0)x+=sm};
/*END*/
void doc()
{
	cin>>n>>m;
	fr(i,1,n)
	{
		fr(j,1,m)
		{
			cin>>a[i][j];
		}
	}
	fr(i,1,n)
	{
		fr(j,1,m)
		{
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
		}
	}
}
int hcn(int x,int y,int u,int v)
{
	return s[u][v]-s[x-1][v]-s[u][y-1]+s[x-1][y-1];
}
namespace sub1
{
	void xuly()
	{
		int res=-1e9;
		fr(i,1,n-1)
		{
			fr(j,i+1,n)
			{
				int ma=hcn(i,1,j,1);
				fr(k,2,m)
				{
					int sum=hcn(i,k,j,k)+ma;
					maximize(res,sum);
					ma=max(hcn(i,k,j,k),ma+a[j][k]+a[i][k]);
				}
			}
		}
		cout<<n<<" "<<m;
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
/* May man chi den voi nhung nguoi co thuc luc */




















