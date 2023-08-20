#include"main.h"

/* for testing purposes + } = */

int main(void)
{
    char var = 'c';
    char *s = "I love you so much";
    int nb;

    nb = _printf("%s %c\n", s, var);
    nb = printf("%s %c\n", s, var);
    printf("The number of character print %d\n", nb);
    

    return (0);
}


