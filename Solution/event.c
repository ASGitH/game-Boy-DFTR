#include "event.h"
#include "obstaclesTD.c"
#include "sprites.h"

BOOLEAN hasSelectedEventBeenInitialized = FALSE;
BOOLEAN haveEventsBeenSelected = FALSE;

struct sprite eventSprites[40];

UINT8 currentNumberOfEvents = 0;
UINT8 eventDelayTimer = 0;
UINT8 loopCounter = 0;
UINT8 obstacleSpriteIndexCounter = 0;

// Delete below later
UINT8 seed = 0;
// Delete above later

UINT8 spritesToUse = 0;

// BOOLEAN eventInitializer(struct event *_events)
// {
//     printf("%d", &(UINT16)currentNumberOfEvents);

//     return FALSE;
// }

void tumblingBarrels()
{
    if(!hasSelectedEventBeenInitialized)
    {
        eventDelayTimer = 0;

        hasSelectedEventBeenInitialized = TRUE;

        obstacleSpriteIndexCounter = 13;

        // Delete below later
        while(joypad() != J_A) 
        { 
            seed += 1;

            if(seed >= 255) { seed = 0; } 
        }

        initrand(seed);
        // Delete above later

        set_sprite_data(12, 5, obstacleSprites);

        spritesToUse = 10;

        defaultSpriteStruct(eventSprites, spritesToUse);

        addSTU(eventSprites, spritesToUse);

        for(; loopCounter < spritesToUse; loopCounter++)
        {
            set_sprite_tile(loopCounter, obstacleSpriteIndexCounter);

            // UINT8 overlapCheck = 

            move_sprite (loopCounter, 0, 0);
            // move_sprite (loopCounter, (16 + (8 * (randw() % 18) /* (loopCounter * 2) */)), 40);
            delay(99);
        }

        loopCounter = 0;
    }
    else
    {
        eventDelayTimer += 1;

        if(eventDelayTimer >= 12)
        {
            eventDelayTimer = 0;

            obstacleSpriteIndexCounter += 1;

            if(obstacleSpriteIndexCounter > 16) { obstacleSpriteIndexCounter = 13; }

            for(; loopCounter < spritesToUse; loopCounter++) 
            { 
                scroll_sprite(loopCounter + 1, 0, 12); 

                set_sprite_tile(loopCounter + 1, obstacleSpriteIndexCounter);
            }

            loopCounter = 0;
        }
    }
}