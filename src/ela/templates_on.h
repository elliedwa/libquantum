#if defined(BASE_ELA_COMPLEX_LONG)
#define BASE ela_complex_long_double
#define SHORT complex_long_double
#define SHORT_REAL long_double
#define ATOMIC long double
#define MULTIPLICITY 2
#define ZERO                                                                   \
        {                                                                      \
                {                                                              \
                        0.0L, 0.0L                                             \
                }                                                              \
        }
#define ONE                                                                    \
        {                                                                      \
                {                                                              \
                        1.0L, 0.0L                                             \
                }                                                              \
        }

#elif defined(BASE_ELA_COMPLEX)
#if defined(_MSC_VER) && defined(complex)
#undef complex
#endif
#define BASE ela_complex_double
#define SHORT complex
#define SHORT_REAL double
#define ATOMIC double
#define MULTIPLICITY 2
#define ZERO                                                                   \
        {                                                                      \
                {                                                              \
                        0.0, 0.0                                               \
                }                                                              \
        }
#define ONE                                                                    \
        {                                                                      \
                {                                                              \
                        1.0, 0.0                                               \
                }                                                              \
        }
#elif defined(BASE_ELA_COMPLEX)
#define BASE ela_complex_float
#define SHORT complex_float
#define SHORT_REAL float
#define ATOMIC float
#define MULTIPLICITY 2
#define ZERO                                                                   \
        {                                                                      \
                {                                                              \
                        0.0F, 0.0F                                             \
                }                                                              \
        }
#define ONE                                                                    \
        {                                                                      \
                {                                                              \
                        1.0F, 0.0F                                             \
                }                                                              \
        }
#elif defined(BASE_DOUBLE)
#define BASE double
#define SHORT
#define ATOMIC double
#define MULTIPLICITY 1
#define ZERO 0.0
#define ONE 1.0

#else
#error unknown BASE_ directive in source.h
#endif

#define CONCAT2x(a, b) a##_##b
#define CONCAT2(a, b) CONCAT2x(a, b)
#define CONCAT3x(a, b, c) a##_##b##_##c
#define CONCAT3(a, b, c) CONCAT3x(a, b, c)
#define CONCAT4x(a, b, c, d) a##_##b##_##c##_##d
#define CONCAT4(a, b, c, d) CONCAT4x(a, b, c, d)

#ifndef USE_QUALIFIER
#define QUALIFIER
#endif

#ifdef USE_QUALIFIER
#if defined(BASE_DOUBLE)
#define FUNCTION(dir, name) CONCAT3(dir, QUALIFIER, name)
#define TYPE(dir) dir
#define VIEW(dir, name) CONCAT2(dir, name)
#define QUALIFIED_TYPE(dir) QUALIFIER dir
#define QUALIFIED_VIEW(dir, name) CONCAT3(dir, QUALIFIER, name)
#else
#define FUNCTION(a, c) CONCAT4(a, SHORT, QUALIFIER, c)
#define TYPE(dir) CONCAT2(dir, SHORT)
#define VIEW(dir, name) CONCAT3(dir, SHORT, name)
#define QUALIFIED_TYPE(dir) QUALIFIER CONCAT2(dir, SHORT)
#define QUALIFIED_VIEW(dir, name) CONCAT4(dir, SHORT, QUALIFIER, name)
#endif
#if defined(BASE_ELA_COMPLEX)
#define REAL_FUNCTION(dir, name) CONCAT3(dir, QUALIFIER, name)
#define REAL_TYPE(dir) dir
#define REAL_VIEW(dir, name) CONCAT2(dir, name)
#define QUALIFIED_REAL_TYPE(dir) QUALIFIER dir
#define QUALIFIED_REAL_VIEW(dir, name) CONCAT3(dir, QUALIFIER, name)
#else
#define REAL_FUNCTION(a, c) CONCAT4(a, SHORT_REAL, QUALIFIER, c)
#define REAL_TYPE(dir) CONCAT2(dir, SHORT_REAL)
#define REAL_VIEW(dir, name) CONCAT3(dir, SHORT_REAL, name)
#define QUALIFIED_REAL_TYPE(dir) QUALIFIER CONCAT2(dir, SHORT_REAL)
#define QUALIFIED_REAL_VIEW(dir, name) CONCAT4(dir, SHORT_REAL, QUALIFIER, name)
#endif
#else
#if defined(BASE_DOUBLE)
#define FUNCTION(dir, name) CONCAT2(dir, name)
#define TYPE(dir) dir
#define VIEW(dir, name) CONCAT2(dir, name)
#define QUALIFIED_TYPE(dir) TYPE(dir)
#define QUALIFIED_VIEW(dir, name) CONCAT2(dir, name)
#else
#define FUNCTION(a, c) CONCAT3(a, SHORT, c)
#define TYPE(dir) CONCAT2(dir, SHORT)
#define VIEW(dir, name) CONCAT3(dir, SHORT, name)
#define QUALIFIED_TYPE(dir) TYPE(dir)
#define QUALIFIED_VIEW(dir, name) CONCAT3(dir, SHORT, name)
#endif
#if defined(BASE_ELA_COMPLEX)
#define REAL_FUNCTION(dir, name) CONCAT3(dir, name)
#define REAL_TYPE(dir) dir
#define REAL_VIEW(dir, name) CONCAT2(dir, name)
#define QUALIFIED_REAL_TYPE(dir) dir
#define QUALIFIED_REAL_VIEW(dir, name) CONCAT3(dir, name)
#else
#define REAL_FUNCTION(a, c) CONCAT3(a, SHORT_REAL, c)
#define REAL_TYPE(dir) CONCAT2(dir, SHORT_REAL)
#define REAL_VIEW(dir, name) CONCAT3(dir, SHORT_REAL, name)
#define QUALIFIED_REAL_TYPE(dir) CONCAT2(dir, SHORT_REAL)
#define QUALIFIED_REAL_VIEW(dir, name) CONCAT3(dir, SHORT_REAL, name)
#endif
#endif

#define STRING(x) #x
#define EXPAND(x) STRING(x)
#define NAME(x) EXPAND(TYPE(x))
