#include<bits/stdc++.h>
using namespace std;
// 0    1   2   3   4
// 5    4   2   1   3

//1st time  4   5   2    1    3
//  4   2   5   1   3
//  4   2   1   5   3
//  4   2   1   3   |5 

//  2   4   1   3   |5
//  2   1   4   3   |5
//  2   1   3   |4  5
//  1   2   |3   4  5  
void print(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
void bubblesort(int arr[],int n){
for(int i=0;i<n;i++){
for(int j=0;j<n-i-1;j++){
    if(arr[j]>arr[j+1]){
        swap(arr[j],arr[j+1]);
    }
}    
}
}
void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int mn=arr[i];
        for(int j=i+1;j<n;j++){
            mn=min(mn,arr[i]);
        }
        swap(arr[i],mn);
    }
}
void insertionsort(int arr[],int n){
       if(n==1){
            return ;
        }
        for(int i=1;i<n;i++){
         int key=arr[i];
         int j=i-1;
         while(j>=0&&arr[j]>key){
             arr[j+1]=arr[j];
             j--;
         }
         arr[j+1]=key;
        }
}
void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void merge(int arr[],int low,int mid,int high){
    int *temp=new int[high+1];
    int i=low;
    int j=mid+1;
    int k=low;
    while(i<=mid&&j<=high){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=high){
        temp[k++]=arr[j++];
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i];
    }
    delete temp;
}
void mergesort(int arr[],int low,int high){
    if(low<high){
        int mid=low+(high-low)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
void insert(int arr[],int val,int n){
  if(n==0||arr[n-1]<=arr[n]){
    arr[n]=val;
    return;
  }
  int temp=arr[n-1];
  insert(arr,val,n-1);
  arr[n]=temp;
}
void insertionsortrecursive(int arr[],int n){
    if(n==1){
        return;
    }
    int val=arr[n-1];
    n--;
    insertionsortrecursive(arr,n-1);
    insert(arr,val,n);
    
}
void insertrecursive(vector<int>&v,int val){
    if(v.size()==0||v[v.size()-1]<=val){
        v.push_back(val);
        return;
    }
    int temp=v[v.size()-1];
    v.pop_back();
    insertrecursive(v,val);
   v.push_back(temp);
}
void insertionsortr(vector<int>&v){
    if(v.size()==0){
        return;
    }
    int val=v[v.size()-1];
   v.pop_back();
   insertionsortr(v);
   insertrecursive(v,val);
}
int main(){
int arr[] = {4, 1, 3, 9, 7};
int n=5;
vector<int>v;
v.push_back(4);
v.push_back(1);
v.push_back(3);
v.push_back(9);
v.push_back(7);
// bubblesort(arr,n);
// insertionsort(arr,n);
// selectionsort(arr,n);
// mergesort(arr,0,n-1);
insertionsortrecursive(arr,n);
// insertionsortr(v);
// print(v);
printarray(arr,n);
    return 0;
}