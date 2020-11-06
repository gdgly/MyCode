/*******************************************************************************
*
* E M B E D D E D   W I Z A R D   P R O J E C T
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This software is delivered "as is" and shows the usage of other software 
* components. It is provided as an example software which is intended to be 
* modified and extended according to particular requirements.
* 
* TARA Systems hereby disclaims all warranties and conditions with regard to the
* software, including all implied warranties and conditions of merchantability 
* and non-infringement of any third party IPR or other rights which may result 
* from the use or the inability to use the software.
*
* This file was generated automatically by Embedded Wizard Studio.
*
* Please do not make any modifications of this file! The modifications are lost
* when the file is generated again by Embedded Wizard Studio!
*
* Version  : 9.30
* Date     : 14.02.2020  8:00:50
* Profile  : iMX_RT
* Platform : NXP.iMX_RT.RGB565
*
*******************************************************************************/

/* This is a font resource. */
EW_DEFINE_FONT_RES( CutterCaptionFont, 15, 4, 0, 16, 0x0001, 0x00C0 )
  EW_GLYPH( 0x0001, 0, -11, 7, 11, 7, 0x00000000 ),
  EW_GLYPH( 0x0020, 0, 0, 0, 0, 4, 0x00000101 ),                /* ' ' */
  EW_GLYPH( 0x0021, 1, -11, 2, 11, 4, 0x00000101 ),             /* '!' */
  EW_GLYPH( 0x0022, 1, -12, 4, 4, 5, 0x0000013F ),              /* '"' */
  EW_GLYPH( 0x0023, 0, -11, 10, 11, 10, 0x0000016C ),           /* '#' */
  EW_GLYPH( 0x0024, 0, -13, 9, 15, 9, 0x000002E5 ),             /* '$' */
  EW_GLYPH( 0x0025, 0, -11, 11, 11, 12, 0x000004A8 ),           /* '%' */
  EW_GLYPH( 0x0026, 0, -11, 10, 11, 10, 0x00000652 ),           /* '&' */
  EW_GLYPH( 0x0027, 0, -12, 2, 4, 3, 0x000007E7 ),              /* ''' */
  EW_GLYPH( 0x0028, 1, -13, 5, 17, 5, 0x000007FE ),             /* '(' */
  EW_GLYPH( 0x0029, 0, -13, 5, 17, 6, 0x000008EB ),             /* ')' */
  EW_GLYPH( 0x002A, 0, -11, 7, 7, 7, 0x000009D0 ),              /* '*' */
  EW_GLYPH( 0x002B, 0, -10, 9, 9, 9, 0x00000A75 ),              /* '+' */
  EW_GLYPH( 0x002C, 0, -2, 3, 4, 3, 0x00000B2A ),               /* ',' */
  EW_GLYPH( 0x002D, 0, -5, 5, 1, 4, 0x00000B54 ),               /* '-' */
  EW_GLYPH( 0x002E, 1, -2, 2, 2, 4, 0x00000B6E ),               /* '.' */
  EW_GLYPH( 0x002F, 0, -11, 7, 12, 7, 0x00000B7D ),             /* '/' */
  EW_GLYPH( 0x0030, 0, -11, 9, 11, 9, 0x00000C4A ),             /* '0' */
  EW_GLYPH( 0x0031, 1, -11, 5, 11, 9, 0x00000D69 ),             /* '1' */
  EW_GLYPH( 0x0032, 0, -11, 9, 11, 9, 0x00000DD3 ),             /* '2' */
  EW_GLYPH( 0x0033, 0, -11, 8, 11, 9, 0x00000F14 ),             /* '3' */
  EW_GLYPH( 0x0034, 0, -11, 9, 11, 9, 0x00001052 ),             /* '4' */
  EW_GLYPH( 0x0035, 1, -11, 8, 11, 9, 0x0000114A ),             /* '5' */
  EW_GLYPH( 0x0036, 1, -11, 8, 11, 9, 0x0000128A ),             /* '6' */
  EW_GLYPH( 0x0037, 0, -11, 9, 11, 9, 0x000013D8 ),             /* '7' */
  EW_GLYPH( 0x0038, 0, -11, 9, 11, 9, 0x000014ED ),             /* '8' */
  EW_GLYPH( 0x0039, 0, -11, 8, 11, 9, 0x00001660 ),             /* '9' */
  EW_GLYPH( 0x003A, 1, -8, 2, 8, 4, 0x000017A3 ),               /* ':' */
  EW_GLYPH( 0x003B, 0, -8, 3, 10, 3, 0x000017D4 ),              /* ';' */
  EW_GLYPH( 0x003C, 0, -8, 7, 7, 8, 0x00001826 ),               /* '<' */
  EW_GLYPH( 0x003D, 1, -7, 7, 4, 9, 0x000018F2 ),               /* '=' */
  EW_GLYPH( 0x003E, 1, -8, 7, 7, 8, 0x0000196E ),               /* '>' */
  EW_GLYPH( 0x003F, 0, -11, 7, 11, 8, 0x00001A41 ),             /* '?' */
  EW_GLYPH( 0x0040, 0, -11, 14, 14, 14, 0x00001B3C ),           /* '@' */
  EW_GLYPH( 0x0041, 0, -11, 11, 11, 10, 0x00001E05 ),           /* 'A' */
  EW_GLYPH( 0x0042, 1, -11, 9, 11, 10, 0x00001F71 ),            /* 'B' */
  EW_GLYPH( 0x0043, 0, -11, 10, 11, 10, 0x00002094 ),           /* 'C' */
  EW_GLYPH( 0x0044, 1, -11, 9, 11, 11, 0x000021F1 ),            /* 'D' */
  EW_GLYPH( 0x0045, 1, -11, 8, 11, 9, 0x000022EB ),             /* 'E' */
  EW_GLYPH( 0x0046, 1, -11, 8, 11, 9, 0x000023CC ),             /* 'F' */
  EW_GLYPH( 0x0047, 1, -11, 9, 11, 11, 0x00002492 ),            /* 'G' */
  EW_GLYPH( 0x0048, 1, -11, 10, 11, 11, 0x000025EF ),           /* 'H' */
  EW_GLYPH( 0x0049, 1, -11, 2, 11, 4, 0x000026A7 ),             /* 'I' */
  EW_GLYPH( 0x004A, 0, -11, 8, 11, 9, 0x000026C6 ),             /* 'J' */
  EW_GLYPH( 0x004B, 1, -11, 9, 11, 10, 0x00002777 ),            /* 'K' */
  EW_GLYPH( 0x004C, 1, -11, 8, 11, 9, 0x00002893 ),             /* 'L' */
  EW_GLYPH( 0x004D, 1, -11, 12, 11, 14, 0x00002911 ),           /* 'M' */
  EW_GLYPH( 0x004E, 1, -11, 9, 11, 11, 0x00002A78 ),            /* 'N' */
  EW_GLYPH( 0x004F, 0, -11, 11, 11, 11, 0x00002B5E ),           /* 'O' */
  EW_GLYPH( 0x0050, 1, -11, 9, 11, 10, 0x00002CC8 ),            /* 'P' */
  EW_GLYPH( 0x0051, 0, -11, 10, 13, 11, 0x00002DC3 ),           /* 'Q' */
  EW_GLYPH( 0x0052, 1, -11, 9, 11, 10, 0x00002F61 ),            /* 'R' */
  EW_GLYPH( 0x0053, 0, -11, 10, 11, 10, 0x00003083 ),           /* 'S' */
  EW_GLYPH( 0x0054, 0, -11, 10, 11, 10, 0x00003215 ),           /* 'T' */
  EW_GLYPH( 0x0055, 0, -11, 10, 11, 10, 0x000032D0 ),           /* 'U' */
  EW_GLYPH( 0x0056, 0, -11, 10, 11, 10, 0x000033AA ),           /* 'V' */
  EW_GLYPH( 0x0057, 0, -11, 14, 11, 14, 0x000034F7 ),           /* 'W' */
  EW_GLYPH( 0x0058, 0, -11, 10, 11, 10, 0x000036E9 ),           /* 'X' */
  EW_GLYPH( 0x0059, 0, -11, 10, 11, 10, 0x0000384B ),           /* 'Y' */
  EW_GLYPH( 0x005A, 0, -11, 9, 11, 10, 0x0000395C ),            /* 'Z' */
  EW_GLYPH( 0x005B, 1, -13, 4, 15, 4, 0x00003A8F ),             /* '[' */
  EW_GLYPH( 0x005C, 0, -11, 7, 12, 7, 0x00003AF2 ),             /* '\' */
  EW_GLYPH( 0x005D, 0, -13, 3, 15, 4, 0x00003BC8 ),             /* ']' */
  EW_GLYPH( 0x005E, 0, -11, 7, 5, 7, 0x00003C19 ),              /* '^' */
  EW_GLYPH( 0x005F, 0, 0, 8, 1, 7, 0x00003C95 ),                /* '_' */
  EW_GLYPH( 0x0060, 0, -12, 4, 2, 5, 0x00003CBD ),              /* '`' */
  EW_GLYPH( 0x0061, 1, -8, 7, 8, 9, 0x00003CE1 ),               /* 'a' */
  EW_GLYPH( 0x0062, 1, -12, 8, 12, 9, 0x00003DD2 ),             /* 'b' */
  EW_GLYPH( 0x0063, 0, -8, 8, 8, 8, 0x00003EC2 ),               /* 'c' */
  EW_GLYPH( 0x0064, 0, -12, 8, 12, 9, 0x00003FB2 ),             /* 'd' */
  EW_GLYPH( 0x0065, 0, -8, 8, 8, 8, 0x000040A9 ),               /* 'e' */
  EW_GLYPH( 0x0066, 0, -12, 6, 12, 6, 0x000041B3 ),             /* 'f' */
  EW_GLYPH( 0x0067, 0, -8, 8, 11, 9, 0x0000425B ),              /* 'g' */
  EW_GLYPH( 0x0068, 1, -12, 7, 12, 9, 0x0000438A ),             /* 'h' */
  EW_GLYPH( 0x0069, 1, -11, 2, 11, 4, 0x00004430 ),             /* 'i' */
  EW_GLYPH( 0x006A, -1, -11, 4, 14, 4, 0x00004466 ),            /* 'j' */
  EW_GLYPH( 0x006B, 1, -12, 8, 12, 8, 0x000044D8 ),             /* 'k' */
  EW_GLYPH( 0x006C, 1, -12, 2, 12, 4, 0x000045BF ),             /* 'l' */
  EW_GLYPH( 0x006D, 1, -8, 12, 8, 14, 0x000045E2 ),             /* 'm' */
  EW_GLYPH( 0x006E, 1, -8, 7, 8, 9, 0x000046D1 ),               /* 'n' */
  EW_GLYPH( 0x006F, 0, -8, 9, 8, 9, 0x00004758 ),               /* 'o' */
  EW_GLYPH( 0x0070, 1, -8, 8, 11, 9, 0x00004857 ),              /* 'p' */
  EW_GLYPH( 0x0071, 0, -8, 8, 11, 9, 0x0000495C ),              /* 'q' */
  EW_GLYPH( 0x0072, 0, -8, 5, 8, 5, 0x00004A55 ),               /* 'r' */
  EW_GLYPH( 0x0073, 0, -8, 8, 8, 8, 0x00004AA4 ),               /* 's' */
  EW_GLYPH( 0x0074, 0, -10, 5, 10, 5, 0x00004BB9 ),             /* 't' */
  EW_GLYPH( 0x0075, 1, -8, 7, 8, 9, 0x00004C25 ),               /* 'u' */
  EW_GLYPH( 0x0076, 0, -8, 8, 8, 8, 0x00004C9E ),               /* 'v' */
  EW_GLYPH( 0x0077, 0, -8, 12, 8, 12, 0x00004D73 ),             /* 'w' */
  EW_GLYPH( 0x0078, 0, -8, 8, 8, 8, 0x00004ED4 ),               /* 'x' */
  EW_GLYPH( 0x0079, 0, -8, 8, 11, 8, 0x00004FBE ),              /* 'y' */
  EW_GLYPH( 0x007A, 0, -8, 8, 8, 8, 0x000050DE ),               /* 'z' */
  EW_GLYPH( 0x007B, 0, -12, 6, 15, 5, 0x000051C4 ),             /* '{' */
  EW_GLYPH( 0x007C, 1, -11, 2, 13, 4, 0x0000529D ),             /* '|' */
  EW_GLYPH( 0x007D, -1, -12, 6, 15, 5, 0x000052C0 ),            /* '}' */
  EW_GLYPH( 0x007E, 1, -6, 9, 3, 11, 0x0000539E ),              /* '~' */
  EW_GLYPH( 0x00A0, 0, 0, 0, 0, 4, 0x00005415 ),
  EW_GLYPH( 0x00A1, 1, -8, 2, 11, 4, 0x00005415 ),
  EW_GLYPH( 0x00A2, 1, -10, 8, 12, 9, 0x00005454 ),
  EW_GLYPH( 0x00A3, 0, -11, 9, 11, 9, 0x00005578 ),
  EW_GLYPH( 0x00A4, 0, -11, 11, 11, 11, 0x0000569B ),
  EW_GLYPH( 0x00A5, 0, -11, 10, 11, 10, 0x00005839 ),
  EW_GLYPH( 0x00A6, 1, -11, 2, 13, 4, 0x00005997 ),
  EW_GLYPH( 0x00A7, 0, -11, 9, 15, 10, 0x000059D2 ),
  EW_GLYPH( 0x00A8, 0, -12, 6, 2, 7, 0x00005BF8 ),
  EW_GLYPH( 0x00A9, 0, -11, 12, 11, 13, 0x00005C1A ),
  EW_GLYPH( 0x00AA, 1, -11, 5, 6, 7, 0x00005E28 ),
  EW_GLYPH( 0x00AB, 0, -7, 8, 6, 8, 0x00005EA5 ),
  EW_GLYPH( 0x00AC, 1, -6, 7, 3, 9, 0x00005F49 ),
  EW_GLYPH( 0x00AD, 0, -5, 5, 1, 4, 0x00005F8E ),
  EW_GLYPH( 0x00AE, 0, -11, 12, 11, 13, 0x00005FA8 ),
  EW_GLYPH( 0x00AF, 0, -11, 7, 1, 7, 0x00006184 ),
  EW_GLYPH( 0x00B0, 1, -11, 4, 4, 6, 0x000061A6 ),
  EW_GLYPH( 0x00B1, 0, -11, 8, 11, 9, 0x000061EC ),
  EW_GLYPH( 0x00B2, 0, -11, 6, 6, 6, 0x000062BE ),
  EW_GLYPH( 0x00B3, 0, -11, 6, 6, 6, 0x00006354 ),
  EW_GLYPH( 0x00B4, 1, -12, 4, 2, 5, 0x000063E6 ),
  EW_GLYPH( 0x00B5, 1, -8, 7, 11, 9, 0x0000640B ),
  EW_GLYPH( 0x00B6, 0, -11, 7, 11, 8, 0x000064B5 ),
  EW_GLYPH( 0x00B7, 1, -7, 2, 2, 4, 0x00006560 ),
  EW_GLYPH( 0x00B8, 0, 0, 4, 3, 4, 0x00006573 ),
  EW_GLYPH( 0x00B9, 1, -11, 3, 6, 6, 0x0000659D ),
  EW_GLYPH( 0x00BA, 0, -11, 7, 6, 7, 0x000065D4 ),
  EW_GLYPH( 0x00BB, 0, -7, 8, 6, 8, 0x0000666A ),
  EW_GLYPH( 0x00BC, 1, -11, 11, 11, 12, 0x0000670A ),
  EW_GLYPH( 0x00BD, 1, -11, 11, 11, 12, 0x0000686E ),
  EW_GLYPH( 0x00BE, 0, -11, 12, 11, 12, 0x000069E3 ),
  EW_GLYPH( 0x00BF, 0, -8, 8, 11, 8, 0x00006BB4 ),
  EW_GLYPH( 0x00C0, 0, -14, 11, 14, 10, 0x00006CA3 ),
  EW_GLYPH( 0x00C1, 0, -14, 11, 14, 10, 0x00006E56 ),
  EW_GLYPH( 0x00C2, 0, -14, 11, 14, 10, 0x0000700A ),
  EW_GLYPH( 0x00C3, 0, -15, 11, 15, 10, 0x000071D0 ),
  EW_GLYPH( 0x00C4, 0, -14, 11, 14, 10, 0x000073AC ),
  EW_GLYPH( 0x00C5, 0, -15, 11, 15, 10, 0x00007565 ),
  EW_GLYPH( 0x00C6, -1, -11, 16, 11, 15, 0x00007747 ),
  EW_GLYPH( 0x00C7, 0, -11, 10, 14, 10, 0x00007923 ),
  EW_GLYPH( 0x00C8, 1, -14, 8, 14, 9, 0x00007AC8 ),
  EW_GLYPH( 0x00C9, 1, -14, 8, 14, 9, 0x00007BE7 ),
  EW_GLYPH( 0x00CA, 1, -14, 8, 14, 9, 0x00007D07 ),
  EW_GLYPH( 0x00CB, 1, -14, 8, 14, 9, 0x00007E39 ),
  EW_GLYPH( 0x00CC, -1, -14, 4, 14, 4, 0x00007F5E ),
  EW_GLYPH( 0x00CD, 1, -14, 4, 14, 4, 0x00007FC5 ),
  EW_GLYPH( 0x00CE, 0, -14, 5, 14, 4, 0x0000802D ),
  EW_GLYPH( 0x00CF, -1, -14, 6, 14, 4, 0x000080B5 ),
  EW_GLYPH( 0x00D0, 0, -11, 10, 11, 11, 0x0000813E ),
  EW_GLYPH( 0x00D1, 1, -15, 9, 15, 11, 0x00008279 ),
  EW_GLYPH( 0x00D2, 0, -14, 11, 14, 11, 0x000083C7 ),
  EW_GLYPH( 0x00D3, 0, -14, 11, 14, 11, 0x00008578 ),
  EW_GLYPH( 0x00D4, 0, -14, 11, 14, 11, 0x0000872A ),
  EW_GLYPH( 0x00D5, 0, -15, 11, 15, 11, 0x000088EE ),
  EW_GLYPH( 0x00D6, 0, -14, 11, 14, 11, 0x00008AC8 ),
  EW_GLYPH( 0x00D7, 0, -9, 8, 7, 9, 0x00008C7F ),
  EW_GLYPH( 0x00D8, 0, -12, 11, 13, 11, 0x00008D5E ),
  EW_GLYPH( 0x00D9, 0, -14, 10, 14, 10, 0x00008F4E ),
  EW_GLYPH( 0x00DA, 0, -14, 10, 14, 10, 0x0000906C ),
  EW_GLYPH( 0x00DB, 0, -14, 10, 14, 10, 0x0000918B ),
  EW_GLYPH( 0x00DC, 0, -14, 10, 14, 10, 0x000092BC ),
  EW_GLYPH( 0x00DD, 0, -14, 10, 14, 10, 0x000093E0 ),
  EW_GLYPH( 0x00DE, 1, -11, 8, 11, 9, 0x00009536 ),
  EW_GLYPH( 0x00DF, 1, -12, 9, 12, 10, 0x0000960E ),
  EW_GLYPH( 0x00E0, 1, -11, 7, 11, 9, 0x00009744 ),
  EW_GLYPH( 0x00E1, 1, -11, 7, 11, 9, 0x00009870 ),
  EW_GLYPH( 0x00E2, 1, -11, 7, 11, 9, 0x0000999D ),
  EW_GLYPH( 0x00E3, 1, -12, 7, 12, 9, 0x00009ADC ),
  EW_GLYPH( 0x00E4, 1, -11, 7, 11, 9, 0x00009C2D ),
  EW_GLYPH( 0x00E5, 1, -12, 7, 12, 9, 0x00009D5F ),
  EW_GLYPH( 0x00E6, 0, -8, 14, 8, 14, 0x00009EB6 ),
  EW_GLYPH( 0x00E7, 0, -8, 8, 11, 8, 0x0000A087 ),
  EW_GLYPH( 0x00E8, 0, -11, 8, 11, 8, 0x0000A1BA ),
  EW_GLYPH( 0x00E9, 0, -11, 8, 11, 8, 0x0000A302 ),
  EW_GLYPH( 0x00EA, 0, -11, 8, 11, 8, 0x0000A44B ),
  EW_GLYPH( 0x00EB, 0, -11, 8, 11, 8, 0x0000A5A6 ),
  EW_GLYPH( 0x00EC, -1, -11, 4, 11, 4, 0x0000A6F4 ),
  EW_GLYPH( 0x00ED, 1, -11, 4, 11, 4, 0x0000A751 ),
  EW_GLYPH( 0x00EE, -1, -11, 5, 11, 4, 0x0000A7AF ),
  EW_GLYPH( 0x00EF, -1, -11, 6, 11, 4, 0x0000A82A ),
  EW_GLYPH( 0x00F0, 0, -12, 9, 12, 9, 0x0000A8A3 ),
  EW_GLYPH( 0x00F1, 1, -12, 7, 12, 9, 0x0000AA28 ),
  EW_GLYPH( 0x00F2, 0, -11, 9, 11, 9, 0x0000AB0F ),
  EW_GLYPH( 0x00F3, 0, -11, 9, 11, 9, 0x0000AC4F ),
  EW_GLYPH( 0x00F4, 0, -11, 9, 11, 9, 0x0000AD90 ),
  EW_GLYPH( 0x00F5, 0, -12, 9, 12, 9, 0x0000AEE3 ),
  EW_GLYPH( 0x00F6, 0, -11, 9, 11, 9, 0x0000B04A ),
  EW_GLYPH( 0x00F7, 0, -10, 9, 9, 9, 0x0000B190 ),
  EW_GLYPH( 0x00F8, 0, -9, 9, 10, 9, 0x0000B24A ),
  EW_GLYPH( 0x00F9, 1, -11, 7, 11, 9, 0x0000B39E ),
  EW_GLYPH( 0x00FA, 1, -11, 7, 11, 9, 0x0000B452 ),
  EW_GLYPH( 0x00FB, 1, -11, 7, 11, 9, 0x0000B507 ),
  EW_GLYPH( 0x00FC, 1, -11, 7, 11, 9, 0x0000B5CE ),
  EW_GLYPH( 0x00FD, 0, -11, 8, 14, 8, 0x0000B688 ),
  EW_GLYPH( 0x00FE, 1, -12, 8, 15, 9, 0x0000B7E7 ),
  EW_GLYPH( 0x00FF, 0, -11, 8, 14, 8, 0x0000B904 ),

  EW_FONT_PIXEL( CutterCaptionFont, 0x0000BA68 )                /* ratio 74.11 % */
    0xCF7BDCE3, 0xFEF7BBF0, 0xE498C398, 0x2D6B1334, 0x279093C8, 0x9C85AD61, 0x31873266,
    0x7F7BDDF9, 0xC009BFDE, 0x9BD3D4FF, 0x0807FC7F, 0x47BF0181, 0x78F3C437, 0xE27BAC7E,
    0x75AFDCDE, 0xDD5FBAD7, 0x07FC7917, 0xC43C8F58, 0xF3EFB9BD, 0x1BFB88DE, 0xC837B8F7,
    0xBF9C1329, 0x4E918167, 0x5404DE02, 0x7FCFF980, 0xFEFB79E3, 0x31EB7367, 0xF858C3E6,
    0x61BE5F15, 0xDE7F8CBC, 0xEDF8C06F, 0x52B17FFF, 0x2DE5F7AE, 0x1BF58464, 0x3EF0ADF2,
    0x87E7BBFF, 0xA017EE3E, 0x69FF9E03, 0x7A9CEFC0, 0xE18C47C4, 0xC625DF49, 0xE0F4E4F0,
    0xEFD54E77, 0xFA7FE783, 0x13C00BF7, 0x81FF3BF3, 0x7D3977E8, 0xFCF2FBF0, 0x9CB11255,
    0xC7E24ABF, 0xFB50FA72, 0xFBE20BFE, 0x1902FEDD, 0x8C89158F, 0xE8818F47, 0x707F1FF7,
    0xBE087462, 0x38C9D767, 0xDF1E9F23, 0xC1062B3C, 0xD592EF17, 0xEFC1A729, 0x5F8CF7B9,
    0x018571AD, 0x7306FC3E, 0x9E5EFCBD, 0x3C1FB0F1, 0x48483889, 0xF1278388, 0xC1E3507F,
    0x8D5CC5EF, 0xE7855A5F, 0x4C1F641B, 0x3D87CF13, 0x0521E982, 0x7A60A400, 0x3E7823D8,
    0xE1F6531E, 0x45C40779, 0xCFFFE880, 0x827BE67B, 0x06BA78BD, 0xF2F5AEFD, 0xF10D7E5B,
    0x025F9004, 0xDEE78000, 0x3CFBDF6D, 0xDEFB6EF7, 0xC4000007, 0x460FB80C, 0xBBF1BD54,
    0x03F7C6F7, 0x07CE0FEA, 0x27CC0F51, 0x1E503BE1, 0x7D440F38, 0xEF849F30, 0xFE078D40,
    0xF7FEB013, 0x73DF30BF, 0xCDF277DF, 0xF8C7E6A1, 0x20043FE3, 0x30080000, 0x0771B184,
    0x3EB52ADF, 0xF7DEFBE6, 0x7DFAD49D, 0x7F45627D, 0x00000173, 0xFFA00000, 0xD5F0BFF7,
    0xE4BBEFB9, 0x9FAD43D3, 0x2B100FD1, 0x5F01F588, 0x3FCDF04E, 0xD60375E8, 0xFDF309BC,
    0xDF637827, 0xFF43EF7B, 0x757C9EEF, 0xCF13F76F, 0x9C6EAA9B, 0x7ACC0807, 0x0EFBEF71,
    0x977BFBDC, 0x9C6FCD40, 0x8D3AA302, 0xFB3DF3E7, 0x7D816FDE, 0x98C01E81, 0x1FEF380B,
    0x5A8173BC, 0x13AF882F, 0xFBDEF1BC, 0x7BDF6FB9, 0x00BEE7EF, 0x7BDFF800, 0xF77C65EF,
    0x904C4BDE, 0xCE738402, 0xD9F65617, 0x25FEAFF3, 0x481118EF, 0xCD21F7F3, 0x8F4479F7,
    0x6F73BE31, 0xF3BF51FC, 0xBEFB7D62, 0xE056FF64, 0xCCF01E37, 0x64379CEF, 0x9F9FB3DD,
    0x9F7C8F98, 0xD7298BC8, 0x2CFD94C6, 0xFFC8CEF9, 0xCF5EBBBE, 0x7BDEF7BD, 0xBDEF73C7,
    0xDF0073B7, 0x80B1CC07, 0xBE4F026F, 0xD402BBC0, 0x49F701F8, 0xDE05EA30, 0xBFF58031,
    0xBEF585FF, 0xBF277DF7, 0xC03EAA55, 0xD4ABBC58, 0xBBF53C3A, 0xB5E87ABF, 0xF98B5EEF,
    0x15EFC61B, 0xF9E22201, 0xF09EF8D2, 0x3EA7BDD5, 0xE2BFB9F4, 0x97F77DAD, 0x9EB4DF31,
    0x4FD89A5F, 0x4F11B89A, 0xD5F267A7, 0xEF057B3E, 0x203E6F39, 0x773C3F9F, 0xFD39EF15,
    0x3F7C7EFA, 0xFBE1FBE0, 0xE003F7C1, 0xF551183E, 0xE61FA806, 0xFFD622FE, 0xECDFBBF7,
    0xBB30AFFA, 0xFAC42BFE, 0xC3F77EFF, 0xEFFC5FDC, 0xFEFEF7BD, 0x7F7BDEF7, 0xF7BDFF80,
    0xC07EDFDE, 0xE0AFFBF3, 0xEDDFBF3D, 0xAF9EEE64, 0xFBE7BB98, 0x76EFDFDE, 0x0AFFBF3E,
    0x6F3DDF8C, 0xFBDC7FC4, 0xFC5A33F4, 0x13D8FEAA, 0xF9AC69FA, 0x03DBC41F, 0x02B105DE,
    0x01600CF2, 0xF3DFFBE3, 0x773E807B, 0x83E7D3DF, 0x304FFE35, 0xEFC9A37E, 0xE5FF3DE3,
    0x84F7C27D, 0xA3F79C6F, 0xEA33F3CA, 0x65272627, 0x208C27AA, 0x1067084F, 0x18427183,
    0xCA6E1FF8, 0xFAD4BFC7, 0x1CF1E7CB, 0xE7739D6B, 0x55BC3DFF, 0xFDCBE77E, 0xFFF125FF,
    0x601E307A, 0x3B9EF75C, 0x0013DE00, 0x31CC04CB, 0x7CF7C03F, 0xBF18C039, 0xC6FC0FAC,
    0xF3015FF0, 0xA330B4C7, 0xE1F1BDEF, 0x77BDEF3F, 0x0FEB218F, 0x2CBE7C63, 0x7BDE5BF0,
    0x7913DDEF, 0x09DF7DEF, 0x0B01B53C, 0xF790F2B0, 0xDE455EDE, 0xC0BD777B, 0x600016F8,
    0xF7BC8B7C, 0xF445E79E, 0xF03BFEFF, 0xF1DEF71F, 0xF297E3A7, 0x81E78F1D, 0xE0BCBFAC,
    0x002001D7, 0xE5BE0BC8, 0xF49F2079, 0x1DF297C6, 0x7D8FF88F, 0x7BDED8EF, 0xE44DFFEF,
    0x02ECFBBD, 0xF80BE6B1, 0x025201F2, 0x04A40000, 0x7A207CBE, 0x3BBDE4BE, 0xBDEF7976,
    0xEF25DEF7, 0x002EF7BD, 0xEF790000, 0xDEF23FBD, 0x00007F7B, 0xF7BDE400, 0x7BDEF5DE,
    0xBC8FBDEF, 0x00FBDEF7, 0x7BC80000, 0x7BC97DEF, 0x00017DEF, 0xF7880000, 0x886FFF7F,
    0xDCDEF79D, 0xDF94BF5E, 0x74414F58, 0x01F301E6, 0xF7BDCF00, 0xBDCF0E37, 0x5802B7E5,
    0x33507FCF, 0x9EF77EFD, 0x0FF7DEFE, 0x00000DD6, 0x79000000, 0x91B7BDEF, 0x1B7BDEF7,
    0x00000000, 0x0002F780, 0x017FF000, 0x00000000, 0xCF007200, 0x689E7186, 0xC7FE4F5E,
    0xF7CFF939, 0x98067D0F, 0xBCF01BF3, 0x7BF182BF, 0x9CFFC81F, 0xF18266E0, 0xA8C16BFE,
    0x5A80BAF8, 0x079D025F, 0xFF7DF270, 0x00000000, 0x00000000, 0xF7BC8000, 0xBBDE3BDE,
    0x3E5F7580, 0x82C8C3E0, 0x03AAC91A, 0x93EE26B7, 0xFCA81D64, 0x962D46F8, 0x827E61EF,
    0x4D33C730, 0x26F9D620, 0x03E357C0, 0x77095518, 0x68CFDF83, 0x7C01CE40, 0x1B270179,
    0x98039EC8, 0xA3BC01CF, 0x8135EC81, 0x02F80959, 0x1DFF7FFA, 0x77BDC7B0, 0x97F2B1FC,
    0x37CD17F2, 0x0790F3C1, 0x1806149C, 0x84300C22, 0xDF24E0BC, 0xCAC3CF02, 0x345FCA5F,
    0x8EF7B8F6, 0xEF7BBF3F, 0xDD497FFD, 0x00DC6F7B, 0x0C0165F9, 0xEA58BF10, 0x50ED7BDE,
    0x25F3DEF7, 0x00000000, 0xFDFFDE20, 0xEE3FE237, 0xC6F363BD, 0x65CBF297, 0x8BF5103E,
    0x00FF83F8, 0x3F888000, 0x81F30FF8, 0xBE379FA8, 0xF12E5F94, 0x7D777BCF, 0xB3DFFE88,
    0xB7F406DE, 0xFDEF7BDF, 0x7BDEF237, 0x7E301F9E, 0xF8C00015, 0xBDEF213D, 0x7BC8FBFB,
    0xE7C812FF, 0x4098F405, 0xE7403F3E, 0xFEE77EA4, 0x7FEFD41E, 0x4E4DFDEE, 0x26366A4D,
    0xF8EF2F7C, 0xEE31720D, 0x4257FFF8, 0x3F6739F4, 0xF3BC64AC, 0x89C1FBC7, 0xBE3273D0,
    0x9FFBF30A, 0xBDE7EB7B, 0xEF7BDEF7, 0x57BDEF1D, 0x00077BDF, 0x00000000, 0x00000000,
    0x1F710000, 0x00006E78, 0x00000000, 0x11000000, 0xE847F87F, 0x66CCF0F9, 0xE739CEFE,
    0xE07F7D37, 0xA82C9DFF, 0xF87F953C, 0xAC16F967, 0x9E1E2787, 0xDC3AC8F8, 0xA2279C4A,
    0xCB58F0FE, 0x5FFFEB04, 0x01F557C0, 0x79818C63, 0xF7E07D03, 0x0313C295, 0x4FF33FCF,
    0xA231F8E6, 0xAFE4F154, 0x60EE18A8, 0xFF08CF3F, 0x97E794A2, 0xCC9FD4B9, 0x9D9E18F1,
    0x17BDA851, 0xEE062ABB, 0x17F94DAC, 0x55078E54, 0x607CC87F, 0xD0BCF22B, 0xC1CF6467,
    0xE3987398, 0x4671B370, 0xEF90BCAF, 0x4B00E77C, 0x068B40BC, 0x0B3DBE63, 0x2F59AE6E,
    0x78EF2F3A, 0xF907398D, 0xB093EACE, 0x10FD78CE, 0x33D11AEF, 0xB4733579, 0x9FA06F9C,
    0xAA0B1BF1, 0x1DE06CEE, 0x036900F5, 0x30000000, 0xDEF7BDEE, 0xDEF71BFB, 0x64175F7B,
    0x68EF02AF, 0xC6039EB0, 0xD9B8073B, 0xB180F3A0, 0x16A704DE, 0xBDEEB278, 0xBDFFDEF7,
    0x0000DE61, 0x00000000, 0x3FAC6F30, 0xEA20A398, 0x35015380, 0x303EF826, 0x1F3C4073,
    0xC6A02B38, 0xE607DF02, 0xFF7BFF18, 0x0000001F, 0x187FF800, 0x45EBC077, 0xFC93EF3E,
    0xB93F599E, 0xDEE2BD5E, 0x23BDEF7B, 0xB3BC9FFF, 0x97FEFFF4, 0xBCF7B9F7, 0xCF1A77B3,
    0x6F7FF78D, 0x5BDCEAF9, 0xDA80DF9E, 0xDD78D561, 0x5FFE6B73, 0xC0000000, 0x5179CEF8,
    0x63EBFCE7, 0x804FD195, 0xA6004125, 0x19E8CAB4, 0x7AFF39E6, 0x5FDCF789, 0xF77BCFF1,
    0xB0DE3597, 0xFF121BF2, 0x89288817, 0xC37A8D6F, 0xF797C7AA, 0xEF027FEE, 0x8000001F,
    0x792F9CF7, 0x29DE7FEB, 0x25186FE6, 0x2300803D, 0xA1BF980A, 0xCFFCFD16, 0x7F73E859,
    0xDDEF2FC5, 0x85FA8E5F, 0xEE72BE35, 0xDEE219BD, 0x623BEF7B, 0x18771A80, 0xFFCFD87B,
    0xBE20DFDE, 0xFDD7A3F3, 0x65C04F51, 0x8CFBECDC, 0x001F7D9B, 0xE0000000, 0xBFEBE73D,
    0x7DE7FEB7, 0x9461BF58, 0x18000F11, 0x37F300F1, 0xFF9FA28C, 0x9CFA2779, 0xA1BF422F,
    0xB7BAF3EA, 0x005FFE7B, 0x3E8C0000, 0x7FEA17E7, 0x91EB6CF6, 0x000100F5, 0xC7DF0000,
    0x007EFDF7, 0xF817BF00, 0x005EFCBD, 0x66000000, 0xFF7E773C, 0x00000005, 0xE6033AC0,
    0xFA781FFB, 0x2ABFD81B, 0xF82AFF58, 0xCC12FE8D, 0x9F17C03A, 0x00000BDF, 0x9CEFDFFC,
    0x7E73DE37, 0x5FF3DEA1, 0x7EBB9F77, 0xCF3C61BE, 0x000B7E23, 0x00000000, 0x6FFE0000,
    0xEB0BF39F, 0xAD7CF67F, 0x01015647, 0xAC000000, 0xBC2FFDFF, 0x7BE7B9DF, 0xF461ECC5,
    0x7942C78C, 0x6163C180, 0x30F66279, 0x3BF7867A, 0xFFAF7CF7, 0xA2F39DFB, 0x8FAFF3DE,
    0x27BF186F, 0xC00123C0, 0x8C37C313, 0xE7BE62DF, 0x9DF92F5F, 0xC00002F3, 0xFEF7CE7B,
    0x6F3FF57D, 0x5187A789, 0x690002D2, 0x187A7881, 0xF3FF57C5, 0x7CE7BC4E, 0x6E200009,
    0x1FF8C3EF, 0x0000004E, 0x7E73BF20, 0x5C6E75C9, 0x65745B91, 0xBC56FF74, 0xFE73DD69,
    0xBCF3F19F, 0xECC6A7FF, 0xC774C4F0, 0xAD2FFFBD, 0xAEEDB80B, 0x0002EEDB, 0x75582100,
    0xFDE2FFFA, 0x40000001, 0x5AA54F00, 0xCA73ED7A, 0xA733883C, 0xC3AD3287, 0xC44F7C59,
    0x5AC631F3, 0xFFFBE063, 0x1355983F, 0x7F582AA2, 0xAB387EFC, 0x613D4532, 0xB1F233C4,
    0x548D4B2A, 0xBBFFFFDB, 0xB27FF176, 0xFCF153D6, 0xD9915D28, 0x3F9EA063, 0x2D7055BF,
    0xEE33F89E, 0xD6393AC3, 0xD4EDF22F, 0x899F7BF9, 0xC107CF53, 0xE0EAB380, 0xA972FEF5,
    0xC77E8AF9, 0x39DC49BC, 0xB4C561E3, 0xFF17FC7E, 0x54FEB231, 0x7C2C9EFE, 0x9983EFCF,
    0x4AA881E3, 0xC660FEB0, 0xC0EF9C44, 0x7BDEF7B8, 0x4F7BDC63, 0x7C5F013E, 0x5A81CFD0,
    0xF37E44BF, 0x3C2F9381, 0xEF7BDC63, 0xFAB1B983, 0xBC899BE0, 0x28AC4800, 0xB7837EDE,
    0x028AC0DF, 0xF85E4009, 0xE3ECC4CD, 0x0000005D, 0x13D384F6, 0x03B83F39, 0x13150080,
    0xF92FBEF9, 0x13152FBE, 0x903B8001, 0x49E9C3F3, 0x8C1EEEFC, 0xFFBEE3AF, 0xCF1C3BC7,
    0xFBFABDFF, 0xFE7ABEF8, 0xFC448007, 0xB980A80A, 0x7E9E5EFD, 0xBBD7AEEF, 0xB196FE4A,
    0xB1800F31, 0x2ADF3F51, 0x7BF669D9, 0xEDCCBD77, 0xC40320D7, 0xE06FEE7B, 0x3FE6F79F,
    0x2FC3718C, 0x0FBC8B0A, 0xFBEDB580, 0xFBBE3AC7, 0x60030007, 0xFCF9E059, 0x05F7BDEF,
    0xF59FFC40, 0x6755FFBF, 0xB9F6FCC4, 0xD872FF67, 0x6FC61BF9, 0xBE07DF14, 0x13C0B229,
    0x02C88001, 0x03EF844F, 0xF97E29BF, 0x9F2FC61B, 0xB9F7B58C, 0xE639EC67, 0x989EF01D,
    0x17F318D5, 0x9FA1E7DE, 0xCF56EC87, 0xDD5CE60F, 0x1DEB7B81, 0x7BDC5DEF, 0xDC5DEFA3,
    0x8BBDF57B, 0x77BEAF7B, 0xFF800001, 0xFDFFC00B, 0x7F3000BF, 0x661EFCE7, 0xF7F6739F,
    0xAAC3D7F8, 0xF5F42623, 0xA30D7FE6, 0xFFB7C6FC, 0xAF5629FF, 0x41BA7DDF, 0x79E33BF4,
    0xFEAF8207, 0x2F7E7EFF, 0xCCFC4E7D, 0xEF78C278, 0xF10B7D78, 0x315FCC44, 0xBEBF7B6B,
    0x713DFFE7, 0x2007DF1E, 0xBFFDFFDF, 0xFBBDCF09, 0xD18B7BEE, 0xFFDFF9FB, 0xBEF4DF73,
    0xEBFBEFF1, 0x95559FEC, 0x054F6E65, 0x208588B1, 0x5560B116, 0x53DB9965, 0x7DFE37DE,
    0x33FD9D7F, 0xEFFCFDDE, 0x526FB9FF, 0xEFBBEEF7, 0x1EEFB52D, 0xF67AB7D1, 0xB73EF35D,
    0x3DFAFE39, 0x4D8DB182, 0xF2E71B9C, 0x067BE33D, 0xBE33DF00, 0xC6E71067, 0xF7BDEEB9,
    0xBDEF75DE, 0xDEEFC017, 0x7FF7C81B, 0xDD426FFF, 0xB7BEEFBB, 0x9FFEEF18, 0x9BEE7FFB,
    0xF77C37DE, 0xAB3FD9BB, 0xC054F2C0, 0xC046DF77, 0x5586DF77, 0x794F4CF0, 0x3FD900DF,
    0x92FFDDE3, 0x7526FBBF, 0xDEFBBEEF, 0x7BDEF712, 0xF5FFFD57, 0x7BC2FBDE, 0x18030BEF,
    0x1800003B, 0xFEE76EF7, 0xB9DBBDC7, 0x4400007F, 0xDC0BF901, 0xAFBDEF7B, 0x79A9673E,
    0xE2751DFF, 0x0EFE60C9, 0x58C3DFFD, 0x3BE3EE75, 0xFCF235E7, 0xEFFE8C67, 0x33FFFC19,
    0x767283EB, 0xBF3FFE67, 0x78BFF9F5, 0x000000FF, 0x8C350060, 0x67EDCF22, 0xD7F7FE7A,
    0xFE80003F, 0xADFAFBDF, 0x813028C4, 0xFC018C09, 0xCEF8809F, 0x00001049, 0x5E716FBF,
    0x2ABB956E, 0xF3FEFFD7, 0xEC6002FF, 0x77E707BB, 0x34E6477F, 0xD3990033, 0xF77E70CC,
    0xFF0FF877, 0x7BC4F781, 0xEAAFAA82, 0xABEAA003, 0xBC4F78FA, 0x00FF6427, 0xC6A898CE,
    0x007EF03E, 0xF18097EF, 0xC57B802C, 0x77F9E5FF, 0xE301BF0D, 0xB82C4F69, 0xA307F447,
    0xCE679986, 0xDEEB3465, 0x0FF65739, 0x6A898CE0, 0x07EF03EC, 0x18097EF0, 0xB7B802CF,
    0xFF3C59CF, 0xBFEF35AE, 0x9D74F183, 0x07B83278, 0x351877F3, 0x8C1EFFE8, 0xF73AAC66,
    0x0D39DF89, 0x4DF3FF18, 0xFFF39354, 0xF83F789B, 0x2FDE19EF, 0x8C227E79, 0x7389E167,
    0xFF8DEE3B, 0xABFE77CB, 0x3006FC6B, 0x01627E9E, 0xC07F44F7, 0xCCF331A8, 0xBADA30B9,
    0xEF85CE77, 0x0FBE0003, 0x93C40FE8, 0xF868FF10, 0xE9F21FC5, 0x7FA93080, 0x9DC4FC8C,
    0xF1B9E4E1, 0x401FFF21, 0xB90059DE, 0x027BC00B, 0x39809960, 0x9EF807E6, 0xE318072F,
    0xDF81F597, 0x602BFE18, 0x661698FE, 0x3E37BDF4, 0xF7BDE7FC, 0xFD6431EE, 0x97CF8C61,
    0xC80B7E05, 0x5BF007FF, 0x01FBC01F, 0x960027BC, 0x7E639809, 0x72F9EF80, 0x597E3180,
    0xE18DF81F, 0x8FE602BF, 0xDF466169, 0x7FC3E37B, 0x1EEF7BDE, 0xC61FD643, 0xE0597CF8,
    0x7FFCC0B7, 0x47B7D401, 0x7DE3B503, 0x8009EF01, 0x98E60265, 0xBE7BE01F, 0x5F8C601C,
    0x637E07D6, 0xF980AFF8, 0xD1985A63, 0xF0F8DEF7, 0xBBDEF79F, 0x87F590C7, 0x165F3E31,
    0xC0002DF8, 0x826FAF3A, 0x1313EEF7, 0x0FCE789C, 0x58009EF0, 0xF98E6026, 0xCBE7BE01,
    0x65F8C601, 0x8637E07D, 0x3F980AFF, 0x7D1985A6, 0xFF0F8DEF, 0x7BBDEF79, 0x187F590C,
    0x8165F3E3, 0xC79C42DF, 0xC40001F7, 0xE01F7C79, 0x4CB0013D, 0x03F31CC0, 0x0397CF7C,
    0xFACBF18C, 0xFF0C6FC0, 0x4C7F3015, 0xDEFA330B, 0xF3FE1F1B, 0x18F77BDE, 0xC630FEB2,
    0xBF02CBE7, 0x0BDFBE05, 0x0237E318, 0x0237E318, 0x805EFDF0, 0x32C004F7, 0x0FCC7301,
    0x0E5F3DF0, 0xEB2FC630, 0xFC31BF03, 0x31FCC057, 0x7BE8CC2D, 0xCFF87C6F, 0x63DDEF7B,
    0x18C3FAC8, 0xFC0B2F9F, 0x7BDF4016, 0x0077BDEF, 0x7BDC7339, 0xFBC01DEF, 0x3E600054,
    0xF44001EF, 0x8DF8004C, 0xF7BDEF26, 0x749A7A85, 0xBC2FBDEF, 0x003F7BBE, 0xF7BDEE3D,
    0x0D9C8027, 0x131DE00B, 0xFBDEF738, 0xFF7FFA23, 0x7B8FF81D, 0xF1D3F8EF, 0xC78EF94B,
    0x5FD640F3, 0x00EBF05E, 0x05E40010, 0x903CF2DF, 0x4BE37A4F, 0xFC478EF9, 0x6C77BEC7,
    0x1AA27BC4, 0x7700AB70, 0x81FFF215, 0xEE40B3BC, 0xBDEF7BC2, 0xEF792EF7, 0x000177BD,
    0xEF7BC800, 0xDEF791FD, 0x000003FB, 0xF7BDEF20, 0x03FFE42E, 0xF781F5BF, 0xBDEF7BC3,
    0xEF792EF7, 0x000177BD, 0xEF7BC800, 0xDEF791FD, 0x000003FB, 0xF7BDEF20, 0x0BFFE62E,
    0xA347B7D4, 0xEF2FBC76, 0xBBDEF7BD, 0xDEF7BDE4, 0x20000005, 0x47F7BDEF, 0x0FEF7BDE,
    0xBC800000, 0xC4BBDEF7, 0x001F7C79, 0xE7DF1E71, 0x7BDEF7BD, 0xDEF7BC97, 0x000000BB,
    0xFEF7BDE4, 0xFDEF7BC8, 0x90000001, 0x577BDEF7, 0x67793FFE, 0x17BC5DC9, 0x00000000,
    0xDF9FFF20, 0xEF1FBCFA, 0x00000005, 0x7FFCC000, 0x5D1EDF51, 0x7BD7DE3B, 0x00000001,
    0xCE200000, 0x3880FBE3, 0xBDE3EF8F, 0x00000000, 0x80000000, 0xBF3DEF75, 0xFF9EE702,
    0xF7F300B7, 0x1F19E026, 0x76BF1CC0, 0x3B5F80EE, 0x1CC00077, 0x103F2780, 0x7389D7F3,
    0x005BFFEF, 0x9BEBCEB0, 0x313EEF78, 0x3F39E271, 0x9FBF06EE, 0x039C80D1, 0x4E02F2F8,
    0x073D9036, 0x78039F30, 0x6BD90347, 0xF012B302, 0x03FFE405, 0x200B3BC8, 0x7FFA0177,
    0xC7B01DFF, 0xB1FC77BD, 0x17F297F2, 0xF3C137CD, 0x149C0790, 0x0C221806, 0xE0BC8430,
    0xCF02DF24, 0xCA5FCAC3, 0xB8F6345F, 0x203F8EF7, 0x6FC01FFF, 0x07EF007D, 0x77FDFFE8,
    0xDEF71EC0, 0x5FCAC7F1, 0xDF345FCA, 0x1E43CF04, 0x60185270, 0x10C03088, 0x7C9382F2,
    0x2B0F3C0B, 0xD17F297F, 0x3BDEE3D8, 0x7FFCC0FE, 0x47B7D401, 0x7DE3B503, 0x7FDFFE81,
    0xEF71EC07, 0xFCAC7F1D, 0xF345FCA5, 0xE43CF04D, 0x01852701, 0x0C030886, 0xC9382F21,
    0xB0F3C0B7, 0x17F297F2, 0xBDEE3D8D, 0xB0000FE3, 0xE09BEBCE, 0x04C4FBBD, 0x03F39E27,
    0x1DFF7FFA, 0x77BDC7B0, 0x97F2B1FC, 0x37CD17F2, 0x0790F3C1, 0x1806149C, 0x84300C22,
    0xDF24E0BC, 0xCAC3CF02, 0x345FCA5F, 0x8EF7B8F6, 0x7C79C43F, 0x9C40001F, 0xFD01F7C7,
    0xD80EFFBF, 0xFE3BDEE3, 0xF94BF958, 0xE09BE68B, 0x4E03C879, 0x110C030A, 0x5E421806,
    0x816F9270, 0x2FE561E7, 0x7B1A2FE5, 0x1FC77BDC, 0xFC5BC0DF, 0x5F2D6F87, 0x1FF57FFD,
    0xE07AA37C, 0xAF83D51B, 0x0FFABFFE, 0x16B7C3FE, 0xFFD10780, 0xF175EFFB, 0xEA9EF71F,
    0x34BF1D1F, 0x60F3C996, 0x43C8FCC6, 0x85277EFC, 0x8441D7C1, 0x9083C661, 0x6E3F7E37,
    0x17EFACF2, 0xCF9D0F3C, 0x44D17F23, 0xF8EF73CC, 0xF7FFBAA3, 0xFFF901DF, 0x01677900,
    0x7DC41772, 0x0001B9E0, 0x00000000, 0x44000000, 0xA11FE1FC, 0x9B33C3E7, 0x9CE73BF9,
    0xFFF904DF, 0x01F5BF00, 0x3EE20FDE, 0x0000DCF0, 0x00000000, 0x22000000, 0xD08FF0FE,
    0xCD99E1F3, 0xCE739DFC, 0xFFF9826F, 0x47B7D402, 0xBEF1DA83, 0xB9E07DC4, 0x00000001,
    0x00000000, 0xE1FC4400, 0xC3E7A11F, 0x3BF99B33, 0x44DF9CE7, 0x01F7C79C, 0xDF1E7100,
    0x9E07DC47, 0x0000001B, 0x00000000, 0x1FC44000, 0x3E7A11FE, 0xBF99B33C, 0x4DF9CE73,
    0xF00FFF90, 0xFDE01F5B, 0x3AC24FA0, 0xBC43F5E3, 0xE4CF446B, 0x72D1CCD5, 0xC67E81BE,
    0xBAA82C6F, 0xD47781B3, 0x000DA403, 0x5DC00000, 0xF7BE8000, 0x7BDF497C, 0x62F880ED,
    0xB17C4001, 0x0ED7BDF4, 0x12F9EF7D, 0xBFF98000, 0xFB78C1FB, 0x37E4BF7E, 0xB116331E,
    0x4FD01618, 0xC40BA882, 0x77338038, 0x203EDC80, 0xEC4782BE, 0xC6E73881, 0xE41FFF21,
    0x0BB9059D, 0xE5FFBFFD, 0xEF3DEE7D, 0x73C69DEC, 0x5BDFFDE3, 0x96F73ABE, 0x76A037E7,
    0xF75E3558, 0xFFC89ADC, 0xC1F5BF07, 0xF7FFA1FB, 0xBDCFBCBF, 0xD3BD9DE7, 0xFFBC6E78,
    0xE757CB7B, 0x06FCF2DE, 0xC6AB0ED4, 0x935B9EEB, 0xFA82FFF9, 0xC76A68F6, 0xFBFFD2FB,
    0xDEE7DE5F, 0x69DECEF3, 0xFFDE373C, 0x73ABE5BD, 0x037E796F, 0xE355876A, 0x09ADCF75,
    0x9BEBCEB0, 0x4C4FBBDE, 0xA3F39E27, 0xBCBFF7FF, 0x9DE7BDCF, 0x6E78D3BD, 0xCB7BFFBC,
    0xF2DEE757, 0x0ED406FC, 0x9EEBC6AB, 0xE3CE335B, 0x3CE200FB, 0xDFFE8FBE, 0xF73EF2FF,
    0x4EF6779E, 0xFEF1B9E3, 0x9D5F2DEF, 0x1BF3CB7B, 0x1AAC3B50, 0x4D6E7BAF, 0x318BDFBE,
    0xE318237E, 0xEFDF0237, 0x7FEFFF45, 0xCF7B9F79, 0xF1A77B3B, 0xF7FF78DC, 0xBDCEAF96,
    0xA80DF9E5, 0xD78D561D, 0xF8A6B73D, 0xE33FFDCE, 0x7C1BCF77, 0xFDFBEFB1, 0xC7E6F7FF,
    0x9ACAA5F7, 0xBF1856E2, 0xF73E6F73, 0x63749FDE, 0xDEEB9BDF, 0xBC88EF7B, 0xFE220289,
    0x187647A2, 0x37B9FFCD, 0x7BDC7FF7, 0xFB9EF12F, 0xEF79FE2B, 0x1BC6B2FE, 0xE2437E56,
    0x251102FF, 0x6F51ADF1, 0xF2F8F558, 0xF14FFDDE, 0x6E01C89E, 0x90ABB815, 0x9DE40FFF,
    0xF4177205, 0x97E2BFB9, 0x472FEEF7, 0x5F1AC2FD, 0x0CDEF739, 0xF7BDEF71, 0x8D40311D,
    0xEC3D8C3B, 0x6FEF7FE7, 0xF03FFE40, 0x3F781F5B, 0xC57F73E8, 0x5FDDEF2F, 0x3585FA8E,
    0xBDEE72BE, 0x7BDEE219, 0x80623BEF, 0x7B18771A, 0xDEFFCFD8, 0x7FFCC0DF, 0x68F6FA81,
    0x45F78ED4, 0x7E2BFB9F, 0x72FEEF79, 0xF1AC2FD4, 0xCDEF7395, 0x7BDEF710, 0xD40311DF,
    0xC3D8C3B8, 0xFEF7FE7E, 0xEF8F3886, 0xE3CE2003, 0xFEE7D0FB, 0xBBDE5F8A, 0x0BF51CBF,
    0xDCE57C6B, 0xBDC4337B, 0xC477DEF7, 0x30EE3500, 0xFF9FB0F6, 0xFF91BFBD, 0x7259DE4F,
    0x0017BF17, 0xFFF20000, 0xFBCFADF9, 0x00017BF1, 0xFFF30000, 0x747B7D45, 0x7E5F78ED,
    0x0000002F, 0x7C79C400, 0xF1E7101F, 0x005EFC7D, 0x00000000, 0x0469BF60, 0x777F67DE,
    0x12AAB9E0, 0x055BFFFA, 0x8B8CF1BF, 0x3C7FDFFE, 0x5EEE73F4, 0x886FE611, 0x160F1197,
    0x0C8C1E23, 0x6DEA57F3, 0xFF6F7BFA, 0xBCEB001E, 0xFBBDE9BE, 0x39E274C4, 0xCFB7FF3F,
    0x3FF585F9, 0x23D6BE7B, 0x000080AB, 0xFFF20000, 0x01677901, 0xFFAC0BB9, 0xDFBC2FFD,
    0xC57BE7B9, 0x8CF461EC, 0x807942C7, 0x796163C1, 0x7A30F662, 0xF73BF786, 0xFFC82F7C,
    0x07D6FC07, 0xFF581FBC, 0xBF785FFB, 0x8AF7CF73, 0x19E8C3D9, 0x00F2858F, 0xF2C2C783,
    0xF461ECC4, 0xEE77EF0C, 0xFF985EF9, 0x3DBEA02F, 0xFBC76A1A, 0xFFDFFAC2, 0x7B9DFBC2,
    0x1ECC57BE, 0x2C78CF46, 0x3C180794, 0x66279616, 0x7867A30F, 0xF7CF73BF, 0xAF3AC002,
    0xFBBDE26F, 0xE789C4C4, 0xEFFD60FC, 0xCEFDE17F, 0x662BDF3D, 0x3C67A30F, 0x0C03CA16,
    0x13CB0B1E, 0x33D187B3, 0xE7B9DFBC, 0xF8F3897B, 0xF388003E, 0xFF583EF8, 0xBF785FFB,
    0x8AF7CF73, 0x19E8C3D9, 0x00F2858F, 0xF2C2C783, 0xF461ECC4, 0xEE77EF0C, 0x33A85EF9,
    0x06750000, 0xEF7BAC00, 0x758EF7BD, 0xDEF7BDEF, 0x06750001, 0x626B0000, 0x5BFFEFFD,
    0x8D6E77F4, 0x3E47B316, 0xCB1999BF, 0x990B2DEF, 0xAFAA320F, 0xB3D98AC7, 0x8F533BC6,
    0x197BE7B8, 0x85FFBFF5, 0x77907FFC, 0xFE2EE416, 0x001FDE2F, 0xF0040000, 0xD7A5AA54,
    0xFF20A73E, 0x07D6FC1F, 0xC5FFC7EF, 0x000003FB, 0x4A9E0080, 0xE7DAF4B5, 0x0BFFE614,
    0xA9A3DBEA, 0xFFEBEF1D, 0x0001FDE2, 0x4F004000, 0xED7A5AA5, 0xC79C4A73, 0x79C401F7,
    0x8BFF9F7C, 0x000007F7, 0x953C0100, 0xCFB5E96A, 0x07FFC829, 0xEF03EB7E, 0xB8937987,
    0x8AC3C673, 0x2FF8FD69, 0xFD6463FE, 0x593DFCA9, 0x07DF9EF8, 0x5103C733, 0xC1FD6095,
    0xDF38898C, 0x0000BB81, 0x77E70000, 0xF3EA8BCE, 0xA86F97AD, 0x09150177, 0xFA446016,
    0xD5277A86, 0xF9CD5BE7, 0x0002F39D, 0xFBE3CE20, 0xF8F38800, 0x7126F33E, 0x15878CE7,
    0x5FF1FAD3, 0xFAC8C7FC, 0xB27BF953, 0x0FBF3DF0, 0xA2078E66, 0x83FAC12A, 0xBE711319,
    0x00000003

  EW_FONT_KERNING_CODES( CutterCaptionFont )
  EW_FONT_KERNING_VALUES( CutterCaptionFont )
EW_END_OF_FONT_RES( CutterCaptionFont )

/* Embedded Wizard */