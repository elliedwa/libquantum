#ifndef ELA_VECTOR_COMPLEX_DOUBLE_H_
#define ELA_VECTOR_COMPLEX_DOUBLE_H_

#include "src/ela/block/ela_block_double.h"
#include <stdbool.h>
#include <stdlib.h>

#undef __BEGIN_DECLS
#undef __END_DECLS
#ifdef __cplusplus
#define __BEGIN_DECLS extern "C" {
#define __END_DECLS }
#else
#define __BEGIN_DECLS /* empty */
#define __END_DECLS   /* empty */
#endif

__BEGIN_DECLS

typedef struct ela_vector_complex_struct {
        size_t size;
        size_t stride;
        double *data;
        ela_block *block;
        bool owner;
} ela_vector_complex;

ela_vector_complex *ela_vector_complex_alloc(size_t n);
ela_vector_complex *ela_vector_complex_calloc(size_t n);

ela_vector_complex *ela_vector_complex_alloc_from_block(ela_block *block,
                                                        size_t offset, size_t n,
                                                        size_t stride);

ela_vector_complex *ela_vector_complex_alloc_from_vector_complex(
    ela_vector_complex *w, size_t offset, size_t n, size_t stride);

void ela_vector_complex_free(ela_vector_complex *v);

void ela_vector_complex_set_all(ela_vector_complex *v, double x);

__END_DECLS

#endif
