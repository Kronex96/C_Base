#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void intro_filenames(char *src);
bool checking(char *file);
void read_s(char *src, char *c);
void to_strct(char *in, int *yr, int *mn, int *day, int *hr, int *min, int *temp);

