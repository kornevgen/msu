/**
    @brief Type for 10-items arrays
 */    
struct array10_Array;

/**
    @brief Reads the sequence of integers
    from the standard input, writes to a memory
    by the address given. The sequence ends with number 0
    (it is not included into the sequence).

    @param a Address of the allocated object for writing to.
    
    @return 0 (zero) if the sequence readed contains no more than 10 items,
    non 0 (non zero), otherwise.
 */
int array10_read(struct array10_Array *a);

/**
    @brief Writes the items given by the parameter
    to the standard output.

    @param a Address of the allocated object for reading from.
    
    @return 0 (zero) if the writing is successful,
    non 0 (non zero), otherwise.
 */
int array10_write(struct array10_Array *a);

/**
    @brief Deallocates the object by the parameter given.

    @param a Address of the allocated object. It must be allocated at the heap.
 */
void array10_dealloc(struct array10_Array *a);
