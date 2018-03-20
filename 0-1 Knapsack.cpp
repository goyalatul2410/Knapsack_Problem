#include<iostream>
using namespace std;
int max(int a,int b)
{
	return (a > b)? a:b;
}
int knapsack(int cap, int weight[], int profit[], int n)
{
	int w,i,k[30][30];
	for(i=0;i<=n;i++)
	{
		for(w=0;w<=cap;w++)
		{
			if(i==0 || w==0)
			{
				k[i][w] = 0;
				cout<<k[i][w]<<" ";
			}
			else if(weight[i-1] <= w)
			{
				k[i][w] = max(profit[i-1]+k[i-1][w-weight[i-1]], k[i-1][w]);
				cout<<k[i][w]<<" ";
			}
			else
			{
				k[i][w] = k[i-1][w];
				cout<<k[i][w]<<" ";
			}
			
		}
		cout<<"\n";
	}
	return k[n][cap];
}
int main()
{
	int i,n,cap,weight[20],profit[20],res;
	cout<<"enetr the no of iteams"<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"enter the weight and profit of item"<<i+1<<endl;
		cin>>weight[i]>>profit[i];
		
	}
	cout<<"enter the kanpsack capacity"<<endl;
	cin>>cap;
	res = knapsack(cap, weight, profit, n);
	cout<<"\nmax weight can add "<<res<<endl;
	return 0;
}
