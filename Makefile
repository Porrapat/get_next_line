norminette:
	norminette 

normh:
	norminette get_next_line.h
	norminette get_next_line.c

run:
	gcc -g -Wall -Wextra -Werror -D BUFFER_SIZE=2 get_next_line.c get_next_line_utils.c && ./a.out

runbuffer:
	gcc -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c && ./a.out && rm -rf a.out

runstrict:
	gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c && ./a.out && rm -rf a.out

mem:
	gcc -g -D BUFFER_SIZE=3 get_next_line.c get_next_line_utils.c && valgrind --leak-check=full -q ./a.out

mem3:
	gcc -g -Wall -Wextra -Werror -D BUFFER_SIZE=2 get_next_line.c get_next_line_utils.c && valgrind --leak-check=full -q ./a.out

mem2:
	gcc get_next_line.c get_next_line_utils.c && valgrind --leak-check=full -q ./a.out

memtotal:
	gcc -g -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c && valgrind --leak-check=full -q ./a.out
	gcc -g -D BUFFER_SIZE=2 get_next_line.c get_next_line_utils.c && valgrind --leak-check=full -q ./a.out
	gcc -g -D BUFFER_SIZE=3 get_next_line.c get_next_line_utils.c && valgrind --leak-check=full -q ./a.out
	gcc -g -D BUFFER_SIZE=4 get_next_line.c get_next_line_utils.c && valgrind --leak-check=full -q ./a.out
	gcc -g -D BUFFER_SIZE=5 get_next_line.c get_next_line_utils.c && valgrind --leak-check=full -q ./a.out
	gcc -g -D BUFFER_SIZE=6 get_next_line.c get_next_line_utils.c && valgrind --leak-check=full -q ./a.out


fclean:
	rm -rf a.out