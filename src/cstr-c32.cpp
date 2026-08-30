#include "sld-strings.hpp"

namespace sld {

    SLD_STRINGS_API u32
    cstr_c32_length(
        const cstr_c32* str) {

        assert(str != NULL); 

        const u32 length = cstr_nvar_length(str->chars, 32);

        return(length);
    }

    SLD_STRINGS_API u32
    cstr_c32_hash(
        const cstr_c32* str) {

        assert(str);

        const u32 hash = hash_u32((void*)str->chars, 32);

        return(hash);
    }

    SLD_STRINGS_API u32
    cstr_c32_copy(
        const cstr_c32* str_src,
        cstr_c32*       str_dst) {

        assert(str_src != NULL); 
        assert(str_dst != NULL); 
    
        const u32 length_copied = cstr_nvar_copy(
            str_src->chars, 32,
            str_dst->chars, 32
        );
    
        return(length_copied);
    }

    SLD_STRINGS_API u32
    cstr_c32_append(
        const cstr_c32* str_src,
        cstr*          str_dst) {

        assert(str_src != NULL); 
        assert(str_dst != NULL); 
    
        const u32 length_copied = cstr_nvar_append(
            str_src->chars, 32,
            str_dst->chars, 32
        );
    
        return(length_copied);
    }

    SLD_STRINGS_API bool
    cstr_c32_equals(
        const cstr_c32* str_a,
        const cstr_c32* str_b) {

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
    cstr_c32_is_null_or_empty(
        const cstr_c32* str) {

        const bool is_null_or_empty = cstr_nvar_is_null_or_empty(str->chars, 32);
        return(is_null_or_empty);
    }
};
