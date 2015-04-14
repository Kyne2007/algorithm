#pragma once

struct slist_node {
    int val;
    slist_node *next;
    slist_node(int v = 0) : val(v), next(nullptr) {}
};

slist_node *delete_first_node(slist_node *head, int val);
void delete_first_node(slist_node **head, int val);
void delete_random_node(slist_node *node);

slist_node *reverse(slist_node *head);

