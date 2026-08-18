#ifndef _FROG_H
#define _FROG_H
#include "z3D/actors/z_en_fr.h"

void EnFr_rSetReward(EnFr* frog);
void FrogSongTimer_Init(void);
s16 FrogSongTimerMultiplier(s16 initialFrogTimer);
void EnFr_rDraw(Actor* thisx, GlobalContext* ctx);
#endif //_FROG_H
