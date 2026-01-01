#include<iostream>
#include<vector>
using namespace std;

// We can use class as well instead of struct
// Struct is similar to class, it just does not provides us with features like encapsulation, polymorphism etc.
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

int main(){
    vector<int>arr = {4,5,6,7};
    // One way
    Node x = Node(15);
    Node*y = &x;
    cout<<x.data<<endl;
    cout<<y<<endl;

    // Mostly used
    Node*z = new Node(200);
    cout<<z->data<<endl;
}