#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node * prev;
    Node(int data,Node *next,Node *prev){
        this->data=data;
        this->next=next;
        this->prev=prev;
    }
    Node(int data){
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
    }
   
};
Node *insertbeforehead(Node *head,int val){
    Node *newHead=new Node(val,head,nullptr);
    head->prev=newHead;
    return newHead;
}
Node *insertbeforetail(Node *head,int val){
    //only one Node is their in LL
    if(head->next==NULL){
        return insertbeforehead(head,val);
    }
    Node *tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node *newNode=new Node(val,tail,tail->prev);
    tail->prev->next=newNode;
    tail->prev=newNode;
    return head;
}
Node *insertbeforethekthel(Node *head,int val,int k){
    if(k==1){
        return insertbeforehead(head,val);
    }
    Node *temp=head;
    int cnt=0;
    while(temp!=0){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    Node*newNode=new Node(val,temp,temp->prev);
    temp->prev->next=newNode;
    temp->prev=newNode;
    return head;
}
Node *insertbeforenode(Node *temp,int val){
    Node *prev=temp->prev;
    Node *newNode=new Node(val,temp,prev);
    prev->next=newNode;
    temp->prev=newNode;
}
Node *deletehead(Node* head){
    if(head==NULL || head->next==NULL){
        delete head;
        return NULL;
    }
    Node *prev=head;
    head=head->next;
    head->prev=nullptr;
    prev->next=nullptr;
    delete prev;
    return head;
}
Node *convertArray2DLL(vector <int>&arr){
    Node *head=new Node(arr[0]);
    Node *prev=head;
    for(int i=1;i<arr.size();i++){
        Node *temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
Node *deletetail(Node *head){
    if(head==NULL || head->next==NULL){
    delete head;
    return NULL;
    }
    Node *temp=head;
    while(temp->next!=NULL){
        //prev=temp; this is an SLL Approach not DLL approach
        temp=temp->next;
    }
    Node *prev=temp->prev;
    temp->prev=nullptr;
    prev->next=nullptr;
    delete temp;
    return head;
}

//k can be from 1 to n 
// n size of the DLL
//edge cases you have to see here are 
//head = prev is not their
//tail= next element is not their
Node *deleteatk(Node *head,int k){
    if(head==NULL) return NULL;
    Node *temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
        
    }
    if(temp==NULL) return head;
    Node *prev=temp->prev;
    Node *front=temp->next;
    if(prev==NULL && front==NULL) return NULL;
    else if(front==NULL){
        return deletetail(head); //you caused an mistake here 
    }
    else if(prev==NULL){
        return deletehead(head);
    }
    prev->next=front;
    front->prev=prev;
    temp->prev=nullptr;
    temp->next=nullptr;
    delete temp;
    return head;
}

void deletethenode(Node *temp){
//it will never delte head remember pls never Node!=Head 
Node *back=temp->prev;
Node *front=temp->next;
if(front==NULL){
    back->next=nullptr;
    temp->prev=nullptr;
    delete temp;
    return;
}
back->next=front;
front->prev=back;
temp->prev=nullptr;
temp->next=nullptr;
delete temp;
}
void printall(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.emplace_back(a);
    }
    Node *head=convertArray2DLL(arr);
    printall(head);
    head=deletehead(head);
    printall(head);
    head=deletetail(head);
    printall(head);
    head=deleteatk(head,2);
    printall(head); 
    deletethenode(head->next);
    printall(head); 
    head=insertbeforethekthel(head,23,2);
    printall(head);  
    return 0;
}