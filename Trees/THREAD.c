#include <stdio.h>
#include <stdlib.h>  // malloc, exit ke liye
#define infinity 9999

typedef enum { thread, link } boolean;

struct node {
    struct node *left_ptr;
    boolean left;
    int info;
    boolean right;
    struct node *right_ptr;
} *head = NULL;

// Function prototypes
void insert_head();
void insert(int item);
void del(int item);
void case_a(struct node *par, struct node *loc);
void case_b(struct node *par, struct node *loc);
void case_c(struct node *par, struct node *loc);
void find(int item, struct node **par, struct node **loc);
void inorder();
void preorder();
struct node *in_succ(struct node *p);
struct node *in_pred(struct node *p);

int main() {
    int choice, num;
    insert_head();
    while (1) {
        printf("\n1.Insert\n");
        printf("2.Delete\n");
        printf("3.Inorder Traversal\n");
        printf("4.Preorder Traversal\n");
        printf("5.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to be inserted : ");
                scanf("%d", &num);
                insert(num);
                break;
            case 2:
                printf("Enter the number to be deleted : ");
                scanf("%d", &num);
                del(num);
                break;
            case 3:
                inorder();
                break;
            case 4:
                preorder();
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}

void insert_head() {
    head = (struct node *)malloc(sizeof(struct node));
    head->info = infinity;
    head->left = thread;
    head->left_ptr = head;
    head->right = link;
    head->right_ptr = head;
}

void find(int item, struct node **par, struct node **loc) {
    struct node *ptr, *ptrsave;
    if (head->left_ptr == head) {
        *loc = NULL;
        *par = head;
        return;
    }
    if (item == head->left_ptr->info) {
        *loc = head->left_ptr;
        *par = head;
        return;
    }
    ptr = head->left_ptr;
    while (ptr != head) {
        ptrsave = ptr;
        if (item < ptr->info) {
            if (ptr->left == link)
                ptr = ptr->left_ptr;
            else
                break;
        } else if (item > ptr->info) {
            if (ptr->right == link)
                ptr = ptr->right_ptr;
            else
                break;
        }
        if (item == ptr->info) {
            *loc = ptr;
            *par = ptrsave;
            return;
        }
    }
    *loc = NULL;
    *par = ptrsave;
}

void insert(int item) {
    struct node *tmp, *parent, *location;
    find(item, &parent, &location);
    if (location != NULL) {
        printf("Item already present\n");
        return;
    }
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = item;
    tmp->left = thread;
    tmp->right = thread;

    if (parent == head) {
        head->left = link;
        head->left_ptr = tmp;
        tmp->left_ptr = head;
        tmp->right_ptr = head;
    } else if (item < parent->info) {
        tmp->left_ptr = parent->left_ptr;
        tmp->right_ptr = parent;
        parent->left = link;
        parent->left_ptr = tmp;
    } else {
        tmp->left_ptr = parent;
        tmp->right_ptr = parent->right_ptr;
        parent->right = link;
        parent->right_ptr = tmp;
    }
}

void del(int item) {
    struct node *parent, *location;
    if (head->left_ptr == head) {
        printf("Tree empty\n");
        return;
    }
    find(item, &parent, &location);
    if (location == NULL) {
        printf("Item not present in tree\n");
        return;
    }
    if (location->left == thread && location->right == thread)
        case_a(parent, location);
    else if (location->left == link && location->right == thread)
        case_b(parent, location);
    else if (location->left == thread && location->right == link)
        case_b(parent, location);
    else
        case_c(parent, location);
}

void case_a(struct node *par, struct node *loc) {
    if (par == head) {
        head->left = thread;
        head->left_ptr = head;
    } else if (loc == par->left_ptr) {
        par->left = thread;
        par->left_ptr = loc->left_ptr;
    } else {
        par->right = thread;
        par->right_ptr = loc->right_ptr;
    }
    free(loc);
}

void case_b(struct node *par, struct node *loc) {
    struct node *child, *s, *p;
    if (loc->left == link)
        child = loc->left_ptr;
    else
        child = loc->right_ptr;

    if (par == head)
        head->left_ptr = child;
    else if (loc == par->left_ptr)
        par->left_ptr = child;
    else
        par->right_ptr = child;

    s = in_succ(loc);
    p = in_pred(loc);

    if (loc->right == link)
        s->left_ptr = p;
    else if (loc->left == link)
        p->right_ptr = s;

    free(loc);
}

void case_c(struct node *par, struct node *loc) {
    struct node *ptr, *ptrsave, *suc, *parsuc;
    ptrsave = loc;
    ptr = loc->right_ptr;
    while (ptr->left == link) {
        ptrsave = ptr;
        ptr = ptr->left_ptr;
    }
    suc = ptr;
    parsuc = ptrsave;
    loc->info = suc->info;

    if (suc->left == thread && suc->right == thread)
        case_a(parsuc, suc);
    else
        case_b(parsuc, suc);
}

struct node *in_succ(struct node *ptr) {
    if (ptr->right == thread)
        return ptr->right_ptr;
    ptr = ptr->right_ptr;
    while (ptr->left == link)
        ptr = ptr->left_ptr;
    return ptr;
}

struct node *in_pred(struct node *ptr) {
    if (ptr->left == thread)
        return ptr->left_ptr;
    ptr = ptr->left_ptr;
    while (ptr->right == link)
        ptr = ptr->right_ptr;
    return ptr;
}

void inorder() {
    struct node *ptr;
    if (head->left_ptr == head) {
        printf("Tree is empty\n");
        return;
    }
    ptr = head->left_ptr;
    while (ptr->left == link)
        ptr = ptr->left_ptr;
    while (ptr != head) {
        printf("%d ", ptr->info);
        ptr = in_succ(ptr);
    }
    printf("\n");
}

void preorder() {
    struct node *ptr;
    if (head->left_ptr == head) {
        printf("Tree is empty\n");
        return;
    }
    ptr = head->left_ptr;
    while (ptr != head) {
        printf("%d ", ptr->info);
        if (ptr->left == link)
            ptr = ptr->left_ptr;
        else if (ptr->right == link)
            ptr = ptr->right_ptr;
        else {
            while (ptr != head && ptr->right == thread)
                ptr = ptr->right_ptr;
            if (ptr != head)
                ptr = ptr->right_ptr;
        }
    }
    printf("\n");
}