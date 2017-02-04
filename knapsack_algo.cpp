#include<iostream>
using namespace std;
struct items{
	float weight;
	float profit;
	float ratio;
	int obno;
};
void merge(struct items A[],int p, int q, int r){
	int n1=q-p+1;
	int n2=r-q;
	struct items L[n1+1];
	struct items R[n2+1];
	for(int i=0;i<n1;i++){
		L[i]=A[p+i];
	}
	for(int j=0;j<n2;j++){
		R[j]=A[q+j+1];
	}
	int inf=0;
	L[n1].ratio=inf;
	R[n1].ratio=inf;
	int i=0;
	int j=0;
	for(int k=p;k<=r;k++){
		if(L[i].ratio>=R[j].ratio){
			A[k]=L[i];
			i=i+1;
		} else {
			A[k]=R[j];
			j=j+1;
		}
	}
	
}
void mergesort(struct items A[], int p, int r){
	if(p<r){
		int q=(p+r)/2;
		mergesort(A,p,q);
		mergesort(A,q+1,r);
		merge(A,p,q,r);
	}
	
}
float knapsack(struct items item[],int n, int m){
	int p=0;
	float totprof=0;
	int r=n-1;
	mergesort(item,p,r);
	for(int i=0;i<n;i++){
		cout<<item[i].obno<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		if(m>0&&item[i].weight<=m){
			m=m-item[i].weight;
			totprof=totprof+item[i].profit;
		} else if(m>0){
			totprof=totprof+item[i].ratio*m;
			m=0;
		}
	}
	return totprof;
	
	
}
int main(){
	int n,m;
	float *c;
	cout<<"Enter the no. of items -> ";
	cin>>n;
	cout<<"Enter the size of the knapsack -> ";
	cin>>m;
	struct items item[n];
	for(int i=0;i<n;i++){
		cout<<"Enter the weight of item "<<i+1<<" -> ";
		cin>>item[i].weight;
		cout<<"Enter the profit of item "<<i+1<<" -> ";
		cin>>item[i].profit;
		item[i].ratio=item[i].profit/item[i].weight;
		item[i].obno=i;
	}
	float totprof;
	totprof=knapsack(item,n,m);
	/*float A[n];
	for(int i=0;i<n;i++){
		A[i]=item[i].ratio;
	}
	
	for(int i=0;i<=r;i++){
		cout<<c[i]<<" ";
	}
	cout<<endl;
	int call[n];
	bool flag[n];
	for(int i=0;i<n;i++){
		flag[i]=true;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(item[j].ratio==c[i]&&flag[j]==true){
				call[i]=item[j].obno;
				flag[j]=false;
				break;
			}
		}
	}
	for(int i=0;i<=r;i++){
		cout<<call[i]<<" ";
	}
	cout<<endl;*/
	cout<<"Total profit is -> "<<totprof<<endl;
	
	/*cout<<"The weight is "<<item[0].weight<<endl;
	cout<<"The profit is "<<item[0].profit<<endl;
	cout<<"The ratio is "<<item[0].ratio<<endl;*/
	
}
