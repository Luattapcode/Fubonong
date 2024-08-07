/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
//#define int long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define fi first
#define se second
#define el '\n'
#define dembit1(x) __builtin_popcount(x)
#define TASK "data"
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
const long long inf=1e9;
const int LO=17;
const int CH=27;
const int N=1e4+5;
const int M=100+5;
int n;
struct bg{
	int x;
	int y;
	int z;
};
bg a[N];
int m;
int f[M][N];
//void add(int &x,const int &y){x+=y;if(x>=sm)x-=sm;}
//void sub(int &x,const int &y){x-=y;if(x<0)x+=sm;}
/*END*/
void doc()
{
	cin>>n>>m;
	fr(i,1,m)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
}
namespace sub1
{
	void xuly()
	{
		fr(i,0,m)
		{
			fr(j,0,n) f[i][j]=inf;
		}
		f[0][0]=0;
		fr(i,1,m)
		{
			fr(j,0,n)
			{
				f[i][j]=f[i-1][j];
				fr(k,0,a[i].x)
				{
					if(j>=k)
					{
						minimize(f[i][j],f[i-1][j-k]+a[i].z+k*a[i].y);
					}
				}
			}
		}
		int res=inf;
		fr(i,1,m)
		{
			minimize(res,f[i][n]);
		}
		cout<<res;
	}
}
namespace sub2 
{
	int pre[N];
	int cur[N];
	void xuly()
	{
		fr(i,1,n)
		{
			pre[i]=cur[i]=inf;
		}
		fr(i,1,m)
		{
			fr(j,0,n)
			{
				int canbuy=min(n,j+a[i].x)-j;
				if(canbuy)
				{
					minimize(cur[j+canbuy],pre[j]+a[i].z+canbuy*a[i].y);
				}
			}
			fr(j,0,n) pre[j]=cur[j];
		}
		cout<<cur[n];
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
	sub2::xuly();
	time();
}
























