/*
 * relays.c
 *
 *  Created on: Dec 17, 2019
 *      Author: grzegorz
 */

#include "matrix.h"
#include "main.h"


void MATRIX_DetectModule()
{
	board.module.detected = HAL_GPIO_ReadPin(MODULE_DETECT0_GPIO_Port, MODULE_DETECT0_Pin) && HAL_GPIO_ReadPin(MODULE_DETECT1_GPIO_Port, MODULE_DETECT1_Pin);
}

void MATRIX_InitMain()
{
	matrix.relays[0].id = "01A";
	matrix.relays[0].status = OPEN;
	matrix.relays[0].type = MAIN;
	matrix.relays[0].MCZ33996.cs = 0;
	matrix.relays[0].MCZ33996.spi = 5;
	matrix.relays[0].MCZ33996.pin = 0;

	matrix.relays[1].id = "01B";
	matrix.relays[1].status = OPEN;
	matrix.relays[1].type = MAIN;
	matrix.relays[1].MCZ33996.cs = 0;
	matrix.relays[1].MCZ33996.spi = 5;
	matrix.relays[1].MCZ33996.pin = 7;

	matrix.relays[2].id = "01C";
	matrix.relays[2].status = OPEN;
	matrix.relays[2].type = MAIN;
	matrix.relays[2].MCZ33996.cs = 0;
	matrix.relays[2].MCZ33996.spi = 5;
	matrix.relays[2].MCZ33996.pin = 8;

	matrix.relays[3].id = "02A";
	matrix.relays[3].status = OPEN;
	matrix.relays[3].type = MAIN;
	matrix.relays[3].MCZ33996.cs = 1;
	matrix.relays[3].MCZ33996.spi = 5;
	matrix.relays[3].MCZ33996.pin = 7;

	matrix.relays[4].id = "02B";
	matrix.relays[4].status = OPEN;
	matrix.relays[4].type = MAIN;
	matrix.relays[4].MCZ33996.cs = 1;
	matrix.relays[4].MCZ33996.spi = 5;
	matrix.relays[4].MCZ33996.pin = 6;

	matrix.relays[5].id = "02C";
	matrix.relays[5].status = OPEN;
	matrix.relays[5].type = MAIN;
	matrix.relays[5].MCZ33996.cs = 1;
	matrix.relays[5].MCZ33996.spi = 5;
	matrix.relays[5].MCZ33996.pin = 8;

	matrix.relays[6].id = "03A";
	matrix.relays[6].status = OPEN;
	matrix.relays[6].type = MAIN;
	matrix.relays[6].MCZ33996.cs = 1;
	matrix.relays[6].MCZ33996.spi = 5;
	matrix.relays[6].MCZ33996.pin = 9;

	matrix.relays[7].id = "03B";
	matrix.relays[7].status = OPEN;
	matrix.relays[7].type = MAIN;
	matrix.relays[7].MCZ33996.cs = 1;
	matrix.relays[7].MCZ33996.spi = 5;
	matrix.relays[7].MCZ33996.pin = 10;

	matrix.relays[8].id = "03C";
	matrix.relays[8].status = OPEN;
	matrix.relays[8].type = MAIN;
	matrix.relays[8].MCZ33996.cs = 1;
	matrix.relays[8].MCZ33996.spi = 5;
	matrix.relays[8].MCZ33996.pin = 11;

	matrix.relays[9].id = "04A";
	matrix.relays[9].status = OPEN;
	matrix.relays[9].type = MAIN;
	matrix.relays[9].MCZ33996.cs = 2;
	matrix.relays[9].MCZ33996.spi = 5;
	matrix.relays[9].MCZ33996.pin = 2;

	matrix.relays[10].id = "04B";
	matrix.relays[10].status = OPEN;
	matrix.relays[10].type = MAIN;
	matrix.relays[10].MCZ33996.cs = 2;
	matrix.relays[10].MCZ33996.spi = 5;
	matrix.relays[10].MCZ33996.pin = 1;

	matrix.relays[11].id = "04C";
	matrix.relays[11].status = OPEN;
	matrix.relays[11].type = MAIN;
	matrix.relays[11].MCZ33996.cs = 2;
	matrix.relays[11].MCZ33996.spi = 5;
	matrix.relays[11].MCZ33996.pin = 0;

	matrix.relays[12].id = "05A";
	matrix.relays[12].status = OPEN;
	matrix.relays[12].type = MAIN;
	matrix.relays[12].MCZ33996.cs = 2;
	matrix.relays[12].MCZ33996.spi = 5;
	matrix.relays[12].MCZ33996.pin = 14;

	matrix.relays[13].id = "05B";
	matrix.relays[13].status = OPEN;
	matrix.relays[13].type = MAIN;
	matrix.relays[13].MCZ33996.cs = 2;
	matrix.relays[13].MCZ33996.spi = 5;
	matrix.relays[13].MCZ33996.pin = 13;

	matrix.relays[14].id = "05C";
	matrix.relays[14].status = OPEN;
	matrix.relays[14].type = MAIN;
	matrix.relays[14].MCZ33996.cs = 2;
	matrix.relays[14].MCZ33996.spi = 5;
	matrix.relays[14].MCZ33996.pin = 12;

	matrix.relays[15].id = "06A";
	matrix.relays[15].status = OPEN;
	matrix.relays[15].type = MAIN;
	matrix.relays[15].MCZ33996.cs = 3;
	matrix.relays[15].MCZ33996.spi = 5;
	matrix.relays[15].MCZ33996.pin = 12;

	matrix.relays[16].id = "06B";
	matrix.relays[16].status = OPEN;
	matrix.relays[16].type = MAIN;
	matrix.relays[16].MCZ33996.cs = 3;
	matrix.relays[16].MCZ33996.spi = 5;
	matrix.relays[16].MCZ33996.pin = 13;

	matrix.relays[17].id = "06C";
	matrix.relays[17].status = OPEN;
	matrix.relays[17].type = MAIN;
	matrix.relays[17].MCZ33996.cs = 3;
	matrix.relays[17].MCZ33996.spi = 5;
	matrix.relays[17].MCZ33996.pin = 14;

	matrix.relays[18].id = "07A";
	matrix.relays[18].status = OPEN;
	matrix.relays[18].type = MAIN;
	matrix.relays[18].MCZ33996.cs = 0;
	matrix.relays[18].MCZ33996.spi = 5;
	matrix.relays[18].MCZ33996.pin = 1;

	matrix.relays[19].id = "07B";
	matrix.relays[19].status = OPEN;
	matrix.relays[19].type = MAIN;
	matrix.relays[19].MCZ33996.cs = 0;
	matrix.relays[19].MCZ33996.spi = 5;
	matrix.relays[19].MCZ33996.pin = 5;

	matrix.relays[20].id = "07C";
	matrix.relays[20].status = OPEN;
	matrix.relays[20].type = MAIN;
	matrix.relays[20].MCZ33996.cs = 0;
	matrix.relays[20].MCZ33996.spi = 5;
	matrix.relays[20].MCZ33996.pin = 6;

	matrix.relays[21].id = "08A";
	matrix.relays[21].status = OPEN;
	matrix.relays[21].type = MAIN;
	matrix.relays[21].MCZ33996.cs = 0;
	matrix.relays[21].MCZ33996.spi = 5;
	matrix.relays[21].MCZ33996.pin = 12;

	matrix.relays[22].id = "08B";
	matrix.relays[22].status = OPEN;
	matrix.relays[22].type = MAIN;
	matrix.relays[22].MCZ33996.cs = 0;
	matrix.relays[22].MCZ33996.spi = 5;
	matrix.relays[22].MCZ33996.pin = 13;

	matrix.relays[23].id = "08C";
	matrix.relays[23].status = OPEN;
	matrix.relays[23].type = MAIN;
	matrix.relays[23].MCZ33996.cs = 0;
	matrix.relays[23].MCZ33996.spi = 5;
	matrix.relays[23].MCZ33996.pin = 14;

	matrix.relays[24].id = "09A";
	matrix.relays[24].status = OPEN;
	matrix.relays[24].type = MAIN;
	matrix.relays[24].MCZ33996.cs = 1;
	matrix.relays[24].MCZ33996.spi = 5;
	matrix.relays[24].MCZ33996.pin = 3;

	matrix.relays[25].id = "09B";
	matrix.relays[25].status = OPEN;
	matrix.relays[25].type = MAIN;
	matrix.relays[25].MCZ33996.cs = 1;
	matrix.relays[25].MCZ33996.spi = 5;
	matrix.relays[25].MCZ33996.pin = 4;

	matrix.relays[26].id = "09C";
	matrix.relays[26].status = OPEN;
	matrix.relays[26].type = MAIN;
	matrix.relays[26].MCZ33996.cs = 1;
	matrix.relays[26].MCZ33996.spi = 5;
	matrix.relays[26].MCZ33996.pin = 5;

	matrix.relays[27].id = "10A";
	matrix.relays[27].status = OPEN;
	matrix.relays[27].type = MAIN;
	matrix.relays[27].MCZ33996.cs = 2;
	matrix.relays[27].MCZ33996.spi = 5;
	matrix.relays[27].MCZ33996.pin = 5;

	matrix.relays[28].id = "10B";
	matrix.relays[28].status = OPEN;
	matrix.relays[28].type = MAIN;
	matrix.relays[28].MCZ33996.cs = 2;
	matrix.relays[28].MCZ33996.spi = 5;
	matrix.relays[28].MCZ33996.pin = 4;

	matrix.relays[29].id = "10C";
	matrix.relays[29].status = OPEN;
	matrix.relays[29].type = MAIN;
	matrix.relays[29].MCZ33996.cs = 2;
	matrix.relays[29].MCZ33996.spi = 5;
	matrix.relays[29].MCZ33996.pin = 3;

	matrix.relays[30].id = "11A";
	matrix.relays[30].status = OPEN;
	matrix.relays[30].type = MAIN;
	matrix.relays[30].MCZ33996.cs = 2;
	matrix.relays[30].MCZ33996.spi = 5;
	matrix.relays[30].MCZ33996.pin = 9;

	matrix.relays[31].id = "11B";
	matrix.relays[31].status = OPEN;
	matrix.relays[31].type = MAIN;
	matrix.relays[31].MCZ33996.cs = 2;
	matrix.relays[31].MCZ33996.spi = 5;
	matrix.relays[31].MCZ33996.pin = 10;

	matrix.relays[32].id = "11C";
	matrix.relays[32].status = OPEN;
	matrix.relays[32].type = MAIN;
	matrix.relays[32].MCZ33996.cs = 2;
	matrix.relays[32].MCZ33996.spi = 5;
	matrix.relays[32].MCZ33996.pin = 11;

	matrix.relays[33].id = "12A";
	matrix.relays[33].status = OPEN;
	matrix.relays[33].type = MAIN;
	matrix.relays[33].MCZ33996.cs = 3;
	matrix.relays[33].MCZ33996.spi = 5;
	matrix.relays[33].MCZ33996.pin = 9;

	matrix.relays[34].id = "12B";
	matrix.relays[34].status = OPEN;
	matrix.relays[34].type = MAIN;
	matrix.relays[34].MCZ33996.cs = 3;
	matrix.relays[34].MCZ33996.spi = 5;
	matrix.relays[34].MCZ33996.pin = 10;

	matrix.relays[35].id = "12C";
	matrix.relays[35].status = OPEN;
	matrix.relays[35].type = MAIN;
	matrix.relays[35].MCZ33996.cs = 3;
	matrix.relays[35].MCZ33996.spi = 5;
	matrix.relays[35].MCZ33996.pin = 11;

	matrix.relays[36].id = "13A";
	matrix.relays[36].status = OPEN;
	matrix.relays[36].type = MAIN;
	matrix.relays[36].MCZ33996.cs = 4;
	matrix.relays[36].MCZ33996.spi = 5;
	matrix.relays[36].MCZ33996.pin = 3;

	matrix.relays[37].id = "13B";
	matrix.relays[37].status = OPEN;
	matrix.relays[37].type = MAIN;
	matrix.relays[37].MCZ33996.cs = 4;
	matrix.relays[37].MCZ33996.spi = 5;
	matrix.relays[37].MCZ33996.pin = 4;

	matrix.relays[38].id = "13C";
	matrix.relays[38].status = OPEN;
	matrix.relays[38].type = MAIN;
	matrix.relays[38].MCZ33996.cs = 4;
	matrix.relays[38].MCZ33996.spi = 5;
	matrix.relays[38].MCZ33996.pin = 5;

	matrix.relays[39].id = "14A";
	matrix.relays[39].status = OPEN;
	matrix.relays[39].type = MAIN;
	matrix.relays[39].MCZ33996.cs = 0;
	matrix.relays[39].MCZ33996.spi = 5;
	matrix.relays[39].MCZ33996.pin = 2;

	matrix.relays[40].id = "14B";
	matrix.relays[40].status = OPEN;
	matrix.relays[40].type = MAIN;
	matrix.relays[40].MCZ33996.cs = 0;
	matrix.relays[40].MCZ33996.spi = 5;
	matrix.relays[40].MCZ33996.pin = 3;

	matrix.relays[41].id = "14C";
	matrix.relays[41].status = OPEN;
	matrix.relays[41].type = MAIN;
	matrix.relays[41].MCZ33996.cs = 0;
	matrix.relays[41].MCZ33996.spi = 5;
	matrix.relays[41].MCZ33996.pin = 4;

	matrix.relays[42].id = "15A";
	matrix.relays[42].status = OPEN;
	matrix.relays[42].type = MAIN;
	matrix.relays[42].MCZ33996.cs = 0;
	matrix.relays[42].MCZ33996.spi = 5;
	matrix.relays[42].MCZ33996.pin = 9;

	matrix.relays[43].id = "15B";
	matrix.relays[43].status = OPEN;
	matrix.relays[43].type = MAIN;
	matrix.relays[43].MCZ33996.cs = 0;
	matrix.relays[43].MCZ33996.spi = 5;
	matrix.relays[43].MCZ33996.pin = 10;

	matrix.relays[44].id = "15C";
	matrix.relays[44].status = OPEN;
	matrix.relays[44].type = MAIN;
	matrix.relays[44].MCZ33996.cs = 0;
	matrix.relays[44].MCZ33996.spi = 5;
	matrix.relays[44].MCZ33996.pin = 11;

	matrix.relays[45].id = "16A";
	matrix.relays[45].status = OPEN;
	matrix.relays[45].type = MAIN;
	matrix.relays[45].MCZ33996.cs = 1;
	matrix.relays[45].MCZ33996.spi = 5;
	matrix.relays[45].MCZ33996.pin = 0;

	matrix.relays[46].id = "16B";
	matrix.relays[46].status = OPEN;
	matrix.relays[46].type = MAIN;
	matrix.relays[46].MCZ33996.cs = 1;
	matrix.relays[46].MCZ33996.spi = 5;
	matrix.relays[46].MCZ33996.pin = 1;

	matrix.relays[47].id = "16C";
	matrix.relays[47].status = OPEN;
	matrix.relays[47].type = MAIN;
	matrix.relays[47].MCZ33996.cs = 1;
	matrix.relays[47].MCZ33996.spi = 5;
	matrix.relays[47].MCZ33996.pin = 2;

	matrix.relays[48].id = "17A";
	matrix.relays[48].status = OPEN;
	matrix.relays[48].type = MAIN;
	matrix.relays[48].MCZ33996.cs = 1;
	matrix.relays[48].MCZ33996.spi = 5;
	matrix.relays[48].MCZ33996.pin = 14;

	matrix.relays[49].id = "17B";
	matrix.relays[49].status = OPEN;
	matrix.relays[49].type = MAIN;
	matrix.relays[49].MCZ33996.cs = 1;
	matrix.relays[49].MCZ33996.spi = 5;
	matrix.relays[49].MCZ33996.pin = 13;

	matrix.relays[50].id = "17C";
	matrix.relays[50].status = OPEN;
	matrix.relays[50].type = MAIN;
	matrix.relays[50].MCZ33996.cs = 1;
	matrix.relays[50].MCZ33996.spi = 5;
	matrix.relays[50].MCZ33996.pin = 12;

	matrix.relays[51].id = "18A";
	matrix.relays[51].status = OPEN;
	matrix.relays[51].type = MAIN;
	matrix.relays[51].MCZ33996.cs = 2;
	matrix.relays[51].MCZ33996.spi = 5;
	matrix.relays[51].MCZ33996.pin = 6;

	matrix.relays[52].id = "18B";
	matrix.relays[52].status = OPEN;
	matrix.relays[52].type = MAIN;
	matrix.relays[52].MCZ33996.cs = 2;
	matrix.relays[52].MCZ33996.spi = 5;
	matrix.relays[52].MCZ33996.pin = 7;

	matrix.relays[53].id = "18C";
	matrix.relays[53].status = OPEN;
	matrix.relays[53].type = MAIN;
	matrix.relays[53].MCZ33996.cs = 2;
	matrix.relays[53].MCZ33996.spi = 5;
	matrix.relays[53].MCZ33996.pin = 8;

	matrix.relays[54].id = "19A";
	matrix.relays[54].status = OPEN;
	matrix.relays[54].type = MAIN;
	matrix.relays[54].MCZ33996.cs = 3;
	matrix.relays[54].MCZ33996.spi = 5;
	matrix.relays[54].MCZ33996.pin = 0;

	matrix.relays[55].id = "19B";
	matrix.relays[55].status = OPEN;
	matrix.relays[55].type = MAIN;
	matrix.relays[55].MCZ33996.cs = 3;
	matrix.relays[55].MCZ33996.spi = 5;
	matrix.relays[55].MCZ33996.pin = 1;

	matrix.relays[56].id = "19C";
	matrix.relays[56].status = OPEN;
	matrix.relays[56].type = MAIN;
	matrix.relays[56].MCZ33996.cs = 3;
	matrix.relays[56].MCZ33996.spi = 5;
	matrix.relays[56].MCZ33996.pin = 2;

	matrix.relays[57].id = "20A";
	matrix.relays[57].status = OPEN;
	matrix.relays[57].type = MAIN;
	matrix.relays[57].MCZ33996.cs = 4;
	matrix.relays[57].MCZ33996.spi = 5;
	matrix.relays[57].MCZ33996.pin = 0;

	matrix.relays[58].id = "20B";
	matrix.relays[58].status = OPEN;
	matrix.relays[58].type = MAIN;
	matrix.relays[58].MCZ33996.cs = 4;
	matrix.relays[58].MCZ33996.spi = 5;
	matrix.relays[58].MCZ33996.pin = 1;

	matrix.relays[59].id = "20C";
	matrix.relays[59].status = OPEN;
	matrix.relays[59].type = MAIN;
	matrix.relays[59].MCZ33996.cs = 4;
	matrix.relays[59].MCZ33996.spi = 5;
	matrix.relays[59].MCZ33996.pin = 2;

	matrix.relays[60].id = "AA";
	matrix.relays[60].status = OPEN;
	matrix.relays[60].type = MAIN;
	matrix.relays[60].MCZ33996.cs = 4;
	matrix.relays[60].MCZ33996.spi = 5;
	matrix.relays[60].MCZ33996.pin = 14;

	matrix.relays[61].id = "BB";
	matrix.relays[61].status = OPEN;
	matrix.relays[61].type = MAIN;
	matrix.relays[61].MCZ33996.cs = 4;
	matrix.relays[61].MCZ33996.spi = 5;
	matrix.relays[61].MCZ33996.pin = 13;

	matrix.relays[62].id = "CC";
	matrix.relays[62].status = OPEN;
	matrix.relays[62].type = MAIN;
	matrix.relays[62].MCZ33996.cs = 4;
	matrix.relays[62].MCZ33996.spi = 5;
	matrix.relays[62].MCZ33996.pin = 12;

	matrix.relays[63].id = "CD";
	matrix.relays[63].status = OPEN;
	matrix.relays[63].type = MAIN;
	matrix.relays[63].MCZ33996.cs = 4;
	matrix.relays[63].MCZ33996.spi = 5;
	matrix.relays[63].MCZ33996.pin = 11;

	matrix.relays[64].id = "BE";
	matrix.relays[64].status = OPEN;
	matrix.relays[64].type = MAIN;
	matrix.relays[64].MCZ33996.cs = 4;
	matrix.relays[64].MCZ33996.spi = 5;
	matrix.relays[64].MCZ33996.pin = 10;

	matrix.relays[65].id = "AF";
	matrix.relays[65].status = OPEN;
	matrix.relays[65].type = MAIN;
	matrix.relays[65].MCZ33996.cs = 4;
	matrix.relays[65].MCZ33996.spi = 5;
	matrix.relays[65].MCZ33996.pin = 9;



	matrix.relays[66].id = "01A";
	matrix.relays[66].status = OPEN;
	matrix.relays[66].type = MODULE;
	matrix.relays[66].MCZ33996.cs = 0;
	matrix.relays[66].MCZ33996.spi = 4;
	matrix.relays[66].MCZ33996.pin = 0;

	matrix.relays[67].id = "01B";
	matrix.relays[67].status = OPEN;
	matrix.relays[67].type = MODULE;
	matrix.relays[67].MCZ33996.cs = 0;
	matrix.relays[67].MCZ33996.spi = 4;
	matrix.relays[67].MCZ33996.pin = 7;

	matrix.relays[68].id = "01C";
	matrix.relays[68].status = OPEN;
	matrix.relays[68].type = MODULE;
	matrix.relays[68].MCZ33996.cs = 0;
	matrix.relays[68].MCZ33996.spi = 4;
	matrix.relays[68].MCZ33996.pin = 8;

	matrix.relays[69].id = "02A";
	matrix.relays[69].status = OPEN;
	matrix.relays[69].type = MODULE;
	matrix.relays[69].MCZ33996.cs = 1;
	matrix.relays[69].MCZ33996.spi = 4;
	matrix.relays[69].MCZ33996.pin = 7;

	matrix.relays[70].id = "02B";
	matrix.relays[70].status = OPEN;
	matrix.relays[70].type = MODULE;
	matrix.relays[70].MCZ33996.cs = 1;
	matrix.relays[70].MCZ33996.spi = 4;
	matrix.relays[70].MCZ33996.pin = 6;

	matrix.relays[71].id = "02C";
	matrix.relays[71].status = OPEN;
	matrix.relays[71].type = MODULE;
	matrix.relays[71].MCZ33996.cs = 1;
	matrix.relays[71].MCZ33996.spi = 4;
	matrix.relays[71].MCZ33996.pin = 8;

	matrix.relays[72].id = "03A";
	matrix.relays[72].status = OPEN;
	matrix.relays[72].type = MODULE;
	matrix.relays[72].MCZ33996.cs = 1;
	matrix.relays[72].MCZ33996.spi = 4;
	matrix.relays[72].MCZ33996.pin = 9;

	matrix.relays[73].id = "03B";
	matrix.relays[73].status = OPEN;
	matrix.relays[73].type = MODULE;
	matrix.relays[73].MCZ33996.cs = 1;
	matrix.relays[73].MCZ33996.spi = 4;
	matrix.relays[73].MCZ33996.pin = 10;

	matrix.relays[74].id = "03C";
	matrix.relays[74].status = OPEN;
	matrix.relays[74].type = MODULE;
	matrix.relays[74].MCZ33996.cs = 1;
	matrix.relays[74].MCZ33996.spi = 4;
	matrix.relays[74].MCZ33996.pin = 11;

	matrix.relays[75].id = "04A";
	matrix.relays[75].status = OPEN;
	matrix.relays[75].type = MODULE;
	matrix.relays[75].MCZ33996.cs = 2;
	matrix.relays[75].MCZ33996.spi = 4;
	matrix.relays[75].MCZ33996.pin = 2;

	matrix.relays[76].id = "04B";
	matrix.relays[76].status = OPEN;
	matrix.relays[76].type = MODULE;
	matrix.relays[76].MCZ33996.cs = 2;
	matrix.relays[76].MCZ33996.spi = 4;
	matrix.relays[76].MCZ33996.pin = 1;

	matrix.relays[77].id = "04C";
	matrix.relays[77].status = OPEN;
	matrix.relays[77].type = MODULE;
	matrix.relays[77].MCZ33996.cs = 2;
	matrix.relays[77].MCZ33996.spi = 4;
	matrix.relays[77].MCZ33996.pin = 0;

	matrix.relays[78].id = "05A";
	matrix.relays[78].status = OPEN;
	matrix.relays[78].type = MODULE;
	matrix.relays[78].MCZ33996.cs = 2;
	matrix.relays[78].MCZ33996.spi = 4;
	matrix.relays[78].MCZ33996.pin = 14;

	matrix.relays[79].id = "05B";
	matrix.relays[79].status = OPEN;
	matrix.relays[79].type = MODULE;
	matrix.relays[79].MCZ33996.cs = 2;
	matrix.relays[79].MCZ33996.spi = 4;
	matrix.relays[79].MCZ33996.pin = 13;

	matrix.relays[80].id = "05C";
	matrix.relays[80].status = OPEN;
	matrix.relays[80].type = MODULE;
	matrix.relays[80].MCZ33996.cs = 2;
	matrix.relays[80].MCZ33996.spi = 4;
	matrix.relays[80].MCZ33996.pin = 12;

	matrix.relays[81].id = "06A";
	matrix.relays[81].status = OPEN;
	matrix.relays[81].type = MODULE;
	matrix.relays[81].MCZ33996.cs = 3;
	matrix.relays[81].MCZ33996.spi = 4;
	matrix.relays[81].MCZ33996.pin = 12;

	matrix.relays[82].id = "06B";
	matrix.relays[82].status = OPEN;
	matrix.relays[82].type = MODULE;
	matrix.relays[82].MCZ33996.cs = 3;
	matrix.relays[82].MCZ33996.spi = 4;
	matrix.relays[82].MCZ33996.pin = 13;

	matrix.relays[83].id = "06C";
	matrix.relays[83].status = OPEN;
	matrix.relays[83].type = MODULE;
	matrix.relays[83].MCZ33996.cs = 3;
	matrix.relays[83].MCZ33996.spi = 4;
	matrix.relays[83].MCZ33996.pin = 14;

	matrix.relays[84].id = "07A";
	matrix.relays[84].status = OPEN;
	matrix.relays[84].type = MODULE;
	matrix.relays[84].MCZ33996.cs = 0;
	matrix.relays[84].MCZ33996.spi = 4;
	matrix.relays[84].MCZ33996.pin = 1;

	matrix.relays[85].id = "07B";
	matrix.relays[85].status = OPEN;
	matrix.relays[85].type = MODULE;
	matrix.relays[85].MCZ33996.cs = 0;
	matrix.relays[85].MCZ33996.spi = 4;
	matrix.relays[85].MCZ33996.pin = 5;

	matrix.relays[86].id = "07C";
	matrix.relays[86].status = OPEN;
	matrix.relays[86].type = MODULE;
	matrix.relays[86].MCZ33996.cs = 0;
	matrix.relays[86].MCZ33996.spi = 4;
	matrix.relays[86].MCZ33996.pin = 6;

	matrix.relays[87].id = "08A";
	matrix.relays[87].status = OPEN;
	matrix.relays[87].type = MODULE;
	matrix.relays[87].MCZ33996.cs = 0;
	matrix.relays[87].MCZ33996.spi = 4;
	matrix.relays[87].MCZ33996.pin = 12;

	matrix.relays[88].id = "08B";
	matrix.relays[88].status = OPEN;
	matrix.relays[88].type = MODULE;
	matrix.relays[88].MCZ33996.cs = 0;
	matrix.relays[88].MCZ33996.spi = 4;
	matrix.relays[88].MCZ33996.pin = 13;

	matrix.relays[89].id = "08C";
	matrix.relays[89].status = OPEN;
	matrix.relays[89].type = MODULE;
	matrix.relays[89].MCZ33996.cs = 0;
	matrix.relays[89].MCZ33996.spi = 4;
	matrix.relays[89].MCZ33996.pin = 14;

	matrix.relays[90].id = "09A";
	matrix.relays[90].status = OPEN;
	matrix.relays[90].type = MODULE;
	matrix.relays[90].MCZ33996.cs = 1;
	matrix.relays[90].MCZ33996.spi = 4;
	matrix.relays[90].MCZ33996.pin = 3;

	matrix.relays[91].id = "09B";
	matrix.relays[91].status = OPEN;
	matrix.relays[91].type = MODULE;
	matrix.relays[91].MCZ33996.cs = 1;
	matrix.relays[91].MCZ33996.spi = 4;
	matrix.relays[91].MCZ33996.pin = 4;

	matrix.relays[92].id = "09C";
	matrix.relays[92].status = OPEN;
	matrix.relays[92].type = MODULE;
	matrix.relays[92].MCZ33996.cs = 1;
	matrix.relays[92].MCZ33996.spi = 4;
	matrix.relays[92].MCZ33996.pin = 5;

	matrix.relays[93].id = "10A";
	matrix.relays[93].status = OPEN;
	matrix.relays[93].type = MODULE;
	matrix.relays[93].MCZ33996.cs = 2;
	matrix.relays[93].MCZ33996.spi = 4;
	matrix.relays[93].MCZ33996.pin = 5;

	matrix.relays[94].id = "10B";
	matrix.relays[94].status = OPEN;
	matrix.relays[94].type = MODULE;
	matrix.relays[94].MCZ33996.cs = 2;
	matrix.relays[94].MCZ33996.spi = 4;
	matrix.relays[94].MCZ33996.pin = 4;

	matrix.relays[95].id = "10C";
	matrix.relays[95].status = OPEN;
	matrix.relays[95].type = MODULE;
	matrix.relays[95].MCZ33996.cs = 2;
	matrix.relays[95].MCZ33996.spi = 4;
	matrix.relays[95].MCZ33996.pin = 3;

	matrix.relays[96].id = "11A";
	matrix.relays[96].status = OPEN;
	matrix.relays[96].type = MODULE;
	matrix.relays[96].MCZ33996.cs = 2;
	matrix.relays[96].MCZ33996.spi = 4;
	matrix.relays[96].MCZ33996.pin = 9;

	matrix.relays[97].id = "11B";
	matrix.relays[97].status = OPEN;
	matrix.relays[97].type = MODULE;
	matrix.relays[97].MCZ33996.cs = 2;
	matrix.relays[97].MCZ33996.spi = 4;
	matrix.relays[97].MCZ33996.pin = 10;

	matrix.relays[98].id = "11C";
	matrix.relays[98].status = OPEN;
	matrix.relays[98].type = MODULE;
	matrix.relays[98].MCZ33996.cs = 2;
	matrix.relays[98].MCZ33996.spi = 4;
	matrix.relays[98].MCZ33996.pin = 11;

	matrix.relays[99].id = "12A";
	matrix.relays[99].status = OPEN;
	matrix.relays[99].type = MODULE;
	matrix.relays[99].MCZ33996.cs = 3;
	matrix.relays[99].MCZ33996.spi = 4;
	matrix.relays[99].MCZ33996.pin = 9;

	matrix.relays[100].id = "12B";
	matrix.relays[100].status = OPEN;
	matrix.relays[100].type = MODULE;
	matrix.relays[100].MCZ33996.cs = 3;
	matrix.relays[100].MCZ33996.spi = 4;
	matrix.relays[100].MCZ33996.pin = 10;

	matrix.relays[101].id = "12C";
	matrix.relays[101].status = OPEN;
	matrix.relays[101].type = MODULE;
	matrix.relays[101].MCZ33996.cs = 3;
	matrix.relays[101].MCZ33996.spi = 4;
	matrix.relays[101].MCZ33996.pin = 11;

	matrix.relays[102].id = "13A";
	matrix.relays[102].status = OPEN;
	matrix.relays[102].type = MODULE;
	matrix.relays[102].MCZ33996.cs = 4;
	matrix.relays[102].MCZ33996.spi = 4;
	matrix.relays[102].MCZ33996.pin = 3;

	matrix.relays[103].id = "13B";
	matrix.relays[103].status = OPEN;
	matrix.relays[103].type = MODULE;
	matrix.relays[103].MCZ33996.cs = 4;
	matrix.relays[103].MCZ33996.spi = 4;
	matrix.relays[103].MCZ33996.pin = 4;

	matrix.relays[104].id = "13C";
	matrix.relays[104].status = OPEN;
	matrix.relays[104].type = MODULE;
	matrix.relays[104].MCZ33996.cs = 4;
	matrix.relays[104].MCZ33996.spi = 4;
	matrix.relays[104].MCZ33996.pin = 5;

	matrix.relays[105].id = "14A";
	matrix.relays[105].status = OPEN;
	matrix.relays[105].type = MODULE;
	matrix.relays[105].MCZ33996.cs = 0;
	matrix.relays[105].MCZ33996.spi = 4;
	matrix.relays[105].MCZ33996.pin = 2;

	matrix.relays[106].id = "14B";
	matrix.relays[106].status = OPEN;
	matrix.relays[106].type = MODULE;
	matrix.relays[106].MCZ33996.cs = 0;
	matrix.relays[106].MCZ33996.spi = 4;
	matrix.relays[106].MCZ33996.pin = 3;

	matrix.relays[107].id = "14C";
	matrix.relays[107].status = OPEN;
	matrix.relays[107].type = MODULE;
	matrix.relays[107].MCZ33996.cs = 0;
	matrix.relays[107].MCZ33996.spi = 4;
	matrix.relays[107].MCZ33996.pin = 4;

	matrix.relays[108].id = "15A";
	matrix.relays[108].status = OPEN;
	matrix.relays[108].type = MODULE;
	matrix.relays[108].MCZ33996.cs = 0;
	matrix.relays[108].MCZ33996.spi = 4;
	matrix.relays[108].MCZ33996.pin = 9;

	matrix.relays[109].id = "15B";
	matrix.relays[109].status = OPEN;
	matrix.relays[109].type = MODULE;
	matrix.relays[109].MCZ33996.cs = 0;
	matrix.relays[109].MCZ33996.spi = 4;
	matrix.relays[109].MCZ33996.pin = 10;

	matrix.relays[110].id = "15C";
	matrix.relays[110].status = OPEN;
	matrix.relays[110].type = MODULE;
	matrix.relays[110].MCZ33996.cs = 0;
	matrix.relays[110].MCZ33996.spi = 4;
	matrix.relays[110].MCZ33996.pin = 11;

	matrix.relays[111].id = "16A";
	matrix.relays[111].status = OPEN;
	matrix.relays[111].type = MODULE;
	matrix.relays[111].MCZ33996.cs = 1;
	matrix.relays[111].MCZ33996.spi = 4;
	matrix.relays[111].MCZ33996.pin = 0;

	matrix.relays[112].id = "16B";
	matrix.relays[112].status = OPEN;
	matrix.relays[112].type = MODULE;
	matrix.relays[112].MCZ33996.cs = 1;
	matrix.relays[112].MCZ33996.spi = 4;
	matrix.relays[112].MCZ33996.pin = 1;

	matrix.relays[113].id = "16C";
	matrix.relays[113].status = OPEN;
	matrix.relays[113].type = MODULE;
	matrix.relays[113].MCZ33996.cs = 1;
	matrix.relays[113].MCZ33996.spi = 4;
	matrix.relays[113].MCZ33996.pin = 2;

	matrix.relays[114].id = "17A";
	matrix.relays[114].status = OPEN;
	matrix.relays[114].type = MODULE;
	matrix.relays[114].MCZ33996.cs = 1;
	matrix.relays[114].MCZ33996.spi = 4;
	matrix.relays[114].MCZ33996.pin = 14;

	matrix.relays[115].id = "17B";
	matrix.relays[115].status = OPEN;
	matrix.relays[115].type = MODULE;
	matrix.relays[115].MCZ33996.cs = 1;
	matrix.relays[115].MCZ33996.spi = 4;
	matrix.relays[115].MCZ33996.pin = 13;

	matrix.relays[116].id = "17C";
	matrix.relays[116].status = OPEN;
	matrix.relays[116].type = MODULE;
	matrix.relays[116].MCZ33996.cs = 1;
	matrix.relays[116].MCZ33996.spi = 4;
	matrix.relays[116].MCZ33996.pin = 12;

	matrix.relays[117].id = "18A";
	matrix.relays[117].status = OPEN;
	matrix.relays[117].type = MODULE;
	matrix.relays[117].MCZ33996.cs = 2;
	matrix.relays[117].MCZ33996.spi = 4;
	matrix.relays[117].MCZ33996.pin = 6;

	matrix.relays[118].id = "18B";
	matrix.relays[118].status = OPEN;
	matrix.relays[118].type = MODULE;
	matrix.relays[118].MCZ33996.cs = 2;
	matrix.relays[118].MCZ33996.spi = 4;
	matrix.relays[118].MCZ33996.pin = 7;

	matrix.relays[119].id = "18C";
	matrix.relays[119].status = OPEN;
	matrix.relays[119].type = MODULE;
	matrix.relays[119].MCZ33996.cs = 2;
	matrix.relays[119].MCZ33996.spi = 4;
	matrix.relays[119].MCZ33996.pin = 8;

	matrix.relays[120].id = "19A";
	matrix.relays[120].status = OPEN;
	matrix.relays[120].type = MODULE;
	matrix.relays[120].MCZ33996.cs = 3;
	matrix.relays[120].MCZ33996.spi = 4;
	matrix.relays[120].MCZ33996.pin = 0;

	matrix.relays[121].id = "19B";
	matrix.relays[121].status = OPEN;
	matrix.relays[121].type = MODULE;
	matrix.relays[121].MCZ33996.cs = 3;
	matrix.relays[121].MCZ33996.spi = 4;
	matrix.relays[121].MCZ33996.pin = 1;

	matrix.relays[122].id = "19C";
	matrix.relays[122].status = OPEN;
	matrix.relays[122].type = MODULE;
	matrix.relays[122].MCZ33996.cs = 3;
	matrix.relays[122].MCZ33996.spi = 4;
	matrix.relays[122].MCZ33996.pin = 2;

	matrix.relays[123].id = "20A";
	matrix.relays[123].status = OPEN;
	matrix.relays[123].type = MODULE;
	matrix.relays[123].MCZ33996.cs = 4;
	matrix.relays[123].MCZ33996.spi = 4;
	matrix.relays[123].MCZ33996.pin = 0;

	matrix.relays[124].id = "20B";
	matrix.relays[124].status = OPEN;
	matrix.relays[124].type = MODULE;
	matrix.relays[124].MCZ33996.cs = 4;
	matrix.relays[124].MCZ33996.spi = 4;
	matrix.relays[124].MCZ33996.pin = 1;

	matrix.relays[125].id = "20C";
	matrix.relays[125].status = OPEN;
	matrix.relays[125].type = MODULE;
	matrix.relays[125].MCZ33996.cs = 4;
	matrix.relays[125].MCZ33996.spi = 4;
	matrix.relays[125].MCZ33996.pin = 2;

	matrix.relays[126].id = "AA";
	matrix.relays[126].status = OPEN;
	matrix.relays[126].type = MODULE;
	matrix.relays[126].MCZ33996.cs = 4;
	matrix.relays[126].MCZ33996.spi = 4;
	matrix.relays[126].MCZ33996.pin = 14;

	matrix.relays[127].id = "BB";
	matrix.relays[127].status = OPEN;
	matrix.relays[127].type = MODULE;
	matrix.relays[127].MCZ33996.cs = 4;
	matrix.relays[127].MCZ33996.spi = 4;
	matrix.relays[127].MCZ33996.pin = 13;

	matrix.relays[128].id = "CC";
	matrix.relays[128].status = OPEN;
	matrix.relays[128].type = MODULE;
	matrix.relays[128].MCZ33996.cs = 4;
	matrix.relays[128].MCZ33996.spi = 4;
	matrix.relays[128].MCZ33996.pin = 12;

	matrix.relays[129].id = "CD";
	matrix.relays[129].status = OPEN;
	matrix.relays[129].type = MODULE;
	matrix.relays[129].MCZ33996.cs = 4;
	matrix.relays[129].MCZ33996.spi = 4;
	matrix.relays[129].MCZ33996.pin = 11;

	matrix.relays[130].id = "BE";
	matrix.relays[130].status = OPEN;
	matrix.relays[130].type = MODULE;
	matrix.relays[130].MCZ33996.cs = 4;
	matrix.relays[130].MCZ33996.spi = 4;
	matrix.relays[130].MCZ33996.pin = 10;

	matrix.relays[131].id = "AF";
	matrix.relays[131].status = OPEN;
	matrix.relays[131].type = MODULE;
	matrix.relays[131].MCZ33996.cs = 4;
	matrix.relays[131].MCZ33996.spi = 4;
	matrix.relays[131].MCZ33996.pin = 9;
}
