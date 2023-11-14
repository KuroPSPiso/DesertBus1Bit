#pragma bank 255

#include <gbdk/platform.h>
#include "vm.h"
#include "vm_ui.h"
#include "ui.h"

void native_overlay_move_to_ui(SCRIPT_CTX * THIS) OLDCALL BANKED {
    uint8_t x = *(int16_t*)VM_REF_TO_PTR(FN_ARG0);
    uint8_t y = *(int16_t*)VM_REF_TO_PTR(FN_ARG1);
    uint8_t speed = *(int16_t*)VM_REF_TO_PTR(FN_ARG2);

    vm_overlay_move_to_px(THIS, x, y, speed);
}