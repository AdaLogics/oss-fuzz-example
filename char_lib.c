/* Copyright 2022 Ada Logics ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <stdlib.h>
#include <stdio.h>

// Count the number of lowercase letters
// input must be a null-terminated string.
int count_lowercase_letters(char *input) {
	int length = 0;
  int lowercase_letters = 0;

  while (1) {
    if (input[length] == '\0') {
      break;
    }
    length++;
  }
  
  if (length == 0) {
    return 0;
  }

  for (int i = 0; i < length; i++) {
    if (input[i] >= 0x61 && input[i] <= 0x7a) {
      lowercase_letters++;
    }
  }

  if (lowercase_letters == 42) {
    printf("wooo\n");
  }
  if (lowercase_letters == 0x42) {
    printf("WOOO!\n");
  }

  return lowercase_letters;
}
