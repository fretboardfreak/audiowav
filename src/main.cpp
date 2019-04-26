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
#include <cstring>
#include <iostream>
#include <getopt.h>
#include <sysexits.h>

#include "logging.hpp"
#include "dsound.hpp"
#include "wavegen.hpp"

void usage(void){
  std::cerr << "audiowav [-h|--help] [-v|--verbose] [-q|--quiet]\n"
    << "  -h|--help : Print this help message.\n"
    << "  -v|--verbose : Increase logging verbosity.\n"
    << "  -q|--quiet : Decrease logging verbosity.\n"
    << "  -o|--output-file : Path of the output file. [default: test.wav]\n"
    << "  -w|--wavegen-test : Create test file using WaveGenerator class.\n";
}

int parse_cmd_line(int argc, char **argv, char *output, bool *wavegen_test){
  static struct option longopts[] = {
    {"help", no_argument, NULL, 'h'},
    {"verbose", no_argument, NULL, 'v'},
    {"quiet", no_argument, NULL, 'q'},
    {"output-file", required_argument, NULL, 'o'},
    {"wavegen-test", no_argument, NULL, 'w'}
  };
  // set defaults
  strcpy(output, "test.wav");
  *wavegen_test = false;

  int ch;
  while ((ch = getopt_long(argc, argv, "vqho:w", longopts, NULL)) != -1) {
    switch (ch) {
      case 'h':
        usage();
        // not really an error, but EX_USAGE signals the app should exit
        return EX_USAGE;
      case 'v':
        VERBOSITY++;
        break;
      case 'q':
        VERBOSITY--;
        break;
      case 'o':
        strcpy(output, optarg);
        break;
      case 'w':
        *wavegen_test = true;
        break;
      default:
        usage();
        return EX_USAGE;
    };
  };
  return EX_OK;
}

int main(int argc, char **argv){
  // Set up logging to not prefix INFO messages
  L_PREFIXES[L_INFO] = "";

  bool wavegen_test;
  char output[1024];

  int parse_result = parse_cmd_line(argc, argv, output, &wavegen_test);
  if (parse_result != EX_OK)
    return parse_result;

  log(L_INFO, "Audiowav\n");

  if (wavegen_test) {
    return create_wavegen_test_file(output);
  } else {
    log(L_INFO, "No specified job.\n");
    return EX_OK;
  }
}
