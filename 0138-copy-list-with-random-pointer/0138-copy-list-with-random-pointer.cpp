/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
void insertCopyInBetween(Node* head){
     Node* temp=head;
        while(temp){
            Node* nextelement=temp->next;
            Node* copy=new Node(temp->val);
            
            copy->next=nextelement;
            temp->next=copy;
            temp=nextelement;


        }
}

void connectRandompointer(Node*head){
    Node* temp=head;
    
    while(temp){
        Node* copyNode=temp->next;
        if(temp->random){
            copyNode->random=temp->random->next;
        }else{
            copyNode->random=NULL;
        }
        temp=temp->next->next;
    }
}
Node* getDeepCopyList(Node* head){
    Node* dummynode=new Node(-1);
    Node* res=dummynode;
    Node* temp=head;
    while(temp){
        res->next=temp->next;
        temp->next=temp->next->next;
        res=res->next;
        temp=temp->next;
    }
    return dummynode->next;
}

    Node* copyRandomList(Node* head) {
        insertCopyInBetween(head);
        connectRandompointer(head);
        return getDeepCopyList(head);
        
    }
};