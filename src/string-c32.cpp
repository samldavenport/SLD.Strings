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
    string_c32_init             (const u32     mem_size, void* mem_ptr, const cchar8* c_str = NULL);
    SLD_STRING_API void          string_c32_destroy          (const string_c32* str);
    SLD_STRING_API void          string_c32_assert_valid     (const string_c32* str);
    SLD_STRING_API bool          string_c32_is_empty         (const string_c32* str);
    SLD_STRING_API u32           string_c32_length           (const string_c32* str);
    SLD_STRING_API hash32        string_c32_hash_32          (const string_c32* str);
    SLD_STRING_API hash64        string_c32_hash_64          (const string_c32* str);
    SLD_STRING_API hash128       string_c32_hash_128         (const string_c32* str);
    SLD_STRING_API const cchar8* string_c32_char_buffer      (const string_c32* str);
    SLD_STRING_API u32           string_c32_exists           (const string_c32* str,     const cchar*      sub_string);
    SLD_STRING_API const cchar8* string_c32_copy_to_string   (const string_c32* src_str, const string_c32* dst_str);
    SLD_STRING_API const cchar8* string_c32_copy_to_buffer   (const string_c32* src_str, const cchar8*     dst_buf);
    SLD_STRING_API const cchar8* string_c32_substring        (const string_c32* dst_str, const u32         position);
    SLD_STRING_API const bool    string_c32_does_a_equal_b   (const string_c32* str_a,   const string_c32* str_a);
    SLD_STRING_API const cchar8* string_c32_tokenize         (const string_c32* str,     const cchar8*     delimiter, const cchar*  previous_token = NULL);
    SLD_STRING_API const cchar8* string_c32_append           (string_c32*       dst_str, const cchar8*     src);
    SLD_STRING_API const cchar8* string_c32_update           (string_c32*       dst_str, const u32         position,  const cchar8* buf);

};