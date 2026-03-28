#include<iostream>
#include<algorithm>
using namespace std;
#define maxsize 1010
int N,V;
int v[maxsize],w[maxsize];
int f[maxsize];
int main(){
	cin>>N>>V;
	for(int i=1;i<=N;i++)
	cin>>v[i]>>w[i];
	for(int i=1;i<=N;i++)
	for(int j=V;j>=v[i];j--){
		f[j]=max(f[j],f[j-v[i]]+w[i]);
	}
	cout<<f[V]<<endl;
	return 0;
}
