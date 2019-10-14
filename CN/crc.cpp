#include<bits/stdc++.h>
using namespace std;

bool check(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]!='0')
            return 0;
    }    
    return 1;
}

string solveCRC(string message,string key){
    int m=key.length();
    int n=message.length();
    
    // no of passes..
    int nop=n-m+1;
    for(int i=0;i<nop-1;i++){
        // exor
        if(message[i]=='1'){
            int k=i;
            for(int j=0;j<m;j++,k++){
                if(message[k] == key[j]){
                    message[k]='0';
                }else{
                    message[k]='1';
                }
            }  
        }
    }
    
    // last One
    string ans="";
    for(int i=nop-1,j=0;i<n && j<m;i++,j++){
            if(i!=nop-1)
            if(message[i] == key[j]){
                ans+='0';
            }else{
                ans+='1';
            }
    }
    return ans;
}

int main(){
    cout<<"Enter message"<<endl;
    string message;
    cin>>message;
    cout<<"Enter key"<<endl;    
    string key;
    cin>>key;
    
    // append to message
    string temp=message;
    for(int i=0;i<key.length()-1;i++){
        temp+='0';
    }
    
    string rem = solveCRC(temp, key);
    string target="000";
    
    while(1){
        message += rem;
        string rem = solveCRC(message, key);
        if(rem == target)
            break;
    }
    cout<<"Encoded Message"<<endl;
    cout<<message<<endl;
}