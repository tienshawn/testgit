#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_CHARACTERS 2000
#define MAX_PARAGRAPHS 10

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

/*
Start of user code
*/

typedef struct document document;
typedef struct paragraph paragraph;
typedef struct sentence sentence;
typedef struct word word;

#define parse_subparts(text, delim, parent_type, sub_type, max_subs) {\
    parent_type parent;\
    parent.data = malloc((max_subs) * sizeof(sub_type));\
\
    char *lasts;\
    char *sub_text = strtok_r((text), (delim), &lasts);\
    int i;\
\
    for (i = 0;  sub_text;  i++) {\
        parent.data[i] = get_##sub_type(sub_text);\
        sub_text = strtok_r(NULL, (delim), &lasts);\
    }\
\
    parent.sub_type##_count = i;\
    parent.data = realloc(parent.data, i * sizeof(sub_type));\
\
    return parent;\
}

word get_word(char *text) {
    word w = { text };
    return w;
}

sentence get_sentence(char *text) {
    parse_subparts(text, " ", sentence, word, MAX_CHARACTERS);
}

paragraph get_paragraph(char *text) {
    parse_subparts(text, ".", paragraph, sentence, MAX_CHARACTERS);
}

document get_document(char* text) {
    parse_subparts(text, "\n", document, paragraph, MAX_PARAGRAPHS);
}

paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k - 1];
}

sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return kth_paragraph(Doc, m).data[k - 1];
}

word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return kth_sentence_in_mth_paragraph(Doc, m, n).data[k - 1];
}


void print_word(struct word w) {
    if (!isalpha(w.data)) printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1 || sen.data[i].data == '\0') {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
        printf(" ");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}
/*
End of user coce
*/

/*
Function to read the input. Do not touch this code. You should not touch the code below this line
*/
char* get_input_text() {	
    int number_array_elements; 
    int paragraph_count;
       
    scanf("%d%*c", &paragraph_count); 
    scanf("%d%*c", &number_array_elements);
           
     char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    
    for (int i = 0; i < paragraph_count; i++) {
        
        gets(p[i]);
        //printf("p[%d] %s",i, p[i]);
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
/* This function already get input text from the system. */    
char* text = get_input_text();
    //printf("%s",text);
    struct document Doc = get_document(text);
  
    int query_type;
    
    scanf("%d", &query_type);
      
        if (query_type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
           // printf("k= %d m= %d n= %d",k,m,n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (query_type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
           // printf("k= %d m= %d ",k,m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
            printf(".");
        }

        else 
        {
            int k;
            scanf("%d", &k);
            //printf("k = %d",k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
         
}