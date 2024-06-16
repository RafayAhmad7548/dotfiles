#include <hyprland/src/plugins/PluginAPI.hpp>

inline HANDLE PHANDLE = nullptr;

APICALL EXPORT std::string PLUGIN_API_VERSION(){
    return HYPRLAND_API_VERSION;
}

void onChangeFocus(void* self, SCallbackInfo& info, std::any data){

}


APICALL EXPORT PLUGIN_DESCRIPTION_INFO PLUGIN_INIT(HANDLE handle){
    PHANDLE = handle;

    const std::string HASH = __hyprland_api_get_hash();

    // ALWAYS add this to your plugins. It will prevent random crashes coming from
    // mismatched header versions.
    if(HASH != GIT_COMMIT_HASH){
        HyprlandAPI::addNotification(PHANDLE, "[sttracker] Mismatched headers! Can't proceed.", CColor{1.0, 0.2, 0.2, 1.0}, 5000);
        throw std::runtime_error("[sttracker] Version mismatch");
    }

    std::cout<<"Plugin Started\n";

    HyprlandAPI::registerCallbackDynamic(handle, "activeWindow", [](void* self, SCallbackInfo& info, std::any data){
        std::cout<<"window switched\n";
    });


    return {"sttracker", "An amazing plugin that is going to change the world!", "rafay", "1.0"};
}

APICALL EXPORT void PLUGIN_EXIT(){}