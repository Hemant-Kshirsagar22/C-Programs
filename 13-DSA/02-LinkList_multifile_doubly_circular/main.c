#include <stdio.h>
#include "list.h"

int main(void)
{
    int choice = 0;
    list_t *list = NULL;
    int element = 0;
    int position = 0;

    while (TRUE)
    {
        printf("\t\t\tMENU\n");
        printf("0. Create Random List With Given Size\n");
        printf("1. Create New List\n");
        printf("2. Insert\n");
        printf("3. Remove\n");
        printf("4. Display\n");
        printf("5. Exit\n\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            if(list != NULL)
            {
                freeList(&list);
            }
            printf("Enter Number Of Elements : ");
            scanf("%d", &element);
            list = createRandomList(element);
            break;

        case 1:
            list = createList();
            break;

        case 2:
            if(list == NULL)
            {
                list = createList();
            }

            printf("Enter Position To Insert : ");
            scanf("%d", &position);

            printf("Enter Number To Insert : ");
            scanf("%d", &element);

            insert(list, position, element);

            break;

        case 3:
            printf("Enter Position To Remove : ");
            scanf("%d", &position);

            removeNode(list, position);
            break;

        case 4:
            displayList(list);
            break;
        case 5:
            freeList(&list);
            printf("Exiting...\n\n");
            return(0);

        default:
            printf("Enter Valid choice !!!\n\n");
            break;
        }
    }
}
