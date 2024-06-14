### README: Atividade de Simulação e Análise de Desempenho - Implementação do Xorshift em C

Este repositório contém um projeto desenvolvido como parte de uma atividade do curso de graduação na disciplina de Simulação e Análise de Desempenho. O objetivo principal desta atividade foi implementar o algoritmo Xorshift para geração de números pseudoaleatórios em linguagem C, com base nas diretrizes do livro "Numerical Recipes, 3rd Ed." (Press et al., 2007).

### Estrutura do Projeto

O projeto está estruturado da seguinte forma:

1. **Implementação do Algoritmo Xorshift**

   - **Arquivo `xorshift.c`**: Contém a implementação do algoritmo Xorshift para geração de números pseudoaleatórios.
2. **Funções Implementadas**

   - **Função `xorshift_init`**: Inicializa o estado interno do gerador Xorshift com uma semente específica.
   - **Função `xorshift_next`**: Gera o próximo número pseudoaleatório usando o algoritmo Xorshift.
   - **Função `xorshift_next_event`**: Gera um evento pseudoaleatório específico (números entre 0 e 9) usando o Xorshift.
   - **Função `generate_xorshift_numbers`**: Gera uma sequência de números pseudoaleatórios usando Xorshift, armazenando-os em um array fornecido.
   - **Função `time_function`**: Mede o tempo de execução de uma função que gera números pseudoaleatórios.
   - **Função `chi_squared_test`**: Realiza o teste do chi-quadrado para avaliar a uniformidade dos números gerados.

### Execução do Projeto

Para compilar e executar o projeto:

1. Compile o arquivo `xorshift.c` usando um compilador C compatível (por exemplo, GCC).
   ```bash
   gcc -o xorshift xorshift.c
   ```

2. Execute o programa compilado `xorshift`.
   ```bash
   ./xorshift
   ```

### Resultados Obtidos

Os resultados são apresentados para diferentes configurações de geração de números pseudoaleatórios e incluem:

- **Tempo de Execução**: Medido para a função de geração de números usando Xorshift.
- **Teste do Chi-Quadrado**: Avaliação da uniformidade dos números gerados através do teste estatístico do chi-quadrado.


### Referências

- Press, W. H., Teukolsky, S. A., Vetterling, W. T., & Flannery, B. P. (2007). Numerical Recipes 3rd Edition: The Art of Scientific Computing. Cambridge University Press.

### Autor

Este projeto foi desenvolvido como parte das atividades da disciplina de Simulação e Análise de Desempenho do curso de graduação em Engenharia de Computação.
