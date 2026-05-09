#include "sld-strings.hpp"

namespace sld {

    //--------------------------------------------------------------------
    // DEFINITIONS
    //--------------------------------------------------------------------

    struct string_c32 {
        cchar8 buffer[SIZE_STRING_32];
    };

    //--------------------------------------------------------------------
    // CONSTANTS
    //--------------------------------------------------------------------

    static constexpr u32 STRUCT_SIZE_C32 = sizeof(string_c32);
    
    //--------------------------------------------------------------------
    // METHODS
    //--------------------------------------------------------------------

    SLD_STRING_API u32
    string_c32_memory_size (
        void) {

        return(STRUCT_SIZE_C32);
    }

    SLD_STRING_API string_c32*
    string_c32_create(
        const cchar8* c_str) {

        // allocate memory
        auto mem = malloc(STRUCT_SIZE_C32);
        assert(mem);

        // initialize memory
        memset(mem, 0, STRUCT_SIZE_C32);
        string_c32* str = (string_c32*)mem;        

        // if we have an input buffer, copy it to the string
        if (c_str) {

            // copy at most 32 bytes to the string
            const u32 length = strnlen_s(c_str, STRING_SIZE_32);
            memmove_s(
                (void*)str->buffer                                // dst ptr
                STRUCT_SIZE_C32,                                  // dst size
                c_str                                             // src ptr
                length > STRING_SIZE_32 ? STRING_SIZE_32 : length // src size  
            );

            // ensure the string is terminated
            str->buffer[STRING_SIZE_32 - 1] = STRING_TERMINATOR;
        }

        // validate and return the string
        string_c32_assert_valid(str);
        return(str);

    }

    SLD_STRING_API string_c32*
    string_c32_init (
        const u32     mem_size,
        void*         mem_ptr,
        const cchar8* c_str) {

    }

    SLD_STRING_API void
    string_c32_destroy(
        const string_c32* str) {

        string_c32_assert_valid(str);

        free(str);
    }

    SLD_STRING_API void
    string_c32_assert_valid(
        const string_c32* str) {

        assert(
            str             != NULL &&
            str->buffer[31] == STRING_TERMINATOR
        );
    }

    SLD_STRING_API bool
    string_c32_is_empty(
        const string_c32* str) {

        string_c32_assert_valid(str);

        const bool is_empty = (str->buffer[0] == STRING_TERMINATOR)
        return(is_empty);
    }

    SLD_STRING_API u32
    string_c32_length(
        const string_c32* str) {

        string_c32_assert_valid(str);

        // search for terminator
        u32 length = 0;
        for (
            u32 length = 0;
                length < STRING_SIZE_32;
              ++length) {

            if (str->buffer[length] == STRING_TERMINATOR) {
                break;
            }
        }        

        return(length);
    }

    SLD_STRING_API hash32
    string_c32_hash_32(
        const string_c32* str) {

        string_c32_assert_valid(str);

        const hash32 hash = string_c_hash_32(str->buffer, STRING_SIZE_32);
        return(hash);
    }

    SLD_STRING_API hash64
    string_c32_hash_64(
        const string_c32* str) {

        string_c32_assert_valid(str);

        const hash64 hash = string_c_hash_64(str->buffer, STRING_SIZE_32);
        return(hash);
    }

    SLD_STRING_API hash128
    string_c32_hash_128(
        const string_c32* str) {

        string_c32_assert_valid(str);

        const hash128 hash = string_c_hash_128(str->buffer, STRING_SIZE_32);
        return(hash);
    }

    SLD_STRING_API const cchar8*
    string_c32_char_buffer(
        const string_c32* str) {

        string_c32_assert_valid(str);

        return((const char*)str->buffer);        
    }

    SLD_STRING_API u32
    string_c32_exists(
        const string_c32* str,
        cchar8*           sub_string) {

    }

    SLD_STRING_API const cchar8*
    string_c32_copy_to_string(
        const string_c32* src_str,
        string_c32*       dst_str) {

    }

    SLD_STRING_API const cchar8*
    string_c32_copy_to_buffer(
        const string_c32* src_str,
        cchar8*           dst_buf) {

    }

    SLD_STRING_API const cchar8*
    string_c32_substring(
        const string_c32* dst_str,
        const u32         position) {

    }
    
    SLD_STRING_API const bool
    string_c32_does_a_equal_b(
        const string_c32* str_a,
        const string_c32* str_a) {

        const hash128 str_a_hash = string_c_hash_128(str_a->buffer, STRING_SIZE_32);
        const hash128 str_b_hash = string_c_hash_128(str_b->buffer, STRING_SIZE_32);
    
        const bool is_equal = (
            str_a_hash.hi == str_b_hash.hi &&
            str_a_hash.lo == str_b_hash.lo
        );

        return(is_equal);
    }

    SLD_STRING_API const cchar8*
    string_c32_tokenize(
        const string_c32* str,
        const cchar8*     delimiter,
        const cchar8*     previous_token) {

    }

    SLD_STRING_API const cchar8*
    string_c32_append(
        string_c32*   dst_str,
        const cchar8* src) {

    }

    SLD_STRING_API const cchar8*
    string_c32_update(
        string_c32*   dst_str,
        const u32     position,
        const cchar8* buf) {
        
    }
};