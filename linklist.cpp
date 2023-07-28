#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
void printnode(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
node *createnode(int data)
{
    struct node *ptr;
    ptr = new struct node;
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}
void setnode(struct node *ptr1, struct node *ptr2)
{
    ptr1->next = ptr2;
    ptr2->next = NULL;
}
node *createandsetnode()
{
    node *head = NULL;
    node *ptr = NULL;
    int choice = 1;
    while (choice)
    {
        node *temp = new struct node;
        cout << "enter the data you want to insert in the node" << endl;
        int data;
        cin >> data;
        if (head == NULL)
        {
            temp->data = data;
            temp->next = NULL;
            head = temp;
            ptr = head;
        }
        else
        {
            temp->data = data;
            temp->next = NULL;
            ptr->next = temp;
            ptr = temp;
        }
        cout << "kaise beta exit karna hai yaha sei agar ha toh beta 0 dabao\n";
        cin >> choice;
    }
    return head;
}
node *insertathead(node *head, int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    temp->next = head;
    head = temp;
    return head;
}
node  *insertatbetween(node *head,int data,int position){
    int i=0;
    struct node *temp=new struct node;
    temp->data=data;
    temp->next=NULL;
    if(head==NULL)return temp;
    struct node *ptr1=head;
    struct node *ptr2=head->next;
     
    //  0    1     2     3   4
    //  1    2     3     4   5
    while(i!=position-1){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
        i++;
    }
    temp->next=ptr2;
    ptr1->next=temp;
    return head;
}
node *insertattheend(node*head,int data){
    node *ptr=head;
    struct node *temp=new struct node;
    temp->data=data;
    temp->next=NULL;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    return head;
}
node *deleteatfront(node *head){
    if(head==NULL)return head;
 node *temp=head;
 head=head->next;
 delete temp;
 return head;
}
// 0   1   2   3    4
// 1   2   3   4    5
node *deleteatbetween(node *head,int pos){
    if(head==NULL)return head;
     node *ptr1=head;
    node *ptr2=head->next;
    int i=0;
    while(i!=pos-1){
ptr1=ptr1->next;
        ptr2=ptr2->next;
        i++;
    }
    ptr1->next=ptr2->next;
    delete ptr2;
    return head;
}
node *deletelast(node *head){
    node *ptr1=head;
    node *ptr2=head->next;
    while(ptr2->next!=NULL){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    ptr1->next=NULL;
    delete ptr2;
    return head;
}
//                 prev curr next
//  1    2    3    4     5
node *reverse(node *head){
    node *curr=head;
    node *prev=NULL;
    node *next=NULL;
   while(curr!=NULL){
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
   }
   return prev;
}
node *reverserecursive(node *head){
    if(head==NULL||head->next==NULL)return head;
     node *newhead=reverserecursive(head->next);
        head->next->next=head;
        head->next=NULL;
        return newhead;
}
void printcircularnode(node *head){
    node *ptr=head;
    while(ptr->next!=head){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<ptr->data<<endl;
}
node *createandsetcircularlinklist(){
     node *head = NULL;
    node *ptr = NULL;
    int choice = 1;
    while (choice)
    {
        node *temp = new struct node;
        cout << "enter the data you want to insert in the node" << endl;
        int data;
        cin >> data;
        if (head == NULL)
        {
            temp->data = data;
            temp->next = NULL;
            head = temp;
            ptr = head;
        }
        else
        {
            temp->data = data;
            temp->next = NULL;
            ptr->next = temp;
            ptr = temp;
        }
        cout << "kaise beta exit karna hai yaha sei agar ha toh beta 0 dabao\n";
        cin >> choice;
    }
    ptr->next=head;
    return head;
}
node * insertatheadincircular(node *head,int data){
     node *ptr=new struct node;
     ptr->data=data;
     node *temp=head;
     while(temp->next!=head){
       temp=temp->next;
     }
     ptr->next=temp->next;
     temp->next=ptr;
     return ptr;
}
//between code is same as above 

node *insertatendcircular(node *head,int data){
    node *ptr=new struct node;
     ptr->data=data;
     ptr->next=NULL;
     node *temp=ptr;
     while(temp->next!=head){
        temp=temp->next;
     }
ptr->next=temp->next;
temp->next=ptr;
     return head;
}
node *deletefrontcircularlist(node *head){
    node *ptr=head;
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    ptr->next=head->next;
    node *temp=head;
    head=head->next;
    delete temp;
    return head;
}

//delete between from the circular linklist is the same as the above 

node *deletebackfromcircularlist(node *head){
    node *ptr1=head;
    node *ptr2=head->next;
    while(ptr2->next!=head){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    ptr1->next=ptr2->next;
    delete ptr2;
    return head;
}

//reverse a circular linklist 
// c  n       p
//1->2->3->4->5

//<-1-<-2<-3<-4<-5
void iterativereversecircularlist(node **head){
    if(*head==NULL)return;
    node *prev=NULL;
    node *curr=(*head);
    node *next=NULL;
     do{
      next=curr->next;
      curr->next=prev;
      prev=curr;
      curr=next;
     }while(curr!=(*head));
     curr->next=prev;
     *head=prev;
}
//write its recursive approach also

struct Node {
    Node *prev;
    int data;
    Node *next;
};
Node *createnodedoubly(int data)
{
    struct Node *ptr;
    ptr = new struct Node;
    ptr->prev=NULL;
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}
void setnodedoubly(struct Node *ptr1, struct Node *ptr2)
{
    ptr1->prev=NULL;
    ptr1->next = ptr2;
    ptr2->prev=ptr1;
    ptr2->next = NULL;
}
void printnodedoubly(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
Node *insertatfirstdoubly(Node *head,int data){
    Node *newhead=new struct Node;
    newhead->data=data;
    newhead->next=head;
    head->prev=newhead;
    return newhead;
}
//                 ptr1  ptr2
//       0      1    2    3    4
// null<-1<--><-2-><-3-><-4-><-5->null
Node *insertatbetweendoubly(Node *head,int data,int pos){
Node *temp=new Node;
temp->data=data;
temp->prev=NULL;
temp->next=NULL;
int i=0;
Node *ptr1=head;
Node *ptr2=head->next;
while(i!=pos-1){
    i++;
    ptr1=ptr1->next;
    ptr2=ptr2->next;
}
temp->next=ptr2;
ptr2->prev=temp;
ptr1->next=temp;
temp->prev=ptr1;
return head;
}
Node *insertatlastdoubly(Node *head,int data){
    Node *temp=new Node;
temp->data=data;
temp->prev=NULL;
temp->next=NULL;
Node *ptr1=head;
while(ptr1->next!=NULL){
    ptr1=ptr1->next;
}
ptr1->next=temp;
temp->prev=ptr1;
return head;
}
Node *deletefirstnodedoubly(Node *head){
    Node *ptr1=head;
    head=head->next;
    head->prev=NULL;
    delete ptr1;
    return head;
}
Node *deletebetweendoubly(Node *head,int pos){
int i=0;
Node *ptr1=head;
Node *ptr2=head->next;
while(i!=pos-1){
    i++;
    ptr1=ptr1->next;
    ptr2=ptr2->next;
}
Node *next=ptr2->next;
next->prev=ptr1;
ptr1->next=next;
delete ptr2;
return head;
}
Node *deletelastnodedoubly(Node *head){
    Node *ptr1=head;
    Node *ptr2=head->next;
    while(ptr2->next!=NULL){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    ptr1->next=NULL;
    delete ptr2;
    return head;
}
Node* reverse(Node *head){
 if(head==NULL||head->next==NULL){
    return head;
}
Node *curr=head;
while(curr->next!=NULL){
    curr=curr->next;
}
head=curr;
while(curr!=NULL){
    Node *temp=curr->next;
    curr->next=curr->prev;
    curr->prev=temp;
    curr=curr->next;
}   
return head;
}
int main()
{
    //    node *ptr1=createnode(1);
    //   node * ptr2=createnode(2);
    //   node * ptr3=createnode(3);
    //    node * ptr4=createnode(4);
    //   node * ptr5=createnode(5);
    //    setnode(ptr1,ptr2);
    //    setnode(ptr2,ptr3);
    //    setnode(ptr3,ptr4);
    //    setnode(ptr4,ptr5);
    // node *ptr1 = createandsetnode();
    // ptr1 = insertathead(ptr1, 0);
    // ptr1=insertatbetween(ptr1,10,2);
    // ptr1=insertattheend(ptr1,6);
    // ptr1=deleteatfront(ptr1);
    // ptr1=deleteatbetween(ptr1,2);
    // ptr1=deletelast(ptr1);
    // ptr1=reverse(ptr1);
    // ptr1=reverserecursive(ptr1);
    // printnode(ptr1);
    //   node *ptr1=createnode(1);
    //   node * ptr2=createnode(2);
    //   node * ptr3=createnode(3);
    //    node * ptr4=createnode(4);
    //   node * ptr5=createnode(5);
    //    setnode(ptr1,ptr2);
    //    setnode(ptr2,ptr3);
    //    setnode(ptr3,ptr4);
    //    setnode(ptr4,ptr5);
    //    ptr5->next=ptr1;
    //    ptr1=insertatheadincircular(ptr1,0);
    // ptr1=insertatendcircular(ptr1,6);
    // ptr1=deletefrontcircularlist(ptr1);
    // ptr1=deletebackfromcircularlist(ptr1);
    // iterativereversecircularlist(&ptr1);
    //    printcircularnode(ptr1);

    Node *ptr1=createnodedoubly(1);
      Node * ptr2=createnodedoubly(2);
      Node * ptr3=createnodedoubly(3);
       Node * ptr4=createnodedoubly(4);
      Node * ptr5=createnodedoubly(5);
       setnodedoubly(ptr1,ptr2);
       setnodedoubly(ptr2,ptr3);
       setnodedoubly(ptr3,ptr4);
       setnodedoubly(ptr4,ptr5);
       //ptr1=insertatfirstdoubly(ptr1,0);
    //    ptr1=insertatbetweendoubly(ptr1,6,3);
    // ptr1=insertatlastdoubly(ptr1,6);
    // ptr1=deletefirstnodedoubly(ptr1);
    // ptr1=deletebetweendoubly(ptr1,2);
    // ptr1=deletelastnodedoubly(ptr1);
    ptr1=reverse(ptr1);
       printnodedoubly(ptr1);
    return 0;
}