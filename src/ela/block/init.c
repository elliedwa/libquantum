#include "../ela_macros.h"
#include "../err/ela_error.h"
#include "ela_block.h"

#include <string.h>

ela_block *
ela_block_alloc(const size_t n)
{
        ela_block *b = (ela_block *)malloc(sizeof(ela_block));
        if (b == NULL) {
                ELA_ERROR_VAL("failed to allocate space for block struct",
                              ELA_ENOMEM, 0);
        }

        b->data = (double *)malloc(n * sizeof(double));
        if (b->data == 0 && n > 0) /* malloc may return NULL when n == 0 */
        {
                free(b);
                ELA_ERROR_VAL("failed to allocate space for block data",
                              ELA_ENOMEM, 0);
        }
        b->size = n;
        return b;
}

ela_block *
ela_block_calloc(const size_t n)
{
        ela_block *b = ela_block_alloc(n);
        if (b == NULL) {
                return NULL;
        }

        /* initialize block to zero; the memset call takes care of padding bytes
         */
        memset(b->data, 0, n * sizeof(double));

        for (size_t i = 0; i < n; i++) {
                b->data[i] = 0;
        }

        return b;
}

void
ela_block_free(ela_block *b)
{
        RETURN_IF_NULL(b);
        free(b->data);
        free(b);
}

ela_block_complex *
ela_block_complex_alloc(const size_t n)
{
        ela_block_complex *b =
            (ela_block_complex *)malloc(sizeof(ela_block_complex));
        if (b == NULL) {
                ELA_ERROR_VAL("failed to allocate space for block struct",
                              ELA_ENOMEM, 0);
        }

        b->data = (double *)malloc(2 * n * sizeof(double));
        if (b->data == 0 && n > 0) /* malloc may return NULL when n == 0 */
        {
                free(b);
                ELA_ERROR_VAL("failed to allocate space for block data",
                              ELA_ENOMEM, 0);
        }
        b->size = n;
        return b;
}

ela_block_complex *
ela_block_complex_calloc(const size_t n)
{
        ela_block_complex *b = ela_block_complex_alloc(n);
        if (b == NULL) {
                return NULL;
        }

        /* initialize block to zero; the memset call takes care of padding bytes
         */
        memset(b->data, 0, 2 * n * sizeof(double));

        for (size_t i = 0; i < 2 * n; i++) {
                b->data[i] = 0;
        }

        return b;
}

void
ela_block_complex_free(ela_block_complex *b)
{
        RETURN_IF_NULL(b);
        free(b->data);
        free(b);
}
