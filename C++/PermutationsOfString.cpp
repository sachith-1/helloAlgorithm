#include<iostream>
#include<string>
using namespace std;

string swapChar(string s,int a,int b){
    char temp;
    temp = s[a];
    s[a] = s[b];
    s[b] = temp;
    return s;
}

void providePermutations(string s,int left,int right){

    if(left == right){
        cout<<s<<endl;
        return;
    }
    for(int i=left;i<=right;i++){
        s = swapChar(s,left,i);
        providePermutations(s,left+1,right);
        s = swapChar(s,left,i);
    }
    return;
}



int main(){
    string s = "abcd";
    providePermutations(s,0,s.length()-1);
    return 0;
}