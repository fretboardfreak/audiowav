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

#include "mygtest.hpp"
#include "gtest/gtest.h"

#include "util.hpp"

TEST(UtilTests, isCloseNearZero){
  // max_diff is the important number here. Set at 0.01
  float A=0.1234, B=0.1334;
  bool test = is_close(A, B);
  ASSERT_EQ(test, true);

  A=0.1234, B=0.1344;
  test = is_close(A, B);
  ASSERT_EQ(test, false);
}

TEST(UtilTests, isCloseLarge){
  // max_rel_diff is the important number here. Set at 0.05 (5%)
  float A=123456789, B=123456788;
  bool test = is_close(A, B);
  ASSERT_EQ(test, true);

  A = 123456789;
  B = A * 1.055;
  test = is_close(A, B);
  ASSERT_EQ(test, false);
}
