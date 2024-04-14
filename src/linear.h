#ifndef QUANTUM_LINEAR_H_
#define QUANTUM_LINEAR_H_

#include <complex.h>
#include <stdbool.h>

#define real double

#ifndef SCALAR_REAL
#define SCALAR_COMPLEX
#endif

#if defined(SCALAR_COMPLEX) && defined(SCALAR_REAL)
#warning                                                                       \
    "Both SCALAR_REAL and SCALAR_COMPLEX are defined. Scalars will be complex by default."
#undef SCALAR_REAL
#endif

#ifdef SCALAR_COMPLEX
#define scalar_t real complex
#else
#define scalar_t real
#endif

typedef struct ela_matrix_s {
        unsigned int num_rows;
        unsigned int num_cols;
        scalar_t *data;
        bool is_square;
} ela_matrix;

ela_matrix *ela_matrix_alloc(unsigned int num_rows, unsigned int num_cols);

void ela_matrix_free(ela_matrix *matrix);

#endif

/* vim: set ft=c: */
