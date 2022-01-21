#include <cs50.h>
#include <stdio.h>

int main(void)
{
    unsigned int height;

    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);


    for (unsigned int i = 0; i < height; i++)
    {
        for (unsigned int j = 0; j < height - i; j++)
        {
            if (j != height - i - 1)
            {
                printf(" ");
            }
            else
            {
                for (unsigned int x = 0; x <= i; x++)
                {
                    printf("#");
                }
            }
        }

        printf("  ");
        for (unsigned int y = 0; y <= i; y++)
        {
            printf("#");

        }
        printf("\n");
    }



    /*for (int i = 0; i < height; i++) {
        for (int j = 0; j <= i; j ++) {
            printf("#");
        }
        printf("\n");
    }*/
}