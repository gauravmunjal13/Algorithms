#include <stdio.h>
#include <stdlib.h>
#include "../include/header.h"


/************ Private Function ***********/

int main()
{
    struct HEAP *heap = NULL;
    enum option_e option;
    uint32_t data;

    heap = CreateHeap(MIN_HEAP_SIZE,MAX_HEAP);

    do{
        printf("%s:Enter\n 0:Insertion \t 1:Deletion \t 2:Get Maximum \t \
                3:Print Heap \t 4:Exit\n",__FUNCTION__);
        scanf("%u",&option);
        switch(option)
        {
            case HEAP_INSERTION:
                printf("%s:Enter data to be inserted in heap\n",__FUNCTION__);
                scanf("%d",&data);
                Insert(heap,data);
                break;
            case HEAP_DELETION:
                data = Delete(heap);
                printf("%s:Element deleted:%d\n",__FUNCTION__,data);
            case HEAP_PRINT_HEAP:
                printf("%s:Elements in heap:\n",__FUNCTION__);
                for(int i=0; i < heap->count; i++)
                {
                    printf("%d\t",heap->array[i]);
                }
            case HEAP_GET_MAXIMUM:
            default:
                break;
        }
    }while(HEAP_EXIT != option);
    printf("%s:Elements in heap:\n",__FUNCTION__);
    for(int i=0; i < heap->count; i++)
    {
        printf("%d\t",heap->array[i]);
    }
    return 0;
}
