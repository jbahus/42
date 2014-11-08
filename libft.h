#ifndef LIBFT_H
 #define LIBFT_H

 #include<unistd.h>
 #include<stdlib.h>
 #include<string.h>

 void	ft_bzero(void *s, size_t n);									//ok
 void	*ft_memset(void *s, int c, size_t n);							//ok
 void	*ft_memcpy(void *dst, const void *src, size_t n); 				//ok
 void	*ft_memccpy(void *dst, const void *src, int c, size_t n); 		//ok
 void	*ft_memmove(void *dst, const void *src, size_t len); 			//ok
 void	*ft_memchr(const void *s, int c, size_t n); 					//ok
 int	ft_memcmp(const void *s1, const void *s2, size_t n); 			//ok
 char	*ft_strdup(const char *s1);										//ok
 char	*ft_strcpy(char *src, const char *dst);							//ok
 char	*ft_strncpy(char *src, const char *dest, size_t n);				//ok
 char	*ft_strcat(char *s1, const char *s2);							//ok
 char	*ft_strncat(char *s1, const char *s2, size_t n);				//ok
 char	*ft_strchr(const char *s, int c);								//ok
 char	*ft_strrchr(const char *s, int c);								//ok
 char	*ft_strstr(const char *s1, const char *s2); 					//ok
 char	*ft_strnstr(const char *s1, const char *s2, size_t n); 			//ok CONNARD, cordialement.
 size_t	ft_strlcat(char *dst, const char *src, size_t size);			//ok (Enc*ler de Fils de **** de conn*rd de M*rd* !!!)		
 size_t	ft_strlen(const char *s);										//ok
 int	ft_strcmp(const char *s1, const char *s2);						//ok
 int	ft_strncmp(const char *s1, const char *s2, int n);				//ok
 int	ft_atoi(const char *str);										//ok
 int	ft_isalpha(int c);												//ok
 int	ft_isdigit(int c);												//ok
 int	ft_isalnum(int c);												//ok
 int	ft_isascii(int c);												//ok
 int	ft_isprint(int c);												//ok
 int	ft_toupper(int c);												//ok
 int	ft_tolower(int c);												//ok


 //PART 2

 void	*ft_memalloc(size_t size);										//ok
 //void	ft_memdel(void **ap);
 char	*ft_strnew(size_t size);
 //void	ft_strdel(char **as);
 void	ft_strclr(char *s);
 void	ft_striter(char *s, void (*f)(char *));
 void	ft_striteri(char *s, void (*f)(unsigned int,char *));
 char	*ft_strmap(char const *s, char (*f)(char));
 char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
 int	ft_strequ(char const *s1, char const *s2);
 int	ft_strnequ(char const *s1, char const *s2, size_t n);
 char	*ft_strsub(char const *s, unsigned int start, size_t len);		//Not sure.
 char	*ft_strjoin(char const *s1, char const*s2);						//ok
 //char	*ft_strtrim(char const *s);
 //char	**ft_strsplit(char const *s, char c);
 //char	*ft_itoa(int n);
 void	ft_putchar(char c);												//ok
 void	ft_putstr(char const *s);
 void	ft_putendl(char const *s);
 void	ft_putnbr(int n);												//ok
 void	ft_putchar_fd(char c, int fd);
 void	ft_putstr_fd(char const *s, int fd);
 void	ft_putendl_fd(char const *s, int fd);
 void	ft_putnbr_fd(int n, int fd);

#endif
