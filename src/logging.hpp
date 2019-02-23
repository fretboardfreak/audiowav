/*
 * Copyright 2019 Curtis Sand
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef LOGGING_HPP
#define LOGGING_HPP
/*
 * logging.hpp : Library providing app wide log verbosity support.
 */

#include <stdarg.h>
#include <stdio.h>
#include <map>
#include <string>

#define L_DEBUG 3
#define L_INFO 2
#define L_WARNING 1

// Not usually used for a VERBOSITY setting.
// L_ERROR messages go to stderr instead of stdout.
#define L_ERROR 0

#ifdef DEBUG
inline int VERBOSITY = L_DEBUG;
#else
inline int VERBOSITY = L_INFO;
#endif

// Prefixes to be appended to log messages
inline std::map<int,std::string> L_PREFIXES = {
  {L_ERROR, "ERR: "},
  {L_WARNING, "WRN: "},
  {L_INFO, "INF: "},
  {L_DEBUG, "DBG: "}
};

/* Wrap vfprintf with conditionals based on global VERBOSITY setting. */
inline int log(int level, const char *format, ...){
  if (VERBOSITY < level)
    return 0;
  va_list args;
  va_start(args, format);
  // append prefix here
  std::string fmt (format);
  std::string output = L_PREFIXES[level] + fmt;
  int ret_val;
  if (level == L_ERROR)
    ret_val = vfprintf(stderr, output.c_str(), args);
  else
    ret_val = vfprintf(stdout, output.c_str(), args);
  va_end(args);
  return ret_val;
}

#endif
