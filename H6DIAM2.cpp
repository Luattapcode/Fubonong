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
const int N=2e5+5;
stack <int> st;
int n;
string s;
vector <int> g[N];
//void add(int &x,const int &y){x+=y;if(x>=sm)x-=sm;}
//void sub(int &x,const int &y){x-=y;if(x<0)x+=sm;}
/*END*/
void doc()
{
	cin>>s;
	s='+'+s;
	n=s.size()-1;
}
namespace sub1
{
	int f[N];
	void dfs(int u,int p)
	{
		for(auto v:g[u])
		{
			if(v==p) continue;
			f[v]=f[u]+1;
			dfs(v,u);
		}
	}
	void xuly()
	{
		int dinh=0;
		fr(i,1,n)
		{
			if(s[i]=='(')
			{	
				dinh++;
				if(st.empty()) st.push(dinh);
				else 
				{
					int y=st.top();
					g[dinh].pb(y);
					g[y].pb(dinh);
					st.push(dinh);
				}
			}
			else 
			{
				st.pop();
			}
		}
		dfs(1,0);
		int res1=0;
		int pos1,pos2;
		fr(i,1,n)
		{
			if(maximize(res1,f[i]))
			{
				pos1=i;
			}
		}
		fr(i,1,n) f[i]=0;
		dfs(pos1,0);
		res1=0;
		fr(i,1,n) 
		{
			if(maximize(res1,f[i]))
			{
				pos2=i;
			}
		}
		cout<<res1;
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
























