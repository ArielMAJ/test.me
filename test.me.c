#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
// #include <errno.h>
// #include <sys/stat.h>
#include<string.h>
#include <sys/stat.h>   // stat
// #include <stdbool.h>    // bool type

int file_exists (char *file_path)
{
    struct stat buffer;
    return (stat (file_path, &buffer) == 0);
}

int iterate_tests(char *, char *);
int iterate_folders(char *, char *, char *);
char *process_file(char *path);
int right_check_unwated(FILE *file, char *to_skip);
int left_check_unwated(FILE *file, char *to_skip);
void f_close(FILE *file);
char *get_next_line(FILE *file);

char OUTPUT_FILE[] = "output.txt";
long int LENGTH;

int main(int argc, char *argv[])
{
    if (argc < 3 || argc > 4)
    {
        printf("\x1B[31m_________________________________________________");
        printf("__________________________________________________\e[0m\n");
        printf("\e[1m\e[4m\e[31mERROR\e[0m: Invalid number of arguments\n\n");

        printf("\x1B[32mUsage \e[3m\e[1msingle folder\e[0m:\e[0m ");
        printf("./test.me \x1B[32m<\e[0mcode_path\x1B[32m>\e[0m \x1B[32m<\e[0mtest_folder_path\x1B[32m>\e[0m\e[0m\n");
        printf("Example: ./test.me ./example_input/Q03/solution.c ./example_input/Q03/tests/\n");

        printf("\n\x1B[32mUsage \e[3m\e[1mmultiple folders\e[0m:\e[0m ");
        printf("./test.me \x1B[32m<\e[0mcode_standard_name\x1B[32m>\e[0m \x1B[32m<\e[0mtest_folder_standard_name\x1B[32m>\e[0m \x1B[32m[\e[0mfolders_path\x1B[32m]\e[0m\e[0m\n");
        printf("Example: ./test.me ./solution.c ./tests/ ./example_input/\n");

        
        printf("\x1B[31m_________________________________________________");
        printf("__________________________________________________\e[0m\n");
        
        return EXIT_FAILURE;
    }

    char *code_path = argv[1];
    char tests_path[strlen(argv[2]) + 2];
    tests_path[0] = '\0';
    strcat(tests_path, argv[2]);
    if (tests_path[strlen(tests_path) - 1] != '/' && tests_path[strlen(tests_path) - 1] != '\\' )
        strcat(tests_path, "/");

    int ERROR_CODE = EXIT_SUCCESS;

    if (argc == 3)
        ERROR_CODE += iterate_tests(code_path, tests_path);
    else
    {
        char folders_path[strlen(argv[3]) + 2];
        folders_path[0] = '\0';
        strcat(folders_path, argv[3]);
        if (folders_path[strlen(folders_path) - 1] != '/' && folders_path[strlen(folders_path) - 1] != '\\' )
            strcat(folders_path, "/");

        ERROR_CODE += iterate_folders(code_path, tests_path, folders_path);
    }

#ifdef _WIN32
    ERROR_CODE += system("del compiled_test_file.exe");
    ERROR_CODE += system("del output.txt");
#else
    ERROR_CODE += system("rm ./compiled_test_file.exe");
    ERROR_CODE += system("rm ./output.txt");
#endif

    return ERROR_CODE;
}

int iterate_tests(char *code_path, char *tests_path)
{
    if (!file_exists(code_path))
    {
        printf("%s not found\n", code_path);
        return EXIT_FAILURE;
    }

    int ERROR_CODE = EXIT_SUCCESS;

    // char *cmd = (char *) malloc (45 + strlen(code_path) + 1);
    char cmd[1000];
    cmd[0] = '\0';
    strcat(cmd, "gcc -std=c11 -Wno-sign-compare -Wfloat-equal -Wundef -Wcast-align -Wwrite-strings -Wredundant-decls -Wno-unused-parameter -Wno-unused-variable -Wshadow -Wall -Wextra -Werror -o compiled_test_file.exe -lm ");
    strcat(cmd, code_path);
    ERROR_CODE += system(cmd);
    // free(cmd);

    if (ERROR_CODE != EXIT_SUCCESS)
        return ERROR_CODE;

    DIR *d = opendir(tests_path);
    if (!d)
    {
        printf("Failed accessing %s\n", tests_path);
        return ERROR_CODE + EXIT_FAILURE;
    }

    printf("___________________\n%s\n", tests_path);

    char input_path[250];
    char output_path[250];

    struct dirent *dir;
    while ((dir = readdir(d)) != NULL && ERROR_CODE == EXIT_SUCCESS)
    {
        if (!((dir->d_type == DT_REG) && (strstr(dir->d_name, ".out") != NULL)))
            continue;

        output_path[0] = '\0';
        strcat(output_path, tests_path);
        strcat(output_path, dir->d_name);

        char *buffer = &dir->d_name[1];
        while (*buffer != '.')
            buffer++;
        buffer[0] = '\0';

        input_path[0] = '\0';
        strcat(input_path, tests_path);
        strcat(input_path, dir->d_name);
        strcat(input_path, ".in");

        if (!file_exists(input_path))
            continue;

        // cmd = (char *) malloc (25 + strlen(input_path) + 3 + strlen(OUTPUT_FILE) + 2);
        cmd[0] = '\0';

#ifdef _WIN32
        strcat(cmd, "compiled_test_file.exe < ");
#else
        strcat(cmd, "./compiled_test_file.exe < ");
#endif
        strcat(cmd, input_path);
        strcat(cmd, " > ");
        strcat(cmd, OUTPUT_FILE);
        ERROR_CODE += system(cmd);
        // free(cmd);

        char *actual_output = process_file(OUTPUT_FILE);
        char *expected_output = process_file(output_path);

        if (strstr(actual_output, expected_output))
        {
            printf("    |- %s: \x1B[32mPASSED :)\e[0m\n", dir->d_name);
        }
        else
        {
            printf("    |- %s: \x1B[31mFAILED :(\e[0m\n", dir->d_name);
            printf("    |-------------------------------------------------------------\n");
            printf("        | Expected:\n");
            printf("        |---------------------------------------------------------\n");
            printf("        |\x1B[32m%s\e[0m", expected_output);
            printf("        |---------------------------------------------------------\n");
            printf("        | Actual:\n");
            printf("        |---------------------------------------------------------\n");
            printf("        |\x1B[31m%s\e[0m", actual_output);
            printf("     ___|---------------------------------------------------------\n");
            printf("    |\n");
        }

        free(actual_output);
        free(expected_output);

    }
    closedir(d);
    printf("    |___________________\n");

    return ERROR_CODE;
}

int iterate_folders(
    char *relative_CODE_path_in_each_folder,
    char *relative_TESTS_path_in_each_folder,
    char *folders_path
)
{
    DIR *d;
    struct dirent *dir;
    d = opendir(folders_path);
    char code_path[250];
    char tests_path[250];
    if (!d)
    {
        printf("Failed accessing %s\n", folders_path);
        return EXIT_FAILURE;
    }
    if (relative_TESTS_path_in_each_folder[0] == '.')
        relative_TESTS_path_in_each_folder++;
    if (relative_CODE_path_in_each_folder[0] == '.')
        relative_CODE_path_in_each_folder++;

    int ERROR_CODE = EXIT_SUCCESS;
    while ((dir = readdir(d)) != NULL && ERROR_CODE == EXIT_SUCCESS)
    {
        if (!(dir->d_type == DT_DIR && !strchr(dir->d_name, '.')))
            continue;
        tests_path[0] = '\0';
        strcat(tests_path, folders_path);
        strcat(tests_path, dir->d_name);
        strcat(tests_path, relative_TESTS_path_in_each_folder);

        code_path[0] = '\0';
        strcat(code_path, folders_path);
        strcat(code_path, dir->d_name);
        if (relative_CODE_path_in_each_folder[0] != '/' && relative_CODE_path_in_each_folder[0] != '\\')
            strcat(code_path, "/");
        strcat(code_path, relative_CODE_path_in_each_folder);

        ERROR_CODE += iterate_tests(code_path, tests_path);
    }
    closedir(d);

    return ERROR_CODE;
}

int right_check_unwated(FILE *file, char *to_skip)
{
    // printf("r\n");
    char current_character;

    int is_EOF;

    // While there are characters to_skip between the current position (new line) and the start of the text.
    do
    {
        is_EOF = !fread(&current_character, sizeof(char), 1, file);
        // Keep reading until reach the end of the file or hit the given condition.
        if (is_EOF)
            break;
    }
    while (strchr(to_skip, current_character));

    int start = ftell(file);
    if (is_EOF)
        return start;

    // Going back one character, as the loop above goes past one character after the last character to_skip.
    fseek(file, -1, SEEK_CUR);
    return start - 1;
}

int left_check_unwated(FILE *file, char *to_skip)
{
    // printf("l\n");
    char current_character;
    // While there are characters to_skip between the text and the current position (new line).
    int pos = ftell(file) - 1;
    if (pos == LENGTH - 1)
    {
        fseek(file, -1, SEEK_CUR);
        {
            int tmp = fread(&current_character, sizeof(char), 1, file);
        }

        if (!strchr(" \r\n", current_character))
            pos = LENGTH;
    }
    do
    {
        if (pos == 0 || pos == LENGTH)
            break;
        // As the "current character" was "already read", we have to go back
        // two steps to read the last character.
        fseek(file, -2, SEEK_CUR);
        {
            int tmp = fread(&current_character, sizeof(char), 1, file); // Reading it.
        }

        // while (current_character == '\r')
        // {
        //     fseek(file, -2, SEEK_CUR);
        //     fread(&current_character, sizeof(char), 1, file);
        // }
        pos--;
    }
    while (strchr(to_skip, current_character));


    if (pos == 0)
        fseek(file, 0, SEEK_SET);
    int end = ftell(file);
    // printf("%d %d\n\n", LENGTH,end);
    return end;
}

void f_close(FILE *file)
{
    if (ferror(file))
    {
        fclose(file);
        printf("Error reading file.\n");
        exit(1);
    }
    // Close the file
    fclose(file);
}

char *process_file(char *path)
{
    // Try to open text file
    FILE *file = fopen(path, "rb");
    if (file == NULL)
    {
        printf("Could not open %s.\n", path);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    LENGTH = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *contents = malloc((LENGTH + 3) * sizeof(char));
    char current_character;

    contents[0] = '\0';
    while (fread(&current_character, sizeof(char), 1, file))
    {
        fseek(file, -1, SEEK_CUR);
        char *line = get_next_line(file);
        if (line[0])
        {
            strcat(contents, line);
            strcat(contents, "\n");
        }
        free(line);
    }

    f_close(file);

    return contents;
}

char *get_next_line(FILE *file)
{
    char current_character;
    int not_EOF = 1;

    int start_of_line = right_check_unwated(file, (char *) " ");
    do
    {
        not_EOF = fread(&current_character, sizeof(char), 1, file);
    }
    while ((current_character != '\n') && not_EOF);

    int curr_pos = ftell(file);
    int end_of_line = left_check_unwated(file, (char *) " \r");

    int contents_length = end_of_line - start_of_line;

    if (contents_length < 1)
        contents_length = 1;

    fseek(file, -contents_length, SEEK_CUR); // Go back to the begining of the line.
    char *contents = (char *) malloc(sizeof(char) * (contents_length + 1));
    // // printf("\nSOL: %d, EOL: %d, strlen=%d\n", start_of_line, end_of_line, contents_length);
    {
        int tmp = fread(contents, sizeof(char), contents_length, file);
    }

    contents[contents_length] = '\0';

    fseek(file, curr_pos - end_of_line, SEEK_CUR);
    return contents;
}
