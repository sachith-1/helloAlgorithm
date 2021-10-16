#include<iostream>
using namespace std;

int main(){

    int a[10][10], b[10][10], n;
    int i, j, k;
    int c[10][10];

    cout<<"\nEnter size of nXn matrix : ";
    cin>>n;

    cout<<"\nEnter "<<n*n<<" elements of first matrix : ";
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
           cin>>a[i][j];

    cout<<"\nEnter "<<n<<" elements of second matrix : ";
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
          cin>>b[i][j];

   
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++){
        c[i][j]=0;
        for(int k=0;k<n;k++)
          c[i][j]+=a[i][k]*b[k][j];
      }

    cout<<"The multiplication of matrices gives : \n";
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)   
          cout<<c[i][j]<<' ';
        cout<<'\n';
    }

    return 0;
       
}