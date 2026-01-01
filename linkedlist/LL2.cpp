// Convert an array to a Linked List
#include<iostream>
#include<vector>
using namespace std;

struct Node {
    public:
    int data;
    Node*next;

    public:
    Node(int val){
       data = val;
       next= NULL;
    }
};

Node* convertArrayToLL(vector<int>&v){
    Node*head = new Node(v[0]);
    Node*mover = head;
    for(int i=1;i<v.size();i++){
        Node*temp = new Node(v[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Length of LL
int findLengthOfLL (Node*head){
    Node*temp = head;
    int len = 0;
    while(temp){
        len++;
        temp = temp->next;
    }
    return len;
}

int main(){
    vector<int>arr = {4,5,6,7,8};
    Node*head = convertArrayToLL(arr);
    cout<<findLengthOfLL(head)<<endl;
    return 0;
}
