#ifndef QUANTUM_ERROR_H_
#define QUANTUM_ERROR_H_

#include <stdio.h>
#include <stdlib.h>

#define NP_CHECK(ptr)                                                          \
        if (ptr == NULL) {                                                     \
                fprintf(stderr, "%s:%d NULL POINTER: %s \n", __FILE__,          \
                        __LINE__, (#ptr));                                     \
                exit(99);                                                      \
        }

#endif
