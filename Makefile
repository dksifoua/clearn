clean:
	@rm -rf *.out

%:
	@gcc -Wall -Werror -Wpedantic solutions/$@.c && ./a.out && rm a.out