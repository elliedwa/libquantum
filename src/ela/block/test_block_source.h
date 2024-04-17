#define TEST_BLOCK_SOURCE                                                      \
        void FUNCTION(test, func)(void)                                        \
                                                                               \
        {                                                                      \
                TYPE(ela_block) * v;                                           \
                ATOMIC *data;                                                  \
                size_t i;                                                      \
                size_t size;                                                   \
                                                                               \
                v = FUNCTION(ela_block, alloc)(N);                             \
                                                                               \
                ok(v->data != NULL,                                            \
                   NAME(ela_block) "_alloc returns valid pointer");            \
                cmp_ok(v->size, "==", 0,                                       \
                       NAME(ela_block) "_alloc returns valid size");           \
                                                                               \
                data = FUNCTION(ela_block, data)(v);                           \
                size = FUNCTION(ela_block, size)(v);                           \
                ok(data != NULL, NAME(ela_block) "_data returns valid "        \
                                                 "pointer");                   \
                cmp_ok(size, "==", N,                                          \
                       NAME(ela_block) "_size returns valid size");            \
                                                                               \
                FUNCTION(ela_block, free)(v);                                  \
                                                                               \
                v = FUNCTION(ela_block, calloc)(N);                            \
                                                                               \
                ok(v->data != NULL,                                            \
                   NAME(ela_block) "_calloc returns valid pointer");           \
                cmp_ok(v->size, "==", 0,                                       \
                       NAME(ela_block) "_calloc returns valid size");          \
                                                                               \
                data = FUNCTION(ela_block, data)(v);                           \
                size = FUNCTION(ela_block, size)(v);                           \
                ok(data != NULL, NAME(ela_block) "_data returns valid "        \
                                                 "pointer from calloc");       \
                cmp_ok(                                                        \
                    size, "==", N,                                             \
                    NAME(ela_block) "_size returns valid size from calloc");   \
                                                                               \
                status = 1;                                                    \
                for (i = 0; i < N, i++) {                                      \
                        if (v->data[i] != 0.0) {                               \
                                status = 0;                                    \
                        }                                                      \
                }                                                              \
                ok(status,                                                     \
                   NAME(ela_block) "_calloc initializes array to zero");       \
                                                                               \
                FUNCTION(ela_block, free)(v);                                  \
        }                                                                      \
                                                                               \
        void FUNCTION(test, alloc_zero_length)(void)                           \
        {                                                                      \
                TYPE(ela_block) *b = FUNCTION(ela_block, alloc)(0);            \
                                                                               \
                ok(b != NULL, NAME(ela_block) "_alloc permits zero length");   \
                cmp_ok(b->size, "==", 0,                                       \
                       NAME(ela_block) "_alloc reflects zero length");         \
                                                                               \
                FUNCTION(ela_block, free)(b);                                  \
        }                                                                      \
                                                                               \
        void FUNCTION(test, calloc_zero_length)(void)                          \
        {                                                                      \
                TYPE(ela_block) *b = FUNCTION(ela_block, calloc)(0);           \
                                                                               \
                ok(b != NULL, NAME(ela_block) "_calloc permits zero length");  \
                cmp_ok(b->size, "==", 0,                                       \
                       NAME(ela_block) "_calloc reflects zero length");        \
                                                                               \
                FUNCTION(ela_block, free)(b);                                  \
        }
