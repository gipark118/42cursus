#include <unistd.h>
#include <stdarg.h>

size_t  ft_strlen(const char *s)
{
    size_t count;

    count = 0;
    while (s[count])
        count++;
    return (count);
}

int     ft_numlen(long long num, int base_len)
{
    int i;

    i = 1;
    while (num >= base_len || num <= -base_len)
    {
        num /= base_len;
        i++;
    }
    return (i);
}

void    ft_putnum(long long num, int base_len, char *base)
{
    if (num >= base_len)
        ft_putnum(num / base_len, base_len, base);
    write (1, &base[num % base_len], 1);
}

int ft_printf(char *format, ...)
{
    va_list ap;
    char *base, *s, *str;
    long num;
    int width, point, precision, number_zero, space, base_len, strlen, negative, length;

    width = 0;
    point = 0;
    precision = 0;
    number_zero = 0;
    space = 0;
    strlen = 0;
    negative = 0;
    length = 0;
    va_start(ap, format);
    str = (char *)format;
    while (*str != '\0')
    {
        if (*str == '%')
        {
            str++;
            width = 0;
            point = 0;
            precision = 0;
            number_zero = 0;
            space = 0;
            strlen = 0;
            negative = 0;
            while (*str >= '0' && *str <= '9')
            {
                width = width * 10 + (*str - '0');
                str++;
            }
            if (*str == '.')
            {
                str++;
                while (*str >= '0' && *str <= '9')
                {
                    precision = precision * 10 + (*str - '0');
                    str++;
                }
                point = 1;
            }
            if (*str == 's')
            {
                s = va_arg(ap, char *);
                if (!s)
                    s = "(null)";
                strlen = ft_strlen(s);
            }
            if (*str == 'x')
            {
                num = va_arg(ap, unsigned int);
                base = "0123456789abcdef";
                base_len = 16;
                strlen = ft_numlen(num, base_len);
            }
            if (*str == 'd')
            {
                num = va_arg(ap, int);
                base = "0123456789";
                base_len = 10;
                if (num < 0)
                {
                    num *= -1;
                    negative = 1;
                }
                strlen = ft_numlen(num, base_len) + negative;
            }
            if (point == 1 && precision > strlen && *str != 's')
                number_zero = precision - strlen + negative;
            else if (point == 1 && precision < strlen && *str == 's')
                strlen = precision;
            else if (point == 1 && precision == 0 && (*str == 's' || num == 0))
                strlen = 0;
            space = width - strlen - number_zero;
            while (space-- > 0)
            {
                write (1, " ", 1);
                length++;
            }
            if (negative == 1)
                write (1, "-", 1);
            while (number_zero-- > 0)
            {
                write (1, "0", 1);
                length++;
            }
            if (*str == 's')
                write (1, s, strlen);
            else if (strlen > 0)
                ft_putnum(num, base_len, base);
            length += strlen;
            str++;
        }
        else
        {
            write (1, str, 1);
            str++;
            length++;
        }
    }
    return (length);
}
