#include "ela_block.h"

#define BASE_ELA_COMPLEX
#include "../templates_on.h"
#include "block_source.h"
BLOCK_SOURCE
#include "../templates_off.h"
#undef BASE_ELA_COMPLEX

#define BASE_DOUBLE
#include "../templates_on.h"
#include "block_source.h"
BLOCK_SOURCE
#include "../templates_off.h"
#undef BASE_DOUBLE
