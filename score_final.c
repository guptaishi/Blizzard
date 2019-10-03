    #include <stdio.h>
    #include <stdlib.h>
    #include <windows.h>
    #include <ctype.h>
    #include <conio.h>
    #include <time.h>
    #include <string.h>
    #include<malloc.h>
    #include<math.h>
    #include<ctype.h>
    #define size 100

    struct hscore
    {
        char name[20];
        int score;
    };
    int top=-1;
    int flag=0;
    int stack[size];
   void push(int n)
   {
    if(top==(size-1))
      flag=0;
    else{
       flag=1;
       ++top;
       stack[top]=n;}
    }
    int pop()
    {
      int t=0;
      if(top==-1)
         flag=0;
      else{
        flag=1;
        t=stack[top];
        t--;}
      return t;
     }
     int summ()
     {
      int i,sum=0;
      if(top==-1)
        return 0;
      else
      {
        for(i=top;i>=0;i--)
        {
         sum=sum+stack[i];
        }
      }
      return sum;
     }

    void showLogo() {
          printf("\t---------------------------------------------------------\n");
          printf("\t| ##### #     #####  ###### ######    #    ###### ######|\n");
          printf("\t| #   # #       #        #      #    # #   #   #  #    #|\n");
          printf("\t| ####  #       #       #      #    #####  #####  #    #|\n");
          printf("\t| #   # #       #      #      #     #   #  #   #  #    #|\n");
          printf("\t| ##### ##### #####   #####  #####  #   #  #    # ######|\n");
          printf("\t-------------------------------------------------------\n\n");
    }
    void showInstructions()
    {
        printf("%s%s%s%s%s%s","1. Blizzard is a puzzle game where in the player has to correctly guess the name of the movie of his desired\n",
               "genre  action , thriller , romantic etc\n\n",
               "2. Upon initialisation the program will display the row of empty dashes and the movie to guess \n\n",
               "3. The player will be provided with 10 chances which shall be struck down if the player guesses an incorrect alphabet\n\n",
               "4.On successful guess of the word  the user will be awarded 5 points and will be shown the next word to guess \n\n",
               "PRESS ANY KEY TO CONTINUE");
               getch();
               system("cls");

    }
    struct hscore saveToStruct (char* str)
{
    struct hscore hs;
    int flag = 0;
    char *token = strtok(str, "|");

    while( token != NULL )
    {
        if (!flag)
            strcpy(hs.name, token);
        if(flag)
            hs.score = atoi(token);
        flag++;
        token = strtok( NULL, "|" );
    }
    return hs;
}
    void showScore(struct hscore high[],int count)
    {
        int i,max,pos;
        max=high[0].score;
        for(i=1;i<count;i++)
        {
           if(high[i].score>max)
           {
               max=high[i].score;
               pos=i;
           }
        }
        system("cls");
        printf("\n-----------------\n");
        fflush(stdin);
        printf("HIGH SCORE : \n NAME : %s\n SCORE : %d \n",high[pos].name,high[pos].score);
        printf("\n-----------------\n");
        getch();

    }
   void display(int i) {
     switch (i) {
          case 1 :
          printf("Amount of wrong letters: %d\n\n", i);
          printf("  _______\n");
          printf("  |\n");
          printf("  |\n");
          printf("  |\n");
          printf("  |\n");
          printf("  |\n");
          printf("__|_________\n\n");
         break;
         case 2 :
          printf("Amount of wrong letters: %d\n\n", i);
          printf("  _______\n");
          printf("  |/   | \n");
          printf("  |    O \n");
          printf("  |    |\n");
          printf("  |    |\n");
          printf("  |\n");
          printf("__|_________\n\n");
         break;
         case 3 :
          printf("Amount of wrong letters: %d\n\n", i);
          printf("  _______\n");
          printf("  |/   | \n");
          printf("  |    O \n");
          printf("  |   \\|/\n");
          printf("  |    | \n");
          printf("  |\n");
          printf("__|_________\n\n");
         break;
         case 4 :
          printf("Amount of wrong letters: %d\n\n", i);
          printf("  _______\n");
          printf("  |/   | \n");
          printf("  |    O \n");
          printf("  |   \\|/\n");
          printf("  |    | \n");
          printf("  |   /\n");
          printf("__|_________\n\n");
         break;
         case 5 :
          printf("Amount of wrong letters: %d\n\n", i);
          printf("  _______\n");
          printf("  |/   | \n");
          printf("  |    X \n");
          printf("  |   \\|/\n");
          printf("  |    | \n");
          printf("  |   / \\\n");
          printf("__|_________\n\n");
         break;
     }
    }
    char randomNumber(int max_number) {
    srand(time(NULL));
    int g = (rand() % (max_number + 1));
    return g;
    }
    char *getWord(int r) {
      char c[500];
      FILE *file;
      int n;
       if(r==1)
            {
              file = fopen("romantic.txt", "r");
              printf("\nGENRE SELECTED : ROMANTIC \n");
            }
          else if(r==2)
          {
              file = fopen("action.txt", "r");
              printf("\nGENRE SELECTED : ACTION \n");
          }
          else if(r==3)
             {
                 file = fopen("comedy.txt", "r");
                 printf("\nGENRE SELECTED : COMEDY \n");
             }
          else if(r==4)
             {
                 file = fopen("horror.txt", "r");
                 printf("\nGENRE SELECTED : HORROR \n");
             }
      if(file==NULL) {
        printf("An error has occured: can't open words file.\n\n");

      }  else {
        n = fread(c, 1, 500, file);
        c[n] = '\0';
      }
        char *token;
        token = strtok(c, "|");
        char *words[200] = {0};
        int f = 0;
        while(token != NULL)
        {
          words[f] = malloc(strlen(token)+1);
          strcpy(words[f],token);
          token = strtok(NULL, "|");
          f++;
        }
        fclose(file);
        int wordN = randomNumber(f);
        int q;
        for(q  = 0; q < 200; q++)
        {
            if( q != wordN) {
             free(words[q]);
            }
        }
        return words[wordN];
    }
    int main()
    {
        struct hscore h;
        system("color 17");
    char udi[] = "EMPTY";
    int y;
     showLogo();
     printf("FOR INSTRUCTIONS:  PRESS 1 \nTO START THE GAME: PRESS 2\nVIEW HIGH SCORE :  PRESS 3\n");
     scanf("%d",&y);
     if(y==1)
        showInstructions();
     if(y==3)
     {
         struct hscore hss[50];
    FILE* file = fopen("high_score.txt", "r");
    char buffer[200];
    int flag = 0;
    while (fgets(buffer, 200, file))
    {
        hss[flag] = saveToStruct(buffer);
        flag++;
    }
    showScore(hss,flag);
   printf("FOR INSTRUCTIONS:  PRESS 1 \nTO START THE GAME: PRESS 2\n");
     scanf("%d",&y);
     if(y==1)
        showInstructions();
     }
     system("cls");
     char name[25];
     printf("Enter player's name : \t");
     fflush(stdin);
     gets(name);
     strcpy(h.name,name);
     int score=0;
     system("cls");
    while ((strcmp(udi, "END") != 0) && ((strcmp(udi, "AGAIN") == 0) || (strcmp(udi, "EMPTY") == 0)))
     {
     strcpy(udi, "EMPTY");
     int r;
     system("cls");
     printf("CHOOSE YOUR GENRE -\n\nFOR ROMANTIC: PRESS 1 \nFOR ACTION:   PRESS 2 \nFOR COMEDY:   PRESS 3 \nFOR HORROR:   PRESS 4\n");
     scanf("%d",&r);
     system("cls");
     char *tempWord = getWord(r);
     char guessWord[strlen(tempWord)+1];
     strcpy(guessWord, tempWord);
     free(tempWord);
     int wordlength = strlen(guessWord);
     char* currentWord = malloc( wordlength );
     int t,b=0;
     for (t = 0; t <= wordlength; t++) {
      if (t == wordlength) {
          currentWord[t] = '\0';
      }
      else if (guessWord[t]=='a' ||guessWord[t]=='e' ||guessWord[t]=='i' ||guessWord[t]=='o' ||guessWord[t]=='u')
      {
          currentWord[t]=guessWord[t];b++;
      }
      else {
          currentWord[t] =  '-';
      }
     }
     int errors = 0;
     int guessedLetter = 0;
     int i,n = 1;
     int e,g=0;
     char c;
     printf("%s%s\n","This is the movie you need to guess: ",currentWord);
     printf("number of letters to guess :%d\n\n",(wordlength-b));
     printf("%d.     %s", n, "Enter the letter you want to guess: ");
     while( (strcmp(currentWord, guessWord) != 0) && (errors < 5) ){
     scanf("%c", &c);
     c = tolower(c);
     if (c != '\n') {
     if (isalpha(c)) {
     for (i = 0; i < wordlength; i++) {
      if (guessWord[i] == c) {
       currentWord[i] = c;
       guessedLetter = 1;
      }
     }
     if (guessedLetter == 0) {
      errors++;
     } else {
     guessedLetter = 0;
     g++;
     score+=5;
     }
     n++;
     system("cls");
     if ( (strcmp(currentWord, guessWord) != 0) && (errors < 5) ) {
      printf("%s%s\n\n", "The word including the letters you guessed: ", currentWord);
      display(errors);
      e= 5 - errors;
      printf("\nLives remaining: %d\n\n",e);
      printf("%d.     %s", n, "Enter the letter(s) you want to guess: ");
     }
     }
      else
     {
      printf("Only alphanumeric symbols are allowed (a-z, A-Z), try again:\n");
     }
     }
     }
     system("cls");
     printf("---------------\n");
     printf("--- Results ---\n");
     printf("---------------\n\n");
     if (errors <=5) {
      push(score);
      if (strcmp(currentWord, guessWord) == 0) {

           printf("CONGRATULATIONS !!! You have guessed the right word!\n\n");
          printf("---------------\n");
           printf("NAME : %s",name);
           printf("\nSCORE : %d\n",score);
           h.score=score;
           printf("NUMBER OF CORRECT GUESSES :%d",g);
           score=0;
      } else {

          printf("You have guessed the wrong word, better luck next time!\n\n");
          printf("---------------\n");
           printf("NAME : %s",name);
           printf("\nSCORE : %d\n",score);
           h.score=score;
           printf("NUMBER OF CORRECT GUESSES :%d",g);
           score=0;
              }

     }
     printf("\nTHE WORD NEEDED TO BE GUESSSED: %s\nTHE WORD YOU GUESSED: %s\n", guessWord, currentWord);
     printf("\n---------------\n");
     printf("\nEnter 'end' to end the game or enter 'again' to guess another word:\n");
     while ((strcmp(udi, "END") != 0) && (strcmp(udi, "AGAIN") != 0)) {
      if (strcmp(udi, "EMPTY") != 0) {
          printf("\n\nIt is not allowed to enter anything else than 'again' or 'end', try again:\n");
      }
      scanf("%s", udi);
      int x;
      for (x = 0; x < 5; x++) {
          udi[x] = toupper(udi[x]);
      }
     }
     printf("\n\n--------------------------------------------\n\n");

    }
    if(strcmp(udi,"END")==0)
    {
          int sum;
          sum=summ();
          system("cls");
          printf("\n\n\t\tNAME :        %s\n",name);
          printf("\t\tTOTAL SCORE : %d\n",sum);
          printf("\n\n\n\n");
          printf("\t----------------------------------------------------------------\n");
          printf("\t|   ####    #    #   # #####       ##   #       # #####  #####  |\n");
          printf("\t|  #       # #   ## ## #         #    #  #     #  #      #  #   |\n");
          printf("\t|  #  ##  #####  # # # ###       #    #   #   #   ###    ###    |\n");
          printf("\t|  #   #  #   #  #   # #         #    #    # #    #      #  #   |\n");
          printf("\t|   ###   #   #  #   # #####       ##       #     #####  #   #  |\n");
          printf("\t-----------------------------------------------------------------\n\n");
          FILE *f1;
          f1=fopen("high_score.txt","a");
          fprintf(f1,"%s|%d\n",h.name,h.score);
         fclose(f1);
    }
    return 0;
    }

