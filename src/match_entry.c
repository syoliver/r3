/*
 * match_entry.c
 * Copyright (C) 2014 c9s <yoanlin93@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcre.h>
#include <assert.h>
#include <stdbool.h>

#include "r3.h"
#include "z_malloc.h"

match_entry * match_entry_createl(const char * path, int path_len) {
    match_entry * entry = z_malloc(sizeof(match_entry));
    if(!entry)
        return NULL;
    entry->vars = str_array_create(3);
    entry->path = path;
    entry->path_len = path_len;
    entry->data = NULL;
    return entry;
}

void match_entry_free(match_entry * entry) {
    assert(entry);
    if (entry->vars) {
        str_array_free(entry->vars);
    }
    z_free(entry);
}
