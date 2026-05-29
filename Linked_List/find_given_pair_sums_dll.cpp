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
Node* bubblesort(Node *head){
    if(head==NULL || head->next==NULL) return head;
    Node* temp1=head,*temp2=head;
    while(temp1!=nullptr){
        while(temp2!=nullptr){
            if(temp1->data>temp2->data){
                int temp=temp1->data;
                temp1->data=temp2->data;
                temp2->data=temp;
            }
            temp2=temp2->next;
        }
        temp2=head;
            temp1=temp1->next;
    }
}
vector<pair<Node*,Node*>> find_pairs_gven_with_dll(Node * head,int sum){
    bubblesort(head);
    Node *temp1=head,*temp2;
    vector<pair<Node*,Node*>>mpp;
    while(temp1!=NULL){
        temp2=temp1->next;
        while(temp2!=NULL && temp1->data+temp2->data<=sum){
            if(temp1->data+temp2->data==sum){
                mpp.push_back({temp1,temp2});
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return mpp;
    
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
    int sum;
    cout<<"Enter the sum: ";
    cin>>sum;
    vector<pair<Node*,Node*>>mpp=find_pairs_gven_with_dll(head,sum);
    for(auto it:mpp){
        cout<<it.first->data<<" "<<it.second->data<<endl;
    }
    //printall(head);
    return 0;
}
