#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* const Kat[5] = 
{
"  /\\_/\\  (  ",
" ( ^.^ ) _) ",
"  \\ v / (   MEOW!",
" ( | | )/   ",
"(__q p__)   ",
};



int main(int argc, char *argv[])
{
 
 printf("\n");
 
 for(int i = 0; i < 5; i++) 
 {
    printf("%s\n", Kat[i]);
 } 

 printf("\n");
  char ch;  //A char
  FILE *fl; //File
  if(argc < 2)
  {
    printf("Usage: %s <input file>\n", argv[0]);
    return EXIT_FAILURE;
  }
  
  fl = fopen(argv[1], "rb"); // Open a file
  if(!fl)
  {
   perror(argv[0]); //Show the error
   return EXIT_FAILURE;        //End the program
  }

  //Get the file's size
 
  fseek(fl, 0, SEEK_END); 
  int siz = ftell(fl); 
  fseek(fl, 0, SEEK_SET); 
  

  printf("+-[%s] (%d bytes)-+\n\n", argv[1], siz); //Printf the name of the file
  unsigned char buffer[1024];
  size_t amount;
  while(amount = fread(buffer, 1, sizeof(buffer), fl))
  {
    fwrite(buffer, 1, amount, stdout); //Read the file
  }

  fclose(fl); //Close the file
  return 0;   //End the program
}

