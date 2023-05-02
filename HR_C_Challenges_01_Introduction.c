// HackerRank - C - Introduction - I - Strings


/* 1. Introduction - "Hello World!" in C */
/*
Objective

In this challenge, we will learn some basic concepts of C that will get you started with the language. You will need to use the same syntax to read input and write output in many C challenges. As you work through these problems, review the code stubs to learn about reading from stdin and writing to stdout.

Task

This challenge requires you to print "Hello, World!" on a single line, and then print the already provided input string to stdout (https://en.wikipedia.org/wiki/Standard_streams#Standard_output_.28stdout.29). If you are not familiar with C, you may want to read about the printf() command.

Example

s = "Life is beautiful"

The required output is:

Hello, World!  
Life is beautiful  

Function Description

Complete the main() function below.

The main() function has the following input:

  *  string s: a string

Prints

  *  *two strings: * "Hello, World!" on one line and the input string on the next line.

Input Format

There is one line of text, s.

Sample Input 0

Welcome to C programming.

Sample Output 0

Hello, World!
Welcome to C programming.

*/
/* Solution */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	
    char s[100];
    scanf("%[^\n]%*c", &s);
  	
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    printf("Hello, World!\n%s", s);
    return 0;
}


/* 2. Introduction - Playing With Characters */
/*
Objective

This challenge will help you to learn how to take a character, a string and a sentence as input in C.

To take a single character ch as input, you can use scanf("%c", &ch ); and printf("%c", ch) writes a character specified by the argument char to stdout

char ch;
scanf("%c", &ch);
printf("%c", ch);

This piece of code prints the character ch.

You can take a string as input in C using scanf(“%s”, s). But, it accepts string only until it finds the first space.

In order to take a line as input, you can use scanf("%[^\n]%*c", s); where s is defined as char s[MAX_LEN] where MAX_LEN is the maximum size of n. Here, [] is the scanset character. ^\n stands for taking input until a newline isn't encountered. Then, with this %*c, it reads the newline character and here, the used * indicates that this newline character is discarded.

Note: The statement: scanf("%[^\n]%*c", s); will not work because the last statement will read a newline character, \n, from the previous line. This can be handled in a variety of ways. One way is to use scanf("\n"); before the last statement.

Task

You have to print the character, ch, in the first line. Then print s in next line. In the last line print the sentence, sen.

Input Format

First, take a character, ch as input.
Then take the string, s as input.
Lastly, take the sentence sen as input.

Constraints

Strings for s and sen will have fewer than 100 characters, including the newline.

Output Format

Print three lines of output. The first line prints the character, ch.
The second line prints the string, s.
The third line prints the sentence, sen.

Sample Input 0

C
Language
Welcome To C!!

Sample Output 0

C
Language
Welcome To C!!

*/
/* Solution */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char ch, s[100], sen[101];
    scanf("%c", &ch);
    scanf("%s\n", s);
    scanf("%[^\n]%*c", sen);
    printf("%c\n%s\n%s", ch, s, sen);
    return 0;
}


/* 3. Introduction - Sum and Difference of Two Numbers */
/*
Objective

The fundamental data types in c are int, float and char. Today, we're discussing int and float data types.

The printf() function prints the given statement to the console. The syntax is printf("format string",argument_list);. In the function, if we are using an integer, character, string or float as argument, then in the format string we have to write %d (integer), %c (character), %s (string), %f (float) respectively.

The scanf() function reads the input data from the console. The syntax is scanf("format string",argument_list);. For ex: The scanf("%d",&number) statement reads integer number from the console and stores the given value in variable number.

To input two integers separated by a space on a single line, the command is scanf("%d %d", &n, &m), where n and m are the two integers.

Task

Your task is to take two numbers of int data type, two numbers of float data type as input and output their sum:

  1.  Declare 4 variables: two of type int and two of type float.
  2.  Read 2 lines of input from stdin (according to the sequence given in the 'Input Format' section below) and initialize your 4 variables.
  3.  Use the + and - operator to perform the following operations:
      *  Print the sum and difference of two int variable on a new line.
      *  Print the sum and difference of two float variable rounded to one decimal place on a new line. 

Input Format

The first line contains two integers.
The second line contains two floating point numbers.

Constraints

  *  1 ≤ integer variables ≤ 10^4
  *  1 ≤ float variables ≤ 10^4

Output Format

Print the sum and difference of both integers separated by a space on the first line, and the sum and difference of both float (scaled to 1 decimal place) separated by a space on the second line.

Sample Input

10 4
4.0 2.0

Sample Output

14 6
6.0 2.0

Explanation

When we sum the integers 10 and 4, we get the integer 14. When we subtract the second number 4 from the first number 10, we get 6 as their difference.
When we sum the floating-point numbers 4.0 and 2.0, we get 6.0. When we subtract the second number 2.0 from the first number 4.0, we get 2.0 as their difference. 
*/
/* Solution */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n;
    int m;
    float f;
    float g;
	scanf("%d %d", &n, &m);
    scanf("%f %f", &f, &g);
    printf("%d %d\n", n + m, n - m);
    printf("%.1f %.1f\n", f + g, f - g);
    return 0;
}


/* 4. Introduction - Functions in C */
/*
Objective

In this challenge, you will learn simple usage of functions in C. Functions are a bunch of statements grouped together. A function is provided with zero or more arguments, and it executes the statements on it. Based on the return type, it either returns nothing (void) or something.

A sample syntax for a function is

	return_type function_name(arg_type_1 arg_1, arg_type_2 arg_2, ...) {
    	...
        ...
        ...
        [if return_type is non void]
        	return something of type `return_type`;
    }

For example, a function to read four variables and return the sum of them can be written as

	int sum_of_four(int a, int b, int c, int d) {
    	int sum = 0;
        sum += a;
        sum += b;
        sum += c;
        sum += d;
        return sum;
    }

+= : Add and assignment operator. It adds the right operand to the left operand and assigns the result to the left operand.

a += b is equivalent to a = a + b;

Task

Write a function int max_of_four(int a, int b, int c, int d) which reads four arguments and returns the greatest of them.

Note

There is not built in max function in C. Code that will be reused is often put in a separate function, e.g. int max(x, y) that returns the greater of the two values.

Input Format

Input will contain four integers - a, b, c, d, one on each line.

Output Format

Print the greatest of the four integers.
Note: I/O will be automatically handled.

Sample Input

3
4
6
5

Sample Output

6

*/
/* Solution */

#include <stdio.h>
/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/
int max_of_four(int a, int b, int c, int d) {
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;
    return max;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}


/* 5. Strings - Pointers in C */
/*
Objective

In this challenge, you will learn to implement the basic functionalities of pointers in C. A pointer (https://en.wikipedia.org/wiki/Pointer_%28computer_programming%29) in C is a way to share a memory address among different contexts (primarily functions). They are primarily used whenever a function needs to modify the content of a variable that it does not own.

In order to access the memory address of a variable, val, prepend it with & sign. For example, &val returns the memory address of val.

This memory address is assigned to a pointer and can be shared among various functions. For example, int*p = &val will assign the memory address of val to pointer p. To access the content of the memory to which the pointer points, prepend it with a *. For example, *p will return the value reflected by val and any modification to it will be reflected at the source (val).

	void increment(int *v) {
        (*v)++; 
    }
      	int main() {
        int a;
        scanf("%d", &a);
        increment(&a);
        printf("%d", a);
    	return 0;      
    }     

Task

Complete the function void update(int *a,int *b). It receives two integer pointers, int* a and int* b. Set the value of a to their sum, and b to their absolute difference. There is no return value, and no return statement is needed.

  *  a' = a + b
  *  b' = |a - b|

Input Format

The input will contain two integers, a and b, separated by a newline.

Output Format

Modify the two values in place and the code stub main() will print their values.

Note: Input/ouput will be automatically handled. You only have to complete the function described in the 'task' section.

Sample Input

4
5

Sample Output

9
1

Explanation

  *  a' = 4 + 5 = 9
  *  b' = |4 - 5| = 1
*/
/* Solution */

#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
    int sum = *a + *b;
    *b = abs(*a-*b);
    *a = sum;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}


