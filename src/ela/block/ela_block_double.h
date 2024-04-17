#ifndef ELA_BLOCK_DOUBLE_H_
#define ELA_BLOCK_DOUBLE_H_
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

typedef struct ela_block_struct {
        size_t size;
        double *data;
} ela_block;

ela_block *ela_block_alloc(size_t n);
ela_block *ela_block_calloc(size_t n);
void ela_block_free(ela_block *b);


size_t ela_block_size(const ela_block *b);
double *ela_block_data(const ela_block *b);

__END_DECLS

#endif
