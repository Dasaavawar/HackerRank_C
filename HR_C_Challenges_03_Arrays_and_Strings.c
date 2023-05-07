// HackerRank - C - Introduction - III - Arrays and Strings


/* 1. Arrays and Strings - 1D Arrays in C */
/*
An array is a container object that holds a fixed number of values of a single type. To create an array in C, we can do int arr[n];. Here, arr, is a variable array which holds up to 10 integers. The above array is a static array that has memory allocated at compile time. A dynamic array can be created in C, using the malloc function and the memory is allocated on the heap at runtime. To create an integer array, arr of size n, int *arr = (int*)malloc(n * sizeof(int)), where arr points to the base address of the array. When you have finished with the array, use free(arr) to deallocate the memory.

In this challenge, create an array of size n dynamically, and read the values from stdin. Iterate the array calculating the sum of all elements. Print the sum and free the memory where the array is stored.

While it is true that you can sum the elements as they are read, without first storing them to an array, but you will not get the experience working with an array. Efficiency will be required later.

Input Format

The first line contains an integer, n.
The next line contains n space-separated integers.

Constraints

  *  1 ≤ n ≤ 1000
  *  1 ≤ a[i] ≤ 1000

Output Format

Print the sum of the integers in the array.

Sample Input 0

6
16 13 7 2 1 12 

Sample Output 0

51

Sample Input 1

7
1 13 15 20 12 13 2 

Sample Output 1

76

*/
/* Solution */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    scanf("%d", &n);
    
    int vector[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &vector[i]);
    }
    
    int sum;
    
    for(int j = 0; j < n; j++){
        sum += vector[j];
    }
    printf("%d", sum);
    return 0;
}


/* 2. Arrays and Strings - Array Reversal */
/*
Given an array, of size n, reverse it.

Example: If array, arr = [1, 2, 3, 4, 5], after reversing it, the array should be, arr = [5, 4, 3, 2, 1].

Input Format

The first line contains an integer, n, denoting the size of the array. The next line contains n space-separated integers denoting the elements of the array.

Constraints

  *  1 ≤ n ≤ 1000
  *  1 ≤ arr_i ≤ 1000 where arr_i is the ith element of the array.

Output Format

The output is handled by the code given in the editor, which would print the array.

Sample Input 0

6
16 13 7 2 1 12 

Sample Output 0

12 1 2 7 13 16 

Explanation 0

Given array, arr = [16, 13, 7, 2, 1, 12]. After reversing the array, arr = [12, 1, 2, 7, 13, 16]

Sample Input 1

7
1 13 15 20 12 13 2 

Sample Output 1

2 13 12 20 15 13 1 

Sample Input 2

8
15 5 16 15 17 11 5 11 

Sample Output 2

11 5 11 17 15 16 5 15 

*/
/* Solution */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }


    /* Write the logic to reverse the array. */

    for(i=(num-1); i >= 0; i--)
        printf("%d ", *(arr + i));
    return 0;
}


/* 3. Arrays and Strings - Printing Tokens */
/*
Given a sentence, s, print each word of the sentence in a new line.

Input Format

The first and only line contains a sentence, s.

Constraints

  *  1 ≤ len(s) ≤ 1000

Output Format

Print each word of the sentence in a new line.

Sample Input 0

This is C 

Sample Output 0

This
is
C

Explanation 0

In the given string, there are three words ["This", "is", "C"]. We have to print each of these words in a new line.

Sample Input 1

Learning C is fun

Sample Output 1

Learning
C
is
fun

Sample Input 2

How is that

Sample Output 2

How
is
that

*/
/* Solution */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    
    //Write your logic to print the tokens of the sentence here.
    for(int i=0; i<strlen(s);i++){
        if(s[i]==' '){
            printf("\n");
        }
        else{
        printf("%c", s[i]);
        }
    }
    return 0;
}


/* 4. Arrays and Strings - Digit Frequency */
/*
Given a string, s, consisting of alphabets and digits, find the frequency of each digit in the given string.

Input Format

The first line contains a string, num which is the given number.

Constraints

  *  1 ≤ len(num) ≤ 1000
  *  All the elements of num are made of english alphabets and digits.

Output Format

Print ten space-separated integers in a single line denoting the frequency of each digit from 0 to 9.

Sample Input 0

a11472o5t6

Sample Output 0

0 2 1 0 1 1 1 1 0 0 

Explanation 0

In the given string:

  *  1 occurs two times.
  *  2, 4, 5, 6 and 7 occur one time each.
  *  The remaining digits 0, 3, 8 and 9 don't occur at all.

Sample Input 1

lw4n88j12n1

Sample Output 1

0 2 1 0 1 0 0 0 2 0 

Sample Input 2

1v88886l256338ar0ekk

Sample Output 2

1 1 1 2 0 1 2 0 5 0 

*/
/* Solution */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    
    int arr[10] = {0,0,0,0,0,0,0,0,0,0};
    
    for(int i=0; i<strlen(s); i++){
        if (s[i]=='0') {
            arr[0]++;
        } else if (s[i]=='1') {
            arr[1]++;            
        } else if (s[i]=='2') {
            arr[2]++;            
        } else if (s[i]=='3') {
            arr[3]++;            
        } else if (s[i]=='4') {
            arr[4]++;            
        } else if (s[i]=='5') {
            arr[5]++;            
        } else if (s[i]=='6') {
            arr[6]++;            
        } else if (s[i]=='7') {
            arr[7]++;            
        } else if (s[i]=='8') {
            arr[8]++;            
        } else if (s[i]=='9') {
            arr[9]++;            
        }
    }
    
    for (int j=0; j<10; j++) {
        printf("%d", arr[j]);
        printf(" ");
    }
    
    return 0;
}


/* 5. Arrays and Strings - Dynamic Array in C */
/*
Snow Howler is the librarian at the central library of the city of HuskyLand. He must handle requests which come in the following forms:

1 x y : Insert a book with y pages at the end of the xth shelf.

2 x y : Print the number of pages in the yth book on the xth shelf.

3 x : Print the number of books on the xth shelf.

Snow Howler has got an assistant, Oshie, provided by the Department of Education. Although inexperienced, Oshie can handle all of the queries of types 2 and 3.

Help Snow Howler deal with all the queries of type 1.

Oshie has used two arrays:

int* total_number_of_books;
// This stores the total number of books on each shelf.

int** total_number_of_pages;
// This stores the total number of pages in each book of each shelf.
// The rows represent the shelves and the columns represent the books.

Input Format

The first line contains an integer total_number_of_shelves, the number of shelves in the library.
The second line contains an integer total_number_of_queries, the number of requests.
Each of the following total_number_of_queries lines contains a request in one of the three specified formats.

Constraints

  *  1 ≤ total_number_of_shelves ≤ 10^5
  *  1 ≤ total_number_of_queries ≤ 10^5
  *  For each query of the second type, it is guaranteed that a book is present on the xth shelf at yth index.
  *  0 ≤ x < total_number_of_shelves
  *  Both the shelves and the books are numbered starting from 0.
  *  Maximum number of books per shelf ≤ 1100.

Output Format

Write the logic for the requests of type 1. The logic for requests of types 2 and 3 are provided.

Sample Input 0

5
5
1 0 15
1 0 20
1 2 78
2 2 0
3 0

Sample Output 0

78
2

Explanation 0

There are 5 shelves and 5 requests, or queries.
- 1 Place a 15 page book at the end of shelf 0.
- 2 Place a 20 page book at the end of shelf 0.
- 3 Place a 78 page book at the end of shelf 2.
- 4 The number of pages in the 0th book on the 2nd shelf is 78.
- 5 The number of books on the 0th shelf is 2. 
*/
/* Solution */

#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;

int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    total_number_of_books = (int*) calloc(total_number_of_shelves,sizeof(int));
    total_number_of_pages = (int**) calloc(total_number_of_shelves,sizeof(int*));
    for (int i = 0; i < total_number_of_shelves; i++)
    {
        *(total_number_of_pages+i) = calloc(1100,sizeof(int));
    }
    
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);

    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            /*
             * Process the query of first type here.
            */
            int x, y;
            scanf("%d %d", &x, &y);
            *(*(total_number_of_pages+x)+*(total_number_of_books+x)) =y;
            *(total_number_of_books+x) +=1;
        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}


