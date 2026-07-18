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

void start(int H,int M,int S)
{
    int ch;
    int x=H,y=M,z=S;
    int count=1;

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
        
        if ( t.h==H && t.m==M && t.s==S )
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
                    count++;
                    H=count*x;
                    M=count*y;
                    S=count*z;  
                    if(S>60)
                    {
                        S=S-60;
                        M=M+1;
                    }
                    if(M>60)
                    {
                        M=M=60;
                        H=H+1;
                    }
                    continue;
                     


                case 2:
                    printf("\nClock Stopped at %02d:%02d:%02d\n",
                           t.h, t.m, t.s);
                    Sleep(2000);
                    printf("enter 1 to continue\n");
                    int ck;
                    scanf("%d",&ck);
                    if(ck==1)
                    {
                        count++;
                    H=count*x;
                    M=count*y;
                    S=count*z; 
                    if(S>60)
                    {
                        S=S-60;
                        M=M+1;
                    }
                    if(M>60)
                    {
                        M=M=60;
                        H=H+1;
                    } 
                    continue;
                    }
                    else{
                        exit(0);
                    }


                case 3:
                    t.h = 0;
                    t.m = 0;
                    t.s = 0;
                    H=x;
                    M=y;
                    S=z;
                    count=1;

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
    int H,M,S;

    while (1)
    {
        
        printf("\n===== DIGITAL CLOCK =====\n");
        printf("enter limitd time H : M : S :: \n");
        scanf("%d%d%d",&H,&M,&S);
        printf("\n1. Start Clock");
        printf("\n2. Exit");
        printf("\nEnter your option: ");

        scanf("%d", &opt);

        switch (opt)
        {
            case 1:
                start(H,M,S);
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
