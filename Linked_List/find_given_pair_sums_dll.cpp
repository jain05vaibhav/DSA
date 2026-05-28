#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//given DLL is sorted in order 
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

Node *delete_all_occurences_of_a_key(Node * head,int key){
    Node *temp=head;
    while(temp!=nullptr){
        if(temp->data==key){
            if(temp==head) head=head->next;
            Node *prevNode=temp->prev;
            Node *nextNode=temp->next;
            if(prevNode) prevNode->next=nextNode;
            if(nextNode) nextNode->prev=prevNode;
        }else temp=temp->next;
    }
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
    cout<<"Enter the size of the DLL: ";
    cin>>n;
    vector<int>arr;
    cout<<"Enter the elements of the DLL:";
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.emplace_back(a);
    }
    Node *head=convertArray2DLL(arr);
    printall(head);
    int k;
    cout<<"Enter the Key To delete: ";
    cin>>k;
    head=delete_all_occurences_of_a_key(head,k);
    printall(head);
    return 0;
}
