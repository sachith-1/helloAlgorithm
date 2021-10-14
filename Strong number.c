#include<stdio.h>
int main()
{
    int rem,result=0,number,count=0,cnt,fact=1;
    printf("Enter any number:");
    scanf("%d",&number);

    int q=number;
    while(q!=0)
    {
        q=q/10;
        count++;
    }
    q=number;
    cnt=count;
    while(q!=0)
    {
        rem=q%10;
        while(rem!=1)
        {
            fact=fact*rem;
            rem--;
        }
        result=result+fact;
        q=q/10;
        cnt=count;
        fact=1;

    }
    printf("%d ",result);
    if(result==number)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
} 