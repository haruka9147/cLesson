#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} Node;

/* print all nodes (iterating over a list) */
void print_linkedlist(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d\n", current->val);
        current = current->next;
    }
}

/* Adding a node to the end of the list */
void push(Node *head, int val)
{
    // find the last element (NULL)
    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    // add a new element
    current->next = (Node *)malloc(sizeof(Node));
    current->next->val = val;
    current->next->next = NULL;
}

void addAsFirst(Node **head, int val)
{
    // 1. Create a new node (malloc) and set the value.
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    // 2. Link the new node to point to the head of the list.
    newNode->next = *head;
    // 3. Set the head of the list point to the new node.
    *head = newNode;
}
/* returns the value of the node removed */
int pop(Node **head)
{
    int returned = -1;
    Node *second = NULL;
    if (*head == NULL)
    {
        return -1;
    }
    second = (*head)->next; /* store */
    returned = (*head)->val;
    free(*head);
    *head = second;
    return returned;
}

int remove_last(Node *head)
{
    int returned = -1;
    // if there's only one node
    if (head->next == NULL)
    {
        returned = head->val;
        free(head);
        return returned;
    }
    // iterate over to the last element
    Node *current = head;
    while (current->next->next != NULL) /* when reached the second last */
    {
        current = current->next;
    }
    returned = current->next->val;
    free(current->next);
    current->next = NULL;
    return returned;
}

int main(int argc, char *argv[])
{
    Node *head = NULL;

    head = (Node *)malloc(sizeof(Node));
    if (head == NULL)
    {
        return 1;
    }
    head->val = 1;
    head->next = (Node *)malloc(sizeof(Node));
    head->next->val = 2;
    head->next->next = NULL;

    // print_linkedlist(head);
    push(head, 100);
    // print_linkedlist(head);
    Node **HEAD = &head; // Node * head
    addAsFirst(HEAD, 77);
    print_linkedlist(head);

    return 0;
}