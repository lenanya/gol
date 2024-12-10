#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

#define uint1 bool
#define SIZE 10
#define wrapping_mod(a, b) ((a % b + b) % b)

void print_field(uint1 *field, size_t size) {
    for (size_t y = 0; y < size; ++y) {
        for (size_t x = 0; x < size; ++x) {
            if (field[y * SIZE + x]) {
                printf("O");
            } else {
                printf(".");
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
            for (int yi = -1; yi <= 1; ++yi) {
                for (int xi = -1; xi <= 1; ++xi) {
                    if (!xi && !yi) continue;
                    if (field[wrapping_mod(y + yi, size) * size + wrapping_mod(x + xi, size)]) {
                        neighbors++;
                    }
                }
                
            }
            
            printf("%d", neighbors);
            if (neighbors < 2) {
                field[y * size + x] = 0;
            } else if (neighbors > 3) {
                field[y * size + x] = 0;
            } else if (neighbors == 2 || neighbors == 3) {
                field[y * size + x] = 1;
            }
        }
        printf("\n");
    }
}

int main(void) {

    uint1 *field = calloc(sizeof(uint1), SIZE*SIZE); 
    
    field[99] = 1;
    field[98] = 1;
    field[97] = 1;
    field[89] = 1;
    field[78] = 1;

    for (;;) {
        print_field(field, SIZE);
        eval(field, SIZE);
        usleep(100000);
    }

    return 0;
}
