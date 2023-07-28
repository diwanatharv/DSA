//storage
//insertion end
//deletion
//front,enqueue,dequeue,empty,full,firstval,lastval,peek
#include<bits/stdc++.h>
using namespace std;

// struct queues{
// int front;
// int back;
// int size;
// int *arr;
// };
// bool isempty(queues *q){
//     if(q->front==q->back){
//         return true;
//     }
//     return false;
// }
// bool isfull(queues *q){
//     if(q->back==q->size-1)return true;
//     return false;
// }
// void enqueue(queues *q,int data){
//     if(isfull(q)){
//         cout<<"no jagah baaki";
//         return ;
//     }
//     q->back++;
//     q->arr[q->back]=data;
// }
// int dequeue(queues *q){
//     if(isempty(q)){
//         cout<<"kuch nahi hai";
//         return -1;
//     }
//     q->front++;
//     int temp=q->arr[q->front];
//     return temp;
// }
// int firstval(queues *q){
//     if(isempty(q))return -1;
//     q->front++;
//   int temp=q->arr[q->front];
//     return temp;
// }
// int lastval(queues *q){
//     if(isfull(q))return -1;
//     return q->arr[q->back];
// }
struct queues{
struct queues *next;
int data;
};
bool isempty(queues *front,queues *back){
    if(front==NULL&&back==NULL){
        return true;
    }
    return false;
}
bool isfull(){
    queues *n=new queues;
    if(n==NULL)return true;
    return false;
}
void enqueue(queues *&front,queues *&rear,int data){
    if(isfull())
    {cout<<"beta jagah nahi hain ";
    return;
    }
    queues *temp=new struct queues;
    temp->data=data;
    temp->next=NULL;
    if(front==NULL&&rear==NULL){
     front=rear=temp;
    }else{
     rear->next=temp;
     rear=temp;
    }
}
int dequeue(queues *&front,queues *rear){
    if(isempty(front,rear)){
        cout<<"beta nahi hai kuch isme";
         return -1;
    }
int temp=front->data;
front=front->next;
return temp;
}
int firstval(queues *front){
    if(front==NULL){
        return -1;
    }
    return front->data;
}
int lastval(queues *rear){
    if(rear==NULL){
        return -1;
    }
    return rear->data;
}
int main(){
    // queues *q;
    // q->front=-1;
    // q->back=-1;
    // q->size=10;
    // q->arr=new int[q->size];
    // enqueue(q,1);
    // enqueue(q,2);
    // enqueue(q,3);
    // enqueue(q,4);
    // cout<<dequeue(q);
    // cout<<dequeue(q);
    // cout<<firstval(q);
   queues *front=NULL;
   queues *back=NULL;
enqueue(front,back,1);
enqueue(front,back,2);
enqueue(front,back,3);
dequeue(front,back);
cout<<firstval(front);
cout<<lastval(back);
    return 0;
}
