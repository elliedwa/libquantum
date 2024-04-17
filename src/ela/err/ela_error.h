#ifndef ELA_ERROR_H_
#define ELA_ERROR_H_

#include <errno.h>
#include <stdio.h>

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

enum {
        ELA_SUCCESS  = 0,
        ELA_FAILURE  = -1,
        ELA_CONTINUE = -2, /* iteration has not converged */
        ELA_EDOM     = 1,  /* input domain error, e.g sqrt(-1) */
        ELA_ERANGE   = 2,  /* output range error, e.g. exp(1e100) */
        ELA_EFAULT   = 3,  /* invalid pointer */
        ELA_EINVAL   = 4,  /* invalid argument supplied by user */
        ELA_EFAILED  = 5,  /* generic failure */
        ELA_EFACTOR  = 6,  /* factorization failed */
        ELA_ESANITY  = 7,  /* sanity check failed - shouldn't happen */
        ELA_ENOMEM   = 8,  /* malloc failed */
        ELA_EBADFUNC = 9,  /* problem with user-supplied function */
        ELA_ERUNAWAY = 10, /* iterative process is out of control */
        ELA_EMAXITER = 11, /* exceeded max number of iterations */
        ELA_EZERODIV = 12, /* tried to divide by zero */
        ELA_EBADTOL  = 13, /* user specified an invalid tolerance */
        ELA_ETOL     = 14, /* failed to reach the specified tolerance */
        ELA_EUNDRFLW = 15, /* underflow */
        ELA_EOVRFLW  = 16, /* overflow  */
        ELA_ELOSS    = 17, /* loss of accuracy */
        ELA_EROUND   = 18, /* failed because of roundoff error */
        ELA_EBADLEN  = 19, /* matrix, vector lengths are not conformant */
        ELA_ENOTSQR  = 20, /* matrix not square */
        ELA_ESING    = 21, /* apparent singularity detected */
        ELA_EDIVERGE = 22, /* integral or series is divergent */
        ELA_EUNSUP =
            23, /* requested feature is not supported by the hardware */
        ELA_EUNIMPL = 24, /* requested feature not (yet) implemented */
        ELA_ECACHE  = 25, /* cache limit exceeded */
        ELA_ETABLE  = 26, /* table limit exceeded */
        ELA_ENOPROG =
            27, /* iteration is not making progress towards solution */
        ELA_ENOPROGJ =
            28, /* jacobian evaluations are not improving the solution */
        ELA_ETOLF = 29, /* cannot reach the specified tolerance in F */
        ELA_ETOLX = 30, /* cannot reach the specified tolerance in X */
        ELA_ETOLG = 31, /* cannot reach the specified tolerance in gradient */
        ELA_EOF   = 32  /* end of file */
};

void ela_error(const char *reason, const char *file, int line, int ela_errno);

#define ELA_ERROR(reason, ela_errno)                                           \
        do {                                                                   \
                ela_error(reason, __FILE__, __LINE__, ela_errno);              \
        } while (0)

#define ELA_ERROR_VAL(reason, ela_errno, value)                                \
        do {                                                                   \
                ela_error(reason, __FILE__, __LINE__, ela_errno);              \
                return value;                                                  \
        } while (0)

#define ELA_ERROR_NULL(reason, ela_errno) ELA_ERROR_VAL(reason, ela_errno, 0)

__END_DECLS

#endif
