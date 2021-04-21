#ifndef SPRITES_H
#define SPRITES_H

#include <gb/gb.h>

#include <stdio.h>

struct sprite
{
    BOOLEAN spriteInUse;

    UINT8 spriteCollisionBoundaries[2];
    // 0 - 40
    UINT8 spriteNumber;
    // 0 = X, 1 = Y
    UINT8 spritePosition[2];

    UINT16 spriteNumberTopLeft;
    UINT16 spriteNumberTopLeftX; 
    UINT16 spriteNumberTopLeftY; 
};

extern struct sprite sprites[40];

extern UINT8 spritesInUse; 

// Add sprites to use
BOOLEAN addSTU(struct sprite *, UINT8);

// Sprite number top left update
UINT16 sNTLUpdate(struct sprite *);

void defaultSpriteStruct(struct sprite *, UINT8);

#endif