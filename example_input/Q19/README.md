# Q19

- [EN-US](#question-19---prodesc);
- [PT-BR](#questão-19---prodesc);

## Question 19 - ProdEsc

Create a function called ProdEsc, which calculates the product between the two matrices and prints the result of the product of N matrices. The dot product is found using the following formula:

$$\sum_{i=1}^na_ib_i$$

<hr>

Your code should read the following input template:
```
3
2 3
2.0 2.0 2.0
2.0 2.0 2.0
3 2
3.0 3.0
3.0 3.0
3.0 3.0
2 2
0.1 0.1
0.1 0.1
```
Your code must:
1. **Create** arrays from input;
2. Implement a function ("ProdEsc") that receives two matrices and returns the matrix resulting from the product of two matrices;
3. Print the final matrix after performing the product of "n" matrices in sequence (1 decimal place).


In this example, "3" tells you how many matrices will be read and multiplied in sequence. The next line informs the dimensions of the matrix (2x3), followed by the matrix. All cases will be within this pattern. Consider that you will always receive a valid sequence of matrices for calculating the product.

Considering the 3 matrices A, B and C of the example above, you must do ((A@B)@C) (here "@" represents the product).

A@B:
```
18.0 18.0
18.0 18.0
```
(A@B)@C:
```
3.6 3.6
3.6 3.6
```

<details>
   <summary>Recommendations (click to read)</summary>
   1. If you decide to allocate memory for arrays, remember to free that memory too;
   2. If you allocate memory inside a loop and reuse the same variable for new allocations, remember to free this memory at the end of the loop before new allocations as well;
</details>

#### Important Notes:

1. Do not copy code from colleagues or from the internet (write your own code, preferably with your own logic);
2. All outputs from your code must be processed and returned by the same algorithm that solves the problem for any given case. That is, your algorithm should not return a pre-computed solution for specific cases.
3. You should **NOT** copy the answer (the output) and hard-code it.


## Questão 19 - ProdEsc

Crie uma função chamada prodesc que calcula o produto escalar entre as duas matrizes e imprima o resultado do produto de N matrizes. O produto escalar é encontrado usando a seguinte fórmula:

$$\sum_{i=1}^na_ib_i$$

<hr>

Seu código deve ler o seguinte modelo de entrada:
```
3
2 3
2.0 2.0 2.0
2.0 2.0 2.0
3 2
3.0 3.0
3.0 3.0
3.0 3.0
2 2
0.1 0.1
0.1 0.1
```
Seu código deve:
1. **Criar** matrizes a partir da entrada;
2. Implementar uma função ("ProdEsc") que recebe duas matrizes e retorna a matriz resultante do produto de duas matrizes;
3. Imprimir a matriz final após realizar o produto de "n" matrizes em sequência (1 casa decimal).


Nesse exemplo, "3" informa quantas matrizes serão lidas e multiplicadas em sequência. A linha seguinte informa as dimensões da matriz (2x3), seguida pela matriz. Todos os casos estarão dentro desse padrão. Considere que você sempre receberá uma sequência válida de matrizes para o cálculo do produto.

Considerando as 3 matrizes A, B e C do exemplo acima, você deve fazer ((A@B)@C)  (aqui "@" representa o produto).

A@B:
```
18.0 18.0
18.0 18.0
```
(A@B)@C:
```
3.6 3.6
3.6 3.6
```

<details>
  <summary>Recomendações  (clicar para ler)</summary>
  1. Se decidir alocar memória para as matrizes, lembre-se de liberar essa memória também;
  2. Se você alocar memória dentro de um loop e reutilizar uma mesma variável para novas alocações, lembre-se de liberar essa memória no fim do loop antes de novas alocações também;
</details>

#### Observações Importantes:

1. Não copie código de colegas ou da internet (escreva seu próprio código, preferencialmente com sua própria lógica);
2. Todas as saídas do seu código devem ser processadas e retornadas pelo mesmo algoritmo que resolve o problema para um caso qualquer. Ou seja, seu algoritmo não deve retornar uma solução pré-calculada para casos específicos.
3. Você **NÃO** deve copiar a resposta e colocá-la "hard-coded".
