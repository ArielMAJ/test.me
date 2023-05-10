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

TBA

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
