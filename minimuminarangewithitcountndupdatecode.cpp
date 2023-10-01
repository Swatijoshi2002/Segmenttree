
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int a[100005];
pair<int,int> tree[4*100005];

void min_segtree(int node,int s,int e)
{
    if(s==e)
    {
        tree[node].first=a[s];
        tree[node].second=1;
        return;
    }
    int mid=(s+e)/2;
    min_segtree(2*node,s,mid);
    min_segtree(2*node+1,mid+1,e);
    if(tree[2*node].first<tree[2*node+1].first)
    {
        tree[node].first=tree[2*node].first;
        tree[node].second=tree[2*node].second;
    }
    else if(tree[2*node].first>tree[2*node+1].first){
        tree[node].first=tree[2*node+1].first;
        tree[node].second=tree[2*node+1].second;
    }
    else{
        tree[node].first=tree[2*node].first;
        tree[node].second=tree[2*node].second+tree[2*node+1].second;
    }
}

pair<int,int>find(int node,int l,int r,int s,int e)
{
    if(s>r || e<l)
    {
        return {INT_MAX,-1};
    }
    if(l<=s && r>=e)
    {
       return tree[node];
    }
    int mid=(s+e)/2;
    pair<int,int>q1=find(2*node,l,r,s,mid);
    pair<int,int>q2=find(2*node+1,l,r,mid+1,e);
    pair<int,int>q;
    if(q1.first<q2.first)
    {
        q=q1;
    }
    else if(q1.first>q2.first)
    {
        q=q2;
    }
    else{
        q.first=q1.first;
        q.second=q1.second+q2.second;
    }
    return q;
}

void update(int node,int index,int value,int s,int e)
{
    if(s==e)
    {
        a[s]=value;
        tree[node].first=value;
        tree[node].second=1;
        return;
    }
    int mid=(s+e)/2;
    if(index<=mid)
    {
        update(2*node,index,value,s,mid);
    }
    else{
        update(2*node+1,index,value,mid+1,e);
    }
    
    if(tree[2*node].first<tree[2*node+1].first)
    {
        tree[node].first=tree[2*node].first;
        tree[node].second=tree[2*node].second;
    }
    else if(tree[2*node].first>tree[2*node+1].first){
        tree[node].first=tree[2*node+1].first;
        tree[node].second=tree[2*node+1].second;
    }
    else{
        tree[node].first=tree[2*node].first;
        tree[node].second=tree[2*node].second+tree[2*node+1].second;
    }
    
}
int main()
{
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }
   min_segtree(1,0,n-1);
   for(int i=0;i<15;i++)
   {
       cout<<tree[i].first<<" "<<tree[i].second<<endl;
   }
   cout<<"find_min_in_segtree"<<endl;
   int l,r;
   cout<<"enter range"<<endl;
   cin>>l>>r;
   pair<int,int> ans=find(1,l,r,0,n-1);
   cout<<ans.first<<" "<<ans.second<<endl;
   cout<<"update any value enter index and value"<<endl;
   int index ,value;
   cin>>index>>value;
   update(1,index,value,0,n-1);
   for(int i=0;i<15;i++)
   {
       cout<<tree[i].first<<" "<<tree[i].second<<endl;
   }
    return 0;
}
