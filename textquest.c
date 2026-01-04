#include<stdio.h>
#include<string.h>

struct Keyword{
    char text[100];
    char word[100];
};

void addText(){
    struct Keyword k;
    FILE *fp = fopen("data.txt", "a");
    printf("Enter a text to add: ");
    scanf(" %[^\n]", k.text);

    fprintf(fp, "%s\n", k.text);
    fclose(fp);

    printf("Text added successfully!\n");
}

void viewText(){
    struct Keyword k;
    FILE *fp = fopen("data.txt", "r");

    if(fp == NULL){
    printf("No text found.\n");
    return;
    }

    printf("\n---Text in File---\n");

    while(fscanf(fp, " %[^\n]", k.text) != EOF){
        printf("%s\n", k.text);
    }
    fclose(fp);
}

void searchWord(){
    struct Keyword k;
    FILE *fp = fopen("data.txt", "r");
    int found = 0;

    if(fp == NULL){
        printf("File not found.\n");
    }

    printf("Enter a word to search:");
    scanf(" %[^\n]", k.word);

    printf("\n---Search Results---\n");

   while(fgets(k.text, sizeof(k.text), fp)){
       if(strstr(k.text, k.word) != NULL){
        printf("%s", k.text);
        found++;
       }
   }

   if(found == 0){
    printf("No match found.\n");
   } 
   else{
    printf("\nTotal matches: %d\n", found);
   }
   
   fclose(fp);
}

int main(){
    int option;

    while(1){
    printf("\n---Text File---\n");
    printf("1.Add Text\n");
    printf("2.View Text\n");
    printf("3.Search a word\n");
    printf("4.Exit\n");
    printf("Choose option: ");
    scanf("%d", &option);
    if(option == 1){
        addText();
    }
    else if(option == 2){
        viewText();
    }
    else if(option == 3){
        searchWord();
    }
    else if(option == 4){
        break;
    }
    else{
        printf("Invalid option.\n");
    }
    }
    return 0;
}