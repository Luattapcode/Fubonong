/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define fi first
#define se second
#define TASK "CARDRM"
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
const int N=50+5;
int n;
string s[N];
bool g[N][N];
int f[N];
/*END*/
void doc()
{
	cin>>n;
	fr(i,1,n)
	{
		cin>>s[i];
	}
}
namespace sub1
{
	int check(string x,string y)
	{
		int cnt=0;
		fr(i,0,2)
		{
			fr(j,0,2)
			{
				if(x[i]==y[j]) cnt++;
			}
		}
		return cnt>=2;
	}
	void xuly()
	{
		fr(i,1,n) g[i][i]=0;
		fr(i,1,n-1) g[i][i+1]=1;
		fr(i,1,n-2)
		{
			g[i][i+2]=check(s[i],s[i+2]);
		}
		fr(d,4,n)
		{
			fr(i,1,n-d+1)
			{
				int j=i+d-1;
				fr(k,i+1,j-1)
				{
					if(g[i][k]==1 and g[k][j]==1 and check(s[i],s[j]))
					{
						g[i][j]=1;
						break;
					}
				}
			}
		}
		fr(i,3,n)
		{
			f[i]=f[i-1];
			fr(j,1,i-1)
			{
				if(g[j][i]==1) 
				{
					f[i]=max(f[i],f[j]+i-j-1);
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



















