#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct clock
{
    int h;
    int m;
    int s;
};

struct clock t = {0, 0, 0};

void start(int lim)
{
    int ch;

    while (1)
    {
        system("cls");

        printf("CLOCK : %02d:%02d:%02d\n", t.h, t.m, t.s);

        Sleep(1000);

        t.s++;

        if (t.s == 60)
        {
            t.s = 0;
            t.m++;
        }

        if (t.m == 60)
        {
            t.m = 0;
            t.h++;
        }

        if (t.h == 24)
        {
            t.h = 0;
        }

        if (t.s % lim == 0)
        {
            printf("\n\n1. Continue");
            printf("\n2. Stop");
            printf("\n3. Restart");
            printf("\n4. Exit");

            printf("\n\nEnter your choice: ");
            scanf("%d", &ch);

            switch (ch)
            {
                case 1:
                    /* Continue running */
                    continue;

                case 2:
                    printf("\nClock Stopped at %02d:%02d:%02d\n",
                           t.h, t.m, t.s);
                    Sleep(2000);
                    return;

                case 3:
                    t.h = 0;
                    t.m = 0;
                    t.s = 0;

                    printf("\nClock Restarted!");
                    Sleep(1000);
                    break;

                case 4:
                    exit(0);

                default:
                    printf("\nInvalid Choice!");
                    Sleep(1000);
            }
        }
    }
}

int main()
{
    int opt;
    int lim;

    while (1)
    {
        
        printf("\n===== DIGITAL CLOCK =====\n");
        printf("enter limit\n");
        scanf("%d",&lim);
        printf("\n1. Start Clock");
        printf("\n2. Exit");
        printf("\nEnter your option: ");

        scanf("%d", &opt);

        switch (opt)
        {
            case 1:
                start(lim);
                break;

            case 2:
                printf("Program Terminated.\n");
                return 0;

            default:
                printf("Invalid Option!\n");
        }
    }

    return 0;
}
