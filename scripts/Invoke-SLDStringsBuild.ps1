
$ProjectRoot = Split-Path -Parent $PSScriptRoot 

$SrcFile    = Join-Path $ProjectRoot "src\sld-strings.cpp"
$Compile = @(
    "cl.exe"
    $SrcFile
    "/Fo:" + @(Join-Path $ProjectRoot "build\debug\obj\SLD.Strings.obj")  
    "/I"   + @(Join-Path $ProjectRoot "include")
    "/I"   + @(Join-Path $ProjectRoot "src")
    "/I"   + @(Join-Path $ProjectRoot "SLD.Core\include")
    "/nologo"             # startup banner disabled
    "/c"                  # compile without linking
    "/MD"                 # link against multithreaded runtime library (MSVCRT.dll)
    "/Z7"                 # generate debug info
    "/EHs-"               # disable exception handling
    "/std:c++17"          # c++17 standard mode
    "/Od"                 # disable optimizations
    "/D_HAS_EXCEPTIONS=0" # disable exceptions for STL and CRT
) -join " "

$Link = @(
    "link.exe"
    "SLD.Strings.obj"
    "user32.lib"
    "SLD.Core.lib"
    "/LIBPATH:" + @(Join-Path $ProjectRoot "SLD.Core\build\debug\lib")
    "/LIBPATH:" + @(Join-Path $ProjectRoot "build\debug\obj")
    "/LIBPATH:" + @(Join-Path $ProjectRoot "build\debug\lib")
    "/LIBPATH:" + @(Join-Path $ProjectRoot "vcpkg_installed/x64-windows/lib")
    "/OUT:"     + @(Join-Path $ProjectRoot "build\debug\bin\SLD.Strings.dll")
    "/IMPLIB:"  + @(Join-Path $ProjectRoot "build\debug\lib\SLD.Strings.lib")
    "/nologo"
    "/SUBSYSTEM:WINDOWS"
    "/DEBUG"
    "/DLL"
) -join " "

& .\SLD.Core\scripts\Build-SLDCoreDebug.ps1

Invoke-Expression $Compile
Invoke-Expression $Link
