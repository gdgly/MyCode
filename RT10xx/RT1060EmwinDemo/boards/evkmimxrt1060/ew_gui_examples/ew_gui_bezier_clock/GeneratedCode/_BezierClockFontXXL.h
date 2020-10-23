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

/* Font resource used per default by 'Text' and 'Attributed Text' views to ensure 
   that new views don't remain empty on the screen. */
EW_DEFINE_FONT_RES( BezierClockFontXXL, 32, 8, 0, 16, 0x0001, 0x0060 )
  EW_GLYPH( 0x0001, 1, -23, 13, 23, 15, 0x00000000 ),
  EW_GLYPH( 0x0020, 0, 0, 0, 0, 8, 0x0000031B ),                /* ' ' */
  EW_GLYPH( 0x0021, 2, -23, 3, 23, 7, 0x0000031B ),             /* '!' */
  EW_GLYPH( 0x0022, 2, -25, 6, 7, 9, 0x000003A8 ),              /* '"' */
  EW_GLYPH( 0x0023, 1, -23, 19, 23, 19, 0x0000040F ),           /* '#' */
  EW_GLYPH( 0x0024, 1, -27, 16, 30, 18, 0x00000822 ),           /* '$' */
  EW_GLYPH( 0x0025, 1, -23, 22, 23, 24, 0x00000CC5 ),           /* '%' */
  EW_GLYPH( 0x0026, 1, -23, 19, 23, 20, 0x000011D8 ),           /* '&' */
  EW_GLYPH( 0x0027, 1, -25, 3, 7, 6, 0x000016D8 ),              /* ''' */
  EW_GLYPH( 0x0028, 2, -26, 9, 34, 11, 0x00001703 ),            /* '(' */
  EW_GLYPH( 0x0029, 0, -26, 9, 34, 11, 0x0000197F ),            /* ')' */
  EW_GLYPH( 0x002A, 0, -23, 14, 14, 14, 0x00001C00 ),           /* '*' */
  EW_GLYPH( 0x002B, 1, -20, 17, 18, 19, 0x00001E22 ),           /* '+' */
  EW_GLYPH( 0x002C, 1, -3, 4, 8, 6, 0x00001FF0 ),               /* ',' */
  EW_GLYPH( 0x002D, 0, -11, 9, 2, 9, 0x0000204E ),              /* '-' */
  EW_GLYPH( 0x002E, 2, -3, 4, 3, 8, 0x00002084 ),               /* '.' */
  EW_GLYPH( 0x002F, 0, -23, 12, 25, 13, 0x000020BE ),           /* '/' */
  EW_GLYPH( 0x0030, 1, -23, 16, 23, 18, 0x00002306 ),           /* '0' */
  EW_GLYPH( 0x0031, 2, -23, 10, 23, 18, 0x0000265D ),           /* '1' */
  EW_GLYPH( 0x0032, 1, -23, 16, 23, 18, 0x000027C1 ),           /* '2' */
  EW_GLYPH( 0x0033, 1, -23, 16, 23, 18, 0x00002B43 ),           /* '3' */
  EW_GLYPH( 0x0034, 1, -23, 17, 23, 18, 0x00002F37 ),           /* '4' */
  EW_GLYPH( 0x0035, 2, -23, 15, 23, 18, 0x0000321C ),           /* '5' */
  EW_GLYPH( 0x0036, 2, -23, 15, 23, 18, 0x000035B9 ),           /* '6' */
  EW_GLYPH( 0x0037, 1, -23, 16, 23, 18, 0x0000398F ),           /* '7' */
  EW_GLYPH( 0x0038, 1, -23, 16, 23, 18, 0x00003C81 ),           /* '8' */
  EW_GLYPH( 0x0039, 1, -23, 15, 23, 18, 0x000040E7 ),           /* '9' */
  EW_GLYPH( 0x003A, 2, -18, 4, 18, 7, 0x000044BE ),             /* ':' */
  EW_GLYPH( 0x003B, 1, -18, 5, 23, 6, 0x0000456E ),             /* ';' */
  EW_GLYPH( 0x003C, 1, -17, 14, 13, 17, 0x00004659 ),           /* '<' */
  EW_GLYPH( 0x003D, 2, -15, 14, 9, 18, 0x00004886 ),            /* '=' */
  EW_GLYPH( 0x003E, 2, -17, 14, 13, 17, 0x000049B5 ),           /* '>' */
  EW_GLYPH( 0x003F, 1, -23, 13, 23, 15, 0x00004BF6 ),           /* '?' */
  EW_GLYPH( 0x0040, 1, -23, 28, 30, 30, 0x00004EA3 ),           /* '@' */
  EW_GLYPH( 0x0041, 0, -23, 21, 23, 21, 0x00005736 ),           /* 'A' */
  EW_GLYPH( 0x0042, 2, -23, 17, 23, 20, 0x00005B33 ),           /* 'B' */
  EW_GLYPH( 0x0043, 1, -23, 19, 23, 21, 0x00005EAE ),           /* 'C' */
  EW_GLYPH( 0x0044, 3, -23, 17, 23, 22, 0x0000629B ),           /* 'D' */
  EW_GLYPH( 0x0045, 3, -23, 15, 23, 19, 0x000065B4 ),           /* 'E' */
  EW_GLYPH( 0x0046, 3, -23, 15, 23, 19, 0x0000680E ),           /* 'F' */
  EW_GLYPH( 0x0047, 2, -23, 19, 23, 23, 0x00006A33 ),           /* 'G' */
  EW_GLYPH( 0x0048, 3, -23, 18, 23, 23, 0x00006E58 ),           /* 'H' */
  EW_GLYPH( 0x0049, 3, -23, 3, 23, 9, 0x0000707C ),             /* 'I' */
  EW_GLYPH( 0x004A, 1, -23, 15, 23, 18, 0x000070CF ),           /* 'J' */
  EW_GLYPH( 0x004B, 3, -23, 18, 23, 21, 0x00007309 ),           /* 'K' */
  EW_GLYPH( 0x004C, 3, -23, 14, 23, 17, 0x0000767B ),           /* 'L' */
  EW_GLYPH( 0x004D, 3, -23, 23, 23, 29, 0x000077F5 ),           /* 'M' */
  EW_GLYPH( 0x004E, 2, -23, 19, 23, 23, 0x00007C12 ),           /* 'N' */
  EW_GLYPH( 0x004F, 1, -23, 20, 23, 22, 0x00007F09 ),           /* 'O' */
  EW_GLYPH( 0x0050, 2, -23, 17, 23, 20, 0x0000833C ),           /* 'P' */
  EW_GLYPH( 0x0051, 1, -23, 20, 27, 22, 0x00008639 ),           /* 'Q' */
  EW_GLYPH( 0x0052, 3, -23, 17, 23, 21, 0x00008B1A ),           /* 'R' */
  EW_GLYPH( 0x0053, 1, -23, 18, 23, 20, 0x00008E6D ),           /* 'S' */
  EW_GLYPH( 0x0054, 0, -23, 19, 23, 20, 0x00009308 ),           /* 'T' */
  EW_GLYPH( 0x0055, 2, -23, 18, 23, 22, 0x00009552 ),           /* 'U' */
  EW_GLYPH( 0x0056, 0, -23, 20, 23, 20, 0x000097EF ),           /* 'V' */
  EW_GLYPH( 0x0057, 1, -23, 28, 23, 30, 0x00009BB0 ),           /* 'W' */
  EW_GLYPH( 0x0058, 0, -23, 20, 23, 20, 0x0000A152 ),           /* 'X' */
  EW_GLYPH( 0x0059, 0, -23, 20, 23, 20, 0x0000A59F ),           /* 'Y' */
  EW_GLYPH( 0x005A, 1, -23, 18, 23, 20, 0x0000A8DF ),           /* 'Z' */
  EW_GLYPH( 0x005B, 2, -27, 6, 32, 8, 0x0000AC64 ),             /* '[' */
  EW_GLYPH( 0x005C, 0, -23, 13, 25, 13, 0x0000AD5D ),           /* '\' */
  EW_GLYPH( 0x005D, 0, -27, 6, 32, 8, 0x0000AFBA ),             /* ']' */
  EW_GLYPH( 0x005E, 1, -23, 12, 11, 14, 0x0000B0B3 ),           /* '^' */
  EW_GLYPH( 0x005F, 0, 0, 15, 2, 14, 0x0000B217 ),              /* '_' */
  EW_GLYPH( 0x0060, 1, -25, 7, 5, 9, 0x0000B271 ),              /* '`' */
  EW_GLYPH( 0x0061, 1, -17, 15, 17, 18, 0x0000B2E7 ),           /* 'a' */
  EW_GLYPH( 0x0062, 2, -25, 15, 25, 18, 0x0000B5E9 ),           /* 'b' */
  EW_GLYPH( 0x0063, 1, -17, 15, 17, 17, 0x0000B8F0 ),           /* 'c' */
  EW_GLYPH( 0x0064, 1, -25, 15, 25, 18, 0x0000BBAB ),           /* 'd' */
  EW_GLYPH( 0x0065, 1, -17, 15, 17, 17, 0x0000BEAD ),           /* 'e' */
  EW_GLYPH( 0x0066, 1, -25, 11, 25, 11, 0x0000C19F ),           /* 'f' */
  EW_GLYPH( 0x0067, 1, -17, 15, 24, 18, 0x0000C35F ),           /* 'g' */
  EW_GLYPH( 0x0068, 2, -25, 14, 25, 18, 0x0000C73A ),           /* 'h' */
  EW_GLYPH( 0x0069, 2, -24, 3, 24, 7, 0x0000C968 ),             /* 'i' */
  EW_GLYPH( 0x006A, -2, -24, 8, 31, 8, 0x0000C9EE ),            /* 'j' */
  EW_GLYPH( 0x006B, 2, -25, 14, 25, 16, 0x0000CB73 ),           /* 'k' */
  EW_GLYPH( 0x006C, 2, -25, 3, 25, 7, 0x0000CE1E ),             /* 'l' */
  EW_GLYPH( 0x006D, 2, -17, 25, 17, 29, 0x0000CE76 ),           /* 'm' */
  EW_GLYPH( 0x006E, 2, -17, 14, 17, 18, 0x0000D19A ),           /* 'n' */
  EW_GLYPH( 0x006F, 1, -17, 16, 17, 18, 0x0000D35C ),           /* 'o' */
  EW_GLYPH( 0x0070, 2, -17, 15, 24, 18, 0x0000D65C ),           /* 'p' */
  EW_GLYPH( 0x0071, 1, -17, 15, 24, 18, 0x0000D982 ),           /* 'q' */
  EW_GLYPH( 0x0072, 2, -17, 9, 17, 11, 0x0000DCAF ),            /* 'r' */
  EW_GLYPH( 0x0073, 1, -17, 14, 17, 17, 0x0000DDB9 ),           /* 's' */
  EW_GLYPH( 0x0074, 0, -21, 10, 21, 11, 0x0000E0D0 ),           /* 't' */
  EW_GLYPH( 0x0075, 2, -17, 14, 17, 18, 0x0000E236 ),           /* 'u' */
  EW_GLYPH( 0x0076, 0, -17, 16, 17, 16, 0x0000E3D8 ),           /* 'v' */
  EW_GLYPH( 0x0077, 1, -17, 23, 17, 25, 0x0000E65D ),           /* 'w' */
  EW_GLYPH( 0x0078, 0, -17, 16, 17, 16, 0x0000EA52 ),           /* 'x' */
  EW_GLYPH( 0x0079, 0, -17, 16, 24, 16, 0x0000ED42 ),           /* 'y' */
  EW_GLYPH( 0x007A, 1, -17, 15, 17, 16, 0x0000F0AF ),           /* 'z' */
  EW_GLYPH( 0x007B, 1, -26, 10, 33, 11, 0x0000F318 ),           /* '{' */
  EW_GLYPH( 0x007C, 2, -23, 3, 27, 7, 0x0000F598 ),             /* '|' */
  EW_GLYPH( 0x007D, 0, -26, 10, 33, 11, 0x0000F5F4 ),           /* '}' */
  EW_GLYPH( 0x007E, 2, -13, 19, 6, 23, 0x0000F87E ),            /* '~' */

  EW_FONT_PIXEL( BezierClockFontXXL, 0x0000FA04 )               /* ratio 55.21 % */
    0xEF7BDEE3, 0x3BDEF7BD, 0xEF7BDF44, 0xEB2677BD, 0xF853C407, 0x983F304D, 0x884DF81F,
    0x80FCF0A7, 0x4099C1DF, 0x80111A46, 0x00BEF3FB, 0x00188CF5, 0x580073BE, 0xF2B000F9,
    0x073BE001, 0x06233D40, 0x5F79FDC0, 0x111A4640, 0x4CE0EFC0, 0xF9E14F10, 0xDF81F981,
    0xF304DF84, 0x9101FA8F, 0xF7BDF645, 0x5A677BDE, 0x00000177, 0x0000C190, 0x7800FB9E,
    0x6E78DF4E, 0xFF9FEF3C, 0x3021000F, 0xDC08C42C, 0xBCC00818, 0xC00DBF09, 0x01E7848E,
    0xB88C1560, 0xF0FF2200, 0x018F0028, 0x50C01237, 0xB9E03CF0, 0xEF76DEF7, 0xBDD477BD,
    0x800001F7, 0x637BDEE7, 0xCFEF7BDD, 0x80FBDEEF, 0x03C3038C, 0x9FE07960, 0x031FE001,
    0x246002D6, 0x7801FE44, 0x000C781E, 0x07861719, 0xBFDEF7BC, 0xDB7BDEF7, 0x0006F7B9,
    0xDEF7BC00, 0x7BDEF719, 0x6F7BDE63, 0x8C81E780, 0xB018C00B, 0x3F86003C, 0x780063FC,
    0xC009182C, 0x01E7848E, 0x001DD600, 0x00000000, 0xBBE40000, 0x00F7FFDB, 0xA8839ED6,
    0x5B6607EF, 0x46F3DEFB, 0x3D7ED07D, 0x29E3B988, 0xB201EA2A, 0x9806D21D, 0x46400051,
    0xBC00FC78, 0x0D18C61D, 0x58DC2CF0, 0xFE3000BB, 0xEFFEFC63, 0x57F63000, 0x017FF739,
    0x77FF7E78, 0x400BFF64, 0xBF2BBDCE, 0x9BF18001, 0x0033C571, 0xBF3239BC, 0x69128017,
    0x59188001, 0xBCF84A00, 0xA4737809, 0x1257B959, 0xF1719ECF, 0xF7FFA27B, 0x37C46F9E,
    0x8933DBE0, 0x78C05BEA, 0x56FEEDFF, 0x00000000, 0xDDCF7880, 0x7B10000B, 0x001FD186,
    0xEE75CBF0, 0xF101E7AE, 0xE9E7884B, 0xC0717E30, 0x17480E6F, 0x74F509AC, 0xB7848000,
    0x1230001E, 0x5D205E3D, 0xBD6326B0, 0x74F3C409, 0xB9FE5FC8, 0x72FC0163, 0x9AAFFB9D,
    0x6200B8D6, 0x93FD90CF, 0xC4001AEF, 0xF17FEE7B, 0xE000068E, 0xE77C66A9, 0xF4001EFE,
    0x27FF18F3, 0xDE00D7D4, 0xEF78E3F1, 0xC00D63DD, 0x7B2A1D98, 0xE01F8E32, 0xC828498E,
    0x8BCAC01C, 0xDF200034, 0x00069039, 0x1421A3BC, 0x2F100E64, 0x38C9ECA8, 0xE02BE07E,
    0xA3DDEF78, 0xFB180007, 0x602DF509, 0x02F773ED, 0x611EEC40, 0xBF000EF4, 0xF77BBF91,
    0x78803F18, 0x1FE316E2, 0x212A9005, 0x0300089E, 0xF4801158, 0x00BC6780, 0xF9E06351,
    0x71D002D5, 0x07E7BF78, 0xF7F378C0, 0x0007EB9F, 0x35F8D46B, 0x446FC400, 0xFDC8000C,
    0x80FD1DF4, 0xE3B89278, 0xBF1FF15B, 0x7E1EFC82, 0x3FE22BF9, 0xE42981BE, 0x3B881E33,
    0x58F7F04E, 0xFF5E407E, 0x05C0C4F0, 0xE66F8DE4, 0xF2007A64, 0x8CBC6F3C, 0x85F806CC,
    0x7EB1BC0A, 0xBFEB904F, 0x5F50B3C4, 0xFDEE77D4, 0x4777E677, 0x95D3A83F, 0x3FFBE78C,
    0xEE57F271, 0x845C100B, 0xE407F204, 0xFC4E015D, 0x013CBE03, 0x3A09BCF5, 0x01F1A817,
    0xAAC82637, 0x5B036500, 0x32091501, 0x204A601E, 0x4801201C, 0x24090000, 0x94C03840,
    0x7803C640, 0x80AD8122, 0x2AB206C7, 0x780B1380, 0xB9D00FC6, 0x04DE7A80, 0x7100E37E,
    0x97790363, 0xFF3002F8, 0x1F1FE201, 0x181AA710, 0x35A00E73, 0xF006AB10, 0x0A318179,
    0x18078BF0, 0x401E5036, 0x4094C00E, 0xE008409A, 0x00B80002, 0x80B48021, 0xC0990069,
    0xC0D94050, 0xA8E40A2F, 0x62039F00, 0x1A378156, 0xC406B98C, 0xC7F886C9, 0x00FF581F,
    0x000FEFC0, 0x00000000, 0x0107BF90, 0xF9EB97F3, 0xD1863BCE, 0x73D67DE7, 0x95ED67BF,
    0x1E77D67B, 0x0AEEFCF1, 0x100F7EEB, 0x800F18CF, 0x7E3BDC77, 0x18E73980, 0xF640B3EF,
    0x03BD5668, 0x09AF03A6, 0x3CF21275, 0x00059E00, 0x00001D38, 0x00000000, 0x00000000,
    0xE0000000, 0xF7BDEF77, 0xBDEF7396, 0x00000EF7, 0xBDEF7BBF, 0xEF7B9CB7, 0x000077BD,
    0x00000000, 0x00000000, 0x80000000, 0x7DD60051, 0xC5531C00, 0xD93A7278, 0xF7B8CBBE,
    0x02EF7BDE, 0x8FF3E750, 0x04F1FE27, 0xA00DFF00, 0x627003F2, 0x002D4402, 0xDF003E33,
    0x7F230018, 0x0098BE00, 0x56002AB1, 0x165F001C, 0x801F18C0, 0x2AB004CF, 0x001C6600,
    0xB2007CFF, 0x0F9F001E, 0x7804ACC0, 0xF13800E2, 0x004D6400, 0x6F801F8F, 0x0FCA800C,
    0xBFFBE400, 0x6026FFF7, 0x739267FD, 0xD63B302F, 0xF4BDDEFF, 0x4EBF6883, 0x30FCFF46,
    0xF3C03E63, 0x00FB62C4, 0x06279B5E, 0xC44788C0, 0x24464003, 0x00032C00, 0x00000010,
    0x00000000, 0xC4000100, 0x465800B0, 0x11900244, 0x1500189E, 0xC02F7F0F, 0x33C667F1,
    0xC4C4F981, 0x460EFBCF, 0x379E1ABF, 0xAF77BEE6, 0x9EE609E8, 0x017B9C83, 0x3C07B588,
    0xF183D3BF, 0x892AAF9E, 0x9BFDAD3D, 0x80F4EFA8, 0x00003DF8, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0xBDFFDF20, 0xF5801DFB, 0xFB98C99F, 0xFBE76F05,
    0xB34F77BF, 0x67B1CCF1, 0x0CCFDE32, 0xE780375E, 0x1A8C6589, 0x6D31DB00, 0x0BB30300,
    0x1AC63A40, 0x00B17E00, 0x002B19E0, 0x000D9D10, 0x00037CFF, 0x8005D1BF, 0xC002D6AF,
    0x800D3CFB, 0x8007CF9E, 0x8007CF5E, 0xC003EAB5, 0xE001FAEC, 0x000FC779, 0x007F1BF5,
    0x7B9C62F8, 0xDEF7BDEF, 0x00027F7B, 0xF7FEFA80, 0xF880B7EE, 0xCC649EFD, 0x95FE07DF,
    0xDFF7B9EF, 0x51E87CF1, 0xDAE419FF, 0x7C660CF1, 0x64FD7C80, 0x5250013C, 0x180017EE,
    0x01FCA009, 0x00B9BC60, 0x5C7FEF18, 0xDDEF7BC0, 0x8004EE6B, 0xBDE007A8, 0x5F8EEEF7,
    0x3DAC6003, 0x710003D6, 0x732000BC, 0x801278C4, 0xC0057D49, 0x6400F864, 0x0D18D466,
    0xB1B8FAF0, 0xFCE413F6, 0xFF8C58D7, 0xF7B9DF18, 0x61FD66FF, 0xF249EFEC, 0x0002FDF9,
    0x40017B9E, 0x3F0000FC, 0x79EA0001, 0x9BC40007, 0x1E74000B, 0x0E735000, 0x0BE6F000,
    0x017CDE00, 0x014F98C0, 0x003F1380, 0x000BF9D0, 0x0079F318, 0x0003F5C0, 0x4000746B,
    0xC00135BE, 0xBDEF751B, 0xEE9BDEF7, 0x0009BFBD, 0xDEF7BFF0, 0x37BDEF7B, 0x007F7BDD,
    0x00000000, 0x40000000, 0xBDEF7BDF, 0x077BDEF7, 0x73A40001, 0xDEF7BDEF, 0x0053077B,
    0x100048C0, 0x02520013, 0x98000840, 0xEFFDF3CE, 0xF5202BD9, 0x7D18A4F7, 0xDFFE970B,
    0x6F8ABE7B, 0x25777EF0, 0xB89EFCF1, 0x2F8013C4, 0xCF8000C7, 0x0086000F, 0x04632580,
    0xFD9F2580, 0xE3CE1802, 0xF153F001, 0x18D60364, 0xAFD62FC3, 0x3475F182, 0x9DFACFF1,
    0x5F13F77B, 0x0ADFFC61, 0x802DD631, 0xBBFF7EB1, 0x5DDBF900, 0x62BB5009, 0xA05DCEFD,
    0x2BA758BE, 0x6DE37880, 0x135CDE00, 0x001B3300, 0xB0007C4F, 0xDFFBE795, 0xE23C17B3,
    0x46293DF7, 0xA71907FF, 0xE7BDDF9E, 0x4442791B, 0x9E22BEFE, 0x15F8D95D, 0xF2158BE0,
    0x0F158801, 0x00091C00, 0x48013229, 0xDB001E51, 0xE402F7F3, 0x7C6AA313, 0x79789C40,
    0x884FD9F3, 0xC8B18F67, 0xEE77C63B, 0x90FEB2F9, 0xF510ADFB, 0xBDDF82FD, 0xEF7BDEF7,
    0xFBDEF7BD, 0x77E20002, 0xDEF7BDEF, 0x4FBDEF7B, 0x5590007C, 0x68BF0009, 0x09558800,
    0x005C6F00, 0xC0014730, 0xBC00178A, 0x198001E3, 0xE5F8001F, 0x3F278004, 0x04C6F000,
    0x00CC6780, 0x003E3780, 0x0012B1A8, 0x8C001FAE, 0x5E00127A, 0x33E4002F, 0x06B40006,
    0x0051AC80, 0xBDFFBEA0, 0xBF00AFFF, 0xF3E493DF, 0x2AFC05FB, 0xBFEF7FFA, 0x953C3EA3,
    0x76B9257B, 0x4BF5C3D6, 0x2A61DB20, 0x00613280, 0xE00A3C10, 0x4E8BF0F1, 0x91F8DE20,
    0x724AF63D, 0xF989D1DE, 0xFBDFFECF, 0xC13FF37F, 0xFDE09804, 0xFBDFFDE2, 0xB17BE37F,
    0x9267FD66, 0xC5CCFFF3, 0x2F803F1B, 0x0098A8DF, 0x02E1513C, 0x005C97F0, 0x000F2C52,
    0xFC8E4F3F, 0xE18C7A00, 0x249FB3C6, 0x32E2BD9E, 0xFFBE39FE, 0xF91BE7BD, 0xEFFF181F,
    0xFF79F249, 0x73BE7803, 0xF1016FCF, 0xD5109EFB, 0xE55F01FF, 0x55FDEE7B, 0xC6AB07FE,
    0x56FD419E, 0x80373E5C, 0xD646A31E, 0xC7ED7800, 0x90A8F006, 0x00326400, 0x8006C310,
    0x56012A27, 0x602F158A, 0xFD6741BE, 0x7BF5109F, 0xE66E20E7, 0x55F9EE77, 0xEFF92677,
    0x2BFF390A, 0x73BF582D, 0x7F2A6FFF, 0x002BF800, 0x40018D54, 0xEA005EBE, 0x7200F3E6,
    0x1F597EFE, 0xDFFEF718, 0x1007F78A, 0x42677E63, 0x9E3FCF9D, 0x7513C7F8, 0x0000003E,
    0xE7500000, 0xFE278FF3, 0x1F3A84F1, 0x3FC278FF, 0x03E7509E, 0x00000000, 0xEEB00000,
    0xA4C70003, 0x72727862, 0x002EF9B2, 0x8C01AB10, 0x9E0076EF, 0x5F7C9FBD, 0x72FFF588,
    0xDE313DEE, 0x77DEF1DB, 0xAD7B7EA0, 0x5B8067BD, 0xE003BF63, 0x00EFD8D6, 0x6B5EDFA8,
    0xDE3009EF, 0x779EF1DB, 0xBFFD6200, 0x804F7B9C, 0xDF27EF67, 0x6EF8C017, 0xBDEF7BC7,
    0xEF7BDEF7, 0xE0007FBD, 0x7BDEF7BD, 0xDEF7BDEF, 0x0000003F, 0xC0000000, 0xF7BDEF7B,
    0xBDEF7BDE, 0xF7E0007F, 0xFF7D4000, 0x1AF60015, 0x1801BF7D, 0xD9E7BE7D, 0xBF3C027B,
    0x74F78AFF, 0x5FFFB202, 0x0037FFAD, 0xF3C76F9E, 0x8EDF3C01, 0xFFD903E7, 0x1BFFD6AF,
    0x15FF7E78, 0xF464E9EF, 0xEF679EF9, 0x7D1AF609, 0xEFA801BF, 0xC60002BF, 0x37E7BFF7,
    0x4527EF41, 0x2B583BBD, 0x2FEF73DE, 0xD8DE27C7, 0x359DA833, 0xF104CC56, 0xD2036BA9,
    0x4E0053E9, 0x015FC004, 0x400639C8, 0x7720171C, 0x7790037E, 0x8EE00BFC, 0xF95800FF,
    0x0F3F000E, 0xF8012100, 0x0000005F, 0x7E000000, 0x959004FF, 0x16472005, 0xF779E000,
    0xEBFFF7B9, 0xE7580002, 0x5AC8239B, 0x8002FFBF, 0xF7A8EFF1, 0xFB3DEF7F, 0x00EF467D,
    0xFE7CFF50, 0x318899BF, 0x1D8CFDBF, 0x5FBCFA80, 0x37DF9002, 0xBE7C40FE, 0xEF3C0009,
    0x5D17E098, 0x7EAB0000, 0x409A9E30, 0x1DDDCEFD, 0xD783E6E0, 0x0ABFBC0B, 0xCA84ED63,
    0xE093D44D, 0xF7BBF99D, 0x7A81733F, 0xE6A0B8A8, 0x136E45D8, 0x815FC1DC, 0x0430138E,
    0x0118C218, 0x4704AC63, 0x09CD2982, 0x004407CA, 0x63FC0390, 0x05803900, 0xAC04AC07,
    0x18048409, 0xFC01100B, 0x00203823, 0x87A80391, 0xF0272018, 0x9E6C7202, 0x180E5605,
    0x31BC1233, 0xDDB09919, 0x9EBFD621, 0x3AAF887A, 0x8E607BF8, 0xFCE9EFB1, 0xFFFFBE3A,
    0x89E2733C, 0x1867FC0F, 0x8D7F8DBD, 0x660BDF51, 0xDCF7882E, 0xE77E30BD, 0x8DE01EFC,
    0x00000077, 0x05FE2FC4, 0xACF00000, 0x00801AF8, 0xE75AFD00, 0xBCF9127D, 0xDCC00137,
    0xDFFBF315, 0x5CDFFF7B, 0xEFE40009, 0xD5124FDF, 0x800017FF, 0x8000277D, 0x00007C31,
    0x0018C67E, 0x0FDB3300, 0x57C4F000, 0xC7000139, 0x00078BE3, 0x1C7A5564, 0x6438F000,
    0x17C00255, 0x001EFE0F, 0xF1582E54, 0x20F8E001, 0x54400B2A, 0x001C700E, 0xB2A03E33,
    0x01E7E002, 0x6300B13C, 0x1F3E0254, 0xDEF753E0, 0x7FBDEF7B, 0x000B0063, 0xBA89E07C,
    0xEF7BDEF7, 0x816FF7BD, 0x159000E3, 0x01E2B20F, 0x99F071C0, 0x2564F000, 0x3C000F8F,
    0x0095953E, 0x7B88F3E0, 0xDEF7BDEF, 0x00056FFF, 0x40BBEAC8, 0xBDEF7BDE, 0x4F44F7E7,
    0x9F7D4400, 0x8A9E0006, 0x04860002, 0x94000000, 0x51CC0007, 0xEFA88003, 0xDEF20FCD,
    0xBF3DEF7B, 0x0000FF5A, 0xF7902CF1, 0xFDEF7BDE, 0x8003FABF, 0x167AFF9C, 0x0BC5F000,
    0x0313C400, 0x00000000, 0x03159000, 0x0058E200, 0x3647B9C8, 0xEF7BDEF2, 0xC737FFBD,
    0xE78C000D, 0xBF3009DB, 0xEFFFBDFF, 0xF7FF5001, 0x76F9F249, 0xE397F302, 0xDFFEF73B,
    0x68C26E31, 0xE7209FBD, 0x46E0799E, 0xC6B7802F, 0x0058C6A4, 0x3F7F1F5C, 0x508C5400,
    0x8F28001E, 0xDDF00094, 0x0000090A, 0x00000000, 0x00000000, 0x00012100, 0xEF8004A4,
    0xB0005296, 0x003EFE3C, 0xC6A11C8C, 0x0FB40058, 0xAE804F57, 0xEF5E3131, 0xF67C82AF,
    0x97E603CA, 0xFEF73BF5, 0x813751BF, 0x3256FFE7, 0xF897EFE6, 0xBDEF7BDF, 0x000FBF77,
    0x2FF7E630, 0xEF7BDCE0, 0x7F23BFFD, 0xFB9C800D, 0xC000B58D, 0x004DE2FC, 0x001A3350,
    0x000278E8, 0x70001658, 0x2520001D, 0x0004B000, 0x00000000, 0x400012C0, 0x3AE0004A,
    0x00B2C000, 0x0013C740, 0x005E2B50, 0x00779F98, 0xE8DFB9C8, 0x7BDEE705, 0xE31DFFEF,
    0x318800B7, 0xEF705DBF, 0x7BDEF7BD, 0x2EF7BDEF, 0xDEF70000, 0xF7BDEF7B, 0x0000BBDE,
    0x00000000, 0x00000000, 0x70000000, 0xDEF7BDEF, 0x001FEF7B, 0x7BDEF700, 0xFEF7BDEF,
    0x00000001, 0x00000000, 0x00000000, 0xE0000000, 0xBDEF7BDE, 0x5F7BDEF7, 0xF7BDC000,
    0xBDEF7BDE, 0x00BBDEF7, 0xEF7BDC00, 0x7BDEF7BD, 0x000002EF, 0x00000000, 0x00000000,
    0xBDC00000, 0xEF7BDEF7, 0x00007FBD, 0xBDEF7BDC, 0x07FBDEF7, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0xB9000000, 0xFDDEE77E, 0x777A003D, 0xF6F9E305, 0xFCCB7E00,
    0xEFFF7B9D, 0xB782FF18, 0x9056FFF2, 0x82F8AF73, 0x800EE331, 0xF5E5E27E, 0x87AF0026,
    0x56300132, 0x00023119, 0x003D35FA, 0x80001C00, 0x00000004, 0xDEE20000, 0x37BDEF7B,
    0x200005D2, 0xDEF7B881, 0x0165937B, 0x00E66400, 0x00BC7800, 0x0F3C6F00, 0x6FDA2000,
    0x7301A802, 0x209FBBC5, 0xE2FDFCC6, 0xE317F409, 0xFD9EF73B, 0x781FBC56, 0x3124FBCE,
    0xF72677E6, 0x3EF78002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0xF7BDEF70, 0xBDEF7BDE, 0x00000277, 0xEF7BDEF7, 0x7BDEF7BD, 0x00000027, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0xF0000000, 0x000007DE, 0x00000000, 0xF8000000,
    0x000001DD, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x40000000,
    0x27D80004, 0x80242000, 0xC01F9647, 0x399F1913, 0xE4F9FC80, 0x724AFF8A, 0x5E8B18ED,
    0xFF7BFFD1, 0xDE87F51D, 0xF7CF9073, 0xC005EE0B, 0x0004FFBC, 0x009BCDF3, 0x1271BCF0,
    0xFF17EA00, 0xF9F50001, 0xCFA8000F, 0x7C600037, 0xF18002BE, 0x8C0015F7, 0xC001747F,
    0x013BC7F8, 0x0B91FF20, 0xC8C6F200, 0xF8EE000F, 0x0017A8F6, 0x9C9C7BE3, 0xC8AF8013,
    0x14003D13, 0x13FC5F8C, 0x1C567800, 0xE33F4000, 0x46F80007, 0x9FE00035, 0xE20001EB,
    0x00006FC4, 0x012717E3, 0xB8F3A780, 0x00000017, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xDEF7B800, 0xF7BDEF7B,
    0xDEE0002E, 0xF750000D, 0x00018CBE, 0x003E1038, 0x93C09F20, 0xA7C0002B, 0x00098BE0,
    0x19CC1C66, 0x98CC001F, 0x03E5620B, 0xE05E2F80, 0xA35000E7, 0x1AAC8262, 0xE0178E00,
    0x19F200FA, 0x0572A003, 0xF001F3E0, 0x98CC04C5, 0x07C66240, 0x880098CC, 0xE2F80F95,
    0x039F8005, 0x20002A35, 0x178E06AB, 0xF23EB800, 0xA8000319, 0x02F3E15C, 0x9A62FC00,
    0xCC0000F9, 0x007C66F8, 0x98ECCC00, 0xA27C0000, 0x7C800002, 0xF73C00BC, 0x37FE000F,
    0x80000FC8, 0x860000A7, 0xCF000037, 0x40001FCA, 0x0001E78F, 0x000BF1B8, 0x03E378C0,
    0x26A35800, 0x4E89C000, 0x1C764000, 0x63598000, 0xF17C0001, 0x7440000E, 0xF980005C,
    0xF800068C, 0x80001AC5, 0x80001CF8, 0x0005F27A, 0x001672F8, 0x0005EBC0, 0x000995A8,
    0xC00009D0, 0xFBE78009, 0x1EFFFBDF, 0x3DFFEA00, 0x7FDF3E49, 0xF1CBEA00, 0x7FFDEFFD,
    0xC605FF23, 0x249FBD17, 0x0DF1DD9F, 0x600BD1B8, 0x18D45C75, 0x4635800B, 0xC001F7F1,
    0x00294FE7, 0x09190F28, 0x18431900, 0x0010C000, 0x00000000, 0x00000000, 0x00006100,
    0x0048C843, 0x029418C8, 0xF7F0F280, 0x4FE7C001, 0xAC00D18D, 0xD6370A31, 0x171D5802,
    0x9FBD17C6, 0xF1DD9E24, 0x39FEA01B, 0xE7BDFFBE, 0x803DF91B, 0x249EFFF1, 0x305FEF9F,
    0xDEF7BDEE, 0x7BFFEF7B, 0xBE7C8000, 0xBDEEA03D, 0x7FFBDEF7, 0x000FF8C7, 0x5C4FDCE4,
    0x51CBE000, 0x0367C000, 0x00004300, 0x00860000, 0x00FE7E00, 0x003E47A0, 0xBC57B3E4,
    0xBDEF7BA8, 0x91BFFEF7, 0x9F20015F, 0xF7505FF7, 0xFDEF7BDE, 0x0000137F, 0x00000000,
    0x00000000, 0x00000000, 0x80000000, 0xFBDFFBE7, 0xEA001EFF, 0x3E493DFF, 0xF9801EDF,
    0xBDCEFACB, 0x7F8C77FF, 0xF7FAD181, 0x8AF73904, 0x2F46E12F, 0xE2F19E80, 0xF0016319,
    0x17AE0D66, 0x4A3F3E00, 0x22194001, 0x78600032, 0x440009A4, 0x04300000, 0x00000000,
    0x21800000, 0x220004D2, 0xC0006444, 0x80029490, 0x002F5C52, 0x633C7E7C, 0xACDE002C,
    0x00BD1B81, 0xA30BC67A, 0x7C827EF5, 0xC12F8AF6, 0xCEF8E5FC, 0xE46FFFBD, 0xFFF500BF,
    0x58CB249E, 0xFFDF3C00, 0xF3EFFFDE, 0xE780004D, 0x80006DEF, 0x002D73B1, 0xDCBDDC80,
    0xF7BDEF7B, 0x0016FD9E, 0xBF7F3188, 0x7BDEF704, 0xD677FDEF, 0xDAE4000D, 0x88001F95,
    0x40012A2F, 0x1C00052C, 0x00000001, 0xC4000238, 0xBE2000B2, 0xCE400198, 0xDEE1A35D,
    0xFFBDEF7B, 0x001FEB37, 0x805FBF90, 0xF7BDEF7B, 0xE0002E66, 0x9A800175, 0x1D000163,
    0xE880026F, 0x59800178, 0x37800135, 0xBE40003A, 0xD60003F1, 0xDF3C0A78, 0x5BF3DEFF,
    0xF7FFA801, 0x1B7D5124, 0xEFACBF3C, 0xCBD9EF7F, 0xFD3F10FA, 0xBD18927B, 0x78AC99F3,
    0x3F1E4016, 0x18C00DAE, 0xF8000439, 0x8007DB15, 0xC6AA1BF5, 0x37C00017, 0x0009DB9E,
    0xFFFADBB1, 0x3AC001FB, 0x77D633DF, 0xF9E002BE, 0xE78D6FCE, 0x54004BF7, 0x6EA37FFF,
    0x2BDA8002, 0xC7A0000F, 0x005BF518, 0x3F559E50, 0x8E462000, 0x7E194002, 0x1BE001BE,
    0xFB13E659, 0xF6B9127B, 0x1BDF0713, 0xF7BFF7CF, 0xFF8C7BFE, 0x67BE7980, 0xB7F31884,
    0xBDEF7107, 0xEF7BDEF7, 0x7BDEF7BD, 0x880000FF, 0xF7BDEF7B, 0xBDEF791E, 0x003FDEF7,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFB8C0000, 0x1DDF8003, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00584000, 0x0118C8B0, 0x4A188C40, 0x378AD003, 0x335802E6, 0xFDEB465E, 0x5AFCF104,
    0xC62FCC0F, 0x5F3DEE77, 0x73C137C5, 0x79F24ADE, 0x1BBA83CF, 0xABF75800, 0xFC00031C,
    0x001F8F1C, 0xF3E5918C, 0x43CFC000, 0x1E001656, 0x000EFE1F, 0x51989595, 0xB07F1C00,
    0x8A8801E2, 0xC00EFE09, 0x5654058A, 0xC03EFE02, 0x72B201E7, 0xF01FA600, 0xC6A200F8,
    0xE0099F00, 0x0AC8C1F8, 0xF84C4F00, 0x28AC001C, 0xF00078AC, 0x00B13C39, 0xD70A8C60,
    0xB17E0007, 0x0000C6A2, 0x7E2BFE33, 0xFD544000, 0x8E000262, 0x540000AC, 0x9BFF003A,
    0x001EF200, 0x0052EDE6, 0xDB000C4A, 0xFE00BB7F, 0x2A9400A1, 0xFCA9E005, 0x888C6401,
    0xE2780991, 0xA500235F, 0x9ED80528, 0xCDB6016D, 0xB32B01B6, 0x8A2A0362, 0x4788C052,
    0x3C64053C, 0xE7E09150, 0x65028EC7, 0x62A056C3, 0xAD83F8F0, 0x6390D860, 0xC540B321,
    0xB2828A80, 0x8C81C9E1, 0xF8189E02, 0x2856C147, 0xE22B607F, 0x362A0279, 0x9FCA02B6,
    0x15503F8A, 0x44600C54, 0x957015B1, 0x31500511, 0xB94091AC, 0x7B601B1E, 0x3100FC46,
    0xE50056CA, 0xC5F80296, 0x19009958, 0x5001CECF, 0xAC00597E, 0x918014F1, 0x8AE006D3,
    0x0A15003F, 0xC0051280, 0xBBE80236, 0x3FBDE001, 0x40058C7A, 0xE270F8CD, 0xFAF1001D,
    0x0B8DF205, 0x01E7CBF0, 0xF50346AB, 0xC6F00FE4, 0x37AF101C, 0xE071D900, 0xCC00B397,
    0xF279E6CA, 0xAB17C005, 0x4000E7E2, 0xAC5FBCFC, 0x279E0001, 0xE000346B, 0x680003F0,
    0x7A0004DE, 0x000BC754, 0x8D6F8AC6, 0xFC70005A, 0x013789C2, 0xC879F378, 0x9A800E37,
    0xA35583F9, 0x037AF101, 0xF00731BC, 0x764059CB, 0xF93CF01C, 0x46CACC02, 0xBE001CFC,
    0x6B17C558, 0x8DED1000, 0x600027BA, 0x5E2AA3DC, 0x379AB800, 0xC7300266, 0x0D1BE498,
    0x9585CFC0, 0xCE74014F, 0x72035A01, 0x8D4F0346, 0x01BC7409, 0xF181F8E8, 0x5630058C,
    0x400D5C36, 0x78E64CC7, 0x68E8800A, 0x8003F17E, 0xF9D19E39, 0xEEB80006, 0x8C0005CC,
    0x0005E239, 0x0002C9F8, 0x00000018, 0x00000000, 0x00000000, 0x00000000, 0x80000000,
    0x7BDEF7B8, 0xDEF7BDEF, 0x001FEF7B, 0xEF7B8840, 0x7BDEF7BD, 0x17193DEF, 0x3BE5F800,
    0x6A7CC000, 0xF8EC8001, 0x5F138000, 0xCC778000, 0xC7350002, 0x8BE2000B, 0xD17C0003,
    0x3D560009, 0x378C0013, 0x89C0007F, 0x97C00037, 0x7CC000AB, 0x764001AA, 0x89C000BC,
    0x1E80025F, 0xB50001F3, 0xF10005F2, 0x660001C6, 0xDEF7BEC6, 0xF7BDEF7B, 0x0000FBDE,
    0xEF7BDCF0, 0x5EF79805, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0xC05EF798, 0x635800D9, 0x00F9F000, 0xE0016318, 0x8AC0098B, 0x31A8800F, 0x007E3800,
    0x7C004E54, 0xE33000F1, 0x09551000, 0x5001F1C0, 0xCBE000F9, 0x05C78007, 0x0009EB20,
    0x13C0098E, 0x1666001F, 0x40039F00, 0xFF000556, 0xF8CC0098, 0xDC72B000, 0x807DEF7B,
    0x0004EF7B, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x7B800000, 0x670004EF,
    0x0A319803, 0x017197E0, 0x0959BF95, 0x1F9F98DC, 0xAD653518, 0x8DC7CF80, 0x54955889,
    0xE171987E, 0x0B3787CB, 0x7E331C66, 0x7B8D5620, 0xDEF7BDEF, 0x77BDEF7B, 0x7FE20000,
    0x0DE2710B, 0xB07F378C, 0xCBE079EA, 0xFFBE783F, 0x201DFBBD, 0x6324F7F7, 0x51DC46EE,
    0xBFEF73BF, 0x9CDE4D63, 0x7D720ABF, 0xD406A87E, 0x00BFD4C8, 0x00000258, 0xBDCFBBCF,
    0xFFD416F7, 0xEA00239B, 0xEFFEF1CB, 0xDE16F7BD, 0x20133DE8, 0x84002C73, 0xE2326005,
    0x897E2049, 0x63067715, 0x95BC4ADD, 0xB777B9EF, 0x6F7E4CAF, 0xCFBEA885, 0x003BDFB5,
    0x00000000, 0x00000000, 0x00000000, 0xF7D40000, 0x0137E7BF, 0x5149EFEF, 0x39E80EEF,
    0xCDE7BDF7, 0xEF7D41F1, 0x9ACEE620, 0xAF100F98, 0xE5401F0F, 0x1E580008, 0x00014800,
    0x00B80017, 0x28000A40, 0xC4F0050F, 0xB202DE08, 0x077BF0BD, 0x83D66F31, 0xDEFB98DF,
    0xB07D66F3, 0xEA295BF6, 0xDE3005FD, 0x4DFBBDFF, 0x1933DDE0, 0x9BE0BFF3, 0xFF7BFFD1,
    0x3CF17A2B, 0xFD9257B9, 0xDEBC378F, 0x2B1BC604, 0xCA8028C7, 0xC6003CB3, 0x0001D3BF,
    0x20000000, 0x0A58005D, 0xC7233C40, 0xCAFA8028, 0xDB204DEB, 0x67B999E3, 0x4AE76B92,
    0xFFEF19DE, 0x86EB7FDE, 0xAC64CF77, 0x718000BD, 0x0000005F, 0x00000000, 0x00000000,
    0x7F300000, 0x02BFFEE7, 0xC856F7E2, 0xAF82F7E7, 0xEEF73DF2, 0xE54F1B39, 0xBF78C19D,
    0x7813ABC2, 0x01E23116, 0x0028F1F8, 0x5C000908, 0x4002E000, 0x2C780048, 0x07CA8800,
    0x027470A0, 0xBCA9E2F5, 0x07EF1833, 0xB9EF957E, 0xF06CCF77, 0xBD442AFB, 0xF7B201FB,
    0x5803BBBD, 0xBAC60D7B, 0xFFF5AB05, 0x1BE33DDE, 0x92BDCE8C, 0x6971BEF1, 0x19F3026F,
    0xE00AAB23, 0x600D95F8, 0xDEF7D0CA, 0xF7BDEF7B, 0x70002E2F, 0x7BDEF77D, 0xDEF7BDEF,
    0x7800485F, 0xA318006C, 0x37DA000A, 0x15A8B900, 0xF46077FF, 0x736E937E, 0x1AF77BDF,
    0x1AF6B13B, 0x27FDEB21, 0xEEE77F30, 0x30ADEF80, 0xEF13CF02, 0x9E8E07BD, 0x01313C04,
    0x00000062, 0xDE57BDC0, 0xB8002F7B, 0xEF7BCAF7, 0x00000005, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0xFF73BF98, 0x12FBC95F, 0x3E42B7BF, 0xABE037BF, 0x7BBDCF78,
    0x72A78BCE, 0xDFBC60CF, 0x7813ABC0, 0x01E23116, 0x0028F1F8, 0x38000308, 0x8005C000,
    0x28F00090, 0x078A8800, 0x027470A0, 0xDCA9E2F5, 0x37EF1833, 0x9EF157E0, 0x5E7CF77B,
    0xE42AFBF0, 0xF016FDF3, 0x7FFDCEFC, 0xA400098F, 0x94F80243, 0xE6F00BDC, 0x3F7B3218,
    0x5C66FD41, 0x9DF19FFC, 0xDF157F7B, 0x27BF7C40, 0xAC5BE8C5, 0x000000FB, 0x00000000,
    0x00000000, 0x88000000, 0x77FDCFB5, 0x847BB180, 0xFFE0775C, 0x7F7B9EF7, 0xEE562E23,
    0xC73FD419, 0xE201FE20, 0xF801BC51, 0x010024BB, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x2759CF00, 0x73DF13BE, 0x17758016, 0x00000000, 0x7FE40000, 0xC0639583,
    0xFF2031CA, 0x0000001B, 0x0003FDC4, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x32C02180, 0xDCF6DAA1, 0x4531CBFB, 0x7759B5C8, 0x00000001, 0x00000000, 0x00000000,
    0xFA000000, 0x577800FE, 0xB37C00FD, 0xA7BE007E, 0xCF7E007E, 0xABF003F3, 0xABF003E7,
    0xBFB803E7, 0x559802F2, 0xFAC4004E, 0x6601FE75, 0x807C735B, 0x059EB783, 0x01FB2F80,
    0x12FC4E20, 0x1B8BF180, 0x1F9D3C00, 0xEF53D600, 0x00002FB8, 0x00000000, 0xEFC00000,
    0xF7FF7C86, 0xEF640EEE, 0xC26FFF7B, 0x63267B98, 0x1AF734ED, 0xDF85DCE4, 0x3DEEFCFB,
    0xBCFBE65F, 0xEEF73DE3, 0xFD730F8A, 0xD46E788A, 0x1833FEAF, 0xD19311BF, 0xE01F1640,
    0xFE017973, 0xC91E0056, 0x2400E004, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0xBC000000, 0xCFB58877, 0xBA8077FD, 0x3BAE423D,
    0x7BC6FBF0, 0xB88DFDEE, 0x419ECF58, 0xE20C63FD, 0xC3D3100B, 0x43BF801B, 0x00001002,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFBDFFDE3, 0xDDE0077F, 0x3FB9C933,
    0xFFD19BF0, 0xCF1DFF7B, 0xAF72AB0F, 0x5ACED724, 0x40938DE2, 0xA8AC6F1E, 0xA89E3001,
    0xFD7002EB, 0x196002D3, 0x0C06000C, 0x00B49200, 0x00DAF298, 0x4AC57B5C, 0xF1515180,
    0x4F204DC6, 0xEE5561BC, 0x59DAE495, 0xFA27BF0B, 0xE3BFEF7F, 0xCF6F81F9, 0xF0FEE724,
    0xFFDF50DE, 0x9E04DF9E, 0xA8A4F7EF, 0xCD740777, 0x8DFFEF7D, 0xEF7E41F1, 0x9A8EE720,
    0x9FC80B78, 0xC4F0050F, 0x09280008, 0xC0026900, 0x000E0005, 0x1E000290, 0x13C00F0F,
    0xE401E823, 0x1EFF0BCF, 0x0F51DCC4, 0xF7DACF7E, 0x83EA379E, 0x149EFBF9, 0x7802FEF5,
    0xBF3DFFBE, 0x00000009, 0x00000000, 0x00000000, 0xFB9DFCC0, 0x2FB8CAFF, 0xF90ADFB1,
    0xFF05BEFC, 0x77B9EF91, 0x398BCF3F, 0x7C60CEF2, 0x13A7E25F, 0xF9991678, 0x1659FC00,
    0x00090C00, 0x004002E1, 0x001FC300, 0x39000596, 0x9F1200B2, 0x62F18137, 0x8C19DE56,
    0xCABE0FF7, 0xE7BBDCF7, 0xB7BF10D3, 0x6FDF3E42, 0xEE77F300, 0x00007BFF, 0x00000000,
    0x00000000, 0x1F758000, 0xA2773BF5, 0xB382157F, 0xA2EF7D9E, 0x68C037D6, 0x003007C0,
    0x00000000, 0x00000000, 0x10000000, 0xF67B9F6B, 0x47B7180A, 0x21F7D188, 0xBDF731FF,
    0x1BF13F77, 0xC0EF589E, 0xB1DA3AF8, 0x0E392B01, 0xC667FFC0, 0xC40257B3, 0xE7FFA31E,
    0xFDC806B7, 0xFBD5199B, 0xFFDEA097, 0x9DA8CDF9, 0x56F7A880, 0x17C400BC, 0x803FFE4F,
    0x29E39118, 0xFB4393C0, 0xCFF4607A, 0xEFB5B66B, 0x87E97BBD, 0x18847BB5, 0xF7182F6B,
    0x00000007, 0x56EF73C0, 0x8007DEF7, 0xEEADDEE7, 0x00000FBD, 0x00000000, 0x00000000,
    0x2C200000, 0x8098C640, 0xE1B7BDE5, 0x7BEE295D, 0xBEE7801F, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0xE0001000, 0xC79700D8, 0x8C3E600A, 0xEFA85D8A, 0xBF99BC0D,
    0xC9EFEF7B, 0xC835EE46, 0x790FFF7A, 0x66FB0037, 0x630018D6, 0x007E3A54, 0x2627873F,
    0x33078CC0, 0xC262A01E, 0x1F8E05CF, 0x5101518C, 0x162F8063, 0x1580F8AC, 0x80B17C1F,
    0x51C92358, 0x7C7CF801, 0x87C8C00E, 0x97C00B27, 0x3001F955, 0x8007BF9D, 0x02556A78,
    0x001C46E0, 0x601E3278, 0xF7BC04DF, 0x3FDBCC01, 0xB0172805, 0x9181B2ED, 0x1A8A8051,
    0x8CCFC059, 0x8A8A2302, 0xF9F19E01, 0x7ED97283, 0x6397F230, 0xA278AD81, 0x8BF1E7E0,
    0xCF02A782, 0x8F48D408, 0xFC362A3F, 0xE47E3915, 0xE5056C28, 0xCBF078F2, 0x720393C1,
    0x7891BF14, 0x501664FC, 0x20FC7231, 0x81FCA3C7, 0xE03C7A9F, 0x01476397, 0x091EF623,
    0xB005551E, 0xE407E79E, 0xEC02E2F8, 0x52FC0288, 0x801C9401, 0xEF780547, 0x97DEF00B,
    0x35016737, 0x3789C5F3, 0x3038DE20, 0x2FC1FCDE, 0x3D5601DF, 0x0B53CF0F, 0xE22FC5F0,
    0xFC401F17, 0x17E2FBE2, 0xEAA79E00, 0xF2F00079, 0x388DC002, 0x7CC77800, 0x735005F3,
    0x8059AAF4, 0xC6F0E378, 0x9D97C017, 0x6607C764, 0xB55984D5, 0xF01F1D90, 0xF1383BC5,
    0x717E200B, 0xFC003DE5, 0x03C5666F, 0xE3A47230, 0x9E3E7C02, 0x2C5400AC, 0xCA81313C,
    0xC07E7C0A, 0x31AC81DF, 0xC702CAC0, 0xC03C4F07, 0x1F8E0B13, 0x3C43C660, 0x0E7E0063,
    0xA3007E2B, 0x0263FC2A, 0x15599BF8, 0x8F7C6600, 0x6F95800B, 0xC4F8003C, 0xFC318004,
    0x0C722000, 0x03F15800, 0x00099F00, 0x800278CF, 0x802F3F98, 0x7A379EE7, 0xFA888800,
    0xEF718016, 0x7BDEF7BD, 0x000FBDEF, 0xDEF7B8C0, 0xAFBDEF7B, 0x9D18007A, 0x9C71001F,
    0xDFCBE000, 0xF9ADE000, 0xBD673000, 0x0FCE8C00, 0x004E3880, 0x006FE5F0, 0x007AD6F0,
    0x00356678, 0x001F97E3, 0xE0009C71, 0xDEF7D8CD, 0xF7BDEF7B, 0x80000046, 0xED602DF1,
    0xE7EAC035, 0x3E3D905F, 0x9405E7E0, 0x004C8807, 0x00000013, 0x00300000, 0xFE38092C,
    0x05557C60, 0x1FCCFDFF, 0x9FBFE000, 0x57C603F9, 0x0D8E00F5, 0x00301258, 0x00000000,
    0x0244402C, 0xEB80513C, 0x17A9EA02, 0x0BB9CDF0, 0x711CF778, 0x00000017, 0x00000000,
    0xBEB00000, 0x1BB5C801, 0x6ACFFE78, 0x025637C0, 0x29403F5E, 0x10026440, 0x00000000,
    0x032C0020, 0xEFE01690, 0x1BEAAA00, 0xFED66FC0, 0x737E0003, 0xD4F0FFFD, 0x0ED826F3,
    0x32C04D20, 0x00000100, 0x11180000, 0xB803C540, 0x2CD5F02E, 0x5F33F678, 0x00BF7390,
    0x3BBB9EF1, 0xB90EF900, 0x176B1867, 0xE6F4E6B0, 0xF93F773A, 0xD654702D, 0xAD7C61D3,
    0x7ADE21BF, 0x7D60D962, 0x667BECF9, 0x4059CCFE, 0xEE6295ED, 0x00000000

  EW_FONT_KERNING_CODES( BezierClockFontXXL )
  EW_FONT_KERNING_VALUES( BezierClockFontXXL )
EW_END_OF_FONT_RES( BezierClockFontXXL )

/* Embedded Wizard */
