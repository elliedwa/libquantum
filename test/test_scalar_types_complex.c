#include <assert.h>
#define SCALAR_COMPLEX
#include "src/linear.h"

int
main()
{
        ela_matrix *real_mat = ela_matrix_alloc(3, 3);
        assert(sizeof(*real_mat->data) != sizeof(double));
        assert(sizeof(*real_mat->data) == sizeof(complex double));
        return 0;
}
