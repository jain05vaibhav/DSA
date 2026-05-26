#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data,Node *next){
        this->data=data;
        this->next=next;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

Node* convertvector2LL(vector<int> &arr){
    if(arr.empty()) return NULL;
    Node *head=new Node(arr[0]);
    Node *mover=head;
    for(int i=1;i<arr.size();i++){
        Node *temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

void printall(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node *sort012(Node *head){
    Node* temp=head;
    int cnt0=0,cnt1=0,cnt2=0;
    while(temp!=0){
        if(temp->data==0) cnt0++;
        else if(temp->data==1) cnt1++;
        else cnt2++;
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(cnt0){
             temp->data=0;
             cnt0--;
        }
        else if(cnt1){ 
            temp->data=1;
            cnt1--;
        }
        else if(cnt2){
            temp->data=2;
            cnt2--;
        }
        temp=temp->next; 
    }
    return head;
}

Node *sort012_optimal(Node *head){
    if(head==NULL || head->next==NULL) return head;
    Node *zeroHead=new Node(-1),*zero=zeroHead;
    Node *oneHead=new Node(-1),*one=oneHead;
    Node *twoHead=new Node(-1),*two=twoHead;
    Node *temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            zero->next=temp;
            zero=temp;
        }else if(temp->data==1){
            one->next=temp;
            one=temp;
        }else{
            two->next=temp;
            two=temp;
        }
        temp=temp->next;
    }
    zero->next=(oneHead->next!=NULL)?oneHead->next:twoHead->next;
    one->next=twoHead->next;
    two->next=NULL;

    Node *newHead=zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return newHead;
}

int main(){
    vector<int>arr;
    int a;
    cin>>a;
    while(a!=-1){
        arr.push_back(a);
        cin>>a;
    }

    Node *head=convertvector2LL(arr);
    head=sort012_optimal(head);
    printall(head);
    
    return 0;
}
