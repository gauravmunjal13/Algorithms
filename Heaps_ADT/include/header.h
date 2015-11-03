#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

/* Following has to be moved to new header file */
#define uint32_t int
#define uint8_t char

#define SUCCESS 0
#define FAILURE 1

//heap type
#define MAX_HEAP 0
#define MIN_HEAP 1

#define MIN_HEAP_SIZE 1

struct HEAP
{
    uint32_t *array;
    uint32_t count;
    uint32_t capacity;
    uint32_t heap_type;
};

enum option_e
{
    HEAP_INSERTION,
    HEAP_DELETION,
    HEAP_GET_MAXIMUM,
    HEAP_PRINT_HEAP,
    HEAP_EXIT,
    HEAP_MAX_NUM
};

/*************** Function Declarations ***************/
// Create Heap
struct HEAP * CreateHeap( uint32_t capacity, uint32_t heap_type );
// Resize Heap
uint8_t ResizeHeap( struct HEAP *heap );
// Insert
uint8_t Insert( struct HEAP* heap, uint32_t data );
// Delete
uint32_t Delete(struct HEAP *heap);
//Percolate Down
void PercolateDown(struct HEAP *heap, uint32_t position);
// GetMaximum
// FindParent
uint32_t FindParent( struct HEAP *heap, uint32_t position );
// FindLeftChild
uint32_t FindLeftChild(  struct HEAP * heap, uint32_t position );
// FindRightChild
uint32_t FindRightChild(  struct HEAP * heap, uint32_t position );

#endif // HEADER_H_INCLUDED
