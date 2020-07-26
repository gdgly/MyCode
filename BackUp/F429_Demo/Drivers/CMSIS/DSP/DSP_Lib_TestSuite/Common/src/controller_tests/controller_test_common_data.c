#include "controller_test_data.h"

/*--------------------------------------------------------------------------------*/
/* Input/Output Buffers */
/*--------------------------------------------------------------------------------*/

float32_t controller_output_fut[CONTROLLER_MAX_LEN] = {0};
float32_t controller_output_ref[CONTROLLER_MAX_LEN] = {0};
float32_t controller_output_f32_fut[CONTROLLER_MAX_LEN] = {0};
float32_t controller_output_f32_ref[CONTROLLER_MAX_LEN] = {0};

const q31_t controller_q31_inputs[CONTROLLER_MAX_LEN] =
{
    0xC14A5524, 0xCCABDA17, 0xAD6F5B56, 0xFDAFCE3B, 0xA9B226EB, 0x41F6F6A,
    0xA5CE38BF, 0x3A978AFA, 0xBA44B82A, 0x855C0F8, 0x3D060524, 0x93D5E570,
    0x97D7791D, 0xFFE0C38C, 0x26749841, 0xC0A6EE54, 0x218EC386, 0x39FF3726,
    0x8DC1F7CA, 0x702F2CF5, 0xC1142FF1, 0xEC1476AB, 0x15F640DD, 0xE62CCE49,
    0x3805DE7E, 0xF70871FE, 0xCF8BD360, 0x8D19A8A0, 0xD764F821, 0xA58558CF,
    0x8C0CE04D, 0x50A46C19, 0x66D2370D, 0x50FA359A, 0xB646AE24, 0x6CE00F5C,
    0xE6D48948, 0xB55BD831, 0x3B72950A, 0x9EB69530, 0x73394127, 0x773FA6F4,
    0x9805A980, 0x838DE587, 0x9CF597F4, 0xA2AD1691, 0xFA81A473, 0x7CDC7D7F,
    0x4A5190D0, 0xED895BB9, 0x8FD60F35, 0x1A21D530, 0xA0EB6DDA, 0xBDE6A516,
    0x2501A3E1, 0x5ED893C8, 0xE1E175B1, 0xACBBB2F3, 0xED350907, 0xDB140D7E,
    0xEEAE272D, 0xBE229841, 0xC18BFB88, 0xA6BB9B80, 0xBCF090E4, 0x24DB166C,
    0xF9AB7E42, 0x62DF28D1, 0xC7004665, 0xE3F56FC6, 0x419E0C75, 0x46BE9F38,
    0x2432B9B2, 0x758D83E0, 0xDCE12926, 0x3F57CB74, 0x1F4458E2, 0xF1DD639,
    0x83A1FB49, 0x173AFC76, 0x86EF7531, 0x48D32F34, 0x7D3E3063, 0x8F2FB549,
    0x5C314C9, 0x18CBEB6D, 0xA6F8B697, 0x447B9E9C, 0x2E32BA33, 0xD074D715,
    0x81ACD746, 0xE55A4E04, 0x4891860F, 0x1DA3EB4F, 0xE0E6A27F, 0x20BFDEB4,
    0xD0B3A25B, 0x40C10544, 0xC15656C, 0x15405EAE, 0x9858E3E1, 0xA36A9C4E,
    0x88BD21F9, 0xAACF7A68, 0x773665E5, 0xCEDFDF66, 0x617A9610, 0x524FC968,
    0xC2D086CD, 0x5F008079, 0x24DCA447, 0x6A4F5599, 0xB706CD4A, 0x1DE70608,
    0xA33A2EE5, 0x137E488E, 0x98061B7B, 0x4079D69D, 0xA4A897D5, 0xC4CEC8F5,
    0xD75F7883, 0x22406802, 0xF1AD70BB, 0x9D4ADD79, 0xBCBC7CE4, 0xB358C0D8,
    0x85792E47, 0xA7ADAC05, 0x3D19EEAB, 0x331AC0AF, 0x33035831, 0x13D93987,
    0xFC542094, 0x845F317E, 0xDDC4BF8B, 0x1379E50C, 0x5C20193F, 0xFDD58298,
    0x9D482B82, 0x4A6BE062, 0xDC8A757B, 0x272917C1, 0x90E1EFBC, 0x355AD882,
    0xE6F8EA35, 0x604555A1, 0x7DFFFBB, 0xF58AE216, 0x9A11B463, 0xD3541BAD,
    0xA1576756, 0x483BED8D, 0x1F05AFCC, 0xCEA63DFB, 0x55B84677, 0xFB2E04F2,
    0x787AF96C, 0x84A12CD3, 0x460A9BD, 0x9DB22DD8, 0x1A8C7F28, 0x861E452E,
    0x932D3F78, 0x7652D852, 0x73357BBA, 0xEBBB0A58, 0x62536AFA, 0x3F6B65EF,
    0x6DC57B58, 0x9EB798CE, 0xE6B0A740, 0xDFF68B47, 0x3247FB8F, 0xFFF3D302,
    0xA9FD3E40, 0x475A43D1, 0x6FF9528A, 0x2018A09D, 0x47E0F9C9, 0x4CF5F6D3,
    0x2807CE34, 0xDD6FD8ED, 0x234045D1, 0x51CEB5F9, 0x25297896, 0x6443A0FE,
    0x8F4449A9, 0xD4C3E1C6, 0xF01D52F1, 0x4E09C820, 0xF18F0810, 0xE1548689,
    0xF9DE5A1F, 0x5286DC23, 0x48AC3A4B, 0xEA0C1BE0, 0xA1B785DB, 0x7086465D,
    0x1CC10929, 0x1E1D716E, 0xED231D4C, 0x2049D108, 0xB8FF9971, 0x949CF8D4,
    0x441F1E8B, 0xC3D95372, 0x69C324B4, 0xA10BFDC9, 0xC781DE78, 0x82476137,
    0xE163DDF, 0x390DEEC2, 0xAF68CE5B, 0x8E680ABD, 0x8223A615, 0x92593380,
    0x7B1465FE, 0x865AE957, 0x930F53EB, 0xED772EF7, 0x10E916B6, 0xE3BCFA68,
    0x2ACB80BB, 0xE51C5590, 0x994714B5, 0xF30984EE, 0x59BBE1B4, 0xB4867DBC,
    0xB91C706C, 0xBC16C218, 0xA8931CD0, 0x129A66AB, 0x13171F4D, 0x62882872,
    0x4B167FD4, 0xE6902F4C, 0xFA794932, 0xD4B152C, 0xB0856EA9, 0x39466D55,
    0x3669E451, 0x8F5B9E8C, 0x877A3C6A, 0x51B956B4, 0x367EAD2A, 0x9D2C662A,
    0x78FB6880, 0x4E6D40B6, 0x4070EFDC, 0x4DF9679C, 0x20306EDB, 0xE381AAE7,
    0xA55DA748, 0x9B8B617B, 0x3E036FAD, 0x84E4C4A7, 0xD5A3F517, 0x669BA988,
    0x98FDDE8C, 0x67BD85CE, 0x34BBB46C, 0x76994800, 0x85B9D8B6, 0x6DFA2FEF,
    0x205DB5C, 0x9F843C4C, 0x72721B52, 0x73EF6B86, 0x5FB98B61, 0xC323DDAC,
    0x31D424B4, 0xF68C0D7E, 0x162FAF9D, 0x7B2A7A99, 0xF9392693, 0xC42D12C0,
    0x8692A73E, 0xD9A1EE80, 0xDD956856, 0x44E7BDAC, 0x8D874532, 0x5F5C9DD0,
    0x5D167858, 0x8559FEA2, 0x9D821476, 0xD9654ED2, 0x594C0DC7, 0x1A87B506,
    0x3F693200, 0x7A651AB5, 0xA0CCBC8A, 0x9F9E662C, 0x78EF631, 0x2A09DA0,
    0xB088C72F, 0x92EE0D42, 0x360DCD5F, 0xF333FE48, 0x8D63CC06, 0x233A8ACB,
    0x706651ED, 0x7AA5C079, 0x262239D1, 0x3EBBEBB6, 0xA25A4F3D, 0x32581A06,
    0x6E6FD780, 0x5773F7C7, 0x75ED1DDC, 0x90DF2D15, 0xBC79A9BC, 0xB7175917,
    0x354E381C, 0x762AADD7, 0xF643DAC1, 0xF3BBF49E, 0xD2FECE7E, 0x6C8140F4,
    0xD7694875, 0x92D30822, 0xC742A7CF, 0xB792ED98, 0x121CFE24, 0xA04E1EE7,
    0x58CE268, 0x215A080, 0x316CB323, 0xFAB14A31, 0xE1C13C03, 0xFD8EF4F1,
    0xF3F446D0, 0x6C6CEA0A, 0xBBFDF9FB, 0x67242969, 0xBE55A4EB, 0x8FF5534,
    0x52F0DF1C, 0x9710ADE3, 0xD40F4A21, 0x7984E8E7, 0x419545EB, 0x993F7880,
    0xAB246B20, 0x408AABC4, 0xCBF6EA49, 0xC0894C55, 0x4CAA6398, 0xA47856E9,
    0xAF2AE47D, 0x22F55D33, 0xF0D37915, 0xD0634C72, 0xD983671, 0x2BCC5AF8,
    0x9A77D48, 0xC11B5CFA, 0xF107CD7E, 0x3A6B3593, 0xE1425F05, 0x6271812A,
    0x5B838310, 0xBD8418CA, 0x10A58792, 0x239F7137, 0xA13D5071, 0x7F9930D4,
    0xA462664F, 0x54180F8E, 0x291585BA, 0xE586B87A, 0x144B2C12, 0x98E425C7,
    0xBAA4B373, 0x18F0D03C, 0x99462AC0, 0xD8B4D2EF, 0x72473895, 0xA6BF5435,
    0xEDAD53B, 0xE0912FA6, 0x5C33F331, 0x3D93CD7, 0x4D03D752, 0x20699929,
    0xB89962F9, 0x36E781E9, 0xF58B642C, 0x5FCA69E3, 0x5960A7F4, 0xAD5AAFD0,
    0xDF18324A, 0x3DB1E5AA, 0x76BA3876, 0x1BC29AF6, 0xBCC18841, 0x73A60174,
    0x625BFF58, 0x67C57724, 0x4458E53C, 0xE157B095, 0x2B370837, 0x83DF6CE3,
    0xDD08EEFA, 0x3F52A7C2, 0x191B4785, 0x60843D82, 0xB0DE11F1, 0x105EA26C,
    0x6E1C7AA2, 0x47AADD14, 0xB6676D03, 0x3B8D4DF6, 0x737A694, 0x409521DC,
    0x744206A, 0xC722023F, 0x2BE4EAD5, 0x63E11D76, 0xCA4A09AB, 0x5CF2D2B9,
    0x31586916, 0xCDFD7D84, 0xB203F634, 0xAD7329D4, 0xC524582F, 0x2E53E6C1,
    0xBB0E019B, 0xB8538C6A, 0x6A2542D, 0x8A6A00E5, 0x119725CC, 0x5406D347,
    0x1B6FFAF1, 0xECCF71F1, 0x981117F2, 0x7167CA76, 0x74F4B880, 0x77A55F47,
    0x59EADB62, 0x4A331D95, 0xBCBBA76F, 0xA45C4D50, 0xC718D5, 0x87CE05D1,
    0x60D47AD5, 0xA5CA9C40, 0xB0061766, 0xE69B39DF, 0xBD5F1320, 0x9930EAD3,
    0xA8B38325, 0x8DD090F, 0x6A6EEF37, 0x2DF16F66, 0xAB514C7E, 0x31109C58,
    0xFD48C7FC, 0x515341CA, 0x77AB8EA6, 0x41328DAF, 0xBAF8D31E, 0xA4B31611,
    0xED37F331, 0x7A832A22, 0xA22591C7, 0x722D1F89, 0x3B19CF18, 0x261B8A4D,
    0xC3F6F6DB, 0xCF8CED61, 0x990FA250, 0xA02E72A9, 0x560DCEA2, 0xB08E67B4,
    0x3674E663, 0x97CC3852, 0xA7EB2EAC, 0xFFDE0AA8, 0xA64719A, 0x23269EDD,
    0x3C0B339E, 0x86284D40, 0x48D82ECB, 0xA4D4CCF8, 0x43631B91, 0x4BF0C248,
    0xB6497B9B, 0x6827BC58, 0xE30B7AF9, 0xA0CCBF26, 0x6C3B7B71, 0xD744B3ED,
    0xFA25D2F6, 0x4CDE642D, 0xD65B8142, 0xA6F9207F, 0xE7A207BE, 0xDB506684,
    0x44DA4780, 0x9175EA0C, 0x156104AF, 0x4155E1B0, 0x6E3A6886, 0x9DBA1EA2,
    0x5423D9C8, 0xCC024E22, 0x758F852A, 0x1DD6395, 0x2D19CBAD, 0xE164F5A1,
    0xC2084602, 0x89C274AD, 0x13CB5562, 0xD7FE2D5B, 0xE07A4EE5, 0x1672BA91,
    0x4F624CCF, 0x2E5EA4A3, 0x28FEEFAF, 0xBDDA6EF4, 0x32AFD40C, 0x99A5FB3B,
    0xDD1D73A3, 0xA342CB3E, 0xA78445F5, 0x53979C3B, 0x427D7943, 0x5221B58C,
    0xA6CE9A5E, 0xFB50ECA4, 0xBB86E36E, 0x60839F6D, 0xC5E1C2F3, 0xA1B7FB04,
    0xFBB65E0C, 0x78B80F5E, 0xFD8D972B, 0x3BF3BA90, 0x2D572D9, 0x2B5BC920,
    0xB6A0DE01, 0xD274D306, 0xC7C6C855, 0x9CAA669B, 0xB04AA641, 0x4D6B1760,
    0x3E17ED79, 0xD23241B0, 0xA4A6F957, 0xCBDE76AF, 0x4E5F9493, 0x4C215DA5,
    0x33A052B, 0x1A4D80C2, 0x40AEEBCA, 0x390D106B, 0xE9E8E018, 0x5AF3D6CF,
    0xE35E1D4, 0xC4FB1C6, 0x14B6299B, 0x8D2E25F0, 0xCCBF932A, 0xC5AC18B6,
    0x2227567D, 0x86B5CE2F, 0x26344534, 0x22C515EC, 0x2442B70D, 0xEC3721C6,
    0x34EF687D, 0x9C06323A, 0xEAF3EA60, 0x60396F52, 0xEAE78AA1, 0xC9D06CBC,
    0x6F95F6C8, 0x584CC258, 0xBA9A27BB, 0x66DF8D47, 0x9D4804EA, 0x57DD9E67,
    0xF89C7895, 0xF5336111, 0x25C122C8, 0x62742114, 0xCFBF6D26, 0xBF9F6482,
    0xE6F02CD9, 0x11083202, 0xC99E2618, 0x7EBC9351, 0x440112F1, 0xC9DFFBC1,
    0x3BF4DC25, 0xB1BA7FA0, 0x61AF9AED, 0x6B1F7D29, 0xAD865294, 0xE3E01129,
    0x7E9E77A5, 0x100435D7, 0x9FE3A71, 0x88597C81, 0x722849FA, 0x31C5A0AF,
    0xFBA178DC, 0x7F102D31, 0x5CA07864, 0x950E6F98, 0x82C34882, 0x5D041F11,
    0x8C613C57, 0xD398CFD1, 0x426F38AD, 0x5599AB1D, 0xFAFA078D, 0xAB25B413,
    0xD94B32CF, 0xB288FE38, 0x2893BB46, 0x9A0B4168, 0xA91BCA94, 0x653A5E8D,
    0x2174EBBE, 0xDEFE6415, 0x30DA429C, 0xD0C5E40C, 0xB4719AA4, 0xD29CE7A6,
    0x905957CD, 0xCD287499, 0x83CA0AA7, 0xA8385832, 0x25A0CA02, 0xC20D47A4,
    0xB562F556, 0x4BC19E4C, 0xD9E215C7, 0x27E838B4, 0xC58612F4, 0xA2827F6F,
    0xC49DCDBA, 0x679B7362, 0x4E495845, 0xCFD2F0D1, 0x395E76A0, 0x375A655E,
    0x92E2058F, 0x73F9F0CA, 0x61EFF3B3, 0x51FFD362, 0xE7410345, 0x7FDA8B3B,
    0xA219E2E8, 0x17ABE543, 0x26557412, 0x4B30084D, 0xA68E191D, 0xFE0D93DF,
    0x73EF127D, 0x4DECDDB1, 0x77FAF45F, 0xD6002898, 0x92DD0A40, 0x157F6DDF,
    0xC2A55F8E, 0x4359F924, 0xFB630C3F, 0x338B6B58, 0xB2945F75, 0x4FA23A0E,
    0x836EB8C0, 0xB3B18FD, 0x86114337, 0x24668ACB, 0x99BB82F0, 0x924C8A47,
    0xBA959701, 0x81155ABF, 0x8C612D71, 0x36074CA7, 0xD1668C41, 0xE35F58C7,
    0x7FC2802D, 0x8E6A7CF3, 0x65B07D07, 0x815F6A6B, 0x791BF0DD, 0x6E47D719,
    0xC24394C7, 0xE84A6EB, 0xF194AFEE, 0x464A2F52, 0x677579FD, 0xEBA775AE,
    0x1F6EEFF, 0x9A795237, 0x78D9D45F, 0x9D0B344D, 0xBBD34AB7, 0x2F85B12A,
    0x16C5C2AD, 0x3990985D, 0x88DF3351, 0x82811AA5, 0x6D351F41, 0x4066A69D,
    0x86B660BF, 0x6EDB4768, 0xDDD78CF0, 0xB5D74F6E, 0xE89E220C, 0x91439687,
    0x947CC9C9, 0x3857E2BD, 0x302F8AE4, 0x1DABE7F8, 0x4832D6C9, 0x37D58FCB,
    0x4EA8A711, 0xCD7BAC98, 0x19DBF8BC, 0xD8DE8DC2, 0xEAFF7E7B, 0xB7629C93,
    0x792C6E19, 0xF7009192, 0xFF88439D, 0x2E196A66, 0xEC71B78C, 0xEAF4BB3A,
    0x7C16225E, 0x668F337, 0xCBEE1608, 0x6D5B5552, 0x345DC590, 0x681209CC,
    0x7B24A819, 0xD08A1416, 0x99888FE3, 0x9FC7288A, 0x24BD8502, 0xEA1D9678,
    0x20EECA0, 0x59BEA057, 0x5ADE91EB, 0xDEA8E49D, 0xFA200E6F, 0x9149C81D,
    0xF2281E93, 0x8A5B0451, 0x67312D58, 0xE3B849F1, 0xD2217960, 0x7CDF59F3,
    0x33C775C0, 0x9EBA8799, 0x7DF9506, 0xB4E96110, 0xB8FCF3E3, 0xDEA059B2,
    0x8229B6EA, 0x316486F6, 0x43919185, 0x6C0D90F3, 0x1C6F3DF8, 0x38DB92A9,
    0x5CD41244, 0x2C9F0A7B, 0xDF4A315F, 0xF7CE9C66, 0x4C800860, 0x318D53E0,
    0xF105C20D, 0xD753E1F2, 0x750810BA, 0xA17ECCA5, 0x2010140, 0x4D884763,
    0xC2BB0DA7, 0xB2D5BA74, 0x141CECD4, 0x887FDFC3, 0xC64B53, 0x2D2A85F6,
    0x15532B45, 0x5D5CBCE1, 0xBEB9A16A, 0xA214611B, 0x9FC5AC5F, 0x11AE5DD7,
    0xA0B9A5A9, 0xFC648AF4, 0x740009AC, 0xED0E0321, 0xB8E6A61, 0x8910C544,
    0xC74F26C8, 0x9525CCF3, 0xB41AEB59, 0xE61984CE, 0x598B2197, 0xA412E59D,
    0xE1976DD4, 0xB29BBE16, 0x88FD9FB0, 0xB04006F3, 0xB45E309, 0xD5CC15F1,
    0xD9DAF630, 0xDC809335, 0x803ED52, 0xB537F5A5, 0xA994F6EB, 0xF5288568,
    0xF66FD264, 0x2EA2B3A6, 0x647619F3, 0xFFB38C7A, 0x1BC03B9, 0xB6BC3061,
    0xBF30596E, 0xBE2AD27B, 0x8AC04220, 0x641979A3, 0x9ECCBB89, 0xA144FBC1,
    0x4E8FAE26, 0x8C5A9D90, 0x299ED467, 0xD7C9C7E3, 0x1D4865ED, 0x76F31C3D,
    0xCEE81CDF, 0xB479195E, 0x6FFB3AE1, 0xDC8A398, 0x300F7364, 0xC7940AFA,
    0x3B85BE3E, 0xD98CC40D, 0xA24A3D89, 0x3A674204, 0x22888A38, 0x2E77F2D,
    0xA2841C9C, 0xCF0689C3, 0x9FE98922, 0x89335017, 0x2D6B69A7, 0xFEDB63F9,
    0x899AF4EF, 0x9F9F9B40, 0xA4BE97E8, 0xA51DAF7A, 0x16AC50D3, 0xA8D7ED6,
    0xED193443, 0x7615EF1B, 0xB0DF6A4E, 0x64FFE794, 0xE3DB2C9A, 0x7435B022,
    0x556E825C, 0x23802AF9, 0xC25098A4, 0xE75A18BB, 0x70B2A7B9, 0x7FB81BF,
    0x63EF910, 0x6C669591, 0x6574DD2B, 0xCF6E379D, 0xD2B3AFAC, 0x1E6A1101,
    0x1DE22385, 0x2338191F, 0xC69704B6, 0xCBABC599, 0x54EB4809, 0x7839BE6D,
    0xD50017DD, 0x39B1A0E1, 0x288D52D3, 0x2D52668C, 0x20D22A68, 0x4E1207D1,
    0x3FCC0EFE, 0x47F3FE64, 0x25177A90, 0xB4BFDD4D, 0xDA8DBDCE, 0x6F7275A8,
    0x6BEAA655, 0xAA1810FC, 0xE4DB593A, 0x8A4D4BC0, 0x2C402E93, 0xF1C0F7F9,
    0x6F0CC577, 0x70412414, 0x752F9DC1, 0xD82E38EA, 0xAC455F7B, 0x4DCD4EDB,
    0x92BC2696, 0xFB03F135, 0x4FCA1F8C, 0xBD5E75F6, 0x502F41B0, 0x3616D3F1,
    0x2E5B8E31, 0x2026EB19, 0x57E783D7, 0x467BBE00, 0x4703ABA3, 0x1F776B9C,
    0xE2570A84, 0xFEC7DB48, 0x1BD5012, 0xFD0A2D5D, 0x7FCC29F2, 0x291304B6,
    0x99D5D8ED, 0xC7551C8, 0xFD12F38F, 0xBADE8892, 0xDF749997, 0xA5DAE2F,
    0x2B9FA269, 0x5C13CFED, 0x15E9A399, 0x54437F4E, 0xA72DB2AB, 0x56186AA1,
    0xFE4DB55C, 0xA34D7836, 0x2A879760, 0xC63FA94, 0xAC18B207, 0x5FC78B3,
    0x7F10621E, 0xA769E6B2, 0xEC9F4A11, 0xCE3F982C, 0x62BA2EF5, 0xA5F239CD,
    0x73D63FED, 0xE36E9F5E, 0x8AC1DA0E, 0x3F3DB3EB, 0x738326EA, 0x35C366B1,
    0xCD476E86, 0x82F6B208, 0xF11A9FC1, 0x426AC396, 0x7E4D1B93, 0x75E4EDB7,
    0xAF3C44A7, 0x51A5EF5C, 0xFAD2463D, 0x8A5639CA, 0xC995AC78, 0xCC4BE4F6,
    0x3AFE7F8D, 0x66993D04, 0x4386FF37, 0xCBC1C6C2, 0x55A8F5EC, 0xE81A9A75,
    0x30A67E1B, 0x4A4A7D0C, 0x20F7F993, 0x1891805, 0x738976AD, 0xD426E7D6,
    0x3C5CEEBF, 0x4499187F, 0xABF17C97, 0x447C317F, 0x68D8419C, 0x7AAB6456,
    0x421BCF29, 0xF6740F9C, 0x8916BB8D, 0x3D72AAB, 0x9AD54DD7, 0x7549C6EE,
    0x7317342B, 0xA18546D4, 0x1056BDA7, 0x54BBCCCE, 0x8CE63E46, 0x5D146234,
    0x33BE6C63, 0xB250C4E5, 0x89D72335, 0x87C36BA, 0xB65530CC, 0x2DFAC48C,
    0x1663D16F, 0x59B80AA, 0x950274EA, 0x92532D4A, 0x3CEF802D, 0x492FBDA5,
    0xA63A2574, 0xEF8005C2, 0x94A18651, 0xAF627ABA, 0x6829B238, 0xA698F646,
    0xD2598516, 0x10144D36, 0xD9B1D1B9, 0xAB2ACF05, 0x5395B699, 0xA7851C75,
    0x1806C6F3, 0xAE970306, 0x3284B145, 0x98F4FE8F
};

/* The source data is random across the q31_t range. Accessing it by word should
   remain random. */
const q15_t * controller_q15_inputs = (q15_t *) controller_q31_inputs;

const float32_t controller_f32_inputs[CONTROLLER_MAX_LEN] =
{
    43.0264275639 , -17.0525215570 , -94.8488973910 , -8.1924989580  ,
    7.2830326091   , 66.8368719314  , 33.9778190671  , 117.8652289772 ,
    -129.6077797465, -14.6420815368 , 18.0239223278  , 20.6760530292  ,
    55.0375037651  , 1.8674609862   , -85.6534302408 , -33.5750364909 ,
    29.2110949614  , 110.4727049460 , -94.1914619387 , -1.4084169343  ,
    83.5181653041  , 47.3073514127  , -13.3420621181 , 30.3389699104  ,
    12.1188124277  , 100.9730921941 , -114.0146362390, -77.5823200409 ,
    37.2019034618  , 40.0026301128  , -58.3387276630 , -34.9472398600 ,
    -5.1169678311  , -87.7660091118 , -150.5888601131, 56.0349370503  ,
    50.2168884079  , -74.2313236767 , 22.3648603560  , -6.8676387051  ,
    74.8957303680  , -90.1292012823 , -55.1436241586 , -66.6732976100 ,
    -6.7918147615  , 7.7612697081   , 35.7892605979  , -20.0470508830 ,
    41.8369017546  , -143.7378056984, -41.9127158600 , -108.3531841158,
    -57.1917422289 , -124.2808828105, 38.9316388820  , -77.9212517405 ,
    37.1990818377  , -28.9545952748 , -155.6371057564, 45.8088886393  ,
    36.2537018275  , -6.5727656016  , -104.2070491921, 45.5583813729  ,
    -19.7674717059 , -80.4802190947 , -1.4444563441  , -42.2142256438 ,
    36.6546339194  , -57.0866498590 , 44.4677067511  , 65.7285753407  ,
    -103.8158864647, 25.4348723711  , -153.5419639389, 39.3608409474  ,
    49.1658103436  , 79.5570602275  , 75.2944095996  , 58.9394700746  ,
    -53.1018534392 , 33.4172444014  , 35.6224682287  , -64.4353396418 ,
    -125.8464291251, -47.6072111617 , -26.2177687594 , -12.0061322096 ,
    -17.7887967585 , -28.2926175090 , -62.0691715749 , 40.5098573604  ,
    -191.1123732593, 119.6750713043 , 19.6182375803  , -26.7615252921 ,
    2.2957847015   , -108.3436451287, -50.5906164995 , -5.6360985100  ,
    -11.6772204201 , -84.2765293757 , -60.9317810068 , 82.0446350218  ,
    -70.2048296348 , 72.8738253222  , 60.2450218115  , 114.2741231228 ,
    46.8180775285  , 6.9915412654   , -8.9909197429  , -78.9165936808 ,
    66.4731535459  , -68.4235455651 , -79.8254597080 , -10.6308477115 ,
    -62.6161569330 , -55.7744410292 , -11.8408366528 , 98.1034940997  ,
    35.8213741877  , -54.4694482732 , 86.9631830044  , -53.0343838122 ,
    -47.4898642865 , -47.2010929590 , -31.3312639685 , -23.0908245172 ,
    12.0258009869  , -5.1098204703  , -9.8420230737  , -107.3328761158,
    44.6810431959  , -17.9083820345 , -60.9753512872 , -7.5915088994  ,
    17.2250813329  , 57.9176125648  , 124.3004161362 , -63.1950908493 ,
    120.5788885640 , -44.1734238117 , -91.7408095116 , -43.5696066595 ,
    -49.9560710099 , -167.8513443296, -70.9437505499 , -46.4109705355 ,
    -64.2264526456 , -13.9995803916 , -100.9548186356, 9.9101010575   ,
    -50.0615130815 , -55.7590145012 , -60.3195153388 , 61.7913378549  ,
    -102.0850899209, 53.2360193126  , -25.8997883369 , 75.1445512333  ,
    -113.8148602310, 17.8027281119  , -19.5006822722 , -44.2169628471 ,
    107.5017084384 , -113.7909124666, -43.9735396033 , 7.6880981388   ,
    46.7384653508  , 9.9047443751   , 81.8646964362  , 132.3812863877 ,
    -95.6959050236 , -68.5015813484 , 65.8586404494  , 18.5039353889  ,
    -30.1786166621 , -90.3098515667 , -22.9356228552 , -20.5778272423 ,
    -2.2127786675  , -35.4418447703 , -51.8722915974 , -107.9024439078,
    -51.5940748232 , -51.7463262677 , 74.2795485984  , 94.2205022462  ,
    9.7016384049   , -47.3556083155 , -36.7822314478 , -151.6455525363,
    -15.7183814485 , 78.2063383182  , 0.1516414969   , 37.9304181609  ,
    20.6185902740  , -22.2164106778 , 6.1160554677   , 2.4061326953   ,
    -111.6681824598, -60.0858917090 , 75.1698614693  , -76.5787410444 ,
    28.3391655715  , -2.4946186443  , -68.0378899682 , 104.0893199171 ,
    -51.8319647254 , 38.8521710524  , 75.9114239564  , 73.9206172905  ,
    -103.2533029987, 6.9002718274   , -36.6346436319 , -25.1990926265 ,
    1.5852145953   , -50.6438436795 , 21.5018844428  , -151.9305562846,
    -51.7326681814 , 21.4475994143  , 42.2564011921  , -74.0520586926 ,
    49.7370635809  , -13.2957534126 , 36.6746826778  , -31.7005492589 ,
    148.4894964268 , 79.7890632353  , 16.8856024809  , 16.1690460177  ,
    39.2665169484  , 117.2461167794 , -37.4827984831 , -47.8387803604 ,
    -95.7025286193 , 34.3058214285  , -124.9536456028, 56.1640195764  ,
    94.3636873606  , 35.3992852810  , -38.3920852159 , -100.5738062016,
    -29.7837022314 , 42.9133913996  , -34.2715618187 , -14.3589115627 ,
    -16.5935468750 , 20.4574192236  , -88.7897972666 , -38.6285080386 ,
    53.3203422726  , 98.5991486746  , 122.7305462474 , 67.7902817187  ,
    5.1764117389   , 5.0632821624   , 21.9288789574  , -78.3140512638 ,
    -21.2069682335 , 23.6342010925  , 34.4445769455  , 59.1346766615  ,
    28.9978778000  , 39.8121180845  , -17.1650033520 , -56.9174900874 ,
    17.8157086148  , -112.8801457350, -122.4019040408, 140.8669393157 ,
    -65.4664329639 , 40.6952775518  , 32.7260891658  , -43.2565155866 ,
    19.3945751928  , -20.1815002000 , -67.6601711640 , -18.1921178207 ,
    -35.6802153684 , 49.9550290306  , 131.4925251016 , -31.2940938167 ,
    -5.2848453344  , -109.5580577933, 20.2437599390  , -8.8782958734  ,
    54.1836717264  , 7.2555852190   , -3.5698316137  , -51.9236786262 ,
    6.7861547980   , -104.4814551670, 45.8458629668  , 70.0890876844  ,
    38.3572837740  , 61.8024165129  , 68.0176962024  , -12.8193934080 ,
    -21.4661610917 , -0.9377108815  , -74.2100679061 , 71.0490808147  ,
    91.9813889497  , -14.5797640164 , 3.5036749129   , -138.3605478356,
    -48.1501349794 , -16.0636922482 , -12.1334197606 , 15.0562207637  ,
    -34.0878176054 , 55.1075126157  , 97.3829871877  , 0.2053358099   ,
    -94.8713267382 , 51.5460954054  , 21.2966946363  , 58.1331025047  ,
    -23.4599044132 , -19.3315856528 , -8.4497193577  , -1.9594679356  ,
    -33.1906549336 , -144.6825417978, -57.1218958072 , 35.7353406097  ,
    61.4666549819  , 14.6536253128  , 82.1632196866  , -44.6230161723 ,
    -91.1022589278 , -18.5737673927 , -136.8975612334, 56.9606788003  ,
    70.7059960183  , -68.2829345081 , -10.2629800455 , -53.6385325047 ,
    -68.7928766204 , 88.2444688302  , 83.1412324801  , -102.9206928160,
    -68.2329763159 , -69.7552955469 , 108.2132269009 , -28.2582329307 ,
    5.6685898328   , -36.0392956840 , 43.3269513128  , -8.6436416796  ,
    -16.5054886972 , 11.5008791788  , 39.6923606683  , -28.9039554061 ,
    13.5938214364  , -23.6296332202 , 49.1171161163  , 53.1636857935  ,
    -62.9672053166 , -54.2594757384 , 48.3838956696  , 8.0469071555   ,
    -33.6472086213 , -120.5381752144, 55.0880453111  , 17.8990740563  ,
    144.9402232336 , 101.7886229203 , -73.3666393712 , -16.4721379138 ,
    -12.7447935685 , 101.8245160983 , -49.7026860415 , -15.1227790364 ,
    65.7430288442  , -131.8695390036, 10.2750933946  , 90.9752774838  ,
    -26.5859990591 , -95.6962772568 , 76.2174589344  , 24.8796848060  ,
    -38.8938223046 , 54.1687774852  , -37.3585968996 , -34.6848570502 ,
    33.0151011570  , -55.8345877671 , -3.9009101671  , -31.5024971691 ,
    -9.6863895491  , 91.8719195957  , -58.9993249744 , -25.6887030614 ,
    -8.0829472205  , 4.6386491741   , -71.4019697167 , -21.3734669095 ,
    86.2079144404  , 79.6823974266  , -0.0910915997  , 44.8067718095  ,
    58.7204020766  , 72.6856808976  , -50.3373732478 , -116.1175365534,
    -15.0884909384 , 5.4593772059   , -63.6553527905 , 37.3460388205  ,
    -32.2399421679 , 95.7569350513  , -7.3700141964  , -56.0370832967 ,
    -41.7377150439 , -42.0042856519 , 12.5134312941  , 93.7845584531  ,
    -32.4801087157 , -33.3976050318 , -24.2252126001 , -46.3199064467 ,
    -20.3704610276 , 15.8571376404  , 88.9127217235  , -33.1132582267 ,
    -1.0005675836  , -28.1780471904 , 150.9349379135 , 38.0600520828  ,
    36.4338677563  , -3.3709201641  , 29.7709773016  , 16.5064119077  ,
    21.3147729463  , 110.6714300904 , 18.8406036507  , 14.8963298097  ,
    50.9975960392  , 16.3991140350  , -194.0805845907, -41.6723945839 ,
    -74.8991127408 , -6.4587655805  , -0.6883628218  , -49.8709647175 ,
    194.2265120473 , 64.3043624521  , 16.0040882780  , 68.4032551772  ,
    -43.4050313128 , 84.6826289824  , -28.1357565943 , 134.6895584120 ,
    -7.9746152680  , -95.6692886462 , -48.9444370342 , 79.4479343188  ,
    -50.5345228122 , 52.4800633307  , -14.7735051703 , -20.1510237050 ,
    22.5049816980  , 64.4191999102  , 24.8385648232  , 99.4265041360  ,
    62.0189508473  , -28.3892600378 , -109.8842008564, -79.0407483407 ,
    18.3408112020  , 49.1650536089  , 31.5419844924  , -36.1160722679 ,
    -132.9148081329, 10.4053531567  , -129.2463715470, -43.4602207151 ,
    -24.2420653292 , 91.5388317556  , 21.4762248190  , -44.3810909139 ,
    18.4098011282  , -45.8691164539 , -20.9831197962 , 16.2076792914  ,
    66.0224147666  , -13.6794615513 , 101.2163279622 , -62.4462618603 ,
    22.2040981785  , -52.3208382802 , -24.7909079016 , 58.5150375093  ,
    18.8569705105  , -55.6083430939 , 131.0273367422 , -34.5209015065 ,
    121.4357296573 , -77.2590299593 , -51.5929566898 , 5.0247131098   ,
    -23.8451707592 , -4.5912313547  , 31.1387246821  , 61.7019310824  ,
    49.1912429744  , -50.5836913031 , -74.8182600630 , -21.6209317022 ,
    20.9409464654  , -72.7870824583 , -28.3530746820 , -45.0794425434 ,
    -13.4910629905 , -62.0158772255 , -34.1421181246 , 44.2844972784  ,
    8.4213193211   , 79.9349022793  , 60.0160502260  , 32.2272994080  ,
    -72.2893887746 , 17.3063698247  , -134.6335742431, 64.6499736261  ,
    7.1411921919   , -37.5517577873 , 6.2405670930   , 117.1920927305 ,
    128.7420689815 , -3.1556854963  , -13.4100422909 , -11.9336372907 ,
    -8.6022400553  , -102.0033506666, -78.4696575074 , 15.0765861403  ,
    -111.5219718576, -13.4162786508 , 38.2437013694  , 61.1637732561  ,
    -34.4804160003 , 107.4438003830 , -79.4193067813 , -81.1842853968 ,
    -26.2622970331 , 132.3205425408 , -119.1464268477, 67.3048866598  ,
    103.3266736715 , -58.1865815617 , 27.6231908601  , -11.2004371750 ,
    26.0340617206  , 12.5696123916  , 0.6442714420   , -30.7393043544 ,
    1.5314955897   , 49.9110088250  , -106.1358721920, 51.1608329944  ,
    -32.8684239794 , -27.7215905745 , -11.6450303367 , -36.7731678028 ,
    59.9383486599  , -4.6301990580  , 5.0361682939   , -10.5669407980 ,
    124.0908762205 , 35.8305364082  , -123.6216777114, -74.2569079167 ,
    -56.7651776816 , 16.0736385582  , 23.5030632215  , -110.6764295938,
    44.3086821806  , 9.4452708243   , 5.3300080251   , 39.0483916714  ,
    151.4550562868 , 62.8957092621  , -116.8103461233, 5.1129927759   ,
    -33.2252515135 , -9.4522506046  , 22.7026048372  , -15.5264414569 ,
    71.2087620034  , 19.1191568332  , 50.3019546809  , -5.6096922409  ,
    22.9344126462  , -7.7591876203  , 31.8949515564  , -58.4253952381 ,
    66.4341297173  , -19.0583083044 , 96.7695087855  , 20.4934280047  ,
    4.9544603116   , -20.8288135920 , -173.2659655408, -62.4883621640 ,
    -48.5528422703 , 12.1437504278  , 60.2482234666  , -19.6072312919 ,
    -34.6320214291 , 129.0089698963 , -50.9042160618 , 98.3952661477  ,
    -4.7051792479  , -13.1768910826 , 69.5138802139  , 58.5748201565  ,
    -45.9385652563 , 151.7952104306 , 34.2541941013  , -58.0417838381 ,
    28.1480473670  , 46.4006562684  , 97.7001828545  , 4.0855607626   ,
    -32.6097018162 , 16.8913949959  , 105.7266202978 , -89.3978374651 ,
    -60.9338593128 , -41.2220734230 , 49.9393070783  , 95.0974764854  ,
    49.2498366456  , 58.6214364590  , 34.1113830569  , 45.6634098874  ,
    -22.5356086770 , -97.1978653617 , 86.5565049535  , 70.6118545777  ,
    -30.6978082909 , 118.7238621666 , 14.5922386932  , 11.3449652072  ,
    65.6007783405  , 82.6369678204  , -52.0390492248 , -47.0160551227 ,
    -95.5142448634 , 99.7162626888  , -36.5523815090 , -42.8042935534 ,
    68.3566199798  , -13.8451547552 , -71.1629911780 , 36.2989433752  ,
    -32.4867163365 , 112.4079947071 , -75.6295117422 , 47.5276421639  ,
    51.8078250755  , -26.8715188457 , -9.6291144797  , 40.1999849640  ,
    -38.4634033246 , 40.9764960915  , -26.1715730268 , 36.5996396515  ,
    -26.9924731886 , 53.7879986570  , -83.1658398348 , 23.6381378489  ,
    43.8794937753  , -55.4133836419 , 90.0266130838  , 14.1036181982  ,
    -18.1225736715 , 85.1363181151  , -62.5970846379 , -18.5291947838 ,
    -25.7341986703 , -49.7061342931 , -59.0442763971 , 50.8960636803  ,
    -87.6471123430 , -36.7217762531 , 22.5952364054  , 11.1107885650  ,
    -0.5377327229  , 160.8145792630 , 73.3103441505  , 10.1656872354  ,
    -50.4554350397 , -57.3478171016 , -15.4201715357 , -26.9135446491 ,
    -4.9891264771  , -37.0226770057 , -80.9919535641 , 50.4418660876  ,
    -25.8517575250 , -69.9538258421 , -17.5730160671 , 15.9405836751  ,
    113.9545230349 , -46.1040379057 , -94.2458635014 , -69.0338522452 ,
    43.5813790265  , 107.1836101171 , -55.1012654323 , -77.1529555887 ,
    -33.1530320656 , -94.5582659641 , -53.6837586872 , 27.0680381378  ,
    93.9385415207  , -61.0955216188 , 18.0530957225  , 7.9150142320   ,
    -12.1218191587 , 34.0173961457  , 40.0084937565  , 9.8119275580   ,
    44.2065861274  , -1.8718514394  , 67.4740024215  , 46.7391150131  ,
    207.2404815875 , 45.1635364462  , 43.3580102761  , -44.0244218674 ,
    83.2387206007  , -8.6441851856  , 12.3993902588  , -22.5091685270 ,
    -19.8332981376 , 97.9196509289  , -76.6720306234 , 28.9740705859  ,
    121.9415248016 , 9.6656982611   , -51.0996453694 , 37.3704374740  ,
    74.7589840907  , -113.4066752631, 120.0029566342 , -105.3786221360,
    81.8152755619  , -13.4979932982 , -21.4680758393 , -85.1088235539 ,
    -65.3610798409 , -35.0444139470 , -48.0220794487 , -41.6210317362 ,
    33.1212995259  , -82.1480936443 , -10.5479715135 , 76.4601917004  ,
    42.1983651157  , 92.6104239912  , -42.3536237955 , -24.5644182272 ,
    30.4446637772  , -90.2899420489 , 63.6723540422  , 103.0895811428 ,
    64.1706769263  , -10.7069812309 , 21.8927240409  , 6.3571071738   ,
    57.1457649358  , -52.9866276448 , 66.0981829072  , -29.5372056881 ,
    -79.2252039810 , -136.2440652798, -57.0106422562 , 86.8203548141  ,
    66.4244149837  , 53.3230426111  , -66.1283059222 , -131.0402660353,
    8.0548411081   , 122.9088988100 , 1.2626894208   , -60.5059112373 ,
    -68.8707203082 , -6.4747987200  , 85.8411327244  , 99.9624156733  ,
    90.4197864338  , -35.9630441182 , -22.9158275507 , -17.3660128776 ,
    16.7845345761  , 34.7219749782  , -39.3513765878 , 1.0460702756   ,
    -60.9494500182 , 20.0900333387  , -85.9636743832 , 88.4400782168  ,
    15.0729628728  , 61.5499846243  , 11.8579871757  , 107.8617581581 ,
    -42.9393027864 , -62.8422307621 , -19.0589600542 , 4.0750325807   ,
    -36.0651825425 , 55.7638724501  , -10.4691736080 , -55.5672537178 ,
    -61.2061519915 , -21.1885348576 , -131.2535612498, 24.7463552676  ,
    22.9426321237  , 14.3038202264  , -138.0926317438, -59.0892900856 ,
    -162.5416439986, 7.1307658250   , -141.1236672256, -4.7173618068  ,
    -16.7741532807 , -68.2615451173 , -2.6608701102  , 84.1978109826  ,
    -11.3446202072 , 59.9630033088  , -1.8994925010  , -37.9301641959 ,
    -119.4435600954, -11.4587491646 , 12.2423215240  , -7.3169898616  ,
    -67.0373621128 , 36.0198843055  , 53.9791315249  , -134.5885680695,
    -83.8330811965 , -16.6714816463 , -8.8498552035  , -24.0513088196 ,
    -22.9444328877 , -37.7961441531 , 25.1975736186  , -136.1611637464,
    -5.0843464033  , -10.3939554694 , 20.7422826935  , 75.6854136623  ,
    46.4179626736  , -57.0052830175 , 7.3457235521   , -51.5504447254 ,
    -158.4375751701, -200.2426967181, -48.1234996261 , 1.6623945527   ,
    21.1746524375  , 99.4092980367  , -2.3206772903  , 45.7989166757  ,
    2.0181548348   , -88.0556010969 , -59.1527212096 , 47.3607925077  ,
    -10.4181140309 , 56.3558125650  , -8.9799125560  , -30.0376711812 ,
    -36.7132904688 , 35.7785050392  , -13.0763909369 , -2.1855594714  ,
    18.1550954005  , -28.6711803575 , -55.4495172398 , -2.8812973198  ,
    -59.9575059158 , 40.0588875786  , 57.4713686602  , -3.2835144853  ,
    -36.7193552111 , -64.9415131516 , -166.9555466445, -23.5556853844 ,
    -54.9408569587 , -35.2310451959 , 21.3345143458  , 65.7590671151  ,
    51.2214538168  , 46.1271939944  , -42.2235267919 , 127.2329928299 ,
    105.2391778600 , 17.6726845966  , -129.9021148044, 8.7065613044   ,
    -94.0987112511 , -3.5375742950  , -23.1385452379 , 60.6219530633  ,
    92.5445564235  , 48.5111974469  , -52.5699309159 , -60.0634811685 ,
    25.9034368684  , 140.0249495491 , 1.5918852392   , 38.0266038291  ,
    17.5588710703  , 3.4294066089   , -27.6748782173 , 59.6182974489  ,
    -35.2924781853 , -38.6198576115 , -13.6119803198 , 7.8375587489   ,
    22.7250686519  , -28.3524510951 , -34.4269062817 , 22.6464817325  ,
    -61.6528147860 , -5.9782002429  , 61.4730771294  , 43.5582379527  ,
    55.6862408270  , 87.8745651631  , 46.3401042715  , -19.8780979663 ,
    74.1272633369  , 29.8590452377  , -12.8665765140 , 34.2931401219  ,
    53.9279617551  , -16.9017895140 , -70.1527553166 , -79.6367897992 ,
    109.3728271017 , -129.2214826835, -53.4644539730 , -51.5654458993 ,
    17.6062148433  , 3.5090251835   , 74.2615941204  , -109.3431097845,
    40.1403465151  , 28.8714561280  , 94.0868659302  , -19.0047033845 ,
    -60.0967410050 , -19.0998457619 , -67.2027075128 , 72.0711434846  ,
    -17.8737851232 , 123.7050551274 , 132.6331504104 , 25.5018761009  ,
    -36.7817189239 , -29.1580893235 , -6.5848563828  , 90.2868948516  ,
    -35.7017258498 , -68.5675432955 , -52.4888589786 , 47.1377730021  ,
    -7.4546621940  , -52.0657517138 , -49.0404829633 , -114.6910280126,
    -117.6819819437, -32.7856729408 , 31.8232065591  , 12.1192973039  ,
    35.2678513420  , -1.0336778293  , 30.7021249679  , 127.0442906046 ,
    -84.8457819393 , 28.9862843096  , -47.3524701726 , -126.1094998460,
    -2.9700276582  , -2.4956545870  , -53.8624121141 , -85.2114117637 ,
    76.9057985618  , 137.1205201755 , -19.0830817212 , 14.3407526579  ,
    -56.5921994449 , -25.6084873186 , -44.9470801106 , -133.3139496090,
    0.3487447576   , 33.4499716730  , 34.7126257844  , -9.3307383323  ,
    27.2996276947  , 10.8765676134  , -91.1032360444 , -90.9584216222 ,
    1.6981490570   , 96.8557438791  , 56.7726390913  , -44.3246449237 ,
    52.3260643361  , 21.5551140465  , 27.4535327381  , 2.0072717479   ,
    7.4823125629   , 77.1185863870  , 16.1372262663  , -10.7206012957
};

const float32_t controller_f32_coeffs[CONTROLLER_MAX_COEFFS_LEN] =
{
    /* S->Kp, S->Ki, S->Kd; */
    0.0000000000  , -1.0336778293 , 56.7726390913 ,
    0.3487447576  , 0.0000000000  , 27.4535327381 ,
    -29.1580893235, 1.6981490570  , 0.0000000000  ,
    0.0000000000  , 0.0000000000  , -2.4956545870 ,
    0.0000000000  , 8.7065613044  , 0.0000000000  ,
    0.0000000000  , 0.0000000000  , 0.0000000000  ,
    18.1550954005 , -5.9782002429 , 2.0072717479  ,
    33.1212995259 , -82.1480936443, -10.5479715135,
    -23.6296332202, 49.1171161163 , 53.1636857935 ,
    7.2830326091  , 66.8368719314 , 33.9778190671 ,
    9.4452708243  , 5.3300080251  , 39.0483916714 ,
    6.9915412654  , -8.9909197429 , -78.9165936808
};

const q31_t controller_q31_coeffs[CONTROLLER_MAX_COEFFS_LEN] =
{
    0x00000000,	0xFEF760E4,	0x38C5CBAD,
    0x00594756,	0x00000000,	0x1B741AB9,
    0xE2D78775,	0x01B2B9E6,	0x00000000,
    0x00000000,	0x00000000,	0xFD811CC8,
    0x00000000,	0x08B4E134,	0x00000000,
    0x00000000,	0x00000000,	0x00000000,
    0x1227B455,	0xFA0594AB,	0x0201DC90,
    0x211F0D7C,	0xADDA1689,	0xF573B824,
    0xE85ED05B,	0x311DFB52,	0x3529E750,
    0x074874D3,	0x42D63D3D,	0x21FA525A,
    0x0971FD45,	0x05547B68,	0x270C6366,
    0x06FDD5A6,	0xF7025315,	0xB1155A1E
};


const q15_t controller_q15_coeffs[CONTROLLER_MAX_COEFFS_LEN] =
{
    0x0000,	0xFEF7,	0x38C6,
    0x0059,	0x0000,	0x1B74,
    0xE2D8,	0x01B3,	0x0000,
    0x0000,	0x0000,	0xFD81,
    0x0000,	0x08B5,	0x0000,
    0x0000,	0x0000,	0x0000,
    0x1228,	0xFA06,	0x0202,
    0x211F,	0xADDA,	0xF574,
    0xE85F,	0x311E,	0x352A,
    0x0748,	0x42D6,	0x21FA,
    0x0972,	0x0554,	0x270C,
    0x06FE,	0xF702,	0xB115
};
