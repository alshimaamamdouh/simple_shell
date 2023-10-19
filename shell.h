#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/**
 *struct list_s - singly linked list
 *@str: string - (malloc'ed string)
 *@len: length of the string
 *@next: points to the next node
 *
 *Description: singly linked list node structure
*/
typedef struct list_s
{
char *str;
unsigned int len;
struct list_s *next;
} list_t;

/**
 *struct built_in_command
 *
 *This structure is used to store information about built-in commands commonly
 *found in a shell environment. It associates the command's name with its
 *absolute file path on the system.
 *
 *@command: The name of the built-in command, e.g., "cp" for the copy command.
 *@path: The absolute file path to the executable for the built-in command.
*/
typedef struct built_in_command
{
char *command;
void (*func)(char **array, size_t size, char **env __attribute__((unused)));
} built_in_command;

void exit_command(char **arr, size_t s, char **env __attribute__((unused)));
void env_command(char **arr, size_t s, char **env __attribute__((unused)));
void (*ex_builtin(char *cmd))(char **, size_t, char **);
int is_builtin(char *cmd);
void intractive_mode(int is_intractive, char **environ);
void print_env(char **environ);
int _strlen(char *str);
int _strcmp(char *str, char *s);
char *_strdup(char *c);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
void print_prompt(int is_intractive);
void free_list(list_t *head);
char **linked_list_to_array(list_t *head, size_t *size);
void free_array(char **array, size_t size);
size_t list_len(const list_t *h);
list_t *add_node_end(list_t **head, const char *str);
list_t *get_command(char *lineptr, list_t *head, ssize_t *flag);
void non_intractive_mode(const char *filename);
char *_getenv(const char *name, char **environ, int *offset);
char *_path(char *cmd, char **environ);
#endif
