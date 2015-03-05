#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Definition for binary tree
 */
struct AVL_node {
    int val;
    int height;
    struct AVL_node *left;
    struct AVL_node *right;
};

int get_height(struct AVL_node *r)
{
    if (r == NULL)
        return -1;

    return r->height;
}

struct AVL_node *single_rotate_left(struct AVL_node *k2)
{
    struct AVL_node *k1;

    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    --k1->height;
    ++k2->height;
    --k1->left->height;

    return k1;
}

struct AVL_node *single_rotate_right(struct AVL_node *k1)
{
    struct AVL_node *k2;

    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    ++k1->height;
    --k2->height;
    --k2->right->height;

    return k2;
}

struct AVL_node *double_rotate_left(struct AVL_node *k3)
{
    k3->left = single_rotate_right(k3->left);

    return single_rotate_left(k3);
}

struct AVL_node *double_rotate_right(struct AVL_node *k3)
{
    k3->right = single_rotate_left(k3->right);

    return single_rotate_right(k3);
}

struct AVL_node *insert(struct AVL_node *r, int val)
{
    struct AVL_node *node;

    if (r == NULL) {
        node = (struct AVL_node *)malloc(sizeof(struct AVL_node));
        node->val = val;
        node->left = node->right = NULL;
        node->height = 0;

        return node;
    }

    if (val < r->val) {
        r->left = insert(r->left, val);
        if (get_height(r->left) - get_height(r->right) == 2) {
            if (val < r->left->val)
                r = single_rotate_left(r);
            else
                r = double_rotate_left(r);
        }
    } else if (val > r->val) {
        r->right = insert(r->right, val);
        if (get_height(r->right) - get_height(r->left) == 2) {
            if (val > r->right->val)
                r = single_rotate_right(r);
            else
                r = double_rotate_right(r);
        }
    }

    return r;
}

/* for test */
struct AVL_node *construct_AVL(int n) {
    int i;
    int val;
    struct AVL_node *root;
    struct AVL_node *node;

    srand(time(NULL));

    root = NULL;

    for (i = 0; i < n; i++) {
        val = rand() % 100;
        printf("%d\n", val);

        node = insert(root, val);

        if (root == NULL) {
            root = node;
        }
    }

    return root;
}

void print(struct AVL_node *r) {
    if (r == NULL)
        return ;

    print(r->left);
    printf("%d\n", r->val);
    print(r->right);
}

int main(int argc, char *argv[])
{
    struct AVL_node *root;
    int num;

    while (scanf("%d", &num)) {
        printf("----------------------\n");
        root = construct_AVL(num);
        printf("----------------------\n");
        print(root);
        printf("\n");
    }

    return 0;
}

