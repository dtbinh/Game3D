// Autogenerated by gameplay-luagen
#include "Base.h"
#include "ScriptController.h"
#include "lua_Drawable.h"
#include "Base.h"
#include "Drawable.h"
#include "Node.h"

namespace egret
{

void luaRegister_Drawable()
{
    const luaL_Reg lua_members[] = 
    {
        {"draw", lua_Drawable_draw},
        {"getNode", lua_Drawable_getNode},
        {NULL, NULL}
    };
    const luaL_Reg* lua_statics = NULL;
    std::vector<std::string> scopePath;

    egret::ScriptUtil::registerClass("Drawable", lua_members, NULL, lua_Drawable__gc, lua_statics, scopePath);
}

static Drawable* getInstance(lua_State* state)
{
    void* userdata = luaL_checkudata(state, 1, "Drawable");
    luaL_argcheck(state, userdata != NULL, 1, "'Drawable' expected.");
    return (Drawable*)((egret::ScriptUtil::LuaObject*)userdata)->instance;
}

int lua_Drawable__gc(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                void* userdata = luaL_checkudata(state, 1, "Drawable");
                luaL_argcheck(state, userdata != NULL, 1, "'Drawable' expected.");
                egret::ScriptUtil::LuaObject* object = (egret::ScriptUtil::LuaObject*)userdata;
                if (object->owns)
                {
                    Drawable* instance = (Drawable*)object->instance;
                    SAFE_DELETE(instance);
                }
                
                return 0;
            }

            lua_pushstring(state, "lua_Drawable__gc - Failed to match the given parameters to a valid function signature.");
            lua_error(state);
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Drawable_draw(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                Drawable* instance = getInstance(state);
                unsigned int result = instance->draw();

                // Push the return value onto the stack.
                lua_pushunsigned(state, result);

                return 1;
            }

            lua_pushstring(state, "lua_Drawable_draw - Failed to match the given parameters to a valid function signature.");
            lua_error(state);
            break;
        }
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                lua_type(state, 2) == LUA_TBOOLEAN)
            {
                // Get parameter 1 off the stack.
                bool param1 = egret::ScriptUtil::luaCheckBool(state, 2);

                Drawable* instance = getInstance(state);
                unsigned int result = instance->draw(param1);

                // Push the return value onto the stack.
                lua_pushunsigned(state, result);

                return 1;
            }

            lua_pushstring(state, "lua_Drawable_draw - Failed to match the given parameters to a valid function signature.");
            lua_error(state);
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1 or 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Drawable_getNode(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                Drawable* instance = getInstance(state);
                void* returnPtr = ((void*)instance->getNode());
                if (returnPtr)
                {
                    egret::ScriptUtil::LuaObject* object = (egret::ScriptUtil::LuaObject*)lua_newuserdata(state, sizeof(egret::ScriptUtil::LuaObject));
                    object->instance = returnPtr;
                    object->owns = false;
                    luaL_getmetatable(state, "Node");
                    lua_setmetatable(state, -2);
                }
                else
                {
                    lua_pushnil(state);
                }

                return 1;
            }

            lua_pushstring(state, "lua_Drawable_getNode - Failed to match the given parameters to a valid function signature.");
            lua_error(state);
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

}
