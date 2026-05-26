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

Node* middleNode(Node *head){
    if(head == NULL) return NULL;
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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
    arr.
    Node *head = convertvector2LL(arr);
    printall(head);

    Node *middle = middleNode(head);
    if(middle != NULL){
        cout << middle->data << endl;
    }

    return 0;
}
