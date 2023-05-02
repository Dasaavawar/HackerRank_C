// HackerRank - C - Introduction - II - Conditionals and Loops


/* 1. Conditionals and Loops - Conditional Statements in C */
/*
Objective

if and else are two of the most frequently used conditionals in C/C++, and they enable you to execute zero or one conditional statement among many such dependent conditional statements. We use them in the following ways:

  1.  if: This executes the body of bracketed code starting with statement1 if condition evaluates to true.

if (condition) {
    statement1;
    ...
}

  2.  if - else: This executes the body of bracketed code starting with statement1 if condition evaluates to true, or it executes the body of code starting with statement2 if condition evaluates to false. Note that only one of the bracketed code sections will ever be executed.

if (condition) {
    statement1;
    ...
}
else {
    statement2;
    ...
}

  3.  if - else if - else: In this structure, dependent statements are chained together and the condition for each statement is only checked if all prior conditions in the chain are evaluated to false. Once a condition evaluates to true, the bracketed code associated with that statement is executed and the program then skips to the end of the chain of statements and continues executing. If each condition in the chain evaluates to false, then the body of bracketed code in the else block at the end is executed.

    if(first condition) {
        ...
    }
    else if(second condition) {
        ...
    }
    .
    .
    .
    else if((n-1)'th condition) {
        ....
    }
    else {
        ...
    }

Task

Given a positive integer denoting n, do the following:

  *  If 1 ≤ n ≤ 9, print the lowercase English word corresponding to the number (e.g., one for 1, two for 2, etc.).
  *  If n > 9, print Greater than 9.

Input Format

The first line contains a single integer, n.

Constraints

  *  1 ≤ n ≤ 10^9
  
Output Format

If 1 ≤ n ≤ 9, then print the lowercase English word corresponding to the number (e.g., one for 1, two for 2, etc.); otherwise, print Greater than 9 instead.

Sample Input

5

Sample Output

five

Sample Input #01

8

Sample Output #01

eight

Sample Input #02

44

Sample Output #02

Greater than 9

*/
/* Solution */

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

int main()
{
    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    // Write Your Code Here
    if(n==1) {
        printf("one");
    } else if(n==2) {
        printf("two");
    } else if(n==3) {
        printf("three");
    } else if(n==4) {
        printf("four");
    } else if(n==5) {
        printf("five");
    } else if(n==6) {
        printf("six");
    } else if(n==7) {
        printf("seven");
    } else if(n==8) {
        printf("eight");
    } else if(n==9) {
        printf("nine");
    } else {
        printf("Greater than 9");
    }
    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}


/* 2. Conditionals and Loops - For Loop in C */
/*
Objective

In this challenge, you will learn the usage of the for loop, which is a programming language statement which allows code to be executed until a terminal condition is met. They can even repeat forever if the terminal condition is never met.

The syntax for the for loop is:

for ( <expression_1> ; <expression_2> ; <expression_3> )
    <statement>

  *  expression_1 is used for intializing variables which are generally used for controlling the terminating flag for the loop.
  *  expression_2 is used to check for the terminating condition. If this evaluates to false, then the loop is terminated.
  *  expression_3 is generally used to update the flags/variables.

The following loop initializes i to 0, tests that i is less than 10, and increments i at every iteration. It will execute 10 times.

for(int i = 0; i < 10; i++) {
    ...
}

Task

For each integer n in the interval [a, b] (given as input):

  *  If 1 ≤ n ≤ 9, then print the English representation of it in lowercase. That is "one" for 1, "two" for 2, and so on.
  *  Else if n > 9 and it is an even number, then print "even".
  *  Else if n > 9 and it is an odd number, then print "odd".

Input Format

The first line contains an integer, a.
The seond line contains an integer, b.

Constraints

Output Format

Print the appropriate English representation,even, or odd, based on the conditions described in the 'task' section.

Note: [a, b] = {x ∈ ℤ | a ≤ x ≤ b} = {a, a + 1, ..., b}

Sample Input

8
11

Sample Output

eight
nine
even
odd

*/
/* Solution */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	// Complete the code.
      
    char num_words[11][20] = {"", "one", "two", "three", "four","five", "six", "seven","eight","nine","ten"};
    
    for (int n=a; n<=b; n++) {
        if (n>=1 && n<=9) {
            printf("%s\n", num_words[n]);            
        } else if(n>9) {
            (n&0b1)? printf("odd \n") : printf("even \n");            
        }
    }

    return 0;
}


/* 3. Conditionals and Loops - Conditional Statements in C */
/*
Objective

The modulo operator, %, returns the remainder of a division. For example, 4 % 3 = 1 and 12 % 10 = 2. The ordinary division operator, /, returns a truncated integer value when performed on integers. For example, 5 / 3 = 1. To get the last digit of a number in base 10, use 10 as the modulo divisor.

Task

Given a five digit integer, print the sum of its digits.

Input Format

The input contains a single five digit number, n.

Constraints

  *  10000 ≤ n ≤ 99999

Output Format

Print the sum of the digits of the five digit number.

Sample Input 0

10564

Sample Output 0

16

*/
/* Solution */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.
    int sum;
    for(int i = 0; n > 0; i++){
        sum += n % 10;
        n = n / 10;
    }
    printf("%d", sum);
    return 0;
}


/* 4. Conditionals and Loops - Bitwise Operators */
/*
In this challenge, you will use logical bitwise operators. All data is stored in its binary representation. The logical operators, and C language, use 1 to represent true and 0 to represent false. The logical operators compare bits in two numbers and return true or false, 0 or 1, for each bit compared.

  *  Bitwise AND operator & The output of bitwise AND is 1 if the corresponding bits of two operands is 1. If either bit of an operand is 0, the result of corresponding bit is evaluated to 0. It is denoted by &.

  *  Bitwise OR operator | The output of bitwise OR is 1 if at least one corresponding bit of two operands is 1. It is denoted by |.

  *  Bitwise XOR (exclusive OR) operator ^ The result of bitwise XOR operator is 1 if the corresponding bits of two operands are opposite. It is denoted by ⊕.

For example, for integers 3 and 5,

3 = 00000011 (In Binary)
5 = 00000101 (In Binary)

AND operation        OR operation        XOR operation
  00000011             00000011            00000011
& 00000101           | 00000101          ^ 00000101
  ________             ________            ________
  00000001  = 1        00000111  = 7       00000110  = 6

You will be given an integer n, and a threshold, k. For each number i from 1 through n, find the maximum value of the logical AND, OR and XOR when compared against all int n that are greater than i.

Consider a value only if the comparison returns are less than k. Print the results of the and, or and exclusive or comparisons on separate lines, in that order.

Example

n = 3
k = 3

The results of the comparisons are below:

a b   and or xor
1 2   0   3  3
1 3   1   3  2
2 3   2   3  1

For the and comparison, the maximum is 2. For the or comparison, none of the values is less than k, so the maximum is 0. For the xor comparison, the maximum value less than k is 2. The function should print:

2
0
2

Function Description

Complete the calculate_the_maximum function in the editor below.

calculate_the_maximum has the following parameters:

  *  int n: the highest number to consider
  *  int k: the result of a comparison must be lower than this number to be considered

Prints

Print the maximum values for the and, or and xor comparisons, each on a separate line.

Input Format

The only line contains 2 space-separated integers, n and k.

Constraints

  *  2 ≤ n ≤ 10^3
  *  2 ≤ k ≤ n

Sample Input 0

5 4

Sample Output 0

2
3
3

Explanation 0

n = 5, k = 4
S = {1, 2, 3, 4, 5}
All possible values of a and b are:

  1.  a = 1, b = 2; a & b = 0; a | b = 3; a ⊕ b = 3;
  2.  a = 1, b = 3; a & b = 1; a | b = 3; a ⊕ b = 2;
  3.  a = 1, b = 4; a & b = 0; a | b = 5; a ⊕ b = 5;
  4.  a = 1, b = 5; a & b = 1; a | b = 5; a ⊕ b = 4;
  5.  a = 2, b = 3; a & b = 2; a | b = 3; a ⊕ b = 1;
  6.  a = 2, b = 4; a & b = 0; a | b = 6; a ⊕ b = 6;
  7.  a = 2, b = 5; a & b = 0; a | b = 7; a ⊕ b = 7;
  8.  a = 3, b = 4; a & b = 0; a | b = 7; a ⊕ b = 7;
  9.  a = 3, b = 5; a & b = 1; a | b = 7; a ⊕ b = 6;
  10.  a = 4, b = 5; a & b = 4; a | b = 5; a ⊕ b = 1;  

  *  The maximum possible value of a & b that is also < (k = 4) is 2, so we print 2 on first line.
  *  The maximum possible value of a | b that is also < (k = 4) is 3, so we print 3 on second line.
  *  The maximum possible value of a ⊕ b that is also < (k = 4) is 3, so we print 3 on third line.
*/
/* Solution */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

void calculate_the_maximum(int n, int k) {
  //Write your code here.
  int a = 0, b = 0, c = 0;
  for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
            (a < (i&j) && (i&j) < k) ? a = (i&j) : a;
            (b < (i|j) && (i|j) < k) ? b = (i|j) : b;
            (c < (i^j) && (i^j) < k) ? c = (i^j) : c;
        }
    }
    printf("%d\n %d\n %d\n", a, b, c);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}


/* 5. Conditionals and Loops - Printing Pattern Using Loops */
/*
Print a pattern of numbers from 1 to n as shown below. Each of the numbers is separated by a single space.

                            4 4 4 4 4 4 4  
                            4 3 3 3 3 3 4   
                            4 3 2 2 2 3 4   
                            4 3 2 1 2 3 4   
                            4 3 2 2 2 3 4   
                            4 3 3 3 3 3 4   
                            4 4 4 4 4 4 4   

Input Format

The input will contain a single integer n.

Constraints

  *  1 ≤ n ≤ 1000

Sample Input 0

2

Sample Output 0

2 2 2
2 1 2
2 2 2

Sample Input 1

5

Sample Output 1

5 5 5 5 5 5 5 5 5 
5 4 4 4 4 4 4 4 5 
5 4 3 3 3 3 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 2 1 2 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 3 3 3 3 4 5 
5 4 4 4 4 4 4 4 5 
5 5 5 5 5 5 5 5 5

Sample Input 2

7

Sample Output 2

7 7 7 7 7 7 7 7 7 7 7 7 7 
7 6 6 6 6 6 6 6 6 6 6 6 7 
7 6 5 5 5 5 5 5 5 5 5 6 7 
7 6 5 4 4 4 4 4 4 4 5 6 7 
7 6 5 4 3 3 3 3 3 4 5 6 7 
7 6 5 4 3 2 2 2 3 4 5 6 7 
7 6 5 4 3 2 1 2 3 4 5 6 7 
7 6 5 4 3 2 2 2 3 4 5 6 7 
7 6 5 4 3 3 3 3 3 4 5 6 7 
7 6 5 4 4 4 4 4 4 4 5 6 7 
7 6 5 5 5 5 5 5 5 5 5 6 7 
7 6 6 6 6 6 6 6 6 6 6 6 7 
7 7 7 7 7 7 7 7 7 7 7 7 7 

*/
/* Solution */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int min(int a, int b) {
        if (a<b) return a;
        return b;
}

int main() {

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    for (int i = 1; i <= 2*n - 1; i++) {
        for (int j = 1; j <= 2*n - 1; j++) {
            int min_dis = min(min(i - 1, 2*n - 1 - i), min(j - 1, 2*n- 1 - j));
            printf("%d ", n - min_dis);
        }
        printf("\n");
    }
    return 0;
}


