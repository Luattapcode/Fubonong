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
const int N=1e6+5;
int n;
int a[N];	
int b[N];
int pos[N];
int ok[N];
multiset <int> s;
vector <pair<int,int>> ans;
//void add(int &x,const int &y){x+=y;if(x>=sm)x-=sm;}
//void sub(int &x,const int &y){x-=y;if(x<0)x+=sm;}
/*END*/
void doc()
{
	cin>>n;
	fr(i,1,n) cin>>a[i];
	fr(i,1,n) cin>>b[i];
	fr(i,1,n)
	{
		pos[a[i]]=i;
		ok[b[i]]=1;
	}
}
namespace sub1
{
	void update(int i,int j)
	{
		ans.pb({a[i],a[i]^(1<<j)});
		pos[a[i]]=0;
		if(ok[a[i]]) s.insert(i);
		a[i]=a[i] ^ (1<<j);
		pos[a[i]]=i;
		if(ok[a[i]])
		{
			s.erase(s.find(i));
		}
	}
	void cal(int i,int num,int j)
	{
			for(;j<15;j++)
			{
				int luat1=a[i] & (1<<j);
				int fu=num & (1<<j);
				if(luat1 ^ fu)
				{
					if(pos[a[i] ^ (1<<j)])
					{
						cal(pos[a[i]^(1<<j)],num,j+1);
						update(i,j);
						break;
					}
						else 
				{
					update(i,j);
				}
				}
			}
	}
	void xuly()
	{
		fr(i,1,n)
		{
			if(!ok[a[i]]) s.insert(i);
		}
//		for(auto it:s) cout<<it<<" ";
//		cout<<el;
		fr(i,1,n)
		{
			if(!pos[b[i]])
			{
				cal(*s.begin(),b[i],0);
			}
		}
		cout<<ans.size()<<el;
		for(auto it:ans)
		{
			cout<<it.fi<<" "<<it.se<<el;
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
























