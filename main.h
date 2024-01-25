#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations for factors.c
void factorize_number(int number);
void factorize_file(char *file_path);

// Function declarations for rsa.c
int is_prime(int n);
void rsa_factorize(int number);
void rsa_factorize_file(char *file_path);

#endif
