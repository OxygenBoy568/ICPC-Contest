#include<map>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
/*====================*/
const int INF=0X7F7F7F7F;
const int N=1e6+10;
/*====================*/
int a[N],st[N],ans[N],cnt[N];
vector<int>v;
void Solve(void)
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	int ma=a[1];
	ans[1]=0;
	v.push_back(a[1]);
	cnt[a[1]]++;
	for(int i=2;i<=n;++i)
	{
		if(a[i]==ma)
		{
			ans[i]=ans[i-1];
		}
		else if(a[i]<ma)
		{
			int l=0,r=v.size()-1,p=0;
			while(l<=r)
			{
				int mid=(l+r)/2;
				if(v[mid]>a[i])
				{
					p=mid;
					r=mid-1;
				}
				else
				{
					l=mid+1;
				}
			}
			int res=v.size();
			ans[i]=ans[i-1]+res-p;
			cout<<i<<" "<<res<<'\n';
		}
		else if(a[i]>ma)
		{
			ans[i]=ans[i-1]+cnt[ma]+1;
			ma=a[i];
		}
		v.push_back(a[i]);

		cnt[a[i]]++;
	}
	for(int i=1;i<=n;++i)
	{
		cout<<ans[i];
		if(i!=n)
		{
			cout<<" ";
		}

	}
	cout<<'\n';

}
/*====================*/
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

	int T;cin>>T;
	while(T--)Solve();
	return 0;
}