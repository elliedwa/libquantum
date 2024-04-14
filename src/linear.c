#include "linear.h"
#include "error.h"

#include <stdio.h>
#include <stdlib.h>

ela_matrix *
ela_matrix_alloc(unsigned int num_rows, unsigned int num_cols)
{
        unsigned int num_elems = num_rows * num_cols;
        if (num_elems == 0) {
                fprintf(stderr, "Error: Invalid matrix allocation (%d x %d)\n",
                        num_rows, num_cols);
                return NULL;
        }
        ela_matrix *m = calloc(1, sizeof(*m));
        NP_CHECK(m);
        m->num_rows  = num_rows;
        m->num_cols  = num_cols;
        m->is_square = (num_rows == num_cols);

        m->data      = calloc(num_elems, sizeof(*m->data));
        NP_CHECK(m->data);

        return m;
}

void
ela_matrix_free(ela_matrix *matrix)
{
        free(matrix->data);
        free(matrix);
}
