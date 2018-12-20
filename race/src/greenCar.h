//
// Created by Othmane Amdaui on 20-Dec-18.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GREENCAR_H
#define GBA_SPRITE_ENGINE_PROJECT_GREENCAR_H


//{{BLOCK(green_car)

//======================================================================
//
//	green_car, 16x16@8,
//	+ palette 256 entries, not compressed
//	+ 4 tiles Metatiled by 2x2 not compressed
//	Total size: 512 + 256 = 768
//
//	Time-stamp: 2018-12-20, 10:15:14
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned short green_carTiles[128] __attribute__((aligned(4)))=
        {
                0x0000,0x0000,0x0101,0x0101,0x0000,0x0100,0x0201,0x0101,
                0x0000,0x0101,0x0101,0x0101,0x0000,0x0101,0x0000,0x0000,
                0x0000,0x0101,0x0001,0x0000,0x0000,0x0101,0x0101,0x0000,
                0x0000,0x0101,0x0101,0x0101,0x0000,0x0101,0x0101,0x0101,
                0x0101,0x0001,0x0000,0x0000,0x0201,0x0101,0x0000,0x0000,
                0x0101,0x0101,0x0001,0x0000,0x0000,0x0100,0x0001,0x0000,
                0x0000,0x0101,0x0001,0x0000,0x0100,0x0101,0x0001,0x0000,
                0x0101,0x0101,0x0001,0x0000,0x0101,0x0101,0x0001,0x0000,

                0x0000,0x0101,0x0100,0x0101,0x0000,0x0101,0x0101,0x0101,
                0x0000,0x0101,0x0101,0x0101,0x0000,0x0101,0x0100,0x0101,
                0x0000,0x0101,0x0101,0x0101,0x0000,0x0101,0x0101,0x0101,
                0x0000,0x0101,0x0001,0x0000,0x0000,0x0101,0x0101,0x0101,
                0x0101,0x0100,0x0001,0x0000,0x0101,0x0101,0x0001,0x0000,
                0x0101,0x0101,0x0001,0x0000,0x0101,0x0100,0x0001,0x0000,
                0x0101,0x0101,0x0001,0x0000,0x0101,0x0101,0x0001,0x0000,
                0x0000,0x0101,0x0001,0x0000,0x0101,0x0101,0x0001,0x0000,
        };

const unsigned short green_carPal[256] __attribute__((aligned(4)))=
        {
                0x0000,0x03E0,0x03FF,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
        };

//}}BLOCK(green_car)

#endif //GBA_SPRITE_ENGINE_PROJECT_GREENCAR_H