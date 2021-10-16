#include<bits/stdc++.h>
using namespace std;
// to find out if zero sum subarray(contiguous) exists
// if a no. repeats in cumulative array or if 0 is present in it , then zero sum exists
int main()
{
    vector <int> v = {1,4,13,-3,10,5};
    vector <int> cumm;
    unordered_set <int> s;
    int sum =0;
    for(int x:v)
        {
            sum=sum+x;
            cumm.push_back(sum);
        }
    
    for(int y:cumm)
        cout<<y<<" ";        








    return 0;
}