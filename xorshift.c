#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>



typedef struct {
    uint32_t state;
} Xorshift;


void xorshift_init(Xorshift *x, uint32_t seed) {
    x->state = seed;
}

// Função para gerar o próximo número pseudoaleatório
uint32_t xorshift_next(Xorshift *x) {
    uint32_t state = x->state;
    state ^= state << 13;
    state ^= state >> 17;
    state ^= state << 5;
    x->state = state;
    return state;
}


// Função para gerar o próximo evento
uint32_t xorshift_next_event(Xorshift *x) {
    return xorshift_next(x) % 10;
}


// Função para gerar números usando o Xorshift
void generate_xorshift_numbers(uint32_t seed, int count, int *numbers) {
    Xorshift x;
    xorshift_init(&x, seed);
    for (int i = 0; i < count; i++) {
        numbers[i] = xorshift_next_event(&x);
    }
}

void generate_rand_numbers(int count, int *numbers) {
    for (int i = 0; i < count; i++) {
        numbers[i] = rand() % 10;
    }
}

double time_function(void (*func)(int, int*), int count, int *numbers) {
    clock_t start = clock();
    func(count, numbers);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}


double chi_squared_test(int *numbers, int count) {
    int observed[10] = {0};
    double expected = count / 10.0;
    double chi_squared = 0.0;

    for (int i = 0; i < count; i++) {
        observed[numbers[i]]++;
    }

    for (int i = 0; i < 10; i++) {
        double diff = observed[i] - expected;
        chi_squared += diff * diff / expected;
    }

    return chi_squared;
}


// Inicialização do gerador de números pseudoaleatórios com a semente 42
// e geração de 10 números com tamanhos diferentes
int main() {
    int counts[] = {100000, 1000000, 10000000, 100000000};
    uint32_t seed = 42;
    int *numbers;

    for (int i = 0; i < sizeof(counts)/sizeof(counts[0]); i++) {
        int count = counts[i];
        numbers = (int *)malloc(count * sizeof(int));

        // Testando rand()
        double time_rand = time_function(generate_rand_numbers, count, numbers);
        double chi2_rand = chi_squared_test(numbers, count);

        // Testando Xorshift
        double time_xorshift = time_function((void (*)(int, int *))generate_xorshift_numbers, count, numbers);
        double chi2_xorshift = chi_squared_test(numbers, count);

        printf("Resultados para %d gerações:\n", count);
        printf("Tempo para rand(): %f segundos\n", time_rand);
        printf("Teste do chi-quadrado para rand(): %f\n", chi2_rand);
        printf("Tempo para Xorshift: %f segundos\n", time_xorshift);
        printf("Teste do chi-quadrado para Xorshift: %f\n\n", chi2_xorshift);

        free(numbers);
    }

    return 0;
}
