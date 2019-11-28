#include<bits/stdc++.h>
using namespace std;

int findsum(int a,int b,int c)
{
	int ans=0;
	if(a==0 && b==0 && c==0) ans=0;
	else if(a==0 && b==0 && c==1) ans=1;
	else if(a==0 && b==1 && c==0) ans=1;
	else if(a==0 && b==1 && c==1) ans=0;
	else if(a==1 && b==0 && c==0) ans=1;
	else if(a==1 && b==0 && c==1) ans=0;
	else if(a==1 && b==1 && c==0) ans=0;
	else if(a==1 && b==1 && c==1) ans=1;

	return ans; 
}


int findcarry(int a,int b,int c)
{
	int ans=0;
	if(a==0 && b==0 && c==0) ans=0;
	else if(a==0 && b==0 && c==1) ans=0;
	else if(a==0 && b==1 && c==0) ans=0;
	else if(a==0 && b==1 && c==1) ans=1;
	else if(a==1 && b==0 && c==0) ans=0;
	else if(a==1 && b==0 && c==1) ans=1;
	else if(a==1 && b==1 && c==0) ans=1;
	else if(a==1 && b==1 && c==1) ans=1;

	return ans; 
}

int* fixerror(int sum[],int m)
{
	
	int temp[m]={0};
	temp[m-1]=1;
	int carry[m+1]={0};
	for(int i=m-1;i>0;i--){
	int temps=findsum(sum[i],temp[i],carry[i+1]);
	int tempc=findcarry(sum[i],temp[i],carry[i+1]);
	sum[i]=temps;
	carry[i]=tempc;
	}


	if(carry[0]==1)
	{

		sum = fixerror(sum,m);

	}

	return sum;


}

int* findchecksum(int arr[][4],int cs[])
{
	int k=5;
	int m=4;

int sum[m]={0};


for(int i=0;i<k;i++)
{
	int carry[m+1]={0};

	for(int j=m-1;j>0;j--)
	{

		int temps=findsum(arr[i][j],sum[j],carry[j+1]);
		int tempc=findcarry(arr[i][j],sum[j],carry[j+1]);
		sum[j]+=temps;
		carry[j]=tempc;
	}

	if(carry[0]==1)
	{
		int *tempsum=fixerror(sum,m);
		for(int j=0;j<m;j++)
		{
			sum[j]=tempsum[j];
		}
	}


}



for(int i=0;i<m;i++) 
	{
		// cout<<sum[i]<<" ";
		if(sum[i]==0) cs[i]=1;
		else cs[i]=0;
	}
	cout<<endl;

return cs;
}


int main()
{

    string header;
    cout<<"Enter the code word: \t"<<endl;
    cin>>header;
    int n=header.length();
    int k=5;
    int m=4;
    int c=0;
    int arr[5][4];
    for(int i=0;i<k;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		arr[i][j]=header[c]-'0';
    	}
    }
    int cs[m]={0};

    findchecksum(arr,cs);

    for(int i=0;i<m;i++)
    {
    	cout<<cs[i]<<" ";
    }
    cout<<endl;




}