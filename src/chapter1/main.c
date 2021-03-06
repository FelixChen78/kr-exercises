#include <stdio.h>


#define LOWER 0 /* lower limit of table */
#define UPPER 300 /* upper limit */
#define STEP 20 /* step size */
#define NON_BLANK '_' /* used as sentinel */
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define R_MAX 10 /* max range of histogram */
#define F_MAX 20 /* max frequency of histogram */
#define ASCII_RANGE 127 /* range of ASCII values */
#define MAX_LINE 1000 /* maximum input line length */
#define LOWER_LINE 80 /* lower limit of line output */
#define SPACE_IN_TAB 7 /* number of blank space to replace tab */
#define FOLD_MAX 10 /* max number of char allowed per line */
#define true 1
#define false 0



/** GETTING STARTED */
void printHelloWorld() // Ex 1-1
{
    char helloWorld[] = "Hello, World ! \n";
    printf("%s", helloWorld);
}

void unknownEscapeSequence() // Ex 1-2
{
    //uncomment
//    printf("\c"); /* Ignores backslash because \c is unknown */
}

/** VARIABLES AND ARITHMETIC EXPRESSIONS */

/* print Fahrenheit-Celsius table
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

/** FOR STATEMENT && SYMBOLIC CONSTANT */
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

/** CHARACTER INPUT AND OUTPUT */
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

/** TO SIMULATE EOF:
 *  On mac use: ctrl + d
 *  On windows use: ctrl + z
*/

void eof() // Ex 1-6
{
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

void replaceMultipleSpaceWithOne() // Ex 1-9
{
    int c, pc;
    pc = NON_BLANK;
    while((c = getchar()) != EOF) {
        if(c == ' ') {
            if(pc != ' ')
                putchar(c);
        }
        else {
            putchar(c);
        }
        pc = c;
    }
}

void toEscapeSequence() // Ex 1-10
{
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\b') // ctrl h
            printf("\\b");
        if (c == '\\') // /
            printf("\\\\");
        if (c == '\t') // tab
            printf("\\t");
        if(c != '\t' && c != '\b' && c != '\\')
            putchar(c);
    }
}

/* count lines, words, and characters in input */
void wordCount()
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}

/** Ex 1-11
 * you can test 3 type of inputs:
 *      valid inputs
 *      invalid inputs
 *      boundary conditions
 */

void wordNewLine() // Ex 1-12
{
    int c, state;
    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            if (state == OUT)
                state = IN;
            putchar(c);
        }
        else if (state == IN) {
            state = OUT;
            putchar('\n');
        }
    }
}

/** ARRAYS */
void countDigit() {
    int c, i, nwhite, nother;
    int ndigit[10];
    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;
    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    printf("digits =");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
}

/* steps:
 *      identify is a word
 *      count word length
 *      store frequency of word length in array
 *      graph horizontal histogram:
 *              loop frequency array length
 *                  print number "\t |"
 *                  loop length of value stored in frequency array
 *                          print *
 *      graph vertical histogram:
 *              loop max number of words (descending)
 *                  loop frequency array length
 *                      check if value at frequency array index is greater or equal to descending value
 *                          print *
 */

void wordLengthHistogram() // Ex 1-13
{
    int c, state, i, j, wlength;
    int wcount[R_MAX];
    wlength = 0;

    for (i = 0; i < R_MAX; ++i)
        wcount[i] = 0;
    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            if (state == OUT)
                state = IN;
            ++wlength;

        }
        else if (state == IN) {
            state = OUT;
            if (wlength > R_MAX - 1)
                ++wcount[R_MAX - 1];
            else
                ++wcount[wlength - 1];
            wlength = 0;
        }
    }
    printf("Horizontal Histogram \n");
    printf("-------------------- \n");
    /* Horizontal Histogram */
    for (i = 1; i <= R_MAX; ++i) {
        if (i != R_MAX) {
            printf("%i \t\b\b\b\b: %i | ", i, wcount[i - 1]);
        }
        else
            printf("%s \t\b\b\b\b: %i | ", "10+", wcount[i - 1]);
        for (j = 1; j <= wcount[i - 1]; ++j)
            putchar('*');
        putchar('\n');
    }
    printf("\n\nVertical Histogram \n");
    printf("------------------ \n");

    /* Vertical Histogram */
    for (i = F_MAX; i >= 0; --i) {
        if (i != 0) {
            printf("%i \t\b\b\b\b\b| ", i);
            for (j = 0; j < R_MAX; ++j)
                if (i <= wcount[j])
                    printf("* ");
                else
                    printf("  ");
            printf("\n");
        }


    }
    printf("\t\b\b\b\b\b------------------------\n");
    printf("\t\b\b\b\b\b  1 2 3 4 5 6 7 8 9 10+");


}

void characterFrequency() // Ex 1-14
{
    int c, i, j;
    int characters[ASCII_RANGE];
    int characterFrequency[ASCII_RANGE];


    for (i = 0; i < ASCII_RANGE; ++i) {
        characterFrequency[i] = 0;
        characters[i] = i;
    }

    while ((c = getchar()) != EOF)
        if (c != '\n' && c != '\t' && c != ' ') {
            for (i = 0; i < ASCII_RANGE; ++i)
                if (characters[i] == c)
                    ++characterFrequency[i];
    }

    for (i = 0; i < ASCII_RANGE; ++i) {
        if (characterFrequency[i] != 0) { //ASCII 0 is null
            printf("%c: %d | ", characters[i], characterFrequency[i]);
            for (j = 0; j < characterFrequency[i]; ++j)
                putchar('*');
            putchar('\n');
        }
    }
}

/** FUNCTIONS */

/* function declaration aka function prototype
 *  Note: Function declaration is required if you want to call the function in another file
 */
int power(int m, int n);

/* power: raise base to n-th power; constraint: n >= 0 */
int power(int base, int n)
{
    int i, p;
    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}

void callPower()
{
    int i;
    for (i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2,i), power(-3, i));
//        printf("%d %d %d\n", i, power2(2,i), power2(-3, i));
}

void fahrenheitCelsiusAsFunction(); // Ex 1-15
void fahrenheitCelsiusAsFunction()
{
    int fahrenheit, celsius;
    printf("__________________________ \n");
    printf("|Fahrenheit-Celsius Table| \n");
    printf("-------------------------- \n");

    for (fahrenheit = LOWER; fahrenheit < UPPER; fahrenheit += STEP) {
        celsius = 5 * (fahrenheit - 32) / 9;
        printf("|\t%3.0d \t| \t%6.1d\t |\n", fahrenheit, celsius);
    }
    printf("-------------------------- \n");
}

/** ARGUMENTS - CALL BY VALUE */

/* NOTE: parameter variables are copies and can be used as temporary variables.
 * It does not apply to array or function since the address to array or function is used.
 */

/* power:  raise base to n-th power; n >= 0; version 2 */
int power2(int base, int n)
{
    int p;
    for (p = 1; n > 0; --n)
        p = p * base;
    return p;
}

/** CHARACTER ARRAYS */

int getLine(char s[], int lim);
void copy(char to[], char from[]);
int getLineNoTabNoB(char *s, int lim);
void reverseCopy(char *s, int len);

/* getLine:  read a line into s, return length  */
int getLine(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
/* copy:  copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

void longestInputLine()
{
    int len;               /* current line length */
    int max;               /* maximum length seen so far */
    char line[MAX_LINE];    /* current input line */
    char longest[MAX_LINE]; /* longest line saved here */


    max = 0;
    while ((len = getLine(line, MAX_LINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max>0) /*there was a line*/
        printf("%s", longest);
}

void longestInputLine2() // Ex 1-16
{
    int len, max;
    char line[MAX_LINE];
    char longest[MAX_LINE];

    max = 0;

    while ((len = getLine(line, MAX_LINE)) > 0) {
        printf("%d : %s", len, line);
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
        printf("Longest line is %d characters: %s", max, longest);
}

void over80Characters() // Ex 1-17
{
    int len;
    char line[MAX_LINE];

    while ((len = getLine(line, MAX_LINE)) > 0) {
        if (len > LOWER_LINE) {
            printf("Input line is over %d characters: %s", LOWER_LINE, line);
        }
    }

}

int getLineNoTabNoB(char *s, int lim)
{
    int c, i;
    i = 0;
    while (i < lim - 1 && (c=getchar()) != EOF && c != '\n')
        if (c!=' ' && c!= '\t') {
            s[i] = c;
            ++i;
        }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

void deleteTrailBlankAndTabs() // Ex 1-18
{
    char line[MAX_LINE];
    while ((getLineNoTabNoB(line, MAX_LINE)) > 0)
        printf("%s", line);
}


int stripLead(int num) // Answer to reddit post
{
    int noLead, placeVal;
    noLead = num;
    placeVal = 1;

    while (!(num <= 10 && num >= -10)) {
        num /= 10;
        placeVal *= 10;
    }
    noLead -= num * placeVal;
    return noLead;
}

void reverseCopy(char *s, int len) {
    int i;
    char c[len];
    i = 0;
    while (len > 0) {
        --len;
        if (s[len] != '\0' && s[len] != '\n') {
            c[i] = s[len];
            ++i;
        }
    }
    c[++i] = '\n';
    c[i] = '\0';
    printf("%s \n", c);
}

void reverseString() // Ex 1-19
{
    int len;
    char line[MAX_LINE];
    while ((len = getLine(line, MAX_LINE)) > 0)
        reverseCopy(line, len);
}

/** EXTERNAL VARIABLES AND SCOPE */
void detab() //Ex 1-20
{
    int c, i, j;
    j = -1;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (i = 0; i < SPACE_IN_TAB - j; ++i)
                putchar(' ');
            j = -1;
        }
        else {
            putchar(c);
            ++j;
            if (c == '\n' || j == SPACE_IN_TAB)
                j = -1;
        }
    }
}

void entab() //Ex 1-21
{
     int c, state, spaceCount, spaceReduce;
     state = OUT;
     spaceReduce = 1;
     spaceCount = 0;

     while ((c = getchar()) != EOF) {
         if (c != ' ') {
             if (state == OUT) {
                 state = IN;
                 spaceCount = 0;
             }
             if (c != '\n')
                ++spaceReduce;
             if (spaceReduce > SPACE_IN_TAB)
                 spaceReduce = 1;

             putchar(c);
         }
         else {
             ++spaceCount;
             if (spaceCount >= (SPACE_IN_TAB - spaceReduce)) {
                 putchar('\t');
                 spaceCount -= (SPACE_IN_TAB - spaceReduce);
             }
             if (state == IN) {
                 state = OUT;
                 spaceReduce = 1;
             }
         }
     }
}


void fold() // Ex 1-22
{
    int lines = 1; // num of lines
    int count = 0; // elem in arr
    int indicesCount = 0;
    int c, i;

    char line[MAX_LINE];
    int indices[MAX_LINE];

    while ((c = getchar()) != EOF) {
        //reads in line
        if (c != '\n') {
            if (c == ' ' ||  c == '\t') {
                //will not use arr for solution, only indicesCount
                //can be used to place a new line at a specific index where space and tab occurs
                indices[indicesCount++] = count;
            }
            line[count++] = c;
        }
        //formats line into multiple lines
        else {
            line[count++] = c;
            if (count <= FOLD_MAX) {
                printf("%s", line);
            }
            else if (indicesCount > 0) {
                for (i = 0; i < count; ++i) {
                    //my solution new lines every space or tab
                    //modified solution could be to newline space or tab nearing FOLD_MAX using indices arr
                    if (line[i] == '\t' || line[i] == ' ') {
                        putchar('\n');
                    }
                    else {
                        putchar(line[i]);
                    }
                }
            }
            else {
                for (i = 0; i < count; ++i) {
                    if (i == (lines * FOLD_MAX)) {
                        printf("-\n");
                        ++lines;
                    }
                    putchar(line[i]);
                }
            }
            for (i = 0; i < count; ++i) {
                line[i] = '\0';
            }
            count = 0;
            indicesCount = 0;
            lines = 1;
        }
    }
}

/** Prompt:
 *      Write a program to remove all comments from a C program.
 *      Don't forget to handle quoted strings and character constants properly.
 *      C comments don't nest.
 */

/** CASES:
// *    Not required:
// *        single slash => prints syntax error
// *        non comment mode astrix => prints syntax error
 *      single line comment => removes until next line
 *      multi line comment => removes until * followed by / in consecutive order
 *      character constants: '\\' or "\\" => if quote or double quote, ignore until matching quote/ double quote
 */

/** PSEUDO CODE:
 *      slash = false, / => true. switches back to false if next char is not / or *
 *      astrix = false, multiComment && * => true. switches back to false next character
 *      singleComment = false switches to true when slash true and slash immediately follows
 *      multiComment = false switch true when slash true and astrix immediately follows
 *      quotes = false, ' => true. switches back to false when closing quote
 *      doubleQuotes = false, " => true. switches back to false when closing double quote
 *
 *      4 states:
 *          singleComment state -> prints nothing until \n
 *          multiComment state -> prints nothing until * and /
 *          double quotes -> prints nothing until double quotes
 *          single quotes -> prints nothing until single quotes
 *
 *      Read in characters.
 *
 *      //sets up comment states
 *          Check if not singleComment and not multiComment and not quote and not double quote
 *              check if char is slash and not slash
 *                  slash = true
 *              check if slash and char is astrix
 *                  slash = false
 *                  multiComment = true
 *              check if slash and char is slash
 *                  slash = false
 *                  singleComment = true
 *              else
 *                  slash = false
 *                  //checks for quotes and double quote
 *                  if char is quote
 *                      quote = true
 *                  if char is double quote
 *                      doubleQuotes = true
 *                  prints char
 *      //terminate quote state
 *          check if quote
 *              check if char is quote
 *                  quote = false
 *              print char
 *          check if doubleQuotes
 *              check if char is double quote
 *                  doubleQuote = false
 *              print char
 *      //terminate comment state
 *          Check if singleComment and \n
 *              singleComment = false
 *          check if multiComment
 *              check if astrix is false and char is astrix
 *                  astrix = true
 *              check if astrix is true
 *                  astrix is false
 *                  check if char is slash
 *                      multiComment = false
 *
 */

void removeComments() // Ex 1-23
{
    int c, slash = false, astrix = false, singleComment = false, multiComment = false, quote = false, doubleQuote = false;
    while ((c = getchar()) != EOF) {
        if (!singleComment && !multiComment && !quote && !doubleQuote) {
            if (c == '/' && !slash) {
                slash = true;
            }
            else if (slash && c == '*') {
                slash = false;
                multiComment = true;
            }
            else if (slash && c == '/') {
                slash = false;
                singleComment = true;
            }
            else {
                slash = 0;
                if (c == '\'') {
                    quote = true;
                }
                if (c == '\"') {
                    doubleQuote = true;
                }

                putchar(c);

            }
        }
        //ignores all characters until comment termination
        else if (singleComment) {
            if (c == '\n') {
                singleComment = false;
                putchar('\n');
            }
        }
        else if (multiComment) {
            if (c == '*') {
                astrix = true;
            }
            else if (astrix) {
                astrix = false;
                if (c == '/') {
                    multiComment = false;
                }
            }
        }
        //continues to print all characters inside quotes
        else {
            if (quote) {
                //quote termination
                if (c == '\'') {
                    quote = false;
                }
            }
            if (doubleQuote) {
                //double quote termination
                if (c == '\"') {
                    doubleQuote = false;
                }
            }
            putchar(c);
        }
    }

}


/** Prompt:
 *      Write a program to check a C program for rudimentary syntax errors like unmatched parentheses, brackets and braces.
 *      Don't forget about quotes, both single and double, escape sequences, and comments.
 *      (This program is hard if you do it in full generality.)
 */

/**
 * STATES:
 *      comment state
 *      quote state
 *          escape sequence
 *      normal state
 */

/** Only implemented with specs in prompt which is matching bracket, braces, parenthesis, quotes, comments, and escape sequence. Not assuming multiple nested brackets, braces, and parenthesis */
//A better implementation would be to use palindrome to consider multiple nested braces, brackets, and parenthesis
void syntaxError() //Ex 1-24
{
    int c;
    int slash = false;
    int backslash = false;
    int comment = false;
    int multiComment = false;
    int astrix = false;
    int quote = false;
    int doubleQuote = false;
    int bracket = false;
    int braces = false;
    int parenthesis = false;


    while ((c = getchar()) != EOF) {
        //can't enter comment state while in quote state
        if (!quote && !doubleQuote) {
            //initialize comment state
            if (!slash && c == '/') {
                slash = true;
            }
            else if (slash) {
                if (c == '/') {
                    comment = true;
                }
                if (c == '*') {
                    multiComment = true;
                }
            }
            //terminate comment state
            if (comment && c == '\n') {
                comment = false;
            }
            if (multiComment) {
                if (!astrix && c == '*') {
                    astrix = true;
                }
                else if (astrix) {
                    astrix = false;
                    if (c == '/') {
                        multiComment = false;
                    }
                }
            }
        }
        //can't enter quote state while in comment state
        if (!comment && !multiComment) {
            //initialize else terminate quote state
            if (c == '\'') {
                if (!quote && !doubleQuote) {
                    quote = true;
                }
                else if (doubleQuote) {
                    //unmatched quote
                    printf("EXPECTED DOUBLE QUOTE \n");
                }
                else {
                    quote = false;
                }
            }
            if (c == '\"') {
                if (!quote && !doubleQuote) {
                    doubleQuote = true;
                }
                else if (quote) {
                    //unmatched double quote
                    printf("EXPECTING QUOTE \n");
                }
                else {
                    doubleQuote = false;
                }
            }
        }
        //escape sequence check only in quote state
        if (quote || doubleQuote) {
            if (!backslash && c == '\\') {
                backslash = true;
            }
            else if (backslash) {
                backslash = false;
                if (c != 'b' && c != 't' && c != '\'' && c != '\"' && c != 'n' && c != 'f' && c != 'r' && c != '?' && c != 'a' && c != '\\') {
                    printf("INVALID ESCAPE SEQUENCE \n");
                }
            }
        }
        if (!comment && !multiComment && !quote && !doubleQuote) {
            if (!parenthesis && !bracket && !braces) {
                if (c == '{') {
                    braces = true;
                }
                if (c == '[') {
                    bracket = true;
                }
                if (c == '(') {
                    parenthesis = true;
                }
                if (c == '}' || c == ']' || c == ')') {
                    printf("INVALID START \n");
                }
            }
            if (parenthesis) {
                if (c == '}' || c == ']') {
                    parenthesis = false;
                    printf("INVALID PARENTHESIS PAIR \n");
                }
                if (c == ')') {
                    parenthesis = false;
                }
            }
            if (bracket) {
                if (c == '}' || c == ')') {
                    bracket = false;
                    printf("INVALID BRACKET PAIR \n");
                }
                if (c == ']') {
                    bracket = false;
                }
            }
            if (braces) {
                if (c == ')' || c == ']') {
                    braces = false;
                    printf("INVALID BRACES PAIR \n");
                }
                if (c == '}') {
                    braces = false;
                }
            }
        }
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
//    toEscapeSequence();
////    (page22)
//    wordCount();
//    wordNewLine();
//    countDigit();
//    wordLengthHistogram();
//    characterFrequency();
////    (page26)
//    callPower();
//    fahrenheitCelsiusAsFunction();
//    longestInputLine();
////    (page30)
//    longestInputLine2();
//    over80Characters();
//    deleteTrailBlankAndTabs();
//    reverseString();
//    detab();
//    entab();
////    page 34
//    fold();
//    removeComments();
//    syntaxError();
    return 0;
}


