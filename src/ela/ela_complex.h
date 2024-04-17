#ifndef ELA_COMPLEX_H_
#define ELA_COMPLEX_H_

#if defined(__GNUC__) && (__GNUC__ < 7)
#define ELA_COMPLEX_LEGACY 1
#endif

#if !defined(ELA_COMPLEX_LEGACY) && defined(_Complex_I) && defined(complex) && \
    defined(I) && defined(__STDC__) && (__STDC__ == 1) &&                      \
    defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)

#define ELA_COMPLEX_DEFINE(R, C) typedef R _Complex C;

#define ELA_COMPLEX_P(zp) (&(zp))
#define ELA_COMPLEX_EQ(z1, z2) ((z1) == (z2))

#define ELA_SET_COMPLEX(zp, x, y) (*(zp) = (x) + I * (y))
#define ELA_REAL(z)                                                            \
        (_Generic((z),                                                         \
            complex float: ((float *)&(z)),                                    \
            complex double: ((double *)&(z)),                                  \
            complex long double: ((long double *)&(z)))[0])
#define ELA_IMAG(z)                                                            \
        (_Generic((z),                                                         \
            complex float: ((float *)&(z)),                                    \
            complex double: ((double *)&(z)),                                  \
            complex long double: ((long double *)&(z)))[1])

#define ELA_COMPLEX_P_REAL(zp) ELA_REAL(*(zp))
#define ELA_COMPLEX_P_IMAG(zp) ELA_IMAG(*(zp))
#define ELA_SET_REAL(zp, x)                                                    \
        do {                                                                   \
                ELA_REAL(*(zp)) = (x);                                         \
        } while (0)
#define ELA_SET_IMAG(zp, x)                                                    \
        do {                                                                   \
                ELA_IMAG(*(zp)) = (x);                                         \
        } while (0)

#else
#define ELA_COMPLEX_DEFINE(R, C)                                               \
        typedef struct {                                                       \
                R dat[2];                                                      \
        } C;

#define ELA_REAL(z) ((z).dat[0])
#define ELA_IMAG(z) ((z).dat[1])
#define ELA_COMPLEX_P(zp) ((zp)->dat)
#define ELA_COMPLEX_P_REAL(zp) ((zp)->dat[0])
#define ELA_COMPLEX_P_IMAG(zp) ((zp)->dat[1])
#define ELA_COMPLEX_EQ(z1, z2)                                                 \
        (((z1).dat[0] == (z2).dat[0]) && ((z1).dat[1] == (z2).dat[1]))

#define ELA_SET_COMPLEX(zp, x, y)                                              \
        do {                                                                   \
                (zp)->dat[0] = (x);                                            \
                (zp)->dat[1] = (y);                                            \
        } while (0)
#define ELA_SET_REAL(zp, x)                                                    \
        do {                                                                   \
                (zp)->dat[0] = (x);                                            \
        } while (0)
#define ELA_SET_IMAG(zp, x)                                                    \
        do {                                                                   \
                (zp)->dat[1] = (x);                                            \
        } while (0)

#endif

ELA_COMPLEX_DEFINE(double, ela_complex)
ELA_COMPLEX_DEFINE(long double, ela_complex_long_double)
ELA_COMPLEX_DEFINE(float, ela_complex_float)

#define ELA_SET_COMPLEX_PACKED(zp, n, x, y)                                           \
        do {                                                                          \
                *((zp) + 2 * (n)) = (x); *((zp)+(2*(n)+1)=(y); \
        } while (0)

#endif
