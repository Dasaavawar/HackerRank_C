// HackerRank - C - Challenges - V - Structs and Enums


/* 1. Structs and Enums - Boxes through a Tunnel */
/*
You are transporting some boxes through a tunnel, where each box is a parallelepiped (https://en.wikipedia.org/wiki/Parallelepiped), and is characterized by its length, width and height.

The height of the tunnel 41 feet and the width can be assumed to be infinite. A box can be carried through the tunnel only if its height is strictly less than the tunnel's height. Find the volume of each box that can be successfully transported to the other end of the tunnel. Note: Boxes cannot be rotated.

Input Format

The first line contains a single integer n, denoting the number of boxes.
n lines follow with three integers on each separated by single spaces - length_i, width_i and height_i which are length, width and height in feet of the i-th box.

Constraints

  *  1 ≤ n ≤ 100
  *  1 ≤ length_i, width_i, height_i ≤ 100

Output Format

For every box from the input which has a height lesser than 41 feet, print its volume in a separate line.

Sample Input 0

4
5 5 5
1 2 40
10 5 41
7 2 42

Sample Output 0

125
80

Explanation 0

The first box is really low, only 5 feet tall, so it can pass through the tunnel and its volume is 5 x 5 x 5 = 125.

The second box is sufficiently low, its volume is 1 x 2 x 40 = 80.

The third box is exactly 41 feet tall, so it cannot pass. The same can be said about the fourth box.
*/
/* Solution */

#include <stdio.h>
#include <stdlib.h>
#define MAX_HEIGHT 41

struct box
{
    /**
    * Define three fields of type int: length, width and height
    */
    int length;
    int width;
    int height;
};

typedef struct box box;

int get_volume(box b) {
    /**
    * Return the volume of the box
    */
    return b.length*b.width*b.height;
}

int is_lower_than_max_height(box b) {
    /**
    * Return 1 if the box's height is lower than MAX_HEIGHT and 0 otherwise
    */
    if (b.height < MAX_HEIGHT) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	box *boxes = malloc(n * sizeof(box));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &boxes[i].length, &boxes[i].width, &boxes[i].height);
	}
	for (int i = 0; i < n; i++) {
		if (is_lower_than_max_height(boxes[i])) {
			printf("%d\n", get_volume(boxes[i]));
		}
	}
	return 0;
}


/* 2. Structs and Enums - Small Triangles, Large Triangles */
/*
You are given n triangles, specifically, their sides a_i, b_i and c_i. Print them in the same style but sorted by their areas from the smallest one to the largest one. It is guaranteed that all the areas are different.

The best way to calculate a area of a triangle with sides a, b, and c is Heron's formula:
S = √(p x (p - a) x (p - b) x (p - c)) where p = (a + b + c)/2.

Input Format

The first line of each test file contains a single integer n.
n lines follow with three space-separated integers, a_i, b_i and c_i.

Constraints

  *  1 ≤ n ≤ 100
  *  1 ≤ a_i, b_i, c_i ≤ 70
  *  a_i + b_i > c_i, a_i + c_i > b_i and b_i + c_i > a_i

Output Format

Print exactly n lines. On each line print space-separated integers, the a_i, b_i and c_i of the corresponding triangle.

Sample Input 0

3
7 24 25
5 12 13
3 4 5

Sample Output 0

3 4 5
5 12 13
7 24 25

Explanation 0

The square of the first triangle is 84. The square of the second triangle is 30. The square of the third triangle is 6. So the sorted order is the reverse one.
*/
/* Solution */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

double getArea(triangle *tr) {
    double p;
    p = (tr->a + tr->b + tr->c) / 2.0;
    return sqrt(p * ((p - tr->a) * (p - tr->b) * (p - tr->c)));
}

void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    triangle tr_tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (getArea(&tr[i]) < getArea(&tr[j])) {
                tr_tmp = tr[i];
                tr[i] = tr[j];
                tr[j] = tr_tmp;
            }
        }
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}


/* 3. Structs and Enums - Post Transition */
/*
We live in a big country. This country has towns_count towns in it. Each town has some post offices in which packages are stored and transferred.

Post offices have different inner structure. Specifically, each of them has some limitations on the packages it can store - their weight should be between min_weight and max_weight inclusively, where min_weight and max_weight are fixed for each office.

Packages are stored in some order in the office queue. That means, that they are processed using this order when sending and receiving.

Sometimes two post offices, even in different towns, may organize the following transaction: the first one sends all its packages to the second one. The second one accepts the packages that satisfy the weight condition for the second office and rejects all other ones. These rejected packages return to the first office back and are stored in the same order they were stored before they were sent. The accepted packages move to the tail of the second office's queue in the same order they were stored in the first office.

You should process several queries in your program. You'll be provided with structures package, post_office and
town. in order to complete this task, you should fill the following functions: print_all_packages - given the town t, print all packages in this town. They should be printed as follows:

Town_name:
    0:
        id_0
        id_1
        ...
    1:
        id_2
        id_3
        ...
    ...

where 0, 1 etc are the numbers of post offices and id_0, id_1... are the ids of packages from the 0th post office in the order of its queue, id_2, id_3 are from the 1st one etc. There should be one '\t' symbol before post office numbers and two '\t' symbols before the ids.

send_all_acceptable_packages - given the towns source and target and post office indices source_office_index and target_office_index, manage the transaction described above between the post office #source_office_index in town source and the post office # target_office_index in town target.

town_with_most_packages - given all towns, find the one with the most number of packages in all post offices altogether. If there are several of them, find the first one from the collection towns.

find_towns - given all towns and a string name, find the town with the name name. It's guaranteed that the town exists.

Input Format

First line of the input contains a single integer towns_count. towns_count blocks follow, each describing a town.

Every town block contains several lines. On the first line there is a string town_name - the name of the town. On the second line there is an integer - offices_count the number of the offices in the town. offices_count blocks follow then, each describing an office.

Every office block also contains several lines. On the first line there are three integers separated by single spaces: packages_count (the number of packages in the office), min_weight and max_weight (described above). packages_count blocks follow, each describing a package.

Every package block contains exactly two lines. On the first line there is a string id which is an id of the package. On the second line there is an integer weight which is the weight of the package.

Then, there is a single integer queries on the line which is the number of queries. queries blocks follow, each describing a query.

Every query block contains several lines. On the first line there is an integer 1, 2 or 3. If this integer is 1, on the second line there is a string town_name - the name of town for which all packages should be printed. If this integer is 2, on the second line there are string source_name, integer source_office_index, string target_name and integer target_office_index separated by single spaces. That means transactions between post office #source_office_index in the town source_name and post office #target_office_index in the town target_name should be processed.

If the integer is 3, no lines follow and the town with the most number of packages should be found.

Constraints

  *  All integer are between 0 and 10
  *  towns_count > 0, offices_count > 0.
  *  All strings have length ≤ 5
  *  All towns' names have only uppercase english letters and are unique.
  *  All packages' ids have only lowercase english letters and are unique.
  *  For each post office, min_weight ≤ max_weight.
  *  All queries are valid, that means, towns with the given names always exist, post offices with the given indices always exist.

Output Format

For queries of type 1, print all packages in the format provided in the problem statement. For queries of type 3, print "Town with the most number of packages is town_name" on a separate line.

Sample Input 0

2
A
2
2 1 3
a 2
b 3
1 2 4
c 2
B
1
4 1 4
d 1
e 2
f 3
h 4
5
3
2 B 0 A 1
3
1 A
1 B

Sample Output 0

Town with the most number of packages is B
Town with the most number of packages is A
A:
    0:
        a
        b
    1:
        c
        e
        f
        h
B:
    0:
        d

Explanation 0

Before all queries, town B has 4 packages in total, town A has 3. But after transaction all packages from B's 0th post office go to the 1st post office of A, except package d because it's too light.
*/
/* Solution */

#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 6

struct package
{
    char* id;
    int weight;
};

typedef struct package package;

struct post_office
{
    int min_weight;
    int max_weight;
    package* packages;
    int packages_count;
};

typedef struct post_office post_office;

struct town
{
    char* name;
    post_office* offices;
    int offices_count;
};

typedef struct town town;

void print_all_packages(town t) {
    printf("%s:\n",t.name);
    for(int i = 0; i < t.offices_count; i++){
        printf("\t%d:\n",i);
        for(int j = 0; j < t.offices[i].packages_count; j++)
            printf("\t\t%s\n",t.offices[i].packages[j].id);
    }
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
    post_office *src = source->offices+source_office_index;
    post_office *dst = target->offices+target_office_index;
    package buff[src->packages_count]; int buff_size = 0;
    for(int i = 0; i < src->packages_count;){
        if(src->packages[i].weight >= dst->min_weight && src->packages[i].weight <= dst->max_weight){
            buff[buff_size++] = src->packages[i];
            for(int j = i; j < src->packages_count-1; j++)
                src->packages[j] = src->packages[j+1];
            src->packages_count--;
        }
        else i++;
    }
    dst->packages = realloc(dst->packages, (dst->packages_count+buff_size)*sizeof(package));
    for(int i = 0; i < buff_size; i++){
        dst->packages[dst->packages_count++] = buff[i];
    }
}

town town_with_most_packages(town* towns, int towns_count) {
    town maxt = *towns; int max = 0;
    for(int i = 0; i < towns->offices_count; i++){
        max += towns->offices[i].packages_count;
    } towns++; towns_count--;
    while(towns_count){
        int sum = 0;
        for(int i = 0; i < towns->offices_count; i++){
            sum += towns->offices[i].packages_count;
        }
        if(sum > max) {
            max = sum;
            maxt = *towns;
        }
        towns++; towns_count--;
    }
    return maxt;
}

town* find_town(town* towns, int towns_count, char* name) {
    while(towns_count){
        if(!strcmp(towns->name,name)){
            return towns;
        }
        towns++; towns_count--;
    }
    return NULL;
}

int main()
{
    int towns_count;
    scanf("%d", &towns_count);
    town* towns = malloc(sizeof(town)*towns_count);
    for (int i = 0; i < towns_count; i++) {
        towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
        scanf("%s", towns[i].name);
        scanf("%d", &towns[i].offices_count);
        towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
        for (int j = 0; j < towns[i].offices_count; j++) {
            scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
            towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
            for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
                towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
                scanf("%s", towns[i].offices[j].packages[k].id);
                scanf("%d", &towns[i].offices[j].packages[k].weight);
            }
        }
    }
    int queries;
    scanf("%d", &queries);
    char town_name[MAX_STRING_LENGTH];
    while (queries--) {
        int type;
        scanf("%d", &type);
        switch (type) {
        case 1:
            scanf("%s", town_name);
            town* t = find_town(towns, towns_count, town_name);
            print_all_packages(*t);
            break;
        case 2:
            scanf("%s", town_name);
            town* source = find_town(towns, towns_count, town_name);
            int source_index;
            scanf("%d", &source_index);
            scanf("%s", town_name);
            town* target = find_town(towns, towns_count, town_name);
            int target_index;
            scanf("%d", &target_index);
            send_all_acceptable_packages(source, source_index, target, target_index);
            break;
        case 3:
            printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
            break;
        }
    }
    return 0;
}


/* 4. Structs and Enums - Structuring the Document */
/*
A document is represented as a collection paragraphs, a paragraph is represented as a collection of sentences, a sentence is represented as a collection of words and a word is represented as a collection of lower-case ([a-z]) and upper-case ([A-Z]) English characters. You will convert a raw text document into its component paragraphs, sentences and words. To test your results, queries will ask you to return a specific paragraph, sentence or word as described below.

Alicia is studying the C programming language at the University of Dunkirk and she represents the words, sentences, paragraphs, and documents using pointers:

  *  A word is described by:

struct word {
    char* data;
};

  *  A sentence is described by:

struct sentence {
    struct word* data;
    int word_count;//the number of words in a sentence
};

The words in the sentence are separated by one space (" "). The last word does not end with a space.

  *  A paragraph is described by:

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//the number of sentences in a paragraph
};

The sentences in the paragraph are separated by one period (".").

  *  A document is described by:

struct document {
    struct paragraph* data;
    int paragraph_count;//the number of paragraphs in a document
};

The paragraphs in the document are separated by one newline("\n"). The last paragraph does not end with a newline.

For example:

    Learning C is fun.
    Learning pointers is more fun.It is good to have pointers.

  *  The only sentence in the first paragraph could be represented as:

struct sentence first_sentence_in_first_paragraph;
first_sentence_in_first_paragraph.data = {"Learning", "C", "is", "fun"};

  *  The first paragraph itself could be represented as:

struct paragraph first_paragraph;
first_paragraph.data = {{"Learning", "C", "is", "fun"}};

  *  The first sentence in the second paragraph could be represented as:

struct sentence first_sentence_in_second_paragraph;
first_sentence_in_second_paragraph.data = {"Learning", "pointers", "is", "more", "fun"};

  *  The second sentence in the second paragraph could be represented as:

struct sentence second_sentence_in_second_paragraph;
second_sentence_in_second_paragraph.data = {"It", "is", "good", "to", "have", "pointers"};

  *  The second paragraph could be represented as:

struct paragraph second_paragraph;
second_paragraph.data = {{"Learning", "pointers", "is", "more", "fun"}, {"It", "is", "good", "to", "have", "pointers"}};

  *  Finally, the document could be represented as:

struct document Doc;
Doc.data = {{{"Learning", "C", "is", "fun"}}, {{"Learning", "pointers", "is", "more", "fun"}, {"It", "is", "good", "to", "have", "pointers"}}};

Alicia has sent a document to her friend Teodora as a string of characters, i.e. represented by char* not struct document. Help her convert the document to struct document form by completing the following functions:

  *  void initialise_document (char* text) to intialise the document. You have to intialise the global variable Doc of type struct document.
  *  struct paragraph kth_paragraph (int k) to return the kth paragraph in the document.
  *  struct sentence kth_sentence_in_mth_paragraph (int k, int m) to return the kth sentence in the mth paragraph.
  *  struct void kth_word_in_mth_sentence_of_nth_paragraph (int k, int m, int n) to return the kth word in the mth sentence of the nth paragraph.

Input Format

The first line contains the integer paragraph_count.
Each of the next paragraph_count lines contains a paragraph as a single string.
The next line contains the integer q, the number of queries.
Each of the next q lines contains a query in one of the following formats:

  *  1 k: This corresponds to calling the function kth_paragraph.
  *  2 k m: This corresponds to calling the function kth_sentence_in_mth_paragraph.
  *  3 k m n: This corresponds to calling the function kth_word_in_mth_sentence_of_nth_paragraph.

Constraints

  *  The text which is passed to get_document has words separated by a spaces(" "), sentences separated by a period(".") and paragraphs separated by a newline("\n").
  *  The last word in a sentence does not end with a space.
  *  The last paragraph does not end with a newline.
  *  The words contain only upper-case and lower-case English letters.
  *  1 ≤ number of characters in the entire document ≤ 1000.
  *  1 ≤ number of paragraphs in the entire document ≤ 5.

Output Format

Print the paragraph, sentence or the word corresponding to the query to check the logic of your code.

Sample Input 0

2
Learning C is fun.
Learning pointers is more fun.It is good to have pointers.
3
1 2
2 1 1
3 1 1 1

Sample Output 0

Learning pointers is more fun.It is good to have pointers.
Learning C is fun
Learning

Explanation 0

The first query returns the second paragraph.
The second query returns the first sentence of the first paragraph.
The third query returns the first word of the first sentence of the first paragraph. 
*/
/* Solution */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};
struct document get_document(char* text) {
    struct document doc;
    struct paragraph *cur_paragraph = NULL;
    struct sentence *cur_sentence = NULL;
    char *new_word = NULL;
    doc.data = NULL;
    doc.paragraph_count = 0;
    for (char *s = text; *s; ++s)
    {
        if (*s == ' ' || *s == '.')
        {
            if (cur_paragraph == NULL)
            {
                doc.paragraph_count++;
                doc.data = (struct paragraph *) realloc(doc.data, sizeof(struct paragraph) * doc.paragraph_count);
                cur_paragraph = doc.data + doc.paragraph_count - 1;
                cur_paragraph->data = NULL;
                cur_paragraph->sentence_count = 0;
                cur_sentence = NULL;
            }
            if (cur_sentence == NULL)
            {
                cur_paragraph->sentence_count++;
                cur_paragraph->data = (struct sentence *) realloc(cur_paragraph->data, sizeof(struct sentence) * cur_paragraph->sentence_count);
                cur_sentence = cur_paragraph->data + cur_paragraph->sentence_count - 1;
                cur_sentence->data = NULL;
                cur_sentence->word_count = 0;
            }
            cur_sentence->word_count++;
            cur_sentence->data = (struct word *) realloc(cur_sentence->data, sizeof(struct word) * cur_sentence->word_count);
            cur_sentence->data[cur_sentence->word_count - 1].data = new_word;
            new_word = NULL;
            if (*s == '.')
                cur_sentence = NULL;
            *s = 0;
        }
        else if (*s == '\n')
        {
            cur_sentence = NULL;
            cur_paragraph = NULL;
        }
        else
        {
            if (new_word == NULL)
            {
                new_word = s;
            }
        }
    }
    return doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n - 1].data[m - 1].data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m - 1].data[k - 1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k - 1];
}


void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
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

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}


