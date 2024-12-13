#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    int number,basis;
    cin>>number>>basis;

    int array[20];
    int itob(int n,int s[],int b);
    int length=itob(number,array,basis);
    if(length>=0)
    {
        void output(int a[],int length);
        output(array,length);
    }
    else
    {
        length=-length;
        void output(int a[],int length);
        cout<<'-';
        output(array,length);
    }
    

    

}
void output(int a[],int length)
{
    for(int i=length-1;i>=0;i--)
    {
        if(a[i]>=0&&a[i]<=9)
            cout<<a[i];
        else
        {
            char temp;
            temp=a[i]+87;
            cout <<temp;
        }
    }
}
int itob(int n,int s[],int b)
{
    int fuhao=1;
    if(n<0)
    {
        n=-n;
        fuhao=0;
    }

    int i=0;
    while(pow(b,i+1)<=n)
        i++;
    int length=i+1;
    for(;i>=0;i--)
    {
        int temp=pow(b,i);
        s[i]=(n-n%temp)/temp;
        int test=s[i];
        n-=s[i]*pow(b,i);
    }
    if(fuhao==1)
        return length;
    else
        return -length;
}

