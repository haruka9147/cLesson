#include <stdio.h>

typedef struct{
    int ID;
    char *first;
    char *last;
    struct Person *next;
} Person;

void look_up_name(Person *ptr, int ID)
{
    int isExist = 0;
    Person *current = ptr;
    while(current != NULL)
    {
        int current_id = current->ID;
        if(ID == current_id)
        {
            isExist = 1;
            printf("%s %s\n", current->first, current->last);
            break;
        }
        current = current->next;
    }

    if(isExist == 0)
    {
        printf("No such ID in database\n");
    }
}

int main()
{
    Person *head = NULL;
    head = (Person *)malloc(sizeof(Person));

    head->ID = 1;
    head->first = (char *)malloc(sizeof(10));
    head->last = (char *)malloc(sizeof(10));

    head->first = "Test";
    head->last = "Test";
    head->next = (Person *)malloc(sizeof(Person));
    
    int search_id;
    printf("Search: ");
    scanf("%d\n", &search_id);

    look_up_name(head, search_id);

    return 0;
}