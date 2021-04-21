#include "sprites.h"

struct sprite sprites[40];

UINT8 spritesInUse = 0;

BOOLEAN addSTU(struct sprite *_sprites, UINT8 _sizeOf)
{
    UINT8 uSIUCounter = 0; UINT8 uSIUCounterOne = 0;

    for(uSIUCounter = 0; uSIUCounter < _sizeOf; uSIUCounter++)
    {
        for(uSIUCounterOne = 0; uSIUCounterOne < 40; uSIUCounterOne++)
        {
            if(sprites[uSIUCounterOne].spriteInUse != FALSE && uSIUCounterOne == 39) { return FALSE; }
            else if(sprites[uSIUCounterOne].spriteInUse == FALSE)
            {
                _sprites[uSIUCounterOne].spriteInUse = TRUE;

                sprites[uSIUCounterOne] = _sprites[uSIUCounter];
                sprites[uSIUCounterOne].spriteInUse = TRUE;
                
                spritesInUse += 1;

                break;
            }
        }
    }

    printf("%d\n", (UINT16)spritesInUse);

    return TRUE;
}

UINT16 sNTLUpdate(struct sprite *_sprites)
{    
    _sprites->spriteNumberTopLeftX = (_sprites->spritePosition[0] - 8) / 8;
    _sprites->spriteNumberTopLeftY = (_sprites->spritePosition[1] - 16) / 8;

    _sprites->spriteNumberTopLeft = 20 * _sprites->spriteNumberTopLeftY + _sprites->spriteNumberTopLeftX;

    return _sprites->spriteNumberTopLeft;
}

void defaultSpriteStruct(struct sprite *_sprites, UINT8 _sizeOf)
{
    UINT8 dSSCounter = 0; 

    for(dSSCounter = 0; dSSCounter < _sizeOf; dSSCounter++)
    {
        _sprites[dSSCounter].spriteInUse = FALSE;

        _sprites[dSSCounter].spriteCollisionBoundaries[0] = 0; _sprites[dSSCounter].spriteCollisionBoundaries[1] = 0;
        
        _sprites[dSSCounter].spriteNumber = 0;
        
        _sprites[dSSCounter].spritePosition[0] = 0; _sprites[dSSCounter].spritePosition[1] = 0;

        _sprites[dSSCounter].spriteNumberTopLeft = 0;
        _sprites[dSSCounter].spriteNumberTopLeftX = 0;
        _sprites[dSSCounter].spriteNumberTopLeftY = 0;
    }
}