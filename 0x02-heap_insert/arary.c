#include <stdio.h>

int main()
{
int *array[12];
int i = 0;
array[0] = 12;
array[1] = 14;
while(array[i]) {
    printf("%d", array[i]);
    i++;
}
    return 0;
}
