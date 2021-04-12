#include <stdio.h>


#define LOWER 0 /* lower limit of table */
#define UPPER 300 /* upper limit */
#define STEP 20 /* step size */
#define NONBLANK '_' /* used as sentinel */

void printHelloWorld() // Ex 1-1
{
    char helloWorld[] = "Hello, World ! \n";
    printf("%s", helloWorld);

}

void unknownEscapeSequence() // Ex 1-2
{
    printf("\c"); /* Ignores backslash because \c is unknown*/
}
/** print Fahrenheit-Celsius table
        for fahrenheit = 0, 20, ..., 300 */
void fahrenheitCelsiusTable()
{
    //C = (5/9)(F-32)
    int fahrenheit, celsius;
    int lower, upper, step;
    lower = 0; /* lower limit of temperature scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    fahrenheit = lower;
    while (fahrenheit <= upper) {
        celsius = 5 * (fahrenheit - 32) / 9;
        printf("%d\t%d\n", fahrenheit, celsius);
        fahrenheit = fahrenheit + step;
    }
}

void celsiusFahrenheitTable() //Ex 1-3
{
    int fahrenheit, celsius;
    int lower, upper, step;
    lower = -20;
    upper = 150;
    step = 5;
    celsius = lower;

    while(celsius <= upper) {
        fahrenheit = (celsius * 9 / 5) + 32;
        printf("%d\t%d\n", celsius, fahrenheit);
        celsius = celsius + step;
    }

}

void fahrenheitCelsiusTableFloat() // Ex 1-4
{
    float fahrenheit, celsius;
    float lower, upper, step;
    printf("__________________________ \n");
    printf("|Fahrenheit-Celsius Table| \n");
    printf("-------------------------- \n");

    lower = 0; /* lower limit of temperature scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    fahrenheit = lower;
    while (fahrenheit <= upper) {
        celsius = 5 * (fahrenheit - 32) / 9;
        printf("|\t%3.0f \t| \t%6.1f\t |\n", fahrenheit, celsius);
        fahrenheit = fahrenheit + step;
    }
    printf("-------------------------- \n");

}

void fahrenheitCelsiusReverse() // Ex 1-5
{
    int fahrenheit, celsius;
    printf("__________________________ \n");
    printf("|Fahrenheit-Celsius Table| \n");
    printf("-------------------------- \n");

    for (fahrenheit = UPPER; fahrenheit > LOWER; fahrenheit -= STEP) {
        celsius = 5 * (fahrenheit - 32) / 9;
        printf("|\t%3.0d \t| \t%6.1d\t |\n", fahrenheit, celsius);
    }
    printf("-------------------------- \n");
}

void inputOutput()
{
    int c;
    c = getchar();
    while (c != EOF) {
//        putchar(c);
        printf("%c", c);
        c = getchar();
    }
}

void inputOutput2()
{
    int c;
    while ((c = getchar()) != EOF)
        putchar(c);
}

void eof() // Ex 1-6
{
    /**TO SIMULATE EOF:
     *  On mac use: ctrl + d
     *  On windows use: ctrl + z
    */
    printf("\nEnter char to output 0 or ctrl + d to output 1 ");
    printf("\ngetchar() != EOF: %i", getchar() != EOF); /* prints 1 when not EOF. prints 0 when EOF*/
}
void eof2() //Ex 1-7
{
    printf("Value of EOF = %d", EOF); /* prints value of EOF */
}

void characterCount()
{
    long nc;
    nc = 0;
    getchar();
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);

}
void characterCount2()
{
    double nc;
    getchar();
    for (nc = 0; getchar() != EOF; ++nc);
    printf("%.0f\n", nc);
}

void lineCount()
{
    int c, n1;
    n1 = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++n1;
    printf("%d\n", n1);
}

void blankTabsNewlineCount() // Ex 1-8
{
    int c, b, t, n;
    b = 0;
    t = 0;
    n = 0;
    while((c = getchar()) != EOF) {
        if (c == '\n')
            ++n;
        if (c == '\t')
            ++t;
        if (c == ' ')
            ++b;
    }
    printf("Blanks: %d\nTabs: %d\nNewlines: %d\n", b, t, n);

}

void replaceMultipleSpaceWithOne()
{
    int c, pc;
    pc = NONBLANK;
    while((c = getchar()) != EOF) {
        if(c == ' ')
        {
            if(pc != ' ')
                putchar(c);
        }
        else {
            putchar(c);
        }
        pc = c;
    }
}

/** Driver Code */
int main()
{
//    printHelloWorld();
//    unknownEscapeSequence();
//    fahrenheitCelsiusTable();
//    celsiusFahrenheitTable();
//    fahrenheitCelsiusTableFloat();
//    fahrenheitCelsiusReverse();
//    inputOutput();
//    inputOutput2();
//    eof();
//    characterCount();
//    characterCount2();
//    lineCount();
//    blankTabsNewlineCount();
//    replaceMultipleSpaceWithOne();

    return 0;
}


