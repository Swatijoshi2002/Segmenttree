/*segment tree*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int arr[1000];
int tree[4*1000];
void segment_tree_build(int node,int s,int e)
{
    if(s==e)
    {
        tree[node]=arr[s];
        return ;
    }
    int mid=(s+e)/2;
    segment_tree_build(2*node,s,mid);
    segment_tree_build(2*node+1,mid+1,e);
    
    tree[node]=tree[2*node]+tree[2*node+1];
}
int query_tree_range(int node,int l,int r,int s,int e)
{
     if(r<s || l>e) return 0;
    if(l<=s && r>=e)
    {
        return tree[node];
    }
   
    int mid=(s+e)/2;
    int q1=query_tree_range(2*node,l,r,s,mid);
    int q2=query_tree_range(2*node+1,l,r,mid+1,e);
    return q1+q2;
}

int main()
{
   
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    segment_tree_build(1,0,n-1);
    
    for(int i=0;i<25;i++)
    {
        cout<<tree[i]<<" ";
    }
    int ans =query_tree_range(1,2,4,0,n-1);
    cout<<ans;
    return 0;
}
