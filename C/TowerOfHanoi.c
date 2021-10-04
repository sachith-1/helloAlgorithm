//C program to display the moves possible in TOWER_OF_HANOI using stack
#include <stdio.h>

void towers(int, char, char, char);

int main()
{
    int num;

    printf("Enter the number of disks : ");
    scanf("%d", &num);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(num, 'A', 'C', 'B');
    return 0;
}
void towers(int num, char from, char to, char temp)
{
    if (num == 1)
    {
        printf("\n Move disk 1 from position %c to position %c", from, to);
        return;
    }
    towers(num - 1, from, temp, to);
    printf("\n Move disk %d from position %c to position %c", num, from, to);
    towers(num - 1, temp, to, from);
}
