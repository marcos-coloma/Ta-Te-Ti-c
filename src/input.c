#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "input.h"
#include "messages.h"

void int_number_input(int *value_pointer) {
    char buffer[100];
    int valid = 0;

    do {
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            continue;
        }

        char *endpointer;
        long long value = strtoll(buffer, &endpointer, 10);


        if (endpointer == buffer) {
            input_error();
            continue;
        }
        if (!(*endpointer == '\n' || *endpointer == '\0')) {
            input_error();
            continue;
        }
        if (value < INT_MIN || value > INT_MAX) {
            input_error();
            continue;
        }


        *value_pointer = (int)value;
        valid = 1;

    } while (!valid);
}
