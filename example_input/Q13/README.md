# Q13

- [EN-US](#question-13---columnsum);
- [PT-BR](#questão-13---somacoluna);

## Question 13 - ColumnSum

Write a function called ColumnSum, which receives a matrix, calculates its
transposed and adds the elements of the first column.

<hr>

Your code should read the following input:

```
2 4
1.0 2.0 3.0 4.0
1.0 2.0 3.0 4.0
```
Your code must:
1. **Create** an array from the input;
2. Transpose this matrix;
3. Print the transposed matrix (each element with 1 decimal place);
4. Add elements of the first column with a function ("ColumnSum");
5. Print the result of this sum (1 decimal place).

In this example, "2 4" informs the size of the matrix ("2x4"): the first value is the number of rows and the second is the number of columns.

<details>
   <summary>Recommendations (click to read)</summary>
   1. If you decide to allocate memory for arrays, remember to free that memory too;
   2. It might be interesting to write functions to **create**/**release**/**print** matrices (to be reused in the next questions);
</details>

<details> <summary>Tip 01 (click to read)</summary>Use an auxiliary matrix (remember to release the allocated space of both matrices in this case).</details>

#### Important Notes:

1. Do not copy code from colleagues or from the internet (write your own code, preferably with your own logic);
2. All outputs from your code must be processed and returned by the same algorithm that solves the problem for any given case. That is, your algorithm should not return a pre-computed solution for specific cases.
3. You should **NOT** copy the answer (the output) and hard-code it.


## Questão 13 - SomaColuna

Escreva uma função chamada somacoluna que recebe uma matriz, calcula sua
transposta e soma os elementos da primeira coluna.

<hr>

Seu código deve ler a seguinte entrada:

```
2 4
1.0 2.0 3.0 4.0
1.0 2.0 3.0 4.0
```
Seu código deve:
1. **Criar** uma matriz a partir da entrada;
2. Transpor essa matriz;
3. Imprimir a matriz transposta (cada elemento com 1 casa decimal);
4. Somar elementos da primeira coluna com uma função ("SomaColuna"); e
5. Imprimir o resultado dessa soma (1 casa decimal).

Nesse exemplo, "2 4" informa o tamanho da matriz ("2x4"): o primeiro valor é a quantidade de linhas e o segundo é a quantidade de colunas. 

<details>
  <summary>Recomendações  (clicar para ler)</summary>
  1. Se decidir alocar memória para as matrizes, lembre-se de liberar essa memória também;
  2. Talvez seja interessante escrever funções para **criar**/**liberar**/**imprimir** matrizes (para re-uso nas próximas questões);
</details>

<details> <summary>Dica 01 (clicar para ler)</summary>Utilize uma matriz auxiliar (lembre-se de liberar o espaço alocado de ambas matrizes nesse caso).</details>

#### Observações Importantes:

1. Não copie código de colegas ou da internet (escreva seu próprio código, preferencialmente com sua própria lógica);
2. Todas as saídas do seu código devem ser processadas e retornadas pelo mesmo algoritmo que resolve o problema para um caso qualquer. Ou seja, seu algoritmo não deve retornar uma solução pré-calculada para casos específicos.
3. Você **NÃO** deve copiar a resposta e colocá-la "hard-coded".
