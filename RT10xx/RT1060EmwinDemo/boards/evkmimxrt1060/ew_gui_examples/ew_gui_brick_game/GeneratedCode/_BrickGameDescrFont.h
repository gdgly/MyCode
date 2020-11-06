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

/* Font resource : 'BrickGame::DescrFont' */
EW_DEFINE_FONT_RES( BrickGameDescrFont, 13, 3, 0, 16, 0x0001, 0x00C0 )
  EW_GLYPH( 0x0001, 1, -9, 8, 9, 8, 0x00000000 ),
  EW_GLYPH( 0x0020, 0, 0, 0, 0, 8, 0x000000D0 ),                /* ' ' */
  EW_GLYPH( 0x0021, 3, -10, 3, 10, 8, 0x000000D0 ),             /* '!' */
  EW_GLYPH( 0x0022, 0, -10, 7, 3, 8, 0x0000012B ),              /* '"' */
  EW_GLYPH( 0x0023, 0, -9, 7, 9, 8, 0x00000172 ),               /* '#' */
  EW_GLYPH( 0x0024, 1, -10, 7, 12, 8, 0x0000025C ),             /* '$' */
  EW_GLYPH( 0x0025, 0, -10, 9, 10, 8, 0x00000395 ),             /* '%' */
  EW_GLYPH( 0x0026, 0, -10, 8, 10, 8, 0x000004ED ),             /* '&' */
  EW_GLYPH( 0x0027, 3, -10, 3, 3, 8, 0x0000061D ),              /* ''' */
  EW_GLYPH( 0x0028, 1, -10, 5, 13, 8, 0x0000063F ),             /* '(' */
  EW_GLYPH( 0x0029, 1, -10, 5, 13, 8, 0x00000712 ),             /* ')' */
  EW_GLYPH( 0x002A, 2, -10, 6, 6, 8, 0x000007E7 ),              /* '*' */
  EW_GLYPH( 0x002B, 0, -7, 8, 7, 8, 0x0000087A ),               /* '+' */
  EW_GLYPH( 0x002C, 2, -2, 4, 4, 8, 0x000008F9 ),               /* ',' */
  EW_GLYPH( 0x002D, 2, -4, 4, 1, 8, 0x0000093A ),               /* '-' */
  EW_GLYPH( 0x002E, 3, -2, 3, 2, 8, 0x0000094E ),               /* '.' */
  EW_GLYPH( 0x002F, 1, -10, 7, 11, 8, 0x00000961 ),             /* '/' */
  EW_GLYPH( 0x0030, 1, -9, 7, 9, 8, 0x00000A1B ),               /* '0' */
  EW_GLYPH( 0x0031, 2, -9, 5, 9, 8, 0x00000B14 ),               /* '1' */
  EW_GLYPH( 0x0032, 1, -9, 6, 9, 8, 0x00000B72 ),               /* '2' */
  EW_GLYPH( 0x0033, 1, -9, 6, 9, 8, 0x00000C50 ),               /* '3' */
  EW_GLYPH( 0x0034, 0, -9, 7, 9, 8, 0x00000D18 ),               /* '4' */
  EW_GLYPH( 0x0035, 1, -9, 6, 9, 8, 0x00000DC1 ),               /* '5' */
  EW_GLYPH( 0x0036, 1, -9, 7, 9, 8, 0x00000E75 ),               /* '6' */
  EW_GLYPH( 0x0037, 1, -9, 6, 9, 8, 0x00000F75 ),               /* '7' */
  EW_GLYPH( 0x0038, 1, -9, 7, 9, 8, 0x00001025 ),               /* '8' */
  EW_GLYPH( 0x0039, 1, -9, 7, 9, 8, 0x00001150 ),               /* '9' */
  EW_GLYPH( 0x003A, 3, -7, 3, 7, 8, 0x0000124D ),               /* ':' */
  EW_GLYPH( 0x003B, 2, -7, 4, 9, 8, 0x0000128C ),               /* ';' */
  EW_GLYPH( 0x003C, 1, -8, 5, 8, 8, 0x000012FD ),               /* '<' */
  EW_GLYPH( 0x003D, 1, -5, 6, 3, 8, 0x0000138D ),               /* '=' */
  EW_GLYPH( 0x003E, 1, -8, 5, 8, 8, 0x000013E7 ),               /* '>' */
  EW_GLYPH( 0x003F, 2, -10, 5, 10, 8, 0x00001478 ),             /* '?' */
  EW_GLYPH( 0x0040, 0, -10, 9, 13, 8, 0x0000152A ),             /* '@' */
  EW_GLYPH( 0x0041, -1, -9, 9, 9, 8, 0x000016E1 ),              /* 'A' */
  EW_GLYPH( 0x0042, 1, -9, 7, 9, 8, 0x000017DC ),               /* 'B' */
  EW_GLYPH( 0x0043, 1, -9, 6, 9, 8, 0x000018B9 ),               /* 'C' */
  EW_GLYPH( 0x0044, 1, -9, 7, 9, 8, 0x00001972 ),               /* 'D' */
  EW_GLYPH( 0x0045, 1, -9, 5, 9, 8, 0x00001A23 ),               /* 'E' */
  EW_GLYPH( 0x0046, 1, -9, 5, 9, 8, 0x00001AA4 ),               /* 'F' */
  EW_GLYPH( 0x0047, 0, -9, 7, 9, 8, 0x00001B16 ),               /* 'G' */
  EW_GLYPH( 0x0048, 1, -9, 6, 9, 8, 0x00001C06 ),               /* 'H' */
  EW_GLYPH( 0x0049, 1, -9, 6, 9, 8, 0x00001C6C ),               /* 'I' */
  EW_GLYPH( 0x004A, 1, -9, 6, 9, 8, 0x00001CE6 ),               /* 'J' */
  EW_GLYPH( 0x004B, 1, -9, 7, 9, 8, 0x00001D75 ),               /* 'K' */
  EW_GLYPH( 0x004C, 2, -9, 5, 9, 8, 0x00001E37 ),               /* 'L' */
  EW_GLYPH( 0x004D, 0, -9, 8, 9, 8, 0x00001E7D ),               /* 'M' */
  EW_GLYPH( 0x004E, 1, -9, 6, 9, 8, 0x00001F63 ),               /* 'N' */
  EW_GLYPH( 0x004F, 0, -9, 7, 9, 8, 0x00001FDF ),               /* 'O' */
  EW_GLYPH( 0x0050, 1, -9, 7, 9, 8, 0x000020CE ),               /* 'P' */
  EW_GLYPH( 0x0051, 0, -9, 8, 11, 8, 0x0000217F ),              /* 'Q' */
  EW_GLYPH( 0x0052, 1, -9, 7, 9, 8, 0x000022B7 ),               /* 'R' */
  EW_GLYPH( 0x0053, 1, -9, 7, 9, 8, 0x00002374 ),               /* 'S' */
  EW_GLYPH( 0x0054, 0, -9, 8, 9, 8, 0x0000246D ),               /* 'T' */
  EW_GLYPH( 0x0055, 1, -9, 7, 9, 8, 0x000024F4 ),               /* 'U' */
  EW_GLYPH( 0x0056, 0, -9, 9, 9, 8, 0x00002589 ),               /* 'V' */
  EW_GLYPH( 0x0057, 1, -9, 7, 9, 8, 0x0000267C ),               /* 'W' */
  EW_GLYPH( 0x0058, 0, -9, 8, 9, 8, 0x00002754 ),               /* 'X' */
  EW_GLYPH( 0x0059, 0, -9, 8, 9, 8, 0x0000285A ),               /* 'Y' */
  EW_GLYPH( 0x005A, 1, -9, 6, 9, 8, 0x0000292C ),               /* 'Z' */
  EW_GLYPH( 0x005B, 2, -10, 4, 13, 8, 0x000029E2 ),             /* '[' */
  EW_GLYPH( 0x005C, 1, -10, 7, 11, 8, 0x00002A37 ),             /* '\' */
  EW_GLYPH( 0x005D, 2, -10, 4, 13, 8, 0x00002AF2 ),             /* ']' */
  EW_GLYPH( 0x005E, 0, -9, 7, 4, 8, 0x00002B48 ),               /* '^' */
  EW_GLYPH( 0x005F, 0, 2, 8, 1, 8, 0x00002BA6 ),                /* '_' */
  EW_GLYPH( 0x0060, 1, -10, 4, 2, 8, 0x00002BCE ),              /* '`' */
  EW_GLYPH( 0x0061, 1, -7, 6, 7, 8, 0x00002BF0 ),               /* 'a' */
  EW_GLYPH( 0x0062, 1, -10, 7, 10, 8, 0x00002C97 ),             /* 'b' */
  EW_GLYPH( 0x0063, 1, -7, 5, 7, 8, 0x00002D51 ),               /* 'c' */
  EW_GLYPH( 0x0064, 1, -10, 7, 10, 8, 0x00002DD4 ),             /* 'd' */
  EW_GLYPH( 0x0065, 1, -7, 7, 7, 8, 0x00002E9C ),               /* 'e' */
  EW_GLYPH( 0x0066, 1, -10, 6, 10, 8, 0x00002F6D ),             /* 'f' */
  EW_GLYPH( 0x0067, 1, -7, 7, 10, 8, 0x00002FEF ),              /* 'g' */
  EW_GLYPH( 0x0068, 1, -10, 6, 10, 8, 0x00003125 ),             /* 'h' */
  EW_GLYPH( 0x0069, 1, -10, 6, 10, 8, 0x000031A9 ),             /* 'i' */
  EW_GLYPH( 0x006A, 1, -10, 5, 13, 8, 0x0000322E ),             /* 'j' */
  EW_GLYPH( 0x006B, 1, -10, 7, 10, 8, 0x000032D5 ),             /* 'k' */
  EW_GLYPH( 0x006C, 1, -10, 6, 10, 8, 0x00003384 ),             /* 'l' */
  EW_GLYPH( 0x006D, 0, -7, 8, 7, 8, 0x000033ED ),               /* 'm' */
  EW_GLYPH( 0x006E, 1, -7, 6, 7, 8, 0x00003476 ),               /* 'n' */
  EW_GLYPH( 0x006F, 1, -7, 7, 7, 8, 0x000034DE ),               /* 'o' */
  EW_GLYPH( 0x0070, 1, -7, 7, 10, 8, 0x0000359E ),              /* 'p' */
  EW_GLYPH( 0x0071, 1, -7, 7, 10, 8, 0x00003669 ),              /* 'q' */
  EW_GLYPH( 0x0072, 1, -7, 6, 7, 8, 0x00003744 ),               /* 'r' */
  EW_GLYPH( 0x0073, 1, -7, 6, 7, 8, 0x000037B4 ),               /* 's' */
  EW_GLYPH( 0x0074, 0, -9, 6, 9, 8, 0x00003858 ),               /* 't' */
  EW_GLYPH( 0x0075, 1, -7, 6, 7, 8, 0x000038DF ),               /* 'u' */
  EW_GLYPH( 0x0076, 1, -7, 7, 7, 8, 0x0000393F ),               /* 'v' */
  EW_GLYPH( 0x0077, -1, -7, 9, 7, 8, 0x000039DC ),              /* 'w' */
  EW_GLYPH( 0x0078, 0, -7, 8, 7, 8, 0x00003AD1 ),               /* 'x' */
  EW_GLYPH( 0x0079, 1, -7, 7, 10, 8, 0x00003BA1 ),              /* 'y' */
  EW_GLYPH( 0x007A, 1, -7, 5, 7, 8, 0x00003C82 ),               /* 'z' */
  EW_GLYPH( 0x007B, 1, -10, 5, 13, 8, 0x00003D10 ),             /* '{' */
  EW_GLYPH( 0x007C, 3, -11, 2, 14, 8, 0x00003DB3 ),             /* '|' */
  EW_GLYPH( 0x007D, 2, -10, 5, 13, 8, 0x00003DD8 ),             /* '}' */
  EW_GLYPH( 0x007E, 0, -5, 8, 3, 8, 0x00003E7D ),               /* '~' */
  EW_GLYPH( 0x00A0, 0, 0, 0, 0, 8, 0x00003EF1 ),
  EW_GLYPH( 0x00A1, 3, -7, 3, 10, 8, 0x00003EF1 ),
  EW_GLYPH( 0x00A2, 1, -10, 5, 12, 8, 0x00003F54 ),
  EW_GLYPH( 0x00A3, 1, -9, 6, 9, 8, 0x00004021 ),
  EW_GLYPH( 0x00A4, 1, -8, 7, 7, 8, 0x000040CE ),
  EW_GLYPH( 0x00A5, 0, -9, 8, 9, 8, 0x0000418F ),
  EW_GLYPH( 0x00A6, 3, -11, 2, 14, 8, 0x0000428F ),
  EW_GLYPH( 0x00A7, 1, -10, 7, 12, 8, 0x000042C6 ),
  EW_GLYPH( 0x00A8, 2, -9, 6, 1, 8, 0x0000440A ),
  EW_GLYPH( 0x00A9, 0, -9, 8, 9, 8, 0x00004428 ),
  EW_GLYPH( 0x00AA, 1, -9, 6, 7, 8, 0x00004549 ),
  EW_GLYPH( 0x00AB, 1, -7, 8, 6, 8, 0x00004610 ),
  EW_GLYPH( 0x00AC, 1, -4, 6, 3, 8, 0x000046AD ),
  EW_GLYPH( 0x00AD, 2, -4, 4, 1, 8, 0x000046EA ),
  EW_GLYPH( 0x00AE, 0, -10, 8, 6, 8, 0x000046FE ),
  EW_GLYPH( 0x00AF, 2, -10, 4, 1, 8, 0x000047D2 ),
  EW_GLYPH( 0x00B0, 1, -10, 7, 5, 8, 0x000047E6 ),
  EW_GLYPH( 0x00B1, 0, -8, 8, 8, 8, 0x00004882 ),
  EW_GLYPH( 0x00B2, 2, -10, 4, 5, 8, 0x00004932 ),
  EW_GLYPH( 0x00B3, 2, -10, 5, 5, 8, 0x00004997 ),
  EW_GLYPH( 0x00B4, 3, -10, 5, 2, 8, 0x00004A06 ),
  EW_GLYPH( 0x00B5, 1, -7, 7, 10, 8, 0x00004A2D ),
  EW_GLYPH( 0x00B6, 1, -10, 6, 12, 8, 0x00004AC0 ),
  EW_GLYPH( 0x00B7, 3, -5, 3, 2, 8, 0x00004B7F ),
  EW_GLYPH( 0x00B8, 2, 0, 3, 2, 8, 0x00004B92 ),
  EW_GLYPH( 0x00B9, 1, -10, 5, 5, 8, 0x00004BB0 ),
  EW_GLYPH( 0x00BA, 1, -9, 6, 7, 8, 0x00004C04 ),
  EW_GLYPH( 0x00BB, -1, -6, 8, 5, 8, 0x00004CC3 ),
  EW_GLYPH( 0x00BC, 0, -10, 8, 10, 8, 0x00004D5C ),
  EW_GLYPH( 0x00BD, 0, -10, 8, 10, 8, 0x00004E69 ),
  EW_GLYPH( 0x00BE, 0, -10, 8, 10, 8, 0x00004F7A ),
  EW_GLYPH( 0x00BF, 1, -7, 5, 10, 8, 0x000050A4 ),
  EW_GLYPH( 0x00C0, -1, -12, 9, 12, 8, 0x0000515A ),
  EW_GLYPH( 0x00C1, -1, -12, 9, 12, 8, 0x00005294 ),
  EW_GLYPH( 0x00C2, -1, -12, 9, 12, 8, 0x000053CD ),
  EW_GLYPH( 0x00C3, -1, -12, 9, 12, 8, 0x00005517 ),
  EW_GLYPH( 0x00C4, -1, -11, 9, 11, 8, 0x00005659 ),
  EW_GLYPH( 0x00C5, -1, -12, 9, 12, 8, 0x00005792 ),
  EW_GLYPH( 0x00C6, -1, -9, 8, 9, 8, 0x000058E7 ),
  EW_GLYPH( 0x00C7, 1, -9, 6, 11, 8, 0x000059C9 ),
  EW_GLYPH( 0x00C8, 1, -12, 5, 12, 8, 0x00005AA6 ),
  EW_GLYPH( 0x00C9, 1, -12, 6, 12, 8, 0x00005B5A ),
  EW_GLYPH( 0x00CA, 1, -12, 5, 12, 8, 0x00005C19 ),
  EW_GLYPH( 0x00CB, 1, -11, 6, 11, 8, 0x00005CDD ),
  EW_GLYPH( 0x00CC, 1, -12, 6, 12, 8, 0x00005D9F ),
  EW_GLYPH( 0x00CD, 1, -12, 6, 12, 8, 0x00005E4F ),
  EW_GLYPH( 0x00CE, 1, -12, 6, 12, 8, 0x00005EFE ),
  EW_GLYPH( 0x00CF, 1, -11, 6, 11, 8, 0x00005FBE ),
  EW_GLYPH( 0x00D0, 0, -9, 8, 9, 8, 0x00006070 ),
  EW_GLYPH( 0x00D1, 1, -12, 6, 12, 8, 0x00006147 ),
  EW_GLYPH( 0x00D2, 0, -12, 7, 12, 8, 0x00006201 ),
  EW_GLYPH( 0x00D3, 0, -12, 7, 12, 8, 0x00006329 ),
  EW_GLYPH( 0x00D4, 0, -12, 7, 12, 8, 0x00006450 ),
  EW_GLYPH( 0x00D5, 0, -12, 7, 12, 8, 0x00006588 ),
  EW_GLYPH( 0x00D6, 0, -11, 7, 11, 8, 0x000066B8 ),
  EW_GLYPH( 0x00D7, 0, -7, 7, 7, 8, 0x000067E1 ),
  EW_GLYPH( 0x00D8, 0, -10, 8, 11, 8, 0x000068C1 ),
  EW_GLYPH( 0x00D9, 1, -12, 7, 12, 8, 0x00006A0A ),
  EW_GLYPH( 0x00DA, 1, -12, 7, 12, 8, 0x00006AD8 ),
  EW_GLYPH( 0x00DB, 1, -12, 7, 12, 8, 0x00006BA5 ),
  EW_GLYPH( 0x00DC, 1, -11, 7, 11, 8, 0x00006C83 ),
  EW_GLYPH( 0x00DD, 0, -12, 8, 12, 8, 0x00006D52 ),
  EW_GLYPH( 0x00DE, 1, -9, 7, 9, 8, 0x00006E5F ),
  EW_GLYPH( 0x00DF, 1, -10, 7, 10, 8, 0x00006F1E ),
  EW_GLYPH( 0x00E0, 1, -10, 6, 10, 8, 0x00006FF7 ),
  EW_GLYPH( 0x00E1, 1, -10, 7, 10, 8, 0x000070D4 ),
  EW_GLYPH( 0x00E2, 1, -10, 6, 10, 8, 0x000071C0 ),
  EW_GLYPH( 0x00E3, 1, -10, 6, 10, 8, 0x000072AE ),
  EW_GLYPH( 0x00E4, 1, -9, 7, 9, 8, 0x00007393 ),
  EW_GLYPH( 0x00E5, 1, -11, 6, 11, 8, 0x0000747F ),
  EW_GLYPH( 0x00E6, 0, -7, 7, 7, 8, 0x0000758A ),
  EW_GLYPH( 0x00E7, 1, -7, 5, 9, 8, 0x0000766C ),
  EW_GLYPH( 0x00E8, 1, -10, 7, 10, 8, 0x00007718 ),
  EW_GLYPH( 0x00E9, 1, -10, 7, 10, 8, 0x00007822 ),
  EW_GLYPH( 0x00EA, 1, -10, 7, 10, 8, 0x00007931 ),
  EW_GLYPH( 0x00EB, 1, -9, 7, 9, 8, 0x00007A4C ),
  EW_GLYPH( 0x00EC, 1, -10, 6, 10, 8, 0x00007B5B ),
  EW_GLYPH( 0x00ED, 1, -10, 7, 10, 8, 0x00007BE8 ),
  EW_GLYPH( 0x00EE, 1, -10, 6, 10, 8, 0x00007C84 ),
  EW_GLYPH( 0x00EF, 1, -9, 7, 9, 8, 0x00007D22 ),
  EW_GLYPH( 0x00F0, 1, -10, 7, 10, 8, 0x00007DBE ),
  EW_GLYPH( 0x00F1, 1, -10, 6, 10, 8, 0x00007ED3 ),
  EW_GLYPH( 0x00F2, 1, -10, 7, 10, 8, 0x00007F79 ),
  EW_GLYPH( 0x00F3, 1, -10, 7, 10, 8, 0x00008072 ),
  EW_GLYPH( 0x00F4, 1, -10, 7, 10, 8, 0x00008170 ),
  EW_GLYPH( 0x00F5, 1, -10, 7, 10, 8, 0x0000827A ),
  EW_GLYPH( 0x00F6, 1, -9, 7, 9, 8, 0x0000837B ),
  EW_GLYPH( 0x00F7, 1, -7, 7, 7, 8, 0x00008479 ),
  EW_GLYPH( 0x00F8, 1, -8, 7, 9, 8, 0x0000850F ),
  EW_GLYPH( 0x00F9, 1, -10, 6, 10, 8, 0x0000860C ),
  EW_GLYPH( 0x00FA, 1, -10, 7, 10, 8, 0x000086A2 ),
  EW_GLYPH( 0x00FB, 1, -10, 6, 10, 8, 0x00008747 ),
  EW_GLYPH( 0x00FC, 1, -9, 7, 9, 8, 0x000087EE ),
  EW_GLYPH( 0x00FD, 1, -10, 7, 13, 8, 0x00008893 ),
  EW_GLYPH( 0x00FE, 1, -10, 7, 13, 8, 0x000089B2 ),
  EW_GLYPH( 0x00FF, 1, -9, 7, 12, 8, 0x00008A96 ),

  EW_FONT_PIXEL( BrickGameDescrFont, 0x00008BB5 )               /* ratio 80.19 % */
    0xEF7BDEF7, 0xF7BDF61D, 0x80FFEFC2, 0x3A03F7DF, 0xBD81BB81, 0xDF60BD80, 0x2FF72F7B,
    0x198058C2, 0xEFD7BF0C, 0x9C7B881F, 0x4218611B, 0x9F71334E, 0x3E6690F7, 0xBAAEDFEE,
    0xEBAC75F7, 0x15DC70C4, 0x55BDEF7F, 0x18CD7D9F, 0x808E3192, 0x6FEF45E7, 0xCFBCDF5E,
    0xE631AAEF, 0x8337CCC3, 0x8AFC65FE, 0xC5BF15BA, 0xC9CD9FD8, 0x7F3BDC69, 0xE6F7DBDF,
    0xFEA013D9, 0x79B517F7, 0xBDF7A9E7, 0xE0D6608C, 0x78D0EEB7, 0x807667FE, 0x6F78139A,
    0xAC2FEFFD, 0xF53CEF1A, 0x7046D7E6, 0xEB7E17FB, 0xF7D8CB3E, 0xF5FEB817, 0x2814AC62,
    0x2FF0FC5F, 0x667EA937, 0xDF9BD7DC, 0xCB90CBF3, 0x67AB72BB, 0xF3DF49F8, 0xEBAFFF3F,
    0x266218DC, 0x9FD597CC, 0xD6F0DFEA, 0xDFCBC9E3, 0xB6080843, 0xBA2F2787, 0x1BF59E1E,
    0x0BBDFBF4, 0xDF8CDBDF, 0x71AA787A, 0x27F1E1F3, 0xCFE50404, 0xAF53C7CD, 0xBDF2EBF1,
    0x9BC3CE0B, 0xBDF1DE23, 0x2088CFA3, 0xE3BE8F74, 0xE0778CCB, 0x700000BF, 0xF7BECDEF,
    0xF755EF77, 0xEC0000FE, 0xA47198F3, 0xDE77ADFF, 0x1677EF7B, 0xFBC1FC60, 0xDF09AC83,
    0xCC2F9884, 0x60FDF015, 0x42EF84CE, 0xF02FB829, 0xEA1EEFFC, 0xB8FF5DFB, 0x9EB17D39,
    0xE86E7C69, 0xBFC544D3, 0x1EE1B478, 0xE9F39BD3, 0xCEA5C6EF, 0x69C1DCDF, 0xC0000034,
    0xDF8EF2BD, 0xF7BC5F39, 0x2BEF9FFC, 0xA2460B23, 0x735CC7E3, 0x9AF3EF9A, 0x7AF1F3EF,
    0x9EF7BDEE, 0x9DEF70DF, 0xF2073107, 0x3FBFDC59, 0x89BFBEF7, 0xF7D962E5, 0xF83DFD9E,
    0xA01E1FDD, 0xE40D561B, 0xC06FD0DB, 0x7BAAF7D3, 0x02EABDEF, 0x32F7BDEE, 0xC000BDEF,
    0xEE37FFBC, 0x98D9BFBD, 0xDEE76892, 0xF447BE3B, 0xC7FC57BE, 0xDF9BD7BD, 0xD39F6540,
    0xBBCFFE46, 0x772CA7A6, 0x28DF882C, 0x7D6B7E2B, 0xDEE37F77, 0xF7BDEF7B, 0x77E0B7DE,
    0x7BF0A331, 0xFEF078F1, 0xFBC4E4F0, 0x3DFFDE22, 0xEF757E5F, 0x2999F75E, 0x63AB78E7,
    0x75DEBD3D, 0xFEECE7BA, 0x58F4FBD7, 0x18C673F9, 0xDFFADE4A, 0xFFD6BD77, 0x73DEB2EE,
    0x19F7CBEB, 0x9D2078BE, 0xEF8B49E7, 0xF110FFD9, 0x46C7FF3B, 0xD3DCA7DD, 0x0677E7DF,
    0xBF00677E, 0x0677E033, 0x60019DF8, 0x238CC79F, 0x13BD6FFD, 0x36DF52F5, 0xEF99F7BF,
    0xE77CC05C, 0x43EF7E62, 0x7BDEF77D, 0xDEF7BDEF, 0xF7BDEF7B, 0xFEE06FDE, 0x26FDE78B,
    0x9813BE6B, 0x7F4F9DF3, 0x7717FDD3, 0x76B7B877, 0x219B3718, 0xBFBDC699, 0xEDFF39D5,
    0x0FF7E2FF, 0x39DF9018, 0xB3FFDC8D, 0x4B5DE69F, 0x1FAAA6FE, 0xB95FEA2A, 0x33C53FCE,
    0x4F2267B2, 0x238C41F9, 0x47831985, 0x8BF3C8C5, 0xF53F7EBB, 0xF3EBF38C, 0x4158B578,
    0x09EE71DC, 0xBF034EB0, 0x13D203DF, 0xFA9FBE03, 0xC2BF29E0, 0x2F830C30, 0xB1F9BDEF,
    0xB7F7BDF6, 0x752818D4, 0x41BF3DEF, 0xC40F3BDD, 0xA2CF901C, 0xA9FC7FEE, 0x84DFBF7B,
    0xD5B2C2E5, 0x8C7BFB3D, 0xFCCFF9DF, 0xC5F8FFBB, 0x2265561B, 0x03278041, 0xFD5617D7,
    0x7BDE7F9C, 0xF7525FFF, 0xC7640EC6, 0x0000C30B, 0xD18FE501, 0x6B7BA963, 0xABDEF7BB,
    0xA800BDEE, 0xDEEAFF7B, 0xDEEA003F, 0x57BDEF7B, 0x50017BDD, 0xBDD4FEF7, 0x7880003F,
    0xD88DFDCF, 0xAFF6FFCF, 0x2BA30EF3, 0xDEEB2407, 0x952EB05F, 0x02FC6F01, 0x8EF71FE3,
    0xBBF1FDFF, 0x7BA80000, 0x00B7BA8B, 0xBDEF7000, 0xBAAF77F7, 0x0000003F, 0xDD57B800,
    0xDEF7BDDF, 0x02F7BDDF, 0xF2000000, 0xFBDECB0D, 0xFEE7DEFE, 0xE881FE78, 0x81BEF813,
    0xFDEB0B15, 0xDE0D5AC1, 0x16F38167, 0xFBCBEFE4, 0x00000003, 0xD7BDD400, 0x1136E9BC,
    0xE67046B3, 0xF8C1BF18, 0x31054FFF, 0x3794C985, 0x48D7A230, 0x20844062, 0xAEFC37B8,
    0x005CF058, 0x836782EC, 0x25427700, 0x1A7FEFB5, 0xEF7EEFDF, 0x9C565AF3, 0x013CF07A,
    0x133C4022, 0x965C9D4F, 0xFBBF79F7, 0xF7BDC6FB, 0x53DD49EC, 0x07F684EF, 0xEA3AF102,
    0xBA95FCDE, 0x000057E7, 0x37E73BE3, 0xFEB9DFE4, 0xB89F8BF1, 0x650656F1, 0x78802024,
    0xEBFF2832, 0x7D573A27, 0x79B9DEEB, 0x80BF99FE, 0x7BEDCEB3, 0xBA8379EF, 0x09286CDF,
    0xBBEEA6D3, 0x00E77516, 0xAFC07CEF, 0xEF158CC1, 0x6FBFDEFF, 0x3DFEF7BD, 0x37E560A3,
    0xEF737EF0, 0x7AF7B3C9, 0x86CFC617, 0xCF7BDC65, 0x7BDEFBAF, 0x7BBFBDEF, 0x07F7BAAF,
    0x00000000, 0x7F700000, 0x00003FB8, 0x40220000, 0xBF2C33D6, 0xDFDFFADF, 0x9C04EA37,
    0xD652852A, 0x3DF17FC1, 0xA318FAC1, 0x8EA0633C, 0x64F7C1FB, 0x9BC6303D, 0x70FA9E09,
    0xC24F787E, 0x2B1135C8, 0x4F332E47, 0x8349CDCC, 0x11E270CC, 0xA66BE553, 0xFEF90FFC,
    0xB9DE7DF0, 0xBCE3F53C, 0xDE306FD5, 0x4C54162F, 0x989A9F70, 0x453AFBF9, 0x7E3AD477,
    0xFEF5E4CF, 0xD9DCF04E, 0x47393931, 0x747EB2BD, 0xA3272FCC, 0x1E83F9BE, 0x0130C263,
    0xBDEF7000, 0xBDEF7FF7, 0xE851E2F5, 0xF249EB17, 0xE2A3746B, 0xF7BDD741, 0xEE5EF7BE,
    0x00000005, 0xDFDEE000, 0x4A0BEE03, 0x3982EF81, 0x303F7C13, 0x17CC4057, 0x4D64137C,
    0x7BDCFEF0, 0x0002F77F, 0x70000000, 0x705B8C2F, 0x673D17DE, 0x37D79CB4, 0xDEF7BDC7,
    0x57DF6F7B, 0xFF9E59AF, 0xFFFF85F9, 0x592B57AB, 0xE6F15EFB, 0x8B118CB9, 0xFBA6E71E,
    0x5C800003, 0x79CB34E7, 0x9659E3D7, 0x1610800D, 0xB89EF8BF, 0xFFAD3FC7, 0xF77FABBD,
    0x0B92637E, 0xF43D4F09, 0xEE0BDDFC, 0xF730000F, 0xBDF7CC3D, 0x823C6F97, 0xA82040B1,
    0x7E1FF327, 0x60F4FFCF, 0x31FFEFFE, 0x5F7EF7DF, 0xFF2CAAFD, 0x592F7BAC, 0x3EFBDEF7,
    0xFB3D03CF, 0xEFB18BDE, 0x6A5CE3A5, 0x755EE006, 0x002EABDD, 0xCEF88000, 0xADF7F7BD,
    0x9ABFD3FB, 0xF19A8E51, 0xADFDC238, 0x34F759E5, 0xDDCFB3CF, 0x9CFFC563, 0xE47843D1,
    0xAEFBDCF7, 0x0000FEF7, 0x58767BE4, 0xCF5E3FFB, 0x00082433, 0x00CEFC00, 0x7B833BF0,
    0x017B8FEF, 0x5EE00000, 0xFCE32F75, 0xEEFCE300, 0x7BDEF7BD, 0x0000000B, 0xEEB3C608,
    0xFEF7AFFD, 0x75800000, 0x5E3BE45F, 0x9F33071C, 0xC26B7CC4, 0xE3784ECA, 0x71FDEF75,
    0x0000002F, 0xAF700000, 0x7DAEF7BA, 0xBDE19F6A, 0x3CF8DDF1, 0x002433C3, 0xEDC00000,
    0xCEB0ECEF, 0x86AABC7F, 0x80000104, 0xB1FBBFF5, 0x8DF5BDFA, 0x97EBCAAF, 0xF1089108,
    0xEBE37954, 0xE5F1DDF5, 0x99A73EED, 0xF1EBBCF7, 0x4006CB2C, 0x7C5F8B08, 0x4FF13DC6,
    0x006FCF75, 0xCF7DCC00, 0xDEFBE6FE, 0x8F1BE23B, 0x08102C60, 0xF3FCC9EA, 0x89A7FE7B,
    0x0005DDDF, 0x3B3AD770, 0x95E3FEBC, 0xFB8B486B, 0x7E300001, 0xDD675EE7, 0x7707897B,
    0xDF95E77D, 0xB878D9E9, 0x62D99EF7, 0x47B8182F, 0xBE8F7BDF, 0x11000017, 0xDEF37E1B,
    0x00FEE3FB, 0x7A720000, 0x87738F43, 0x63D4E0E7, 0x5A954A18, 0x79FF6DDC, 0x9A85989E,
    0x33FDF705, 0x9F37E07F, 0x4393E605, 0x911990DC, 0xE19999F3, 0xCDFBFD89, 0x3C4778C5,
    0xCFCF3927, 0x9BBC39FF, 0xD6BBCBDF, 0x7EFBE2F4, 0x83C4641F, 0xC1BEF738, 0x7CF18CF7,
    0x7CF4D5DE, 0x8F53839F, 0xE5528C61, 0xFAB770F7, 0x40C33CF1, 0x3D6E0FF5, 0x7E224630,
    0x1EFDD62F, 0xFFEF7BDC, 0x4F2F5BDE, 0xFD1FE894, 0xB793950B, 0x7D8CBDEE, 0x01E32EB9,
    0x5FDDB280, 0x26AFEE3D, 0x7C8002E5, 0x2FBDC6F0, 0x77000000, 0x678BAE0F, 0x61EB8000,
    0xE39AEF8E, 0x00055D77, 0x65E3724F, 0xEDC5FFFC, 0x19FFFF8E, 0xF778F5FE, 0xFF7E79FF,
    0xBF1FEFC0, 0x010622D7, 0x83808963, 0xBBCDF418, 0xAFDCF7F2, 0x4479990D, 0x7A47565C,
    0x9F7AEFAD, 0x1189997D, 0x1FFCEFC4, 0xDFF7B3DF, 0x80B464F3, 0xD575EEAB, 0xAAE000BD,
    0xA8FD6F7B, 0xF9FFCC2F, 0x8FF19A86, 0xCBA56A1B, 0xC4AB8F58, 0xFFAC3717, 0x24EF86F9,
    0x9A7E7DCF, 0x19FA27AE, 0xEACCBC73, 0xB2E89BDF, 0x97BCB770, 0xDCBDD57B, 0x5EE5EEAB,
    0x02FBAF75, 0x0BEE5F70, 0xBDCEFC80, 0x25EF759C, 0x7B19E023, 0x773DCDF0, 0xD6F8E67B,
    0xDA53CF9A, 0xE9EBEAFD, 0x6B7ABEFA, 0x903C7B52, 0xDEF7B8F1, 0x7EFEFCFA, 0xE73BF27F,
    0x6BDDB14B, 0xCFBB8F47, 0xF3BD6BA7, 0x9231CAAA, 0x19323991, 0xAE7BF559, 0xF3DF6D55,
    0x5EED8E8D, 0x7F7BEC3B, 0x5F53DF69, 0x5F11CEFE, 0xDCBF3FED, 0xF3FF1A6F, 0xBDEFBFFB,
    0x25FABEF7, 0x8E0CC577, 0xE6F3F19A, 0xE7E33001, 0x833113CD, 0x7BDEE7BF, 0xDEF7BDEF,
    0xAF7BDC02, 0x8379CF78, 0xFC77B8FF, 0xBFFBF18D, 0xE63031BF, 0xB9DF8C60, 0xB8FF863D,
    0x7BDDFC77, 0xFF7FE7AF, 0xDBBF7D4B, 0x8F4DFCFD, 0xFFA63DBD, 0x5F7F7DD3, 0x7000FEE1,
    0xFEF755EF, 0xDEEABDEE, 0xEE00001F, 0x7BDEF70F, 0xF77DFDEF, 0x578EEFAC, 0xE7BE7A8D,
    0xFF9D45F7, 0x737FED3D, 0xEE93C772, 0x7FDCF7AE, 0x9EAFBEB5, 0xB8FEEBDF, 0x0000003F,
    0x3858EA60, 0xF4EA7F3A, 0x00093F3C, 0xDBDEFFD6, 0x00995F9D, 0x819BF028, 0x0003CF78,
    0x4F91D080, 0xBF3F7B39, 0x3B8C2CEF, 0x3BE39CDF, 0xF83FEF3F, 0xEABDC016, 0x3CF9CFA7,
    0xE67FFFEB, 0x8D7B8636, 0xFFF9CF61, 0x4E7BC7AF, 0xF7BDEF7B, 0xFDE0FFAD, 0x3CE93AD4,
    0x9F4C73E9, 0xB57D31CF, 0x593FFA4E, 0x7B6D4BFF, 0xB07ABDE1, 0x8D7E406A, 0xA02FF6F7,
    0xB5EF04E6, 0x78D56BEF, 0xF36BF23F, 0xEE17FB35, 0xA97FEB35, 0x57BC2F6D, 0xC80D560F,
    0xFEDEF1AF, 0xE09CD405, 0xACBEFBBD, 0xF259FB1A, 0xFD3EB36B, 0x38FC6F0B, 0xE70F65F7,
    0xDC33D659, 0xE5EF9F27, 0xCE35F19E, 0xCE707A89, 0xB17F40F8, 0xF59EABEF, 0xBE6BE87E,
    0xAF70D766, 0x0C7FFE49, 0xEF0FFF88, 0xF667FF5F, 0x4C3BDDFA, 0x7797E0D2, 0xD2F75DC8,
    0xCD7A05F7, 0xB016FA02, 0xDFBF034E, 0x0313D203, 0xE0FA9FBE, 0x30C2BF29, 0xEF2F830C,
    0xF6B1F9BD, 0xD4B7F7BD, 0xE3052818, 0x00E3A06E, 0x9D6093BF, 0x07BF7E06, 0x7C0627A4,
    0x53C1F53F, 0x1861857E, 0x7BDE5F06, 0x7BED63F3, 0x31A96FEF, 0xFBFF0A50, 0x164F9507,
    0x816EFDD4, 0xFDF81A75, 0x189E901E, 0x07D4FDF0, 0x8615F94F, 0x797C1861, 0xB58FCDEF,
    0xA5BFBDEF, 0xFA2940C6, 0xBAE0D1BC, 0x0D3DE3A0, 0xF7E069D6, 0x627A407B, 0x1F53F7C0,
    0x1857E53C, 0xE5F06186, 0xD63F37BD, 0x96FEF7BE, 0xF0A5031A, 0xF85EFD7B, 0xAC2F7EBD,
    0xF7EFC0D3, 0x80C4F480, 0x783EA7EF, 0x0C30AFCA, 0x7BCBE0C3, 0x7DAC7E6F, 0x352DFDEF,
    0xBBE14A06, 0xFFCF181F, 0xFF9E3019, 0x123FC033, 0x901EFDF8, 0xFDF0189E, 0xF94F07D4,
    0x18618615, 0xCDEF797C, 0xBDEFB58F, 0x40C6A5BF, 0xEF7BEC29, 0x5EF34C65, 0x1E78177E,
    0x7F798B50, 0x5FDE65CE, 0xD56177D4, 0xCC5DF0BD, 0xF9DF8D7B, 0xFFBBFCCF, 0x561BC5F8,
    0x80412265, 0x17D70327, 0x139CFD56, 0x1DC9EAEA, 0x5E97DF53, 0xEE5BE8B3, 0x7BAAF7BD,
    0xDEEA002F, 0x0FF7BABF, 0x32F7BA80, 0xC1C746EE, 0xEF7BA4EF, 0x17BDD4BD, 0xFF7BA800,
    0x007FBDD4, 0xFCBDEEA0, 0x93E55FEF, 0x75BBF755, 0xDD57BDEF, 0xF750017B, 0x7FBDD5FE,
    0xD7BDD400, 0xFD7BF5EF, 0xDEF7BF5E, 0xEF752F7B, 0xDEEA0005, 0x1FEF753F, 0xAF7BA800,
    0xCD7A2FBE, 0xDEE2DF42, 0x5EEFEF7B, 0x00007F75, 0xAF700000, 0xDDC63FBA, 0x9DF838E8,
    0xF7BDEF74, 0x3FBAAF77, 0x00000000, 0x9FDD57B8, 0xF953FDFF, 0xDDFBA964, 0xF7BDEF72,
    0x3FBAAF77, 0x00000000, 0x9FDD57B8, 0xFAF7EBDF, 0xBDEF7EBD, 0xBDDFDEF7, 0x0000FEEA,
    0x5EE00000, 0xBDEE7F75, 0xF75137FF, 0x6F203B3E, 0x571860BC, 0x22EAB85D, 0x78C3F940,
    0x7DEEA2C7, 0x346F3EB6, 0x3DE3A5D7, 0xBBF0DEED, 0x0173C162, 0x0D9E0BB0, 0x9509DC02,
    0xD7A17DF4, 0xA85BE82C, 0xF8D3FF7D, 0x9F7BF77E, 0xD4E2B2D7, 0x1009E783, 0x7899E201,
    0xBCB2E4EA, 0xDFDDFBCF, 0x86EE3037, 0x93BF038E, 0x69FFBED4, 0xBDFBBF7C, 0x71596BCF,
    0x04F3C1EA, 0x4CF10088, 0x5972753C, 0xEEFDE7DE, 0xEFFC1BEF, 0x164F951F, 0xD45BBF75,
    0x7C69FFBE, 0xCFBDFBBF, 0xEA71596B, 0x8804F3C1, 0x3C4CF100, 0xDE597275, 0xEFEEFDE7,
    0xD1BCFA1B, 0xDE3A2EB8, 0xFFBED4D3, 0xFBBF7C69, 0x596BCFBD, 0xF3C1EA71, 0xF1008804,
    0x72753C4C, 0xFDE7DE59, 0xFC1BEFEE, 0xDF97BF5E, 0x7DAAF7EB, 0x7EF8D3FF, 0xD79F7BF7,
    0x83D4E2B2, 0x011009E7, 0xEA7899E2, 0xCFBCB2E4, 0x37DFDDFB, 0x778C97F2, 0x7CE39BCC,
    0x77BDC671, 0xD41A6F18, 0xC63FC5FB, 0x7C6E7FF7, 0x7EE43FE3, 0xDF6A3721, 0x3CDF18BD,
    0xFC6F6E63, 0x5663BE72, 0x0ECA77C6, 0x53C221EA, 0x29F3CC88, 0xF44733FB, 0xBBC9F398,
    0xF7FF336B, 0xA17DF4DF, 0x5BE82CD7, 0x1FDC3FB8, 0x00000000, 0x19EB2011, 0xFD6FDF96,
    0x8C1BEFEF, 0xC0E3A1BB, 0x87F724EF, 0x000003FB, 0x64022000, 0xFBF2C33D, 0x7DFDFFAD,
    0x51FEFFC3, 0xF75164F9, 0xE1FDC5BB, 0x000000FE, 0x59008800, 0x7EFCB0CF, 0xDF7F7FEB,
    0x5EFD7BF0, 0xEBDFAF7E, 0x007F70FE, 0x44000000, 0x5867AC80, 0xBFF5BF7E, 0xDC606FBF,
    0xF80E3A0D, 0x8277E49D, 0xC98ECEE7, 0x95EA39C9, 0x7E63A3F5, 0xCDF51939, 0x1318F41F,
    0x80000986, 0xDEEA03FB, 0x9E7BA93D, 0x7F5E2277, 0xAF688108, 0x50F737BA, 0x4006FCF7,
    0xF2EEE7BC, 0xD57AFB5B, 0xF1AC1093, 0xE426B783, 0x4EC77093, 0x041F138C, 0xBEDEBBB8,
    0x42CD7A2F, 0x3FF3C2DF, 0x7FFFF0BF, 0x6B256AF5, 0x3CDE2BDF, 0xD1623197, 0xBE84DCE3,
    0x2F7E7A2F, 0xFE783CFA, 0xFFFC17E7, 0x92B4BD5F, 0xBC2BDF6A, 0x88C62E79, 0x26E71E85,
    0xF7E43EEA, 0xEF9E52FC, 0xFCFFCF24, 0xD5FFFFC2, 0x7DAC95AB, 0x5CF378AF, 0x8F4588C6,
    0x379F5373, 0xF1D2EB9A, 0x9FF9E69E, 0xBFFFF85F, 0xB592B57A, 0x9E6F15EF, 0xE8B118CB,
    0xFBF26E71, 0xFDF9FDFB, 0xFF3CFEFD, 0xFFFE0BF3, 0x495A5EAF, 0xDE15EFB5, 0xC463173C,
    0x13738F42, 0xCF18FDDF, 0xF3C619FF, 0xFDDF067F, 0x2FCFFCF0, 0xBD5FFFFC, 0xF7DAC95A,
    0x65CF378A, 0x38F4588C, 0xF3FF3D37, 0xFFF9E77E, 0x6DEA33FF, 0xFE7C8E43, 0x9BF19CD7,
    0x5457BCD7, 0x7FDD6F14, 0xEFFD6BDC, 0xF7BBFD9D, 0x10B92637, 0x9FA1EAB0, 0x8DF1BDDF,
    0x7D6C9EBA, 0x0B35E85F, 0xFFCC16FA, 0xFBE63FFD, 0x5FABEFDE, 0x759FE595, 0xDEEB25EF,
    0x79E7DF7B, 0x7BDF67A0, 0x9E8BEFA1, 0x0F3E8BDF, 0x1FFEFFE6, 0xF7EF7DF3, 0xF2CAAFD5,
    0x92F7BACF, 0xEFBDEF75, 0xB3D03CF3, 0x7DD4BDEF, 0x4BF3DF90, 0x31277CF2, 0x98FFF7FF,
    0xAFBF7BEF, 0x7F96557E, 0xAC97BDD6, 0x9F7DEF7B, 0x7D9E81E7, 0xF7F7E5EF, 0xFBFBF3FB,
    0xFBFF99FD, 0xBDF7CC7F, 0x2ABF57DF, 0xDEEB3FCB, 0xF7BDD64B, 0x40F3CFBE, 0xEAF7BECF,
    0x2CD7A2FB, 0xBDEE2DF4, 0x0005EE3F, 0xD57B8000, 0xA2FBE8BD, 0xCFA2F7E7, 0x87F7BDC3,
    0x0000017B, 0xEEABDC00, 0x7E43EEA5, 0xF9E52FCF, 0xFEF7BA4E, 0x000017B8, 0xF755EE00,
    0xFEFDFDFA, 0x7F7EFEFC, 0xEE1FDEF7, 0x00000005, 0x97BAAF70, 0xCFEFDDF8, 0xFFCBAC8E,
    0xFCC7C5FB, 0xF6F9A6BF, 0xF1BE78ED, 0x0458F698, 0x2A9E7089, 0xBEBD3C6F, 0xF3ECBE3B,
    0x3A5D7346, 0x7F6ED3DE, 0xFE758767, 0x243555E3, 0xFA000008, 0x166BD0BE, 0xFF582DF4,
    0xDFAB1FBB, 0xAAF8DF5B, 0x10897EBC, 0x954F1089, 0xDF5EBE37, 0xEFA25F1D, 0x8BDF9E8B,
    0xFFD60F3E, 0xF7EAC7EE, 0x2ABE37D6, 0x44225FAF, 0xE553C422, 0x77D7AF8D, 0x3EEA97C7,
    0x25F9EFC8, 0x5893BE79, 0xAB1FBBFF, 0xF8DF5BDF, 0x897EBCAA, 0x4F108910, 0x5EBE3795,
    0xF65F1DDF, 0x5D71A379, 0xB1A7BC74, 0x563F77FE, 0xF1BEB7BF, 0x12FD7955, 0x9E211221,
    0xBD7C6F2A, 0xF4BE3BBE, 0xF9FDFBFB, 0xACFEFDFD, 0xD58FDDFF, 0x7C6FADEF, 0x44BF5E55,
    0xA7884488, 0xAF5F1BCA, 0xF92F8EEF, 0xBF0003FD, 0xBDEF707F, 0xEF7B8EF7, 0xFBF077BD,
    0x3F180007, 0xB0EEFFE6, 0xE67B77DE, 0x376BF557, 0x3E691679, 0xF7E79E21, 0x33F5F1BD,
    0xFFC97D76, 0x45F7D2EC, 0x5BE859AF, 0x07F71FDC, 0xD3900000, 0x3B9C7A1B, 0x9E8BEFA0,
    0x0F3E8BDF, 0x01FDC7F7, 0x9C800000, 0xB9C7A0DE, 0xF21F7503, 0xCF297E7B, 0x71FDD277,
    0x0000007F, 0xC7A1BD39, 0xDFDF83B9, 0xEFEFCFEF, 0xDC7F77F7, 0x0000001F, 0x7A0DE9C8,
    0xDF403B9C, 0x17BF3D17, 0x839E1E7D, 0x8C618F53, 0x70F7E552, 0x3CF1FAB7, 0x0FF540C3,
    0x46303D6E, 0xD62F7E22, 0x1FDC1EFD, 0x3AE40000, 0xBBCE59A7, 0x6CB2CF1E, 0xF8B08400,
    0x89CF27C5, 0xF9CE7A7F, 0xDF80000D, 0xEFCFEFDF, 0x1CF7F7EF, 0x630C7A9C, 0x87BF2A94,
    0xE78FD5BB, 0x7FAA0619, 0x3181EB70, 0xB17BF112, 0x0000F7EE

  EW_FONT_KERNING_CODES( BrickGameDescrFont )
  EW_FONT_KERNING_VALUES( BrickGameDescrFont )
EW_END_OF_FONT_RES( BrickGameDescrFont )

/* Embedded Wizard */