//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

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

class Solution {
  public:
    Node* reverse(Node *head)
    {
        if(head == NULL || head -> next == NULL) return head;
        Node* newHead = reverse(head->next);
        Node* front = head -> next;
        front->next = head;
        head -> next = NULL;
        return newHead;
    }
    Node* addOne(Node* head) {
        if(head == NULL) return head;
        Node* newHead = reverse(head);
        int carry = 1,sum;
        Node *temp = newHead;
        while(temp!=NULL)
        {
            sum = temp -> data + carry;
            temp -> data = sum % 10;
            carry = sum / 10;
            if(carry == 0) break;
            temp = temp -> next;
        }
        if(carry == 0)
        {
            head = reverse(newHead);
            return head;
        }
        if(carry == 1)
        {
            head = reverse(newHead);
            Node *nn = new Node(carry);
            nn -> next = head;
            head = nn;
            return head;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends