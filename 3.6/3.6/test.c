#include <stdio.h>
//1.反转链表
//两个方法
//1.逆转方向，让每个结点的next指向前一个结点的地址，双指针--将指针指向前面，最后一个变成头。两个指针，一前一后
//  ---单链表不能往前走
///第一个指针首先指向NULL ，第二个指针在后面，
//不过这时第二个指针的后面的地址无法知道，这时需要第三个指针用来记录第二个指针后面的结点的地址
//struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* prev = NULL;
//    struct ListNode* cur = head;
//    struct ListNode* next =cur->next;
//    while (cur)
//    {
//        //方向逆转
//        cur->next = prev;
//        //迭代
//        prev = cur;
//        cur = next;
//        if (next)
//            next = next->next;
//    }
//    return head;
//}
//2.取原结点头插到新链表
//struct ListNode* reverseList(struct ListNode* head)
//{
//	struct ListNode* cur = head;
//	struct ListNode* newnode = NULL;
//	while (cur)
//	{
//		//首先要记录下来cur后面结点的地址
//		struct ListNode* next = cur->next;
//		//头插
//		cur->next = newnode;
//		newnode = cur;//更新头指针
//		cur = next;//cur要往后走
//	}
//	return newnode;
//}
//3.合并两个链表
//方法：依次比较取小的结点尾插
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//	if (list1 == NULL)
//		return pList2;
//	if (list2 == NULL)
//		return pList1;
//
//	struct ListNode* cur1 = List1, * cur2 = List2;
//	struct ListNode* head = NULL, * tail = NULL;
//	while (cur1 && cur2)//当其中有i一个结束就结束
//	{
//		if (cur1->val < cur2->val)
//		{
//			//将小的尾插
//			//但一开始为空第一步就是赋值
//			if (head == NULL)
//			{
//				head = tail = cur1;
//			}
//			//接下来才是真正的尾插
//			tail->next = cur1;
//			tail = tail->next;
//			cur1 = cur1->next;
//		}
//		else (cur1->val > cur2->val)
//		{
//			//将小的尾插
//			//但一开始为空第一步就是赋值
//			if (head == NULL)
//			{
//				head = tail = cur2;
//			}
//			//接下来才是真正的尾插
//			tail->next = cur2;
//			tail = tail->next;
//			cur2 = cur2->next;
//		}
//	}
//	//将长的链表指针尾插到tail后面
//	//不过还有一种情况就是plist为空cur1为空，则tail还是NULL，这种情况需要讨论
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

//带有头哨兵卫的头结点
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//	struct ListNode* cur1 = list1, * cur2 = list2;
//	struct ListNode* head = NULL, * tail = NULL;
//	struct ListNode* guard = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
//	while (cur1 && cur2)//当其中有i一个结束就结束
//	{
//		if (cur1->val < cur2->val)
//		{
//			//将小的尾插
//			//但一开始为空第一步就是赋值
//			//接下来才是真正的尾插
//
//			tail->next = cur1;
//			tail = tail->next;
//			cur1 = cur1->next;
//		}
//		else
//		{
//			//将小的尾插
//			//但一开始为空第一步就是赋值
//			//接下来才是真正的尾插
//
//			tail->next = cur2;
//			tail = tail->next;
//			cur2 = cur2->next;
//		}
//	}
//	//将长的链表指针尾插到tail后面
//	//不过还有一种情况就是plist为空cur1为空，则tail还是NULL，这种情况需要讨论
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
分割链表--带有哨兵头结点---首先比较分成两个链表
较大的到一个链表取，较小的到一个链表取
最后将两个链表链接起来
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
//特殊案例 6 6 6 6 6  比较val 5  分析带有哨兵卫的好处
//转空子--将链表数据拷贝到数组里，然后根据数组来判断
//不过数组要动态开辟的，因为链表长度有时不知道。
//4.判断链表是否为回文结构--对称
//第一步 根据快慢指针找到中间结点
//第二步逆转中间点之后的数据
//第三步将前面的数据与逆转后的数据进行比较
6.链表相交问题
1.传统思路：将cur1种的元素都与cur2中的元素比一遍--当相同时，就是第一个相交的点
时间复杂度为n ^ 2
要求时间O(N)空间为O(1);
//首先判断是否相交--比较尾结点的地址
//分别求两个长度
//长的链表先走差距步--不知道哪个长需要讨论一下
//再同时走，比较，第一个地址相同的就是交点。
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