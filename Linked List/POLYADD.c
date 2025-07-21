/* Program of polynomial addition using linked list */
#include <stdio.h>
#include <stdlib.h>  // malloc ke liye

struct node {
    float coef;
    int expo;
    struct node *link;
};

struct node *poly_add(struct node *, struct node *);
struct node *enter(struct node *);
struct node *insert(struct node *, float, int);
void display(struct node *);

int main() {
    struct node *p1_start = NULL, *p2_start = NULL, *p3_start = NULL;

    printf("Polynomial 1 :\n");
    p1_start = enter(p1_start);

    printf("Polynomial 2 :\n");
    p2_start = enter(p2_start);

    p3_start = poly_add(p1_start, p2_start);

    printf("\nPolynomial 1 is :  ");
    display(p1_start);
    printf("Polynomial 2 is :  ");
    display(p2_start);
    printf("Added polynomial is :  ");
    display(p3_start);

    return 0;
}

/* Enter polynomial */
struct node *enter(struct node *start) {
    int i, n, ex;
    float co;
    printf("How many terms you want to enter : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("Enter coefficient for term %d : ", i);
        scanf("%f", &co);
        printf("Enter exponent for term %d : ", i);
        scanf("%d", &ex);
        start = insert(start, co, ex);
    }
    return start;
}

/* Insert a term into polynomial (sorted by exponent) */
struct node *insert(struct node *start, float co, int ex) {
    struct node *ptr, *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->coef = co;
    tmp->expo = ex;
    tmp->link = NULL;

    // Empty list or highest exponent
    if (start == NULL || ex > start->expo) {
        tmp->link = start;
        start = tmp;
    } else {
        ptr = start;
        while (ptr->link != NULL && ptr->link->expo > ex)
            ptr = ptr->link;
        tmp->link = ptr->link;
        ptr->link = tmp;
    }
    return start;
}

/* Polynomial addition */
struct node *poly_add(struct node *p1, struct node *p2) {
    struct node *p3_start = NULL, *p3 = NULL, *tmp;

    while (p1 != NULL && p2 != NULL) {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->link = NULL;

        if (p3_start == NULL) {
            p3_start = tmp;
            p3 = p3_start;
        } else {
            p3->link = tmp;
            p3 = p3->link;
        }

        if (p1->expo > p2->expo) {
            tmp->coef = p1->coef;
            tmp->expo = p1->expo;
            p1 = p1->link;
        } else if (p2->expo > p1->expo) {
            tmp->coef = p2->coef;
            tmp->expo = p2->expo;
            p2 = p2->link;
        } else { // Equal exponents
            tmp->coef = p1->coef + p2->coef;
            tmp->expo = p1->expo;
            p1 = p1->link;
            p2 = p2->link;
        }
    }

    while (p1 != NULL) {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->coef = p1->coef;
        tmp->expo = p1->expo;
        tmp->link = NULL;

        if (p3_start == NULL) {
            p3_start = tmp;
            p3 = p3_start;
        } else {
            p3->link = tmp;
            p3 = p3->link;
        }
        p1 = p1->link;
    }

    while (p2 != NULL) {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->coef = p2->coef;
        tmp->expo = p2->expo;
        tmp->link = NULL;

        if (p3_start == NULL) {
            p3_start = tmp;
            p3 = p3_start;
        } else {
            p3->link = tmp;
            p3 = p3->link;
        }
        p2 = p2->link;
    }

    return p3_start;
}

/* Display polynomial */
void display(struct node *ptr) {
    if (ptr == NULL) {
        printf("Empty\n");
        return;
    }
    while (ptr != NULL) {
        printf("(%.1fx^%d)", ptr->coef, ptr->expo);
        ptr = ptr->link;
        if (ptr != NULL) printf(" + ");
    }
    printf("\n");
}