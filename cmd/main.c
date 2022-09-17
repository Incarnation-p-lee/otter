#include "../common/types.h"
#include "../common/apis.h"

static inline void validate_riscv_extensions() {
    s_validate_result_collection_t *collection = validate_extensions();

    dispose_result_collection(&collection);
}

int main() {
    validate_riscv_extensions();

    return 0;
}
