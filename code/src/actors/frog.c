#include "z3D/z3D.h"
#include "z3D/actors/z_en_fr.h"
#include "settings.h"
#include "objects.h"
#include "enemy_souls.h"

void EnFr_rSetReward(EnFr* frog) {
    if (frog->songIndex < FROG_STORMS) {
        // Shuffled rupee rewards will use the song index as the override flag (+1 to avoid GetItem 0)
        frog->reward =
            gSettingsContext.shuffleFrogSongRupees == SHUFFLEFROGSONGRUPEES_ON ? frog->songIndex + 1 : GI_RUPEE_PURPLE;
    } else if (frog->songIndex == FROG_STORMS) {
        frog->reward = GI_HEART_PIECE;
    } else {
        frog->reward = GI_HEART_PIECE_WIN;
    }
}

s16 FrogSongTimerMultiplier(s16 initialFrogTimer) {
    return initialFrogTimer * (gSettingsContext.frogSongTimerMult + 1);
}

void FrogSongTimer_Init(void) {
    for (u8 i = 0; i < ARRAY_SIZE(sTimerFrogSong); i++) {
        sTimerFrogSong[i] = FrogSongTimerMultiplier(sTimerFrogSong[i]);
    }
}

void EnFr_rDraw(Actor* thisx, GlobalContext* ctx){
    CitraPrint("EnFr_rDraw Actor: %x Params: %x",thisx->id,thisx->params);
    ObjectEntry* obj = Object_FindEntry(OBJECT_FROG);
    SoullessModels_ModifyGenericCmb(obj->zarInfo.cmbMans[1]);
}