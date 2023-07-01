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

// Structure just to pass pointers to helper functions
typedef struct
{
    struct word curr_word;
    struct sentence curr_sentence;
    struct paragraph curr_para;
    struct document curr_doc;
} CompountStructType;


void end_word(CompountStructType *p)
{
    struct word* curr_word = &p->curr_word;
    struct sentence* curr_sentence = &p->curr_sentence;

    // Add the current word to the sentence, making space for it - if there is a word
    if (curr_word->data)
    {
        curr_sentence->data = realloc(curr_sentence->data, (1 + curr_sentence->word_count) * sizeof(struct word));
        curr_sentence->data[curr_sentence->word_count] = *curr_word;
        curr_sentence->word_count++;

        // Clear down current word
        curr_word->data = NULL;
    }
}

void end_sentence(CompountStructType* p)
{
    struct sentence* curr_sentence = &p->curr_sentence;
    struct paragraph* curr_para = &p->curr_para;

    // Add the current sentence to the paragraph, making space for it - if there is a sentence
    if (curr_sentence->data)
    {
        curr_para->data = realloc(curr_para->data, (1 + curr_para->sentence_count) * sizeof(struct sentence));
        curr_para->data[curr_para->sentence_count] = *curr_sentence;
        curr_para->sentence_count++;

        // Clear down current sentence
        curr_sentence->data = NULL;
        curr_sentence->word_count = 0;
    }
}

void end_paragraph(CompountStructType *p)
{
    struct paragraph* curr_para = &p->curr_para;
    struct document* curr_doc = &p->curr_doc;

    // Add the current paragraph to the document, making space for it - if there is a paragraph
    if (curr_para->data)
    {
        curr_doc->data = realloc(curr_doc->data, (1 + curr_doc->paragraph_count) * sizeof(struct paragraph));
        curr_doc->data[curr_doc->paragraph_count] = *curr_para;
        curr_doc->paragraph_count++;

        // Clear down current paragraph
        curr_para->data = NULL;
        curr_para->sentence_count = 0;
    }
}


struct document get_document(char* text) {

    CompountStructType data = { 0 };

    while (*text != '\0')
    {
        switch (*text)
        {
        case '\n':
            // End of word, sentence and paragraph
            *text = '\0';   // Close off current word
            end_word(&data);
            end_sentence(&data);
            end_paragraph(&data);
            break;

        case '.':
            // End of word and end of sentence.  
            *text = '\0';   // Close off current word
            end_word(&data);
            end_sentence(&data);
            break;

        case ' ':
            // End of word
            *text = '\0';   // Close off current word
            end_word(&data);
            break;

        default:
            if (!data.curr_word.data)
            {
                // Start current word here since we have text which is not a special character
                data.curr_word.data = text;
            }
            break;
        }
        text++;
    }

    // Finish up any word, sentence and paragraph which was pending
    end_word(&data);
    end_sentence(&data);
    end_paragraph(&data);

    return data.curr_doc;   // return byval
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n-1].data[m-1].data[k-1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) {
    return Doc.data[m-1].data[k-1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {

    return Doc.data[k-1];
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