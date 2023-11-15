#pragma bank 255

#include <gbdk/platform.h>
#include "vm.h"
#include "vm_ui.h"
#include "ui.h"

/*
void native_overlay_clear(SCRIPT_CTX * THIS, UBYTE x, UBYTE y, UBYTE w, UBYTE h, UBYTE color, UBYTE options) OLDCALL BANKED {
    THIS;
    text_bkg_fill = (color) ? TEXT_BKG_FILL_W : TEXT_BKG_FILL_B;
    if (options & UI_DRAW_FRAME) {
        ui_draw_frame(x, y, w, h);
        if (options & UI_AUTOSCROLL) vm_overlay_set_scroll(THIS, x + 1, y + 1, w - 2, h - 2, color);
    } else {
        fill_win_rect(x, y, w, h, ((color) ? ui_while_tile : ui_black_tile));
        if (options & UI_AUTOSCROLL) vm_overlay_set_scroll(THIS, x, y, w, h, color);
    }
}*/

unsigned char WindowMap[] =
{
  0x15,0x1C,0x01,0x17
};


void native_overlay_show_ui(SCRIPT_CTX * THIS) OLDCALL BANKED {
    //original: UBYTE pos_x, UBYTE pos_y, UBYTE color, UBYTE options

    uint8_t pos_x = *(int16_t*)VM_REF_TO_PTR(FN_ARG0);
    uint8_t pos_y = *(int16_t*)VM_REF_TO_PTR(FN_ARG1);
    
    const uint8_t width = 20;
    const uint8_t height = 18;
    fill_win_rect(0, 0, width, height, ui_black_tile);
    
    set_win_tiles(1, 0, 4, 1, WindowMap);
    //if ((pos_x < 20u) && (pos_y < 18u)) native_overlay_clear(THIS, 0, 0, 20u - pos_x, 18u - pos_y, color, options);
    ui_set_pos(pos_x << 3, pos_y << 3);
}