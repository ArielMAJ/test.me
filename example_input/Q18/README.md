# Q18

- [EN-US](#question-18---multimat);
- [PT-BR](#questão-18---multimat);

## Question 18 - MultiMat

Write a function called multimat, which multiplies N matrices.

<hr>

Your code should read the following input:
```
3
2 3
2.0 2.0 2.0
2.0 2.0 2.0
2 3
3.0 3.0 3.0
3.0 3.0 3.0
2 3
0.5 0.5 0.5
0.5 0.5 0.5
```
Your code must:
1. **Create** arrays from input;
2. Implement a function ("MultiMat") that receives two matrices and returns the multiplication of the values in it;<br>
&#9;&#9;&#9;a. The "n" matrices will have the same format;<br>
&#9;&#9;&#9;b. The multiplication will be done by &prod;<sub>n</sub>a<sub>n</sub>[i][j];<br>
&#9;&#9;&#9;c. Not to be confused with Dot Product (which is the next question).
3. Print the final matrix after multiplying "n" matrices in sequence (1 decimal place).

In this example, "3" tells you how many matrices will be read and multiplied in sequence. The next line informs the dimensions of the matrix (2x3), followed by the matrix. All cases will follow this pattern. Assume that you will always receive a valid sequence of matrices for multiplication.


<details>
   <summary>Recommendations (click to read)</summary>
   1. If you decide to allocate memory for arrays, remember to free that memory too;
   2. If you allocate memory inside a loop and reuse the same variable for new allocations, remember to free this memory at the end of the loop before new allocations as well;
</details>

#### Important Notes:

1. Do not copy code from colleagues or from the internet (write your own code, preferably with your own logic);
2. All outputs from your code must be processed and returned by the same algorithm that solves the problem for any given case. That is, your algorithm should not return a pre-computed solution for specific cases.
3. You should **NOT** copy the answer (the output) and hard-code it.


## Questão 18 - MultiMat

Escreva uma função chamada multimat que multiplica N matrizes.

<hr>

Seu código deve ler a seguinte entrada:
```
3
2 3
2.0 2.0 2.0
2.0 2.0 2.0
2 3
3.0 3.0 3.0
3.0 3.0 3.0
2 3
0.5 0.5 0.5
0.5 0.5 0.5
```
Seu código deve:
1. **Criar** matrizes a partir da entrada;
2. Implementar uma função ("MultiMat") que recebe duas matrizes e retorna a multiplicação dos valores nela;<br>
&#9;&#9;&#9;a. As "n" matrizes terão o mesmo formato;<br>
&#9;&#9;&#9;b. A multiplicação se dará por &prod;<sub>n</sub>a<sub>n</sub>[i][j];<br>
&#9;&#9;&#9;c. Não confundir com Produto Escalar (que é a próxima questão).
3. Imprimir a matriz final após multiplicar "n" matrizes em sequência (1 casa decimal).

Nesse exemplo, "3" informa quantas matrizes serão lidas e multiplicadas em sequência. A linha seguinte informa as dimensões da matriz (2x3), seguida pela matriz. Todos os casos estarão dentro desse padrão. Assuma que você sempre receberá uma sequência válida de matrizes para multiplicação.


<details>
  <summary>Recomendações  (clicar para ler)</summary>
  1. Se decidir alocar memória para as matrizes, lembre-se de liberar essa memória também;
  2. Se você alocar memória dentro de um loop e reutilizar uma mesma variável para novas alocações, lembre-se de liberar essa memória no fim do loop antes de novas alocações também;
</details>

#### Observações Importantes:

1. Não copie código de colegas ou da internet (escreva seu próprio código, preferencialmente com sua própria lógica);
2. Todas as saídas do seu código devem ser processadas e retornadas pelo mesmo algoritmo que resolve o problema para um caso qualquer. Ou seja, seu algoritmo não deve retornar uma solução pré-calculada para casos específicos.
3. Você **NÃO** deve copiar a resposta e colocá-la "hard-coded".
