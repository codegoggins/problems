// Deletion & Insertion of Nodes in a LL

#include<iostream>
#include<vector>
using namespace std;

struct Node{
    public:
    int data;
    Node*next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

Node*deleteHead(Node*head){
    if(head == NULL) return head;

    Node*temp = head;
    head = head->next;
    delete temp;
    // free(temp); We can also use this
    return head;
}

// Remove tail node
Node* removeTail(Node*head){
    if(head == NULL)return head;
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node*temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

// Delete Kth Node from LL
Node* removeKthNode(Node* head, int K){
    // Empty LL
    if(head == NULL) return NULL;

    // Delete head of LL , K = 1
    if(K == 1){
        Node*temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int cnt=0;
    Node*temp = head;
    Node*prev = NULL;

    while(temp != NULL){
        cnt++;
        if(cnt == K){
            prev->next = prev->next->next;
            delete temp; // Temp points to the index which node I want to delete
            break;
        }
        prev = temp;
        temp = temp->next;

    }
    return head;
}

// Delete Kth Node from LL
Node* removeEl(Node* head, int el){
    // Empty LL
    if(head == NULL) return NULL;

    // Delete head of LL , K = 1
    if(head->data == el){
        Node*temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node*temp = head;
    Node*prev = NULL;

    while(temp != NULL){
        if(temp->data == el){
            prev->next = prev->next->next;
            delete temp; // Temp points to the index which node I want to delete
            break;
        }
        prev = temp;
        temp = temp->next;

    }
    return head;
}

// Insert New Node at Head
Node* insertNodeAtHead(Node* head, int el){
    Node*newHead = new Node(el);
    newHead->next = head;
    return newHead;
}

// Insert New Node at the tail
Node* insertNodeAtTail(Node*head, int el){
    // Empty LL
    if(head == NULL){
        Node*newNode = new Node(el);
        return newNode;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* newNode = new Node(el);
    temp->next = newNode;
    return head;
}

// Insert New Node at the Kth Position
Node* insertNodeAtTail(Node*head, int k, int el){
    // Empty LL
    if(head == NULL){
        Node*newNode = new Node(el);
        return newNode;
    }

    if(k == 1){
        Node*newNode = new Node(el);
        newNode->next = head;
        return newNode;
    }

    int cnt = 0;
    Node*temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k-1){
            Node*newNode = new Node(el);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;  
}

// Insert New Node before
Node* insertNodeAtTail(Node*head, int val, int el){
    // Empty LL
    if(head == NULL){
        // Can never find value so how can we insert below that
       return NULL;
    }

    if(head->data == val){
        Node*newNode = new Node(el);
        newNode->next = head;
        return newNode;
    }

    Node*temp = head;
    // We don't go to the last element in this case
    // We won't be able to access data and get error
    while(temp->next != NULL){
        if(temp->next->data == val){
            Node*newNode = new Node(el);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;  
}

void printLL(Node*head){
    Node*temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return;
}

Node*convertArrayToLL(vector<int>&v){
    Node*head = new Node(v[0]);
    Node*mover = head;
    for(int i=1;i<v.size();i++){
        Node*temp = new Node(v[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int main(){
    vector<int>arr = {1,2,4,5,6,8,24};
    Node*head = convertArrayToLL(arr);
    printLL(head);
    // Node*newHead = deleteHead(head);
    // printLL(newHead);
    Node*newHead = removeTail(head);
    printLL(newHead);
    return 0;
}