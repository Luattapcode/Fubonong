/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define TASK "thesis"
using namespace std;
/*Khai Bao*/
const long long inf=1e18;
const int LO=17;
const int CH=27;
const int N=1e6+6;
ll n;
char a[N];
/*END*/
void doc()
{
	cin>>n;
	fr(i,1,n)
	{
		cin>>a[i];
	}
}
namespace sub1
{
	void xuly()
	{
		ll cnt=0,ct=1,cf=1;
		fr(i,1,n)
		{
			if(i%2==0 and a[i]!='F') 
			{
				fr(j,max(cf,(ll)i+1),n)
				{
					if(a[j]=='F')
					{
						swap(a[i],a[j]);
						cnt+=j-i;
						cf=j+1;
						break;
					}
				}
			}
			else if(i%2==1 and a[i]!='T')
			{
				fr(j,max(ct,(ll)i+1),n)
				{
					if(a[j]=='T')
					{
						swap(a[i],a[j]);
						cnt+=j-i;
						ct=j+1;
						break;
					}
				}
			}
		}
		cout<<cnt;
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















