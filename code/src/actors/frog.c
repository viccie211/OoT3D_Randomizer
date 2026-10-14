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
#define GET_CMB_STATUS(cmbMan) (((CMB_HEAD*)cmbMan->cmbChunk)->name[0])


void EnFr_ButterflyColorOverride(CmbManager* cmbMan, u8 noteIndex) {
    if (GET_CMB_STATUS(cmbMan) == noteIndex+1) {
        return;
    }

    GET_CMB_STATUS(cmbMan) = noteIndex+1;
    CMB_MATS* cmbMats      = Cmb_GetMatsChunk(cmbMan->cmbChunk);
    CMB_TEX* cmbTex        = Cmb_GetTexChunk(cmbMan->cmbChunk);
    // Modify all combiners to use operand `green` instead of `color`, making the texture draw in grayscale.
    for (Combiner* combiner = Cmb_GetCombiners(cmbMats); (u32)combiner < (u32)cmbTex; combiner++) {
        for (s32 opIdx = 0; opIdx < ARRAY_SIZE(combiner->operandColors); opIdx++) {
            if (combiner->operandColors[opIdx] == COMBINEROP_COLOR) {
                combiner->operandColors[opIdx] = COMBINEROP_COLOR+noteIndex;
            }
        }
    }
};



void EnFr_rDraw(Actor* thisx, GlobalContext* ctx){
    EnFr* this = (EnFr*)thisx;
    u8 ocarinaNoteIndex = this->ocarinaNote;
    CitraPrint("OcarinaNoteIndex: %x",ocarinaNoteIndex);
    ObjectEntry* obj = Object_FindEntry(OBJECT_FROG);
    EnFr_ButterflyColorOverride(obj->zarInfo.cmbMans[1],ocarinaNoteIndex);
}

