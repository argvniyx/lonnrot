#include <stdio.h>
#include <inttypes.h>
#include "types.h"

int64_t entry();
void print_result(int64_t);
void print_char(int64_t);

int main(int argc, char **argv) {
    print_result(entry());
    return 0;
}

void print_result(int64_t result) {
    if(INT_TYPE_TAG == (INT_TYPE_MASK & result)) {
        printf("%" PRId64 "\n", result >> INT_SHIFT);
    }
    else if (CHAR_TYPE_TAG == (CHAR_TYPE_MASK & result)) {
        print_char(result);
        printf("\n");
    }
    else {
        switch(result) {
            case VAL_TRUE:
                printf("#t\n");
                break;
            case VAL_FALSE:
                printf("#f\n");
                break;
        }
    }
}
