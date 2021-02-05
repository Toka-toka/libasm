# include "stdio.h"
# include "string.h"
#include "fcntl.h"
#include "unistd.h"
#include "errno.h"
// nasm -f macho64 ft_strcmp.s ; gcc main.c *.o ; ./a.out

char *ft_strcpy(char *dest, char *str);
int ft_strcmp(char *str, char *new);
size_t ft_read(int fd, char *buff, size_t size);
int    ft_write(int fd, char *buff, size_t size);
char    *ft_strdup(const char *str);
int    ft_strlen(const char *str);
//int ft_summ(int i, int j);
//int ft_strlen(char *str);

int main(void)
{
    int i = 4;
    int j = 4;
    
//    printf("i + j = %d\n", ft_summ(i, j));
//    printf("len = %d\n", ft_strlen("1"));
    
    char *str = "123";
    char dest[20];
    char *new;
    
    new = ft_strcpy(dest, str);
    printf("str = %s\n", str);
    printf("dest = %s\n", dest);
    printf("dest = %s\n", dest);

    str = "1";
    new = "1";

    printf("i = %d\n", ft_strcmp(str, new));
    printf("i = %d\n", strcmp(str, new));

    str = "";
    new = "123";

    printf("i = %d\n", ft_strcmp(str, new));
    printf("i = %d\n", strcmp(str, new));

    str = "123";
    new = "";

    printf("i = %d\n", ft_strcmp(str, new));
    printf("i = %d\n", strcmp(str, new));   

    str = "1234567";
    new = "1234567";

    printf("i = %d\n", ft_strcmp(str, new));
    printf("i = %d\n", strcmp(str, new));

    str = "12";
    new = "123";

    printf("i = %d\n", ft_strcmp(str, new));
    printf("i = %d\n", strcmp(str, new));    

    str = "123";
    new = "12";

    printf("i = %d\n", ft_strcmp(str, new));
    printf("i = %d\n", strcmp(str, new));    

    int fd;
    char buff[5];
    int  status;
    fd = open("test", O_RDWR | O_APPEND);
    status = ft_read(42, buff, 5);
    printf("\n%d %d buff = %s\n %d", fd, status, buff, errno);
    status = read(42, buff, 5);
    printf("\n%d %d buff = %s\n %d", fd, status, buff, errno);

    errno = 0;
    status = ft_write(fd, "Test\n", 5);
    printf("\n%d %d %d\n", fd, errno, status);

    errno = 0;
    status = write(fd, "Test\n", 5);
    printf("\n%d %d %d\n", fd, errno, status);

    char *newstr;

    newstr = ft_strdup("");
//    newstr[0] = '1';
//    newstr[1] = '2';
//    newstr[2] = '3';
//   newstr[3] = '\0';
//    printf("Helllo! %s\n", newstr);
//    printf("status = %d\n", status);
 //   newstr = strdup(NULL);

    printf("%d\n", errno);
    printf("Helllo! %s\n", newstr);

    return(0);
}
