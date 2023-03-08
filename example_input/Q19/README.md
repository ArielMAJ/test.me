# Questão 19 - ProdEsc

Crie uma função chamada prodesc que calcula o produto escalar entre as
duas matrizes e, usando as duas matrizes A e B definidas na questão anterior,
imprima o resultado. O produto escalar é encontrado usando a seguinte fórmula:

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

1. Não copie código de colegas ou da internet (crie seu próprio código, preferencialmente com sua própria lógica);
2. Todas as saídas do seu código devem ser processadas e retornadas pelo mesmo algoritmo que resolve o problema para um caso qualquer. Ou seja, seu algoritmo não deve retornar uma solução pré-calculada para casos específicos.
3. As entradas, saídas esperadas e saídas reais estão visíveis para simples conferência e facilitar resolver o problema. Você **NÃO** deve copiar a resposta e colocá-la "hard-coded".
