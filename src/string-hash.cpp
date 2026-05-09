#pragma once

#include "sld-strings.hpp"
#include "meow_hash_x64_aesni.h"


namespace sld {

    SLD_STRING_API hash32
    string_c_hash_32(
        const cchar8* str_buffer,
        const u32     str_size) {

        assert(str_buffer != NULL && str_size != 0);

        meow_u128    meow_hash = MeowHash    (MeowDefaultSeed, str_size, str_buffer);
        const hash32 sld_hash  = MeowU32From (meow_hash, 0); 
    
        return(sld_hash);
    }

    SLD_STRING_API hash32
    string_w_hash_32(
        const wchar16* str_buffer,
        const u32      str_size) {

        assert(str_buffer != NULL && str_size != 0);
    
        const u32    size_actual = (str_size * sizeof(wchar16));
        meow_u128    meow_hash   = MeowHash    (MeowDefaultSeed, size_actual, str_buffer);
        const hash32 sld_hash    = MeowU32From (meow_hash, 0); 
    
        return(sld_hash);
    }

    SLD_STRING_API hash64
    string_c_hash_64(
        const cchar8* str_buffer,
        const u32     str_size) {

        assert(str_buffer != NULL && str_size != 0);
        
        meow_u128    meow_hash = MeowHash    (MeowDefaultSeed, str_size, str_buffer);
        const hash64 sld_hash  = MeowU64From (meow_hash, 0); 
    
        return(sld_hash);
    }

    SLD_STRING_API hash64
    string_w_hash_64(
        const wchar16* str_buffer,
        const u32      str_size) {

        assert(str_buffer != NULL && str_size != 0);

        const u32    size_actual = (str_size * sizeof(wchar16));
        meow_u128    meow_hash   = MeowHash    (MeowDefaultSeed, size_actual, str_buffer);
        const hash32 sld_hash    = MeowU64From (meow_hash, 0); 
    
        return(sld_hash);
    }

    SLD_STRING_API hash128
    string_c_hash_128(
        const cchar8* str_buffer,
        const u32     str_size) {

        assert(str_buffer != NULL && str_size != 0);
        
        meow_u128 meow_hash = MeowHash(MeowDefaultSeed, str_size, str_buffer);
        
        hash128 sld_hash;
        sld_hash.lo = MeowU64From (meow_hash, 0);
        sld_hash.hi = MeowU64From (meow_hash, 1);

        return(sld_hash);
    }    

    SLD_STRING_API hash128
    string_w_hash_128(
        const wchar16*str_buffer,
        const u32     str_size) {

        assert(str_buffer != NULL && str_size != 0);

        const u32 size_actual = (str_size * sizeof(wchar16));
        meow_u128 meow_hash   = MeowHash(MeowDefaultSeed, size_actual, str_buffer);
        
        hash128 sld_hash;
        sld_hash.lo = MeowU64From (meow_hash, 0);
        sld_hash.hi = MeowU64From (meow_hash, 1);

        return(sld_hash);
    }    
};