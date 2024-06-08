#include "../headers/util.h"

void str_reverse(char* str, size_t length) {
  int start = 0;
  int end = length - 1;
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    end--;
    start++;
  }
}

void long_to_ascii(long num, char* str) {
  int i = 0;
  int is_negative = 0;
  if (num < 0) {
    is_negative = 1;
    num = -num;
  }
  if (num == 0) {
    str[i++] = '0';
  }
  while (num != 0) {
    str[i++] = (num % 10) + '0';
    num /= 10;
  }
  if (is_negative) {
    str[i++] = '-';
  }
  str[i] = '\0';
  str_reverse(str,i);
}