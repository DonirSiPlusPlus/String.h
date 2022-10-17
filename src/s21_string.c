#include "s21_string.h"
// поиск длинны строки
s21_size_t s21_strlen(const char *str) {  //  длинна строки
    s21_size_t size = 0;
    while (str[size] != '\0') size++;
    return size;
}
// cравнивает первые n байтов str1 и str2.
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    if ((int)n == 0) return 0;
    while (--n && *(char *)str1 == *(char *)str2) {
        str1 = (char *)str1 + 1;
        str2 = (char *)str2 + 1;
    }
    return (*(char *)str1) - (*(char *)str2);
}
//  равнивает строку, на которую указывает str1, со строкой, на которую
//  указывает
// str2
int s21_strcmp(const char *str1, const char *str2) {
    s21_size_t size = 0;
    int result = 0;
    while (str1[size] != '\0' || str2[size] != '\0') {
        if (str1[size] != str2[size]) {
            result = str1[size] - str2[size];
            break;
        }
        size++;
    }
    return result;
}
// сравнивает первые n символов
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    const char *end = str1 + n;
    int result = 0;
    while (result == 0 && str1 != end && (*str1 || *str2)) {
        result = *(str1++) - *(str2++);
    }
    // for (; result == 0 && str1 != end && (*str1 || *str2);
    //      result = *(str1++) - *(str2++))
    //     ;
    return result;
}  // верхний регистр
void *s21_to_upper(const char *str1) {
    s21_size_t size = 0;
    char *str = malloc(sizeof(s21_strlen(str1)));
    while (str1[size] != '\0') {
        if (str1[size] >= 'a' && str1[size] <= 'z')
            str[size] = str1[size] - 32;
        else
            str[size] = str1[size];
        size++;
    }
    str[size] = '\0';
    return (void *)str;
}  // нижний регистр
void *s21_to_lower(const char *str1) {
    s21_size_t size = 0;
    char *str = malloc(sizeof(s21_strlen(str1) + 1));
    while (str1[size] != '\0') {
        if (str1[size] >= 'A' && str1[size] <= 'Z')
            str[size] = str1[size] + 32;
        else
            str[size] = str1[size];
        size++;
    }
    str[size] = '\0';
    return (void *)str;
}  // вставляет строку в строку в указанном индексе
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char *res = malloc(s21_strlen(src) + s21_strlen(str) + 1);
    if (start_index <= s21_strlen(src) && start_index >= 0) {
        char *src_copy, *str_copy;
        src_copy = malloc(s21_strlen(src));
        s21_strcpy(src_copy, src);
        str_copy = malloc(s21_strlen(str));
        s21_strcpy(str_copy, str);
        for (s21_size_t i = 0, j = 0; i < s21_strlen(src) + s21_strlen(str) + 1;
             i++, j++) {
            if (i == start_index) {
                s21_strcat(res, str);
                i += s21_strlen(str);
                res[i] = src_copy[j];
            } else {
                res[i] = src_copy[j];
            }
        }
        res[s21_strlen(src) + s21_strlen(str) + 1] = '\0';
    } else {
        res = '\0';
    }
    return (void *)res;
}
// возвращает новую строку,
// в которой удаляются все начальные и конечные вхождения набора заданных
// символов(trim_chars)
// из данной строки(src).
// void *s21_trim(const char *str, const char *char_trim) {  //  (\n\0\t )
// char *retval = "";
// int start = 1;
// int end = 1;
// s21_size_t end_counter = 0;
// char trimmers[128];
// if (char_trim == s21_NULL || char_trim == "\0") {
// trimmers[0] = ' ';
// trimmers[1] = '\n';
// trimmers[2] = '\t';
// trimmers[3] = '\0';
// } else {
// int i = 0;
// while (char_trim[i] != '\0') {
// trimmers[i] = char_trim[i];
// i++;
// }
// }
// s21_size_t trim_lenght = s21_strlen(trimmers);
// s21_size_t start_counter = 0;
// if (str == s21_NULL) {
// start = 0;
// end = 0;
// end_counter = -1;
// } else {
// end_counter = s21_strlen(str) - 1;
// }
// while (start == 1 || end == 1) {
// int finish = 0;
// start = 0;
// end = 0;
// for (int i = 0; i < trim_lenght; i++) {
// if (str[start_counter] == trimmers[i] && start == 0) {
// start_counter++;
// start = 1;
// }
// if (str[end_counter] == trimmers[i] && end == 0) {
// end_counter--;
// end = 1;
// }
// }
// }
// if (start_counter >= end_counter || str == s21_NULL) {
// retval = s21_NULL;
// } else {
// for (int i = start_counter, j = 1; i <= end_counter + 1; i++, j++) {
// retval = (char *)realloc(retval, sizeof(char) * j);
// retval[j - 1] = str[i];
// }
// }
// return (void *)retval;
// }
/*
Функция s21_strcspn определяет наибольшую длину начального участка строки
str1, не содержащего ни один из символов строки str2.
*/
s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t numb = 0, flag = 0;
    for (; str1[numb] != '\0'; numb++) {
        for (int i = 0; str2[i] != '\0'; i++) {
            if (str1[numb] == str2[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) break;
    }
    return numb;
}
/*
Функция s21_memchr ищет вхождение в массив (область памяти) символа c, сравнивая
каждый байт массива (области памяти) определенный как unsigned char с кодом
искомого символа. Если искомый символ найден, то возвращается адрес найденного
символа и сравнение завершается. Если, после проверки n байтов, искомый символ
не найден, то сравнение прекращается и функция возвращает s21_NULL.
*/
void *s21_memchr(const void *str, int c, s21_size_t n) {
    const char *symb = s21_NULL, *ptr = str;
    for (s21_size_t i = 0; i < n; i++, ptr++) {
        if (*ptr == c) {
            symb = ptr;
            break;
        }
    }
    return (void *)symb;
}
/*
Функция s21_strchr ищет первое вхождения символа c (ASCII), в строке str
*/
char *s21_strchr(const char *str, int c) {
    const char *symb = "";
    for (symb = str; *symb != c; symb++) {
        if (*symb == '\0') {
            symb = s21_NULL;
            break;
        }
    }
    return (char *)symb;
}
/*
Функция s21_strpbrk ищет первое вхождение в строке str1,
одного из символов, входящих в строку str2.
*/
char *s21_strpbrk(const char *str1, const char *str2) {
    const char *symb = "";
    for (symb = str1; *symb != '\0'; symb++) {
        const char *i = "";
        i = str2;
        while (*i != *symb && *i != '\0') {
            i++;
        }
        // for (i = str2; *i != *symb && *i != '\0'; i++) {
        // ;
        // }
        if (*i == *symb) break;
    }
    if (*symb == '\0') symb = s21_NULL;
    return (char *)symb;
}
/*
Функция s21_strchr ищет последнее вхождения символа,
в строке str.
*/
char *s21_strrchr(const char *str, int c) {
    char *rtnval = 0;
    do {
        if (*str == c) {
            rtnval = (char *)str;
        }
    } while (*str++);
    return (char *)rtnval;
}
/*
Функция s21_strstr ищет первое вхождение строки (за исключением признак конца
строки) needle, в строку haystack. Если строка needle имеет нулевую длину, то
функция вернет указатель на начало строки haystack.
*/
char *s21_strstr(const char *haystack, const char *needle) {
    char *temp = s21_NULL;
    if (*needle == '\0') {
        temp = (char *)haystack;
    } else {
        temp = s21_NULL;
        do {
            const char *p = "";
            const char *q = "";
            for (p = haystack, q = needle; *q != '\0' && *p == *q; p++, q++) {
            }
            if (*q == '\0') {
                temp = (char *)haystack;
            }
        } while (*(haystack++) != '\0');
    }
    return (char *)temp;
}
char *s21_strtok(
    char *str,
    const char *delimiters) {  //  Заменить все на наши фунеции и убрать коммы
    char *token = "";
    static char *olds = "";
    if (str == s21_NULL) str = olds;

    /* Scan leading delimiters.  */
    str += s21_strspn(str, delimiters);
    if (*str == '\0') {
        olds = str;
        token = s21_NULL;
    } else {
        /* Find the end of the token.  */
        token = str;
        str = s21_strpbrk(token, delimiters);
        if (str == s21_NULL) { /* This token finishes the string.  */
            olds = s21_memchr(token, '\0', 1024);
        } else {
            /* Terminate the token and make OLDS point past it.  */
            *str = '\0';
            olds = str + 1;
        }
    }
    return (char *)token;
}

char *s21_strcat(
    char *dest,
    const char *src) {  //  Заменить все на наши фунеции и убрать коммы
    s21_strcpy(dest + s21_strlen(dest), src);
    return dest;
}

char *s21_strncat(
    char *dest, const char *src,
    s21_size_t n) {  //  Заменить все на наши фунеции и убрать коммы
    char *str = dest;
    /* Find the end of str1.  */
    dest += s21_strlen(dest);
    s21_size_t str_size = s21_strlen(src);
    if (str_size > n) str_size = n;
    dest[str_size] = '\0';
    s21_memcpy(dest, src, str_size);
    return str;
}

char *s21_strerror(int errnum) {
    char *errlist[] = {ERRSTR};
    static char retval[80];
    if (errnum >= ERRMIN && errnum < ERRMAX) {
        s21_strcpy(retval, errlist[errnum]);
    } else {
        char num[10] = {0};
        if (errnum < 0) {
            num[0] = '-';
            errnum *= -1;
        }
        s21_strcpy(retval, "Unknown error: ");
        int i = 0;
        for (i = 8; errnum != 0; errnum /= 10, i--) num[i] = errnum % 10 + '0';
        if (num[0] == '-') retval[15] = '-';
        s21_strcat(retval, num + i + 1);
    }
    return (char *)retval;
}
/*
Возвращает целочисленное значение, задающее длину подстроки в str1,
которая состоит исключительно из символов в str2.
Если str1 начинается с символа, не из str2, функция возвращает 0.
str1 - Строка для поиска, завершающаяся символом NULL.
str2 - Набор символов, завершающийся символом NULL.
*/
s21_size_t s21_strspn(const char *str1, const char *str2) {
    const char *p = "";
    const char *a = "";
    int count = 0;
    for (p = str1; *p != '\0'; ++p) {
        for (a = str2; *a != '\0'; ++a) {
            if (*p == *a) {
                count++;
                break;
            }
        }
        if (*a == '\0') {
            break;
        }
    }
    return count;
}
/*
s21_memcpy копирует count байт из src в dest;
При перекрытии исходного и конечного буферов
поведение s21_memcpy не определено.
Используйте s21_memmove для обработки перекрывающихся областей.
dest - Новый буфер.
src - Буфер, из которого происходит копирование.
n - Число копируемых символов.
*/
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    char *csrc = (char *)src;
    char *cdest = (char *)dest;
    for (int i = 0; i < n; i++) {
        cdest[i] = csrc[i];
    }
    return (void *)cdest;
}

/*
Копирует count байтов из src в dest.
Если отдельные области конечного объекта перекрывают области
исходного объекта,
то функция гарантируют, что байты исходного объекта в
перекрывающейся области будут скопированы,
прежде чем будут перезаписаны.
Убедитесь в том, что буфер назначения равен или превосходит
по размеру исходный буфер.
dest - Конечный объект.
src - Исходный объект.
n - Число копируемых байтов.
*/
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    char *csrc = (char *)src;
    char *cdest = (char *)dest;
    char *temp = s21_NULL;
    temp = (char *)malloc(sizeof(char) * n);
    for (int i = 0; i < n; i++) {
        temp[i] = csrc[i];
    }
    for (int i = 0; i < n; i++) {
        cdest[i] = temp[i];
    }
    free(temp);
    temp = s21_NULL;
    return (void *)cdest;
}

/*
Задает для первых n символов str значение символа c.
str - Указатель на место назначения.
c - Задаваемый символ.
n - Число символов.
*/
void *s21_memset(void *str, int c, s21_size_t n) {
    if (str != s21_NULL) {
        char *temp = (char *)str;
        for (int i = 0; i < n; i++) {
            *temp++ = c;
        }
    }
    return str;
}
/*
Функция копирует src, включая завершающий символ null,
в расположение, указанное параметром dest.
При перекрытии исходного и конечного буферов поведение
s21_strcpy не определено.
dest - Конечная строка.
src - Исходная строка, завершающаяся символом NULL.
*/
char *s21_strcpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
/*
Функция s21_strncpy копирует первые несколько символов,
количество которых определяет параметр n,
из строки src в строку dest и возвращает строку dest.
Если значение параметра n меньше или равно длине строки src,
символ null не добавляется к скопированной строке автоматически.
Если значение n больше, чем длина строки src,
строка назначения заполняется символами null, пока ее длина
не достигнет длины строки n.
При перекрытии исходного и конечного буферов поведение
s21_strncpy не определено.
dest - Конечная строка.
src - Исходная строка.
n - Число копируемых символов.
*/
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    s21_size_t i = 0;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for (; i < n; i++) {
        dest[i] = '\0';
    }
    return dest;
}
int s21_sprintf(char *str, const char *format, ...) {
    int bytes = 0;
    if (format == s21_NULL || str == s21_NULL) {
        bytes = -1;
    } else {
        *str = '\0';
        va_list(args);
        va_start(args, format);
        for (; *format != '\0'; format++) {
            if (*format == '%' && *(format + 1) == '\0') break;
            if (*format == '%') {
                s21_size_t lengthofspec =
                    s21_strcspn(format + 1, "%%cdifsu") + 1;
                char *flags = s21_strchr("-+ ", *(format + 1)), *first = str,
                     *arg_string = "";
                char *lastspec =
                         s21_strchr("%%cdifsu", *(format + lengthofspec)),
                     *accur = s21_memchr(format, '.', lengthofspec),
                     *modifier = s21_strchr("hl", *(format + lengthofspec - 1));
                s21_size_t width = s21_atoi(format + 1), acc = 0,
                           numb_of_flags = 0, minus_fl = 0;
                char plus_or_space = '\0';
                if (accur != s21_NULL) acc = s21_atoi(accur + 1);
                if (flags != s21_NULL) {
                    numb_of_flags = s21_strspn(format + 1, "-+ ");
                    width = s21_atoi(format + 1 + numb_of_flags);
                    const char *i = format + 1;
                    for (s21_size_t j = 0; j < numb_of_flags; j++, i++) {
                        if (*i == '-') {
                            minus_fl = 1;
                        } else {
                            if (plus_or_space == '\0' ||
                                (plus_or_space != '\0' &&
                                 plus_or_space == ' ' && *i == '+'))
                                plus_or_space = *i;
                        }
                    }
                }
                long long int numb = 0;
                if (lastspec != s21_NULL) {
                    s21_size_t symbs = 0;
                    double float_count = 0;
                    switch (*lastspec) {
                        case '%':
                            *str = '%';
                            str++;
                            bytes++;
                            break;
                        case 'c':
                            symbs = case_char(va_arg(args, int), flags,
                                              minus_fl, first, width, str);
                            bytes += symbs;
                            str += symbs;
                            break;
                        case 'u':
                        case 'i':
                        case 'd':
                            if (modifier != s21_NULL) {
                                switch (*modifier) {
                                    case 'l':
                                        numb = va_arg(args, long int);
                                        break;
                                    case 'h':
                                        numb = va_arg(args, int);
                                }
                            } else {
                                numb = va_arg(args, int);
                            }
                            if (*lastspec == 'u' && numb < 0) {
                                bytes = -1;
                                break;
                            }
                            s21_size_t dig = digits(numb);
                            if (flags != s21_NULL) {
                                if (minus_fl == 1) {
                                    if (numb >= 0 && (plus_or_space != '\0') &&
                                        *lastspec != 'u') {
                                        *first = plus_or_space;
                                        first++;
                                        str++;
                                        if (width > dig) width--;
                                        bytes++;
                                    }
                                    if (accur != s21_NULL && acc > dig) {
                                        if (numb < 0) {
                                            *first = '-';
                                            numb *= -1;
                                            first++;
                                            if (width > dig) width--;
                                            bytes++;
                                        }
                                        zeros(acc - dig, first);
                                        s21_itoa(numb, first + acc - dig);
                                        symbs = MinusflagAcc(first, width, acc);
                                        str = first + symbs;
                                    } else {
                                        if (accur != s21_NULL && acc == 0 &&
                                            numb == 0)
                                            dig = 0;
                                        else
                                            s21_itoa(numb, first);
                                        symbs = MinusflagNoAcc(first, width,
                                                               dig, numb);
                                        str = first + symbs;
                                    }
                                    bytes += symbs;
                                    first = s21_NULL;
                                } else {
                                    if (numb >= 0 && plus_or_space != '\0' &&
                                        *lastspec != 'u') {
                                        if (accur != s21_NULL && acc > dig) {
                                            if (width > acc && width > dig) {
                                                str +=
                                                    padding(first, width - acc);
                                                *(str - 1) = plus_or_space;
                                                str += zeros(acc - dig, str);
                                                bytes += width;
                                            } else {
                                                *str = plus_or_space;
                                                str +=
                                                    zeros(acc - dig, str + 1) +
                                                    1;
                                                bytes += acc + 1;
                                            }
                                        } else {
                                            if (accur != s21_NULL && acc == 0 &&
                                                numb == 0)
                                                dig = 0;
                                            if (width > dig) {
                                                str += padding(first,
                                                               width - dig - 1);
                                                bytes += width;
                                            } else {
                                                bytes += dig + 1;
                                            }
                                            *str = plus_or_space;
                                            str++;
                                            if (dig == 0) first = s21_NULL;
                                        }
                                    }
                                }
                            }
                            if (accur != s21_NULL && acc > dig &&
                                first != s21_NULL &&
                                (flags == s21_NULL || *lastspec == 'u' ||
                                 (flags != s21_NULL && numb < 0 &&
                                  minus_fl != 1))) {
                                if (width > acc) {
                                    str += padding(first, width - acc);
                                    if (numb < 0) {
                                        *(str - 1) = '-';
                                        numb *= -1;
                                    }
                                    str += zeros(acc - dig, str);
                                    bytes += width;
                                } else {
                                    if (numb < 0) {
                                        *first = '-';
                                        first++;
                                        numb *= -1;
                                        bytes++;
                                    }
                                    zeros(acc - dig, first);
                                    str = first + acc - dig;
                                    bytes += acc;
                                }
                            } else {
                                if (numb < 0)
                                    dig++;
                                else if (accur != s21_NULL && acc == 0 &&
                                         first != s21_NULL && numb == 0)
                                    dig = 0;
                                if (width > dig && first != s21_NULL &&
                                    (flags == s21_NULL ||
                                     (flags != s21_NULL && numb < 0 &&
                                      minus_fl != 1))) {
                                    padding(str, width - dig);
                                    str += width - dig;
                                    bytes += width;
                                } else {
                                    if ((flags == s21_NULL &&
                                         first != s21_NULL) ||
                                        (flags != s21_NULL && numb < 0 &&
                                         minus_fl != 1))
                                        bytes += dig;
                                }
                                if (dig == 0) first = s21_NULL;
                            }
                            if (first != s21_NULL) str += s21_itoa(numb, str);
                            break;
                        case 's':
                            arg_string = va_arg(args, char *);
                            numb = s21_strlen(arg_string);
                            if (flags != s21_NULL && minus_fl == 1) {
                                if (accur != s21_NULL) {
                                    if (acc > (s21_size_t)numb) acc = numb;
                                    s21_strncpy(str, arg_string, acc);
                                    str += acc;
                                    if (width > acc) {
                                        str += padding(str, width - acc);
                                        bytes += width - acc;
                                    }
                                    bytes += acc;
                                } else {
                                    s21_strcpy(str, arg_string);
                                    str += numb;
                                    if (width > (s21_size_t)numb) {
                                        str += padding(str, width - numb);
                                        bytes += width - numb;
                                    }
                                    bytes += numb;
                                }
                            } else {
                                if (accur != s21_NULL) {
                                    if (acc > (s21_size_t)numb) acc = numb;
                                    if (width > acc) {
                                        str += padding(str, width - acc);
                                        bytes += width - acc;
                                    }
                                    s21_strncpy(str, arg_string, acc);
                                    str += acc;
                                    bytes += acc;
                                } else {
                                    if (width > (s21_size_t)numb) {
                                        str += padding(str, width - numb);
                                        bytes += width - numb;
                                    }
                                    s21_strcpy(str, arg_string);
                                    str += numb;
                                    bytes += numb;
                                }
                            }
                            break;
                        case 'f':
                            float_count = 0;
                            float_count = va_arg(args, double);
                            if (accur == s21_NULL) acc = 6;
                            s21_size_t dig_f = float_numb(float_count, acc);
                            if (flags != s21_NULL) {
                                if (minus_fl == 1) {
                                    if (float_count >= 0 &&
                                        (plus_or_space != '\0')) {
                                        *first = plus_or_space;
                                        first++;
                                        str++;
                                        if (width > dig_f) width--;
                                        bytes++;
                                    }
                                    str += ftoa(float_count, 1, acc, str);
                                    symbs =
                                        floatMinusflagAcc(str, width, dig_f);
                                    str = first + symbs;
                                    bytes += symbs;
                                    first = s21_NULL;
                                } else {
                                    if (float_count >= 0 &&
                                        plus_or_space != '\0') {
                                        if (width > dig_f) {
                                            str +=
                                                padding(first, width - dig_f);
                                            *(str - 1) = plus_or_space;
                                            bytes += width;
                                        } else {
                                            *str = plus_or_space;
                                            str++;
                                            bytes += dig_f + 1;
                                        }
                                    }
                                }
                            }
                            if (width > dig_f && first != s21_NULL &&
                                (flags == s21_NULL ||
                                 (flags != s21_NULL && float_count < 0))) {
                                str += padding(first, width - dig_f);
                                bytes += width;
                            } else {
                                if ((flags == s21_NULL) ||
                                    (flags != s21_NULL && float_count < 0 &&
                                     minus_fl != 1))
                                    bytes += dig_f;
                            }
                            if (first != s21_NULL)
                                str += ftoa(
                                    float_count, 1, acc,
                                    str);  //  (Переменная типа флоат(дабл),
                                           //  тип нотации, точность, строка)
                            break;
                    }
                    if (bytes == -1) break;
                } else {
                    bytes = -1;
                    break;
                }
                format += lengthofspec;
            } else {
                *str = *format;
                str++;
                bytes++;
            }
        }
        va_end(args);
        *str = '\0';
    }
    return bytes;
}
/*
Функция считает количество цифр в числе. (при number = 0 возвращает 1)
*/
s21_size_t digits(long long int number) {
    s21_size_t count = 0;
    if (number < 0)
        number *= (-1);
    else if (number == 0)
        count = 1;
    while (number > 0) {
        number /= 10;
        count++;
    }
    return count;
}
/*
Наполнение строки пробелами, возврщает кол-во пробелов
*/
s21_size_t padding(char *str, s21_size_t width) {
    s21_size_t count = 0;
    for (; count < width; count++) {
        *str = ' ';
        str++;
    }
    return count;
}
/*
Преобразование числа (int) в строкубю, возврщает кол-во цифр в числе
*/
int s21_itoa(long long int a, char *str) {
    char *ptr = str;
    if (a < 0) {
        *ptr = '-';
        a *= -1;
        ptr++;
    }
    for (int i = digits(a) - 1; i >= 0; i--) {
        *ptr = (char)((a / (int)pow(10, i)) + 48);
        ptr++;
        a %= (int)pow(10, i);
    }
    return ptr - str;
}
/*
Наполнение строки нулями, возврщает кол-во нолей
*/
s21_size_t zeros(s21_size_t acc, char *str) {
    char *ptr = str;
    for (s21_size_t i = 0; i < acc; i++) {
        *ptr = '0';
        ptr++;
    }
    return ptr - str;
}

s21_size_t s21_atoi(const char *strnumb) {
    s21_size_t numb = 0;
    if (*strnumb > '0' && *strnumb <= '9') {
        int razr = 1;
        for (; *strnumb != '\0' && *strnumb >= '0' && *strnumb <= '9';
             strnumb++) {
            numb *= razr;
            if (razr == 1) razr = 10;
            numb += (*strnumb - 48);
        }
    }
    return numb;
}

int case_char(int arg, char *flags, int minus_fl, char *first, s21_size_t width,
              char *str) {
    int bytes = 0;
    if (width > 1) {
        if (flags == s21_NULL || (flags != s21_NULL && minus_fl != 1)) {
            str += padding(first, width - 1);
            *str = arg;
        } else {
            *str = arg;
            str += padding(first + 1, width - 1);
        }
        bytes += width;
    } else {
        *str = arg;
        bytes++;
    }
    str++;
    return bytes;
}

s21_size_t MinusflagAcc(char *first, s21_size_t width, s21_size_t acc) {
    s21_size_t bytes = 0;
    if (width > acc) {
        padding(first + acc, width - acc);
        bytes += width;
    } else {
        bytes += acc;
    }
    return bytes;
}

s21_size_t MinusflagNoAcc(char *first, s21_size_t width, s21_size_t dig,
                          long long numb) {
    s21_size_t bytes = 0;
    if (numb < 0) dig++;
    if (width > dig) {
        padding(first + dig, width - dig);
        bytes += width;
    } else {
        bytes += dig;
    }
    return bytes;
}
s21_size_t floatMinusflagAcc(char *str, s21_size_t width, s21_size_t dig_f) {
    s21_size_t bytes;
    if (width > dig_f) {
        padding(str, width - dig_f);
        bytes = width;
    } else {
        bytes = dig_f;
    }
    return bytes;
}

s21_size_t float_numb(long double a, int accur) {
    long double test = a;
    s21_size_t counts = 0;
    int before = 0;
    long int d = test;
    if (a < 0) {
        counts++;
        test *= -1;
    }
    if (d == 0) {
        counts++;
    }
    for (; test > 1.0;) {
        before++;
        test /= 10;
    }
    test *= 10;
    for (; before > 0; before--, test *= 10) {
        d = test;
        counts++;
    }
    if (accur != 0) {
        counts++;
    }
    test = a - (int)a;
    test *= 10;
    if (a < 0) test *= -1;
    for (int u = 0; u < (accur + 1); u++, test *= 10) {
        d = test;
        if (u < accur) counts++;
    }
    return counts;
}

int ftoa(long double a, int notation, int accur, char *str) {
    int counts = 0;
    long double test;
    char *ptr;
    switch (notation) {
        case 1:
            test = a;
            ptr = str;
            int before = 0;
            long int d = test;
            if (a < 0) {
                ptr[counts] = '-';
                counts++;
                test *= -1;
            }
            if (d == 0) {
                ptr[counts] = '0';
                counts++;
            }
            for (; test > 1.0;) {
                before++;
                test /= 10;
            }
            test *= 10;
            for (; before > 0; before--, test *= 10) {
                d = test;
                int dd = d % 10;
                ptr[counts] = dd + 48;
                counts++;
            }
            if (accur != 0) {
                ptr[counts] = '.';
                counts++;
            }
            test = a - (int)a;
            double round = test;
            test *= 10;
            if (a < 0) test *= -1;
            for (int u = 0; u < (accur + 1); u++, test *= 10) {
                d = test;
                int dd = d % 10;
                ptr[counts] = dd + 48;
                if (u < accur) counts++;
            }
            if (ptr[counts] - 48 >= 5 && ptr[counts] - 48 < 10 && accur != 0) {
                ptr[counts - 1]++;
                ptr[counts]--;
            }
            if (accur == 0) {
                if (round > 0.500000) {
                    ptr[counts - 1]++;
                    ptr[counts]--;
                } else {
                    if ((ptr[counts - 1] - 48) % 2 != 0 &&
                        ptr[counts] - 48 >= 5) {
                        ptr[counts - 1]++;
                        ptr[counts]--;
                    }
                }
            }
            for (int i = counts; i > 1; i--) {
                if (ptr[i] - 48 >= 10) {
                    ptr[i - 1]++;
                    ptr[i]--;
                }
                if (ptr[i] == '/') ptr[i - 1]++;
            }
            ptr[counts] = '\0';
            break;
        case 2:
            break;
        default:
            break;
    }
    return counts;
}
