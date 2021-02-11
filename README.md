# LIBASM

Один из учебных проектов школы 21, направленный на знакомство студентов с языком ассемблера.

Цель проекта - реализация перечня функций на языке ассемблера с последующим созданием библиотеки.

Требование к проекту:
  - использование синтаксиса Intel;
  - соблюдение "соглашения о вызовах";
  - библиотека должна называться libasm.a;
  - сборка библитеки должна осуществляться с помощью Makefile из файлов с расширением ’.s’;
  - при обращении к системным вывовам необходимо взаимодействие с перемернной "errno" в случае ошибок;
  - проект должен содержать файл main.c, при компиляции с которым можно протестировать функциональность библиотеки.
  
# Прототипы функций:
    int   ft_strlen(const char *str);
    char *ft_strcpy(char *dest, char *str);
    int   ft_strcmp(char *str, char *new);
    int   ft_write(int fd, char *buff, size_t size);
    int   ft_read(int fd, char *buff, size_t size);
    char *ft_strdup(const char *str);
