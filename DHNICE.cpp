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
const int N=1e5+5;
int n;
int a[N];
int f[N];
//void add(int &x,const int &y){x+=y;if(x>=sm)x-=sm;}
//void sub(int &x,const int &y){x-=y;if(x<0)x+=sm;}
/*END*/
void doc()
{
	cin>>n;
	fr(i,1,n)
	{
		cin>>a[i];
	}
}
namespace sub1
{
	void xuly()
	{
		fr(i,1,n) f[i]=inf;
		f[1]=1;
		fr(i,2,n)
		{
			f[i]=f[i-1]+1;
			fr(j,1,i)
			{
				if(a[j]==i-j) minimize(f[i],f[j-1]);
				else 
				{
					if(i-j>a[j]) minimize(f[i],f[j-1]+i-j-a[j]);
				}
			}
		}
		cout<<f[n];
	}
}
namespace sub2
{
	void xuly()
	{
		fr(i,1,n) f[i]=inf;
		f[n]=1;
		frd(i,n-1,1)
		{
			minimize(f[i],f[i+1]+1);
			if(a[i]<=n-i) minimize(f[i],f[i+a[i]+1]);	
		}	
		cout<<f[1];
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
























