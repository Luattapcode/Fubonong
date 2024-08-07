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
const int N=1e7+5   ;
struct bg{
	int x;
	int y;
	int z;
};
int check[N];
int n,m,k;
vector <bg> v;
int a[N];
int ne[N];
//void add(int &x,const int &y){x+=y;if(x>=sm)x-=sm;}
//void sub(int &x,const int &y){x-=y;if(x<0)x+=sm;}
/*END*/
void doc()
{
	cin>>n>>m>>k;
	fr(i,1,m)
	{
		int x,y,z;
		cin>>x>>y>>z;
		v.pb({x,y,z});
	}
}
namespace sub1
{
	int goc(int x)
	{
		if(x==ne[x]) return x;
		else return ne[x]=goc(ne[x]);
	}
	void hn(int u,int v)
	{
		int r1=goc(u);
		int r2=goc(v);
		if(r1!=r2)
		{
			if(r1>r2) swap(r1,r2);
			ne[r1]=r2;
		}
	}
	void xuly()
	{
		reverse(v.begin(),v.end());
		fr(i,1,n) ne[i]=i;
		for(auto k:v)
		{
			int x=k.x;
			int y=k.y;
			int z=k.z;
			while(x<=y)
			{
				x=goc(x);
				if(x>y) break;
				if(check[x]==0)
				{
					check[x]=1;
					a[x]=z;
					hn(x,x+1);
				}
				else 
				{
					x++;
				}
			}
		}
		int res=0;
		fr(i,1,n)
		{
			res=(res*10+a[i])%k;
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
























