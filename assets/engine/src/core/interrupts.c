#pragma bank 255

#include <gb/gb.h>

#include "interrupts.h"

#include "scroll.h"
#include "parallax.h"
#include "ui.h"
#include "states/topdown.h"

#define LYC_SYNC_VALUE 150u

UBYTE hide_sprites = FALSE;
UBYTE show_actors_on_overlay = FALSE;
UBYTE overlay_cut_scanline = LYC_SYNC_VALUE; 

void remove_LCD_ISRs() BANKED {
    CRITICAL {
        remove_LCD(parallax_LCD_isr);
        remove_LCD(simple_LCD_isr);
        remove_LCD(fullscreen_LCD_isr);
        remove_LCD(fullscreen_td_LCD_isr);
        LCDC_REG &= ~LCDCF_BG8000;
    }
}

void simple_LCD_isr() NONBANKED {
    if (LYC_REG == LYC_SYNC_VALUE) {
        SCX_REG = draw_scroll_x;
        SCY_REG = draw_scroll_y;
        if (WY_REG) {
            if (WY_REG < MENU_CLOSED_Y) LYC_REG = WY_REG - 1; 
        } else {
            if ((WX_REG == MINWNDPOSX) && (show_actors_on_overlay == FALSE)) HIDE_SPRITES;
            LYC_REG = overlay_cut_scanline;
        }
    } else {
        if (LYC_REG < overlay_cut_scanline) {
            if ((WX_REG == MINWNDPOSX) && (show_actors_on_overlay == FALSE)) {
                while (STAT_REG & STATF_BUSY) ;
                HIDE_SPRITES;
            }
            LYC_REG = overlay_cut_scanline;
        } else { 
            while (STAT_REG & STATF_BUSY) ;
            HIDE_WIN;
            if (!hide_sprites) SHOW_SPRITES;
            LYC_REG = LYC_SYNC_VALUE;
            return;
        }
    }
}

void fullscreen_LCD_isr() NONBANKED {
    if (LYC_REG == LYC_SYNC_VALUE) {
        LCDC_REG &= ~LCDCF_BG8000;
        SCX_REG = draw_scroll_x;
        SCY_REG = draw_scroll_y;
        LYC_REG = (9 * 8) - 1;    
    } else {
        while (STAT_REG & STATF_BUSY) ;
        LCDC_REG |= LCDCF_BG8000;
        LYC_REG = LYC_SYNC_VALUE;
    }
}

void fullscreen_td_LCD_isr() NONBANKED {
    //static one frame:
    /*STAT_REG = 0x45;
    LYC_REG = 0x00;
    if (LYC_REG == 0x00) {
        move_bkg(scrollx_1, 0);
        LYC_REG = 0x30;
    }
    if (LYC_REG == 0x30) {
        move_bkg(20, 0);
        LYC_REG = 0x64;
    }
    if (LYC_REG == 0x64) {
        move_bkg(scrollx_2, 0);
        LYC_REG = 0x00;
    }*/

    //sings between frames:
    if (LYC_REG == LYC_SYNC_VALUE) {
        SCX_REG = draw_scroll_x;
        SCY_REG = draw_scroll_y;
        if (WY_REG) {
            if (WY_REG < MENU_CLOSED_Y) LYC_REG = WY_REG - 1;
        }
        else {
            if ((WX_REG == MINWNDPOSX) && (show_actors_on_overlay == FALSE)) HIDE_SPRITES;
            LYC_REG = overlay_cut_scanline;
        }
        LYC_REG = 0;
    }
    else {
        if (LYC_REG == 0x00) {
            move_bkg(scrollx_1, 0);
        }
        if (LYC_REG == 0x30) {
            move_bkg(20, 0);
            //LYC_REG = 0x64;
        }
        if (LYC_REG == 0x64) {
            move_bkg(scrollx_2, 0);
            //LYC_REG = 0x00;
        }

        LYC_REG++;
        if (LYC_REG == 144) LYC_REG = LYC_SYNC_VALUE;
    }
}

void VBL_isr() NONBANKED {
    WX_REG = win_pos_x + MINWNDPOSX;
    if ((WY_REG = win_pos_y) < MENU_CLOSED_Y) SHOW_WIN; else HIDE_WIN;
    if (hide_sprites) HIDE_SPRITES; else SHOW_SPRITES;
    scroll_shadow_update();
}
