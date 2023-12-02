#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    int read = input(data, &n);

    if (read == 0) {
        squaring(data, n);
        output(data, n);
    } else {
        printf("n/a");
    }

    return 0;
}

int input(int *a, int *n) {
    int succes_read_variable = scanf("%d", n);
    char last_char = getchar();
    if (succes_read_variable == 1 && last_char == '\n' && *n > 0 && *n < NMAX) {
        for (int *p = a; p < (a + *(n)); p++) {
            int quantity_read_variable = scanf("%d", p);
            char last_char_second_input = getchar();
            if (quantity_read_variable != 1 && last_char_second_input != '\n') {
                return 1;
            }
        }
        return 0;
    } else {
        return 1;
    }
}

void output(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        if (i < n - 1) {
            printf("%d ", *(a + i));
        } else {
            printf("%d", *(a + i));
        }
    }
}

void squaring(int *a, int n) {
    int *p = a;
    for (int i = 0; i < n; i++) {
        *p = *(p) * (*p);
        p++;
    }
}
