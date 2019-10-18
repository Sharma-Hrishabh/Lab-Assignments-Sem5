#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"The flag used here is 01111110 and escape character is 01010101 and header and trailer is ignored.\n";
    again:
    cout<<"Enter the data to be sent\n";
    string s;
    cin>>s;
    int flag = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '0' || s[i] == '1'){
            continue;
        }else {
            cout<<"Please enter a binary data.\n";
            flag = 1;
            break;
        }
    }
    if(flag)
        goto again;

    string f = "01111110";
    string esc = "01010101";
    string code_word;
    bool fl = false;
    for(int i=0; i<8; i++)
        code_word.push_back(f[i]);
    for(int i=0; i<=s.length()-8; i++){
        int cnt = 0;
        fl = false;
        for(int j=i; j<i+8; j++){
            if(s[j] == f[j-i]){
                cnt++;
            }
        }
        if(cnt == 8){
            code_word.push_back('0');
            code_word.push_back('1');
            code_word.push_back('0');
            code_word.push_back('1');
            code_word.push_back('0');
            code_word.push_back('1');
            code_word.push_back('0');
            code_word.push_back('1');
            fl = true;

        }
        cnt = 0;
        for(int j=i; j<i+8; j++){
            if(s[j] == esc[j-i]){
                cnt++;
            }
        }
        if(cnt == 8){
            code_word.push_back('0');
            code_word.push_back('1');
            code_word.push_back('0');
            code_word.push_back('1');
            code_word.push_back('0');
            code_word.push_back('1');
            code_word.push_back('0');
            code_word.push_back('1');
            fl = true;
        }
        if(fl){
                for(int j=i; j<i+8; j++){
                code_word.push_back(s[j]);
            }
            i = i+7;
        }
        else{
            code_word.push_back(s[i]);
        }
    }
    for(int i=0; i<8; i++)
        code_word.push_back(f[i]);
    cout<<"The codeword generated including flags is:\n"<<code_word<<endl;
}
