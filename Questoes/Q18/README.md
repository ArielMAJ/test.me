# Exercício: Questão 18 - Lista Programação (MultiMat)

Arquivo zip gerado em: 08/05/2022 16:58:13 
Este arquivo contém todos os casos de teste cadastrados até o momento, disponível apenas para professores/monitores. 
Para alterar um caso de teste acesse o sistema. 


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

Nesse exemplo, "3" informa quantas matrizes serão lidas e multiplicadas em sequência. A linha seguinte informa as dimensões da matriz (2x3), seguida pela matriz. Todos os casos estarão dentro desse padrão. Considere que você sempre receberá uma sequência válida de matrizes para o cálculo da multiplicação.


<details>
  <summary>Recomendações  (clicar para ler)</summary>
  1. Se decidir alocar memória para as matrizes, lembre-se de liberar essa memória também;
  2. Se você alocar memória dentro de um loop e reutilizar uma mesma variável para novas alocações, lembre-se de liberar essa memória no fim do loop antes de novas alocações também;
</details>


#### Observações Importantes:

1. Não copie código de colegas ou da internet (crie seu próprio código, preferencialmente com sua própria lógica);
2. Todas as saídas do seu código devem ser processadas e retornadas pelo mesmo algoritmo que resolve o problema para um caso qualquer. Ou seja, seu algoritmo não deve retornar uma solução pré-calculada para casos específicos.
3. As entradas, saídas esperadas e saídas reais estão visíveis para simples conferência e facilitar resolver o problema. Você **NÃO** deve copiar a resposta e colocá-la "hard-coded".