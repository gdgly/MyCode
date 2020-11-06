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
EW_DEFINE_FONT_RES( WasherListFontL, 21, 6, 0, 16, 0x0001, 0x00C0 )
  EW_GLYPH( 0x0001, 1, -14, 11, 14, 14, 0x00000000 ),
  EW_GLYPH( 0x0020, 0, 0, 0, 0, 4, 0x000001D4 ),                /* ' ' */
  EW_GLYPH( 0x0021, 1, -15, 4, 15, 6, 0x000001D4 ),             /* '!' */
  EW_GLYPH( 0x0022, 1, -14, 7, 5, 9, 0x00000267 ),              /* '"' */
  EW_GLYPH( 0x0023, 0, -13, 10, 13, 11, 0x000002D0 ),           /* '#' */
  EW_GLYPH( 0x0024, 1, -16, 9, 19, 11, 0x00000471 ),            /* '$' */
  EW_GLYPH( 0x0025, 0, -14, 17, 14, 18, 0x00000667 ),           /* '%' */
  EW_GLYPH( 0x0026, 0, -14, 13, 14, 13, 0x0000091B ),           /* '&' */
  EW_GLYPH( 0x0027, 1, -14, 3, 5, 5, 0x00000B6F ),              /* ''' */
  EW_GLYPH( 0x0028, 1, -15, 5, 19, 7, 0x00000BA1 ),             /* '(' */
  EW_GLYPH( 0x0029, 0, -15, 5, 19, 7, 0x00000CA9 ),             /* ')' */
  EW_GLYPH( 0x002A, 1, -15, 7, 7, 9, 0x00000DA3 ),              /* '*' */
  EW_GLYPH( 0x002B, 0, -12, 10, 11, 11, 0x00000E56 ),           /* '+' */
  EW_GLYPH( 0x002C, 1, -2, 4, 6, 5, 0x00000F27 ),               /* ',' */
  EW_GLYPH( 0x002D, 0, -6, 6, 1, 7, 0x00000F87 ),               /* '-' */
  EW_GLYPH( 0x002E, 1, -3, 3, 3, 5, 0x00000FA6 ),               /* '.' */
  EW_GLYPH( 0x002F, 0, -15, 8, 18, 8, 0x00000FD8 ),             /* '/' */
  EW_GLYPH( 0x0030, 0, -13, 10, 13, 11, 0x0000111A ),           /* '0' */
  EW_GLYPH( 0x0031, 1, -13, 9, 13, 11, 0x000012A2 ),            /* '1' */
  EW_GLYPH( 0x0032, 0, -13, 10, 13, 11, 0x00001366 ),           /* '2' */
  EW_GLYPH( 0x0033, 0, -13, 10, 13, 11, 0x000014DD ),           /* '3' */
  EW_GLYPH( 0x0034, 0, -13, 10, 13, 11, 0x00001682 ),           /* '4' */
  EW_GLYPH( 0x0035, 0, -13, 10, 13, 11, 0x000017B7 ),           /* '5' */
  EW_GLYPH( 0x0036, 1, -13, 9, 13, 11, 0x0000193B ),            /* '6' */
  EW_GLYPH( 0x0037, 0, -13, 10, 13, 11, 0x00001AEC ),           /* '7' */
  EW_GLYPH( 0x0038, 0, -13, 10, 13, 11, 0x00001C29 ),           /* '8' */
  EW_GLYPH( 0x0039, 0, -13, 10, 13, 11, 0x00001DFA ),           /* '9' */
  EW_GLYPH( 0x003A, 1, -11, 3, 11, 5, 0x00001FA7 ),             /* ':' */
  EW_GLYPH( 0x003B, 1, -11, 4, 15, 5, 0x00002025 ),             /* ';' */
  EW_GLYPH( 0x003C, 0, -11, 10, 8, 11, 0x000020DD ),            /* '<' */
  EW_GLYPH( 0x003D, 0, -9, 10, 5, 11, 0x00002201 ),             /* '=' */
  EW_GLYPH( 0x003E, 0, -11, 10, 8, 11, 0x000022B1 ),            /* '>' */
  EW_GLYPH( 0x003F, 0, -14, 8, 14, 9, 0x000023CA ),             /* '?' */
  EW_GLYPH( 0x0040, 1, -13, 16, 16, 18, 0x00002505 ),           /* '@' */
  EW_GLYPH( 0x0041, 0, -14, 12, 14, 12, 0x0000287E ),           /* 'A' */
  EW_GLYPH( 0x0042, 1, -14, 11, 14, 13, 0x00002A58 ),           /* 'B' */
  EW_GLYPH( 0x0043, 1, -14, 11, 14, 12, 0x00002BFB ),           /* 'C' */
  EW_GLYPH( 0x0044, 1, -14, 11, 14, 13, 0x00002DA6 ),           /* 'D' */
  EW_GLYPH( 0x0045, 1, -14, 9, 14, 11, 0x00002F21 ),            /* 'E' */
  EW_GLYPH( 0x0046, 1, -14, 9, 14, 11, 0x00003032 ),            /* 'F' */
  EW_GLYPH( 0x0047, 1, -14, 11, 14, 13, 0x00003127 ),           /* 'G' */
  EW_GLYPH( 0x0048, 1, -14, 11, 14, 14, 0x000032EC ),           /* 'H' */
  EW_GLYPH( 0x0049, 1, -14, 3, 14, 6, 0x000033D4 ),             /* 'I' */
  EW_GLYPH( 0x004A, 0, -14, 9, 14, 10, 0x0000340A ),            /* 'J' */
  EW_GLYPH( 0x004B, 1, -14, 12, 14, 12, 0x000034E2 ),           /* 'K' */
  EW_GLYPH( 0x004C, 1, -14, 9, 14, 10, 0x00003679 ),            /* 'L' */
  EW_GLYPH( 0x004D, 1, -14, 13, 14, 16, 0x00003720 ),           /* 'M' */
  EW_GLYPH( 0x004E, 1, -14, 11, 14, 14, 0x000038DD ),           /* 'N' */
  EW_GLYPH( 0x004F, 1, -14, 12, 14, 14, 0x00003A1F ),           /* 'O' */
  EW_GLYPH( 0x0050, 1, -14, 11, 14, 12, 0x00003C1B ),           /* 'P' */
  EW_GLYPH( 0x0051, 1, -14, 13, 17, 14, 0x00003D72 ),           /* 'Q' */
  EW_GLYPH( 0x0052, 1, -14, 11, 14, 12, 0x00003FE8 ),           /* 'R' */
  EW_GLYPH( 0x0053, 0, -14, 11, 14, 11, 0x00004166 ),           /* 'S' */
  EW_GLYPH( 0x0054, 0, -14, 11, 14, 12, 0x00004342 ),           /* 'T' */
  EW_GLYPH( 0x0055, 1, -14, 11, 14, 14, 0x00004433 ),           /* 'U' */
  EW_GLYPH( 0x0056, 0, -14, 11, 14, 11, 0x0000454E ),           /* 'V' */
  EW_GLYPH( 0x0057, 0, -14, 16, 14, 17, 0x000046F5 ),           /* 'W' */
  EW_GLYPH( 0x0058, 0, -14, 11, 14, 11, 0x0000499C ),           /* 'X' */
  EW_GLYPH( 0x0059, 0, -14, 10, 14, 10, 0x00004B6E ),           /* 'Y' */
  EW_GLYPH( 0x005A, 0, -14, 11, 14, 12, 0x00004CC8 ),           /* 'Z' */
  EW_GLYPH( 0x005B, 2, -15, 4, 18, 7, 0x00004E64 ),             /* '[' */
  EW_GLYPH( 0x005C, 0, -15, 8, 18, 8, 0x00004EDA ),             /* '\' */
  EW_GLYPH( 0x005D, 0, -15, 5, 18, 7, 0x0000501F ),             /* ']' */
  EW_GLYPH( 0x005E, 1, -14, 9, 8, 11, 0x000050AF ),             /* '^' */
  EW_GLYPH( 0x005F, 0, 2, 11, 1, 11, 0x00005194 ),              /* '_' */
  EW_GLYPH( 0x0060, 3, -15, 5, 3, 12, 0x000051CD ),             /* '`' */
  EW_GLYPH( 0x0061, 1, -10, 9, 10, 11, 0x00005208 ),            /* 'a' */
  EW_GLYPH( 0x0062, 1, -15, 10, 15, 12, 0x00005354 ),           /* 'b' */
  EW_GLYPH( 0x0063, 1, -10, 9, 10, 10, 0x000054AC ),            /* 'c' */
  EW_GLYPH( 0x0064, 1, -15, 9, 15, 12, 0x000055BE ),            /* 'd' */
  EW_GLYPH( 0x0065, 1, -10, 9, 10, 11, 0x00005708 ),            /* 'e' */
  EW_GLYPH( 0x0066, 0, -15, 7, 15, 6, 0x00005865 ),             /* 'f' */
  EW_GLYPH( 0x0067, 0, -10, 11, 14, 11, 0x00005933 ),           /* 'g' */
  EW_GLYPH( 0x0068, 1, -15, 9, 15, 12, 0x00005B57 ),            /* 'h' */
  EW_GLYPH( 0x0069, 1, -14, 3, 14, 5, 0x00005C49 ),             /* 'i' */
  EW_GLYPH( 0x006A, -1, -14, 5, 18, 5, 0x00005C97 ),            /* 'j' */
  EW_GLYPH( 0x006B, 1, -15, 10, 15, 11, 0x00005D37 ),           /* 'k' */
  EW_GLYPH( 0x006C, 1, -15, 4, 15, 5, 0x00005E6C ),             /* 'l' */
  EW_GLYPH( 0x006D, 1, -10, 15, 10, 18, 0x00005EC9 ),           /* 'm' */
  EW_GLYPH( 0x006E, 1, -10, 9, 10, 12, 0x00006008 ),            /* 'n' */
  EW_GLYPH( 0x006F, 1, -10, 10, 10, 12, 0x000060C6 ),           /* 'o' */
  EW_GLYPH( 0x0070, 1, -10, 10, 14, 12, 0x00006219 ),           /* 'p' */
  EW_GLYPH( 0x0071, 1, -10, 9, 14, 12, 0x0000637F ),            /* 'q' */
  EW_GLYPH( 0x0072, 1, -10, 7, 10, 7, 0x000064DE ),             /* 'r' */
  EW_GLYPH( 0x0073, 0, -10, 9, 10, 9, 0x00006570 ),             /* 's' */
  EW_GLYPH( 0x0074, 0, -13, 7, 13, 7, 0x000066BB ),             /* 't' */
  EW_GLYPH( 0x0075, 1, -10, 9, 10, 12, 0x00006782 ),            /* 'u' */
  EW_GLYPH( 0x0076, 0, -10, 10, 10, 10, 0x00006834 ),           /* 'v' */
  EW_GLYPH( 0x0077, 0, -10, 15, 10, 15, 0x00006974 ),           /* 'w' */
  EW_GLYPH( 0x0078, 0, -10, 10, 10, 10, 0x00006B47 ),           /* 'x' */
  EW_GLYPH( 0x0079, 0, -10, 10, 14, 10, 0x00006C85 ),           /* 'y' */
  EW_GLYPH( 0x007A, 0, -10, 9, 10, 9, 0x00006E1A ),             /* 'z' */
  EW_GLYPH( 0x007B, 0, -15, 6, 18, 7, 0x00006F30 ),             /* '{' */
  EW_GLYPH( 0x007C, 1, -16, 3, 21, 5, 0x0000703C ),             /* '|' */
  EW_GLYPH( 0x007D, 0, -15, 6, 18, 7, 0x00007085 ),             /* '}' */
  EW_GLYPH( 0x007E, 0, -9, 10, 3, 11, 0x00007182 ),             /* '~' */
  EW_GLYPH( 0x00A0, 0, 0, 0, 0, 4, 0x00007207 ),
  EW_GLYPH( 0x00A1, 1, -10, 4, 14, 6, 0x00007207 ),
  EW_GLYPH( 0x00A2, 1, -14, 9, 15, 11, 0x00007296 ),
  EW_GLYPH( 0x00A3, 1, -13, 9, 13, 11, 0x00007409 ),
  EW_GLYPH( 0x00A4, 0, -12, 10, 10, 11, 0x0000756B ),
  EW_GLYPH( 0x00A5, 0, -13, 10, 13, 11, 0x000076F0 ),
  EW_GLYPH( 0x00A6, 1, -16, 3, 21, 5, 0x0000788C ),
  EW_GLYPH( 0x00A7, 0, -14, 10, 15, 11, 0x000078F3 ),
  EW_GLYPH( 0x00A8, 3, -14, 6, 2, 12, 0x00007AF3 ),
  EW_GLYPH( 0x00A9, 1, -14, 14, 14, 16, 0x00007B1B ),
  EW_GLYPH( 0x00AA, 0, -13, 7, 8, 7, 0x00007DF1 ),
  EW_GLYPH( 0x00AB, 0, -9, 8, 8, 9, 0x00007EBD ),
  EW_GLYPH( 0x00AC, 0, -7, 10, 6, 11, 0x00007FA9 ),
  EW_GLYPH( 0x00AD, 0, -6, 6, 1, 7, 0x0000803B ),
  EW_GLYPH( 0x00AE, 0, -15, 9, 8, 9, 0x0000805A ),
  EW_GLYPH( 0x00AF, 3, -14, 6, 1, 12, 0x00008183 ),
  EW_GLYPH( 0x00B0, 0, -14, 7, 5, 7, 0x000081A3 ),
  EW_GLYPH( 0x00B1, 0, -12, 10, 12, 11, 0x0000822B ),
  EW_GLYPH( 0x00B2, 0, -17, 7, 8, 8, 0x00008337 ),
  EW_GLYPH( 0x00B3, 0, -17, 7, 8, 8, 0x000083FF ),
  EW_GLYPH( 0x00B4, 4, -15, 5, 3, 12, 0x000084E9 ),
  EW_GLYPH( 0x00B5, 1, -10, 9, 15, 12, 0x00008524 ),
  EW_GLYPH( 0x00B6, 0, -14, 10, 16, 12, 0x0000862F ),
  EW_GLYPH( 0x00B7, 1, -9, 3, 3, 5, 0x00008744 ),
  EW_GLYPH( 0x00B8, 4, -1, 4, 6, 12, 0x00008776 ),
  EW_GLYPH( 0x00B9, 1, -17, 4, 8, 8, 0x000087D2 ),
  EW_GLYPH( 0x00BA, 0, -13, 7, 8, 8, 0x00008805 ),
  EW_GLYPH( 0x00BB, 1, -9, 7, 8, 9, 0x000088C9 ),
  EW_GLYPH( 0x00BC, 1, -14, 16, 14, 17, 0x000089B9 ),
  EW_GLYPH( 0x00BD, 1, -14, 15, 14, 17, 0x00008BB6 ),
  EW_GLYPH( 0x00BE, 0, -14, 17, 14, 17, 0x00008DC0 ),
  EW_GLYPH( 0x00BF, 1, -10, 8, 14, 9, 0x00009076 ),
  EW_GLYPH( 0x00C0, 0, -17, 12, 17, 12, 0x0000919D ),
  EW_GLYPH( 0x00C1, 0, -17, 12, 17, 12, 0x000093C7 ),
  EW_GLYPH( 0x00C2, 0, -17, 12, 17, 12, 0x000095F1 ),
  EW_GLYPH( 0x00C3, 0, -17, 12, 17, 12, 0x0000982F ),
  EW_GLYPH( 0x00C4, 0, -17, 12, 17, 12, 0x00009A77 ),
  EW_GLYPH( 0x00C5, 0, -18, 12, 18, 12, 0x00009CB1 ),
  EW_GLYPH( 0x00C6, 0, -14, 17, 14, 18, 0x00009F03 ),
  EW_GLYPH( 0x00C7, 1, -14, 11, 19, 12, 0x0000A136 ),
  EW_GLYPH( 0x00C8, 1, -17, 9, 17, 11, 0x0000A371 ),
  EW_GLYPH( 0x00C9, 1, -17, 9, 17, 11, 0x0000A4C9 ),
  EW_GLYPH( 0x00CA, 1, -17, 9, 17, 11, 0x0000A621 ),
  EW_GLYPH( 0x00CB, 1, -17, 9, 17, 11, 0x0000A78D ),
  EW_GLYPH( 0x00CC, 0, -17, 5, 17, 6, 0x0000A8F5 ),
  EW_GLYPH( 0x00CD, 1, -17, 5, 17, 6, 0x0000A982 ),
  EW_GLYPH( 0x00CE, 0, -17, 6, 17, 6, 0x0000AA0F ),
  EW_GLYPH( 0x00CF, 0, -17, 6, 17, 6, 0x0000AAC1 ),
  EW_GLYPH( 0x00D0, 0, -14, 13, 14, 14, 0x0000AB6F ),
  EW_GLYPH( 0x00D1, 1, -17, 11, 17, 14, 0x0000AD21 ),
  EW_GLYPH( 0x00D2, 1, -17, 12, 17, 14, 0x0000AECE ),
  EW_GLYPH( 0x00D3, 1, -17, 12, 17, 14, 0x0000B11A ),
  EW_GLYPH( 0x00D4, 1, -17, 12, 17, 14, 0x0000B366 ),
  EW_GLYPH( 0x00D5, 1, -17, 12, 17, 14, 0x0000B5C6 ),
  EW_GLYPH( 0x00D6, 1, -17, 12, 17, 14, 0x0000B830 ),
  EW_GLYPH( 0x00D7, 1, -11, 9, 9, 11, 0x0000BA8C ),
  EW_GLYPH( 0x00D8, 1, -15, 12, 16, 14, 0x0000BBBF ),
  EW_GLYPH( 0x00D9, 1, -17, 11, 17, 14, 0x0000BE79 ),
  EW_GLYPH( 0x00DA, 1, -17, 11, 17, 14, 0x0000BFE1 ),
  EW_GLYPH( 0x00DB, 1, -17, 11, 17, 14, 0x0000C149 ),
  EW_GLYPH( 0x00DC, 1, -17, 11, 17, 14, 0x0000C2C5 ),
  EW_GLYPH( 0x00DD, 0, -17, 10, 17, 10, 0x0000C43D ),
  EW_GLYPH( 0x00DE, 1, -14, 11, 14, 13, 0x0000C5E1 ),
  EW_GLYPH( 0x00DF, 1, -15, 11, 15, 12, 0x0000C740 ),
  EW_GLYPH( 0x00E0, 1, -15, 9, 15, 11, 0x0000C8EF ),
  EW_GLYPH( 0x00E1, 1, -15, 9, 15, 11, 0x0000CAA0 ),
  EW_GLYPH( 0x00E2, 1, -15, 9, 15, 11, 0x0000CC51 ),
  EW_GLYPH( 0x00E3, 1, -14, 9, 14, 11, 0x0000CE1A ),
  EW_GLYPH( 0x00E4, 1, -14, 9, 14, 11, 0x0000CFD2 ),
  EW_GLYPH( 0x00E5, 1, -15, 9, 15, 11, 0x0000D17A ),
  EW_GLYPH( 0x00E6, 1, -10, 15, 10, 17, 0x0000D33B ),
  EW_GLYPH( 0x00E7, 1, -10, 9, 15, 10, 0x0000D58C ),
  EW_GLYPH( 0x00E8, 1, -15, 9, 15, 11, 0x0000D71D ),
  EW_GLYPH( 0x00E9, 1, -15, 9, 15, 11, 0x0000D8DF ),
  EW_GLYPH( 0x00EA, 1, -15, 9, 15, 11, 0x0000DAA1 ),
  EW_GLYPH( 0x00EB, 1, -14, 9, 14, 11, 0x0000DC7B ),
  EW_GLYPH( 0x00EC, 0, -15, 5, 15, 5, 0x0000DE34 ),
  EW_GLYPH( 0x00ED, 1, -15, 5, 15, 5, 0x0000DEC3 ),
  EW_GLYPH( 0x00EE, 0, -15, 6, 15, 5, 0x0000DF52 ),
  EW_GLYPH( 0x00EF, 0, -14, 6, 14, 5, 0x0000E008 ),
  EW_GLYPH( 0x00F0, 1, -16, 10, 16, 12, 0x0000E0A0 ),
  EW_GLYPH( 0x00F1, 1, -14, 9, 14, 12, 0x0000E2B9 ),
  EW_GLYPH( 0x00F2, 1, -15, 10, 15, 12, 0x0000E3E3 ),
  EW_GLYPH( 0x00F3, 1, -15, 10, 15, 12, 0x0000E5A0 ),
  EW_GLYPH( 0x00F4, 1, -15, 10, 15, 12, 0x0000E75D ),
  EW_GLYPH( 0x00F5, 1, -14, 10, 14, 12, 0x0000E932 ),
  EW_GLYPH( 0x00F6, 1, -14, 10, 14, 12, 0x0000EAF5 ),
  EW_GLYPH( 0x00F7, 0, -12, 10, 10, 11, 0x0000ECA8 ),
  EW_GLYPH( 0x00F8, 1, -11, 10, 12, 12, 0x0000ED8C ),
  EW_GLYPH( 0x00F9, 1, -15, 9, 15, 12, 0x0000EF5D ),
  EW_GLYPH( 0x00FA, 1, -15, 9, 15, 12, 0x0000F074 ),
  EW_GLYPH( 0x00FB, 1, -15, 9, 15, 12, 0x0000F18B ),
  EW_GLYPH( 0x00FC, 1, -14, 9, 14, 12, 0x0000F2BA ),
  EW_GLYPH( 0x00FD, 0, -15, 10, 19, 10, 0x0000F3C8 ),
  EW_GLYPH( 0x00FE, 1, -15, 10, 19, 12, 0x0000F5C7 ),
  EW_GLYPH( 0x00FF, 0, -14, 10, 18, 10, 0x0000F765 ),

  EW_FONT_PIXEL( WasherListFontL, 0x0000F95A )                  /* ratio 67.76 % */
    0xF7BDEF71, 0x78FF7BDE, 0x0337BDEE, 0x635833CF, 0xDE2D1DE1, 0x5EABA079, 0xF9EAA82F,
    0x02C3D006, 0xF1024454, 0xAF02F5BE, 0x673055D5, 0x63D0D51B, 0x6C87E3D2, 0xDDF01A8C,
    0x82216F7B, 0x810099BD, 0x24006045, 0xB7B37411, 0x6318C631, 0x7197718C, 0x90A42017,
    0x62221843, 0x2F58988A, 0x197FE0BD, 0x8B993309, 0x7BBF1DFF, 0x3FF7FFF3, 0xFF71DDEE,
    0x5612B064, 0x91620B12, 0xDD5FB8C9, 0xE33EF3DB, 0xBEB7BECE, 0x9AC990FB, 0x21232730,
    0x00200A53, 0xE20006CF, 0x92F9E5FD, 0x8EEFFD7F, 0x90DF8D4F, 0xB00616BF, 0x7EC804E2,
    0xBB980AEE, 0xEFC82EFA, 0xF902F4FF, 0x17E02F1B, 0xF444E011, 0x5359E1FF, 0x6FB9EF7F,
    0x97FB58B7, 0xCF00027B, 0xB39DF106, 0x73F01E40, 0x1BA137F6, 0xF7E579E2, 0x6909AC61,
    0x01B70390, 0xD203C780, 0x036F0720, 0x3EFCB4F1, 0xE77C5573, 0xF6717E2C, 0x3F5EFD37,
    0x7C537F67, 0x32AB2CE7, 0x1F7E579E, 0x1A4FEF10, 0x267A00E4, 0x497AC800, 0xBFA01C83,
    0xDF969E20, 0xF82D6307, 0xC4DFD9C5, 0x017FDDF8, 0x5F7F719C, 0x335F3300, 0x0521080A,
    0x01674210, 0x00757E65, 0x03FEBD59, 0xC0DF2E81, 0xBD5DE13A, 0x455F81DE, 0xF3F567CE,
    0xCB5C6A1F, 0xBD7FCBE5, 0xF13F9655, 0xC978DFCF, 0x12CF2739, 0xBFB78667, 0xF7FC7B7B,
    0x1771CBF3, 0x31110E42, 0xA79E2BF1, 0x7C632778, 0x855246FC, 0x210F4871, 0x0420C060,
    0xA838C1E9, 0x63246FC2, 0x9E27787C, 0xD912FCA7, 0xD6493DF8, 0x72A0FD87, 0xC0C83C30,
    0x1E60003C, 0x543C3064, 0xD643F60E, 0xB249EFC7, 0x84420F21, 0x9FF8E7D0, 0xF30FFDE7,
    0x33E658FF, 0xC9AEFD38, 0x080BBD37, 0x0001B580, 0xF7180000, 0xEF7BCEDE, 0x3B7BDC6F,
    0x003FBDEF, 0xD6000000, 0x787CE786, 0x3DF8D9E2, 0x673F3DF1, 0xDEF7B887, 0x8FF59D5F,
    0xE07E3FDF, 0x80BB03F9, 0x814307F5, 0x05CF015F, 0x27A81463, 0x720FEFC0, 0x008CF02C,
    0x1EA207FB, 0x3EE09950, 0x8D40FD40, 0x1005FE01, 0x82BFB9EF, 0xFEEFB3FF, 0x5A6E398A,
    0xE073FCD9, 0x60B3D237, 0x92C06258, 0x24012401, 0x6A92C062, 0x1CDCB0C1, 0xD4F48DF8,
    0x7E2F2B4D, 0x3FFBBECF, 0xF05DDF50, 0xEFC03DFB, 0x0000006E, 0x00000000, 0xE0000000,
    0x7BEB77B9, 0x3DFFE887, 0xB9D7625F, 0x7BD27637, 0x078FCF88, 0x00C02462, 0x8E80D8A8,
    0x03A3BC09, 0x504CF9CC, 0x5F181F5D, 0xF3FC607E, 0x88FF101F, 0x4BBDEF7B, 0x57E7BEF4,
    0x9BDF55F8, 0x2EDF87BF, 0xC021C6F1, 0x05CC8098, 0xC1F8CEA2, 0x03717E7B, 0x2F6BBBDE,
    0x13B3BC60, 0x480F2DB0, 0x60DF7C73, 0x3D8C73BE, 0x7EFF3DCE, 0xE02F7181, 0x0263BC00,
    0xBE205F35, 0x7C6FC05A, 0x00DE7CC0, 0x5F80ABD9, 0x74EF7BAC, 0xF7BDEFFF, 0x01FEE9DE,
    0xEE000000, 0x1FDEF7BD, 0xFEF7BDF4, 0x06180108, 0x3A600420, 0xF585EEE7, 0xFD7F739C,
    0xAD62BF23, 0x09BF801A, 0xD46E0180, 0x7E8A6FD8, 0xDC6FC63A, 0x626FC77B, 0x45EEE77C,
    0xBEF7FFFD, 0x85737C5B, 0x0BC667E7, 0x9CC011EC, 0xA5F39DF9, 0xFE7BEF9C, 0x61BF12F3,
    0xA131CE74, 0xE081E79C, 0xBB1E0F1F, 0x56F19766, 0xCF7D7F79, 0xDEF713F3, 0x2BBDEF7B,
    0xDEF7BDEE, 0x9E780B1A, 0x8035E80B, 0xAF807E35, 0x01791812, 0x033B00A5, 0x44404CF0,
    0x08018600, 0xDCF78807, 0x7DCEC0FD, 0xD99937FB, 0x020FE6A9, 0x0F150CFF, 0x7FFC8476,
    0x3C2D631D, 0x367FDD63, 0xC7A79DF3, 0xFCC75744, 0x87F111DB, 0x217119CE, 0x8C2B9BF0,
    0xF7B3D39B, 0x3076A7BD, 0x897CE77E, 0xDD73EFFA, 0x3E259FA4, 0xEF86C62D, 0x44F0C009,
    0xEF0861FC, 0xAC6F4533, 0x5A7DDDFE, 0x3FF7FEB0, 0x33B0131F, 0xEB1FAC81, 0x933CE30D,
    0xDFDEF791, 0x1FEB3A8F, 0xEAFC7FBF, 0xB3A8002C, 0xC7FBF1FE, 0x8FF2CEAF, 0xD4FC7F9F,
    0xE0000059, 0x789E1F39, 0x7C4F7E36, 0x01D9CFCF, 0xCC42FD90, 0x7D4BAFFD, 0x3DFF57F7,
    0xFF8DFFF3, 0x004613BF, 0xFFF37FF9, 0xDDF5095F, 0x1FBFEFDF, 0xB5FFB988, 0xDEF7BDC7,
    0xDC6FEF7B, 0xF7BDEF7B, 0x600000FE, 0xBDEF7BDC, 0xF7C6FEF7, 0xF4EFD200, 0x6FCEF880,
    0x780AF7FC, 0xA7DBF77E, 0xF9E20B01, 0x3A77EF9D, 0x7B1BFBBE, 0xA77E90AF, 0xB9DF1807,
    0xBDE6E6FF, 0x1DDAF5BF, 0x804028E6, 0x67107E31, 0x81C6F82C, 0x3FC25FAA, 0xB016701E,
    0x4FF7E05E, 0xE540B950, 0xFFDF3C02, 0xD409DD9E, 0xCF7DDCFF, 0xAFCC17B5, 0x7A304F7F,
    0xFFD1937F, 0x876F9007, 0xFFD60EFB, 0xAE54BFF4, 0xCEFF45CA, 0xFBA87CC9, 0xC3BAE45F,
    0x73E6E0CE, 0x2EE0C6F9, 0x078C1888, 0x007FD899, 0xCCF19FCF, 0xF195EC99, 0x1D38DB1B,
    0xFB5AC7FB, 0x6F73CF7F, 0xDE1F334F, 0xBBEC6BB3, 0x2BF7E21F, 0xBEFCF000, 0x12FA82AF,
    0xDEFFEE78, 0x007FEE7B, 0xFC01BBCC, 0xEA202473, 0x59600F17, 0xCFF00FCF, 0xD44123D8,
    0xD9603CA3, 0x3FC0FC46, 0xA8891A8A, 0xA583D707, 0x1F9FBDEE, 0xBDEF71FE, 0x55148E77,
    0x5CB1EFE0, 0x8FF3F150, 0x7191A807, 0xFFF7BDEF, 0xEF7BCC26, 0xF1809DC9, 0x129007C6,
    0xEA03F860, 0xEF79858E, 0xEF30B9FD, 0xBFDFFFBD, 0x35DEB901, 0x2C014A00, 0xB202B600,
    0x7BCC1AD7, 0xC35FCDEF, 0xFFF73BF3, 0xFFBF7E26, 0xBC7F27B9, 0x7E327FCF, 0x00E731AF,
    0x8600FCFC, 0x00133001, 0x18026600, 0x0FCFC006, 0xC1333C60, 0xC3EE7BE0, 0xDF83FDF8,
    0x727B9CEF, 0xEF7BDC47, 0xEF304DF9, 0x017FBBDD, 0x3F3FFAE4, 0x019F3180, 0x1803F3F0,
    0x80130006, 0x94016000, 0x00F7F00D, 0x72099AC6, 0xF3179FFD, 0x3F7FBDDE, 0xEF7BDEE2,
    0xBDE67FBD, 0x003FDEF7, 0x30000000, 0x8FF7BDEF, 0x7FBDEF79, 0x00000000, 0xEF798000,
    0xBDC6F7BD, 0xFF7BDEF7, 0xBDEF7BCC, 0x0000007F, 0xBCC00000, 0xE63FDEF7, 0x01FEF7BD,
    0x00000000, 0xDCEFD400, 0x7EF07BF3, 0xE8EF7BFF, 0x0CFFAEF0, 0xCE723BD1, 0x07E7C201,
    0x99800C30, 0xEF7B8000, 0xDEE1335D, 0x7E0030CB, 0x99E3007E, 0xFE7BE003, 0x7E4B4433,
    0x3BBDFFBF, 0x05F713F6, 0x00000FEE, 0x00000000, 0xDEF7BCC0, 0x7BDE617B, 0x0000BDEF,
    0x00000000, 0xF7100000, 0x00000005, 0x0EEB0000, 0x00000000, 0x00000000, 0x0C000000,
    0xFF88C7F8, 0x8AF53C2F, 0xBBF6F71D, 0xFE217DC4, 0xC6F800FF, 0xBF5BC009, 0x3D739801,
    0x80D5D180, 0x7180D13C, 0x19E03446, 0xA00F59BF, 0x6A068E9F, 0x6240B9D1, 0x7400378E,
    0x39AA8034, 0xE2D1BC00, 0x000000BE, 0x00000000, 0x00000000, 0x30000000, 0xBEF7BDEF,
    0xFB026F71, 0x18C0783E, 0x37E07E30, 0xF3C246A0, 0x8C3E3383, 0x0F7E2031, 0x8E605ABE,
    0x3C403AC1, 0x38051A9F, 0x3C00FFE5, 0x003F59E3, 0xF80073AB, 0x58C007F2, 0x201D0013,
    0x3FB81FEE, 0x998C01B2, 0x88069F00, 0xCCC0067E, 0x03C7A00B, 0xE80354F0, 0xF318025C,
    0x6F68018D, 0x009DE200, 0x1A0018D6, 0x6FCF7DAC, 0xEFAFEC42, 0xBE1FBF39, 0x9F73C5BC,
    0x909BD54F, 0x0F7F19F3, 0x227BF3F0, 0x00C46181, 0x26600130, 0xA00C3980, 0xF01F9F8C,
    0x26678DF7, 0x2FD3358C, 0x7FF3C3EF, 0xDEFF625E, 0x88FF4E73, 0xFFBDEF7B, 0x7BDE60AF,
    0x404DF8EF, 0x4600D5BE, 0xE0030024, 0x37C600C9, 0xEF7BCC5E, 0xEF30BB19, 0x0137FFBD,
    0x00000000, 0xED600000, 0xC4137E7B, 0xF39EFAFE, 0xB797C1FB, 0x51F3EE78, 0x7CE426F5,
    0xF807BF86, 0x812279F9, 0x60018861, 0x01330002, 0xCA00C34C, 0xFE03F3F0, 0x84CD467E,
    0x97C19EB1, 0xF939E1F7, 0xEFAFEC43, 0x58076FED, 0x005DE9FF, 0x0866FADE, 0xF7FFAFC0,
    0xBDEF716E, 0x980DFFF7, 0x5FE3DEF7, 0x068DF180, 0x00000730, 0xF8C029E2, 0x77BDE634,
    0xF7981EC7, 0x1D01274E, 0x98EF100D, 0x401B2B00, 0x633C0347, 0x77BEE626, 0xF5FDE277,
    0xC63F5DBD, 0x5FB515FC, 0x1D20031E, 0x0BB51A80, 0xF7E39FF0, 0xFFDE205F, 0x201FFD1A,
    0x03FCACFB, 0xD8028CF4, 0x1FE018C2, 0x993BFEE5, 0x1DFB0DF3, 0xB7FF9EFB, 0x7BDEF73C,
    0x7DF7BDEF, 0xDF5BBDEE, 0x00005F7B, 0x00000000, 0x00000000, 0x00000000, 0xFB880000,
    0x0007F702, 0x00000000, 0x00000000, 0x46400000, 0xA7AE1826, 0xE962FC06, 0x756B0771,
    0xB3DEEBB0, 0x403ED37F, 0x0517F7DC, 0x60FE5D96, 0x40B233C7, 0xA8993C3D, 0x60F3F3F8,
    0xA8D88C5B, 0xE427AC0A, 0x528FF0D8, 0xF6D8A81E, 0x7EA55048, 0x0515CDC0, 0x8039BC54,
    0xDE60A278, 0xE03BDE07, 0xA1FC7FF7, 0xC46B3C14, 0x91FE6440, 0xA83CF7F1, 0x30D30AF8,
    0xC54FD922, 0x4DFC7B60, 0x66450F6A, 0x61C88658, 0x8C8B59FC, 0x44AA52BF, 0x7FCB3C6E,
    0x0F1F23B0, 0x54A2AA46, 0x6C6AD81A, 0x3C077B8C, 0xE5541EFE, 0x046B9103, 0xAC173E76,
    0x90F12828, 0x5FF607E7, 0xD1CC2ACE, 0x8DF8D1BC, 0x63C77887, 0xD7CAC366, 0xF8F40AAF,
    0xA33C0BE5, 0x1E910266, 0x03C77B40, 0x3473BE72, 0x5CE96378, 0xF1A97AA8, 0x370B9D06,
    0x183F1CDA, 0x04EFC6B5, 0x98DDF9C4, 0x78D6E330, 0x63A51BE1, 0xE35364F2, 0x77851DE3,
    0x3C2F18D4, 0xC078F6E3, 0x3302F557, 0x018C01E2, 0x00000000, 0xEF7B9E00, 0xF2DEF7BD,
    0xFDEF7BDC, 0xC74028C7, 0x0E678C05, 0xCC068DC0, 0x9D1006F1, 0x02F1D00B, 0xB402AAC6,
    0x4CD4F017, 0x56036740, 0x7AF100FE, 0xDEF7BDEF, 0xD9FDEF75, 0x000007F7, 0x00000000,
    0xF5FDF600, 0x180AFC07, 0x03FA80A3, 0x0C6A02FF, 0x2DC07EA0, 0x3C4132A0, 0x01FFF00F,
    0xB188046B, 0x781FDF80, 0x03C7201E, 0x95F8173C, 0x3CFBDEE7, 0x000026F7, 0x00000000,
    0x3C000000, 0xEEFC26F7, 0x0FACF900, 0x02B7D6FC, 0x89CCBEB1, 0xC3EF8635, 0x528D63EF,
    0x797510F9, 0xBBF6EF13, 0xEF7BDEF7, 0x8FF623BD, 0x7F24CF38, 0x7FEF9E1D, 0xEF778BCF,
    0x7B2F5BFB, 0xE016A786, 0xBEB1831F, 0xFFBF137F, 0xEB79B7B9, 0x11893EFF, 0x88F11803,
    0x77EBD2F5, 0xEE31F1FF, 0x00000002, 0x31800400, 0xF437FDF7, 0x3F9EDFF9, 0xB79E1D3C,
    0x014A1706, 0x000C01D2, 0x589C05CB, 0x7574537C, 0x8CFFCE70, 0xDDFCC4DF, 0xFAF87BF3,
    0x4F983BDC, 0x5F1FA23F, 0x003C604C, 0xFC01E300, 0xFD5601E2, 0xEFCBD61E, 0x1BD9EF7D,
    0x00017FE0, 0x58980000, 0xF89FFBFF, 0x29F77DBD, 0xE88F7EB3, 0x8C03C5F4, 0x27200007,
    0xBC01C9E0, 0x88FC8679, 0x7DE7FEBD, 0xFDFFAC1F, 0x77EFC1BF, 0xF9BFCDEE, 0xF1DF219C,
    0xF3224F7C, 0x7BDEEA3F, 0xDEE7866F, 0xC77DEF7B, 0x0272FC02, 0x9A327AAB, 0xDCF77F5F,
    0x8B39DF0B, 0x5267FEB7, 0x002410CF, 0xDFEEAB9E, 0x03FDD573, 0x00000000, 0xBF200000,
    0x37BDEF73, 0x1BEF76C4, 0x5F1BC37D, 0x0843F598, 0x30BF5C04, 0x79ACC5EB, 0x107BFFEF,
    0x7BFB9F6B, 0x78028D60, 0xF3DEF7BC, 0x7FE7C87B, 0xA5F1BDEF, 0x4D710FEF, 0x478EC175,
    0x67B219CD, 0xEEFCDF87, 0x71A7B1BD, 0x00000017, 0x8C600200, 0xF38D3DDF, 0x935DF77D,
    0x3F8AC37C, 0x0004C607, 0x00000000, 0x78D39E00, 0x05DC634E, 0x9E000000, 0x34E780D3,
    0x0005DC60, 0x00000000, 0xF53F0400, 0x71CDE7DE, 0x0000001F, 0xD0000000, 0xBAB980B7,
    0x205CF540, 0x7905E7BF, 0xCF578123, 0x17AAEE02, 0x30D1EA74, 0x400D7318, 0x02EE35E7,
    0x00000000, 0x9E35C000, 0x731DC735, 0x7E34FFDF, 0xF3DC2CF7, 0xFB7DEBBF, 0xAA1FB3BD,
    0xA5F9EBC3, 0x0F48B976, 0x13000064, 0x00000000, 0x00000000, 0xE78EE300, 0xFEE34F77,
    0x49AEFBBF, 0xE7F15875, 0x000098C2, 0x00000000, 0xF3DF6B00, 0xDF6F7E26, 0xEB30F63D,
    0xEB8DF92B, 0x8C67828B, 0x09BF80F1, 0x6FE098C0, 0x8CF0597E, 0xF92DEB31, 0xEBEFCB8D,
    0xC61EC7BB, 0x7FDF731D, 0xDBFF39C3, 0xC3A787F3, 0x42E0D6F3, 0x803A4029, 0x80B96001,
    0x11EF8B13, 0xFEFC1D5D, 0x137E33FF, 0x057F7FFA, 0x00000001, 0x67FEFFD6, 0xEFB7BF5F,
    0xDFACD33E, 0xE2F87A23, 0x0003C601, 0xE4F01390, 0x433CDE00, 0xF5EC437E, 0x8879EF3F,
    0x2D5F9CEF, 0xC0000080, 0x9FF9E3B8, 0x2465F7C1, 0xF60DEFB9, 0x00000000, 0xFFAC0000,
    0xEFD15F3D, 0x9E2E6F7B, 0xE60F44A7, 0x79EF8133, 0xBF112BFF, 0xC27BBCFD, 0x440D9BE8,
    0x6159E445, 0xEF644F3C, 0xE1F3CF7B, 0x9826417D, 0xBDD66F30, 0xEF755E6B, 0x00000002,
    0x33D40900, 0xF3FF5D04, 0xFB81F73E, 0x00000003, 0xC2000000, 0x85F15240, 0x73BF837A,
    0x37D1EFF6, 0xF9FCEEA1, 0x8C731FE0, 0x97E2D607, 0x333F8A83, 0xE22C9C7E, 0x4E07A879,
    0xF07E278E, 0x018F6FC4, 0xC07EB3D6, 0xDCF13197, 0x791B7989, 0x51D8B967, 0xA8551528,
    0x699D8239, 0x46F11A67, 0x35294551, 0x6C46D9E2, 0xECBB6E46, 0x3CAA14A5, 0x57F8C55B,
    0x4654C760, 0xBF286D54, 0x828BEB07, 0x19D8DCA8, 0x8C3F3C83, 0x87ADF2DB, 0xED1ACD9B,
    0xD1DC2F19, 0x5CC60B3D, 0x030A81A3, 0x178FFCCC, 0x9AE8E7A2, 0xAA7B46F8, 0xD78D53C3,
    0xBA80EFA7, 0x3FC1F3F3, 0xD60B3E66, 0xC543C4E2, 0x3FC3CA9F, 0xF5A55F0B, 0xE2A78CC0,
    0x7FDF5107, 0xFD72700C, 0x8098CA80, 0x5D640159, 0xE4154F20, 0xF80FCFD9, 0xBDEF7BDD,
    0xFDEF77E9, 0x6CDE0959, 0x3182F9D0, 0x0FD7029F, 0xD101D1CC, 0x0BCFC135, 0xBDFF89EA,
    0xEFC43EF7, 0xFECF98FC, 0x00049E71, 0x201B82C4, 0xF187BF90, 0x689C668F, 0x3800AFC4,
    0x66200013, 0x17E79DE0, 0x00000037, 0x00000000, 0xE2FFB9E0, 0x9B85EBB9, 0x00990000,
    0xC60F9500, 0xF3D4BDF3, 0x0059197B, 0x0008C062, 0xD5DCF26E, 0x05F3BF18, 0xF2739C43,
    0x38CEE23F, 0xFDCF7E8F, 0x631B7B4D, 0xB0C6318C, 0x818BEF37, 0x21601200, 0x08135858,
    0xA0006AC0, 0x3BFE77BE, 0xE73FEFF4, 0xD7AB1889, 0x099F5E35, 0x005200A4, 0xF9A8137F,
    0xE97C6BAE, 0x4F39EDFD, 0x3BDF9E0E, 0x60001DFF, 0xDCEFC835, 0xFB1D88BD, 0xE8CD2FF6,
    0x031D3B54, 0x0B6C0908, 0x7BBE7FFC, 0x93EFFCFF, 0x0061FEF7, 0xF8D4013C, 0x8172FA81,
    0x7BDEF237, 0x318132EF, 0x9CF7BFB2, 0xF97FFCDF, 0xBFCF793D, 0x2F8ED79F, 0x4F50F5CC,
    0x00031FE0, 0x31FE04F5, 0x5CC2F8EC, 0xB8D6FC8F, 0xE74FDFE7, 0xDF9CFBAF, 0x2EE37FFC,
    0xF98DF388, 0x26D3F4C2, 0xFBC437DE, 0xE5858E63, 0xEFD06BF1, 0xDEE21F33, 0xDEEAFC6F,
    0x19DEF715, 0xF715DEE7, 0xBBDCE9DE, 0x9D3BDEE2, 0x0000177B, 0x00371000, 0xF14C0000,
    0x0142FC46, 0x9F400000, 0xFBC0EFFB, 0xD4067BEC, 0x9817E34A, 0xF46402CF, 0x773F40E9,
    0xFCC5BAD7, 0x7E76F8C5, 0xC4E31FC9, 0x926F3D63, 0xFEE73BC2, 0xEF263BC6, 0x3FAED67F,
    0x04CADF64, 0x2ED45AE2, 0xAA78B271, 0xFF7975EF, 0x4017FF11, 0x7E7BFFBE, 0xDEF7580B,
    0x07FCFA7B, 0x1933DED6, 0x7E527BEF, 0xCE77E45F, 0x7D7BF597, 0x7BCDC45F, 0x51CE61FE,
    0xAC3A378F, 0xAA64F3C1, 0x000FFC02, 0x00AA990C, 0xCDE3D4E7, 0xD4F1730E, 0xBCEC45F7,
    0x33399767, 0x77E47FBF, 0x5FAA37CE, 0x64AF6FD6, 0xB13FEFBC, 0xF4F7B9EE, 0xBF3C0FF9,
    0x7D187FF3, 0xB0E63F7E, 0x177EB062, 0x18C3DF7B, 0x4D4D216F, 0x053FF7F4, 0x558B796F,
    0xEF3CAAB5, 0x7E23DE79, 0x001EBF9D, 0xEBF9D7E2, 0xE7DEF3C1, 0xAD4F58BD, 0xF7BDC6A7,
    0x6FEF7BDE, 0xBDEF7BDC, 0x00000277, 0x8BFA0000, 0xB1FDEF7B, 0xBC4F77FE, 0x97B3DF67,
    0xFBEE7D91, 0xBA8EA2FD, 0xBA857E2B, 0xCEABA833, 0xF4635D8C, 0xC3B7E717, 0x7B3DF67B,
    0xF7BDEF79, 0x0DFDF635, 0x11CF7BCE, 0x78464F1E, 0xB9CE193C, 0x07F580E7, 0x60000000,
    0xEF3B7BDC, 0xEF71BFBD, 0xFEF7BCED, 0xB2000000, 0x00179E00, 0x7BDEF718, 0x633FBDEF,
    0x79C3FFDF, 0xFF0BF7EF, 0x11848AC7, 0x7E067709, 0xC3ED89B3, 0x3FBDD47F, 0xF9A7BBF9,
    0x4ABFF7FE, 0xE326334F, 0xEE326F7E, 0x6B509DEF, 0xEA31FFC7, 0xFFDCE71F, 0x30EDF8B3,
    0xBFD1139F, 0xFF82EE34, 0x0000001F, 0xE0000000, 0xA19E0722, 0xDFFCC0EE, 0x73933EFB,
    0x47FAAFEE, 0x8C000002, 0xFDF2013D, 0x33FBBFDF, 0x03A04CF6, 0x40000510, 0xDE005000,
    0x06BDC804, 0x3FDF7A20, 0x00000000, 0xE8000000, 0xE3FD6753, 0xC11F8FF7, 0x22FAC4BB,
    0xF9A659FE, 0x7DE86F9E, 0x00000BF5, 0x3FE77C40, 0x9FB739F9, 0x67BE5A7C, 0x4B00B249,
    0x5A7CAFF2, 0xDCE7E3CE, 0xF174BA7E, 0x1BEFC6FB, 0x3DF27BC6, 0x9ADFCD61, 0x7F35803F,
    0x7BC6FE6B, 0xFBF13DF2, 0xF41BEFC6, 0xD00F20BE, 0x000DD02F, 0xE0009AC6, 0x3C780036,
    0x006DE000, 0xFF115730, 0xC5EFC03F, 0xAD73C0AF, 0x20362A4A, 0x17DE1FDE, 0x3EF267A0,
    0x897AC809, 0x3797EEB9, 0xF7105FD0, 0x306F2FDE, 0xDE8002D6, 0xFD01E417, 0x3000DD02,
    0xDB8004D6, 0x0078F000, 0x98006DE0, 0xFFBEC6AB, 0x9D7BF007, 0xE0BF7EF7, 0xFFA556B9,
    0xBC424563, 0xA122303F, 0x033B8267, 0xCDF82F59, 0xB102FE86, 0x82D6307D, 0x7F7BA8FF,
    0x834F77F2, 0xDFFBE03C, 0x06E82AFF, 0x1898CD3D, 0x7EE3026B, 0x6036E26F, 0x793BDFDC,
    0x6D6A003C, 0xFFE206DE, 0x5737F518, 0x389FFF89, 0xE59FFEE7, 0x182BF2F7, 0xAADA7BBF,
    0xC401B154, 0x017DE3FB, 0x27DE99E8, 0x62BD6401, 0x0DE5FBAE, 0x7B885FD0, 0x603797EF,
    0x790005AC, 0x04C4F05E, 0xE7904C4F, 0xA80B7E05, 0xE41F960B, 0xF9B80CFB, 0xE60B8F41,
    0xD5400033, 0xDF9FDE23, 0x0BC77BEC, 0x1801FFE3, 0x7200BE77, 0xDDE600BF, 0x1239FE00,
    0x078BF510, 0x07E7ACB0, 0x91EC67F8, 0x1E51EA20, 0x7E236CB0, 0x8D451FE0, 0xEB83D444,
    0xDEF752C1, 0xB8FF0FCF, 0x473BDEF7, 0xF7F02A8A, 0xF8A82E58, 0xD403C7F9, 0x0FFBE048,
    0x01DE7780, 0x9804EEF0, 0xE7F80377, 0x2FD44048, 0x9EB2C01E, 0xB19FE01F, 0x47A88247,
    0x8DB2C079, 0x147F81F8, 0x0F511235, 0xDD4B07AE, 0xFC3F3F7B, 0xEF7BDEE3, 0xC0AA291C,
    0xA0B963DF, 0x0F1FE7E2, 0xCEA12350, 0xDFBD4029, 0xFF5016F7, 0xE6017FAA, 0x39FE00DD,
    0x8BF51012, 0xE7ACB007, 0xEC67F807, 0x51EA2091, 0x236CB01E, 0x451FE07E, 0x83D4448D,
    0xF752C1EB, 0xFF0FCFDE, 0x3BDEF7B8, 0xF02A8A47, 0xA82E58F7, 0x03C7F9F8, 0x673C48D4,
    0x7D03FC8F, 0xFC0DDDEF, 0x00F3EC63, 0xFE00DDE6, 0xF5101239, 0xACB0078B, 0x67F807E7,
    0xEA2091EC, 0x6CB01E51, 0x1FE07E23, 0xD4448D45, 0x52C1EB83, 0x0FCFDEF7, 0xDEF7B8FF,
    0x2A8A473B, 0x2E58F7F0, 0xC7F9F8A8, 0xBC48D403, 0x80BCE227, 0xFFBC00C1, 0x980BFF88,
    0xE7F80377, 0x2FD44048, 0x9EB2C01E, 0xB19FE01F, 0x47A88247, 0x8DB2C079, 0x147F81F8,
    0x0F511235, 0xDD4B07AE, 0xFC3F3F7B, 0xEF7BDEE3, 0xC0AA291C, 0xA0B963DF, 0x0F1FE7E2,
    0x9D612350, 0xFDDE00B3, 0xFDDE017F, 0x39D6017F, 0x0DDE600B, 0x01239FE0, 0x0078BF51,
    0x807E7ACB, 0x091EC67F, 0x01E51EA2, 0x07E236CB, 0x48D451FE, 0x1EB83D44, 0xFDEF752C,
    0x7B8FF0FC, 0xA473BDEF, 0x8F7F02A8, 0x9F8A82E5, 0x8D403C7F, 0xEF7BEC04, 0xC05EF7BD,
    0xF7BED233, 0x47780BDE, 0x5E398001, 0x0F97E000, 0x03F99800, 0xB1317E00, 0x6037BDEF,
    0xDEFB0BE5, 0x98DE037B, 0x9C456000, 0xEF00277B, 0x09DEF7B8, 0x4001A3A0, 0xE00051CC,
    0xF7D80B8D, 0x9E077BDE, 0x37FFB9DF, 0xCFFDFBF1, 0x7DE3F93D, 0x7BF193FE, 0xE007398D,
    0x0C3007E7, 0x00009980, 0x30C01330, 0x007E7E00, 0x060999E3, 0xC61F73DF, 0x7EFC1FEF,
    0x3B93DCE7, 0xFDEB7F30, 0x7D6209BF, 0x167F8801, 0xEF0134C0, 0xFF1806F9, 0xBE77180F,
    0x7117EE40, 0xDEF7BDEF, 0x7BDEF33F, 0x00001FEF, 0xF7980000, 0xBCC7FBDE, 0x003FDEF7,
    0x00000000, 0xDEF7BCC0, 0x1FF7C17B, 0x80779DE0, 0xEF712777, 0x3FDEF7BD, 0xEF7BDEF3,
    0x0000001F, 0xDEF79800, 0xF7BCC7FB, 0x00003FDE, 0xC0000000, 0x7BDEF7BC, 0xD414E751,
    0xA16F7DFB, 0x12FF55FE, 0xEF7BDEF7, 0xBDEF33FD, 0x0001FEF7, 0x79800000, 0xCC7FBDEF,
    0x03FDEF7B, 0x00000000, 0xEF7BCC00, 0x44F797BD, 0x0306179C, 0xFFC47FDE, 0x7BDEF715,
    0xEF33FDEF, 0x01FEF7BD, 0x80000000, 0x7FBDEF79, 0xFDEF7BCC, 0x00000003, 0x7BCC0000,
    0xFC77BDEF, 0x2F9DC63F, 0xBEE25FB9, 0x00000000, 0x00000000, 0x7787FDF0, 0x29DDE1DE,
    0x00000BEE, 0x00000000, 0x4E750000, 0xDEFBF7A9, 0xBFD57FAA, 0x00017DC4, 0x00000000,
    0x00000000, 0x5E7113DE, 0x47FDE183, 0x5F715FFC, 0x00000000, 0x00000000, 0x7BDE0000,
    0x809DD9EF, 0x5D8F4F73, 0xDF57EA00, 0x05E3A000, 0x3000AB20, 0xCE9DD462, 0xDD4B83BD,
    0x003BDCE9, 0x9E000700, 0x14720018, 0x40346F00, 0xC12F9EFD, 0x2DC7B7B9, 0xF23D9CF0,
    0xBBDEFA0F, 0xEC63FC1B, 0x0FF710F3, 0x00D91FDC, 0x4F804CC6, 0x033F4403, 0xD005E660,
    0xAA7801E3, 0x012E7401, 0x00C6F98C, 0xF10037B4, 0x0C6B004E, 0xFFC60D00, 0x7CEE3003,
    0x017EE401, 0x37E7BED6, 0xF7D7F621, 0x5F0FDF9C, 0xCFB9E2DE, 0xC84DEAA7, 0x07BF8CF9,
    0x913DF9F8, 0x006230C0, 0x13300098, 0x50061CC0, 0xF80FCFC6, 0x1333C6FB, 0x97E99AC6,
    0x3FF9E1F7, 0xEF7FB12F, 0x007FA739, 0xBC007FDF, 0x77800EF3, 0x7BED6027, 0x7F62137E,
    0xFDF9CF7D, 0x9E2DE5F0, 0xDEAA7CFB, 0xF8CF9C84, 0xDF9F807B, 0x230C0913, 0x00098006,
    0x61CC0133, 0xFCFC6500, 0x3C6FBF80, 0x99AC6133, 0x9E1F797E, 0xFB12F3FF, 0xFA739EF7,
    0x0539D407, 0xDEFBF7A8, 0xF55FEA02, 0x7BED602F, 0x7F62137E, 0xFDF9CF7D, 0x9E2DE5F0,
    0xDEAA7CFB, 0xF8CF9C84, 0xDF9F807B, 0x230C0913, 0x00098006, 0x61CC0133, 0xFCFC6500,
    0x3C6FBF80, 0x99AC6133, 0x9E1F797E, 0xFB12F3FF, 0xFA739EF7, 0x47B39E07, 0xF7BE81FE,
    0x31FE06EE, 0xB58079F6, 0x884DF9EF, 0xE73DF5FD, 0xB797C3F7, 0xA9F3EE78, 0x3E72137A,
    0x7E01EFE3, 0x30244F7E, 0x2600188C, 0x3004CC00, 0xF1940187, 0xBEFE03F3, 0xB184CCF1,
    0x7DE5FA66, 0x4BCFFE78, 0xCE7BDFEC, 0x4F781FE9, 0x830179C4, 0x11FF7801, 0xFB5817FF,
    0xD884DF9E, 0x7E73DF5F, 0x8B797C3F, 0xAA9F3EE7, 0x33E72137, 0xE7E01EFE, 0xC30244F7,
    0x02600188, 0x73004CC0, 0x3F194018, 0x1BEFE03F, 0x6B184CCF, 0x87DE5FA6, 0xC4BCFFE7,
    0x9CE7BDFE, 0xC426B1FE, 0xF10FBC2F, 0x95FAD65F, 0xE7A1FE2F, 0xD0379BF7, 0x1DE13AA3,
    0xDF5E89D5, 0xD6B0DE6F, 0x0FF17CAF, 0x17FC43EF, 0xEFE60400, 0x9F7CBDDC, 0xB9CEFDF8,
    0xD7AFFBDF, 0xF30FB9EF, 0xF3C727CD, 0xAACBE226, 0x1E6F829F, 0xE7A061FF, 0x9E133C37,
    0xE4064279, 0x0A6037EF, 0xB1183D67, 0x645EB7D5, 0x3EB7E3D4, 0x89F2FC78, 0x33EF9027,
    0xEA2D72A2, 0xFEAF9F3E, 0x7FA73EEF, 0xFCCFBE3F, 0x3027B39D, 0xB8C01FFE, 0xFDC805F3,
    0xB817DC42, 0x0000003F, 0x00000000, 0x00000000, 0xC1323200, 0xE0353D70, 0x3B8F4B17,
    0x5D83AB58, 0x9BFD9EF7, 0x003FEF80, 0xF003BCEF, 0x17DC44EE, 0x00003FB8, 0x00000000,
    0x00000000, 0x32320000, 0x353D70C1, 0x8F4B17E0, 0x83AB583B, 0xFD9EF75D, 0x29CEA09B,
    0x7BEFDEA0, 0xEABFD40B, 0x817DC45F, 0x000003FB, 0x00000000, 0x00000000, 0x13232000,
    0x0353D70C, 0xB8F4B17E, 0xD83AB583, 0xBFD9EF75, 0x3889EF09, 0xC018302F, 0xBFF88FFB,
    0xFB817DC4, 0x00000003, 0x00000000, 0x00000000, 0x0C132320, 0x7E0353D7, 0x83B8F4B1,
    0x75D83AB5, 0x09BFD9EF, 0xBC01FF7C, 0xDDE00EF3, 0x8809DF89, 0x6131BBF3, 0xC2F1ADC6,
    0xE4C74A37, 0xC7C6A6C9, 0xA8EF0A3B, 0xC6785E31, 0xAF80F1ED, 0xC46605EA, 0x00031803,
    0x00000000, 0x0000BEE2, 0xDEF30000, 0xE60AFFFB, 0xDF8EF7BD, 0x0D5BE404, 0x30024460,
    0x600C9E00, 0xBCC5E37C, 0x2FF19EF7, 0xFFEF7BCC, 0x0000001D, 0x17CF7DCC, 0xEEEFDF30,
    0xA67E87F5, 0xC460C6FC, 0x8DF8001F, 0x803CE801, 0x42026F5C, 0x09EC8C00, 0x5FF79FB0,
    0x2FB6FC40, 0x028DE301, 0x7933C058, 0x39FF8163, 0xFF620FF1, 0x04CF3880, 0x3C01D7F2,
    0xF9E00027, 0x78BCF7FE, 0xF5BFBEF7, 0x6A7867B2, 0x1831FE01, 0xF137FBEB, 0x9B7B9FFB,
    0x93EFFEB7, 0x11803118, 0xBD2F588F, 0x1F1FF77E, 0xCC03B7E0, 0xFF4404E7, 0x0079C412,
    0xEFFDF3C0, 0x7DEEF179, 0xCF65EB7F, 0xFC02D4F0, 0xF7D63063, 0x3FF7E26F, 0xFD6F36F7,
    0x623127DF, 0xB11E2300, 0xEEFD7A5E, 0xE7103E3F, 0xF5ADF804, 0xEFBE6783, 0xF66CF07C,
    0xFBE78003, 0xDDE2F3DF, 0xCBD6FEFB, 0x05A9E19E, 0xAC60C7F8, 0xEFC4DFEF, 0xDE6DEE7F,
    0x624FBFFA, 0x3C4600C4, 0xFAF4BD62, 0x507C7FDD, 0xD1B18F67, 0x8DFF7BFF, 0x053EC63D,
    0xDFFBE780, 0xFBDDE2F3, 0x9ECBD6FE, 0xF805A9E1, 0xEFAC60C7, 0x7FEFC4DF, 0xFADE6DEE,
    0xC4624FBF, 0x623C4600, 0xDDFAF4BD, 0xFEF07C7F, 0x002FFE23, 0xFF88FFBC, 0xFBE7800B,
    0xDDE2F3DF, 0xCBD6FEFB, 0x05A9E19E, 0xAC60C7F8, 0xEFC4DFEF, 0xDE6DEE7F, 0x624FBFFA,
    0x3C4600C4, 0xFAF4BD62, 0xA07C7FDD, 0xEF02FFFE, 0xF0002FBD, 0xFA82FBDE, 0xF7CF0BFF,
    0xBBC5E7BF, 0x97ADFDF7, 0x0B53C33D, 0x58C18FF0, 0xDF89BFDF, 0xBCDBDCFF, 0xC49F7FF5,
    0x788C0188, 0xF5E97AC4, 0xF0F8FFBB, 0x92EEE77C, 0xE4BE73BF, 0x5F7EF7DD, 0xCBAE73DD,
    0xF7E6619E, 0x4C6FC47B, 0x188589E0, 0xFF7EB197, 0x6F7BDCE9, 0x9CFFDF8A, 0xEF7BDD3D,
    0xFF5BEFBD, 0x006389F7, 0x0BD20623, 0x3AC4788C, 0xBC61BD5F, 0x97CEFD7A, 0xF79FE7BF,
    0xDDFCC0DE, 0xFAF87BF3, 0x4F983BDC, 0x5F1FA23F, 0x003C604C, 0xFC01E300, 0xFD5601E2,
    0xEFCBD61E, 0x1BD9EF7D, 0x3DFECF6B, 0x100BEB10, 0x9A602CFF, 0x80DF3DE0, 0xCE203FD8,
    0x75FC8133, 0x0009CF00, 0xFFF7FEB0, 0xB9DFBF06, 0x73E6FF37, 0xF3C77C86, 0xFFCC893D,
    0xBDEF7BA8, 0xEF7B9E19, 0x0B1DF7BD, 0xAC09CBF0, 0x7E68C9EA, 0x2F73DDFD, 0xE601DBF0,
    0x7FA20273, 0x003CE209, 0xFFDFFAC0, 0xE77EFC1B, 0xCF9BFCDE, 0xCF1DF219, 0xFF3224F7,
    0xF7BDEEA3, 0xBDEE7866, 0x2C77DEF7, 0xB0272FC0, 0xF9A327AA, 0xBDCF77F5, 0xF804E710,
    0x6783F5AD, 0xF07CEFBE, 0x0003F66C, 0x6FFF7FEB, 0x7B9DFBF0, 0x673E6FF3, 0xDF3C77C8,
    0x8FFCC893, 0x9BDEF7BA, 0xDEF7B9E1, 0x00B1DF7B, 0xAAC09CBF, 0xD7E68C9E, 0xE2F73DDF,
    0x5FFC47FD, 0x11FF7800, 0xD60017FF, 0xE0DFFEFF, 0xE6F73BF7, 0x90CE7CDF, 0x27BE78EF,
    0x751FF991, 0xC337BDEF, 0xF7BDEF73, 0x7E0163BE, 0x3D558139, 0xBFAFCD19, 0xFB15EE7B,
    0x92679C47, 0x139E0EBF, 0x000BB8C0, 0x00000000, 0x7CC3B7E0, 0x52FF444E, 0xEE30079C,
    0x00000002, 0x73880000, 0x3F5ADF82, 0xF9DF7CCF, 0x00FD9B3C, 0x00005DC6, 0x00000000,
    0xE23FEF00, 0x3FEF02FF, 0xC602FFE2, 0x0000005D, 0x00000000, 0xBC6013BC, 0xBE36FCAF,
    0x6E7FED77, 0xE46AC638, 0x2AE7FC7F, 0x6F1BFBE4, 0x5CE850BE, 0xE2DDFFE8, 0xFDCE7EC7,
    0x9C6B0DFF, 0xDF897A21, 0x588C7018, 0xF8273180, 0x4073FC67, 0x929D663D, 0x5F7E6CBF,
    0xA87F9BDF, 0xE8D8C7B3, 0xC6FFBDFF, 0x029F631E, 0xFCF1DC60, 0xFFDC69EE, 0xA935DF77,
    0x5CFE2B0E, 0x00001318, 0x00000000, 0x100FF620, 0xFC8099E7, 0x139E0075, 0xEFB58000,
    0xB7BF1379, 0x987B1EEF, 0xC6FC95F5, 0x33C145F5, 0xDFC078C6, 0xF04C6004, 0x782CBF37,
    0x96F598C6, 0xF7E5C6FC, 0x0F63DDF5, 0x9803B7E0, 0xFD1009CF, 0x03CE204B, 0x3DF6B000,
    0xF6F7E26F, 0xB30F63DD, 0xB8DF92BE, 0xC67828BE, 0x9BF80F18, 0xFE098C00, 0xCF0597E6,
    0x92DEB318, 0xBEFCB8DF, 0x01EC7BBE, 0xBF004E71, 0x99E07EB5, 0x781F3BEF, 0x0001FB36,
    0x4DE7BED6, 0x7BBEDEFC, 0x57D661EC, 0x17D71BF2, 0xE318CF05, 0x80137F01, 0xFCDFC131,
    0x6319E0B2, 0x1BF25BD6, 0x77D7DF97, 0x67503D8F, 0xFFA1B18F, 0xF61BFEF7, 0x0014FB18,
    0x6F3DF6B0, 0xDDF6F7E2, 0xBEB30F63, 0xBEB8DF92, 0x18C67828, 0x009BF80F, 0xE6FE098C,
    0x18CF0597, 0xDF92DEB3, 0xBEBEFCB8, 0xF781EC7B, 0x017FF11F, 0xF11FF780, 0xB580017F,
    0xBF1379EF, 0x7B1EEFB7, 0xFC95F598, 0xC145F5C6, 0xC078C633, 0x4C6004DF, 0x2CBF37F0,
    0xF598C678, 0xE5C6FC96, 0x63DDF5F7, 0x019DF00F, 0x49DF0020, 0xB8C00000, 0xEF7BDEF7,
    0xEF7B8DFD, 0x1FDEF7BD, 0x019DF000, 0x6B000020, 0x7F8EF3DF, 0xDDEFBDFA, 0x5672FECF,
    0x9F8E723F, 0x7EEB272F, 0x73C58C63, 0x6E31349F, 0x1FD198C3, 0xEF8DFCC3, 0xA631BE25,
    0x5C6FC967, 0x77BEFBDF, 0x737E1EE7, 0x84DE7BED, 0xCE203FD8, 0x75FC8133, 0x0009CF00,
    0xFB81F73C, 0x00000003, 0xC2000000, 0x85F15240, 0x73BF837A, 0x7E01EFF6, 0x4E7CC03B,
    0x412FF440, 0x9E00079C, 0x01FDC0FB, 0x00000000, 0x20610000, 0xBD42F8A9, 0xFB39DFC1,
    0x139C40F7, 0x0FD6B7E0, 0xF3BEF99E, 0x0FD9B3C1, 0xE07DCF00, 0x000000FE, 0x80000000,
    0x7C549030, 0xEFE0DEA1, 0xF07BFD9C, 0x2FFE23FE, 0x88FFBC00, 0x73C00BFF, 0x003FB81F,
    0x00000000, 0x240C2000, 0x37A85F15, 0xFF673BF8, 0x03B7E01E, 0x1009CF98, 0xCE204BFD,
    0x1DF40003, 0x3E7E7750, 0x67CCC7F8, 0x789C5AC1, 0x7953F8A8, 0xABE167F8, 0xF1981EB4,
    0xEA20FC54, 0x4E018FFB, 0x19501FAE, 0x802B3013, 0xA9E40BAC, 0xF9FB3C82, 0x00177181,
    0x20000000, 0xEFB98C00, 0xFFCFA1BF, 0xE9E1FCF6, 0xB835BCF0, 0x0E900A50, 0x2E580060,
    0x7BE2C4E0, 0xBF075744, 0xDF8CFFFF, 0x5FDFFE84, 0x00000041, 0xF11FF780, 0xF780017F,
    0x017FF11F, 0xBA80EFA0, 0x3FC1F3F3, 0xD60B3E66, 0xC543C4E2, 0x3FC3CA9F, 0xF5A55F0B,
    0xE2A78CC0, 0x7FDF5107, 0xFD72700C, 0x8098CA80, 0x5D640159, 0xE4154F20, 0x000FCFD9

  EW_FONT_KERNING_CODES( WasherListFontL )
  EW_FONT_KERNING_VALUES( WasherListFontL )
EW_END_OF_FONT_RES( WasherListFontL )

/* Embedded Wizard */