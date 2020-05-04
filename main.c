//Albert Paez 
 
 #include <stdio.h>
 #include <ctype.h>
 #include <string.h>
 #include <stdlib.h>


//===============Exercise 7.1========================
 void convert_case(const char* letter_case, int argc){
     if(argc != 2){ 
         printf("Enter command -u(uppercase) or -l(lowercase)...\n");
         return;
    }
     int c;
     if(strcmp(letter_case, "-u") == 0){
        while((c = getchar()) != EOF){
            putchar(toupper(c));
        } 
     }
     if(strcmp(letter_case, "-l") == 0){
        while((c = getchar()) != EOF){
            putchar(tolower(c));
        } 
     }

 }

//===============Exercise 7.6========================
void file_compare(int argc, const char* first_file, const char* second_file){
    if(argc != 3){
        printf("Usage: ./run file1 file2\n");
        exit(1);
    }
    char first[BUFSIZ],second[BUFSIZ];

    FILE *ffirst = fopen(first_file, "r");
    FILE *fsecond = fopen(second_file, "r");

    while((fgets(first, BUFSIZ, ffirst)) && (fgets(second, BUFSIZ, fsecond)) ){
        if (strcmp(first, second) != 0){
            printf("====FILES ARE DIFFERENT=====\n");
            printf("First File: %s", first);
            printf("Second File: %s", second);
        }
    }

    fclose(ffirst);
    fclose(fsecond);
}

//===============Exercise 7.8========================
void print_file(int argc, const char* argv[]){
    if(argc != 3){
        printf("Usage: ./run file1 file2\n");
        exit(1);
    }
    char first[BUFSIZ],second[BUFSIZ];
    int pagecount = 1, stringcount = 0;


    FILE *ffp = fopen(argv[1], "r"); //First file pointer
    FILE *sfp = fopen(argv[2], "r"); //Second file pointer

    printf("=======%s=========\n\n", argv[1]);
    printf("\n-----------Page %d------------\n", pagecount);
    while(fgets(first, BUFSIZ,ffp)){
        stringcount++;
        printf("%s", first);
        if(stringcount >= 10){
            ++pagecount;
            printf("\n-----------Page %d------------\n", pagecount);
            stringcount = 0;
        }
    }
    printf("========================\n\n");
    ++pagecount;
    
    printf("=======%s=========\n\n", argv[2]);
    printf("\n-----------Page %d------------\n", pagecount);
    while(fgets(second, BUFSIZ,sfp)){
        stringcount++;
        printf("%s", second);
        if(stringcount >= 10){
            ++pagecount;
            printf("\n-----------Page %d------------\n", pagecount);
            stringcount = 0;
        }
    }
    printf("========================\n\n");
    ++pagecount;

}

//===================================================
 int main(int argc, const char* argv[]){
    //convert_case(argv[1], argc);
    // file_compare(argc, argv[1], argv[2]);
    print_file(argc, argv);
    return 0;
 }