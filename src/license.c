#include <stdio.h>
#include "license.h"

void printLicenseInformation(const char* restrict name, const char* restrict year, const char* restrict author) {
    printf(
        " * %s  Copyright (C) %s  %s\n"
        " * This program comes with ABSOLUTELY NO WARRANTY.\n"
        " * This is free software, and you are welcome to redistribute it\n"
        " * under certain conditions.\n *\n"
        " * See <https://www.gnu.org/licenses/> for details.\n\n",
        name,
        year,
        author
    );
}
