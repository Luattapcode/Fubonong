/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define fi first
#define se second
#define TASK "TROCHOICONMUC"
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
const int sm=998244353;
int numperson,maxeat,numturn,delta;
int start[11];
	void add(int &x,const int &y)
	{
		x+=y;
		if(x>=sm) x-=sm;
	}
	void sub(int &x,const int &y)
	{
		x-=y;
		if(x<0) x+=sm;
	}
/*END*/
void doc()
{
	cin>>numperson>>maxeat>>numturn>>delta;
	fr(i,1,numperson) cin>>start[i];
}	
namespace sub1
{
	const int MT=111;
	const int ME=1111;
	int sum[MT][MT*ME];
	int f[MT][MT*ME];
	int cntway(int minall,int maxall)
	{
		int ans=1;
		fr(i,1,numperson)
		{
			int low=minall-start[i];
			int high=maxall-start[i];
			maximize(low,0);
			minimize(high,maxeat*numturn);
			if(low>high) return 0;
			int mul=sum[numturn][high];
			if(low>0)
			{
				sub(mul,sum[numturn][low-1]);
			}
			ans=1ll*ans*mul%sm;
		}
		return ans;
	}
	void xuly()
	{
		f[0][0]=1;
		fr(i,0,numturn*maxeat) sum[0][i]=1;
		fr(i,1,numturn)
		{
			fr(j,0,i*maxeat)
			{
				f[i][j]=sum[i-1][j];
				if(j-maxeat-1>=0)
				{
					sub(f[i][j],sum[i-1][j-maxeat-1]);
				}
				sum[i][j]=f[i][j];
				if(j>0) add(sum[i][j],sum[i][j-1]);
			}
			fr(j,i*maxeat+1,maxeat*numturn)
			{
				f[i][j]=0;
				sum[i][j]=sum[i][j-1];
			}
		}
		int minstart=start[1];
		fr(i,1,numperson)
		{
			minimize(minstart,start[i]);
		}
		int res=0;
		fr(i,minstart,minstart+maxeat*numturn)
		{
			int j=i+delta;
			add(res,cntway(i,j));
			sub(res,cntway(i+1,j));	
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



















