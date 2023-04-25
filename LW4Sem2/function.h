#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

#define QUESTION 'Q'
#define ANSWER 'A'
#define YES 'y'
#define NO 'n'

FILE* file_create(const char* file_name);
FILE* file_open(const char* file_name);
node* new_node(const char* question);
node* traversal(node* root);
void free_tree(node* root);
void free_node(node* tree_node);
void add(node* node_to_change);
void push_database(FILE* database_file, node* root);
node* load_database(FILE* database_file);
