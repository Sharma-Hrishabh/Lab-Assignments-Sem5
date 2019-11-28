#include<bits/stdc++.h>
using namespace std;


string solveCRC(string message,string key)
{

int n=message.length();
int m=key.length();

int passes = n-m+1;

for(int i=0;i<passes-1;i++)
{
if(message[i]='1')
{
	int k=i;
	for(int j=0;j<m;j++,k++)
	{
		if(message[k]==key[j])
		{
			message[k]='0';
		}
		else message[k]='1';

	}
}

}

string ans="";
for(int i=passes-1,j=0;j<m && i<n;i++,j++)
{
	if(i!=passes-1)
	{
		if(message[i]==key[j]) ans+='0';
		else ans+='1';
	}

}

return ans;


}


int main()
{
string message;
string key;

cin>>message;
cin>>key;


string temp = message;
for(int i=0;i<key.length()-1;i++)
{
	temp+='0';
}

string rem = solveCRC(temp,key);
message+=rem;

cout<<rem<<endl;
cout<<message<<endl;


}