#pragma once
#include "BaseForm.h"
#include "tjsCommHead.h"
#include "movie/ffmpeg/VideoPlayer.h"

namespace cocos2d {
    class Sprite;
}

class SimplePlayerOverlay;

class SimpleMediaFilePlayer : public iTVPBaseForm {
    typedef cocos2d::Node inherit;

public:
    ~SimpleMediaFilePlayer() override;
    static SimpleMediaFilePlayer *create();

    void PlayFile(ttstr uri);

    void Play();
    void Pause();
    void TooglePlayOrPause();

private:
    SimpleMediaFilePlayer();
    void onPlayerEvent(KRMovieEvent Msg, void *p);
    void onSliderChanged();
    void rearrangeLayout() override;

    void bindHeaderController(const Node *allNodes) override;
    void bindBodyController(const Node *allNodes) override;
    void bindFooterController(const Node *allNodes) override;

    void update(float dt) override;

    SimplePlayerOverlay *_player;
    int _totalTime; // in sec
    float hideRemain = 0;
    bool _inupdate = false;

    // ui controllers
    cocos2d::ui::Text *Title, *PlayTime, *RemainTime, *OSDText;
    cocos2d::ui::Slider *Timeline;
    cocos2d::Node *NaviBar, *ControlBar, *OSD, *Overlay;
    cocos2d::ui::Widget *PlayBtn;
    cocos2d::Node *PlayBtnNormal, *PlayBtnPress, *PlayIconNormal,
        *PlayIconPress, *PauseIconNormal, *PauseIconPress;
    void setPlayButtonHighlight(bool highlight);
    void refreshPlayButtonStatus();
};
