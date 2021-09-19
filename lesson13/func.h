#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void intro_filenames(char *src);
bool checking(char *file);
void read_s(char *src, char *c);
bool to_strct(char *in, int *yr, int *mn, int *day, int *hr, int *min, int *temp);
void print_stat(int nmn, int cnt, int min, int max, int aver);
void help();
bool m_to_num(const char *s, int *m);
