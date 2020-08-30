#include <stdio.h>



struct __attribute__ ((__packed__))tbox_pack1
{
//    uint32_t	d1 : 8;

//    uint32_t	c1 : 1;
//    uint32_t	c2 : 1;
//    uint32_t	c3 : 1;
//    uint32_t	c4 : 1;
//    
//    uint32_t	d2 : 8;
    
    long long VehicleForcedActivation    :  2;

/*
    int RemoteUnlock               :  1;
    int EPSWorkingStatusReq        :  2;
    int EPSWorkingModeReq          :  2;
    int DriveModeReq               :  2;
    int DriveModeSpdSet            :  2;
    int SpeedAdjustmentFunc        :  4;
    int Remaining_mileage          : 16;
    int BluetoothPowerOn		   :  2;
    int RemotePowerOn              :  2;
*/ 

};


struct tbox_unpack
{
//    uint32_t	d1 : 8;

//    uint32_t	c1 : 1;
//    uint32_t	c2 : 1;
//    uint32_t	c3 : 1;
//    uint32_t	c4 : 1;
//    
//    uint32_t	d2 : 8;
    
    long long VehicleForcedActivation    :  2;
/* 
    int RemoteUnlock               :  1;
    int EPSWorkingStatusReq        :  2;
    int EPSWorkingModeReq          :  2;
    int DriveModeReq               :  2;
    int DriveModeSpdSet            :  2;
    int SpeedAdjustmentFunc        :  4;
    int Remaining_mileage          : 16;
    int BluetoothPowerOn		   :  2;
    int RemotePowerOn              :  2;
*/ 
};


typedef struct tbox_unpack TBOX_PACK1;
typedef struct tbox_unpack TBOX_UNPACK;

TBOX_PACK1  tbox_pack1 = {0};
TBOX_UNPACK tbox_unpack = {0};

void main(void)
{

    printf("sizeof(tbox_pack1) = %d\r\n", sizeof(tbox_pack1));
    printf("sizeof(tbox_unpack) = %d\r\n", sizeof(tbox_unpack));

}

