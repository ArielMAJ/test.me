.SILENT: test.me-v2

test.me-v2:
	gcc -std=c11 -Wno-sign-compare -Wfloat-equal -Wundef -Wcast-align -Wwrite-strings -Wlogical-op -Wredundant-decls -Wno-unused-parameter -Wno-unused-variable -Wshadow -Wall -Wextra -o test.me ./test.me-v2.c
