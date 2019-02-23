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
#include <sndfile.hh>

#include "logging.hpp"
#include "wavegen.hpp"

void usage(void){
  std::cerr << "audiowav [-h|--help] [-v|--verbose] [-q|--quiet]\n"
    << "  -h|--help : Print this help message.\n"
    << "  -v|--verbose : Increase logging verbosity.\n"
    << "  -q|--quiet : Decrease logging verbosity.\n"
    << "  -o|--output-file : Path of the output file. [default: test.wav]\n";
}

int parse_cmd_line(int argc, char **argv, char *output){
  static struct option longopts[] = {
    {"help", no_argument, NULL, 'h'},
    {"verbose", no_argument, NULL, 'v'},
    {"quiet", no_argument, NULL, 'q'},
    {"output-file", required_argument, NULL, 'o'}
  };
  // set defaults
  strcpy(output, "test.wav");

  int ch;
  while ((ch = getopt_long(argc, argv, "vqho:", longopts, NULL)) != -1) {
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
      default:
        usage();
        return EX_USAGE;
    };
  };
  return EX_OK;
}

/* Temp method for testing libsndfile support. */
int create_empty_test_file(const char *fname){
  static int buffer_len = 1024;
  static float buffer[1024]; // using values between -1.0, 1.0

	SndfileHandle file;
	int channels = 1;
	int srate = DEFAULT_FRAMERATE;

	log(L_INFO, "Creating file named '%s'\n", fname);
	file = SndfileHandle(fname, SFM_WRITE, SF_FORMAT_WAV | SF_FORMAT_FLOAT,
                       channels, srate);
	memset(buffer, 0, sizeof(buffer));
	file.write(buffer, buffer_len);

  // SndfileHandle destructor called when object out of scope
  return EX_OK;
}

int main(int argc, char **argv){
  // Set up logging to not prefix INFO messages
  L_PREFIXES[L_INFO] = "";

  char output[1024];

  int parse_result = parse_cmd_line(argc, argv, output);
  if (parse_result != EX_OK)
    return parse_result;

  log(L_INFO, "Audiowav\n");

  return create_empty_test_file(output);
}
