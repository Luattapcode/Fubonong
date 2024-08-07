/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define TASK "bits"
using namespace std;
/*Khai Bao*/
const long long inf=1e18;
const int LO=17;
const int CH=27;
string s1,s2;
/*END*/
void doc()
{
	cin>>s1;
	cin>>s2;
	s1='&'+s1;
	s2='&'+s2;	
}
namespace sub1
{
	void xuly()
	{
		ll n=s1.size()-1;
		ll dem=0;
		ll res=0;
		if(s1==s2)
		{
			cout<<0;
			return;
		}
		fr(i,1,n)
		{
			if(s1[i]=='1' and s2[i]=='0')
			{
				res+=(dem>0);
				dem--;
			}
			else if(s1[i]=='0' and s2[i]=='1')
			{
				res+=(dem<0);
				dem++;
			}
		}
		if(dem>=0)
		{
			res+=dem;
			fr(i,1,n)
			{
				res+=(s1[i]=='?');
			}
			cout<< (res==0 ? -1 :res);
			return;
		}
		else 
		{
			fr(i,1,n)
			{
				if(s1[i]=='?' and s2[i]=='1' and dem<0)
				{
					res+=2;
					dem++;
				}
				else if(s1[i]=='?' and s2[i]=='0') res++;
				else if(s1[i]=='?' and dem==0) res++;
			}
		}
		if(dem<0) cout<<-1;
		else cout<<(res==0 ? -1 :res);
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
	time();
}
/*
	Name of problem:
	Copyright: Luattapcode
	Author: Huynh Quoc Luat
*/















