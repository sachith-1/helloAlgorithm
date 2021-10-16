#include<bits/stdc++.h>
using namespace std;

int main()
{   int i;
    vector<int> v1 = {10,15,20,25,30,50};
    vector <int> v2= {30,5,15,80};

    set <int> s ;
    for( i=0;i<v2.size();i++)
    s.insert(v2[i]);


    for(i=0;i<v1.size();i++)
    {
        if(s.find(v1[i])!=s.end())
        {
            cout<<v1[i]<<" ";
        }
    }




    return 0;
}