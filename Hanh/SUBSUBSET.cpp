#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define boxanglua ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
using namespace std;
ll n,S;
int f[2208][5604][2];
int a[1000005];
int sm=998244353;
void doc()
{
	cin>>n>>S;
	fr(i,1,n) cin>>a[i];
	f[0][0][0]=1;
}
void add(ll x, ll y)// chuyen x-> (x+y)%sm
{
	x=x+y;
	if(x>=sm) x-=sm;
}
void xuly()
{
	fr(i,0,n)
	{
		fr(j,0,S)
		{
			fr(k,0,1) f[i][j][k]=0;
		}
	}
	f[0][0][0]=1;
	fr(i,0,n-1)
	{
		fr(j,0,S)
		{
			fr(k,0,1)
			{
				if(f[i][j][k]>0)
					
					{
					f[i+1][j][k]=(f[i+1][j][k]+f[i][j][k])%sm;
					f[i+1][j][1]=(f[i+1][j][1]+f[i][j][k])%sm;
					if(j+a[i+1]<=S) f[i+1][j+a[i+1]][k]=(f[i+1][j+a[i+1]][k]+f[i][j][k])%sm;
				}
			}
		}
	}
	int res=0;
	fr(j,0,S) res=(res+f[n][j][1])%sm;
	cout<<res;
}
void time()
{
    cerr<< endl<<"Time: "<<clock()<<"ms"<<endl;
}
int main()
{
	boxanglua
	freopen("SUBSUBSET.INP", "r", stdin);
	freopen("SUBSUBSET.OUT", "w", stdout);
	doc();
	xuly();
	time();
}
