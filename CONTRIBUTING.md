# Contributing to [test.me](https://github.com/ArielMAJ/test.me)

We love your input! We want to make contributing to this project as easy and transparent as possible, whether it's:

-   Reporting an issue;
-   Discussing the current state of the code;
-   Submitting a fix;
-   Proposing new features;
-   Becoming a maintainer;

## All Changes Happen Through Pull Requests

Pull requests are the best way to propose changes. We actively welcome your pull requests:

1.  Fork the repo and create your branch from `develop`;
2.  If you've changed how something works, update the documentation;
3.  Issue that pull request!

## Under the hood of test.me

Most of the core test.me functionality can be found on [core.c](./src/core.c).

More broadly, in short, test.me will:

<hr>

1. Compile your code (in `code_path`) how you'd probably normally would for simple problem solutions: `gcc <ManyCFlags> -o your_solution.exe your_solution.c`;
2. Execute your code with the input provided by the user (in the test_folder_path/test_folder_standard_name) and save the output to a file: `./your_solution.exe < XX.in > output.txt`;
3. Compare the output of your code with the expected output XX.out (in the test_folder_path/test_folder_standard_name);
4. Print the result of the comparison to the user (PASSED or FAILED);
5. Repeat steps 2-4 for every test in the test_folder_path/test_folder_standard_name;
6. Repeat steps 1-5 for every solution in the folders_path, if folders_path is passed.

<hr>

This can be easily done by hand, but can become somewhat cumbersome when you have to do it for many solutions and many tests. This is where test.me comes in. It automates this process for you, so you can focus on writing your code and tests.

Following the logic above, test.me can easily support any language by just changing the compilation and execution commands (of course, it'll only work if the language is installed in the system). Currently, test.me supports only C. If you want to add support for another language, feel free to do so. Most of the work will probably be writing the logic to identify the file extension and select which way to run each language.


<div align="center">➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖</div>

To understand how test.me reads files, think of files as a very long string/vector of characters. New lines also are character themselves (e.g. `\n`, `\r`, `\r\n`). So, when test.me reads a file, it reads the file character by character until it finds a new line (`\n`). It tries to find the beginning and end of each line stripping not only `\n` and `\r` characters, but also spaces from the beginning and end of each line. After that, it adds a single new line character (`\n`) to the end of the line (to make it easier to print the actual and expected output later, when a test fails). This "pre-processing" is done both to the expected output and the actual output. This is done to make it easier to compare the output of your code with the expected output. For example, if your code outputs `Hello World!\n` and the expected output is `Hello World!` (or even `\nHello World!`, or `Hello World!  ` - with a couple spaces forgotten at the end), test.me will still consider the test as PASSED.

## Local Development

Make sure you have installed all the tools in the [How to prepare your enviroment](./README.md#how-to-prepare-your-enviroment) section in the README.

After you make any changes to the source code, you can compile the project by running `make` in the root folder of the project. Any new `.c` files will be automatically added to the compilation process by the makefile. You can also run `make clean` to remove all the compiled files. If you want to run the project with the example inputs, as a way to easily check if the project is working properly, you can run `make run` or `make run_all` to run all the example inputs.

## Before your PR

Before you submit a pull request, please make sure you have:
1. Ran `make run_all` and `make valgrind` to check if everything is working properly;
2. Ran `make format` to format the code;
3. Updated the documentation related to the functionality you implemented, if necessary.

## Any contributions you make will be under the Apache 2.0 Software License

In short, when you submit changes, your submissions are understood to be under the same [Apache 2.0 License](https://choosealicense.com/licenses/apache-2.0/) that covers the project. Feel free to contact the maintainers if that's a concern.

## Report issues/bugs using GitHub's [issues](https://github.com/ArielMAJ/test.me/issues)

We use GitHub issues to track public bugs. Report a bug by [opening a new issue](https://github.com/ArielMAJ/test.me/issues/new); it's that easy!

## Frequently Asked Questions (FAQs)

TBA

### Bug Reports

**Great Bug Reports** tend to have:

-   A quick summary and/or background
-   Steps to reproduce
    -   Be specific!
    -   Share the snapshot, if possible.
    -   GitHub Readme Stats' live link
-   What actually happens
-   What you expected would happen
-   Notes (possibly including why you think this might be happening or stuff you tried that didn't work)

People _love_ thorough bug reports. I'm not even kidding.

### Feature Request

**Great Feature Requests** tend to have:

-   A quick idea summary
-   What & why do you want to add the specific feature
-   Additional context like images, links to resources to implement the feature, etc.

## License

By contributing, you agree that your contributions will be licensed under its [Apache License 2.0](./LICENSE).
