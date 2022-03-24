norminette:
	norminette 

normh:
	norminette get_next_line.h
	norminette get_next_line.c

run:
	gcc get_next_line.c && ./a.out && rm -rf a.out

runstrict:
	gcc -Wall -Wextra -Werror get_next_line.c && ./a.out && rm -rf a.out