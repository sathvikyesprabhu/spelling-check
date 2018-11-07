#include "IO.h"

static const char delim[] = {".,:;`/\"+-_(){}[]<>*&^%$#@!?~/|\\=1234567890 \t\n"};

static ENTRY *find(char *word)
{
  ENTRY e;

  e.key = word;
  return hsearch(e, FIND);
}

static int update(char *word)
{
  ENTRY *e = find(word);

  if (!e)
  return 0;

  e->data++;

  return 1;
}

int readFile(ENTRY dict)
{
  char *line, *word, *w;
  int file_size = 0;
  FILE *input_file_object = fopen(DICTIONARY, "r");

  if (!input_file_object)
    return 0;

  fseek(input_file_object, 0L, SEEK_END);
  file_size = ftell(input_file_object);
  fread(line, sizeof(char), file_size, input_file_object);

  word = strtok(line, delim);

  while(word != NULL)
  {
    /* https://stackoverflow.com/questions/2661766/c-convert-a-mixed-case-string-to-all-lower-case*/
    for ( ; *word; ++word) *word = tolower(*word);
    if (!update(w))
    {
      dict.key  = w;
      dict.data = 0;
      hsearch(dict, ENTER);
    }
    word = strtok(NULL, delim);
  }
  fclose(input_file_object);
  return 1;
}
