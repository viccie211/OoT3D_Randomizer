#ifndef _EN_FR_H_
#define _EN_FR_H_

#include "z3D/z3D.h"

typedef enum {
    /* 00 */ FROG_ZL,
    /* 01 */ FROG_EPONA,
    /* 02 */ FROG_SARIA,
    /* 03 */ FROG_SUNS,
    /* 04 */ FROG_SOT,
    /* 05 */ FROG_STORMS,
    /* 06 */ FROG_CHOIR_SONG,
    /* 07 */ FROG_NO_SONG
} FrogSongType;

typedef struct EnFr {
    /* 0x000 */ Actor actor;
    /* 0x1a4 */ SkelAnime skelAnime;
    /* 0x228 */ char unk_228[0x790];
    /* 0x9b8 */ SkelAnime skelAnimeButterfly;
    /* 0xA3C */ char unk_A3C[0xD8];
    /* 0xB14 */ void* actionFunc;
    /* 0xB18 */ char unk_B18[0x1F];
    /* 0xB37 */ s32 jumpCounter;
    /* 0xB3B */ float blinkTimer;
    /* 0xB3F */ void* blinkFunk;
    /* 0xB43 */ u8 eyeTexIndex;
    /* 0xB44 */ u8 isJumpingUp;
    /* 0xB45 */ u8 isBelowWaterSurfacePrevious;
    /* 0xB46 */ u8 isBelowWaterSurfaceCurrent;
    /* 0xB47 */ u8 isDeactivating;
    /* 0xB48 */ u8 isActive;
    /* 0xB49 */ u8 growingScaleIndex;
    /* 0xB4A */ u8 isGrowing;
    /* 0xB4B */ u8 unk_B4B;
    /* 0xB4C */ u8 ocarinaNote;
    /* 0xB4D */ char unk_B4D[0xEE];
    /* OxC3C */ u8 ocarinaNoteIndex; 
    /* 0xC3E */ u8 songIndex;
    /* 0xC3F */ char unk_20C[0x5];
    /* 0xC44 */ s32 reward;
    /* 0xC48 */ char unk_C48[0x208];
} EnFr; // size 0xE50

extern s16 sTimerFrogSong[5];

void EnFr_Draw(Actor* thisx, GlobalContext* ctx);
#endif //_EN_FR_H_
