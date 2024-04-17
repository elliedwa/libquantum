#ifndef ELA_TEST_H_
#define ELA_TEST_H_

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

void ela_test(int status, const char *test_description, ...);

__END_DECLS
#endif
