#include<bits/stdc++.h> 
using namespace std;

void check(string s){
 
 if(s.size()!= 19 or s[4]!='-' or s[9]!='-' or s[14]!='-' )
 {
     cout<<"Invalid";
     return;
 }
 
 for(int i=0; i<19; i++)
 {
     if( i != 4 and i != 9 and i != 14){
         
         if(!isdigit(s[i])){
             
             cout<<"Invalid";
             return;
         }
     }
 }
 
 cout<<"Valid";
 return;
}


int main() 
{ 
    int n;
    cin>>n;
    
    while(n--){
        
        string s;
        
        cin>>s;
        
        check(s);
        
    }
    return 0; 
}
