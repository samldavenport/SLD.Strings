#ifndef SLD_STRINGS_HPP
#define SLD_STRINGS_HPP

#include <Windows.h>
#include <cstdint>
#include <assert.h>

namespace sld {

    //--------------------------------------------------------------------
    // MACROS
    //--------------------------------------------------------------------

    #define SLD_STRING_API

    //--------------------------------------------------------------------
    // CONSTANTS
    //--------------------------------------------------------------------

    static constexpr u32 STRING_TERMINATOR = 0;
    static constexpr u32 STRING_SIZE_32    = 32;
    static constexpr u32 STRING_SIZE_64    = 64;
    static constexpr u32 STRING_SIZE_128   = 128;
    static constexpr u32 STRING_SIZE_256   = 256;

    //--------------------------------------------------------------------
    // SLD TYPES
    //--------------------------------------------------------------------

#   ifndef SLD_TYPES
#   define SLD_TYPES

    // signed integers
    typedef int8_t   s8;
    typedef int16_t  s16;
    typedef int32_t  s32;
    typedef int64_t  s64;

    struct s128 {
        union {
            struct {
                s64 hi;
                s64 lo;
            };
            s64 val[2];
        };
    };


    // unsigned integers
    typedef uint8_t  u8;
    typedef uint16_t u16;
    typedef uint32_t u32;
    typedef uint64_t u64;

    struct u128 {
        union {
            struct {
                u64 hi;
                u64 lo;
            };
            u64 val[2];
        };
    };

    // booleans
    typedef u8  b8;
    typedef u16 b16;
    typedef u32 b32;
    typedef u64 b64;

    // characters
    typedef char    cchar8;
    typedef wchar_t wchar16;

    // memory
    typedef u8       byte;
    typedef vptr     void*;
    typedef intptr_t addr;
    typedef u32      index;
    typedef void     element;
    typedef void     key;
    typedef void     value;

    // hash
    typedef u32  hash32;
    typedef u64  hash64;
    typedef u128 hash128;

#   endif //SLD_TYPES

    //--------------------------------------------------------------------
    // STRING TYPES
    //--------------------------------------------------------------------

    // c cstrings
    typedef struct string_c32;
    typedef struct string_c64;
    typedef struct string_c128;
    typedef struct string_c256;
    typedef struct string_cnvar;
    
    // w strings
    typedef struct string_w32;
    typedef struct string_w64;
    typedef struct string_w128;
    typedef struct string_w256;
    typedef struct string_wnvar;

    //--------------------------------------------------------------------
    // C STRING 32
    //--------------------------------------------------------------------

    SLD_STRING_API u32           string_c32_memory_size      (void);
    SLD_STRING_API string_c32*   string_c32_create           (const cchar8* c_str = NULL);
    SLD_STRING_API string_c32*   string_c32_init             (const u32     mem_size, void* mem_ptr, const cchar8* c_str = NULL);
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

    //--------------------------------------------------------------------
    // C STRING 64
    //--------------------------------------------------------------------

    SLD_STRING_API u32           string_c64_memory_size      (void);
    SLD_STRING_API string_c64*   string_c64_create           (const cchar8* c_str = NULL);
    SLD_STRING_API string_c64*   string_c64_init             (const u32     mem_size, void* mem_ptr, const cchar8* c_str = NULL);
    SLD_STRING_API void          string_c64_destroy          (const string_c64* str);
    SLD_STRING_API void          string_c64_assert_valid     (const string_c64* str);
    SLD_STRING_API bool          string_c64_is_empty         (const string_c64* str);
    SLD_STRING_API u32           string_c64_length           (const string_c64* str);
    SLD_STRING_API hash32        string_c64_hash_32          (const string_c64* str);
    SLD_STRING_API hash64        string_c64_hash_64          (const string_c64* str);
    SLD_STRING_API hash128       string_c64_hash_128         (const string_c64* str);
    SLD_STRING_API const cchar8* string_c64_char_buffer      (const string_c64* str);
    SLD_STRING_API u32           string_c64_exists           (const string_c64* str,     const cchar*      sub_string);
    SLD_STRING_API const cchar8* string_c64_copy_to_string   (const string_c64* src_str, const string_c64* dst_str);
    SLD_STRING_API const cchar8* string_c64_copy_to_buffer   (const string_c64* src_str, const cchar8*     dst_buf);
    SLD_STRING_API const cchar8* string_c64_substring        (const string_c64* dst_str, const u32         position);
    SLD_STRING_API const bool    string_c64_does_a_equal_b   (const string_c64* str_a,   const string_c64* str_a);
    SLD_STRING_API const cchar8* string_c64_tokenize         (const string_c64* str,     const cchar8*     delimiter, const cchar*  previous_token = NULL);
    SLD_STRING_API const cchar8* string_c64_append           (string_c64*       dst_str, const cchar8*     src);
    SLD_STRING_API const cchar8* string_c64_update           (string_c64*       dst_str, const u32         position,  const cchar8* buf);

    //--------------------------------------------------------------------
    // C STRING 128
    //--------------------------------------------------------------------
 
    SLD_STRING_API u32           string_c128_memory_size     (void);
    SLD_STRING_API string_c128*  string_c128_create          (const cchar8* c_str = NULL);
    SLD_STRING_API string_c128*  string_c128_init            (const u32     mem_size, void* mem_ptr, const cchar8* c_str = NULL);
    SLD_STRING_API void          string_c128_destroy         (const string_c128* str);
    SLD_STRING_API void          string_c128_assert_valid    (const string_c128* str);
    SLD_STRING_API bool          string_c128_is_empty        (const string_c128* str);
    SLD_STRING_API u32           string_c128_length          (const string_c128* str);
    SLD_STRING_API hash32        string_c128_hash_32         (const string_c128* str);
    SLD_STRING_API hash64        string_c128_hash_64         (const string_c128* str);
    SLD_STRING_API hash128       string_c128_hash_128        (const string_c128* str);
    SLD_STRING_API const cchar8* string_c128_char_buffer     (const string_c128* str);
    SLD_STRING_API u32           string_c128_exists          (const string_c128* str,     const cchar*       sub_string);
    SLD_STRING_API const cchar8* string_c128_copy_to_string  (const string_c128* src_str, const string_c128* dst_str);
    SLD_STRING_API const cchar8* string_c128_copy_to_buffer  (const string_c128* src_str, const cchar8*      dst_buf);
    SLD_STRING_API const cchar8* string_c128_substring       (const string_c128* dst_str, const u32          position);
    SLD_STRING_API const bool    string_c128_does_a_equal_b  (const string_c128* str_a,   const string_c128* str_a);
    SLD_STRING_API const cchar8* string_c128_tokenize        (const string_c128* str,     const cchar8*      delimiter, const cchar*  previous_token = NULL);
    SLD_STRING_API const cchar8* string_c128_append          (string_c128*       dst_str, const cchar8*      src);
    SLD_STRING_API const cchar8* string_c128_update          (string_c128*       dst_str, const u32          position,  const cchar8* buf);

    //--------------------------------------------------------------------
    // C STRING NVAR
    //--------------------------------------------------------------------

    SLD_STRING_API u32           string_cnvar_memory_size    (const u32 str_size);
    SLD_STRING_API string_cnvar* string_cnvar_create         (const u32 str_size, const cchar8* c_str = NULL);
    SLD_STRING_API string_cnvar* string_cnvar_init           (const u32 str_size, const u32 mem_size, void* mem_ptr, const cchar8* c_str = NULL);
    SLD_STRING_API void          string_cnvar_destroy        (const string_cnvar* str);
    SLD_STRING_API void          string_cnvar_assert_valid   (const string_cnvar* str);
    SLD_STRING_API bool          string_cnvar_is_empty       (const string_cnvar* str);
    SLD_STRING_API u32           string_cnvar_length         (const string_cnvar* str);
    SLD_STRING_API hash32        string_cnvar_hash_32        (const string_cnvar* str);
    SLD_STRING_API hash64        string_cnvar_hash_64        (const string_cnvar* str);
    SLD_STRING_API hash128       string_cnvar_hash_128       (const string_cnvar* str);
    SLD_STRING_API const cchar8* string_cnvar_char_buffer    (const string_cnvar* str);
    SLD_STRING_API u32           string_cnvar_exists         (const string_cnvar* str,     const cchar*        sub_str_ptr, const u32 sub_str_size);
    SLD_STRING_API const cchar8* string_cnvar_copy_to_string (const string_cnvar* src_str, const string_cnvar* dst_str_ptr, const u32 dst_str_size);
    SLD_STRING_API const cchar8* string_cnvar_copy_to_buffer (const string_cnvar* src_str, const cchar8*       dst_buf_ptr, const u32 dst_buf_size);
    SLD_STRING_API const cchar8* string_cnvar_substring      (const string_cnvar* dst_str, const u32           position);
    SLD_STRING_API const bool    string_cnvar_does_a_equal_b (const string_cnvar* str_a,   const string_cnvar* str_a);
    SLD_STRING_API const cchar8* string_cnvar_tokenize       (const string_cnvar* str,     const cchar8*       delimiter, const u32 token_size, const cchar*  previous_token = NULL);
    SLD_STRING_API const cchar8* string_cnvar_append         (string_cnvar*       dst_str, const cchar8*       src_ptr,   const u32 src_size);
    SLD_STRING_API const cchar8* string_cnvar_update         (string_cnvar*       dst_str, const u32           dst_pos,   const cchar8* dst_buf_ptr, const u32 dst_buf_size);

    //--------------------------------------------------------------------
    // W STRING 32
    //--------------------------------------------------------------------

    SLD_STRING_API u32           string_w32_memory_size      (void);
    SLD_STRING_API string_w32*   string_w32_create           (const cchar8* c_str = NULL);
    SLD_STRING_API string_w32*   string_w32_init             (const u32     mem_size, void* mem_ptr, const cchar8* c_str = NULL);
    SLD_STRING_API void          string_w32_destroy          (const string_w32* str);
    SLD_STRING_API void          string_w32_assert_valid     (const string_w32* str);
    SLD_STRING_API bool          string_w32_is_empty         (const string_w32* str);
    SLD_STRING_API u32           string_w32_length           (const string_w32* str);
    SLD_STRING_API hash32        string_w32_hash_32          (const string_w32* str);
    SLD_STRING_API hash64        string_w32_hash_64          (const string_w32* str);
    SLD_STRING_API hash128       string_w32_hash_128         (const string_w32* str);
    SLD_STRING_API const cchar8* string_w32_char_buffer      (const string_w32* str);
    SLD_STRING_API u32           string_w32_exists           (const string_w32* str,     const cchar*      sub_string);
    SLD_STRING_API const cchar8* string_w32_copy_to_string   (const string_w32* src_str, const string_w32* dst_str);
    SLD_STRING_API const cchar8* string_w32_copy_to_buffer   (const string_w32* src_str, const cchar8*     dst_buf);
    SLD_STRING_API const cchar8* string_w32_substring        (const string_w32* dst_str, const u32         position);
    SLD_STRING_API const bool    string_w32_does_a_equal_b   (const string_w32* str_a,   const string_w32* str_a);
    SLD_STRING_API const cchar8* string_w32_tokenize         (const string_w32* str,     const cchar8*     delimiter, const cchar*  previous_token = NULL);
    SLD_STRING_API const cchar8* string_w32_append           (string_w32*       dst_str, const cchar8*     src);
    SLD_STRING_API const cchar8* string_w32_update           (string_w32*       dst_str, const u32         position,  const cchar8* buf);

    //--------------------------------------------------------------------
    // W STRING 64
    //--------------------------------------------------------------------

    SLD_STRING_API u32           string_w64_memory_size      (void);
    SLD_STRING_API string_w64*   string_w64_create           (const cchar8* c_str = NULL);
    SLD_STRING_API string_w64*   string_w64_init             (const u32     mem_size, void* mem_ptr, const cchar8* c_str = NULL);
    SLD_STRING_API void          string_w64_destroy          (const string_w64* str);
    SLD_STRING_API void          string_w64_assert_valid     (const string_w64* str);
    SLD_STRING_API bool          string_w64_is_empty         (const string_w64* str);
    SLD_STRING_API u32           string_w64_length           (const string_w64* str);
    SLD_STRING_API hash32        string_w64_hash_32          (const string_w64* str);
    SLD_STRING_API hash64        string_w64_hash_64          (const string_w64* str);
    SLD_STRING_API hash128       string_w64_hash_128         (const string_w64* str);
    SLD_STRING_API const cchar8* string_w64_char_buffer      (const string_w64* str);
    SLD_STRING_API u32           string_w64_exists           (const string_w64* str,     const cchar*      sub_string);
    SLD_STRING_API const cchar8* string_w64_copy_to_string   (const string_w64* src_str, const string_w64* dst_str);
    SLD_STRING_API const cchar8* string_w64_copy_to_buffer   (const string_w64* src_str, const cchar8*     dst_buf);
    SLD_STRING_API const cchar8* string_w64_substring        (const string_w64* dst_str, const u32         position);
    SLD_STRING_API const bool    string_w64_does_a_equal_b   (const string_w64* str_a,   const string_w64* str_a);
    SLD_STRING_API const cchar8* string_w64_tokenize         (const string_w64* str,     const cchar8*     delimiter, const cchar*  previous_token = NULL);
    SLD_STRING_API const cchar8* string_w64_append           (string_w64*       dst_str, const cchar8*     src);
    SLD_STRING_API const cchar8* string_w64_update           (string_w64*       dst_str, const u32         position,  const cchar8* buf);

    //--------------------------------------------------------------------
    // W STRING 128
    //--------------------------------------------------------------------

    SLD_STRING_API u32           string_w128_memory_size     (void);
    SLD_STRING_API string_w128*  string_w128_create          (const cchar8* c_str = NULL);
    SLD_STRING_API string_w128*  string_w128_init            (const u32     mem_size, void* mem_ptr, const cchar8* c_str = NULL);
    SLD_STRING_API void          string_w128_destroy         (const string_w128* str);
    SLD_STRING_API void          string_w128_assert_valid    (const string_w128* str);
    SLD_STRING_API bool          string_w128_is_empty        (const string_w128* str);
    SLD_STRING_API u32           string_w128_length          (const string_w128* str);
    SLD_STRING_API hash32        string_w128_hash_32         (const string_w128* str);
    SLD_STRING_API hash64        string_w128_hash_64         (const string_w128* str);
    SLD_STRING_API hash128       string_w128_hash_128        (const string_w128* str);
    SLD_STRING_API const cchar8* string_w128_char_buffer     (const string_w128* str);
    SLD_STRING_API u32           string_w128_exists          (const string_w128* str,     const cchar*       sub_string);
    SLD_STRING_API const cchar8* string_w128_copy_to_string  (const string_w128* src_str, const string_w128* dst_str);
    SLD_STRING_API const cchar8* string_w128_copy_to_buffer  (const string_w128* src_str, const cchar8*      dst_buf);
    SLD_STRING_API const cchar8* string_w128_substring       (const string_w128* dst_str, const u32          position);
    SLD_STRING_API const bool    string_w128_does_a_equal_b  (const string_w128* str_a,   const string_w128* str_a);
    SLD_STRING_API const cchar8* string_w128_tokenize        (const string_w128* str,     const cchar8*      delimiter, const cchar*  previous_token = NULL);
    SLD_STRING_API const cchar8* string_w128_append          (string_w128*       dst_str, const cchar8*      src);
    SLD_STRING_API const cchar8* string_w128_update          (string_w128*       dst_str, const u32          position,  const cchar8* buf);

    //--------------------------------------------------------------------
    // W STRING NVAR
    //--------------------------------------------------------------------

    SLD_STRING_API u32           string_wnvar_memory_size    (const u32 str_size);
    SLD_STRING_API string_wnvar* string_wnvar_create         (const u32 str_size, const cchar8* c_str = NULL);
    SLD_STRING_API string_wnvar* string_wnvar_init           (const u32 str_size, const u32 mem_size, void* mem_ptr, const cchar8* c_str = NULL);
    SLD_STRING_API void          string_wnvar_destroy        (const string_wnvar* str);
    SLD_STRING_API void          string_wnvar_assert_valid   (const string_wnvar* str);
    SLD_STRING_API bool          string_wnvar_is_empty       (const string_wnvar* str);
    SLD_STRING_API u32           string_wnvar_length         (const string_wnvar* str);
    SLD_STRING_API hash32        string_wnvar_hash_32        (const string_wnvar* str);
    SLD_STRING_API hash64        string_wnvar_hash_64        (const string_wnvar* str);
    SLD_STRING_API hash128       string_wnvar_hash_128       (const string_wnvar* str);
    SLD_STRING_API const cchar8* string_wnvar_char_buffer    (const string_wnvar* str);
    SLD_STRING_API u32           string_wnvar_exists         (const string_wnvar* str,     const cchar*        sub_str_ptr, const u32 sub_str_size);
    SLD_STRING_API const cchar8* string_wnvar_copy_to_string (const string_wnvar* src_str, const string_wnvar* dst_str_ptr, const u32 dst_str_size);
    SLD_STRING_API const cchar8* string_wnvar_copy_to_buffer (const string_wnvar* src_str, const cchar8*       dst_buf_ptr, const u32 dst_buf_size);
    SLD_STRING_API const cchar8* string_wnvar_substring      (const string_wnvar* dst_str, const u32           position);
    SLD_STRING_API const bool    string_wnvar_does_a_equal_b (const string_wnvar* str_a,   const string_wnvar* str_a);
    SLD_STRING_API const cchar8* string_wnvar_tokenize       (const string_wnvar* str,     const cchar8*       delimiter, const u32 token_size, const cchar*  previous_token = NULL);
    SLD_STRING_API const cchar8* string_wnvar_append         (string_wnvar*       dst_str, const cchar8*       src_ptr,   const u32 src_size);
    SLD_STRING_API const cchar8* string_wnvar_update         (string_wnvar*       dst_str, const u32           dst_pos,   const cchar8* dst_buf_ptr, const u32 dst_buf_size);

#endif //SLD_STRINGS_HPP