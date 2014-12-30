// debug.h 
// Copyright 2014 by Towry Wang

#ifndef _DEBUG_H
#define _DEBUG_H

#include "console-colors.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef DEBUG 

#define debug(m, ...) fprintf(stdout, "[DEBUG] %s:%d: " m "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define debug(m, ...)
#endif

#define err_to_str() (errno == 0 ? "None" : strerror(errno))

#define log_err(m, ...) ({ \
  cc_fprintf(CC_FG_DARK_RED, stderr, "[ERROR] "); \
  fprintf(stderr, m "\n", ##__VA_ARGS__); \
})

#define log_warn(m, ...) ({ \
  cc_fprintf(CC_FG_DARK_YELLOW, stdout, "[WARN] (%s:%d: errno: %s) ", __FILE__, __LINE__, err_to_str()); \
  fprintf(stdout, m "\n", ##__VA_ARGS__); \
})

#define log_info(m, ...) ({ \
  cc_fprintf(CC_FG_CYAN, stdout, "[INFO] (%s:%d) ", __FILE__, __LINE__); \
  fprintf(stdout, m "\n",  ##__VA_ARGS__); \
})

#define out_of_memory() log_err("Out of memory.")

#endif
