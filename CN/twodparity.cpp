#include<bits/stdc++.h>
using namespace std;
int main()
{

int n;
cin>>n;

int a[n+1][n+1]={{0}};




for(int i=0;i<n;i++)
{
	int count=0;
	for(int j=0;j<n;j++)
	{
		cin>>a[i][j];
		if(a[i][j]==1) count++;
	}
	if(count%2!=0) a[i][n]=1;
	else a[i][n]=0;
}


for(int j=0;j<n;j++)
{
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(a[i][j]==1) count++;

	}
	if(count%2!=0) a[n][j]=1;
	else a[n][j]=0;

}



// a[1][1]=0;

// for(int i=0;i<=n;i++)
// {
// 	for(int j=0;j<=n;j++)
// 	{
// 		cout<<a[i][j]<<" ";
// 	}
// 	cout<<endl;

// }

int flag=0;
for(int i=0;i<n;i++)
{
	int count=0;
	for(int j=0;j<=n;j++)
	{
		if(a[i][j]==1) count++;
	}
	if(count%2!=0) 
	{
		flag=1;
		break;
	}
}

for(int j=0;j<n;j++)
{
	int count=0;
	for(int i=0;i<=n;i++)
	{
		if(a[i][j]==1) count++;
	}
	if(count%2!=0) 
	{
		flag=1;
		break;
	}
}



if(flag==1) cout<<"Error"<<endl;
else cout<<"Np"<<endl;

}