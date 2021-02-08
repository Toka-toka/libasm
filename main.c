#include "stdio.h"
#include "string.h"
#include "fcntl.h"
#include "unistd.h"
#include "errno.h"
#include "stdlib.h"

#define RED  "\x1B[31m"
#define GREEN  "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define WHITE  "\x1B[37m"

char *ft_strcpy(char *dest, char *str);
int ft_strcmp(char *str, char *new);
size_t ft_read(int fd, char *buff, size_t size);
int    ft_write(int fd, char *buff, size_t size);
char    *ft_strdup(const char *str);
int    ft_strlen(const char *str);
int    main ();

char *g_1 = YELLOW;
char *g_2 = YELLOW;
char *g_3 = YELLOW;
char *g_4 = YELLOW;
char *g_5 = YELLOW;
char *g_6 = YELLOW;

void    print_end()
{
    char *buff;
    int answer;
    int status;
    
    printf("%s", WHITE);
    printf("\nВведите 0 для выхода, любой другой символ для продолжения: ");
    if ((status = scanf("%d", &answer)) == -1 || answer != 0)
        main();
    exit(0);
}

void check_strdup()
{
    char *src[6];
    char *temp;
    int  i = 0;

    system("clear");
    printf("%s", YELLOW);
    printf("███████ ████████      ███████ ████████ ██████  ██████  ██    ██ ██████  \n");
    printf("██         ██         ██         ██    ██   ██ ██   ██ ██    ██ ██   ██ \n");
    printf("█████      ██         ███████    ██    ██████  ██   ██ ██    ██ ██████  \n");
    printf("██         ██              ██    ██    ██   ██ ██   ██ ██    ██ ██      \n");
    printf("██         ██ ███████ ███████    ██    ██   ██ ██████   ██████  ██      \n");
    printf("%s", WHITE);

    src[0] = "";
    src[1] = "1";
    src[2] = "123";
    src[3] = "ABC";
    src[4] = "12345";
    src[5] = "123456789olk,mjuiokjhgfedghytredwq234567890-=][';plop0-[';plo0p;lk,jhygtfre3w2sxcdfvgbhnjmkl;[']=[-p';";

    while (i < 6)
    {
        printf("%sTest_%d\n", YELLOW, i + 1);
        printf("%ssrc = \"%s\"\n", WHITE, src[i]);
        printf("%snew = \"%s\"\n", WHITE, (temp = ft_strdup(src[i])));
        if (strcmp(temp, src[i]) == 0)
            printf("%s|-OK-|\n\n", GREEN);
        else printf("%s|-KO-|\n\n", g_6 = RED);
        i++;
        free(temp);
    }
    if (strcmp(g_6, RED) != 0)
        g_6 = GREEN;
    print_end();
}

void check_read()
{
    int fd[4];
    char buff[9];

    fd[0] = open("test", O_RDONLY | O_CREAT);
    fd[1] = open("test1", O_RDWR | O_CREAT, 0666);
    fd[2] = 0;

    int i = 0;
    int  res_1 = 0;
    int  res_2 = 0;
    int  errno1;
    int  errno2;

    system("clear");
    printf("%s", YELLOW);
    printf("███████ ████████      ██████  ███████  █████  ██████  \n");
    printf("██         ██         ██   ██ ██      ██   ██ ██   ██ \n");
    printf("█████      ██         ██████  █████   ███████ ██   ██ \n");
    printf("██         ██         ██   ██ ██      ██   ██ ██   ██ \n");
    printf("██         ██ ███████ ██   ██ ███████ ██   ██ ██████  \n");
    printf("%s", WHITE);

    while (i < 3)
    {
        printf("\n%s      Test_%d (fd = %d)", YELLOW, i + 1, fd[i]);
        printf("%s", WHITE);
        errno = 0;
        printf("\n\n   ft_read  |   read");
        res_1 = ft_read(fd[i], buff, 9);
        errno1 = errno;
        errno = 0;
        res_2 = read(fd[i], buff, 9);
        errno2 = errno;
        printf("\nerrno = | %d | %d | \n  ret = | %d | %d |\n", errno1, errno2, res_1, res_2);
        i++;
        if (errno1 == errno2 && res_1 == res_2)
            printf("%s         |-OK-|\n", GREEN);
        else printf("%s        |-KO-|\n", g_5 = RED);
    }
    if (strcmp(g_5, RED))
        g_5 = GREEN;
    print_end();
}

void check_write()
{
    int fd[4];

    fd[0] = open("test", O_RDONLY | O_CREAT);
    fd[1] = open("test1", O_RDWR | O_CREAT, 0666);
    fd[2] = 0;
    fd[3] = -42;

    int i = 0;
    int  res_1 = 0;
    int  res_2 = 0;
    int  errno1;
    int  errno2;

    system("clear");
    printf("%s", YELLOW);
    printf("███████ ████████      ██     ██ ██████  ██ ████████ ███████ \n");
    printf("██         ██         ██     ██ ██   ██ ██    ██    ██      \n");
    printf("█████      ██         ██  █  ██ ██████  ██    ██    █████   \n");
    printf("██         ██         ██ ███ ██ ██   ██ ██    ██    ██      \n");
    printf("██         ██  █████   ███ ███  ██   ██ ██    ██    ███████ \n");
    printf("%s", WHITE);

    while (i < 4)
    {
        printf("\n%s      Test_%d (fd = %d)\n", YELLOW, i + 1, fd[i]);
        printf("%s", WHITE);
        errno = 0;
        printf("\n   ft_write |  write");
        res_1 = ft_write(fd[i], "ft_write\n", 9);
        errno1 = errno;
        errno = 0;
        res_2 = write(fd[i], "___write\n", 9);
        errno2 = errno;
        printf("\nerrno = | %d | %d | \n  ret = | %d | %d |\n", errno1, errno2, res_1, res_2);
        i++;
        if (errno1 == errno2 && res_1 == res_2)
            printf("%s         |-OK-|\n", GREEN);
        else printf("%s        |-KO-|\n", g_4 = RED);
    }
    if (strcmp(g_4, RED))
        g_4 = GREEN;
    print_end();
}

void check_strcmp()
{
    char *str1[9];
    char *str2[9];
    char *temp;
    int  i = 0;
    int  res_1;
    int  res_2;    

    system("clear");
    printf("%s", YELLOW);
    printf("███████ ████████      ███████ ████████ ██████   ██████ ███    ███ ██████  \n");
    printf("██         ██         ██         ██    ██   ██ ██      ████  ████ ██   ██ \n");
    printf("█████      ██         ███████    ██    ██████  ██      ██ ████ ██ ██████  \n");
    printf("██         ██              ██    ██    ██   ██ ██      ██  ██  ██ ██      \n");
    printf("██         ██ ███████ ███████    ██    ██   ██  ██████ ██      ██ ██      \n");
    printf("%s", WHITE);

    str1[0] = "";
    str2[0] = "";

    str1[1] = "";
    str2[1] = "123";   

    str1[2] = "123";
    str2[2] = "";        

    str1[3] = "123";
    str2[3] = "123";    

    str1[3] = "123";
    str2[3] = "12345";

    str1[4] = "12345";
    str2[4] = "123";

    str1[5] = "ABC";
    str2[5] = "ABC";    

    str1[6] = "ABC";
    str2[6] = "ABCA";    

    str1[7] = "ABC";
    str2[7] = "ABB";

    str1[8] = "123456789olk,mjuiokjhgfedghytredwq234567890-=][';plop0-[';plo0p;lk,jhygtfre3w2sxcdfvgbhnjmkl;[']=[-p';";
    str2[8] = "123456789olk,mjuiokjhgfedghytredwq234567890-=][';plop0-[';plo0p;lk,jhygtfre3w2sxcdfvgbhnjmkl;[']=[-p';";

    while (i < 9)
    {
        printf("%sTest_%d\n", YELLOW, i + 1);
        printf("%sstr1 = \"%s\"\n", WHITE, str1[i]);
        printf("%sstr2 = \"%s\"\n", WHITE, str2[i]);
        printf("ft_strcmp = %d | ", res_1 = ft_strcmp(str1[i], str2[i]));
        printf("%d = strcmp \n", res_2 = strcmp(str1[i], str2[i]));        
        if (res_1 == res_2)
            printf("%s|-OK-|\n\n", GREEN);
        else printf("%s|-KO-|\n\n", g_3 = RED);
        i++;
    }
    if (strcmp(g_2, RED) != 0)
        g_3 = GREEN;
    print_end();
}


void check_strcpy()
{
    char dest[100];
    char *src[6];
    char *temp;
    int  i = 0;

    system("clear");
    printf("%s", YELLOW);
    printf("███████ ████████     ███████ ████████ ██████   ██████ ██████ ██    ██\n");
    printf("██         ██        ██         ██    ██   ██ ██      ██   ██ ██  ██  \n");
    printf("█████      ██        ███████    ██    ██████  ██      ██████   ████   \n");
    printf("██         ██             ██    ██    ██   ██ ██      ██        ██    \n");
    printf("██         ██   ████ ███████    ██    ██   ██  ██████ ██        ██    \n");
    printf("%s", WHITE);

    src[0] = "";
    src[1] = "1";
    src[2] = "123";
    src[3] = "ABC";
    src[4] = "12345";
    src[5] = "123456789olk,mjuiokjhgfedghytredwq234567890-=][';plop0-[';plo0p;lk,jhygtfre3w2sxcdfvgbhnjmkl;[']=[-p';";

    while (i < 6)
    {
        printf("%sTest_%d\n", YELLOW, i + 1);
        printf("%ssrc = \"%s\"\n", WHITE, src[i]);
        printf("%sdest = \"%s\"\n", WHITE, (temp = ft_strcpy(dest, src[i])));
        if (strcmp(dest, src[i]) == 0)
            printf("%s|-OK-|\n\n", GREEN);
        else printf("%s|-KO-|\n\n", g_2 = RED);
        i++;
    }
    if (strcmp(g_2, RED) != 0)
        g_2 = GREEN;
    print_end();
}

void check_strlen()
{
    char *str[6];
    int  res_1;
    int  res_2;
    int  i = 0;
    
    system("clear");
    printf("%s", YELLOW);
    printf("███████ ████████      ███████ ████████ ██████  ██      ███████ ███    ██ \n");
    printf("██         ██         ██         ██    ██   ██ ██      ██      ████   ██ \n");
    printf("█████      ██         ███████    ██    ██████  ██      █████   ██ ██  ██ \n");
    printf("██         ██              ██    ██    ██   ██ ██      ██      ██  ██ ██ \n");
    printf("██         ██ ███████ ███████    ██    ██   ██ ███████ ███████ ██   ████ \n");
    printf("%s", WHITE);

    str[0] = "";
    str[1] = "1";
    str[2] = "123";
    str[3] = "ABC";
    str[4] = "12345";
    str[5] = "123456789olk,mjuiokjhgfedghytredwq234567890-=][';plop0-[';plo0p;lk,jhygtfre3w2sxcdfvgbhnjmkl;[']=[-p';";

    printf("\n");
    while (i < 6)
    {
        printf("%sTest_%d\n", YELLOW, i + 1);
        printf("%sstr = \"%s\"\n", WHITE, str[i]);
        printf("ft_strlen = %d | ", res_1 = ft_strlen(str[i]));
        printf("%d = strlen \n", res_2 = strlen(str[i]));
        if (res_1 == res_2)
            printf("%s|-OK-|\n\n", GREEN);
        else printf("%s|-KO-|\n\n", g_1 = RED);
        i++;
    }
    if (strcmp(g_1, RED))
        g_1 = GREEN;
    print_end();
}

int main ()
{
    int answer;

    system("clear");
    printf("%s", YELLOW);
    printf("██      ██ ██████   █████  ███████ ███    ███     ████████ ███████ ███████ ████████ \n");
    printf("██      ██ ██   ██ ██   ██ ██      ████  ████        ██    ██      ██         ██    \n");
    printf("██      ██ ██████  ███████ ███████ ██ ████ ██        ██    █████   ███████    ██    \n");
    printf("██      ██ ██   ██ ██   ██      ██ ██  ██  ██        ██    ██           ██    ██    \n");
    printf("███████ ██ ██████  ██   ██ ███████ ██      ██        ██    ███████ ███████    ██    \n");
    printf("%s", WHITE);
    while (1)
    {
        printf("\nДля проверки функций данной библиотеки введи номер функции\n\n");
        printf("| ft_strlen | - | %s1%s |\n\n", g_1, WHITE);
        printf("| ft_strcpy | - | %s2%s |\n\n", g_2, WHITE);
        printf("| ft_strcmp | - | %s3%s |\n\n", g_3, WHITE);
        printf("|  ft_write | - | %s4%s |\n\n", g_4, WHITE);
        printf("|  ft_read  | - | %s5%s |\n\n", g_5, WHITE);
        printf("| ft_strdup | - | %s6%s |\n\n", g_6, WHITE);
        printf("|  Закрыть  | - | %s0%s |\n\n", YELLOW, WHITE);
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
            check_write();
        else if (answer == 5)
            check_read();
        else if (answer == 6)
            check_strdup();
        else
            printf("Введи номер еще раз\n");
    }
}