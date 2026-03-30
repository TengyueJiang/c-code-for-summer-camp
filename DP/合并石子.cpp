#include<iostream>
#include<algorithm>
using namespace std;
int f[1010][1010];
int s[1010];
int n;
int a[1010];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	
	for(int i=2;i<=n;i++)
		for(int j=1;j+i-1<=n;j++)
			{
				int l=j,r=j+i-1;
				f[l][r]=1e9;
				for(int k=l;k<r;k++)
					f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
			}
	cout<<f[1][n]<<endl;
	return 0;
}
