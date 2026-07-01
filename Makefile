clean:
	@rm -rf *.out

%:
	@gcc -std=c23 -Wall -Werror -Wpedantic solutions/$@.c && ./a.out && rm a.out