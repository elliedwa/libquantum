#ifndef ELA_MACROS_H_
#define ELA_MACROS_H_

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
#define RETURN_IF_NULL(x)                                                      \
        if (!(x)) {                                                            \
                return;                                                        \
        }
__END_DECLS

#endif
