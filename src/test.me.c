#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colors.h"
#include "core.h"

int main(int argc, char *argv[]) {
  if (argc < 3 || argc > 4) {
    printf(RED
           "___________________________________________________________________"
           "________________________________\n" NO_COLOR);
    printf("\e[1m\e[4m\e[31mERROR" NO_COLOR
           ": Invalid number of arguments\n\n");

    printf(GREEN "Usage \e[3m\e[1msingle folder" NO_COLOR ": " YELLOW
                 "./test.me " GREEN "<" CYAN "code_path" GREEN "> <" CYAN
                 "test_folder_path" GREEN ">\n" NO_COLOR);
    printf(
        "Example: ./test.me ./example_input/Q03/solution.c "
        "./example_input/Q03/tests/\n\n");

    printf(GREEN "Usage \e[3m\e[1mmultiple folders" NO_COLOR ": " YELLOW
                 "./test.me " GREEN "<" CYAN "code_standard_name" GREEN
                 "> <" CYAN "test_folder_standard_name" GREEN "> <" CYAN
                 "folders_path" GREEN ">\n" NO_COLOR);
    printf("Example: ./test.me ./solution.c ./tests/ ./example_input/\n");

    printf(RED
           "___________________________________________________________________"
           "________________________________\n" NO_COLOR);

    return EXIT_FAILURE;
  }

  char *code_path = argv[1];
  char tests_path[strlen(argv[2]) + 2];
  tests_path[0] = '\0';
  strcat(tests_path, argv[2]);
  if (tests_path[strlen(tests_path) - 1] != '/' &&
      tests_path[strlen(tests_path) - 1] != '\\')
    strcat(tests_path, "/");

  int ERROR_CODE = EXIT_SUCCESS;

  if (argc == 3)
    ERROR_CODE += iterate_tests(code_path, tests_path);
  else {
    char folders_path[strlen(argv[3]) + 2];
    folders_path[0] = '\0';
    strcat(folders_path, argv[3]);
    if (folders_path[strlen(folders_path) - 1] != '/' &&
        folders_path[strlen(folders_path) - 1] != '\\')
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
