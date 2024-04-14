#include "src/error.h"
#include "src/linear.h"

int
main()
{
        ela_matrix *m = ela_matrix_alloc(1, 0);
        NP_CHECK(m);
        return 0;
}
