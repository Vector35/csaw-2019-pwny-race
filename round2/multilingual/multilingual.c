#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/sendfile.h>
#include <unistd.h>
#include <signal.h>



#define true  1
#define false 0
char name[10];

struct language {
    char tag[3];
    char greeting[20];
    struct language* next; 
};


struct language* newlang(char tag[3], char greeting[20])
{
    struct language* next = (struct language*)malloc(sizeof(struct language)); 
    strcpy(next->tag, tag);
    strcpy(next->greeting, greeting);
    next->next = NULL;
    return next;
}


void listlang(struct language* lang)
{
    struct language* next;
    next = lang;
    puts("TAG\tGREETING");
    while (next->next != NULL)
    {
        printf("%s\t%s\n", next->tag, next->greeting);
        next = next->next;
    }
}


void addlanguage(struct language* head)
{
    struct language* next = (struct language*)malloc(sizeof(struct language)); 
    struct language* current = head;
    printf("\nLanguage tag: \n-> ");
    fflush(stdout);
    scanf("%2s", next->tag);
    printf("\nGreeting: \n-> ");
    fflush(stdout);
    scanf("%19s", next->greeting);
    next->next = NULL;
    while (current->next != NULL);
    {
        if (strcmp(current->tag, next->tag) == 0)
        {
            puts("Sorry, this language already exists.");
            fflush(stdout);
            return;
        }
        current = current->next;
    }
    if (strcmp(current->tag, next->tag) == 0)
    {
        puts("Sorry, this language already exists.");
        return;
    }
    //does not yet exist, add it.
    current->next = next;
}


struct language* changelanguage(struct language* head, struct language* current)
{
    char tag[3];
    struct language* next = head;
    printf("\nLanguage tag: \n-> ");
    fflush(stdout);
    scanf("%2s", tag);
    while (strcmp(next->tag, tag) != 0)
    {
        if (next->next == NULL)
        {
            printf("Sorry, I could not find tag: \"%s\"", tag);
            return current;
        }
        else
            next = next->next;
    }
    return next;



}


void removelanguage(struct language* head, struct language* current)
{


}


struct language* initlang()
{
    struct language* head = NULL;
    struct language* current = NULL;
    struct language* next = NULL;
    head = (struct language*)malloc(sizeof(struct language)); 
    strcpy(head->tag, "ar");
    strcpy(head->greeting, "marhaba");
    current = head;
    next = newlang("de", "guten tag");
    current->next = next;
    current = next;
    next = newlang("es", "hola");
    current->next = next;
    current = next;
    next = newlang("en", "hello");
    current->next = next;
    current = next;
    next = newlang("fa", "salaam");
    current->next = next;
    current = next;
    next = newlang("fr", "bonjour");
    current->next = next;
    current = next;
    next = newlang("ha", "sannu");
    current->next = next;
    current = next;
    next = newlang("hi", "namaste");
    current->next = next;
    current = next;
    next = newlang("hu", "szia");
    current->next = next;
    current = next;
    next = newlang("id", "halo");
    current->next = next;
    current = next;
    next = newlang("it", "chao");
    current->next = next;
    current = next;
    next = newlang("ja", "konnichiwa");
    current->next = next;
    current = next;
    next = newlang("kk", "salemetsiz be");
    current->next = next;
    current = next;
    next = newlang("ko", "ahn-young-ha-se-yo");
    current->next = next;
    current = next;
    next = newlang("mn", "sain bainuu");
    current->next = next;
    current = next;
    next = newlang("pt", "ola");
    current->next = next;
    current = next;
    next = newlang("ru", "zdras-tvuy-te");
    current->next = next;
    current = next;
    next = newlang("sw", "habari");
    current->next = next;
    current = next;
    next = newlang("tr", "merhaba");
    current->next = next;
    current = next;
    current->next = NULL;
    return head;
}


int ask(char* greeting)
{
    puts("In what language would you like to be greeted?\n: ");
    fflush(stdout);
    fgets(greeting, 2, stdin);
    //Print language specific hello

    //printf("So you're in %s? That sounds great!", buffer);
    return true;
}


void print1(char* output)
{
    printf("%s\n", output);
}


void print2(char* output)
{
    puts(output);
}


void print3(char* output)
{
    for (int i = 0; i < strlen(output); i++)
    {
        putchar(output[i]);
    }
    putchar(0x0a);
}


void print4(char* output)
{
    char fname[L_tmpnam];
    char cmd[L_tmpnam + 4] = "cat ";
    tmpnam(fname);
    strcat(cmd, fname);
    //FILE* tmp = tmpfile();
    FILE* tmp = fopen(fname, "w+");
    int i = 0;
    if (tmp == NULL) 
    {
        return;
    }
    while (output[i] != '\0')
    {
        fputc(output[i], tmp);
        i++;
    }
    fputc(0xa, tmp);
    i++;
    rewind(tmp);
    fclose(tmp);
    system(cmd);
    unlink(fname);
}


void print5r(char* output)
{
   if (*output == '\0')
      return;
   putchar(output[0]);
   print5r(++output);
}


void print5(char* output)
{
    print5r(output);
    putchar(0x0a);
}


void print6(char* output)
{
    char *ptr;
    ptr=output;
    while(*ptr!='\0')
        printf("%c",*ptr++);
    printf("\n");
}


char* strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}


void print7(char* output)
{
    char* buf = (int*)calloc(1, strlen(output) + 2);
    for (int i = 0; i < strlen(output); i++)
    {
        buf[strlen(output)-1-i] = output[i];
    }
    buf[strlen(output) + 1] = '\0';
    puts(strrev(buf));
}


void print8(char* output)
{
    char* cmd = (int*)calloc(1, strlen(output) + 8);
    strcpy(cmd, "echo \"");
    strcat(cmd, output);
    strcat(cmd, "\"");
    system(cmd);
}


void pick_print(struct language* lang)
{
    if (name[0] == '\0')
    {
        puts("But I don't even know what to call you!");
        return;
    }
    void (*pptr)(char*); 
    void* ptrs[8] = { print1, print2, print3, print4, print5, print6, print7, print8 };
    int count = (lang->tag[0] + lang->tag[1]) - 194;
    //printf("DEBUG: Calculated tag: %d\n", count);
    pptr = ptrs[(count % 52) / 7];
    pptr(lang->greeting);
    pptr(name);
}


int main()
{
    char* greeting;
    struct language* head = initlang();
    struct language* current = head;
    int choice;

    while(1) 
    {
        puts("\n -= Welcome to the multilingual pwnage server =-");
        printf("Current language: %s", current->tag);
        printf("\n1) List Languages\n2) Add Language\n3) Remove Language\n4) Change Language\n5) Change Name\n6) Greetings!\n7) Exit\n\n-> ");
        fflush(stdout);
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                listlang(head);
                break;
            case 2:
                addlanguage(head);
                break;
            case 3:
                removelanguage(head, current);
                break;
            case 4:
                current = changelanguage(head, current);
                break;
            case 5:
                printf("\nNew name: \n-> ");
                fflush(stdout);
                scanf("%9s", name);
                break;
            case 6:
                pick_print(current);
                break;
            case 7:
                exit(0);
                break;
            default:
                break;
        }
    }

    return 0;
}
