#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data, Node *next){
        this->data = data;
        this->next = next;
    }
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

Node* convertvector2LL(vector<int> &arr){
    if(arr.empty()) return nullptr;
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printall(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *reverse(Node *head){
    Node *temp=head,*prev=nullptr;
    while(temp!=NULL){
        Node *front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;

    }
    return prev;
}
Node *add_1_toLL(Node *head){
    head=reverse(head);
    int carry=1;
    Node *temp=head;
    while(temp!=NULL){
        temp->data=temp->data+carry;
        if(temp->data<10) {
            carry=0;
            break;
        }else{
            temp->data=0;
            carry=1;
        }
        temp=temp->next;
    }
    if(carry==1){
        Node *newNode=new Node(1);
        head=reverse(head);
        newNode->next=head;
        return newNode;
    }
    head=reverse(head);
    return head;
}
int helper(Node * head){
    if(head==NULL) return 1;
    int carry=helper(head->next);
    head->data=head->data+carry;
    if(head->data<10){
        return 0;
    }
    head->data=0;
    return 1;
}
Node *add_1_toLL_Optimal(Node *head){
    int carry=helper(head);
    if(carry==1){
            Node *newNode=new Node(1);
            newNode->next=head;
            return newNode;
    }
    return head;
}


int main(){
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    Node *head = convertvector2LL(arr);
    printall(head);
    head = add_1_toLL_Optimal(head);
    printall(head);
    return 0;
}
