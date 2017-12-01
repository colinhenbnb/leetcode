#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode *l)
{
    ListNode * tmp = l;
    for (; tmp!=NULL; tmp = tmp->next) {
        cout<<tmp->val;
    }
    cout<<endl;
}


class Solution {
public:
    ListNode * appendList(ListNode *s, ListNode *n)
    {
        if (s == NULL) {
            s = n;
            return s;
        }

        ListNode *tmp = s;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }

        tmp->next = n;
        return s;
    }

    ListNode * addTwoNumbers(ListNode *l1, ListNode *l2){
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }

        ListNode* tmp1 = l1;
        ListNode* tmp2 = l2;
        ListNode* rst = NULL;
        int up = 0;

        while (1) {
            int v = 0;
            if (tmp1 != NULL) {
                v += tmp1->val;
                tmp1 = tmp1->next;
            }
            if (tmp2 != NULL) {
                v += tmp2->val;
                tmp2 = tmp2->next;
            }
            v += up;

            ListNode* node = new ListNode(0);
            node->val = v % 10;
            up = v/10;
            rst = appendList(rst, node);

            if (tmp1 == NULL && tmp2 == NULL) {
                if (up > 0) {
                    ListNode* node = new ListNode(0);
                    node->val = up;
                    rst = appendList(rst, node);
                }
                break;
            }
        }

        return rst;
    }
};

int main()
{
    ListNode *s1 = NULL;
    ListNode *s2 = NULL;
    ListNode *tmp = NULL;
    s1 = new ListNode(2);
    s2 = new ListNode(5);

    tmp = new ListNode(4);
    s1->next = tmp;
    tmp = new ListNode(3);
    s1->next->next = tmp;

    tmp = new ListNode(6);
    s2->next = tmp;

    tmp = new ListNode(4);
    s2->next->next = tmp;
    Solution doit;
    ListNode *rst = doit.addTwoNumbers(s1, s2);
    print(s1);
    print(s2);
    print(rst);

}
