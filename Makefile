clean:
	@rm -rf *.out

%:
	@cc solutions/$@.c && ./a.out && rm a.out