//样例输入：sum=abc+234;while(abc==700)tab{ass=346++;bss=abc+267;}
#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    string array;
    getline(cin,array);
    int length=array.size();
    //输入并得到长度

    bool temp=0,temp_words=0;
    int tempnumber[10],templength=0,numberarr[20],n_number=0;//数字
    char tempwords[20],wordsarr[20][20]={{'\0'}};
    int templength_words=0,words_number=0;//单词
    char others[20];
    int othersnumber=0;//其他
    void fuzhi(int tempnumber[],int templength,int *numberarr);
    void fuzhi_words(char *tempwords,int templength_words,char *wordsarr);
    for(int i=0;i<=length-1;i++)
    {
        if(array[i]>=48&&array[i]<=57)
        {
            temp=1;
            tempnumber[templength++]=(array[i]-48);
        }
        if(temp==1&&!(array[i]>=48&&array[i]<=57))
        {
            temp=0;
            fuzhi(tempnumber,templength,numberarr+n_number);
            n_number++;
            templength=0;
        }
        if(!(array[i]>=48&&array[i]<=57))
            temp=0;
        //读取数字

        if((array[i]>=65&&array[i]<=90)||(array[i]>=97&&array[i]<=122))
        {
            temp_words=1;
            tempwords[templength_words++]=array[i];
        }
        if(temp_words==1&&!((array[i]>=65&&array[i]<=90)||(array[i]>=97&&array[i]<=122)))
        {
            temp_words=0;
            fuzhi_words(tempwords,templength_words,&wordsarr[0][0]+words_number*20);
            words_number++;
            templength_words=0;
        }
        if(!((array[i]>=65&&array[i]<=90)||(array[i]>=97&&array[i]<=122)))
            temp_words=0;
        //读取单词

        if((array[i]>=33&&array[i]<=47)||(array[i]>=58&&array[i]<=64)
        ||(array[i]>=91&&array[i]<=96)||(array[i]>=123&&array[i]<=126))
        {
            others[othersnumber++]=array[i];
        }

    }//读取字符串，提取
    if(array[length-1]>=48&&array[length-1]<=57)
    {
        fuzhi(tempnumber,templength,numberarr+n_number);
        n_number++;
    }//避免最后一个字符是数字带来的遗漏
    if((array[length-1]>=65&&array[length-1]<=90)||(array[length-1]>=97&&array[length-1]<=122))
    {
        fuzhi_words(tempwords,templength,&wordsarr[0][0]+words_number*20);
        words_number++;
    }
    //主体部分

    cout<<"There are "<<n_number<<" integers:";
    for(int i=0;i<=n_number-1;i++)
    {
        cout<<numberarr[i]<<' ';
    }
    cout << endl;
    cout<<"There are "<<words_number<<" words:";
    for(int i=0;i<=words_number-1;i++)
    {
        cout<<wordsarr[i];
        cout<<' ';
    }
    cout << endl;
    cout<<"There are "<<othersnumber<<" symbles:";
    for(int i=0;i<othersnumber;i++)
        cout<<others[i]<<' ';
    //输出
}
void fuzhi(int tempnumber[],int templength,int *numberarr)//
{
    int sum=0;
    for(int i=templength-1;i>=0;i--)
    {
        sum+=tempnumber[i]*pow(10,templength-1-i);
    }
    *numberarr=sum;
}
void fuzhi_words(char *tempwords,int templength_words,char *wordsarr)
{
    for(int i=0;i<=templength_words-1;i++)
    {
        *(wordsarr+i)=*(tempwords+i);
    }
}

