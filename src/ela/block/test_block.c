#include "../test/tap.h"
#include "ela_block.h"
#include <stdlib.h>

int status = 0;

#ifndef DESC
#define DESC ""
#endif

#define N 1027

#define BASE_DOUBLE
#include "../templates_on.h"
#include "test_block_source.h"
TEST_BLOCK_SOURCE
#include "../templates_off.h"
#undef BASE_DOUBLE

int
main(void)
{
        plan(NO_PLAN);
        ela_block *b;
        double *data;
        size_t i;
        size_t size;

        b = ela_block_alloc(N);
        ok(b->data != NULL, "ela_block_alloc returns valid pointer");
        ok(b->size == N, "ela_block_alloc returns valid size");
        data = ela_block_data(b);
        size = ela_block_size(b);
        ok(data != NULL, "ela_block_size returns valid pointer");
        ok(size == N, "ela_block_size returns valid size");

        ela_block_free(b);

        b = ela_block_calloc(N);
        ok(b->data != NULL, "ela_block_calloc returns valid pointer");
        ok(b->size == N, "ela_block_calloc returns valid size");
        data = ela_block_data(b);
        size = ela_block_size(b);
        ok(data != NULL, "ela_block_size returns valid pointer from calloc");
        ok(size == N, "ela_block_size returns valid size from calloc");

        status = 0;
        for (i = 0; i < N; i++) {
                if (b->data[i] != 0.0) {
                        status = 1;
                }
        }
        ok(status == 0, "ela_block_calloc initializes array to zero");

        ela_block_free(b);

        b = ela_block_alloc(0);
        ok(b != NULL, "ela_block_alloc permits zero length");
        ok(b->size == 0, "ela_block_alloc reflects zero length");
        ela_block_free(b);

        b = ela_block_calloc(0);
        ok(b != NULL, "ela_block_calloc permits zero length");
        ok(b->size == 0, "ela_block_calloc reflects zero length");
        ela_block_free(b);

        ela_block_complex *bc;
        double *data_complex;

        bc = ela_block_complex_alloc(N);
        ok(bc->data != NULL, "ela_block_complex_alloc returns valid pointer");
        ok(bc->size == N, "ela_block_complex_alloc returns valid size");
        data_complex = ela_block_complex_data(bc);
        size         = ela_block_complex_size(bc);
        ok(data_complex != NULL,
           "ela_block_complex_size returns valid pointer");
        ok(size == N, "ela_block_complex_size returns valid size");

        ela_block_complex_free(bc);

        bc = ela_block_complex_calloc(N);
        ok(bc->data != NULL, "ela_block_complex_calloc returns valid pointer");
        ok(bc->size == N, "ela_block_complex_calloc returns valid size");
        data_complex = ela_block_complex_data(bc);
        size         = ela_block_complex_size(bc);
        ok(data_complex != NULL,
           "ela_block_complex_size returns valid pointer from calloc");
        ok(size == N, "ela_block_complex_size returns valid size from calloc");

        status = 0;
        for (i = 0; i < N; i++) {
                if (bc->data[i] != 0.0) {
                        status = 1;
                }
        }
        ok(status == 0, "ela_block_complex_calloc initializes array to zero");

        ela_block_complex_free(bc);

        bc = ela_block_complex_alloc(0);
        ok(bc != NULL, "ela_block_complex_alloc permits zero length");
        ok(bc->size == 0, "ela_block_complex_alloc reflects zero length");
        ela_block_complex_free(bc);

        bc = ela_block_complex_calloc(0);
        ok(bc != NULL, "ela_block_complex_calloc permits zero length");
        ok(bc->size == 0, "ela_block_complex_calloc reflects zero length");
        ela_block_complex_free(bc);

        done_testing();
}
