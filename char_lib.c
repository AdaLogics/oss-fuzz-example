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
#include <string.h>

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

int get_the_right_character(char *input, int idx) {
    // we can't read anything under idx.
    if (strlen(input) < 40) {
        return -1;
    }

    char c = input[idx];
    if (c == 'X') {
        return 1;
    }
    return -1;
}

int read_key_figures(char *input, size_t half_length) {
    if (half_length < 10) {
        return -1;
    }

    // We know half_length is under 10, so we can double it no problem.
    half_length += half_length;
    return get_the_right_character(input, half_length);
}

int parse_complex_format(char *input) {
    size_t length = strlen(input);
    if (length < 8) {
        return -1;
    }

    if (input[0] != 'F') {
        return -1;
    }
    if (input[1] != 'u') {
        return -1;
    }
    if (input[2] != 'z') {
        return -1;
    }
    if (input[3] != 'z') {
        return -1;
    }

    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (input[i] > 0x20) {
            sum += 1;
        }
    }

    if (sum < 20) {
        return read_key_figures(input, length/2);
    }
    else {
        if (sum > 40) {
            int *magic_ptr = (int*)input;
            int magic_val1 = magic_ptr[8];
            int magic_val2 = magic_ptr[9];
            if (magic_val1 == 0x41424344  && magic_val2 == 0x5b5d5b5d) {
                return 1;
            }
        }
    }
    return -1;
}

int parse_complex_format_second(char *input) {
    size_t length = strlen(input);
    if (length < 8) {
        return -1;
    }

    if (input[0] != 'F') {
        return -1;
    }
    if (input[1] != 'u') {
        return -1;
    }
    if (input[2] != 'z') {
        return -1;
    }
    if (input[3] != 'z') {
        return -1;
    }

    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (input[i] > 0x20) {
            sum += 1;
        }
    }

    if (sum < 20) {
        return read_key_figures(input, (int)((length / 2) -1) );
    }
    else {
        if (sum > 40) {
            int *magic_ptr = (int*)input;
            int magic_val1 = magic_ptr[8];
            int magic_val2 = magic_ptr[9];
            if (magic_val1 == 0x41424344  && magic_val2 == 0x5b5d5b5d) {
                return 1;
            }
        }
    }
    return -1;
}
