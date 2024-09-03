#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};



int main()
{
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int num1 = 0;
    int num2 = 0;
    struct ListNode* iter1 = l1;
    struct ListNode* iter2 = l2;
    int i = 1;
    while(iter1 != NULL){
        num1 += iter1->val * i;
        iter1 = iter1->next;
        i *= 10;
    }
    i = 1;
    while(iter2 != NULL){
        num2 += iter2->val * i;
        iter2 = iter2->next;
        i *= 10;
    }

    int num3 = num1 + num2;
    int temp = 0;
    struct ListNode *l3 = malloc(sizeof(struct ListNode));
    struct ListNode* iter3 = l3;
    l3->val = 0;
    while(num3 != 0){
        temp = num3 % 10;
        num3 = num3 / 10;
        iter3->val = temp;
        if(num3 != 0){
            iter3->next = malloc(sizeof(struct ListNode));
            iter3 = iter3->next;
        }
        else {
        iter3->next = NULL;
    }
    }
    iter3-> next =NULL;
    iter3 = l3;
    while(iter3!= NULL){
        iter3 = iter3->next;
    }

    return l3;
}

}
