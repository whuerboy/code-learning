#include <iostream>
using namespace std;
/* 创建一个单链表 */
struct ListNode {
    int m_key;
    ListNode* next;
};
void createList(ListNode* pHead,int length) {
    ListNode* p = pHead;
    for (int i = 0; i < length; ++i) {
        ListNode* pNewNode = new ListNode;
        int data;
        cin >> data;
        pNewNode->m_key = data; // 将新节点的值赋值为i
        pNewNode->next = NULL;
        p->next = pNewNode; // 上一个节点指向这个新建立的节点
        p = pNewNode; // p节点指向这个新的节点
    }
}

//void PrintList(ListNode* phead) {
//    ListNode* p = phead;
//    ListNode* m = p->next;
//    do {
//        cout << m->m_key << " ";
//        p = m->next;
//        m = p;
//    } while (m->next != NULL);
//    cout << m->m_key << endl;
//    
//}

int FindMin(ListNode* phead,int length) {
    ListNode* p = phead;
    if (!p) {
        return -1; 
    }
    int n=0, m=0;//n用于计数，m用于返回
    int mn = p->next->m_key;//找最大和最小的这里会不一样，要注意
    while (p->next) {
        p = p->next;
        n++;
        if (mn >= p->m_key) {
            mn = p->m_key;
            m = n;
        }
    }
    return m;
}

int main5() {
    ListNode* head = NULL;
    head = new ListNode;
    head->m_key = 0;
    head->next = NULL;
    int length;
    cin >> length;
    createList(head,length);
   int m= FindMin(head, length);
   cout <<  m << endl;
   //销毁单链表
   {
       ListNode* pre, * p;
       pre = head; p = pre->next;
       while (p != NULL) {
           delete pre;
           pre = p;
           p = p->next;
       }
       delete p;
       p = NULL; pre = NULL;
   }


    return 0;
}