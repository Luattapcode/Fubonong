/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define int long long
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
const long long inf=1e18;
const int LO=17;
const int CH=27;
const int N=20+5;
int n,k;
int a[N][N];
int f[1<<20+1];
//void add(int &x,const int &y){x+=y;if(x>=sm)x-=sm;}
//void sub(int &x,const int &y){x-=y;if(x<0)x+=sm;}
/*END*/
void doc()
{
	cin>>n>>k;
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
		int tt=(1<<n)-1;
		fr(i,0,tt) f[i]=inf;
		f[tt]=0;
		frd(p,tt,1)
		{
			fr(i,0,n-1)
			{
				if((p & (1<<i))==0)
				{
					fr(j,0,n-1)
					{
						if((p & (1<<j))!=0)
						{
							int x=p | (1<<i);
							minimize(f[p],f[x]+a[i+1][j+1]);
						}
					}
				}
			}
		}
		int res=inf;
		fr(i,1,tt)
		{
			if(dembit1(i)==k)
			{
				minimize(res,f[i]);
			}
		}
		cout<<res;
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
























