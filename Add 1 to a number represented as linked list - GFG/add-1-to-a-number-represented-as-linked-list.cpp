//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node *head){
       Node *c=head,*p=NULL,*n=NULL;
       while(c){
           n=c->next;
           c->next=p;
           p=c;
           c=n;
            
       }
       return p;
        
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding on
        
        Node *temp=head;
        Node * re=reverse(head);
        Node * ans=re;
        int carry=1;
        while(re){
            if((re->data+carry)>=10){
                re->data=((re->data+carry)%10);
            }
            else{
                re->data=re->data+carry;
                carry=0;
            }
            if(re->next==NULL and carry>0){
                re->next=new Node(carry);
                break;
            }
            re=re->next;
        }
        Node *te=reverse(ans);
        return te;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends