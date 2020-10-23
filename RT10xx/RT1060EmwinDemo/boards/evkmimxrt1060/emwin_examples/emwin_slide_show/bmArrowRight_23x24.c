/*********************************************************************
 *                SEGGER Microcontroller GmbH & Co. KG                *
 *        Solutions for real time microcontroller applications        *
 *                           www.segger.com                           *
 **********************************************************************
 *                                                                    *
 * C-file generated by                                                *
 *                                                                    *
 *        Bitmap Converter for emWin V5.38c.                          *
 *        Compiled Dec 14 2016, 11:34:30                              *
 *                                                                    *
 *        (c) 1998 - 2016 Segger Microcontroller GmbH & Co. KG        *
 *                                                                    *
 **********************************************************************
 *                                                                    *
 * Source file: ArrowRight_23x24                                      *
 * Dimensions:  23 * 24                                               *
 * NumColors:   16                                                    *
 *                                                                    *
 **********************************************************************
 */

#include <stdlib.h>

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
#define GUI_CONST_STORAGE const
#endif

extern GUI_CONST_STORAGE GUI_BITMAP bmArrowRight_23x24;

/*********************************************************************
 *
 *       Palette
 *
 *  Description
 *    The following are the entries of the palette table.
 *    The entries are stored as a 32-bit values of which 24 bits are
 *    actually used according to the following bit mask: 0xBBGGRR
 *
 *    The lower   8 bits represent the Red   component.
 *    The middle  8 bits represent the Green component.
 *    The highest 8 bits represent the Blue  component.
 */
static GUI_CONST_STORAGE GUI_COLOR _ColorsArrowRight_23x24[] = {
#if (GUI_USE_ARGB == 0)
    0x623700, 0x14B6A9, 0x574716, 0x5C3F0B, 0x19AC9D, 0x3D714E, 0x338265, 0x387A59, 0x1EA491,
    0x4C582C, 0x28937B, 0x239B86, 0x525021, 0x476038, 0x426943, 0x2D8B70
#else
    0xFF003762, 0xFFA9B614, 0xFF164757, 0xFF0B3F5C, 0xFF9DAC19, 0xFF4E713D, 0xFF658233, 0xFF597A38, 0xFF91A41E,
    0xFF2C584C, 0xFF7B9328, 0xFF869B23, 0xFF215052, 0xFF386047, 0xFF436942, 0xFF708B2D
#endif

};

static GUI_CONST_STORAGE GUI_LOGPALETTE _PalArrowRight_23x24 = {16, // Number of entries
                                                                0,  // No transparency
                                                                &_ColorsArrowRight_23x24[0]};

static GUI_CONST_STORAGE unsigned char _acArrowRight_23x24[] = {
    0x2A, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21, 0x1B, 0xD0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21, 0x11, 0x18, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x21, 0x11, 0x11, 0x14, 0x53, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21, 0x11, 0x11, 0x11, 0x11, 0x62,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x41, 0x11, 0x11, 0x11, 0x11, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x35, 0x81, 0x11, 0x11, 0x11, 0x11, 0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0xA1, 0x11, 0x11,
    0x11, 0x11, 0xBE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x61, 0x11, 0x11, 0x11, 0x11, 0x85, 0x30, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x03, 0x58, 0x11, 0x11, 0x11, 0x11, 0x47, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xDA, 0x11, 0x11, 0x11, 0x11, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC4, 0x11, 0x11, 0x11, 0x20,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x41, 0x11, 0x11, 0x11, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x35,
    0x41, 0x11, 0x11, 0x11, 0xB9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x35, 0x41, 0x11, 0x11, 0x11, 0xBD, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x37, 0x41, 0x11, 0x11, 0x11, 0x8E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x37, 0x11, 0x11, 0x11,
    0x11, 0x4E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x26, 0x11, 0x11, 0x11, 0x11, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x36, 0x11, 0x11, 0x11, 0x11, 0x45, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21, 0x11, 0x11, 0x11, 0x17, 0x30,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21, 0x11, 0x11, 0x17, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x21, 0x11, 0x16, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21, 0x1F, 0x20, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2F, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

GUI_CONST_STORAGE GUI_BITMAP bmArrowRight_23x24 = {23,                    // xSize
                                                   24,                    // ySize
                                                   12,                    // BytesPerLine
                                                   4,                     // BitsPerPixel
                                                   _acArrowRight_23x24,   // Pointer to picture data (indices)
                                                   &_PalArrowRight_23x24, // Pointer to palette
                                                   NULL};

/*************************** End of file ****************************/
