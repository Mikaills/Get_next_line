# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif 

char	*get_next_line(int fd);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *temp, char *buffer);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(char *str);

#endif