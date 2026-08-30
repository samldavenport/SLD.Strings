#ifndef SLD_STRINGS_HPP
#define SLD_STRINGS_HPP

#include <sld.hpp>


#ifdef SLD_STRINGS_STATIC 
#   define SLD_STRINGS_API 
#elif defined(SLD_STRINGS_DLL_EXPORT)
#   define SLD_STRINGS_API __declspec(dllexport)
#else
#   define SLD_STRINGS_API __declspec(dllimport)
#endif


namespace sld {

    struct cstr {
        cchar* chars;
        u64    size;
    };

    struct cstr_c8   { cchar chars[8];   };
    struct cstr_c16  { cchar chars[16];  };
    struct cstr_c32  { cchar chars[32];  };
    struct cstr_c64  { cchar chars[64];  };
    struct cstr_c128 { cchar chars[128]; };
    struct cstr_c256 { cchar chars[256]; };

    SLD_STRINGS_API u32  cstr_nvar_length           (const cchar* str,     const u32 size);
    SLD_STRINGS_API u32  cstr_nvar_hash             (const cchar* str,     const u32 size);
    SLD_STRINGS_API u32  cstr_nvar_copy             (const cchar* src_str, const u32 src_size, cchar* dst_str, const u32 dst_size);
    SLD_STRINGS_API u32  cstr_nvar_append           (const cchar* src_str, const u32 src_size, cchar* dst_str, const u32 dst_size);
    SLD_STRINGS_API bool cstr_nvar_equals           (const cchar* str_a,   const cchar* str_b, const u32 max_size);
    SLD_STRINGS_API bool cstr_nvar_is_null_or_empty (const cchar* str,     const u32 size);
    
    SLD_STRINGS_API u32  cstr_length                (const cstr* str);
    SLD_STRINGS_API u32  cstr_hash                  (const cstr* str);
    SLD_STRINGS_API u32  cstr_copy                  (const cstr* str_src, cstr* str_dst);
    SLD_STRINGS_API u32  cstr_append                (const cstr* str_src, cstr* str_dst);
    SLD_STRINGS_API bool cstr_equals                (const cstr* str_a,   const cstr* str_b);
    SLD_STRINGS_API bool cstr_is_null_or_empty      (const cstr* str);

    SLD_STRINGS_API u32  cstr_c8_length             (const cstr_c8* str);
    SLD_STRINGS_API u32  cstr_c8_hash               (const cstr_c8* str);
    SLD_STRINGS_API u32  cstr_c8_copy               (const cstr_c8* str_src, cstr* str_dst);
    SLD_STRINGS_API u32  cstr_c8_append             (const cstr_c8* str_src, cstr* str_dst);
    SLD_STRINGS_API bool cstr_c8_equals             (const cstr_c8* str_a,   const cstr* str_b);
    SLD_STRINGS_API bool cstr_c8_is_null_or_empty   (const cstr_c8* str);

    SLD_STRINGS_API u32  cstr_c16_length            (const cstr_c16* str);
    SLD_STRINGS_API u32  cstr_c16_hash              (const cstr_c16* str);
    SLD_STRINGS_API u32  cstr_c16_copy              (const cstr_c16* str_src, cstr* str_dst);
    SLD_STRINGS_API u32  cstr_c16_append            (const cstr_c16* str_src, cstr* str_dst);
    SLD_STRINGS_API bool cstr_c16_equals            (const cstr_c16* str_a,   const cstr* str_b);
    SLD_STRINGS_API bool cstr_c16_is_null_or_empty  (const cstr_c16* str);

    SLD_STRINGS_API u32  cstr_c32_length            (const cstr_c32* str);
    SLD_STRINGS_API u32  cstr_c32_hash              (const cstr_c32* str);
    SLD_STRINGS_API u32  cstr_c32_copy              (const cstr_c32* str_src, cstr* str_dst);
    SLD_STRINGS_API u32  cstr_c32_append            (const cstr_c32* str_src, cstr* str_dst);
    SLD_STRINGS_API bool cstr_c32_equals            (const cstr_c32* str_a,   const cstr* str_b);
    SLD_STRINGS_API bool cstr_c32_is_null_or_empty  (const cstr_c32* str);

    SLD_STRINGS_API u32  cstr_c64_length            (const cstr_c64* str);
    SLD_STRINGS_API u32  cstr_c64_hash              (const cstr_c64* str);
    SLD_STRINGS_API u32  cstr_c64_copy              (const cstr_c64* str_src, cstr* str_dst);
    SLD_STRINGS_API u32  cstr_c64_append            (const cstr_c64* str_src, cstr* str_dst);
    SLD_STRINGS_API bool cstr_c64_equals            (const cstr_c64* str_a,   const cstr* str_b);
    SLD_STRINGS_API bool cstr_c64_is_null_or_empty  (const cstr_c64* str);

    SLD_STRINGS_API u32  cstr_c128_length           (const cstr_c128* str);
    SLD_STRINGS_API u32  cstr_c128_hash             (const cstr_c128* str);
    SLD_STRINGS_API u32  cstr_c128_copy             (const cstr_c128* str_src, cstr* str_dst);
    SLD_STRINGS_API u32  cstr_c128_append           (const cstr_c128* str_src, cstr* str_dst);
    SLD_STRINGS_API bool cstr_c128_equals           (const cstr_c128* str_a,   const cstr* str_b);
    SLD_STRINGS_API bool cstr_c128_is_null_or_empty (const cstr_c128* str);

    SLD_STRINGS_API u32  cstr_c256_length           (const cstr_c256* str);
    SLD_STRINGS_API u32  cstr_c256_hash             (const cstr_c256* str);
    SLD_STRINGS_API u32  cstr_c256_copy             (const cstr_c256* str_src, cstr* str_dst);
    SLD_STRINGS_API u32  cstr_c256_append           (const cstr_c256* str_src, cstr* str_dst);
    SLD_STRINGS_API bool cstr_c256_equals           (const cstr_c256* str_a,   const cstr* str_b);
    SLD_STRINGS_API bool cstr_c256_is_null_or_empty (const cstr_c256* str);
};

#endif //SLD_STRINGS_HPP
