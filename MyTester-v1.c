#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char * process_file(char * path);
char * get_line(char *path, int line);
int isnumeric(char *str);
int right_check_unwated(FILE *file, char *to_skip);
int left_check_unwated(FILE *file, char *to_skip);
void f_close(FILE *file);
int skip_lines(FILE *file, int amount);
char * get_next_line(FILE *file);
char * get_specific_line(char *path, int line);


char OUTPUT_FILE[] = "output.txt";
long int LENGTH;

int main(int argc, char *argv[])
{
    // This file should only run in the following conditions:
    // It should receive exactly 6 arguments (including the file path).
    if (argc != 6)
    {
        printf(
            "Invalid usage: not enough arguments. \"Empty\" arguments should receive \"_\".\n\
            \rExpected:\n%s \"<CommandLine>\" \"_<AssertFilePath>\" \"_<SpecificLineNumber>\" \"_<Contains>\" \"<ExpectedResult>\"\n",
            argv[0]
        );
        return 1;
    }
    // The third, fourth and fifth argument should always start with "_", which will
    // be ignored and removed from the string later.
    if (!((argv[2][0] == '_') && (argv[3][0] == '_') && (argv[4][0] == '_')))
    {
        printf(
            "Invalid usage: arguments in the middle should have a \"_\" before the actual input.\n\
            \rExpected:\n%s \"<CommandLine>\" \"_<AssertFilePath>\" \"_<SpecificLineNumber>\" \"_<Contains>\" \"<ExpectedResult>\"",
            argv[0]
        );
        return 1;
    }

    char *input_command_line = argv[1];
    char *input_assert_file_path = argv[2] + 1;
    char *input_specific_line = argv[3] + 1;
    char *input_contains = argv[4] + 1;
    char *input_expected_result = argv[5];

    printf("******************************************\n");
    printf("COMMAND LINE: %s\n", input_command_line);
    printf("ASSERT FILE PATH: %s\n", input_assert_file_path);
    printf("SPECIFIC LINE: %s\n", input_specific_line);
    printf("CONTAINS: %s\n", input_contains);
    printf("EXPECTED RESULT: %s\n", input_expected_result);
    printf("******************************************\n\n");

    char *cmd;
    cmd = (char *) malloc(sizeof(char) * (strlen(input_command_line) + 3 + strlen(OUTPUT_FILE) + 1));
    cmd[0] = '\0';
    strcat(cmd, input_command_line);
    strcat(cmd, " > ");
    strcat(cmd, OUTPUT_FILE);
    
    // printf("%s\n", cmd);
    system(cmd);
    free(cmd);

    // printf("Getting OUTPUT_FILE\n");
    char *actual_output = process_file(OUTPUT_FILE);


    char *expected_output;

    // printf("Checking OP\n");
    // Checking chosen option and getting the raw expected output.
    if (input_contains[0]) // If it is an empty string this will be false, else it's true.
    {
        // printf("CONTAINS\n");
        expected_output = (char *) malloc(sizeof(input_contains) + 1);
        expected_output[0] = '\0';
        strcat(expected_output, input_contains);
        // strcat(expected_output, "\n");
    }
    else if (input_assert_file_path[0])
    {
        // printf("PATH\n");
        if (isnumeric(input_specific_line))
            expected_output = get_specific_line(input_assert_file_path, atoi(input_specific_line));
        else
            expected_output = process_file(input_assert_file_path);
    }
    else
    {
        // printf("Not enough inputs.");
        return 1;
    }

    // Checking if tests passed and comparing against expected result.
    char test_result[8];
    if (strstr(actual_output, expected_output))
        strncpy(test_result, "PASSED\0", 7);
    else
        strncpy(test_result, "FAILED\0", 7);

    printf(
        "Expected: %s\nActual: %s\n",
        input_expected_result,
        test_result
    );

    if (test_result[0] == 'F')
    {
        printf("Expected:\n%s\n", expected_output);
        printf("Actual:\n%s\n", actual_output);
    }

    
    // int i = 0;
    // while(expected_output[i]!='\0') {
        // printf("%d", expected_output[i]);
        // i++;
    // }
    // i = 0;
    // while(actual_output[i]!='\0') {
        // printf("%d", actual_output[i]);
        // i++;
    // }
    
    free(actual_output);
    free(expected_output);
    
    // TODO: compare strings correctly
    if (!(test_result[0] == input_expected_result[0]))
    {
        printf(":(\n");
        // printf("❌❌❌❌❌❌❌❌❌❌\n");
        return EXIT_FAILURE;
    }

    // TODO: Find a way of printing emojis in any OS correctly.
    
    // First way I found that prints in Windows.
    // // #include <io.h>
    // // #include <fcntl.h>
    // #ifndef _O_U16TEXT
    //   #define _O_U16TEXT 0x20000
    // #endif
    // Both of the following functions raises the "implicit declaration" warning
    // _setmode(_fileno(stdout), _O_U16TEXT); // Not sure where they are declared nor how to call them properly.
    // wprintf(L"✅✅");

    // Second way I found that prints in Windows.
    // SetConsoleOutputCP(CP_UTF8); // Needs to #include <Windows.h> (windows only??)
    // printf("✅✅✅✅✅✅✅✅✅✅✅✅");

    // Success
        printf(":)\n");
    return EXIT_SUCCESS;
}

// char * process_file(char * path)
// {
//     // Try to open text file
//     FILE *file = fopen(path, "rb");
//     if (file == NULL)
//     {
//         printf("Could not open %s.\n", path);
//         exit(1);
//     }

//     fseek(file, 0, SEEK_END);
//     long int length = ftell(file);
//     fseek(file, 0, SEEK_SET);

//     char *contents = malloc((length + 1) * sizeof(char));
//     // Spell-check each word in text
//     char current_character;
//     int index = 0;

//     // Skipping spaces, \\r and \\n at the beginning of the file.
//     right_check_unwated(file, (char *) " \r\n");

//     while (fread(&current_character, sizeof(char), 1, file))
//     {
//         printf("%d\t", current_character);
//         if (strchr("\r\n", current_character))
//         {
//             // printf("%d", current_character);
//             // Getting current position in the file as to resume iterating towards the end of the it.
//             size_t to_go_back = ftell(file);

//             int end_of_phrase = left_check_unwated(file, (char *) " \r\n");

//             // Goes back some positions in the contents string (as to later
//             // automatically "erase" unwanted characters by overwriting them).
//             index -= (to_go_back) - end_of_phrase;

//             // The iteration above ends up going back to the first non white space character.
//             // index++; // So we add one to this variable so we don't overwrite that character.
            
//             fseek(file, to_go_back, SEEK_SET); // Go back to the new line.
            
//             int start_of_phrase = right_check_unwated(file, (char *) " \r\n");

//             if (start_of_phrase == length) // Stops if we reach the end of the file. 
//                 break;

//             // char *ptr = strchr(" \r\n", ch);

//             // We only get here if we found at least one new line character,
//             // so we're adding it to the content.
//             contents[index] = '\n';
//             index++;      
//         }
//         // Appending current character to string.
//         contents[index] = current_character;
//         index++;
//     }


//     // Goes back some positions in the contents string (as to later
//     // automatically "erase" unwanted characters by overwriting them).
//     // int end_of_file = ftell(file);
//     // int end_of_phrase = left_check_unwated(file, (char *) " \r\n");
//     printf("\nIndex: %d\n", index);
//     // index -= end_of_file - end_of_phrase;
//     index++;
//     printf("\nIndex: %d\n", index);
//     // Adding null character to ensure correctness.
//     contents[index] = '\0';

//     f_close(file);

//     return contents;
// }

int isnumeric(char *str)
{
    int i = 0;
    do
    {
        if (!isdigit(str[i]))
              return 0;
        i++;
    }
    while (str[i] != '\0');

    return 1;
}


// char * get_line(char *path, int line)
// {
//     printf("Lines\n");
//     if (line < 1)
//     {
//         printf("Line was %d. Expected an integer greater than 0.", line);
//         exit(EXIT_FAILURE);
//     }

//     FILE *file = fopen(path, "rb");

//     char current_character;
  
//     // Check if file exists
//     if (file == NULL)
//     {
//         printf("Could not open file %s", path);
//         exit(1);
//     }

//     int start_of_line = 0, end_of_line = 0;
//     // Skipping spaces in the first line.
//     start_of_line = right_check_unwated(file, (char *) " ");

//     int new_line_count = 0;
//     while (fread(&current_character, sizeof(char), 1, file)) //&& (new_line_count != line))
//     {
//         printf("%d\t", current_character);
//         if (strchr("\n", current_character))
//         {   
//             new_line_count++;
//             if (new_line_count == line - 1)
//                 start_of_line = right_check_unwated(file, (char *) " ");
//             else if (new_line_count == line)
//             {
//                 // Skipping spaces at the end of the line.
//                 end_of_line = left_check_unwated(file, (char *) " \r");
//                 break;
//             }
//         }
//     }
//     if (new_line_count + 1 < line)
//     {
//         printf("Line \"%d\" specified doesn't exist. Amout of lines in file: %d.\n", line, new_line_count + 1);
//         exit(1);
//     }

//     if ((new_line_count == 0) || (new_line_count + 1 == line))
//         end_of_line = left_check_unwated(file, (char *) " ");
//     printf("\nnew_line_count: %d\n",new_line_count);
//     fseek(file, start_of_line, SEEK_SET); // Go back to the begining of the line.

//     int contents_length = end_of_line - start_of_line;
//     if (contents_length < 1)
//         contents_length = 0;

//     char * contents = (char *) malloc(sizeof(char) * (contents_length + 1));
//     printf("\nSOL: %d, EOL: %d, strlen=%d\n", start_of_line, end_of_line, contents_length);
//     fread(contents, sizeof(char), contents_length, file);
//     contents[contents_length] = '\0';

//     f_close(file);
    
//     return contents;
// }

int right_check_unwated(FILE *file, char *to_skip)
{
    // printf("r\n");
    char current_character;

    int is_EOF;

    // While there are characters to_skip between the current position (new line) and the start of the text.
    do {
        is_EOF = !fread(&current_character, sizeof(char), 1, file);
        // Keep reading until reach the end of the file or hit the given condition.
        if (is_EOF)
            break;
    } while (strchr(to_skip, current_character));
    
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
        fread(&current_character, sizeof(char), 1, file);
        if (!strchr(to_skip, current_character))
            pos = 0;
    }
    do {
        if (pos == 0)
            break;
        // As the "current character" was "already read", we have to go back
        // two steps to read the last character.
        fseek(file, -2, SEEK_CUR);
        fread(&current_character, sizeof(char), 1, file); // Reading it.
        // while (current_character == '\r')
        // {
        //     fseek(file, -2, SEEK_CUR);
        //     fread(&current_character, sizeof(char), 1, file);
        // }
        pos--;
    } while (strchr(to_skip, current_character));


    if (pos == 0)
        fseek(file, 0, SEEK_SET);

    int end = ftell(file);
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

char * process_file(char * path)
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

    char *contents = malloc((LENGTH + 1) * sizeof(char));
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


int skip_lines(FILE *file, int amount)
{
    if (amount == 0)
        return 0;

    char current_character;
    int line_count = 0;
    int not_EOF;
    do 
    {
        not_EOF = fread(&current_character, sizeof(char), 1, file);
        if (current_character == '\n')
            line_count++;
    }
    while (line_count < amount && not_EOF);

    return line_count;
}

char * get_next_line(FILE *file)
{
    char current_character;
    int not_EOF = 1;

    int start_of_line = right_check_unwated(file, (char *) " ");
    do {
        not_EOF = fread(&current_character, sizeof(char), 1, file);
    } while ((current_character != '\n') && not_EOF);

    int curr_pos = ftell(file);
    int end_of_line = left_check_unwated(file, (char *) " \r");

    int contents_length = end_of_line - start_of_line;
    if (contents_length < 1)
        contents_length = 0;

    fseek(file, -contents_length, SEEK_CUR); // Go back to the begining of the line.
    char * contents = (char *) malloc(sizeof(char) * (contents_length + 1));
    // // printf("\nSOL: %d, EOL: %d, strlen=%d\n", start_of_line, end_of_line, contents_length);
    fread(contents, sizeof(char), contents_length, file);
    contents[contents_length] = '\0';
    
    fseek(file, curr_pos - end_of_line, SEEK_CUR);
    return contents;
}

char * get_specific_line(char *path, int line)
{
    FILE *file = fopen(path, "rb");
    if (file == NULL)
    {
        printf("Could not open %s.\n", path);
        exit(1);
    }
    if (skip_lines(file, line - 1) < line - 1)
    {
        printf("The file %s has less than %d lines.", path, line);
        exit(1);
    }
    char *contents = get_next_line(file);
    f_close(file);
    return contents;
}
