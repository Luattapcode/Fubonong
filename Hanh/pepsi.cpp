/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define fi first
#define se second
#define TASK "pepsi"
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
const int N=1e5+5;
struct bg{
	int x;
	int y;
	int z;
};
bool cmp(bg u,bg v)
{
	return u.x<v.x;
}
vector <bg> v;
int c,n,m;
/*END*/
void doc()
{
	cin>>c>>n>>m;
	v.clear();
	fr(i,1,n)
	{
		int x;
		cin>>x;
		v.pb({x,0,0});
	}
	fr(i,1,m)
	{
		int x,y;
		cin>>x>>y;
		v.pb({x,y,1});
	}
	sort(v.begin(),v.end(),cmp);
}
namespace sub1
{
	void xuly()
	{
		int cnt=0;
		int bag=c;
		fr(i,0,v.size()-1)
		{
			int x=v[i].z;
			if(x==0) bag=c;
			else
			{
				if(bag-v[i].y>=0)
				{
					bag-=v[i].y;
					cnt+=v[i].y;
				}
			}
		}
		cout<<cnt<<'\n';
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
	int t;
	cin>>t;
	while(t--)
	{
	doc();
	sub1::xuly();
}
	time();
}


















