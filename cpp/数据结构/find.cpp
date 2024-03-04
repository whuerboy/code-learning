#include <iostream>
using namespace std;
/* ����һ�������� */
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
        pNewNode->m_key = data; // ���½ڵ��ֵ��ֵΪi
        pNewNode->next = NULL;
        p->next = pNewNode; // ��һ���ڵ�ָ������½����Ľڵ�
        p = pNewNode; // p�ڵ�ָ������µĽڵ�
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
    int n=0, m=0;//n���ڼ�����m���ڷ���
    int mn = p->next->m_key;//��������С������᲻һ����Ҫע��
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
   //���ٵ�����
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