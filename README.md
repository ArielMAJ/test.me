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

1. Compile test.me.c.
    - e.g. `gcc -O2 -std=c11 -Wall -Wextra -lm -o test.me.exe .\test.me-v2.c`
2. Write your code and create tests for it (example inputs and expected outputs) as per [the examples in this repo](https://github.com/ArielMAJ/test.me/tree/main/example_input).
    - Input and output for one single test should have the same naming except for the file extension (".in" for input, ".out" for output).
3. Test your code.
    - e.g. `.\test.me <Path to your C code> <Path to your example inputs and outputs>`
    - e.g. `.\test.me .\example_input\Q03\solution.c .\example_input\Q03\tests\`
4. If you have many solutions to different problems in a subfolder with the same naming structure, you can test it all with:
    - e.g. `.\test.me <Solution path in each subfolder> <Tests path in each subfolder> <Folder with subfolders for testing>`
    - `.\test.me .\solution.c .\tests\ .\example_input\`

## Compatibility

- Windows, works and is the primary development platform.

## Translations

TBA
