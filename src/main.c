#include "IO.h"

#define DICT_SIZE 3000000

int main(int argc, char** argv)
{
  if(argc != 2)
  {
    fprintf(stderr, "Usage: ./spellcheck <word>\n");
    exit(0);
  }

  ENTRY dict;
  hcreate(DICT_SIZE);

  if(!readFile(dict))
  {
    fprintf(stderr, "\nCould not read dictionary file: %s\n", DICTIONARY);
    exit(0);
  }
  char* suggestion = "the";
  //suggestion = correct(argv[1]);

  if (strcmp(suggestion, argv[1]))
    printf("Did you mean \"%s\"?\n", suggestion);
  else
    printf("\"%s\" is correct!\n", argv[1]);

  return 0;
}
