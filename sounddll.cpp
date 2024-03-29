#include <windows.h>
#include <iostream>
#include <stdlib.h>

#pragma comment(lib,"WinMM.Lib")
#pragma comment(lib,"libwinmm.a")
using namespace std;

extern "C" {
    #define LUA_COMPAT_APIINTCASTS
    #include <lualib.h>
    #include <lauxlib.h>
    #include <lua.h>
}

#include "luaApi.h"
extern "C" __declspec(dllexport) int luaopen_sound(lua_State *L)
{
    initLua(L);
    return 1;
}
