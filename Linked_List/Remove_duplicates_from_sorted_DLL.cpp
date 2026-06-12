#include<iostream>
#include<vector>
#include<stack>
#include<map>
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

Node* bubblesort(Node* head){
    if(head==nullptr || head->next==nullptr) return head;

    bool swapped;

    do{
        swapped = false;
        Node* temp = head;

        while(temp->next){
            if(temp->data > temp->next->data){
                swap(temp->data,temp->next->data);
                swapped = true;
            }
            temp = temp->next;
        }
    }while(swapped);

    return head;
}
Node *remove_duplicates_from_sorted_DLL(Node *head){
    Node *temp=head;
    while(temp!=NULL && temp->next!=NULL){
        Node *nextNode=temp;
        while(nextNode!=NULL && nextNode->data==temp->data){
            Node *duplicate=nextNode;
            nextNode=nextNode->next;
            delete duplicate;
        }
        temp->next=nextNode;
       if(nextNode!=NULL) nextNode->prev=temp;
        temp=temp->next;
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
    head=bubblesort(head);
    cout<<"After sorting: ";
    printall(head);
    head= remove_duplicates_from_sorted_DLL(head);
    printall(head);
    return 0;
}
