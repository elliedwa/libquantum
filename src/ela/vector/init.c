#include "../block/ela_block.h"
#include "../ela_macros.h"
#include "../err/ela_error.h"
#include "ela_vector.h"
#include <stdlib.h>
#include <string.h>

ela_vector *
ela_vector_alloc(const size_t n)
{
        ela_block *block;
        ela_vector *v = (ela_vector *)malloc(sizeof(ela_vector));
        if (v == NULL) {
                ELA_ERROR_VAL("failed to allocate space for vector struct",
                              ELA_ENOMEM, 0);
        }
        block = ela_block_alloc(n);
        if (block == NULL) {
                free(v);
                ELA_ERROR_VAL("failed to allocate space for block", ELA_ENOMEM,
                              0);
        }
        v->data   = block->data;
        v->size   = n;
        v->stride = 1;
        v->block  = block;
        v->owner  = true;
        return v;
}

ela_vector *
ela_vector_calloc(const size_t n)
{
        ela_vector *v = ela_vector_alloc(n);
        if (v == NULL) {
                return 0;
        }

        memset(v->data, 0, n * sizeof(double));
        for (size_t i = 0; i < n; i++) {
                v->data[i] = 0;
        }
        return v;
}

ela_vector *
ela_vector_alloc_from_block(ela_block *block, const size_t offset,
                            const size_t n, const size_t stride)
{
        ela_vector *v;
        if (stride == 0) {
                ELA_ERROR_VAL("stride must be positive integer", ELA_EINVAL, 0);
        }
        if (block->size <= offset + (n > 0 ? n - 1 : 0) * stride) {
                ELA_ERROR_VAL("vector would extend past end of block",
                              ELA_EINVAL, 0);
        }
        v = (ela_vector *)malloc(sizeof(ela_vector));
        if (v == NULL) {
                ELA_ERROR_VAL("failed to allocate space for vector struct",
                              ELA_ENOMEM, 0);
        }

        v->data   = block->data + offset;
        v->size   = n;
        v->stride = stride;
        v->block  = block;
        v->owner  = false;

        return v;
}

ela_vector *
ela_vector_alloc_from_vector(ela_vector *w, const size_t offset, const size_t n,
                             const size_t stride)
{
        ela_vector *v;
        if (stride == 0) {
                ELA_ERROR_VAL("stride must be positive integer", ELA_EINVAL, 0);
        }
        if (offset + (n > 0 ? n - 1 : 0) * stride >= w->size) {
                ELA_ERROR_VAL("vector would extend past end of block",
                              ELA_EINVAL, 0);
        }
        v = (ela_vector *)malloc(sizeof(ela_vector));
        if (v == NULL) {
                ELA_ERROR_VAL("failed to allocate space for vector struct",
                              ELA_ENOMEM, 0);
        }
        v->data   = w->data + w->stride * offset;
        v->size   = n;
        v->stride = stride * w->stride;
        v->block  = w->block;
        v->owner  = false;

        return v;
}

void
ela_vector_free(ela_vector *v)
{
        RETURN_IF_NULL(v);
        if (v->owner) {
                ela_block_free(v->block);
        }
        free(v);
}

void
ela_vector_set_all(ela_vector *v, double x)
{
        double *const data  = v->data;
        const size_t n      = v->size;
        const size_t stride = v->stride;

        for (size_t i = 0; i < n; i++) {
                *(double *)(data + i * stride) = x;
        }
}

void
ela_vector_set_zero(ela_vector *v)
{
        double *const data  = v->data;
        const size_t n      = v->size;
        const size_t stride = v->stride;

        for (size_t i = 0; i < n; i++) {
                *(double *)(data + i * stride) = 0.0;
        }
}

void
ela_vector_set_basis(ela_vector *v, size_t i)
{
        double *const data  = v->data;
        const size_t n      = v->size;
        const size_t stride = v->stride;

        if (i >= n) {
                ELA_ERROR("index out of range", ELA_EINVAL);
        }
        for (size_t k = 0; k < n; k++) {
                *(double *)(data + k * stride) = 0.0;
        }

        *(double *)(data + i * stride) = 1.0;
}
