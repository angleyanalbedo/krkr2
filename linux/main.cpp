#include <string>
#include <memory>
#include <gtk/gtk.h>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "environ/cocos2d/AppDelegate.h"

#include "environ/ui/MainFileSelectorForm.h"

int main(int argc, char **argv) {
    gtk_init(&argc, &argv);
    spdlog::set_level(spdlog::level::debug);

    static auto core_logger = spdlog::stdout_color_mt("core");
    static auto tjs2_logger = spdlog::stdout_color_mt("tjs2");
    static auto plugin_logger = spdlog::stdout_color_mt("plugin");
    // 将输入的参数也就是输入文件转为wstring
    if(argc > 1) {
        
        TVPMainFileSelectorForm::filePath = utf8_to_wstr(argv[1]);
    } else {
        TVPMainFileSelectorForm::filePath = L"";
    }
    spdlog::set_default_logger(core_logger);


    static std::unique_ptr<TVPAppDelegate> pAppDelegate =
        std::make_unique<TVPAppDelegate>();
    return pAppDelegate->run();
}