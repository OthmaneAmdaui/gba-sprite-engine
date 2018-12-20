//
// Created by Othmane Amdaui on 03-Dec-18.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_RED_CAR_H
#define GBA_SPRITE_ENGINE_PROJECT_RED_CAR_H

//{{BLOCK(red_car)

//======================================================================
//
//	red_car, 16x16@8,
//	+ palette 256 entries, not compressed
//	+ 4 tiles Metatiled by 2x2 not compressed
//	Total size: 512 + 256 = 768
//
//	Time-stamp: 2018-12-03, 10:09:01
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned short red_carTiles[128] __attribute__((aligned(4)))=
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
const unsigned short heartTiles[128] __attribute__((aligned(4)))=
        {
                0x3F3F,0x3F3F,0x3F3F,0x3F3F,0x3F3F,0x3F3F,0x3F3F,0x3F3F,
                0x3F3F,0x233F,0x2300,0x3F3F,0x3F3F,0x0E0B,0x1E1C,0x230D,
                0x003F,0x1C1C,0x152B,0x0022,0x003F,0x2B1C,0x0115,0x080F,
                0x003F,0x152B,0x2C01,0x252E,0x0B3F,0x0105,0x2E2C,0x2F25,
                0x3F3F,0x3F3F,0x3F3F,0x3F3F,0x3F3F,0x3F3F,0x3F3F,0x3F3F,
                0x0005,0x1000,0x3F3F,0x3F3F,0x122D,0x2125,0x3F1D,0x3F3F,
                0x252E,0x2F2F,0x0626,0x3F3F,0x1325,0x2929,0x2326,0x3F19,
                0x2F13,0x2929,0x2304,0x3F07,0x2929,0x2929,0x111D,0x3F07,

                0x3F3F,0x2D2A,0x252E,0x2F2F,0x3F3F,0x063F,0x131B,0x2929,
                0x3F3F,0x3F3F,0x0003,0x2904,0x3F3F,0x3F3F,0x243F,0x001D,
                0x3F3F,0x3F3F,0x3F3F,0x1F3F,0x3F3F,0x3F3F,0x3F3F,0x3F3F,
                0x3F3F,0x3F3F,0x3F3F,0x3F3F,0x3F3F,0x3F3F,0x3F3F,0x3F3F,
                0x2929,0x140C,0x1617,0x3F3F,0x1829,0x2800,0x3F0A,0x3F3F,
                0x1D09,0x161A,0x3F3F,0x3F3F,0x2717,0x3F16,0x3F3F,0x3F3F,
                0x1902,0x3F3F,0x3F3F,0x3F3F,0x3F3F,0x3F3F,0x3F3F,0x3F3F,
                0x3F3F,0x3F3F,0x3F3F,0x3F3F,0x3F3F,0x3F3F,0x3F3F,0x3F3F,
        };

const unsigned short red_carPal[256] __attribute__((aligned(4)))=
        {
                0x0000,0x001F,0x03FF,0x0000,0x0000,0x0000,0x0000,0x0000,
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

//}}BLOCK(red_car)

#endif //GBA_SPRITE_ENGINE_PROJECT_RED_CAR_H