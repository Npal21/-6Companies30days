
//Link: https://www.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1

/*
    struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
         Node *curr = head, *t;
        while (curr != nullptr) { 
            for (int i = 1; i < m && curr!= nullptr; i++) 
                curr = curr->next; 
                
            if (curr == nullptr) 
                return head; 
            
            t = curr->next; 
            for (int i = 1; i <= n && t!= nullptr; i++) { 
                Node *temp = t; 
                t = t->next; 
                delete(temp); 
            }
            curr->next = t; 
            curr = t;
        }
        return head;
    }
};