#include <stdio.h>
#include <stdlib.h>
void ll_input(), ll_print(), ll_update(), ll_delete();

struct NODE {
    int ID;
    int value;
    struct NODE *next;
} *head, *tail, *ptr;


//main function
int main() {
    head = NULL;
    int index, flag = 0;
    while(flag == 0) {
        printf("Enter [(1) Input, (2) Print, (3) Update, (4) Delete, (5) Exit]: ");
        scanf("%d", &index);
        if (index == 1) {ll_input();}
        else if(index == 2) {ll_print();}
        else if(index == 3) {ll_update();}
        else if(index == 4) {ll_delete();}
        else if(index == 5) {printf("Exit this Program\n"); flag=1;}
        else {printf("Enter Again (between 1 and 5)\n");}
    }
    return 0;
}


//ll_input() Function
void ll_input(){
    int in_ID, in_value;
    printf("\tID, value: "); scanf("%d %d4",&in_ID, &in_value);
    ptr = (struct NODE *)malloc(sizeof(struct NODE));
    if (head == NULL) {head = ptr;} else {tail->next = ptr;}
    ptr->ID = in_ID;
    ptr->value = in_value;
    ptr->next = NULL;
    tail = ptr;
    ll_print();
}


//ll_input() Function
void ll_print() {
    ptr = head;
    printf("(ID, Values): ");
    while(ptr != NULL) {
        printf("(%d, %d)", ptr->ID, ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}

//ll_update() Function
void ll_update() {
    int update_ID, update_value;
    printf("\tlD for update:"); scanf("%d", &update_ID);
    ptr = head;
    while (ptr != NULL) {
        if(ptr->ID == update_ID) {
            printf("\tEnter the value for this ID: ");
            scanf("%d", &update_value);
            ptr->value = update_value;
            ll_print();
            return;
        }
        ptr = ptr->next;
    }
}

//ll_delete() Function
void ll_delete() {
    int delete_ID;
    printf("\tD for delete:"); scanf("%d", &delete_ID);
    ptr = head;
    if(ptr->ID == delete_ID) { /* Delete the first NODE */
        head = ptr->next;
        free(ptr);
        ll_print();
        return;
    }
    struct NODE *tmp;
    while (ptr != NULL) { /* Otherwise */
        tail = ptr;
        ptr = ptr->next;
        if(ptr->ID == delete_ID) {
            tail->next = ptr->next;
            tmp = tail;
            free(ptr);
            while(tail->next != NULL) {
                tail = tmp;
                tmp = tmp->next;
            }
            ll_print();
            return;
        }}}