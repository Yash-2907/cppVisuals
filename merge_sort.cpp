#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& v,int start,int end,int mid)
{
    int size1 = mid - start + 1, size2 = end - mid + 1,ptr1=start,ptr2=mid+1,ptr3=0;
    vector<int> temp(end-start+1);
    while(ptr1<=mid && ptr2<=end)
    {
        if(v[ptr1]<v[ptr2])
        {
            temp[ptr3]=v[ptr1];
            ptr1++;
        }
        else{
            temp[ptr3] = v[ptr2];
            ptr2++;
        }
        ptr3++;
    }
    while(ptr1<=mid)
    {
        temp[ptr3] = v[ptr1];
        ptr1++;
        ptr3++;
    }
    while(ptr2<=end)
    {
        temp[ptr3] = v[ptr2];
        ptr2++;
        ptr3++;
    }
    for(int i=0;i<end-start+1;i++)
    v[start+i]=temp[i];
}

void divide(vector<int>& v,int start,int end)
{
    if(start<end)
    {
        int mid=(start+end)/2;
        divide(v,start,mid);
        divide(v,mid+1,end);
        merge(v,start,end,mid);
    }
}

int main()
{
    vector<int> v(100);
    for (auto &it : v)
        it = rand() % 100;
    divide(v,0,v.size()-1);
    for(auto& it: v) cout<<it<<" ";
}