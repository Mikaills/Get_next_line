SRCS = get_next_line.c \
	   get_next_line_utils.c

comp:
	@$(CC) $(CFLAGS) main.c $(SRCS)
run: comp
	@./a.out