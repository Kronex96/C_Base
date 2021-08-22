#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef long unsigned size_t;

void intro_filenames(char *src, char *dst);
bool checking(char *file);
int size_file(char *file);
void cp_file(char *src, char *dst);