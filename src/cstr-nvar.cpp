#pragma once

#include "sld-strings.hpp"

namespace sld {

    SLD_STRINGS_API u32
    cstr_nvar_length(
        const cchar* str,
        const u32    size) {

        assert(str  != NULL);
        assert(size != 0);

        u32 length = 0;
        for (
            u32 i = 0;
            i < size;
            ++i) {

            if (str[i] == 0) break;
            ++length;
        }

        return(length);
    }

    SLD_STRINGS_API u32
    cstr_nvar_hash(
        const cchar* str,
        const u32    size) {

        const u32 hash = hash_u32((void*)str, size);
        return(hash);
    }

    SLD_STRINGS_API u32
    cstr_nvar_copy(
        const cchar* src_str,
        const u32    src_size,
        cchar*       dst_str,
        const u32    dst_size) {

        assert(src_str  != NULL);
        assert(src_size != 0);
        assert(dst_str  != NULL);
        assert(dst_size != 0);

        const u32 size_to_copy = (src_size <= dst_size)
            ? src_size
            : dst_size;

        u32 size_copied = 0;
        for (
            u32 i = 0;
            i < size_to_copy;
            ++i) {

            dst_str[i] = src_str[i];
            if (src_str[i] == 0) {
                break;
            }
            ++size_copied;
        }

        dst_str[dst_size - 1] = 0;

        return(size_copied);
    }

    SLD_STRINGS_API u32
    cstr_nvar_append(
        const cchar* src_str,
        const u32    src_size,
        cchar*       dst_str,
        const u32    dst_size) {

        assert(src_str  != NULL);
        assert(src_size != 0);
        assert(dst_str  != NULL);
        assert(dst_size != 0);

        // get the destination length
        const u32 dst_len = cstr_nvar_length(dst_str, dst_size);
        assert(dst_len <= dst_size);
        
        // calculate the max size we can copy
        const u32 copy_size_max = dst_size - dst_len;
        if (copy_size_max == 0) return(0);

        // determine the actual copy size
        const u32 size_to_copy = (copy_size_max <= src_size) 
            ? copy_size_max
            : src_size;
   
        u32 size_copied = 0;
        for (
            u32 i = 0;
            i < size_to_copy;
            ++i
        ) {

            const u32 dst_offset = i + dst_len;
            dst_str[dst_offset] = src_str[i];
            if (src_str[i] == 0) {
                break;
            }
            ++size_copied;
        }

        return(size_copied);
    }

    SLD_STRINGS_API bool
    cstr_nvar_equals(
        const cchar* str_a,
        const cchar* str_b,
        const u32    max_size) {

        const u32 len_a = cstr_nvar_length(str_a, max_size);
        const u32 len_b = cstr_nvar_length(str_b, max_size);
        if (len_a != len_b) return(false);

        const u32 hash_a = hash_u32((void*)str_a, len_a);
        const u32 hash_b = hash_u32((void*)str_a, len_b);
        return(hash_a == hash_b); 
    }

    SLD_STRINGS_API bool
    cstr_nvar_is_null_or_empty(
        const cchar* str,
        const u32    size) {

        const bool is_null  = (str == NULL);
        const bool is_empty = (size == 0);
        return(is_null || is_empty);
    }
};
