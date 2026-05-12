#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data,Node *next){
        this->data=data;
        this->next=next;
    }
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
   
};
//Deletion of HeAD
Node *deleteHead(Node* head){
    if(head==NULL) return head;
    Node* temp=head;
    head=head->next;
    free(temp); //No need of this in java garbage collector you way
    return head;
}
Node *deleteTail(Node *head){
    Node* temp=head;
    if((head==NULL) || (head->next==NULL)) return NULL;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;
    return head;
}
 Node* convertvector2LL(vector<int>nums){
        Node *head=new Node(nums[0]);
        Node *mover=head;
        for(int i=1;i<nums.size();i++){
            Node *temp=new Node(nums[i]);
            mover->next=temp;
            mover=mover->next;
        }
        return head;
    }
int LLtraversal(Node *head){
    int c=0;
    Node *temp=head;
    while(temp!=NULL){
        c++;
        //cout<<temp->data<<" ";
        temp=temp->next;
    }
    return c;
}
int lengthofLL(Node *head,int f){
    Node *temp=head;
    int c=0;
    while(temp!=NULL){
        c++;
        if(temp->data==f){
            return c;            
        }
        temp=temp->next;
    }
    return -1;
}
//Priniting all elements
void printall(Node *head){
     Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node *deletek(Node *head,int k){
    if(head==NULL) return head;
    if(k==1){
       Node* temp=head;
        head=head->next;
        temp->next=NULL;
        free(temp);
        return head;
    }
    int cnt=0;
    Node *temp=head,*prev=NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            temp->next=NULL;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
Node *deletebyel(Node *head,int data){
    if(head==NULL) return head;
    if(head->data==data){
       Node* temp=head;
        head=head->next;
        temp->next=NULL;
        free(temp);
        return head;
    }
    Node *temp=head,*prev=NULL;
    while(temp!=NULL){
        if(temp->data==data){
            prev->next=prev->next->next;
            temp->next=NULL;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
Node *insertathead(Node *head,int val){
    return new Node(val,head);
}
Node *insertatk(Node *head,int value,int k){
    if(head==NULL){
        if(k==1){
            return new Node(value);
        }
        else{
            return head;
        }
    }
    if(k==1){
        return new Node(value,head);
    }
    int cnt=0;
    Node *temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k-1){
            Node *x=new Node(value,temp->next);
            temp->next=x;
            break;
        }

        temp=temp->next;
    }
    return head;
}

Node *insertelbeforex(Node *head,int value,int k){
    if(head==NULL){
       return head;
    }
    if(k==1){
        return new Node(value,head);
    }
    Node *temp=head;
    while(temp->next!=NULL){
        if(temp->next->data==value){
            Node *x=new Node(value,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}
int main(){
    vector<int>arr={12,1,3,8};
    Node *head=convertvector2LL(arr);
    cout<<head->data<<" "<<endl;
   head=deleteHead(head);
   printall(head);
   cout<<endl;
   head=deleteTail(head);
   printall(head);
   head=deletebyel(head,3);
   cout<<endl;
   printall(head);
   head=deletek(head,1);
   printall(head);
   head=insertatk(head,3,1);
   printall(head);
    return 0;
}
