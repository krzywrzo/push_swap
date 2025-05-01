#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>

#include "libft/libft.h"

char    *fill_stack(char *filler_values, char *stack);
char    **copy_args(int argc, char **argv);
int     *temp_to_stack(char **temp_stack, int stack_size);

#endif