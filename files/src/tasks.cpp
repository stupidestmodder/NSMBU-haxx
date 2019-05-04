#include <globals.h>
#include <level.h>
#include <physics.h>
#include <tasks.h>

extern "C" {
    void readHaxxOptions(AreaTask *_this) {
        setLevelInstances();
        _this->wrapFlag = 0;

        char areaId = LevelInfo->currentAreaId;
        LevelArea *area = getAreaById(Level, (unsigned int)areaId);
        AreaOptions *areaOptions = (AreaOptions *)area->blockPtrs[1];

        if (areaOptions->wrapByte & 1)
            _this->wrapFlag = 1;

        if (areaOptions->wrapByte & 2) {
            setPlayerJumpArc(0.5);
            setMiniPlayerJumpArc(0.5);
            setPlayerJumpMax(4.5);
            setPlayerDescentRate(-2.0);
        }

        else {
            setPlayerJumpArc(PlayerJumpArc);
            setMiniPlayerJumpArc(MiniPlayerJumpArc);
            setPlayerJumpMax(PlayerJumpMax);
            setPlayerDescentRate(PlayerDescentRate);
        }
    }
}