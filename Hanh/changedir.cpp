/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define TASK "changedir"
#define openfile if(fopen("TASK.inp","r")) {freopen("TASK.inp", "r", stdin); freopen("TASK.out", "w", stdout);}
using namespace std;
/*Khai Bao*/
const long long inf=1e18;
const int LO=17;
const int CH=27;
const int N=2207+5;;
const int sm=998244353;
int n,m;
int f[N][N][6];
int nx[]={0,1,1,1,2,0};
int ny[]={0,0,2,1,1,1};
char a[N][N];
/*END*/
void doc()
{
	cin>>n>>m;
	fr(i,1,n)
	{
		fr(j,1,m)
		{
			cin>>a[i][j];
		}
	}
}
namespace sub1
{
	void xuly()
	{
		if(n==1 and m==1)
		{
			cout<<1;
			
		}
		fr(i,1,5)
		{
			ll dx=nx[i]+1;
			ll dy=ny[i]+1;
			if(dx>=1 and dx<=n and dy>=1 and dy<=m and a[dx][dy]=='.')
			{
				f[dx][dy][i]=1;
			}
		}
		fr(i,1,n)
		{
			fr(j,1,m)
			{
				if(a[i][j]=='.' )
				{
					fr(u,1,5)
					{
							ll dx=i-nx[u];
							ll dy=j-ny[u];
							if(dx>=1 and dx<=n and dy>=1 and dy<=m)
							{
								fr(v,1,5)
								{
									if(v!=u)
									{
										f[i][j][u]=(f[i][j][u]+f[dx][dy][v])%sm;
									}
								}
							}
					}
				}
			}
		}
		ll res=0;
		fr(i,1,5)
		{
			res=(res+f[n][m][i])%sm;
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
	freopen(TASK".INP", "r", stdin);
	freopen(TASK".OUT", "w", stdout);
	doc();
	sub1::xuly();
}
/*
	Name of problem:
	Copyright: Luattapcode
	Author: Huynh Quoc Luat
*/















