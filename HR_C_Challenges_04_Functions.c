// HackerRank - C - Challenges - IV - Functions


/* 1. Functions - Calculate the Nth term */
/*
Objective
This challenge will help you learn the concept of recursion.

A function that calls itself is known as a recursive function. The C programming language supports recursion. But while using recursion, one needs to be careful to define an exit condition from the function, otherwise it will go into an infinite loop.

To prevent infinite recursion, if... else statement (or similar approach) can be used where one branch makes the recursive call and other doesn't.

void recurse() {
    .....
    recurse()  //recursive call
    .....
}
int main() {
    .....
    recurse(); //function call
    .....
}

Task

There is a series, S, where the next term is the sum of pervious three terms. Given the first three terms of the series, a, b, and c respectively, you have to output the nth term of the series using recursion.

Recursive method for calculating nth term is given below.


S(n) = { a, 				n = 1
       { b, 				n = 2
       { c, 				n = 3
       { S(n-1) + S(n-2) + S(n-3) 	otherwise


Input Format

  *  The first line contains a single integer, n.
  *  The next line contains 3 space-separated integers, a, b, and c.

Constraints

Output Format

Print the nth term of the series, S(n).

Sample Input 0

5
1 2 3

Sample Output 0

11

Explanation 0

Consider the following steps:

  1.  S(1) = 1
  2.  S(2) = 2
  3.  S(3) = 3
  4.  S(4) = S(3) + S(2) + S(1)
  5.  S(5) = S(4) + S(3) + S(2)
  
From steps 1, 2, 3, and 4, we can say S(4) = 3 + 2 + 1 = 6; then using the values from step 2, 3, 4, and 5, we get S(5) = 6 + 3 + 2 = 11. Thus, we print 11 as our answer.
*/
/* Solution */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

int find_nth_term(int n, int a, int b, int c) {
  //Write your code here.
  if (n == 1) {
      return a;
  } else if (n == 2) {
      return b;
  } else if (n == 3) {
      return c;
  } else {
      return find_nth_term(n - 1, a, b, c) + find_nth_term(n - 2, a, b, c) + find_nth_term(n - 3, a, b, c);
  }
}

int main() {
    int n, a, b, c;
  
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);
 
    printf("%d", ans); 
    return 0;
}


/* 2. Functions - Students Marks Sum */
/*
You are given an array of integers, marks, denoting the marks scored by students in a class.

  *  The alternating elements marks_0, marks_2, marks_4 and so on denote the marks of boys.
  *  Similarly, marks_1, marks_3, marks_5 and so on denote the marks of girls.

The array name, marks, works as a pointer which stores the base address of that array. In other words, marks contains the address where marks_0 is stored in the memory.

For example, let marks = [3, 2, 5] and marks stores 0x7fff9575c05f. Then, 0x7fff9575c05f is the memory address of marks_0.

[/data/Students_Marks_Sum.png]

(https://s3.amazonaws.com/hr-assets/0/1525261282-328cd090eb-UntitledDiagram9.png)

Function Description

Complete the function, marks_summation in the editor below.

marks_summation has the following parameters:

  *  int marks[number_of_students]: the marks for each student
  *  int number_of_students: the size of marks[]
  *  char gender: either 'g' or 'b'

Returns

  *  int: the sum of marks for boys if gender = b, or of marks of girls if gender = g
  
Input Format

  *  The first line contains number_of_students, denoting the number of students in the class, hence the number of elements in marks.
  *  Each of the number_of_students subsequent lines contains marks_i.
  *  The next line contains genders.

Constraints

  *  1 ≤ number_of_students ≤ 10^3
  *  1 ≤ marks_i ≤ 10^3 (where 0 ≤ i ≤ number_of_students)
  *  gender = g or b

Sample Input 0

3
3
2
5
b

Sample Output 0

8

Explanation 0

marks = [3, 2, 5] and gender = b.

So, marks_0 + marks_2 = 3 + 5 = 8.

Sample Input 1

5
1
2
3
4
5
g

Sample Output 1

6

Explanation 1

marks = [1, 2, 3, 4, 5] and = g.

So, sum = marks_1 + marks_3 = 2 + 5 = 8.

Sample Input 2

1
5
g

Sample Output 2

0

Explanation 2

marks = [5] and gender = g.

Here, marks_1 does not exist. So, sum = 0.
*/
/* Solution */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Complete the following function.

int marks_summation(int* marks, int number_of_students, char gender) {
  //Write your code here.
  int i, sum = 0;
  for (i = (gender == 'b' ? 0 : 1); i < number_of_students; i = i + 2) {
      sum += *(marks + i);
  }
  return sum;
}

int main() {
    int number_of_students;
    char gender;
    int sum;
  
    scanf("%d", &number_of_students);
    int *marks = (int *) malloc(number_of_students * sizeof (int));
 
    for (int student = 0; student < number_of_students; student++) {
        scanf("%d", (marks + student));
    }
    
    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    free(marks);
 
    return 0;
}


/* 3. Functions - Permutations of Strings */
/*
Strings are usually ordered in lexicographical order. That means they are ordered by comparing their leftmost different characters. For example, abc < abd because c < d. Also z > yyy because z > y. If one string is an exact prefix of the other it is lexicographically smaller, e.g., gh < ghij.

Given an array of strings sorted in lexicographical order, print all of its permutations in strict lexicographical order. If two permutations look the same, only print one of them. See the 'note' below for an example.

Complete the function next_permutation which generates the permutations in the described order.

For example, s = [ab, bc, cd]. The six permutations in correct order are:

ab bc cd
ab cd bc
bc ab cd
bc cd ab
cd ab bc
cd bc ab

Note: There may be two or more of the same string as elements of s.
For example, s = [ab, ab, bc]. Only one instance of a permutation where all elements match should be printed. In other words, if s[0] == s[1], then print either s[0] s[1] or s[1] s[0] but not both.

A three element array having three distinct elements has six permutations as shown above. In this case, there are three matching pairs of permutations where s[0] = ab and s[1] = ab are switched. We only print the three visibly unique permutations:

ab ab bc
ab bc ab
bc ab ab

Input Format

The first line of each test file contains a single integer n, the length of the string array s.

Each of the next n lines contains a string s[i].

Constraints

  *  2 ≤ n ≤ 9
  *  1 ≤ [s[i]] ≤ 10
  *  s[i] contains only lowercase English letters.

Output Format

Print each permutation as a list of space-separated strings on a single line.

Sample Input 0

2
ab
cd

Sample Output 0

ab cd
cd ab

Sample Input 1

3
a
bc
bc

Sample Output 1

a bc bc
bc a bc
bc bc a

Explanation 1

This is similar to the note above. Only three of the six permutations are printed to avoid redundancy in output.
*/
/* Solution */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
	/**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
	*/
    int i=n-1;
    while(i>0 && strcmp(s[i], s[i-1])<=0) i--;
    if(i==0) return 0;
    
    int j=n-1;;
    while(j>=i && strcmp(s[j], s[i-1])<=0) j--; 
    char *a=s[i-1];
    s[i-1]=s[j];
    s[j]=a;
    
    j=n-1;
    while(i<j){
        a=s[i];
        s[i]=s[j];
        s[j]=a;
        i++; j--;
    }
    return 1;
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}


/* 4. Functions - Sorting Array of Strings */
/*
To sort a given array of strings into lexicographically increasing order or into an order in which the string with the lowest length appears first, a sorting function with a flag indicating the type of comparison strategy can be written. The disadvantage with doing so is having to rewrite the function for every new comparison strategy.

A better implementation would be to write a sorting function that accepts a pointer to the function that compares each pair of strings. Doing this will mean only passing a pointer to the sorting function with every new comparison strategy.

Given an array of strings, you need to implement a string_sort function which sorts the strings according to a comparison function, i.e, you need to implement the function :

void string_sort(const char **arr,const int cnt, int (*cmp_func)(const char* a, const char* b)){
    
}

The arguments passed to this function are:

  *  an array of strings : arr
  *  length of string array: count
  *  pointer to the string comparison function: cmp_func

You also need to implement the following four string comparison functions:

  *  int lexicographic_sort (char*, char*) to sort the strings in lexicographically non-decreasing order.

  *  int lexicographic_sort_reverse (char*, char*) to sort the strings in lexicographically non-increasing order.
  
  *  int sort_by_number_of_distinct_characters (char*, char*) to sort the strings in non-decreasing order of the number of distinct characters present in them. If two strings have the same number of distinct characters present in them, then the lexicographically smaller string should appear first.

  *  int sort_by_length (char*, char*) to sort the strings in non-decreasing order of their lengths. If two strings have the same length, then the lexicographically smaller string should appear first.

Input Format

You just need to complete the function string\_sort and implement the four string comparison functions.

Constraints

  *  No. of Strings
  *  Total Length of all the strings
  *  You have to write your own sorting function and you cannot use the inbuilt qsort function
  *  The strings consists of lower-case English Alphabets only.

Output Format

The locked code-stub will check the logic of your code. The output consists of the strings sorted according to the four comparsion functions in the order mentioned in the problem statement.

Sample Input 0

4
wkue
qoi
sbv
fekls

Sample Output 0

fekls
qoi
sbv
wkue

wkue
sbv
qoi
fekls

qoi
sbv
wkue
fekls

qoi
sbv
wkue
fekls

*/
/* Solution */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return -strcmp(a, b);
}

int unique_characters(const char *arr){
    int uniqeCharacters = 0;      
    int characters[26] = {0};
    int i = -1;
    while(++i < strlen(arr))
        characters[arr[i]-'a']++;
    for(i = 0 ; i < 26 ; i++)
        if(characters[i])   uniqeCharacters++;
    return uniqeCharacters;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int cmp = unique_characters(a) - unique_characters(b);
    if(cmp == 0)      
        cmp = lexicographic_sort(a,b);         
    return cmp;
}

int sort_by_length(const char* a, const char* b) {
    if(strlen(a)==strlen(b))
    {
        return strcmp(a,b)>0;
    }
    else {
        return strlen(a) < strlen(b )? -1 : 1;
    }
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for (int i = 0; i < len - 1; i++) {
        for (int j = i+1; j < len; j++) {
            if (cmp_func(arr[i], arr[j]) > 0) {
                char* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}


/* 5. Functions - Variadic functions in C */
/*
Variadic functions are functions which take a variable number of arguments. In C programming, a variadic function will contribute to the flexibility of the program that you are developing.

The declaration of a variadic function starts with the declaration of at least one named variable, and uses an ellipsis as the last parameter, e.g.

int printf(const char* format, ...);

In this problem, you will implement three variadic functions named
sum(), min() and max() to calculate sums, minima, maxima of a variable number of arguments. The first argument passed to the variadic function is the count of the number of arguments, which is followed by the arguments themselves.

Input Format

  *  The first line of the input consists of an integer number_of_test_cases.
  *  Each test case tests the logic of your code by sending a test implementation of 3, 5 and 10 elements respectively.
  *  You can test your code against sample/custom input.
  *  The error log prints the parameters which are passed to the test implementation. It also prints the sum, minimum element and maximum element corresponding to your code.

Constraints

  *  1 ≤ number_of_test_cases ≤ 50
  *  1 ≤ element ≤ 10000000

Output Format

"Correct Answer" is printed corresponding to each correct execution of a test implementation."Wrong Answer" is printed otherwise.

Sample Input 0

1

Sample Output 0

Correct Answer
Correct Answer
Correct Answer

*/
/* Solution */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ELEMENT 1
#define MAX_ELEMENT 1000000

int  sum (int count,...) {
    int total = 0;
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++) {
        int num = va_arg(args, int);
        total += num;
    }

    va_end(args);
    return total;
}

int min(int count,...) {
    int n;
    va_list args;
    va_start(args, count);
        
    for(int i= 0; i< count; i++){
        int num = va_arg(args, int);
        if (num < n){
            n = num;
        }
    }
    va_end(args);
    return n;
}

int max(int count,...) {
    int m;
    va_list args;
    va_start(args, count);
    
    for(int i= 0; i< count; i++){
        int num = va_arg(args, int);
        if (num > m){
            m = num;
        }
    }
    va_end(args);
    return m; 
}

int test_implementations_by_sending_three_elements() {
    srand(time(NULL));
    
    int elements[3];
    
    elements[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    
    fprintf(stderr, "Sending following three elements:\n");
    for (int i = 0; i < 3; i++) {
        fprintf(stderr, "%d\n", elements[i]);
    }
    
    int elements_sum = sum(3, elements[0], elements[1], elements[2]);
    int minimum_element = min(3, elements[0], elements[1], elements[2]);
    int maximum_element = max(3, elements[0], elements[1], elements[2]);

    fprintf(stderr, "Your output is:\n");
    fprintf(stderr, "Elements sum is %d\n", elements_sum);
    fprintf(stderr, "Minimum element is %d\n", minimum_element);
    fprintf(stderr, "Maximum element is %d\n\n", maximum_element);
    
    int expected_elements_sum = 0;
    for (int i = 0; i < 3; i++) {
        if (elements[i] < minimum_element) {
            return 0;
        }
        
        if (elements[i] > maximum_element) {
            return 0;
        }
        
        expected_elements_sum += elements[i];
    }
    
    return elements_sum == expected_elements_sum;
}

int test_implementations_by_sending_five_elements() {
    srand(time(NULL));
    
    int elements[5];
    
    elements[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[3] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[4] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    
    fprintf(stderr, "Sending following five elements:\n");
    for (int i = 0; i < 5; i++) {
        fprintf(stderr, "%d\n", elements[i]);
    }
    
    int elements_sum = sum(5, elements[0], elements[1], elements[2], elements[3], elements[4]);
    int minimum_element = min(5, elements[0], elements[1], elements[2], elements[3], elements[4]);
    int maximum_element = max(5, elements[0], elements[1], elements[2], elements[3], elements[4]);
    
    fprintf(stderr, "Your output is:\n");
    fprintf(stderr, "Elements sum is %d\n", elements_sum);
    fprintf(stderr, "Minimum element is %d\n", minimum_element);
    fprintf(stderr, "Maximum element is %d\n\n", maximum_element);
    
    int expected_elements_sum = 0;
    for (int i = 0; i < 5; i++) {
        if (elements[i] < minimum_element) {
            return 0;
        }
        
        if (elements[i] > maximum_element) {
            return 0;
        }
        
        expected_elements_sum += elements[i];
    }
    
    return elements_sum == expected_elements_sum;
}

int test_implementations_by_sending_ten_elements() {
    srand(time(NULL));
    
    int elements[10];
    
    elements[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[3] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[4] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[5] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[6] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[7] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[8] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[9] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    
    fprintf(stderr, "Sending following ten elements:\n");
    for (int i = 0; i < 10; i++) {
        fprintf(stderr, "%d\n", elements[i]);
    }
    
    int elements_sum = sum(10, elements[0], elements[1], elements[2], elements[3], elements[4],
                           elements[5], elements[6], elements[7], elements[8], elements[9]);
    int minimum_element = min(10, elements[0], elements[1], elements[2], elements[3], elements[4],
                           elements[5], elements[6], elements[7], elements[8], elements[9]);
    int maximum_element = max(10, elements[0], elements[1], elements[2], elements[3], elements[4],
                           elements[5], elements[6], elements[7], elements[8], elements[9]);
    
    fprintf(stderr, "Your output is:\n");
    fprintf(stderr, "Elements sum is %d\n", elements_sum);
    fprintf(stderr, "Minimum element is %d\n", minimum_element);
    fprintf(stderr, "Maximum element is %d\n\n", maximum_element);
    
    int expected_elements_sum = 0;
    for (int i = 0; i < 10; i++) {
        if (elements[i] < minimum_element) {
            return 0;
        }
        
        if (elements[i] > maximum_element) {
            return 0;
        }
        
        expected_elements_sum += elements[i];
    }
    
    return elements_sum == expected_elements_sum;
}

int main ()
{
    int number_of_test_cases;
    scanf("%d", &number_of_test_cases);
    
    while (number_of_test_cases--) {
        if (test_implementations_by_sending_three_elements()) {
            printf("Correct Answer\n");
        } else {
            printf("Wrong Answer\n");
        }
        
        if (test_implementations_by_sending_five_elements()) {
            printf("Correct Answer\n");
        } else {
            printf("Wrong Answer\n");
        }
        
        if (test_implementations_by_sending_ten_elements()) {
            printf("Correct Answer\n");
        } else {
            printf("Wrong Answer\n");
        }
    }
    
    return 0;
}


/* 6. Functions - Querying the Document */
/*
A document is represented as a collection paragraphs, a paragraph is represented as a collection of sentences, a sentence is represented as a collection of words and a word is represented as a collection of lower-case ([a-z]) and upper-case ([A-Z]) English characters.

You will convert a raw text document into its component paragraphs, sentences and words. To test your results, queries will ask you to return a specific paragraph, sentence or word as described below.

Alicia is studying the C programming language at the University of Dunkirk and she represents the words, sentences, paragraphs, and documents using pointers:

  *  A word is described by char*.
  
  *  A sentence is described by char**. The words in the sentence are separated by one space (" "). The last word does not end with a space(" ").
  
  *  A paragraph is described by char***. The sentences in the paragraph are separated by one period (".").

  *  A document is described by char****. The paragraphs in the document are separated by one newline("\n"). The last paragraph does not end with a newline.

For example:

    Learning C is fun.
    Learning pointers is more fun.It is good to have pointers.

  *  The only sentence in the first paragraph could be represented as:

char** first_sentence_in_first_paragraph = {"Learning", "C", "is", "fun"};

  *  The first paragraph itself could be represented as:

char*** first_paragraph = {{"Learning", "C", "is", "fun"}};

  *  The first sentence in the second paragraph could be represented as:

char** first_sentence_in_second_paragraph = {"Learning", "pointers", "is", "more", "fun"};

  *  The second sentence in the second paragraph could be represented as:

char** second_sentence_in_second_paragraph = {"It", "is", "good", "to", "have", "pointers"};

  *  The second paragraph could be represented as:

char*** second_paragraph = {{"Learning", "pointers", "is", "more", "fun"}, {"It", "is", "good", "to", "have", "pointers"}};

  *  Finally, the document could be represented as:

char**** document = {{{"Learning", "C", "is", "fun"}}, {{"Learning", "pointers", "is", "more", "fun"}, {"It", "is", "good", "to", "have", "pointers"}}};

Alicia has sent a document to her friend Teodora as a string of characters, i.e. represented by char* not char****. Help her convert the document to char**** form by completing the following functions:

  *  char**** get_document(char* text) to return the document represented by char****.

  *  char**** kth_paragraph (char**** document, int k) to return the kth paragraph.

  *  char** kth_sentence_in_mth_paragraph (char**** document, int k, int m) to return the kth sentence in the mth paragraph.

  *  char* kth_word_in_mth_sentence_of_nth_paragraph (char**** document, int k, int m, int n) to return the kth word in the mth sentence of the nth paragraph.

Input Format

The first line contains the integer paragraph_count.
Each of the next paragraph_count lines contains a paragraph as a single string.
The next line contains the integer q, the number of queries.
Each of the next q lines or groups of lines contains a query in one of the following formats:

  *  1 The first line contains 1 k:
    *  The next line contains an integer x, the number of sentences in the kth paragraph.
    *  Each of the next x lines contains an integer a[i], the number of words in the ith sentence.
    *  This query corresponds to calling the function kth_paragraph. 

  *  2 The first line contains 2 k m:
    *  The next line contains an integer x, the number of words in the kth sentence of the mth paragraph.
    *  This query corresponds to calling the function kth_sentence_in_mth_paragraph.
 
  *  3 The only line contains 3 k m n:
    *  This query corresponds to calling the function kth_word_in_mth_sentence_of_nth_paragraph.

Constraints

  *  The text which is passed to the get_document has words separated by a space (" "), sentences separated by a period (".") and paragraphs separated by a newline("\n").
  
  *  The last word in a sentence does not end with a space.

  *  The last paragraph does not end with a newline.

  *  The words contain only upper-case and lower-case English letters.

  *  1 ≤ number of characters in the entire document ≤ 100
  
  *  1 ≤ number of paragraphs in the entire document ≤ 100

Output Format

Print the paragraph, sentence or the word corresponding to the query to check the logic of your code.

Sample Input 0

2
Learning C is fun.
Learning pointers is more fun.It is good to have pointers.
3
1 2
2
5
6
2 1 1
4
3 1 1 1

Sample Output 0

Learning pointers is more fun.It is good to have pointers.
Learning C is fun
Learning

Explanation 0

The first query corresponds to returning the second paragraph with 2 sentences of lengths 5 and 6 words.
The second query correspond to returning the first sentence of the first paragraph. It contains 4 words.
The third query corresponds to returning the first word of the first sentence of the first paragraph.
*/
/* Solution */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];
}

char**** get_document(char* text) {
    char ****doc = NULL;
    int i_paragraph = 0;
    int i_sentence = 0;
    int i_word = 0;
    doc = (char ****) malloc(sizeof(char ***));
    doc[0] = (char ***) malloc(sizeof(char **));
    doc[0][0] = (char **) malloc(sizeof(char *));
    char *word = NULL;
    for (char *s = text; *s; ++s)
    {
        if (*s == ' ' || *s == '.')
        {
            fprintf(stderr, "add word p%d s%d w%d: %.*s\n", i_paragraph, i_sentence, i_word, (int)(s - word), word);
            doc[i_paragraph][i_sentence][i_word] = word;
            i_word++;
            doc[i_paragraph][i_sentence] = (char **) realloc(doc[i_paragraph][i_sentence], sizeof(char *) * (i_word + 1));
            if (*s == '.' && s[1] != '\n')
            {
                i_word = 0;
                i_sentence++;
                doc[i_paragraph] = (char ***) realloc(doc[i_paragraph], sizeof(char **) * (i_sentence + 1));
                doc[i_paragraph][i_sentence] = (char **) malloc(sizeof(char *));
            }
            *s = 0;
            word = NULL;
        }
        else if (*s == '\n')
        {
            *s = 0;
            word = NULL;
            i_word = 0;
            i_sentence = 0;
            i_paragraph++;
            doc = (char ****) realloc(doc, sizeof(char ***) * (i_paragraph + 1));
            doc[i_paragraph] = (char ***) malloc(sizeof(char **));
            doc[i_paragraph][0] = (char **) malloc(sizeof(char *));
        }
        else
        {
            if (word == NULL)
            {
                word = s;
                //printf("new word: %s\n", word);
            }
        }
    }
    return doc;
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}


