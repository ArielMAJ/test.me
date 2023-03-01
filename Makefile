.SILENT: test-me

test-me:
	gcc -Wno-sign-compare -Wfloat-equal -Wundef -Wcast-align -Wwrite-strings -Wlogical-op -Wredundant-decls -Wno-unused-parameter -Wno-unused-variable -Wshadow -Wall -Wextra -o test.me ./test.me.c
