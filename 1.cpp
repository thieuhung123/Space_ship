#include<iostream>
using namespace std;
int* merge(int* firstArr, int lenArr1, int* secondArr, int lenArr2)
{
    int* Arr;
    int i=0,j=0;
    bool kt;
    for(int k=0;k<lenArr1-1;k++)
    {
        if(firstArr[k]<firstArr[k+1]){kt=true;break;}
        if(firstArr[k]>firstArr[k+1]){kt=false;break;}
    }
    if(kt==true)
    {
        while(i<lenArr1&&j<lenArr2)
        {
            if(firstArr[i]>=secondArr[j])
            {
                Arr[i+j]=secondArr[j];
                j++;
            }
            else
            {
                Arr[i+j]=firstArr[i];
                i++;
            }
        }
        while(i < lenArr1)
        {
            Arr[i+j]=firstArr[i];
                i++;
        }

        while(j < lenArr2){
            Arr[i+j]=secondArr[j];
                j++;
        }
    }
    else
    {
        while(i<lenArr1&&j<lenArr2)
        {
            if(firstArr[i]<=secondArr[j])
            {
                Arr[i+j]=secondArr[j];
                j++;
            }
            else
            {
                Arr[i+j]=firstArr[i];
                i++;
            }
        }
        while(i < lenArr1)
        {
            Arr[i+j]=firstArr[i];
                i++;
        }

        while(j < lenArr2){
            Arr[i+j]=secondArr[j];
                j++;
        }
    }
    return Arr;
}
int main()
{
    int n,m,a[100],b[100];
    int *c;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    c=merge(a,n,b,m);
    for(int i=0;i<m+n;i++)
    {
        cout<<c[i];
    }
}
