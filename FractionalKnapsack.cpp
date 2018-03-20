#include<iostream>

using namespace std; 

class Knapsack {
	public:
		double frac_knap(int n, int W, int w[],int v[]) {
	
			int i,j;
			double r[n];
			for(i=1;i<=n;i++) {
				r[i]=(v[i]/w[i]);
			}
			
			for(i=1;i<=n-1;i++) {
				for(j=1;j<=n-i-1;j++) {
					if(r[j]<r[j+1]) {
						int temp;
						temp=r[j];  r[j]=r[j+1];  r[j+1]=temp;
						temp=w[j];  w[j]=w[j+1];  w[j+1]=temp;
						temp=v[j];  v[j]=v[j+1];  v[j+1]=temp;
					}
				}	
			}
			
			double benifit=0;
			int totalW=0;
			i=1;
			while(totalW+w[i]<=W) {
				benifit += v[i];
				totalW += w[i];
				i++;
				//cout<<benifit<<"\t"<<totalW<<"\t"<<W-totalW<<endl;
			}
			//cout<<w[i]<<"\t"<<v[i]<<endl;
			double left;
			left=double((W-totalW))/double(w[i]);
			//cout<<left<<endl;
			double value=v[i]*left;
			benifit = benifit+value;
			
			return benifit;
			
		}
};



int main() {
	int n;
	cout<<"Enter no of items: ";
	cin>>n;
	int w[n],v[n];
	int W;
	for(int i=1;i<=n;i++) {
		cout<<"Enter value and weight of "<<i<<" ";
		cin>>v[i]>>w[i];
	}
	cout<<"Enter capacity: ";
	cin>>W;
	
	Knapsack knapsack;
	
	double benefit=knapsack.frac_knap(n,W,w,v);
	
	cout<<endl;
	cout<<"Total Benifit: "<<benefit;
}
