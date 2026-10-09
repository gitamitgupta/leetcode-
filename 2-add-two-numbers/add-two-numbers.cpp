
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1= l1;
        ListNode* temp2=l2;
        ListNode* c = new ListNode(10);
        ListNode* dumm =c;
        int carry =0;
        while(temp1!= nullptr && temp2!=nullptr){
            int v = carry + temp1->val +temp2->val;
            int nodeval = v%10;
           if(v>9) carry = v/10;
           else carry =0;
            ListNode* temp =new ListNode(nodeval);
            c->next =temp;
            c=c->next;
            temp1=temp1->next;
            temp2= temp2->next;
        }
        if(temp2 ==nullptr && temp1!=nullptr){
          while(temp1!=nullptr) {
            int v = carry + temp1->val;
            int nodeval = v%10;
           if(v>9) carry = v/10;
           else carry =0;
            ListNode* temp =new ListNode(nodeval);
            c->next = temp;
            c=c->next;
            temp1=temp1->next;
            }
        }
        if(temp2 !=nullptr && temp1==nullptr){
         while(temp2!=nullptr)  { 
            int v = carry + temp2->val;
            int nodeval = v%10;
           if(v>9) carry = v/10;
           else carry =0;
            ListNode* temp =new ListNode(nodeval);
            c->next = temp;
            c=c->next;
            temp2=temp2->next;
            }
        }
        if(carry !=0) {ListNode* tempk =new ListNode(carry);
        c->next= tempk;}
        return dumm->next;
    }
};