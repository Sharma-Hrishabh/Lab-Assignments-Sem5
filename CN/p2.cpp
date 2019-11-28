#include<bits/stdc++.h>
using namespace std;

int main()
{
	string codeword;
	cin>>codeword;
	std::vector<int> code;
	code.push_back(0);
	for(int i=0;i<codeword.length();i++)
	{
		code.push_back(codeword[i]-'0');
	}



	int max_pow = floor(log2(codeword.length()))+1;
    cout<<"max "<<max_pow<<endl;
	vector<int> ans;

	for(int i=0;i<max_pow;i++)
	{
		int num = pow(2,i);
		if(i==0) num=1;
		int cnt=0;
		for(int j=num;j<=codeword.length();j += (2*num))
		{
			for(int k=j;k<j+num && k<=codeword.length();k++)
			{
				if(code[k]==1) cnt++;
			}
		}
		if(cnt%2==0) ans.push_back(0);
		else ans.push_back(1);

	}

for(vector<int>::iterator it = ans.begin();it!=ans.end();it++)
	{
		cout<<(*it)<<" ";
	}
cout<<endl;

	int bit=0;
	int exp=0;
	for(vector<int>::iterator it = ans.begin();it!=ans.end();it++)
	{
		bit+= (*it)*(pow(2,exp));
		exp++;
	}


	if(bit==0) cout<<"No error\n";
	else cout<<"Error at "<<bit<<endl;


}



// 01110110101