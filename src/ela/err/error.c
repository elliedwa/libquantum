#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "ela_error.h"


void
ela_error(const char *reason, const char *file, int line, int ela_errno)
{
        fprintf(stderr, "ela: %s,%d: %s: %s\n", file, line, "ERROR", reason);
        abort();
}

