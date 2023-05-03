#ifndef CORE_H
#define CORE_H

#include <stdio.h>

int iterate_tests(char *, char *);
int iterate_folders(char *, char *, char *);
char *process_file(char *path);
int right_check_unwated(FILE *file, char *to_skip);
int left_check_unwated(FILE *file, char *to_skip);
void f_close(FILE *file);
char *get_next_line(FILE *file);
int file_exists(char *file_path);

#endif  // CORE_H