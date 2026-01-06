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
            /*
            error_text_2();
            exit(1);
            */ //nose como manejar esto por ahora
            continue;
        }

        char *endpointer;
        long long value = strtoll(buffer, &endpointer, 10);


        if (endpointer == buffer) {
            error_text();
            continue;
        }
        if (!(*endpointer == '\n' || *endpointer == '\0')) {
            error_text();
            continue;
        }
        if (value < INT_MIN || value > INT_MAX) {
            error_text();
            continue;
        }


        *value_pointer = (int)value;
        valid = 1;

    } while (!valid);
}
