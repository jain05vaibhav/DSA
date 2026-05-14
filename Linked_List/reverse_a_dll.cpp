#include<iostream>
#include<vector>
#include<stack>
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
//Brute Force Solution
Node* reverse_a_dll(Node *head){
    Node *temp=head;
    stack<int> st;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}
//Better Solution
Node *reverse_a_dll_better(Node * head){
    //Start by explaining from sctrach like how u cam up with a third variale you got the idea from swap(a,b)
    //that you considered first node then swapping the nodes then you ended up with swapping only the pointers to next and prev nodes 
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *prev=NULL;
    Node *current=head;
    Node *last=nullptr;
    while(current!=NULL){
        last=current->next;
        current->next=current->prev;
        current->prev=last;
        current=current->next;
    }
    return last->back;
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
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.emplace_back(a);
    }
    Node *head=convertArray2DLL(arr);
    head=reverse_a_dll(head);
    printall(head);
    head=reverse_a_dll_better(head);
    printall(head);
    return 0;
}
