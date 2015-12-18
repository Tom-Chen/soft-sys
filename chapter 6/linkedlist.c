#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} link;

void print_list(link *head) {
    link *current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

link *extend_list(link *current, int input_value) {
    link *new_node = malloc(sizeof(link));
    new_node->val = input_value;
    new_node->next = NULL;
    current->next = new_node;
    return new_node;
}

int main() {
    link *root_node = malloc(sizeof(link));
    root_node->val = 0;

    link *temp = malloc(sizeof(link));
    temp->val = 1;
    root_node->next = temp;

    int i;
    for(i = 2; i < 10; i++) {
        temp = extend_list(temp,i);
    }
    temp->next = NULL;

    print_list(root_node);
}