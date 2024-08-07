/*The best way to get something done is to begin*/
#include <bits/stdc++.h>
#define ll long long
#define openfile if(fopen("Data.inp","r")) {freopen("Data.inp", "r", stdin); freopen("Data.out", "w", stdout);}
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define TASK "string"
using namespace std;
/*Khai Bao*/
const long long inf=1e18;
const int LO=17;
const int CH=27;
string s1;
string s2;
unordered_map <char,int> check;
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
		fr(i,1,s1.size()-1)
		{
			check[s1[i]]=1;
			if(s1[i]!=s2[i] and check[s2[i]]==0)
			{
				cout<<"Yes";
				return;
			}
		}
		cout<<"No";
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















