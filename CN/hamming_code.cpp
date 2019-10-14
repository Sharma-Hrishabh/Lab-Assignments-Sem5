#include<bits/stdc++.h>
using namespace std;

int main()
{
    string code_word;
    cout<<"Enter the code word: \t"<<endl;
    cin>>code_word;
    vector< int > code;
    code.push_back(0);
    for(int i=0; i<code_word.length(); i++)
        code.push_back(code_word[i] - '0');
    int max_pow = floor(log2(code_word.length())) + 1;
    vector< int > ans;
    for(int i=0; i<=max_pow; i++){
        int num = pow(2,i);
        if(i == 0)
            num = 1;
        int cnt = 0;
        for(int j = num; j<=code_word.length(); j += 2*num){
            for(int k=j; k<j+num && k<=code_word.length(); k++){
                if(code[k] == 1)
                    cnt++;
            }
        }
        if(cnt%2 == 0){
            ans.push_back(0);
        }else{
            ans.push_back(1);
        }
    }
    int bit = 0;
    int exp = 0;
    for(vector<int>::iterator it = ans.begin(); it != ans.end(); it++){
        bit += (*it)*(pow(2,exp));
        exp++;
    }
    if(bit == 0){
        cout<<"The given hamming code is error free"<<endl;
    }else{
        cout<<"Error in the "<<bit<<"th bit "<<endl;
    }
}
11