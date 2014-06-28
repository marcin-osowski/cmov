
#define FUNC_NAME test_branch
#include "test_base.h"
#undef FUNC_NAME

#define FUNC_NAME test_branch_0
#define EXPECT 0
#include "test_base.h"
#undef EXPECT
#undef FUNC_NAME

#define FUNC_NAME test_branch_1
#define EXPECT 1
#include "test_base.h"
#undef EXPECT
#undef FUNC_NAME


