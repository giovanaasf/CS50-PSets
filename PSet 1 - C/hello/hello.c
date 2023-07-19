#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}
