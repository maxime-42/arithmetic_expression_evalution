# arithmetic_expression_evalution<br/>

-The purpose of this program is to do arithmetic expressions<br/>
computation as well as computation priority management<br/>
<br/>
-I make two versions for the evaluation of an arithmetical expression:<br/>
	- abstract syntax tree (AST)<br/>
	- recursive descends<br/>
<br/>
-I used the following grammar:<br/>
	E -> T E'<br/>
	E'-> + T E' | - T E' | ε <br/>
	T -> F T'<br/>
	T'-> * F T' |  / F T' | % F T' | ε <br/>
	F -> (E) | id<br/>
<br/>
-to compute an arithmetical expression you must compile all the c files like this:<br/>
	compile-> gcc -Wall -Wextra -Werror * .c<br/>
	execute -> ./a.aout "1 + 1"<br/>
<br/>
-for recursive descends I did not implement the modulo operator :)<br/>
<br/>
-I helped myself with the following tutorials:<br/>
	https://www.strchr.com/expression_evaluator<br/>
	https://ruslanspivak.com/lsbasi-part7/<br/>
	https://www.geeksforgeeks.org/evaluation-of-expression-tree/<br/>
