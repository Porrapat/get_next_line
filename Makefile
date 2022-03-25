norminette:
	norminette 

normh:
	norminette get_next_line.h
	norminette get_next_line.c

run:
	gcc get_next_line.c get_next_line_utils.c && ./a.out && rm -rf a.out

runbuffer:
	gcc -D BUFFER_SIZE=6 get_next_line.c get_next_line_utils.c && ./a.out && rm -rf a.out

runstrict:
	gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c && ./a.out && rm -rf a.out

mem:
	gcc -D BUFFER_SIZE=5 get_next_line.c get_next_line_utils.c && valgrind --leak-check=yes -q ./a.out

mem2:
	gcc get_next_line.c get_next_line_utils.c && valgrind --leak-check=yes -q ./a.out

fclean:
	rm -rf a.out