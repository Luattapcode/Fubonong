#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
using namespace std;
int dist[6002][6002];
#define DIST(x,y) dist[(x)+2000][(y)+2000]
const int dx[] = {-1, 1,  2, 2};
const int dy[] = { 2, 2, -1, 1};
const int sm=998244353;
void add(int &x,const int &y)
{
	x+=y;
	if(x>sm) x-=sm;
}
bool inside(int x,int y)
{
	return -2000<=x and x<=4000 and -2000<=y and y<=4000;
}
void xuly()
{
	DIST(0,0)=1;
	fr(sum,0,8000)
	{
		fr(x,max(-2000,sum-4000),min(4000,sum+2000))
		{
			int y=sum-x;
			if(y<-2000 or y>4000) continue;
			fr(i,0,3)
			{
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(inside(nx,ny))
				{
					add(DIST(nx,ny),DIST(x,y));
				}
			}
		}
	}
}
int query(int x,int y,int u,int v)
{
	int nx=u-x;
	int ny=v-y;
	return nx+ny <0 ? 0 : DIST(nx,ny);
}
void time()
{
	cerr<< endl<<"Time: "<<clock()<<"ms"<<endl;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("KNIGHT.INP", "r", stdin);
	freopen("KNIGHT.OUT", "w", stdout);
	xuly();
	int t;
	cin>>t;
	fr(i,1,t)
	{
		int x,y,u,v;
		cin>>x>>y>>u>>v;
		cout<<query(x,y,u,v)<<'\n';
	}
	time();
}


