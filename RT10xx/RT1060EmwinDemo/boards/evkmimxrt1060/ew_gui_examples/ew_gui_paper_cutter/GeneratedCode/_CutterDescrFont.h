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
EW_DEFINE_FONT_RES( CutterDescrFont, 11, 3, 0, 16, 0x0001, 0x00C0 )
  EW_GLYPH( 0x0001, 0, -9, 5, 9, 5, 0x00000000 ),
  EW_GLYPH( 0x0020, 0, 0, 0, 0, 3, 0x000000A3 ),                /* ' ' */
  EW_GLYPH( 0x0021, 0, -9, 3, 9, 3, 0x000000A3 ),               /* '!' */
  EW_GLYPH( 0x0022, 0, -9, 4, 3, 4, 0x000000F1 ),               /* '"' */
  EW_GLYPH( 0x0023, 0, -9, 7, 9, 7, 0x00000121 ),               /* '#' */
  EW_GLYPH( 0x0024, 0, -11, 7, 13, 7, 0x00000222 ),             /* '$' */
  EW_GLYPH( 0x0025, 0, -9, 9, 9, 9, 0x00000379 ),               /* '%' */
  EW_GLYPH( 0x0026, 0, -9, 8, 9, 8, 0x00000498 ),               /* '&' */
  EW_GLYPH( 0x0027, 0, -9, 2, 3, 2, 0x000005AA ),               /* ''' */
  EW_GLYPH( 0x0028, 0, -9, 4, 12, 4, 0x000005C2 ),              /* '(' */
  EW_GLYPH( 0x0029, 0, -9, 4, 12, 4, 0x00000666 ),              /* ')' */
  EW_GLYPH( 0x002A, 0, -9, 6, 5, 6, 0x0000070C ),               /* '*' */
  EW_GLYPH( 0x002B, 0, -8, 7, 7, 6, 0x00000787 ),               /* '+' */
  EW_GLYPH( 0x002C, 0, -1, 3, 4, 3, 0x00000807 ),               /* ',' */
  EW_GLYPH( 0x002D, 0, -4, 5, 1, 5, 0x0000083B ),               /* '-' */
  EW_GLYPH( 0x002E, 0, -1, 3, 1, 4, 0x00000854 ),               /* '.' */
  EW_GLYPH( 0x002F, -1, -9, 6, 10, 4, 0x00000863 ),             /* '/' */
  EW_GLYPH( 0x0030, 0, -9, 7, 9, 7, 0x000008FC ),               /* '0' */
  EW_GLYPH( 0x0031, 1, -9, 4, 9, 7, 0x000009BB ),               /* '1' */
  EW_GLYPH( 0x0032, 0, -9, 7, 9, 7, 0x00000A0C ),               /* '2' */
  EW_GLYPH( 0x0033, 0, -9, 7, 9, 7, 0x00000AFF ),               /* '3' */
  EW_GLYPH( 0x0034, 0, -9, 7, 9, 7, 0x00000BFA ),               /* '4' */
  EW_GLYPH( 0x0035, 0, -9, 7, 9, 7, 0x00000C9E ),               /* '5' */
  EW_GLYPH( 0x0036, 0, -9, 7, 9, 7, 0x00000D8F ),               /* '6' */
  EW_GLYPH( 0x0037, 0, -9, 7, 9, 7, 0x00000E7C ),               /* '7' */
  EW_GLYPH( 0x0038, 0, -9, 7, 9, 7, 0x00000F46 ),               /* '8' */
  EW_GLYPH( 0x0039, 0, -9, 7, 9, 7, 0x0000103E ),               /* '9' */
  EW_GLYPH( 0x003A, 0, -6, 3, 6, 4, 0x0000111E ),               /* ':' */
  EW_GLYPH( 0x003B, 0, -6, 3, 9, 3, 0x00001154 ),               /* ';' */
  EW_GLYPH( 0x003C, 0, -6, 6, 6, 6, 0x000011AF ),               /* '<' */
  EW_GLYPH( 0x003D, 0, -6, 7, 4, 7, 0x00001239 ),               /* '=' */
  EW_GLYPH( 0x003E, 0, -6, 6, 6, 6, 0x000012A6 ),               /* '>' */
  EW_GLYPH( 0x003F, 0, -9, 6, 9, 6, 0x00001339 ),               /* '?' */
  EW_GLYPH( 0x0040, 0, -8, 11, 11, 11, 0x000013FC ),            /* '@' */
  EW_GLYPH( 0x0041, 0, -9, 9, 9, 8, 0x000015DC ),               /* 'A' */
  EW_GLYPH( 0x0042, 0, -9, 8, 9, 8, 0x000016CE ),               /* 'B' */
  EW_GLYPH( 0x0043, 0, -9, 8, 9, 8, 0x000017B4 ),               /* 'C' */
  EW_GLYPH( 0x0044, 0, -9, 8, 9, 8, 0x000018C2 ),               /* 'D' */
  EW_GLYPH( 0x0045, 0, -9, 7, 9, 7, 0x00001983 ),               /* 'E' */
  EW_GLYPH( 0x0046, 0, -9, 7, 9, 7, 0x00001A23 ),               /* 'F' */
  EW_GLYPH( 0x0047, 0, -9, 8, 9, 8, 0x00001AB2 ),               /* 'G' */
  EW_GLYPH( 0x0048, 0, -9, 8, 9, 8, 0x00001BC8 ),               /* 'H' */
  EW_GLYPH( 0x0049, 0, -9, 3, 9, 4, 0x00001C4B ),               /* 'I' */
  EW_GLYPH( 0x004A, 0, -9, 7, 9, 7, 0x00001C74 ),               /* 'J' */
  EW_GLYPH( 0x004B, 0, -9, 8, 9, 8, 0x00001D01 ),               /* 'K' */
  EW_GLYPH( 0x004C, 0, -9, 7, 9, 7, 0x00001DCB ),               /* 'L' */
  EW_GLYPH( 0x004D, 0, -9, 10, 9, 11, 0x00001E2C ),             /* 'M' */
  EW_GLYPH( 0x004E, 0, -9, 8, 9, 8, 0x00001F2F ),               /* 'N' */
  EW_GLYPH( 0x004F, 0, -9, 8, 9, 8, 0x00001FD8 ),               /* 'O' */
  EW_GLYPH( 0x0050, 0, -9, 8, 9, 8, 0x000020D8 ),               /* 'P' */
  EW_GLYPH( 0x0051, 0, -9, 8, 11, 8, 0x00002192 ),              /* 'Q' */
  EW_GLYPH( 0x0052, 0, -9, 8, 9, 8, 0x000022CC ),               /* 'R' */
  EW_GLYPH( 0x0053, 0, -9, 8, 9, 8, 0x000023AA ),               /* 'S' */
  EW_GLYPH( 0x0054, 0, -9, 8, 9, 8, 0x000024E7 ),               /* 'T' */
  EW_GLYPH( 0x0055, 0, -9, 8, 9, 8, 0x00002570 ),               /* 'U' */
  EW_GLYPH( 0x0056, 0, -9, 8, 9, 8, 0x0000260E ),               /* 'V' */
  EW_GLYPH( 0x0057, -1, -9, 11, 9, 10, 0x000026FF ),            /* 'W' */
  EW_GLYPH( 0x0058, 0, -9, 8, 9, 8, 0x0000285A ),               /* 'X' */
  EW_GLYPH( 0x0059, 0, -9, 8, 9, 8, 0x00002965 ),               /* 'Y' */
  EW_GLYPH( 0x005A, 0, -9, 7, 9, 7, 0x00002A38 ),               /* 'Z' */
  EW_GLYPH( 0x005B, 0, -10, 4, 12, 3, 0x00002B0F ),             /* '[' */
  EW_GLYPH( 0x005C, -1, -9, 7, 10, 5, 0x00002B63 ),             /* '\' */
  EW_GLYPH( 0x005D, 0, -10, 3, 12, 3, 0x00002C1B ),             /* ']' */
  EW_GLYPH( 0x005E, 0, -9, 5, 4, 5, 0x00002C57 ),               /* '^' */
  EW_GLYPH( 0x005F, 0, 0, 6, 1, 5, 0x00002CAE ),                /* '_' */
  EW_GLYPH( 0x0060, 0, -9, 4, 2, 4, 0x00002CCC ),               /* '`' */
  EW_GLYPH( 0x0061, 0, -6, 7, 6, 6, 0x00002CEF ),               /* 'a' */
  EW_GLYPH( 0x0062, 0, -9, 7, 9, 7, 0x00002D92 ),               /* 'b' */
  EW_GLYPH( 0x0063, 0, -6, 6, 6, 6, 0x00002E2B ),               /* 'c' */
  EW_GLYPH( 0x0064, 0, -9, 7, 9, 7, 0x00002EC4 ),               /* 'd' */
  EW_GLYPH( 0x0065, 0, -6, 7, 6, 7, 0x00002F65 ),               /* 'e' */
  EW_GLYPH( 0x0066, -1, -9, 6, 9, 4, 0x0000301E ),              /* 'f' */
  EW_GLYPH( 0x0067, 0, -6, 7, 8, 7, 0x0000309B ),               /* 'g' */
  EW_GLYPH( 0x0068, 0, -9, 7, 9, 7, 0x00003159 ),               /* 'h' */
  EW_GLYPH( 0x0069, 0, -8, 3, 8, 3, 0x000031DC ),               /* 'i' */
  EW_GLYPH( 0x006A, -1, -8, 4, 10, 3, 0x0000321A ),             /* 'j' */
  EW_GLYPH( 0x006B, 0, -9, 7, 9, 7, 0x00003285 ),               /* 'k' */
  EW_GLYPH( 0x006C, 0, -9, 3, 9, 3, 0x00003330 ),               /* 'l' */
  EW_GLYPH( 0x006D, 0, -6, 10, 6, 10, 0x00003359 ),             /* 'm' */
  EW_GLYPH( 0x006E, 0, -6, 7, 6, 7, 0x000033F0 ),               /* 'n' */
  EW_GLYPH( 0x006F, 0, -6, 7, 6, 7, 0x00003458 ),               /* 'o' */
  EW_GLYPH( 0x0070, 0, -6, 7, 8, 7, 0x000034EB ),               /* 'p' */
  EW_GLYPH( 0x0071, 0, -6, 7, 8, 7, 0x0000358D ),               /* 'q' */
  EW_GLYPH( 0x0072, 0, -6, 5, 6, 5, 0x0000362D ),               /* 'r' */
  EW_GLYPH( 0x0073, 0, -6, 6, 6, 6, 0x00003675 ),               /* 's' */
  EW_GLYPH( 0x0074, 0, -8, 4, 8, 4, 0x0000372A ),               /* 't' */
  EW_GLYPH( 0x0075, 0, -6, 7, 6, 7, 0x00003787 ),               /* 'u' */
  EW_GLYPH( 0x0076, -1, -6, 8, 6, 6, 0x000037E8 ),              /* 'v' */
  EW_GLYPH( 0x0077, 0, -6, 9, 6, 9, 0x00003886 ),               /* 'w' */
  EW_GLYPH( 0x0078, 0, -6, 7, 6, 6, 0x00003959 ),               /* 'x' */
  EW_GLYPH( 0x0079, -1, -6, 8, 8, 6, 0x000039F4 ),              /* 'y' */
  EW_GLYPH( 0x007A, 0, -6, 6, 6, 6, 0x00003AC0 ),               /* 'z' */
  EW_GLYPH( 0x007B, 0, -9, 4, 11, 4, 0x00003B57 ),              /* '{' */
  EW_GLYPH( 0x007C, 1, -9, 2, 11, 3, 0x00003BE0 ),              /* '|' */
  EW_GLYPH( 0x007D, 0, -9, 4, 11, 4, 0x00003BFD ),              /* '}' */
  EW_GLYPH( 0x007E, 0, -5, 8, 3, 8, 0x00003C87 ),               /* '~' */
  EW_GLYPH( 0x00A0, 0, 0, 0, 0, 3, 0x00003CF5 ),
  EW_GLYPH( 0x00A1, 1, -6, 3, 8, 4, 0x00003CF5 ),
  EW_GLYPH( 0x00A2, 0, -8, 7, 10, 7, 0x00003D3E ),
  EW_GLYPH( 0x00A3, 0, -9, 7, 9, 7, 0x00003E29 ),
  EW_GLYPH( 0x00A4, 0, -8, 8, 8, 8, 0x00003EFF ),
  EW_GLYPH( 0x00A5, -1, -9, 9, 9, 7, 0x00003FF2 ),
  EW_GLYPH( 0x00A6, 0, -9, 3, 11, 3, 0x000040E8 ),
  EW_GLYPH( 0x00A7, 0, -9, 8, 11, 8, 0x00004130 ),
  EW_GLYPH( 0x00A8, 0, -8, 6, 1, 6, 0x000042B1 ),
  EW_GLYPH( 0x00A9, 0, -9, 9, 9, 9, 0x000042CC ),
  EW_GLYPH( 0x00AA, 0, -9, 5, 5, 5, 0x00004430 ),
  EW_GLYPH( 0x00AB, 0, -5, 6, 4, 6, 0x00004493 ),
  EW_GLYPH( 0x00AC, 1, -5, 5, 3, 7, 0x000044F3 ),
  EW_GLYPH( 0x00AD, 0, -4, 5, 1, 5, 0x00004528 ),
  EW_GLYPH( 0x00AE, 0, -9, 9, 9, 9, 0x00004541 ),
  EW_GLYPH( 0x00AF, 0, -9, 6, 1, 6, 0x0000469C ),
  EW_GLYPH( 0x00B0, 0, -9, 4, 3, 5, 0x000046B9 ),
  EW_GLYPH( 0x00B1, 0, -8, 6, 8, 6, 0x000046F2 ),
  EW_GLYPH( 0x00B2, 0, -9, 5, 5, 5, 0x00004781 ),
  EW_GLYPH( 0x00B3, 0, -9, 5, 5, 5, 0x000047FC ),
  EW_GLYPH( 0x00B4, 0, -9, 4, 2, 4, 0x00004872 ),
  EW_GLYPH( 0x00B5, 0, -6, 7, 8, 8, 0x00004897 ),
  EW_GLYPH( 0x00B6, 0, -9, 6, 9, 6, 0x00004911 ),
  EW_GLYPH( 0x00B7, 0, -5, 3, 1, 4, 0x0000498F ),
  EW_GLYPH( 0x00B8, 0, 0, 3, 3, 3, 0x000049A1 ),
  EW_GLYPH( 0x00B9, 1, -9, 3, 5, 5, 0x000049CB ),
  EW_GLYPH( 0x00BA, 0, -9, 5, 5, 6, 0x000049FA ),
  EW_GLYPH( 0x00BB, 0, -5, 6, 4, 6, 0x00004A6D ),
  EW_GLYPH( 0x00BC, 0, -9, 9, 9, 9, 0x00004ACB ),
  EW_GLYPH( 0x00BD, 0, -9, 10, 9, 9, 0x00004BDA ),
  EW_GLYPH( 0x00BE, 0, -9, 10, 9, 10, 0x00004D08 ),
  EW_GLYPH( 0x00BF, 0, -6, 6, 8, 6, 0x00004E66 ),
  EW_GLYPH( 0x00C0, 0, -11, 9, 12, 8, 0x00004F16 ),
  EW_GLYPH( 0x00C1, 0, -11, 9, 12, 8, 0x0000504A ),
  EW_GLYPH( 0x00C2, 0, -11, 9, 12, 8, 0x00005180 ),
  EW_GLYPH( 0x00C3, 0, -11, 9, 12, 8, 0x000052C6 ),
  EW_GLYPH( 0x00C4, 0, -11, 9, 11, 8, 0x0000540E ),
  EW_GLYPH( 0x00C5, 0, -11, 9, 13, 8, 0x0000553C ),
  EW_GLYPH( 0x00C6, 0, -9, 11, 9, 11, 0x0000568A ),
  EW_GLYPH( 0x00C7, 0, -9, 8, 12, 8, 0x000057AC ),
  EW_GLYPH( 0x00C8, 0, -11, 7, 12, 7, 0x00005900 ),
  EW_GLYPH( 0x00C9, 0, -11, 7, 12, 7, 0x000059DC ),
  EW_GLYPH( 0x00CA, 0, -11, 7, 12, 7, 0x00005ABA ),
  EW_GLYPH( 0x00CB, 0, -11, 7, 11, 7, 0x00005BA8 ),
  EW_GLYPH( 0x00CC, -1, -11, 4, 12, 4, 0x00005C80 ),
  EW_GLYPH( 0x00CD, 0, -11, 4, 12, 4, 0x00005CE5 ),
  EW_GLYPH( 0x00CE, -1, -11, 6, 12, 4, 0x00005D4C ),
  EW_GLYPH( 0x00CF, -1, -11, 6, 11, 4, 0x00005DDB ),
  EW_GLYPH( 0x00D0, -1, -9, 9, 9, 8, 0x00005E55 ),
  EW_GLYPH( 0x00D1, 0, -11, 8, 12, 8, 0x00005F33 ),
  EW_GLYPH( 0x00D2, 0, -11, 8, 12, 8, 0x0000602F ),
  EW_GLYPH( 0x00D3, 0, -11, 8, 12, 8, 0x0000616E ),
  EW_GLYPH( 0x00D4, 0, -11, 8, 12, 8, 0x000062AF ),
  EW_GLYPH( 0x00D5, 0, -11, 8, 12, 8, 0x00006400 ),
  EW_GLYPH( 0x00D6, 0, -11, 8, 11, 8, 0x00006553 ),
  EW_GLYPH( 0x00D7, 0, -7, 6, 6, 6, 0x0000668D ),
  EW_GLYPH( 0x00D8, 0, -10, 8, 11, 8, 0x00006724 ),
  EW_GLYPH( 0x00D9, 0, -11, 8, 12, 8, 0x0000686C ),
  EW_GLYPH( 0x00DA, 0, -11, 8, 12, 8, 0x00006949 ),
  EW_GLYPH( 0x00DB, 0, -11, 8, 12, 8, 0x00006A28 ),
  EW_GLYPH( 0x00DC, 0, -11, 8, 11, 8, 0x00006B17 ),
  EW_GLYPH( 0x00DD, 0, -11, 8, 12, 8, 0x00006BEF ),
  EW_GLYPH( 0x00DE, 0, -9, 7, 9, 7, 0x00006D03 ),
  EW_GLYPH( 0x00DF, 0, -9, 8, 9, 8, 0x00006DA2 ),
  EW_GLYPH( 0x00E0, 0, -9, 7, 9, 6, 0x00006E6E ),
  EW_GLYPH( 0x00E1, 0, -9, 7, 9, 6, 0x00006F4D ),
  EW_GLYPH( 0x00E2, 0, -9, 7, 9, 6, 0x0000702E ),
  EW_GLYPH( 0x00E3, 0, -9, 7, 9, 6, 0x0000711F ),
  EW_GLYPH( 0x00E4, 0, -8, 7, 8, 6, 0x00007212 ),
  EW_GLYPH( 0x00E5, 0, -10, 7, 10, 6, 0x000072ED ),
  EW_GLYPH( 0x00E6, 0, -6, 10, 6, 10, 0x000073E4 ),
  EW_GLYPH( 0x00E7, 0, -6, 6, 9, 6, 0x00007508 ),
  EW_GLYPH( 0x00E8, 0, -9, 7, 9, 7, 0x000075DB ),
  EW_GLYPH( 0x00E9, 0, -9, 7, 9, 7, 0x000076D0 ),
  EW_GLYPH( 0x00EA, 0, -9, 7, 9, 7, 0x000077C7 ),
  EW_GLYPH( 0x00EB, 0, -8, 7, 8, 7, 0x000078CE ),
  EW_GLYPH( 0x00EC, -1, -9, 4, 9, 3, 0x000079BF ),
  EW_GLYPH( 0x00ED, 0, -9, 4, 9, 3, 0x00007A18 ),
  EW_GLYPH( 0x00EE, -1, -9, 6, 9, 3, 0x00007A73 ),
  EW_GLYPH( 0x00EF, -1, -8, 6, 8, 3, 0x00007AF0 ),
  EW_GLYPH( 0x00F0, 0, -9, 7, 9, 7, 0x00007B58 ),
  EW_GLYPH( 0x00F1, 0, -9, 7, 9, 7, 0x00007C4D ),
  EW_GLYPH( 0x00F2, 0, -9, 7, 9, 7, 0x00007D05 ),
  EW_GLYPH( 0x00F3, 0, -9, 7, 9, 7, 0x00007DD4 ),
  EW_GLYPH( 0x00F4, 0, -9, 7, 9, 7, 0x00007EA5 ),
  EW_GLYPH( 0x00F5, 0, -9, 7, 9, 7, 0x00007F86 ),
  EW_GLYPH( 0x00F6, 0, -8, 7, 8, 7, 0x00008069 ),
  EW_GLYPH( 0x00F7, 0, -7, 7, 5, 7, 0x00008134 ),
  EW_GLYPH( 0x00F8, 0, -7, 7, 8, 7, 0x000081B2 ),
  EW_GLYPH( 0x00F9, 0, -9, 7, 9, 7, 0x0000827F ),
  EW_GLYPH( 0x00FA, 0, -9, 7, 9, 7, 0x0000831C ),
  EW_GLYPH( 0x00FB, 0, -9, 7, 9, 7, 0x000083BB ),
  EW_GLYPH( 0x00FC, 0, -8, 7, 8, 7, 0x0000846A ),
  EW_GLYPH( 0x00FD, -1, -9, 8, 11, 6, 0x00008503 ),
  EW_GLYPH( 0x00FE, 0, -9, 7, 11, 7, 0x00008610 ),
  EW_GLYPH( 0x00FF, -1, -8, 8, 10, 6, 0x000086CC ),

  EW_FONT_PIXEL( CutterDescrFont, 0x000087D2 )                  /* ratio 79.39 % */
    0xD6FDEF75, 0xC61B67B9, 0x13FC0F90, 0x0C1F24FF, 0xCF73AC63, 0x384DF75E, 0xF71C8098,
    0xEF7EBBA9, 0x291C75EF, 0xC61F5EE8, 0xDCF7FFFF, 0x3DFE9EFA, 0x27FFD77F, 0xCEFFA532,
    0x6BFE3BBF, 0xF21DCFBD, 0x3CCCC49C, 0x60778120, 0x7F933AEC, 0x888EF59E, 0xC89F3B11,
    0x9D3FF391, 0xFF6313DC, 0xCFFCDB7E, 0xC6B319E7, 0xE2FE6527, 0x3FCF2AD6, 0xE209C36F,
    0xD6B03F77, 0x407C6A7D, 0xF75AC3DC, 0x7E22CFF9, 0xF01F9FB7, 0x61FDDF7E, 0xC3E679CA,
    0xF2FC05FF, 0xF23E6799, 0x77817F77, 0x8531A79E, 0x17BFCA81, 0xE572FE47, 0x9EDFA5D3,
    0xE2B959DB, 0x9E1DFE39, 0xA79E6B58, 0x613FBD6A, 0x6DF1AF50, 0x7F513CFD, 0x1048478F,
    0xF511E3D2, 0xF8C79FA7, 0xBFB0FBF6, 0x1ECD3CF2, 0x0E91E3C3, 0xF1E3C748, 0xB6A9E31F,
    0x58B7C2BF, 0xE7ADE71D, 0xDC9FFD56, 0x75EC231D, 0x77807207, 0x2DDF8007, 0x96EFC6E7,
    0xBBC00373, 0xE21F7183, 0x88CCE789, 0xE793EF7B, 0x16E073C5, 0xC288C6D4, 0x90AA246F,
    0x818A87E3, 0xA173C17F, 0x7C43DDF6, 0xD8ABFAEB, 0x95C49E2A, 0xAC824000, 0xFC5476D8,
    0xC8FF5DD7, 0x7FFBEDF9, 0x0001FFE2, 0xDFF9E000, 0xBADF197F, 0x66B9F8BE, 0x23C7DF64,
    0x9E0CC6F1, 0xC5F8CD99, 0x1DE27109, 0x2EF7D4CC, 0xE5FFB9EF, 0x1ECEF7C9, 0x78116FCF,
    0xF783BD6F, 0x17E1378E, 0xA2037EB5, 0xB358BF3E, 0x607FAEEB, 0x05F21FDD, 0x22F1AC07,
    0x62F855DF, 0xBDF6F56D, 0x8000BD5B, 0x86F7BDFF, 0x846F7BAC, 0x7FCEB484, 0xF13BF7CA,
    0x53F2CC66, 0x6DD00D63, 0xBADF1AC7, 0xEFC60BEB, 0xEF3B3C3C, 0xC1BC6FC3, 0xA5A7FE13,
    0xC3D67FF5, 0x7813FC76, 0xF9FAE7E2, 0xF1BEBBAF, 0xBBDEF7BB, 0xE1DEF77E, 0xF89518C1,
    0x60F1581C, 0x87CF82C6, 0xE7C0C631, 0xFFBFF583, 0xECEE3B25, 0xEF911021, 0xBC66F5B8,
    0x57378EE3, 0x00A2FCFC, 0xA8BF3F15, 0xA5F8DCFC, 0xF297F7DA, 0x4F5D775B, 0x10164F6C,
    0x3F464B65, 0xF3AC25FF, 0x3F1E8517, 0x47BF19C6, 0x0BCF379E, 0xE79BCF20, 0x1802F3CD,
    0x789E21F7, 0x2F640CCE, 0xDF2FFBF5, 0x80BDAE6F, 0x5ED737EF, 0xC65FF7EA, 0x18DEF7BD,
    0x037BDEF7, 0xF7BDEE30, 0x980EF3C6, 0xFE78F7FB, 0xC10FBEBD, 0x7DF9EFF3, 0x7C3DFEE6,
    0x7E7EB4E7, 0x2B239AEF, 0xFE3FDFDD, 0xD2F99A82, 0xE06A304E, 0x81F3887E, 0x0DF3DFFE,
    0xCF7BCEC4, 0xFCDF17FE, 0xBF1FF3BE, 0xE7AF5657, 0x4633FFCE, 0x989EFC8D, 0x3CA770D7,
    0x338821A4, 0xA6718D52, 0x7D7EBD9E, 0xFCF31CAC, 0xDE21ECFA, 0xAB0190F3, 0x4127B9CF,
    0x0AC03B9C, 0x0F17F03F, 0x03958D44, 0x3E1F5D4B, 0xF0E4597B, 0xD63CA23B, 0x67E3AFBD,
    0xF7B8CA53, 0xDE40DF9E, 0x8E41FCFD, 0x06239018, 0x22F1FF79, 0xA01ECDEF, 0x7916504C,
    0xDE297C6F, 0x6F837E73, 0x39FEBBED, 0xF17E32AA, 0x133AC194, 0x86220088, 0x46B33AC1,
    0xF1E2FC65, 0x7FAEFB5F, 0x3DDEF73E, 0x5DEFEEA1, 0x3C0BC560, 0x04008051, 0xC560A278,
    0x77BFBA8B, 0xF7BDEE79, 0xBBDEEA2E, 0xDEEA0000, 0x02F7BA8B, 0xEF7BA800, 0xF7BDEE7A,
    0xF7BDD43E, 0x7BA80001, 0x0BDEEA2F, 0xEF880000, 0x5FE0DF9C, 0xF1FEBBFF, 0x8BF11A8C,
    0xDD67F7F5, 0xAEF7B819, 0x0EFE6DC0, 0xFE1AC678, 0xCEFFD7F8, 0x31FDCF5E, 0x00000FEE,
    0x4377BA80, 0x0001BBDD, 0x0FF71800, 0xFF000000, 0x0000003B, 0xF1011000, 0xE463159E,
    0x39F7BCF7, 0xBFF3FDC6, 0x31A39D0D, 0x3AB81C56, 0xA900C391, 0x85C8F621, 0xA80DED11,
    0x0FEE7E8A, 0x00000000, 0xF7500000, 0xBBDCF1DE, 0x9B1FEE70, 0xFF0A880A, 0x03D4B280,
    0x0DC8F723, 0xC145FA9E, 0x027AC5F8, 0x007FA462, 0x7EF7858F, 0x0CF177BC, 0x0AA30340,
    0xF460D17C, 0x00666058, 0xE206780D, 0xF60BE73B, 0x336D7BBA, 0xE727C89F, 0x076FE7F6,
    0xF6C40110, 0x7CCF6FE7, 0xF69C9F32, 0xE36D7BDA, 0x857F7BDE, 0x097E67BA, 0xF1E05151,
    0x06FAF750, 0x007EEF75, 0xEF880000, 0xEBD82F9C, 0x7CCDB5EE, 0xDB9C9F22, 0x401DBF9F,
    0x9FDB1004, 0xC9F33DBF, 0x6BDA727C, 0xEF88B3FF, 0xF1059A9C, 0xBDEE35DB, 0x7BA83F77,
    0x69884BE2, 0xA878CC42, 0xEA0EC67B, 0x7CF80466, 0xB202B1E0, 0xDCEFCA62, 0xFF3EE0DF,
    0x1911FF33, 0x5195BE23, 0x877AC5F1, 0x06FBAF5F, 0xB6B7FFD6, 0x93CF3FBA, 0xA693E54F,
    0xF1BED6E9, 0xF7BDDF8D, 0xEEFCFBDE, 0x003EF756, 0x00000000, 0xFDCF0000, 0x000FBBF1,
    0x40000000, 0x23395100, 0xEF3B9666, 0x93BED79D, 0x66CFF779, 0xF28A3DFB, 0x188E4664,
    0xE294F1E9, 0x18FDBFE7, 0x540E4F59, 0x0F9FC144, 0xF70E72E7, 0x91118C78, 0x0F9863C3,
    0xFDFC31EB, 0x5B63FF2F, 0x863919F2, 0x678D6329, 0x4F244F3D, 0xC1E23BDA, 0xFC0C3D60,
    0xBDB08E45, 0xFADCE3F7, 0xAA8AE545, 0x34FBF19C, 0x067CCC6F, 0xC588B8B1, 0x2ACAC741,
    0x69FDE2B9, 0x8C662B1D, 0xFB2777E7, 0xC637F5D6, 0x5E351AA8, 0xC6B7AF2F, 0xF89E33C3,
    0x1E1313E0, 0xEF000003, 0xF3DEF7BD, 0x17877BDE, 0xF685C8CF, 0x8931CAC3, 0x8AA3A357,
    0xD85F1A5C, 0xDEE7DEF7, 0x0000F987, 0xF3000000, 0x8F01BFF1, 0x183F3F09, 0x7CFC2463,
    0x472078F0, 0xB07CF80E, 0xFA8A882C, 0x0001DFDF, 0xF3070000, 0xA9F8BE4E, 0xCFBACFF1,
    0xF7BDEE78, 0xA7E751DE, 0x9DFA8D7A, 0x3BF54BFB, 0x9DF15EBB, 0x0FA7EA6D, 0xEBA0F186,
    0xF73C31BB, 0xE7800005, 0x5FEB1A7F, 0x00DB48AB, 0x7F81B690, 0xFCE7D2AD, 0x57FEAD62,
    0x3FBE356F, 0x9E55B3D4, 0xEBBD5ADF, 0x003BBF07, 0x93FE7D00, 0xF83FD567, 0xED8016BB,
    0xFFAAD45A, 0xFFDFFCC2, 0xCEE7DEA3, 0x56EB6E5F, 0xBDEF7844, 0x7E33EFE3, 0x1FCF73EA,
    0x3F06FFCF, 0xE24C6437, 0xEAD8AEAF, 0xB0000002, 0xE7DDF9CE, 0xDFC13AE9, 0xD76C0035,
    0x13FEBAA0, 0xD962FF71, 0x9F2FAEF7, 0xC00002FB, 0xE62F3FF3, 0x218399FF, 0xB000004D,
    0xB3EEB3EE, 0x780002EE, 0xE5DCF2EE, 0x00002FB9, 0x3EF7E748, 0x0005DD73, 0x8339C600,
    0x3307FC73, 0x0CC440E7, 0x770F8ECC, 0x7DCF9A8E, 0xDE000001, 0xFACFFEFB, 0x1D9C1DDD,
    0x6498F5FD, 0x0000E910, 0xFDCF0000, 0xF887EFFD, 0xD21833D7, 0xD6000004, 0xF4F2EEFF,
    0x6DB17D73, 0xB6D80515, 0xB9FA7A8A, 0xFEEE78BE, 0xD7FAC69F, 0x0036D22A, 0xFEB06DA4,
    0x3FF3C5D5, 0xFF9F400B, 0xEAB53EEF, 0x004B618F, 0xD75496C3, 0xFF9D617F, 0xBDDC6003,
    0x32FFE25F, 0xBE200003, 0x7DE37E73, 0xEF1C7DBE, 0x55FCC62F, 0xEF1CE6FD, 0x7CFB3EEB,
    0x03FB8F4F, 0xFAB7FD5B, 0x67258403, 0xDEBEE7EE, 0x800000FB, 0xD66A0C30, 0xF237FE1F,
    0x795479FE, 0x8FDBD9F8, 0xE0635591, 0xC3C1F8CB, 0x73C77BC3, 0xCF6F6EAB, 0x9CBFD3B6,
    0xC8AAE7CA, 0x846B3B27, 0x8B327CCA, 0xFAFE51ED, 0x3A7F71AE, 0xC5F9ABDF, 0x89208398,
    0xC74AAB37, 0x7FE68DEF, 0x479FEF33, 0xFF9F8795, 0x4F18C7DF, 0xFE17E255, 0x620988F0,
    0x1A7FF3C1, 0xBF7BDEEB, 0xCD11FF75, 0x1ACD331B, 0x6F2E3A2D, 0xDE3FBEC4, 0x061967A5,
    0xB2FC7CC1, 0x0F99B2FD, 0x59E86182, 0x60000037, 0xCB4F3C7D, 0x749CC01C, 0xCCFE74FE,
    0x67873209, 0xF2BCEB36, 0xCEFEF197, 0x53C727AA, 0xFF6DDFEB, 0x8375BFED, 0x01CC04BC,
    0x3C0BE01E, 0xBF91FB7F, 0x62A7E379, 0xA5903FBB, 0xE46EFB62, 0x0BF9DE6F, 0xE07EDFCF,
    0xFCE7580B, 0x7AED7552, 0x8DDCFF0D, 0xADA78C6B, 0xBCDA78FB, 0x83A4090F, 0x7FBDF5A7,
    0xCF7BF980, 0x3D737F79, 0xAB3C6F71, 0x2B3A23B2, 0x3C72781F, 0x1D93E4F0, 0x715559D1,
    0xB7D9546F, 0xE3B4DDD4, 0xD46AAA68, 0xB89C7428, 0x07B4B678, 0x077D6DCF, 0x077D6DCF,
    0x077D6DCF, 0x003EE300, 0xEE33EE30, 0xEFC60003, 0x3FF82F9C, 0x227CFFF7, 0x629A8C46,
    0x9FDF8F64, 0xCB3FF995, 0x764EF8A8, 0xCEFF958E, 0x0CDE7D4A, 0x2FADFFC6, 0x1158C62B,
    0xB9FFC323, 0xE4EA39F7, 0xDFFAC938, 0x7B9EF13D, 0x7E865ECF, 0x7F3B7F6F, 0x1CDF77BF,
    0xE94664FD, 0x4A332791, 0xDFBF3C8F, 0xFA39BBFB, 0xFEDCFA19, 0xBDCF7A76, 0xEFB12F67,
    0x239DF627, 0x7728777E, 0xFE3079A8, 0x7CE33FCF, 0xCE204BFD, 0xF7BCBFD7, 0x77BDFFDE,
    0x7DEF7103, 0x27BBFF58, 0xD9EF73DE, 0xEFFDF0CB, 0xFDFCEDFB, 0x93F46BCC, 0xE467DE69,
    0x8D6F34C9, 0xC61FBF3C, 0x7EF867EA, 0xF7A7677E, 0x12F67BDC, 0x7C3BDEF7, 0xEF388D67,
    0xFEF2F388, 0xCB759321, 0xEE5BAFFD, 0x0EF8001F, 0xFEE73DCF, 0x4F3F77E2, 0x5F519FFC,
    0x7F9BE18F, 0x13CE33CF, 0xF78CFEFB, 0x393AC8D4, 0xC4F93CC6, 0xEEF954EF, 0xB89EB193,
    0x00FF717F, 0x09118000, 0xF67185EE, 0xFFD403FD, 0x625F91DE, 0x10150005, 0xFDF2167B,
    0xFFF88000, 0x7DC756FA, 0x73EF1DC6, 0xE800FF96, 0xF39F33B3, 0x72A9CDFB, 0x9CF9954E,
    0x9FFC6FDF, 0xFBCF1A7F, 0xDE78C01C, 0x00BF50E7, 0x23F116F1, 0xA81B7E36, 0xFB78C0B9,
    0x57F712FF, 0xFEA301FF, 0xFDEF82CF, 0xB783398F, 0xA8673BDE, 0x96F1005F, 0x7E6C41F8,
    0x02E6B01B, 0xFDDF8DF4, 0x13C6B988, 0xF51867FF, 0xC397EFAA, 0x367BE2F7, 0xE33CF16F,
    0x0FEFB13C, 0x21A9EF18, 0x1C9D647E, 0x4F319B7E, 0xF117353E, 0xFEDEB53B, 0xDFDF72BF,
    0x8C03FEAF, 0x7C0B3FFA, 0x19CC7FEF, 0x73BDEB78, 0xFA067D06, 0xA837BC0C, 0x1CF8C235,
    0x9AE6F17E, 0x9CFFEA87, 0x3AAF57EF, 0x0D7AA03F, 0xC401EE60, 0xF0AC03B9, 0x40F17F03,
    0xB03958D4, 0xB3E1F5D4, 0xBF0E4597, 0xDD63CA23, 0x367E3AFB, 0x1F77C0A5, 0x901EB190,
    0xEE7106BF, 0xC0FC2B00, 0x35103C5F, 0x752C0E56, 0x65ECF87D, 0x88EFC391, 0xBEF758F2,
    0x294D9F8E, 0x6414FFD4, 0xB913B33F, 0x9C4277BB, 0x3F0AC03B, 0x440F17F0, 0x4B03958D,
    0x7B3E1F5D, 0x3BF0E459, 0xBDD63CA2, 0x5367E3AF, 0x2717FB0A, 0x815DDE50, 0x40FFF9DA,
    0x0AC03B9C, 0x0F17F03F, 0x03958D44, 0x3E1F5D4B, 0xF0E4597B, 0xD63CA23B, 0x67E3AFBD,
    0x393A8A53, 0x8E4EA24E, 0x0EE71093, 0xFC0FC2B0, 0x635103C5, 0xD752C0E5, 0x165ECF87,
    0x288EFC39, 0xEBEF758F, 0x8294D9F8, 0xF6300BEF, 0x2DF6302D, 0xC402FBE0, 0xF0AC03B9,
    0x40F17F03, 0xB03958D4, 0xB3E1F5D4, 0xBF0E4597, 0xDD63CA23, 0x367E3AFB, 0xF7BEC0A5,
    0x8350BBDE, 0x1B42EF7D, 0x1EA31816, 0xDDF35A01, 0xFA7B28CB, 0x6E75E5EE, 0x0233E44B,
    0xBEA47ED0, 0x73DE2FF7, 0xED6F837E, 0xAA39FEBB, 0x94F17E32, 0x88133AC1, 0xC1862200,
    0x6546B33A, 0x5FF1E2FC, 0x8A7FAEFB, 0xD01DC677, 0x2E33C171, 0x7AA0FCEA, 0xF07B980D,
    0x5DEF7BDC, 0x0177BDD4, 0x17BDD400, 0x0005EF75, 0x85DEF750, 0x58C83EEF, 0x3CD7F20F,
    0x177BDEF7, 0x005DEF75, 0x45EF7500, 0x00017BDD, 0x5177BDD4, 0x3F6453FF, 0xEEEE53B3,
    0xF7BDCF9D, 0x7BDD45DE, 0xDD400017, 0x5EF7517B, 0xEF750000, 0x38E4EA5D, 0x938E4EA9,
    0xDEF7BDCF, 0x177BDD45, 0x7BDD4000, 0x005EF751, 0x5DEF7500, 0xD7AA7E75, 0xEE30F730,
    0x0000001F, 0x8C9F77C0, 0x8DAFE4F5, 0x000007FB, 0xA7FEA000, 0x33B33F64, 0xE34EF777,
    0x000001FE, 0xA8000000, 0x9D64E393, 0xFB8D271C, 0x00000007, 0xDC400000, 0xE40BFF7B,
    0xA7817EED, 0xE2A90266, 0x1C441BC8, 0x2A400379, 0xC81CD4F0, 0xFF62FDDB, 0xDDE504E2,
    0xFFCED415, 0xDE3F7BC7, 0xA00678BB, 0xBE055181, 0x2C7A3068, 0x06803330, 0xFCEA033C,
    0x601AF540, 0xCEF881EE, 0xEEBD82F9, 0x27CCDB5E, 0xFDB9C9F2, 0x4401DBF9, 0xF9FDB100,
    0xCC9F33DB, 0xF6BDA727, 0xF77C1B5E, 0x40F58C81, 0x9DF11AFE, 0xDD7B05F3, 0x4F99B6BD,
    0xFB7393E4, 0x8803B7F3, 0xF3FB6200, 0x993E67B7, 0xED7B4E4F, 0x7FEA36BD, 0xECCFD90A,
    0x4EF77724, 0x0BE73BE2, 0x6D7BBAF6, 0x27C89F33, 0x6FE7F6E7, 0xC4011007, 0xCF6FE7F6,
    0x9C9F327C, 0x6D7BDAF6, 0xA09C5FEC, 0xDA82BBBC, 0xDF10FFF9, 0xD7B05F39, 0xF99B6BDD,
    0xB7393E44, 0x803B7F3F, 0x3FB62008, 0x93E67B7F, 0xD7B4E4F9, 0x27536BDE, 0xE4EA49C7,
    0xE77C4938, 0x775EC17C, 0x13E66DAF, 0xFEDCE4F9, 0x2200EDFC, 0xFCFED880, 0xE64F99ED,
    0x7B5ED393, 0xA17F2DAF, 0x5EBE7CE7, 0xF3D6BABB, 0x9EB5D501, 0xAF5F3E6F, 0xCFA08C0D,
    0xEB7E1DF9, 0x518C6BBF, 0xBF119E35, 0xE0F6BE92, 0x39C08F59, 0x4D667949, 0x4E7C6A35,
    0x8F78E4FC, 0x9CFB3A7F, 0x0FCEA0DF, 0xE601AF54, 0x8FEE781E, 0x00007DDF, 0x02000000,
    0x3119CA88, 0xEF79DCB3, 0x0FBBE0BC, 0xF207AC64, 0xC7F73CD7, 0x00003EEF, 0x01000000,
    0x988CE544, 0x77BCEE59, 0x14FFD45E, 0x49D99FB2, 0x9E9DEEEE, 0x1F77E3FB, 0x00000000,
    0x72A20080, 0x772CCC46, 0x752F3BDE, 0x4EA49C72, 0xFB9E938E, 0x001F77E3, 0x80000000,
    0x4672A200, 0xDE772CCC, 0xF77C2F3B, 0x40F58C81, 0x3BBF1AFE, 0xBFAEB7D9, 0xA8D54631,
    0xBD797AF1, 0xF19E1E35, 0x989F07C4, 0x000018F0, 0x80017758, 0xDF45E7BE, 0x052C2F9E,
    0xE7B7D14B, 0x02F3DF4B, 0x8D39DFC8, 0x1EB5DCF3, 0x60904631, 0x5E018099, 0x9CCD6037,
    0xEFA04708, 0x3F3AA73B, 0xE6035EA8, 0xDCEFD41E, 0xD9DFAA5F, 0x6CEF8AF5, 0x307D3F53,
    0xDF5D078C, 0x7DDF018D, 0xE41EB190, 0xB9DFA9AF, 0xB3BF54BF, 0xD9DF15EB, 0x60FA7EA6,
    0xBEBA0F18, 0x9FFA831B, 0x9D99FB22, 0x54EF7772, 0xA97F73BF, 0x2BD7677E, 0xFD4DB3BE,
    0x1E30C1F4, 0x06377D74, 0x942717FB, 0x9DA85777, 0x9DFA8FFF, 0x3BF54BFB, 0x9DF15EBB,
    0x0FA7EA6D, 0xEBA0F186, 0xC9D431BB, 0x1C9D5271, 0xDCEFD527, 0xD9DFAA5F, 0x6CEF8AF5,
    0x307D3F53, 0xDF5D078C, 0x0BEF818D, 0x630B7D8C, 0x0BEF82DF, 0x2FEE77EA, 0x7AECEFD5,
    0xA9B677C5, 0xC6183E9F, 0xC6EFAE83, 0xFEFFEF90, 0x997F73BF, 0xF3C6FFEF, 0xEF8DEBFD,
    0x37F7E1DC, 0xF2DE67DF, 0xB5CFF7BF, 0xD6F18CFC, 0xEEB59E7B, 0x5F9CFA9D, 0xEAFFD5AC,
    0x87F7C6AD, 0xF3CAB67A, 0xFD77AB5B, 0x741B8CF4, 0x52E33C5C, 0x6BD507E7, 0xF303DCC0,
    0x7A8FFF7F, 0xB97F3B9F, 0xE1115BAD, 0xBF8EF7BD, 0xCFA9F8CF, 0xEEF87F3D, 0x20F58C83,
    0xBFF98D7F, 0xCFBD47FF, 0xD6DCBF9D, 0xDEF088AD, 0x67DFC77B, 0x9EE7D4FC, 0x453FF53F,
    0xE53B33F6, 0xFCC9DEEE, 0xDEA3FFDF, 0x6E5FCEE7, 0x784456EB, 0xEFE3BDEF, 0x73EA7E33,
    0x1C9D5FCF, 0x71C9D527, 0xFFBFF992, 0x9DCFBD47, 0xADD6DCBF, 0x7BDEF088, 0xFC67DFC7,
    0xBF9EE7D4, 0x6BD53F3A, 0xF7187B98, 0xBE000007, 0x27AC64FB, 0x1FDC6D7F, 0xFF500000,
    0xD99FB253, 0xA77BBB99, 0x00007F71, 0x72750000, 0xE393AC9C, 0x007F71A4, 0xC6000000,
    0x5A88B3BF, 0x2FCF24FF, 0x1BF7AC7E, 0xCE7E8CF9, 0x812D9767, 0xFED89E21, 0xEEB7E5F1,
    0xC5FED2FA, 0x15DDE509, 0xE3FFE76A, 0xFDFFBFB9, 0x067AFF10, 0x00009A43, 0x541F9D40,
    0x0F7301AF, 0xE5DDFFAC, 0x62FAE7E9, 0xB00A2ADB, 0xF4F5156D, 0xEF817D73, 0x0F58C83E,
    0xFF58D7F2, 0xCFD3CBBB, 0x55B6C5F5, 0x2ADB6014, 0xFAE7E9EA, 0x914FFD42, 0xB94ECCFD,
    0xFEB277BB, 0x9FA79777, 0xAB6D8BEB, 0x55B6C028, 0xF5CFD3D4, 0x138BFD85, 0xD42BBBCA,
    0xF587FFCE, 0xFD3CBBBF, 0x5B6C5F5C, 0xADB60145, 0xAE7E9EA2, 0x38E4EA2F, 0x938E4EA9,
    0xE5DDFFAC, 0x62FAE7E9, 0xB00A2ADB, 0xF4F5156D, 0xBAC17D73, 0xEF16EB05, 0xF5DEF7BD,
    0x5DEF7BDE, 0x2D405BAC, 0xE17EFFD6, 0x6C75A7E9, 0xEC515BFB, 0x54F36C15, 0xF9F8F3D4,
    0x1777B8C2, 0xBD507E75, 0x783DCC06, 0x0FBDEBEE, 0xC3080000, 0x81FD66A0, 0x58C83EEF,
    0x3CD7F20F, 0x07DEF5F7, 0x61840000, 0x50FEB350, 0x3F6453FF, 0xEEEE53B3, 0x7AFB9E9D,
    0x000003EF, 0x59A830C2, 0x71C9D47F, 0x271C9D52, 0xDEF5F73D, 0x84000007, 0xFEB35061,
    0x903EEF80, 0x5FC81EB1, 0xEF337FE3, 0x8795479F, 0xC7DFFF9F, 0xE2554F18, 0x88F0FE17,
    0xF3C16209, 0xBEE31A7F, 0xFCF00000, 0x6BFD634F, 0x001B6915, 0xFF5836D2, 0x9FF9E2EA,
    0x8E4EA005, 0x71C9D493, 0xBCCDFF92, 0x1E551E7F, 0x1F7FFE7E, 0x89553C63, 0x23C3F85F,
    0xCF058826, 0x000069FF

  EW_FONT_KERNING_CODES( CutterDescrFont )
  EW_FONT_KERNING_VALUES( CutterDescrFont )
EW_END_OF_FONT_RES( CutterDescrFont )

/* Embedded Wizard */
