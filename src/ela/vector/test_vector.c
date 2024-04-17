#include "../test/tap.h"
#include "ela_vector.h"

int status = 0;

#ifndef DESC
#define DESC ""
#endif

ela_vector *
create_vector(size_t stride, size_t N)
{
        ela_vector *v = ela_vector_calloc(N * stride);
        v->stride     = stride;
        v->size       = N;
        return v;
}

void
test_func(size_t stride, size_t N)
{
        diag("test_func(%lu, %lu)", stride, N);
        ela_vector *v0;
        ela_vector *v;

        if (stride == 1) {
                v = ela_vector_calloc(N);

                ok(v->data != NULL, "ela_vector_calloc pointer");
                cmp_ok(v->size, "==", N, "ela_vector_calloc size");
                cmp_ok(v->stride, "==", 1, "ela_vector_calloc stride");

                {
                        // isnull, ispos, isneg, isnonneg
                }

                ela_vector_free(v);
        }
        if (stride == 1) {
                v = ela_vector_alloc(N);

                ok(v->data != NULL, "ela_vector_alloc pointer");
                cmp_ok(v->size, "==", N, "ela_vector_alloc size");
                cmp_ok(v->stride, "==", 1, "ela_vector_alloc stride");

                ela_vector_free(v);
        }
}

void
test_alloc_zero_length(void)
{
        ela_vector *b = ela_vector_alloc(0);
        ok(b != NULL, "ela_vector_alloc permits zero length");
        cmp_ok(b->size, "==", 0, "ela_vector_alloc reflects zero length");
        ela_vector_free(b);
}
void
test_calloc_zero_length(void)
{
        ela_vector *b = ela_vector_calloc(0);
        ok(b != NULL, "ela_vector_calloc permits zero length");
        cmp_ok(b->size, "==", 0, "ela_vector_calloc reflects zero length");
        ela_vector_free(b);
}

ela_vector_complex *
create_complex_vector(size_t stride, size_t N)
{
        ela_vector_complex *v = ela_vector_complex_calloc(N * stride);
        v->stride             = stride;
        v->size               = N;
        return v;
}

int
main(void)
{
        plan(NO_PLAN);
        for (size_t N = 10; N < 1024; N = 2 * N + 1) {
                for (size_t stride = 1; stride < 5; stride++) {
                        test_func(stride, N);
                }
        }

        test_alloc_zero_length();
        test_calloc_zero_length();
        done_testing();
}
