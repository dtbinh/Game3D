// Autogenerated by gameplay-luagen
#ifndef LUA_SCRIPTTARGETEVENTREGISTRY_H_
#define LUA_SCRIPTTARGETEVENTREGISTRY_H_

namespace egret
{

// Lua bindings for ScriptTarget::EventRegistry.
int lua_ScriptTargetEventRegistry__gc(lua_State* state);
int lua_ScriptTargetEventRegistry__init(lua_State* state);
int lua_ScriptTargetEventRegistry_addEvent(lua_State* state);
int lua_ScriptTargetEventRegistry_getEvent(lua_State* state);
int lua_ScriptTargetEventRegistry_getEventCount(lua_State* state);

void luaRegister_ScriptTargetEventRegistry();

}

#endif
