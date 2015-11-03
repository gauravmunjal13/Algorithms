#include <stdio.h>
#include <stdlib.h>
#include "../include/header.h"

#define ROOT_INDEX 0
/************** Public Functions *****************/

struct HEAP * CreateHeap( uint32_t capacity, uint32_t heap_type )
{
    struct HEAP *heap;

    heap = ( struct HEAP * )malloc( sizeof(struct HEAP) );
    if( NULL == heap )
    {
        printf("%s:Error in allocating memory",__FUNCTION__);
        return heap;
    }
    heap->count = 0;
    heap->capacity = capacity;
    heap->heap_type = heap_type;

    heap->array = (uint32_t *) malloc(sizeof(uint32_t)*heap->capacity);
    if( NULL == heap->array )
    {
        printf("%s:Error in allocating memory",__FUNCTION__);
        return NULL;
    }
    return heap;
}

uint8_t ResizeHeap( struct HEAP *heap )
{
    if(heap->count == heap->capacity)
    {
        uint32_t array_old[heap->capacity];
        uint32_t* temp_ptr = NULL;

        //Copy the contents of heap into temp array
        for(int i=0; i<heap->capacity; i++)
        {
            array_old[i] = heap->array[i];
        }

        //Allocate new memory to the heap array
        temp_ptr = heap->array;
        heap->array = (uint32_t *) malloc(sizeof(uint32_t)*heap->capacity*2);
        if( NULL == heap->array )
        {
            printf("%s:Error in allocating memory",__FUNCTION__);
            heap->array = temp_ptr;
            return FAILURE;
        }
        //On memory allocation, free the old memory
        free( temp_ptr );
        temp_ptr = NULL;

        //put the contents of old array into the new array
        for(int i=0; i<heap->capacity; i++)
        {
            heap->array[i] = array_old[i];
        }
        heap->capacity *= 2;
     }//heap->count == heap->capacity
    return SUCCESS;
}
/* Open points
The second alternative is instead of taking local array, use the existing old heap array, get the new memory,
copy the contents from old heap array to the new heap array and finally delete the old memory array.
*/

uint8_t Insert( struct HEAP* heap, uint32_t data )
{
    uint32_t retval = SUCCESS;
    uint32_t parent_pos, insertion_pos;
    retval = ResizeHeap( heap );
    if( SUCCESS == retval )
    {
        heap->count++;
        insertion_pos = heap->count-1;
        if( insertion_pos != 0 )
        {
            parent_pos = FindParent(heap,insertion_pos);
            //heapify up
            while( (data > heap->array[parent_pos]) && (insertion_pos != parent_pos) )
            {
                heap->array[insertion_pos] = heap->array[parent_pos];
                insertion_pos = parent_pos;
                parent_pos = FindParent(heap,insertion_pos);
            }
        }
        heap->array[insertion_pos] = data;
    }
    return retval;
}

uint32_t FindParent( struct HEAP *heap, uint32_t position )
{
    if( position == 0 )
    {
        printf("%s:Root node",__FUNCTION__);
        return position;
    }
    else
        return (position-1)/2;
}

uint32_t FindLeftChild(  struct HEAP * heap, uint32_t position )
{
    uint32_t child;

    child = 2*position+1;
    if(child < heap->count)
        return child;
    else
    {
        printf("%s:No child",__FUNCTION__);
        return position;
    }
}

uint32_t FindRightChild(  struct HEAP * heap, uint32_t position )
{
    uint32_t child;

    child = 2*position+2;
    if(child < heap->count)
        return child;
    else
    {
        printf("%s:No child",__FUNCTION__);
        return position;
    }
}


uint32_t Delete(struct HEAP *heap)
{
    uint32_t temp;

    temp= heap->array[0];

    heap->array[0] = heap->array[heap->count-1];
    heap->count--;

    if(heap->count != 0)
        PercolateDown(heap,ROOT_INDEX);

    return temp;

}


void PercolateDown(struct HEAP *heap, uint32_t position)
{
    if(heap->count == 0)
        return;

    uint32_t left, right, max, temp ;

    left = FindLeftChild(heap, position);
    right = FindRightChild(heap, position);
    if(heap->array[left] > heap->array[right])
        max = left;
    else
        max = right;

    if(heap->array[position] > heap->array[max])
        max = position;

    if(max != position)
    {
        temp = heap->array[position];
        heap->array[position] = heap->array[max];
        heap->array[max] = temp;

        PercolateDown(heap,max);
    }
    return;
}

