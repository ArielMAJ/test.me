# test.me [![License](https://img.shields.io/badge/License-Apache_2.0-blue.svg)](https://github.com/ArielMAJ/test.me/blob/develop/LICENSE) [![test.me](https://github.com/ArielMAJ/test.me/actions/workflows/test.me.yml/badge.svg)](https://github.com/ArielMAJ/test.me/actions/workflows/test.me.yml)

## Índice

- [Sobre](#sobre)
  - [O que é o _test.me_?](#o-que-é-o-testme)
  - [O que o _test.me_ faz?](#o-que-o-testme-faz)
  - [Quais são os benefícios de usar o _test.me_?](#quais-são-os-benefícios-de-usar-o-testme)
  - [Exemplo de uso](#exemplo-de-uso)
  - [Por que C?](#por-que-c)
- [Como preparar seu ambiente](#como-preparar-seu-ambiente)
  - [Linux](#linux)
  - [Windows](#windows)
  - [MacOS](#macos)
- [Como usar](#como-usar)
- [Compatibilidade](#compatibilidade)
- [Traduções](#traduções)
- [Contribuindo](#contribuindo)
- [Licença](#licença)
- [Autores, contribuidores e agradecimentos](#autores-contribuidores-e-agradecimentos)

## Sobre

### O que é o _test.me_?

Como desenvolvedor(a) de software ou até mesmo quem está iniciando no mundo da programação, provavelmente já passou pelos seguintes desafios:

1. Código rodar localmente e não compilar em uma ferramenta especifica, o famoso "funciona na minha maquina";

2. Ter que copiar e colar manualmente a entrada para cada caso de teste e verificar manualmente se a saída está correta;

3. Ter casos de teste (que parecem) que tem infinitos caracteres de entrada;

4. Em uma prova online, ter que submeter várias vezes um arquivo para testar se seus casos estão passando.

Esse são apenas alguns dos problemas que podem surgir quando você está desenvolvendo uma solução para um problema. Impasses como esses podem tornar as coisas um pouco mais difíceis do que precisam ser e tirar o foco do que realmente importa no momento: SEU CÓDIGO.

É pensando nesses e outros contratempos que o test.me foi pensado, como forma de otimizar o que realmente é importante: O SEU TEMPO.

### O que o _test.me_ faz?

O _test.me_ é uma ferramenta que automatiza o processo de teste do seu código. Ele recebe como entrada o seu código e uma pasta com casos de teste e retorna o resultado de cada caso de teste (PASSED ou FAILED).

### Quais são os benefícios de usar o _test.me_?

- Você pode testar seu código sem precisar submetê-lo a uma ferramenta de auto-avaliação toda vez que fizer uma alteração;

- Você pode testar seu código offline, sem precisar estar conectado à internet;

- Você pode testar seu código em questão de segundos, sem precisar recompilar e copiar e colar sua entrada toda vez;

- A saída do seu programa será comparada automaticamente com a saída esperada;

- Você pode testar seu código com vários casos de teste em um único comando;

### Exemplo de uso

https://github.com/ArielMAJ/test.me/assets/69123486/a90d5f43-c24d-4f14-8fe9-47c798c35dfb

Obs.: Os comandos do Makefile são apenas para facilitar a construção/compilação e desenvolvimento desta ferramenta. Para usár a ferramenta em si, você só precisará compilá-la uma única vez. Após isso basta apenas executá-la com seu código e testes conforme exemplificado em parte do vídeo e no comando `make run` do Makefile.

### Por que C?

O _test.me_ poderia ter sido desenvolvido em, basicamente, **qualquer** linguagem. Mas foi desenvolvido em C como forma de aprimorar as habilidades do desenvolvedor nessa linguagem. Muitas vezes, C e C++ são as linguagens de escolha para estudar Estruturas de Dados e Algoritmos (EDA) e programação competitiva. É importante saber usá-las de forma eficiente.

## Como preparar seu ambiente

### Linux

#### Instalar git, gcc, make e clang-format

`Ctrl+Alt+T` para abrir o Terminal.

```
sudo apt update
sudo apt upgrade
sudo apt install git
sudo apt install make
sudo apt install gcc
sudo apt install clang-format
```

#### Baixar este repositório

```
git clone https://github.com/ArielMAJ/test.me.git
cd test.me/
```

### Windows

#### Instalar chocolatey

- [Chocolatey](https://chocolatey.org/install) é "A maneira sã de gerenciar software no Windows".

#### Instalar git, gcc, make e clang-format

Aperte `Windows+X` e então `A` para abrir o Terminal.

```
choco install git
choco install mingw
choco install make
choco install llvm
```

#### Baixar este repositório

Aperte `Windows+X` e então `I` para abrir o Terminal.

Então escreva:

```
git clone https://github.com/ArielMAJ/test.me.git
cd test.me/
```

### MacOS

TBA

## Como usar

### Comandos `make`

```bash
make # Compila o projeto.
make help # Mostra os comandos disponíveis.
make clean # Apaga os arquivos compilados.
make run # Roda o projeto com um exemplo de entrada.
make run_all # Roda o projeto com todos os exemplos de entrada.
make valgrind # Roda o projeto com um exemplo de entrada usando valgrind (precisa ter valgrind instalado -> Apenas Linux).
make valgrind_all # Roda o projeto com todos os exemplos de entrada usando valgrind (precisa ter valgrind instalado -> Apenas Linux).
make format # Roda o clang-format no projeto para formatar o código (precisa do clang-format instalado).
```

### Compilar test.me

```
make
```

### Escreva seu código e crie casos de teste para ele

Escreva exemplos de entrada e saídas esperadas para seu código como nos [exemplos deste repositório](../example_input/).

Obs.: A entrada e saída para um único teste devem ter o mesmo nome, exceto pela extensão do arquivo (".in" para entrada, ".out" para saída).

### Teste seu código

```
./bin/test.me <Caminho para seu código C> <Caminho para seus exemplos de entrada e saída>
```

Ex.:

```
./bin/test.me ./example_input/Q03/solution.c ./example_input/Q03/tests/
```

ou, se você tiver muitas soluções para problemas diferentes em uma subpasta com a mesma estrutura de nome, você pode testar tudo com:

```
./bin/test.me <Caminho para a solução em cada pasta> <Caminho para os testes em cada pasta> <Pasta com subpastas para testar>
```

e.g:

```
./bin/test.me ./solution.c ./tests/ ./example_input/
```

## Compatibilidade

- Windows: funciona e é a plataforma principal de desenvolvimento;
- Linux & WSL: funciona e é testado esporadicamente;
- MacOS: deve funciona, ainda precisa de pessoas para testar.

Toda e qualquer pessoa é bem-vinda para testar essa ferramenta localmente e deixar um feedback em [#78](https://github.com/ArielMAJ/test.me/discussions/78). Se você tiver um tempo livre e interesse por isso, sinta-se à vontade para contribuir.

## Traduções

- [Português Brasileiro](./README-ptbr.md)
- [English](../README.md)

## Contribuindo

Contribuições são sempre bem-vindas! Por favor, leia o [guia de contribuição](./CONTRIBUTING.md) para mais detalhes sobre como contribuir com este projeto.

## Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](./LICENSE) para mais detalhes.

## Autores, contribuidores e agradecimentos

- [@ArielMAJ](https://github.com/ArielMAJ): ariel.maj@hotmail.com
  - Ideia original e desenvolvimento da ferramenta.
- [@tauanesales](https://github.com/tauanesales): taysales6@gmail.com
  - Melhorias gerais;
  - Ideias e feedback.

[Topo](#índice)
