/*样例输入
ghde
fbac
*/

#include<iostream>
using namespace std;
int main()
{
    char arr1[100],arr2[100];
    int inputarr(char *arr);
    int l1=inputarr(arr1);
    int l2=inputarr(arr2);

    void  str_bin(char str1[ ], char str2[ ],int l1,int l2);
    str_bin(arr1,arr2,l1,l2);
}
int inputarr(char *arr)
{
    char temp;
    int length=0;
    while(1)
    {
        temp=getchar();
        if(temp=='\n')
            break;
        *(arr+length)=temp;
        length++;
    }
    return length;
}
void merge(char *arr,int left,int mid,int right)
{
    int length=right-left+1;
    char temp[length];
    int i=0,k=left,j=mid+1;
    /*错误示范
    错误原因：k,j数组越界
    for(;i<=length-1;i++){
        if(*(arr+k)<=*(arr+j)){
            temp[i]=*(arr+k);
            k++;
        }
        else{
            temp[i]=*(arr+j);
            j++;
        }
    }*/
    //正确示范如下：
    while(k<=mid&&j<=right){
        if(*(arr+k)<=*(arr+j)){
            temp[i]=*(arr+k);
            k++;
        }
        else{
            temp[i]=*(arr+j);
            j++;
        }
        i++;
    }
    while(k<=mid){
        temp[i]=*(arr+k);
        k++;
        i++;
    }
    while(j<=right){
        temp[i]=*(arr+j);
        j++;
        i++;
    }

    for(int i=0;i<=length-1;i++)
        arr[left+i]=temp[i];
}
void mergesort(char *arr,int left,int right)
{
    if(left>=right)
        return;
    int mid=(left+right)/2;
    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);
    merge(arr,left,mid,right);
}
void  str_bin(char str1[ ], char str2[ ],int l1,int l2)
{
    char arr[l1+l2];
    for(int i=0;i<=l1-1;i++)
        arr[i]=*(str1+i);
    for(int i=l1,j=0;i<=l1+l2-1;i++,j++)
        arr[i]=*(str2+j);
    mergesort(arr,0,l1+l2-1);
    for(int i=0;i<=l1+l2-1;i++)
        cout<<arr[i];
}