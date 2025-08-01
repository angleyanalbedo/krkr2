#pragma once

#include "FileSelectorForm.h"


#if defined(_WIN32)
#include <windows.h>
#elif defined(__linux__)
#include <sys/stat.h>
#endif

namespace cocos2d {
    class LayerColor;
}

class TVPMainFileSelectorForm : public TVPBaseFileSelectorForm {
    typedef TVPBaseFileSelectorForm inherit;

public:
    static std::wstring filePath;
    void bindBodyController(const Node *allNodes) override;

    void show();

    static TVPMainFileSelectorForm *create();

    void initFromFile();

    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode,
                      cocos2d::Event *event) override;

    void runFromPath(const std::string &path);

protected:
    TVPMainFileSelectorForm();

    void onEnter() override;

    bool CheckDir(const std::string &path);

    void onCellClicked(int idx) override;

    void getShortCutDirList(std::vector<std::string> &pathlist) override;

    void startup(const std::string &path);

    static void doStartup(const std::string &path);

    void showMenu(cocos2d::Ref *);

    void hideMenu(cocos2d::Ref *);

    bool isMenuShowed();

    bool isMenuShrinked();

    void onShowPreferenceConfigAt(const std::string &path);

    void ListHistory();

    class HistoryCell : public cocos2d::ui::Widget {
    public:
        static HistoryCell *create(const std::string &fullpath,
                                   const std::string &prefix,
                                   const std::string &pathname,
                                   const std::string &filename) {
            HistoryCell *ret = new HistoryCell();
            ret->autorelease();
            ret->init();
            ret->initInfo(fullpath, prefix, pathname, filename);
            return ret;
        }

        void initInfo(const std::string &fullpath, const std::string &prefix,
                      const std::string &pathname, const std::string &filename);

        void initFunction(const ccWidgetClickCallback &funcDel,
                          const ccWidgetClickCallback &funcJump,
                          const ccWidgetClickCallback &funcConf,
                          const ccWidgetClickCallback &funcPlay);

        void rearrangeLayout();

        const std::string &getFullpath() { return _fullpath; }

    private:
        void onSizeChanged() override;

        cocos2d::ui::ScrollView *_scrollview;
        cocos2d::ui::Widget *_btn_delete, *_btn_jump, *_btn_conf, *_btn_play;
        cocos2d::ui::Text *_prefix, *_path, *_file;
        cocos2d::Node *_panel_delete, *_root = nullptr;
        std::string _fullpath;
    };

    void RemoveHistoryCell(cocos2d::Ref *, HistoryCell *cell);

    std::string _lastpath;
    cocos2d::ui::Widget *_touchHideMenu;
    cocos2d::ui::ListView *_menuList, *_historyList = nullptr;
    cocos2d::LayerColor *_mask;
    cocos2d::Node *_menu, *_fileList = nullptr;
    cocos2d::Node *newLocalPref, *localPref;
    cocos2d::Size sizeNewLocalPref, sizeLocalPref;
};

