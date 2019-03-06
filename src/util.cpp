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

#include <cmath>
// enable if max_diff defined using std::numeric_limits
// #include <limits>

#include "logging.hpp"

/* Test whether float A is close enough to float B to call them equal. */
bool is_close(float A, float B){
  float max_rel_diff = 0.05;
  // could also use "std::numeric_limits<float>::min() * 10;" for max_diff
  float max_diff = 0.01;

  // Check if the numbers are really close -- needed
  // when comparing numbers near zero.
  float diff = std::fabs(A - B);
  if (diff <= max_diff){
    log(L_DEBUG, "      closer than %f\n", max_diff);
    return true;
  }

  A = std::fabs(A);
  B = std::fabs(B);
  float largest = (B > A) ? B : A;

  if (diff <= largest * max_rel_diff){
    log(L_DEBUG, "      closer than %f %\n", max_rel_diff);
    return true;
  }
  log(L_DEBUG, "      not close\n");
  return false;
}
