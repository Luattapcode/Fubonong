/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define TASK data
using namespace std;
const int N=1e5+5;
struct bg{
	ll x;
	ll y;
	ll z;
};
bg a[N];
ll f[405][405];
ll n;
ll b[405][405];
void doc()
{
	cin>>n;
	fr(i,1,n)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
		b[a[i].x+200][a[i].y+200]=a[i].z;
	}
}
namespace sub1
{
	void xuly()
	{
		ll res=0;
		fr(i,0,400)
		{
			fr(j,i+1,400)
			{
				f[1][2]=f[1][3]=f[1][4]=f[2][3]=f[2][4]=f[3][4]=0;
				fr(k,0,400)
				{
						ll x=b[i][k];
						ll y=b[j][k];
						if(x>y) swap(x,y);
						if(x!=y and x!=0 and y!=0)
						{
						if(x==3 and y==4) res+=f[1][2];
						else if(x==1 and y==2) res+=f[3][4];
						else if(x==1 and y==3) res+=f[2][4];
						else if(x==2 and y==3) res+=f[1][4];
						else if(x==2 and y==4) res+=f[1][3];
						else if(x==1 and y==4) res+=f[2][3];
						f[x][y]++;
						}
				}
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
	//freopen(TASK".INP", "r", stdin);
	//freopen(TASK".OUT", "w", stdout);
	doc();
	sub1::xuly();
	time();
}
/*
	Name of problem:
	Copyright: Luattapcode
	Author: Huynh Quoc Luat
*/












