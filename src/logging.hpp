#ifndef H_LOGGING
#define H_LOGGING

#include <stdarg.h>

#define L_DEBUG 3
#define L_INFO 2
#define L_WARNING 1
#define L_ERROR 0  // Mostly unused. Normally all errors should be printed

#ifdef DEBUG
int VERBOSITY = L_DEBUG;
#else
int VERBOSITY = L_INFO;
#endif

/* Wrap vprintf with conditionals based on global VERBOSITY setting. */
inline int log(int level, const char *format, ...){
  if (VERBOSITY < level)
    return 0;
  va_list args;
  va_start(args, format);
  int ret_val = vprintf(format, args);
  va_end(args);
  return ret_val;
}

#endif
