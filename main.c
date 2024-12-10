#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

#define uint1 bool
#define SIZE 3
#define wrapping_mod(a, b) ((a % b + b) % b)

void print_field(uint1 *field, size_t size) {
    for (size_t y = 0; y < size; ++y) {
        for (size_t x = 0; x < size; ++x) {
            if (field[y * SIZE + x]) {
                printf("O");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void eval(uint1 *field, size_t size) {
    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            size_t neighbors = 0;
            for (int i = -1; i <= 1; ++i) {
                if (!i) continue;
                if (field[y * size + wrapping_mod(x + i, size)]) {
                    neighbors++;
                }
            }
            for (int i = -1; i <= 1; ++i) {
                if (!i) continue; 
                if (field[wrapping_mod(y + i, size) * size + x]) {
                    neighbors++;
                }
            }
            if (neighbors < 2) {
                field[y * size + x] = 0;
            } else if (neighbors > 3) {
                field[y * size + x] = 0;
            } else {
                field[y * size + x] = 1;
            }
        }
    }
}

int main(void) {

    uint1 field[SIZE * SIZE] = {
        0, 1, 0,
        0, 0, 1,
        1, 1, 1,
    };

    for (;;) {
        print_field(field, SIZE);
        eval(field, SIZE);
        getchar();
    }

    return 0;
}
