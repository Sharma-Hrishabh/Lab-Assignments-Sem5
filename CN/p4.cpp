#include<bits/stdc++.h>
using namespace std;




int minDistance(vector<int>dist,vector<bool>processedV,int V)
{
	int min_index,min=INT_MAX;

	for(int i=0;i<V;i++)
	{
		if(!processedV[i] && dist[i]<min)
		{
			min_index=i;
			min=dist[i];
		}
	}

	return min_index;

}


void print(vector<int>dist,int V)
{
	for(int i=0;i<V;i++)
		cout<<dist[i]<<" ";
}


void djikstra(vector<vector<int>>g,int s,int V)
{
vector<int>dist(V);
vector<bool>processedV(V);
	fill(dist.begin(),dist.end(),INT_MAX);
	fill(processedV.begin(),processedV.end(),false);

	dist[s]=0;
	for(int i=0;i<V-1;i++)
	{
		int u = minDistance(dist,processedV,V);
		processedV[u]=true;

		for(int v=0;v<V;v++)
		{
			if(!processedV[v] && g[u][v] && dist[u]!=INT_MAX && dist[u]+g[u][v]<dist[v]) dist[v]=dist[u]+g[u][v];
		}


	}


print(dist,V);


}
int main()
{

int V;
cin>>V;

vector<vector<int>>g(V);

for(int i=0;i<V;i++)
{

vector<int>temp(V);

g[i]=temp;

for(int j=0;j<V;j++) cin>>g[i][j];
}

int s;
cin>>s;

djikstra(g,s,V);



}