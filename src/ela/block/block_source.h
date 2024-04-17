#define BLOCK_SOURCE                                                           \
        size_t FUNCTION(ela_block, size)(const TYPE(ela_block) * b)            \
        {                                                                      \
                return b->size;                                                \
        }                                                                      \
                                                                               \
        ATOMIC *FUNCTION(ela_block, data)(const TYPE(ela_block) * b)           \
        {                                                                      \
                return b->data;                                                \
        }
