#include "sld-strings.hpp"

namespace sld {

    SLD_STRINGS_API u32
    cstr_c8_length(
        const cstr_c8* str) {

        assert(str != NULL); 

        const u32 length = cstr_nvar_length(str->chars, 8);

        return(length);
    }

    SLD_STRINGS_API u32
    cstr_c8_hash(
        const cstr_c8* str) {

        assert(str);

        const u32 hash = hash_u32((void*)str->chars, 8);

        return(hash);
    }

    SLD_STRINGS_API u32
    cstr_c8_copy(
        const cstr_c8* str_src,
        cstr_c8*       str_dst) {

        assert(str_src != NULL); 
        assert(str_dst != NULL); 
    
        const u32 length_copied = cstr_nvar_copy(
            str_src->chars, 8,
            str_dst->chars, 8
        );
    
        return(length_copied);
    }

    SLD_STRINGS_API u32
    cstr_c8_append(
        const cstr_c8* str_src,
        cstr*          str_dst) {

        assert(str_src != NULL); 
        assert(str_dst != NULL); 
    
        const u32 length_copied = cstr_nvar_append(
            str_src->chars, 8,
            str_dst->chars, 8
        );
    
        return(length_copied);
    }

    SLD_STRINGS_API bool
    cstr_c8_equals(
        const cstr_c8* str_a,
        const cstr_c8* str_b) {

        assert(str_a);
        assert(str_b);

        const bool does_equal = cstr_nvar_equals(
            str_a->chars, 
            str_b->chars,
            8
        );

        return(does_equal);
    }

    SLD_STRINGS_API bool
    cstr_c8_is_null_or_empty(
        const cstr_c8* str) {

        const bool is_null_or_empty = cstr_nvar_is_null_or_empty(str->chars, 8);
        return(is_null_or_empty);
    }
};
