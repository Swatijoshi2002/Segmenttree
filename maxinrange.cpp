/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<bits/stdc++.h>
int arr[1000];
int tree[4*1000];
using namespace std;
void  build_maxsegtree(int node ,int s,int e)
{
    if(s==e)
    {
         tree[node]=arr[s];
         return;
    }
    int mid=(s+e)/2;
    build_maxsegtree(2*node,s,mid);
    build_maxsegtree(2*node+1,mid+1,e);
    tree[node]=max(tree[2*node],tree[2*node+1]);
}
int get_max(int node,int l,int r,int s,int e)
{
    if(r<s || e<l)
    {
        return INT_MIN;
    }
    if(l<=s && r>=e)
    {
        return tree[node];
    }
    int mid=(s+e)/2;
    int m1=get_max(2*node,l,r,s,mid);
    int m2=get_max(2*node+1,l,r,mid+1,e);
    return max(m1,m2);
}
int main()
{
   
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    build_maxsegtree(1,0,n-1);
    
    for(int i=0;i<25;i++)
    {
        cout<<tree[i]<<" ";
    }
    int ans =get_max(1,1,2,0,n-1);
    cout<<ans;
    return 0;
}
