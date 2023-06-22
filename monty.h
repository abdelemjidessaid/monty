#ifndef _MANAGER_H_
#define _MANAGER_H_

/* __________HEADER FILES__________ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* ___________MACROS__________*/
#define BUF_SIZE 1024



/* ________STRUCTS________ */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct variable - global variable to store pointer of stack, and 
 * current code instruction, file included.
 * @file: pointer to the file included.
 * @inst_code: code of current instruction.
 * @stack: pointer of pointer to the stack.
 * 
 * Description: global structure variable.
 */
typedef struct variable
{
        FILE *file;
        int inst_code;
        stack_t **stack;
} global_var;

typedef void (*function)(stack_t **stack, unsigned int line_number);



/* _________EXTERN VARIABLES_________*/
extern global_var var;



/* __________PROTOTYPES__________ */
stack_t *insert_start(stack_t **head, int data);
stack_t *insert_end(stack_t **head, int data);
void read_file(void);
int word_count(char *line);
char *_strdup(char *str);
char **handle_line(char *line);
char **split_line(char *line);
int is_num(char *num);
function find_function(char *opcode);

/* ----------ERROR FUNCTIONS ----------*/
void malloc_error();
void cannot_open_file();
void monty_usage();
void push_error(unsigned int line_number);
void inst_error(unsigned int line_number, char *opcode);
void pint_error(unsigned int line_number);
void pop_error(unsigned int line_number);
void swap_error(unsigned int line_num);
void add_error(unsigned int line_number);
void sub_error(unsigned int line_number);
void div_error(int type, unsigned int line_number);

/* --------- INSTRUCTIONS --------- */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);

/* --------- MEMORY ---------*/
void free_array(char **array);
void free_stack(void);



#endif /* _MANAGER_H_ */
