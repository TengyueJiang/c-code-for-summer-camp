#include<iostream>
#include<algorithm>
using namespace std;
int N;
struct Range{
	int l,r;
	bool operator<(const Range &W){
		return r<W.r;
	}
}range[100010];

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>range[i].l>>range[i].r;
	}	
	int ed=-2e9,cnt=0;
	sort(range,range+N);
	for(int i=0;i<N;i++){
		if(range[i].l>ed)
			{
				cnt++;
				ed=range[i].r;
			}
	}
	cout<<cnt<<endl;
}
