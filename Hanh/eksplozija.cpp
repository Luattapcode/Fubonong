/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll int
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define TASK "eksplozija"
#define openfile if(fopen(TASK".inp","r")) {freopen(TASK".inp", "r", stdin); freopen(TASK".out", "w", stdout);}
using namespace std;
/*Khai Bao*/
const long long inf=1e18;
const int LO=17;
const int CH=27;
const int N=3e6;
string s,t;
const int MOD[]={(int)1e9+2277,(int)1e9+5277};
const int base=256;
char ch[N];
int cnt=0;
int pw[2][N];
pair <int,int> hs[N];	
/*END*/
void doc()
{
	cin>>s;
	cin>>t;
}
namespace sub1
{
	
	void xuly()
	{
		fr(j,0,1)
		{
			pw[j][0]=1;
			fr(i,1,N-1)
			{
				pw[j][i]=1ll*pw[j][i-1]*base%MOD[j];
			}
		}
		pair <int,int> ht;
		fr(i,0,t.size()-1)
		{
			ht.first=(1ll*ht.first*base+t[i])%MOD[0];
			ht.second=(1ll*ht.second*base+t[i])%MOD[1];
		}	
		fr(i,0,s.size()-1)
		{
			ch[++cnt]=s[i];
			hs[cnt].first=(1ll*hs[cnt-1].first*base+s[i])%MOD[0];
			hs[cnt].second=(1ll*hs[cnt-1].second*base+s[i])%MOD[1];
			if(cnt>=t.size())
			{
				int f=((hs[cnt].first-1ll*hs[cnt-t.size()].first*pw[0][t.size()])%MOD[0]+MOD[0])%MOD[0];
				int p=((hs[cnt].second-1ll*hs[cnt-t.size()].second*pw[1][t.size()])%MOD[1]+MOD[1])%MOD[1];
				if(f==ht.first and p==ht.second) cnt-=t.size();
			}
		}
		if(cnt==0) cout<<"miss you baby";
		else 
		{
			fr(i,1,cnt) cout<<ch[i];
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
	//freopen(TASK".INP", "r", stdin);
	//freopen(TASK".OUT", "w", stdout);
	openfile
	doc();
	sub1::xuly();
	time();
}
/*
	Name of problem:
	Copyright: Luattapcode
	Author: Huynh Quoc Luat
*/

















