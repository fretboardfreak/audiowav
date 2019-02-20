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
#include <iostream>
#include <getopt.h>

#include "logging.hpp"
#include "wavegen.hpp"

void parse_cmd_line(int argc, char **argv){
  log(L_DEBUG, "parse_cmd_line not implemented: %d args found\n" , argc);
}

int main(int argc, char **argv){
  log(L_INFO, "Audiowav\n");
  parse_cmd_line(argc, argv);
  return 0;
}
