#include "sld-strings.hpp"

namespace sld {

    SLD_STRINGS_API u32
    cstr_length(
        const cstr* str) {

        assert(str);

        const u32 length = cstr_nvar_length(str->chars, str->size);

        return(length);
    }

    SLD_STRINGS_API u32
    cstr_hash(
        const cstr* str) {

        assert(str);

        const u32 hash = cstr_nvar_hash(str->chars, str->size);
        return(hash);
    }

    SLD_STRINGS_API u32
    cstr_copy(
        const cstr* str_src,
        cstr*       str_dst) {

        assert(str_src != NULL);
        assert(str_dst != NULL);

        const u32 length_copied = cstr_nvar_copy(
            str_src->chars,
            str_src->size,
            str_dst->chars,
            str_dst->size
        );

        return(length_copied);
    }

    SLD_STRINGS_API u32
    cstr_append(
        const cstr* str_src,
        cstr*       str_dst) {

        assert(str_src != NULL);
        assert(str_dst != NULL);

        const u32 length_copied = cstr_nvar_append(
            str_src->chars,
            str_src->size,
            str_dst->chars,
            str_dst->size
        );

        return(length_copied);
    }

    SLD_STRINGS_API bool
    cstr_equals(
        const cstr* str_a,
        const cstr* str_b) {

        assert(str_a != NULL);
        assert(str_b != NULL);
        if (str_a->size != str_b->size) return(false);

        const bool does_equal = cstr_nvar_equals(str_a->chars, str_b->chars, str_a->size);

        return(does_equal);
    }

    SLD_STRINGS_API bool
    cstr_is_null_or_empty(
        const cstr* str) {

        if (str == NULL)        return(true);
        if (str->chars == NULL) return(true);
        if (str->chars[0] == 0) return(true);

        return(false);
    }
};
