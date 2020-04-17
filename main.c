#include <stdio.h>
#include "Queue_library.h"
int main()
{
    int option =0;
    while(1)
    {
        printf("\nSelect the option to execute\n");
        printf("1. Push an element to queue\n");
        printf("2. Pop the queue\n");
        printf("3. Get data in first element\n");
        printf("4. Get data in last element\n");
        printf("5. Size of the queue\n");
        printf("6. Check if the queue is empty or not\n");
        printf("7. Exit\n");

        printf("Your option:\n");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
            {
                int element;
                printf("Enter the element to push:");
                scanf("%d", &element);
                printf("\n");
                push(element);
                break;
            }
            case 2:
            {
                printf("Popped element is: %d\n", pop());
                break;
            }
            case 3:
            {
                printf("Data in first element is %d\n", front());
                break;
            }
            case 4:
            {
                printf("Data in last element is %d\n", back());
                break;
            }
            case 5:
            {
                printf("Size of the queue is: %d\n", size());
                break;
            }
            case 6:
            {
                if(empty())
                {
                    printf("The queue is empty");    
                }
                else
                {
                    printf("The queue is not empty");   
                }
                
                break;
            }
            case 7:
            {
                printf("Exiting\n");
                return 0;
            }
            default:
            {
                printf("Invalid option!\n");
                break;
            }    
        }

    }    
    return 0;
}

