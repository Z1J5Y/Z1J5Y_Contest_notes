#include<iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *t1=l1,*t2=l2;
    ListNode *result=nullptr,*t=nullptr,*s;
    int temp=0,give=0;
    while(t1||t2)
    {
        if(t1) {temp+=t1->val;t1=t1->next;}
        if(t2) {temp+=t2->val;t2=t2->next;}
        temp+=give;
        if(!result) {result=new ListNode(temp%10);t=result;}
        else {s=new ListNode(temp%10);t->next=s;t=s;}
        give=temp/10;
        temp=0;
    }
    if(give)
    {
        s=new ListNode(temp%10);
        t->next=s;
        t=s;
    }
    return result;
}

int main()
{
    ListNode *a=new ListNode(9),*b=new ListNode(9);
    a->next=new ListNode(9),b->next=new ListNode(9);
    a->next->next=new ListNode(9),b->next->next=new ListNode(9);

    addTwoNumbers(b,a);
    return 0;
}