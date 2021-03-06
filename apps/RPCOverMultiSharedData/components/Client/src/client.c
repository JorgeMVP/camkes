/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <camkes.h>
#include <stdio.h>
#include <payload.h>

int run(void)
{
    int operands[] = { 342, 74, 283, 37, 534 };
    int sz = sizeof(operands) / sizeof(int);
    const char *name = get_instance_name();

    printf("%s: what's the answer to ", name);
    for (int i = 0; i < sz; i++) {
        printf("%d ", operands[i]);
        if (i != sz - 1) {
            printf("+ ");
        }
    }
    printf("?\n");

    payload_t p = {0};
    p.sz = sz;
    for (int i = 0; i < sz; i++) {
        p.operands[i] = operands[i];
    }

    a_calculate(&p);

    printf("%s: result was %d\n", name, p.result);
    return 0;
}
