#ifndef InputOutput
#define InputOutput

/*http://pubs.opengroup.org/onlinepubs/7908799/xsh/search.h.html*/
#include<search.h>
const char delim[] = {".,:;`/\"+-_(){}[]<>*&^%$#@!?~/|\\=1234567890 \t\n"};

/*
  Function to read the Dictionary file any add words into a Dictionary
  Input
    input_file_name: path to dictionary file
    dict: structure with char* key and void* data for searching
  Output
    0: The dictionary file could not be read
    1: The dictionary file was read and words were put into a dictionary
*/
int readFile(char* input_file_name, ENTRY dict);
#endif
