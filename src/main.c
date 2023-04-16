/**
 * c_cipher – a simple cli tool for symmetric de-/encryption
 * Copyright (C) 2023  Johannes Nielsen
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "license.h"
#include "stralloc.h"

int main(void) {
    printLicenseInformation("c_cipher", "2023", "Johannes Nielsen");
    char* key = NULL;
    char* msg = NULL;
    printf("Please enter your secret key: ");
    if (readString(&key) == 0) {
        printf("Unable to allocate memory for the key. Exiting.\n");
        free(key);
        key = NULL;
        return EXIT_FAILURE;
    }
    printf("Please enter a line of text do de- or encrypt using your key: ");
    if (readString(&msg) == 0) {
        printf("Unable to allocate memory for the message. Exiting.\n");
        free(key);
        key = NULL;
        free(msg);
        msg = NULL;
        return EXIT_FAILURE;
    }

    size_t l = strlen(msg);
    size_t kl = strlen(key);

    for (size_t i = 0; i < l; ++i) {
        *(msg + i) ^= *(key + (i % kl));
        printf("%d\n", *(msg + i));
    }

    printf("%s\n", msg);

    free(key);
    key = NULL;
    free(msg);
    msg = NULL;

    return EXIT_SUCCESS;
}
