#pragma bank 255

#include <gbdk/platform.h>
#include "vm.h"
#include "vm_ui.h"
#include "ui.h"

void native_blink(SCRIPT_CTX * THIS) OLDCALL BANKED {
    uint8_t bgp = *(int16_t*)VM_REF_TO_PTR(FN_ARG0);
    
	if(bgp == 3) {
        BGP_REG = 0xE4U;
    }
	else if(bgp == 2){
        BGP_REG = 0xF9U;
    }
	else if(bgp == 1){
        BGP_REG = 0xFEU;
    } 
	else {
        BGP_REG = 0xFFU;
    }
}