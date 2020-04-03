# arithmetic_expression_evalution

-The purpose of this program is to do arithmetic expressions
computation as well as computation priority management

-I make two versions for the evaluation of an arithmetical expression:
	- abstract syntax tree (AST)
	- recursive descends

-I used the following grammar:
	E -> T E'
	E'-> + T E' | - T E'
	T -> F T'
	T'-> * F T' | / F T' | % F T'\n
	F -> (E) | id\n

-to compute an arithmetical expression you must compile all the c files like this:
	compile-> gcc -Wall -Wextra -Werror * .c
	execute -> ./a.aout "1 + 1"

-for recursive descends I did not implement the modulo operator :)

-I helped myself with the following tutorials:
	https://ruslanspivak.com/lsbasi-part7/
	https://www.geeksforgeeks.org/evaluation-of-expression-tree/
