#ifndef UNIQUE_SYMBOLS_H
#define UNIQUE_SYMBOLS_H

char* unique_chars(const char* str1, const char* str2);

int is_char_in_str(const char* str, char c);

void add_unique(const char* basic_str, const char* comp_str, char** res_str, size_t* capacity, size_t* size);
#endif
