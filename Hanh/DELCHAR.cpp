/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define fi first
#define se second
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
const int N=1e3+5;
int f[N][N];//goi f[i][j] la so phep xoa it nhat de s[i...j] la day ngoac dung
string s;
int n;
//void add(int &x,const int &y){x+=y;if(x>=sm)x-=sm;}
//void sub(int &x,const int &y){x-=y;if(x<0)x+=sm;}
/*END*/
void doc()
{
	cin>>s;
	n=s.size();
	s='s'+s;
}
namespace sub1
{
	void xuly()
	{
		fr(i,1,n)
		{
			fr(j,i,n) f[i][j]=inf;
		}
		fr(i,1,n) f[i][i]=1;
	}
}
namespace sub2
{
	int check(int i,int j)
	{
		if(s[i]=='(' and s[j]==')') return 1;
		else if(s[i]=='[' and s[j]==']') return 1;
		else if(s[i]=='{' and s[j]=='}') return 1;
		return 0;
	}
	void xuly()
	{
		fr(i,1,n)
		{
			fr(j,i,n) f[i][j]=inf;
		}
		fr(i,1,n) f[i][i]=1;
		fr(len,2,n)
		{
			fr(i,1,n-len+1)
			{
				int j=i+len-1;
				if(check(i,j)) f[i][j]=f[i+1][j-1];
				fr(k,i,j-1)
				{
					f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
				}
			}
		}
		cout<<f[1][n];
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
