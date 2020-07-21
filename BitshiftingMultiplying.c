// https://stackoverflow.com/questions/6357038/is-multiplication-and-division-using-shift-operators-in-c-actually-faster/59701955#59701955
// I wanted to see if I could Beat the House. this is a more general bitwise for any-number by any number multiplication. the macros I made are about 25% more to twice as slower than normal * multiplication. as said by others if it's close to a multiple of 2 or made up of few multiples of 2 you might win. like X*23 made up of (X<<4)+(X<<2)+(X<<1)+X is going to be slower then X*65 made up of (X<<6)+X.

    #include <stdio.h>
    #include <time.h>

    #define MULTIPLYINTBYMINUS(X,Y) (-((X >> 30) & 1)&(Y<<30))+(-((X >> 29) & 1)&(Y<<29))+(-((X >> 28) & 1)&(Y<<28))+(-((X >> 27) & 1)&(Y<<27))+(-((X >> 26) & 1)&(Y<<26))+(-((X >> 25) & 1)&(Y<<25))+(-((X >> 24) & 1)&(Y<<24))+(-((X >> 23) & 1)&(Y<<23))+(-((X >> 22) & 1)&(Y<<22))+(-((X >> 21) & 1)&(Y<<21))+(-((X >> 20) & 1)&(Y<<20))+(-((X >> 19) & 1)&(Y<<19))+(-((X >> 18) & 1)&(Y<<18))+(-((X >> 17) & 1)&(Y<<17))+(-((X >> 16) & 1)&(Y<<16))+(-((X >> 15) & 1)&(Y<<15))+(-((X >> 14) & 1)&(Y<<14))+(-((X >> 13) & 1)&(Y<<13))+(-((X >> 12) & 1)&(Y<<12))+(-((X >> 11) & 1)&(Y<<11))+(-((X >> 10) & 1)&(Y<<10))+(-((X >> 9) & 1)&(Y<<9))+(-((X >> 8) & 1)&(Y<<8))+(-((X >> 7) & 1)&(Y<<7))+(-((X >> 6) & 1)&(Y<<6))+(-((X >> 5) & 1)&(Y<<5))+(-((X >> 4) & 1)&(Y<<4))+(-((X >> 3) & 1)&(Y<<3))+(-((X >> 2) & 1)&(Y<<2))+(-((X >> 1) & 1)&(Y<<1))+(-((X >> 0) & 1)&(Y<<0))
    #define MULTIPLYINTBYSHIFT(X,Y) (((((X >> 30) & 1)<<31)>>31)&(Y<<30))+(((((X >> 29) & 1)<<31)>>31)&(Y<<29))+(((((X >> 28) & 1)<<31)>>31)&(Y<<28))+(((((X >> 27) & 1)<<31)>>31)&(Y<<27))+(((((X >> 26) & 1)<<31)>>31)&(Y<<26))+(((((X >> 25) & 1)<<31)>>31)&(Y<<25))+(((((X >> 24) & 1)<<31)>>31)&(Y<<24))+(((((X >> 23) & 1)<<31)>>31)&(Y<<23))+(((((X >> 22) & 1)<<31)>>31)&(Y<<22))+(((((X >> 21) & 1)<<31)>>31)&(Y<<21))+(((((X >> 20) & 1)<<31)>>31)&(Y<<20))+(((((X >> 19) & 1)<<31)>>31)&(Y<<19))+(((((X >> 18) & 1)<<31)>>31)&(Y<<18))+(((((X >> 17) & 1)<<31)>>31)&(Y<<17))+(((((X >> 16) & 1)<<31)>>31)&(Y<<16))+(((((X >> 15) & 1)<<31)>>31)&(Y<<15))+(((((X >> 14) & 1)<<31)>>31)&(Y<<14))+(((((X >> 13) & 1)<<31)>>31)&(Y<<13))+(((((X >> 12) & 1)<<31)>>31)&(Y<<12))+(((((X >> 11) & 1)<<31)>>31)&(Y<<11))+(((((X >> 10) & 1)<<31)>>31)&(Y<<10))+(((((X >> 9) & 1)<<31)>>31)&(Y<<9))+(((((X >> 8) & 1)<<31)>>31)&(Y<<8))+(((((X >> 7) & 1)<<31)>>31)&(Y<<7))+(((((X >> 6) & 1)<<31)>>31)&(Y<<6))+(((((X >> 5) & 1)<<31)>>31)&(Y<<5))+(((((X >> 4) & 1)<<31)>>31)&(Y<<4))+(((((X >> 3) & 1)<<31)>>31)&(Y<<3))+(((((X >> 2) & 1)<<31)>>31)&(Y<<2))+(((((X >> 1) & 1)<<31)>>31)&(Y<<1))+(((((X >> 0) & 1)<<31)>>31)&(Y<<0))
    int main()
    {
        int randomnumber=23;
        int randomnumber2=23;
        int checknum=23;
        clock_t start, diff;
        srand(time(0));
        start = clock();
        for(int i=0;i<1000000;i++)
        {
            randomnumber = rand() % 10000;
            randomnumber2 = rand() % 10000;
            checknum=MULTIPLYINTBYMINUS(randomnumber,randomnumber2);
            if (checknum!=randomnumber*randomnumber2)
            {
                printf("s %i and %i and %i ",checknum,randomnumber,randomnumber2);
            }
        }
        diff = clock() - start;
        int msec = diff * 1000 / CLOCKS_PER_SEC;
        printf("MULTIPLYINTBYMINUS cat Time %d milliseconds ", msec);
        start = clock();
        for(int i=0;i<1000000;i++)
        {
            randomnumber = rand() % 10000;
            randomnumber2 = rand() % 10000;
            checknum=MULTIPLYINTBYSHIFT(randomnumber,randomnumber2);
            if (checknum!=randomnumber*randomnumber2)
            {
                printf("s %i and %i and %i ",checknum,randomnumber,randomnumber2);
            }
        }
        diff = clock() - start;
        msec = diff * 1000 / CLOCKS_PER_SEC;
        printf("MULTIPLYINTBYSHIFT Time %d milliseconds ", msec);
        start = clock();
        for(int i=0;i<1000000;i++)
        {
            randomnumber = rand() % 10000;
            randomnumber2 = rand() % 10000;
            checknum= randomnumber*randomnumber2;
            if (checknum!=randomnumber*randomnumber2)
            {
                printf("s %i and %i and %i ",checknum,randomnumber,randomnumber2);
            }
        }
        diff = clock() - start;
        msec = diff * 1000 / CLOCKS_PER_SEC;
        printf("normal * Time %d milliseconds ", msec);
        return 0;
    }
