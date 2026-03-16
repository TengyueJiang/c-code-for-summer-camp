#include<iostream>
using namespace std;
#define maxsize 100010
int tmp[maxsize];
void mergesort(int a[],int l,int r){
	if(l>=r) return ;
	int mid=(l+r)/2;
	mergesort(a,l,mid);mergesort(a,mid+1,r);
	int k=0,i=l,j=mid+1;
	
	while(i<=mid&&j<=r){
		if(a[i]<a[j]) tmp[k++]=a[i++];
		else tmp[k++]=a[j++];
	}
	while(i<=mid){
		tmp[k++]=a[i++];
	}
	while(j<=r){
		tmp[k++]=a[j++];
	}
	for(int p=0,i=l;i<=r;p++,i++)
	a[i]=tmp[p];
}
int main(){
	int n;
	int a[maxsize];
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	mergesort(a,0,n-1);
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	return 0;
}
