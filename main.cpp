#include<map>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;
/*====================*/
const int INF=0X7F7F7F7F;
/*====================*/
class Prime
{
public:
	~Prime(void)
	{
		delete[] vis;
		delete[] table;
	}
	int size(void)
	{
		return cnt;
	}
	void init(int n)
	{
		Euler(n);
	}
	int operator[](int x)
	{
		return table[x];
	}
private:
	int cnt=0;
	bool *vis=NULL;
	int *table=NULL;
	void Euler(int n)
	{
		vis=new bool[n+1];
		table=new int[n+1];
		for(int i=0;i<=n;++i)
		{
			vis[i]=true;
		}
		vis[0]=vis[1]=false;
		for(int i=2;i<=n;++i)
		{
			if(vis[i])table[++cnt]=i;
			for(int j=1;j<=cnt;++j)
			{
				if(i*table[j]>n)break;
				vis[i*table[j]]=false;
				if(i%table[j]==0)break;
			}
		}
	}
}prime;
/*====================*/
vector<int>num,cnt;int tot;
void PFF(int x)
{
	for(int i=1;i<=prime.size();++i)
	{
		if(prime[i]*prime[i]>x)break;
		if(x%prime[i]==0)
		{
			num.push_back(prime[i]);
			cnt.push_back(1);
			while(x%prime[i]==0)
			{
				tot++;
				cnt.back()++;
				x/=prime[i];
			}
		}
	}
	if(x!=1)
	{
		tot++;
		num.push_back(x);
		cnt.push_back(1);
	}
	//reverse(num.begin(),num.end());
	//reverse(cnt.begin(),cnt.end());
}
/*====================*/
map<pair<int,int>,int>dp;
int DFS(int a,int b)
{
	if(a==1)return 0;
	if(b==1)return dp[{a,b}]=a-1;
	if(dp.count({a,b})==0)
	{
		int ans=INF;
		for(int i=0;i<num.size();++i)
		{
			if(cnt[i]>0&&(b%num[i])==0)
			{
				int p=num[i];
				cnt[i]--;tot--;
				int del=a%p,add=(p-a%p)%p;
				ans=min(ans,DFS((a-del)/p,b/p)+del+1);
				ans=min(ans,DFS((a+add)/p,b/p)+add+1);
				cnt[i]++;tot++;
			}
		}
		return dp[{a,b}]=ans;
	}
	return dp[{a,b}];
}
/*====================*/
void Solve(void)
{
	int a,b;cin>>a>>b;if(a>b)swap(a,b);
	num.clear();cnt.clear();tot=0;PFF(b-a);
	dp.clear();cout<<DFS(a,b-a)<<endl;
}
/*====================*/
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	prime.init(1e5);
	int T;cin>>T;while(T--)Solve();
	return 0;
}