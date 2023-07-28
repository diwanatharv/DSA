#include<bits/stdc++.h>
using namespace std;
//drawbacks of queue using array space is not efficiently managed 
//elements deleted there space cannot be used
//circular increment%n
//main concept is that your front and back will start from 0
struct queues {
int front;
int rear;
int size;
int *arr;
};
bool isempty(queues *q){
    if(q->front==-1||q->rear<q->front){
        return true;
    }
    return false;
}
bool isfull(queues *q){
    if((q->rear+1)%q->sizn==q->front||q->front==-1){
     return true;
    }
    return false;
}
void enqueue(queues *&q,int val){
 if(isfull(q)){
    cout<<"beta kahe queue overflow karvane mai tule ho";
    return ;
 }
 q->rear=(q->rear+1)%q->size;
 q->arr[q->rear]=val;
}
int dequeue(queues *&q){
    if(isempty(q)){
        cout<<"kuch nahi hai";
        return -1; 
    }
    q->front=(q->front+1)%q->size;
    int temp=q->arr[q->front];
    return temp;
}
int main(){
    queues *q;
    q->front=-1;
    q->front=-1;
    q->size=5;
    q->arr=new int[q->size];
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    enqueue(q,6);
    return 0;
}