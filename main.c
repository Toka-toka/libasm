# include "stdio.h"
# include "string.h"
#include "fcntl.h"
#include "unistd.h"
#include "errno.h"
# include "stdlib.h"
// nasm -f macho64 ft_strcmp.s ; gcc main.c *.o ; ./a.out

char *ft_strcpy(char *dest, char *str);
int ft_strcmp(char *str, char *new);
size_t ft_read(int fd, char *buff, size_t size);
int    ft_write(int fd, char *buff, size_t size);
char    *ft_strdup(const char *str);
int    ft_strlen(const char *str);
//int ft_summ(int i, int j);
//int ft_strlen(char *str);

void check_strcmp()
{
    char str1[100];
    char str2[100];
    int  res_1;
    int  res_2;

    res_1 = 0;
    while (4 > res_1++)
        printf("| --- | --- | --- | --- | --- |");
    
    printf("\n\nТестирование ft_strcmp\n");
    printf("Для передачи пустой строки: ctrl + D\n");
    printf("Возврата в предыдущее меню: exit\n\n");
    res_1 = 0;
    while (4 > res_1++) 
        printf("| --- | --- | --- | --- | --- |");
    while (1)
    {
        printf("\n\n");
        printf("Введи строку, которая будет передана ft_strlen: ");
        if(scanf("%s", str1) == -1)
            str1[0] = '\0';
        if(scanf("%s", str2) == -1)
            str2[0] = '\0';        
        if (str1[0] == 'e' && str1[1] == 'x' && str1[2] == 'i' && str1[3] == 't' && str1[4] == '\0')
            break;
        printf("\nРезультат работы ft_strcmp = | %d | ", (res_1 = strcmp(str1, str2)));
        printf(" | %d | = Результат работы strcmp = \n", (res_2 = strcmp(str1, str2)));
        if (res_1 == res_2)
            printf("\n\n!!!       Тест пройден      !!!\n");
        if (res_1 != res_2)
            printf("\n\n!!!       Тест НЕ пройден   !!!!\n");
    }           
}

void check_strcpy()
{
    char srt[100];
    int  res_1;
    int  res_2;

    res_1 = 0;
    while (4 > res_1++)
        printf("| --- | --- | --- | --- | --- |");
    
    printf("\n\nТестирование ft_strlen\n");
    printf("Для передачи пустой строки: ctrl + D\n");
    printf("Возврата в предыдущее меню: exit\n\n");
    res_1 = 0;
    while (4 > res_1++) 
        printf("| --- | --- | --- | --- | --- |");
    while (1)
    {
        printf("\n\n");
        printf("Введи строку, которая будет передана ft_strlen: ");
        if(scanf("%s", srt) == -1)
            srt[0] = '\0';
        if (srt[0] == 'e' && srt[1] == 'x' && srt[2] == 'i' && srt[3] == 't' && srt[4] == '\0')
            break;
        printf("\nРезультат работы ft_strlen = | %d | ", (res_1 = strlen(srt)));
        printf(" | %d | = Результат работы strlen = \n", (res_2 = strlen(srt)));
        if (res_1 == res_2)
            printf("\n\n!!!       Тест пройден      !!!\n");
        if (res_1 != res_2)
            printf("\n\n!!!       Тест НЕ пройден   !!!!\n");
    }       
}

void check_strlen()
{
    char srt[100];
    int  res_1;
    int  res_2;

    res_1 = 0;
    while (4 > res_1++)
        printf("| --- | --- | --- | --- | --- |");
    
    printf("\n\nТестирование ft_strlen\n");
    printf("Для передачи пустой строки: ctrl + D\n");
    printf("Возврата в предыдущее меню: exit\n\n");
    res_1 = 0;
    while (4 > res_1++)
        printf("| --- | --- | --- | --- | --- |");
    while (1)
    {
        printf("\n\n");
        printf("Введи строку, которая будет передана ft_strlen: ");
        if(scanf("%s", srt) == -1)
            srt[0] = '\0';
        if (srt[0] == 'e' && srt[1] == 'x' && srt[2] == 'i' && srt[3] == 't' && srt[4] == '\0')
            break;
        printf("\nРезультат работы ft_strlen = | %d | ", (res_1 = strlen(srt)));
        printf(" | %d | = Результат работы strlen = \n", (res_2 = strlen(srt)));
        if (res_1 == res_2)
            printf("\n\n!!!       Тест пройден      !!!\n");
        if (res_1 != res_2)
            printf("\n\n!!!       Тест НЕ пройден   !!!!\n");
    }
}

int main ()
{
    int answer;

    printf("Привет!\n\n");
    while (1)
    {
        printf("Для проверки функций данной библиотеки введи номер фунции\n\n");
        printf("| ft_strlen | - | 1 |\n\n");
        printf("| ft_strcpy | - | 2 |\n\n");
        printf("| ft_strcmp | - | 3 |\n\n");
        printf("|  ft_read  | - | 4 |\n\n");
        printf("|  ft_write | - | 5 |\n\n");
        printf("| ft_strdup | - | 6 |\n\n");
        printf("|  Закрыть  | - | 0 |\n\n");
        printf("Запустить проверку функции №: ");
        scanf("%d", &answer);
        if (answer == 0)
            exit(0);
        else if (answer == 1)
            check_strlen();
        else if (answer == 2)
            check_strcpy();
        else if (answer == 3)
            check_strcmp();
        else if (answer == 4)
            printf("Check ft_read\n");
        else if (answer == 5)
            printf("Check ft_write\n");
        else if (answer == 6)
            printf("Check ft_strdup\n");
        else
            printf("Введи номер еще раз\n");
    }
}

/*

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
}*/
