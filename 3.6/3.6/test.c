#include <stdio.h>
//1.��ת����
//��������
//1.��ת������ÿ������nextָ��ǰһ�����ĵ�ַ��˫ָ��--��ָ��ָ��ǰ�棬���һ�����ͷ������ָ�룬һǰһ��
//  ---����������ǰ��
///��һ��ָ������ָ��NULL ���ڶ���ָ���ں��棬
//������ʱ�ڶ���ָ��ĺ���ĵ�ַ�޷�֪������ʱ��Ҫ������ָ��������¼�ڶ���ָ�����Ľ��ĵ�ַ
//struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* prev = NULL;
//    struct ListNode* cur = head;
//    struct ListNode* next =cur->next;
//    while (cur)
//    {
//        //������ת
//        cur->next = prev;
//        //����
//        prev = cur;
//        cur = next;
//        if (next)
//            next = next->next;
//    }
//    return head;
//}
//2.ȡԭ���ͷ�嵽������
//struct ListNode* reverseList(struct ListNode* head)
//{
//	struct ListNode* cur = head;
//	struct ListNode* newnode = NULL;
//	while (cur)
//	{
//		//����Ҫ��¼����cur������ĵ�ַ
//		struct ListNode* next = cur->next;
//		//ͷ��
//		cur->next = newnode;
//		newnode = cur;//����ͷָ��
//		cur = next;//curҪ������
//	}
//	return newnode;
//}
//3.�ϲ���������
//���������αȽ�ȡС�Ľ��β��
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//	if (list1 == NULL)
//		return pList2;
//	if (list2 == NULL)
//		return pList1;
//
//	struct ListNode* cur1 = List1, * cur2 = List2;
//	struct ListNode* head = NULL, * tail = NULL;
//	while (cur1 && cur2)//��������iһ�������ͽ���
//	{
//		if (cur1->val < cur2->val)
//		{
//			//��С��β��
//			//��һ��ʼΪ�յ�һ�����Ǹ�ֵ
//			if (head == NULL)
//			{
//				head = tail = cur1;
//			}
//			//����������������β��
//			tail->next = cur1;
//			tail = tail->next;
//			cur1 = cur1->next;
//		}
//		else (cur1->val > cur2->val)
//		{
//			//��С��β��
//			//��һ��ʼΪ�յ�һ�����Ǹ�ֵ
//			if (head == NULL)
//			{
//				head = tail = cur2;
//			}
//			//����������������β��
//			tail->next = cur2;
//			tail = tail->next;
//			cur2 = cur2->next;
//		}
//	}
//	//����������ָ��β�嵽tail����
//	//��������һ���������plistΪ��cur1Ϊ�գ���tail����NULL�����������Ҫ����
//	if (cur1)
//	{
//		tail->next = cur1;
//	}
//	else
//	{
//		tail->next = cur2;
//	}
//	return head;
//}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//����ͷ�ڱ�����ͷ���
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//	struct ListNode* cur1 = list1, * cur2 = list2;
//	struct ListNode* head = NULL, * tail = NULL;
//	struct ListNode* guard = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
//	while (cur1 && cur2)//��������iһ�������ͽ���
//	{
//		if (cur1->val < cur2->val)
//		{
//			//��С��β��
//			//��һ��ʼΪ�յ�һ�����Ǹ�ֵ
//			//����������������β��
//
//			tail->next = cur1;
//			tail = tail->next;
//			cur1 = cur1->next;
//		}
//		else
//		{
//			//��С��β��
//			//��һ��ʼΪ�յ�һ�����Ǹ�ֵ
//			//����������������β��
//
//			tail->next = cur2;
//			tail = tail->next;
//			cur2 = cur2->next;
//		}
//	}
//	//����������ָ��β�嵽tail����
//	//��������һ���������plistΪ��cur1Ϊ�գ���tail����NULL�����������Ҫ����
//	if (cur1)
//	{
//		tail->next = cur1;
//	}
//	else
//	{
//		tail->next = cur2;
//	}
//	head = guard->next;
//	free(guard);
//	return head;
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
�ָ�����--�����ڱ�ͷ���---���ȱȽϷֳ���������
�ϴ�ĵ�һ������ȡ����С�ĵ�һ������ȡ
�������������������
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        ListNode* Lguard, * Gguard, * ltail, * gtail;
        Lguard = ltail = (ListNode*)malloc(sizeof(ListNode));
        Gguard = gtail = (ListNode*)malloc(sizeof(ListNode));
        ltail->next = NULL;
        gtail->next = NULL;
        ListNode* cur = pHead;
        while (cur)
        {
            if (cur->val < x)
            {
                ltail->next = cur;
                ltail = ltail->next;
            }
            else {
                gtail->next = cur;
                gtail = gtail->next;
            }
            cur = cur->next;
        }
        ltail->next = Gguard->next;
        gtail->next = NULL;
        pHead = Lguard->next;
        free(Lguard);
        free(Gguard);
        return pHead;

    }
};
//���ⰸ�� 6 6 6 6 6  �Ƚ�val 5  ���������ڱ����ĺô�
//ת����--���������ݿ����������Ȼ������������ж�
//��������Ҫ��̬���ٵģ���Ϊ��������ʱ��֪����
//4.�ж������Ƿ�Ϊ���Ľṹ--�Գ�
//��һ�� ���ݿ���ָ���ҵ��м���
//�ڶ�����ת�м��֮�������
//��������ǰ�����������ת������ݽ��бȽ�
6.�����ཻ����
1.��ͳ˼·����cur1�ֵ�Ԫ�ض���cur2�е�Ԫ�ر�һ��--����ͬʱ�����ǵ�һ���ཻ�ĵ�
ʱ�临�Ӷ�Ϊn ^ 2
Ҫ��ʱ��O(N)�ռ�ΪO(1);
//�����ж��Ƿ��ཻ--�Ƚ�β���ĵ�ַ
//�ֱ�����������
//�����������߲�ಽ--��֪���ĸ�����Ҫ����һ��
//��ͬʱ�ߣ��Ƚϣ���һ����ַ��ͬ�ľ��ǽ��㡣
struct ListNode* cur1 = headA, * cur2 = headB;
int lena = 0;
int lenb = 0;
while (cur1->next)
{
    cur1 = cur->next;
    ++lena;
}
while (cur2->next)
{
    cur2 = cur2->next;
    ++lenb;
}
if (cur1 != cur2)
return NULL;
int gap = abs(lena - lenb);
struct ListNode* longlist = headA, * shortlist = headB;
if (lenb > lena)
{
    struct ListNode* longlist = headB, * shortlist = headA;
}
while (gap--)
{
    longlist = longlist->next;
}
while (longlist != shortlist)
{
    longlist = longlist->next;
    shortlist = shortlist->next;
}
return longlist;