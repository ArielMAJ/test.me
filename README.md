# test.me [![License](https://img.shields.io/badge/License-Apache_2.0-blue.svg)](https://github.com/ArielMAJ/test.me/blob/develop/LICENSE) [![test.me](https://github.com/ArielMAJ/test.me/actions/workflows/test.me.yml/badge.svg)](https://github.com/ArielMAJ/test.me/actions/workflows/test.me.yml)

## Table of Contents

- [About](#about)
- [How to use](#how-to-use)
- [Compatibility](#compatibility)
- [Translations](#translations)

## About 

As a software developer or even someone just starting out in the world of programming, you've probably faced the following challenges:

1. Your code runs locally, but doesn't work in a specific auto-grading tool: the famous "but it works on my machine";

2. You have test cases with (what looks like) infinite input characters;

3. In an online test, having to submit a file several times to test if your solution is passing on all test cases.

Hitches like these can make things a little more difficult than they need to be and take the focus away from what really matters at the moment: YOUR CODE.

It is with these and other setbacks in mind that **test.me** was designed. As a way to optimize what is really important: YOUR TIME.

## How to use

### Linux

#### Prepare enviroment

`Ctrl+Alt+T` to open Terminal.
```
sudo apt update
sudo apt upgrade
sudo apt install git
sudo apt install make
sudo apt install gcc
```

#### Download this repo

```
git clone https://github.com/ArielMAJ/test.me.git
cd test.me/
```

#### Compile test.me.c

```
make
```

### Windows

#### Prepare enviroment

1. [Download and install git](https://git-scm.com/download/win);
2. [Download and install gcc](https://sourceforge.net/projects/mingw/)

#### Download this repo

Press `Windows+X` then press `I` to open Terminal.

Then write:
```
git clone https://github.com/ArielMAJ/test.me.git
cd test.me/
```

#### Compile test.me.c

Run the compiling command in [Makefile](./Makefile), or run
```
gcc -Wall -Wextra -o test.me .\test.me.c
```

### MacOS

TBA

### Then

#### Write your code and create tests for it

Write example inputs and expected outputs as per [the examples in this repo](./example_input/).
 
PS: Input and output for one single test should have the same naming except for the file extension (".in" for input, ".out" for output).

#### Test your code

```
.\test.me <Path to your C code> <Path to your example inputs and outputs>
```
e.g:
```
.\test.me .\example_input\Q03\solution.c .\example_input\Q03\tests\
```

or, if you have many solutions to different problems in a subfolder with the same naming structure, you can test it all with:
```
.\test.me <Solution path in each subfolder> <Tests path in each subfolder> <Folder with subfolders for testing>
```
e.g:
```
.\test.me .\solution.c .\tests\ .\example_input\
```

PS.: For now, folder names must end with a slash.

## Compatibility

- Windows: works and is the primary development platform;
- Linux & WSL: should work;
- MacOS: should work, still needs testing.

Any and everyone is welcome to test this tool locally and leave feedback at [#78](https://github.com/ArielMAJ/test.me/discussions/78). If you have some free time and are interested in it, please do.

## Translations

TBA
