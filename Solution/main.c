#include <gb/gb.h>

#include "event.h"

#include "sprites.h"

#include "trackMB.c"
#include "trackTD.c"

// struct event events;

int main(){
    defaultSpriteStruct(sprites, 40);

    set_bkg_data(0, 15, trackSprites);
    set_bkg_tiles(0, 0, 20, 18, trackMap);

    SHOW_BKG;
    SHOW_SPRITES;

    while (TRUE)
    {   
        tumblingBarrels();

        wait_vbl_done();
    }
    return 0;
}