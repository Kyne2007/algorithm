#include "slist.h"

//remove first node from the list for which the val == node.val
//return the new head of the list
slist_node *delete_first_node(slist_node *head, int val)
{
    for (slist_node *pre = nullptr, *curr = head; curr; ) {

        slist_node *next = curr->next;

        if (curr->val == val) {
            if (pre)
                pre->next = next;
            else
                head = next;   //remove head node
            delete curr;

            return head;
        }

        pre = curr;
        curr = next;
    }

    return head;
}

void delete_first_node(slist_node **head, int val)
{
    for (slist_node **curr = head; *curr; ) {
        slist_node *entry = *curr;

        if (entry->val == val) {
            *curr = entry->next;
            delete entry;
            return ;
        }

        curr = &entry->next;
    }
}

//删掉中间节点，不包括头节点和最后一个节点
void delete_random_node(slist_node *node)
{
    if (node == nullptr || node->next == nullptr)
        return ;

    slist_node *next = node->next;

    node->val = next->val;
    node->next = next->next;

    delete next;
}

//翻转单链表
//返回新的头节点
slist_node *reverse(slist_node *head)
{
    if (head == nullptr)
        return nullptr;

    slist_node *pre, *curr;

    for (pre = nullptr, curr = head; curr; ) {
        slist_node *next = curr->next;

        curr->next = pre;
        pre = curr;
        curr = next;
    }

    return pre;
}

