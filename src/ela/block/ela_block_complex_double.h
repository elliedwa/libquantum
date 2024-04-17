#ifndef ELA_BLOCK_COMPLEX_DOUBLE_H_
#define ELA_BLOCK_COMPLEX_DOUBLE_H_
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

typedef struct ela_block_complex_struct {
        size_t size;
        double *data;
} ela_block_complex;

ela_block_complex *ela_block_complex_alloc(size_t n);
ela_block_complex *ela_block_complex_calloc(size_t n);
void ela_block_complex_free(ela_block_complex *b);

size_t ela_block_complex_size(const ela_block_complex *b);
double *ela_block_complex_data(const ela_block_complex *b);

__END_DECLS

#endif
