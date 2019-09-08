EESchema Schematic File Version 4
LIBS:ETH6C16MUX-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 8
Title "Ethernet"
Date ""
Rev "1.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ETH6C16MUX:LAN8742 U202
U 1 1 5D7788FE
P 3100 3400
F 0 "U202" H 2450 4550 50  0000 C CNN
F 1 "LAN8742" H 3550 4550 50  0000 C CNN
F 2 "Package_DFN_QFN:QFN-24-1EP_4x4mm_P0.5mm_EP2.6x2.6mm" H 3150 2350 50  0001 L CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/8720a.pdf" H 2900 2450 50  0001 C CNN
	1    3100 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R205
U 1 1 5D77A84D
P 4000 3500
F 0 "R205" V 3900 3500 50  0000 C CNN
F 1 "12k1" V 4000 3500 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3930 3500 50  0001 C CNN
F 3 "~" H 4000 3500 50  0001 C CNN
	1    4000 3500
	0    1    1    0   
$EndComp
Wire Wire Line
	3850 3500 3800 3500
Wire Wire Line
	4200 3500 4150 3500
$Comp
L Device:LED D201
U 1 1 5D77BF7F
P 4000 4000
F 0 "D201" V 4039 3882 50  0000 R CNN
F 1 "YELLOW" V 3948 3882 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4000 4000 50  0001 C CNN
F 3 "~" H 4000 4000 50  0001 C CNN
	1    4000 4000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4000 3850 4000 3800
Wire Wire Line
	4000 3800 3800 3800
$Comp
L Device:LED D202
U 1 1 5D77C93E
P 4500 4000
F 0 "D202" V 4539 3882 50  0000 R CNN
F 1 "GREEN" V 4448 3882 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4500 4000 50  0001 C CNN
F 3 "~" H 4500 4000 50  0001 C CNN
	1    4500 4000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4500 3850 4500 3700
Wire Wire Line
	4500 3700 3800 3700
$Comp
L Device:R R208
U 1 1 5D77CF0D
P 4000 4300
F 0 "R208" H 4070 4346 50  0000 L CNN
F 1 "270" H 4070 4255 50  0000 L CNN
F 2 "ETH6C16MXU:R_0603_E_Pad1.05x0.95mm_HandSolder" V 3930 4300 50  0001 C CNN
F 3 "~" H 4000 4300 50  0001 C CNN
	1    4000 4300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R209
U 1 1 5D77FB64
P 4500 4300
F 0 "R209" H 4570 4346 50  0000 L CNN
F 1 "270" H 4570 4255 50  0000 L CNN
F 2 "ETH6C16MXU:R_0603_E_Pad1.05x0.95mm_HandSolder" V 4430 4300 50  0001 C CNN
F 3 "~" H 4500 4300 50  0001 C CNN
	1    4500 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 4450 4000 4500
Wire Wire Line
	4000 4500 4250 4500
Wire Wire Line
	4500 4500 4500 4450
Wire Wire Line
	4250 4550 4250 4500
Connection ~ 4250 4500
Wire Wire Line
	4250 4500 4500 4500
Wire Wire Line
	3100 4550 3100 4500
$Comp
L Device:C C208
U 1 1 5D7836AB
P 1800 1950
F 0 "C208" H 1915 1996 50  0000 L CNN
F 1 "470p" H 1915 1905 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1838 1800 50  0001 C CNN
F 3 "~" H 1800 1950 50  0001 C CNN
	1    1800 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:C C209
U 1 1 5D7839BC
P 2250 1950
F 0 "C209" H 2365 1996 50  0000 L CNN
F 1 "1u" H 2365 1905 50  0000 L CNN
F 2 "ETH6C16MXU:C_0603_B_Pad1.05x0.95mm_HandSolder" H 2288 1800 50  0001 C CNN
F 3 "~" H 2250 1950 50  0001 C CNN
	1    2250 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 1750 1800 1800
Wire Wire Line
	2250 1800 2250 1750
Connection ~ 2250 1750
Wire Wire Line
	1800 2100 1800 2150
Wire Wire Line
	1800 2150 2050 2150
Wire Wire Line
	2250 2150 2250 2100
Wire Wire Line
	2050 2200 2050 2150
Connection ~ 2050 2150
Wire Wire Line
	2050 2150 2250 2150
$Comp
L power:PWR_FLAG #FLG0202
U 1 1 5D788385
P 1700 1750
F 0 "#FLG0202" H 1700 1825 50  0001 C CNN
F 1 "PWR_FLAG" V 1700 1877 50  0000 L CNN
F 2 "" H 1700 1750 50  0001 C CNN
F 3 "~" H 1700 1750 50  0001 C CNN
	1    1700 1750
	0    -1   -1   0   
$EndComp
$Comp
L ETH6C16MUX:749010012A L201
U 1 1 5D78EEFA
P 7950 3200
F 0 "L201" H 7950 3765 50  0000 C CNN
F 1 "749010012A" H 7950 3674 50  0000 C CNN
F 2 "ETH6C16MXU:749010012A" H 8950 3450 50  0001 C CNN
F 3 "" H 8950 3450 50  0001 C CNN
	1    7950 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 3400 7550 3400
Wire Wire Line
	7450 3400 7450 3000
Wire Wire Line
	7450 3000 7550 3000
$Comp
L Device:R R206
U 1 1 5D798866
P 8450 3850
F 0 "R206" H 8520 3896 50  0000 L CNN
F 1 "75/1%" H 8520 3805 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8380 3850 50  0001 C CNN
F 3 "~" H 8450 3850 50  0001 C CNN
	1    8450 3850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R207
U 1 1 5D798A04
P 8950 3850
F 0 "R207" H 9020 3896 50  0000 L CNN
F 1 "75/1%" H 9020 3805 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8880 3850 50  0001 C CNN
F 3 "~" H 8950 3850 50  0001 C CNN
	1    8950 3850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C211
U 1 1 5D798BC2
P 8700 4250
F 0 "C211" H 8815 4296 50  0000 L CNN
F 1 "1n/1kV" H 8815 4205 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 8738 4100 50  0001 C CNN
F 3 "~" H 8700 4250 50  0001 C CNN
	1    8700 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 4000 8450 4050
Wire Wire Line
	8450 4050 8700 4050
Wire Wire Line
	8950 4050 8950 4000
Wire Wire Line
	8700 4100 8700 4050
Connection ~ 8700 4050
Wire Wire Line
	8700 4050 8950 4050
$Comp
L power:Earth #PWR0214
U 1 1 5D79DEAE
P 8700 4450
F 0 "#PWR0214" H 8700 4200 50  0001 C CNN
F 1 "Earth" H 8700 4300 50  0001 C CNN
F 2 "" H 8700 4450 50  0001 C CNN
F 3 "~" H 8700 4450 50  0001 C CNN
	1    8700 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 4400 8700 4450
Wire Wire Line
	8450 3700 8450 3400
Wire Wire Line
	8450 3400 8350 3400
Wire Wire Line
	8950 3700 8950 3000
Wire Wire Line
	8950 3000 8350 3000
Wire Wire Line
	7450 3700 7450 3400
Wire Wire Line
	7450 4050 7450 4000
$Comp
L Device:C C210
U 1 1 5D78FAC8
P 7450 3850
F 0 "C210" H 7565 3896 50  0000 L CNN
F 1 "100n" H 7565 3805 50  0000 L CNN
F 2 "ETH6C16MXU:C_0603_A_Pad1.05x0.95mm_HandSolder" H 7488 3700 50  0001 C CNN
F 3 "~" H 7450 3850 50  0001 C CNN
	1    7450 3850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R210
U 1 1 5D7A4345
P 7950 4500
F 0 "R210" V 7743 4500 50  0000 C CNN
F 1 "1M/1kV" V 7834 4500 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 7880 4500 50  0001 C CNN
F 3 "~" H 7950 4500 50  0001 C CNN
	1    7950 4500
	0    1    1    0   
$EndComp
$Comp
L Device:C C212
U 1 1 5D7A48DD
P 7950 4900
F 0 "C212" V 7698 4900 50  0000 C CNN
F 1 "1n/1kV" V 7789 4900 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 7988 4750 50  0001 C CNN
F 3 "~" H 7950 4900 50  0001 C CNN
	1    7950 4900
	0    1    1    0   
$EndComp
Wire Wire Line
	7800 4500 7700 4500
Wire Wire Line
	7700 4500 7700 4900
Wire Wire Line
	7700 4900 7800 4900
Wire Wire Line
	8100 4500 8200 4500
Wire Wire Line
	8200 4500 8200 4900
Wire Wire Line
	8200 4900 8100 4900
$Comp
L power:Earth #PWR0218
U 1 1 5D7A6317
P 8200 5100
F 0 "#PWR0218" H 8200 4850 50  0001 C CNN
F 1 "Earth" H 8200 4950 50  0001 C CNN
F 2 "" H 8200 5100 50  0001 C CNN
F 3 "~" H 8200 5100 50  0001 C CNN
	1    8200 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 5100 8200 4900
Connection ~ 8200 4900
Wire Wire Line
	7700 5100 7700 4900
Connection ~ 7700 4900
Wire Wire Line
	2250 1750 3000 1750
Wire Wire Line
	3000 1750 3000 2200
$Comp
L ETH6C16MUX:LC03-3.3 U201
U 1 1 5D7B5D01
P 10050 2850
F 0 "U201" H 10050 3287 60  0000 C CNN
F 1 "LC03-3.3" H 10050 3181 60  0000 C CNN
F 2 "ETH6C16MXU:SO8E" H 10050 2850 60  0001 C CNN
F 3 "" H 10050 2850 60  0000 C CNN
	1    10050 2850
	1    0    0    -1  
$EndComp
$Comp
L ETH6C16MUX:LC03-3.3 U203
U 1 1 5D7B67F8
P 10050 3650
F 0 "U203" H 10050 4087 60  0000 C CNN
F 1 "LC03-3.3" H 10050 3981 60  0000 C CNN
F 2 "ETH6C16MXU:SO8E" H 10050 3650 60  0001 C CNN
F 3 "" H 10050 3650 60  0000 C CNN
	1    10050 3650
	1    0    0    -1  
$EndComp
NoConn ~ 9700 3600
NoConn ~ 9700 3700
NoConn ~ 10400 3700
NoConn ~ 10400 3600
NoConn ~ 9700 2900
NoConn ~ 9700 2800
NoConn ~ 10400 2800
NoConn ~ 10400 2900
Wire Wire Line
	8350 3100 9600 3100
Wire Wire Line
	9600 3100 9600 3000
Wire Wire Line
	9600 3000 9700 3000
Wire Wire Line
	8350 2900 9400 2900
Wire Wire Line
	9400 2900 9400 2700
Wire Wire Line
	9400 2700 9700 2700
Wire Wire Line
	8350 3300 9600 3300
Wire Wire Line
	9600 3300 9600 3500
Wire Wire Line
	9600 3500 9700 3500
Wire Wire Line
	8350 3500 9400 3500
Wire Wire Line
	9400 3500 9400 3800
Wire Wire Line
	9400 3800 9700 3800
Wire Wire Line
	10400 2700 10500 2700
Wire Wire Line
	10400 3000 10500 3000
Wire Wire Line
	10400 3500 10500 3500
Wire Wire Line
	10400 3800 10500 3800
Wire Wire Line
	7350 3000 7350 3100
Wire Wire Line
	7350 3100 7550 3100
Wire Wire Line
	7250 3100 7250 3300
Wire Wire Line
	7250 3300 7550 3300
Connection ~ 7450 3400
Wire Wire Line
	7100 3200 7100 3500
Wire Wire Line
	7100 3500 7550 3500
Text HLabel 10500 2700 2    50   BiDi ~ 0
TX+
Text HLabel 10500 3000 2    50   BiDi ~ 0
TX-
Text HLabel 10500 3500 2    50   BiDi ~ 0
RX+
Text HLabel 10500 3800 2    50   BiDi ~ 0
RX-
$Comp
L Device:C C201
U 1 1 5D812F75
P 1800 1250
F 0 "C201" H 1915 1296 50  0000 L CNN
F 1 "100n" H 1915 1205 50  0000 L CNN
F 2 "ETH6C16MXU:C_0603_A_Pad1.05x0.95mm_HandSolder" H 1838 1100 50  0001 C CNN
F 3 "~" H 1800 1250 50  0001 C CNN
	1    1800 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C202
U 1 1 5D8133E4
P 2250 1250
F 0 "C202" H 2365 1296 50  0000 L CNN
F 1 "100n" H 2365 1205 50  0000 L CNN
F 2 "ETH6C16MXU:C_0603_A_Pad1.05x0.95mm_HandSolder" H 2288 1100 50  0001 C CNN
F 3 "~" H 2250 1250 50  0001 C CNN
	1    2250 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 1100 1800 1050
Wire Wire Line
	1800 1050 2250 1050
Wire Wire Line
	2250 1100 2250 1050
Connection ~ 2250 1050
$Comp
L Device:Ferrite_Bead FB201
U 1 1 5D817580
P 3100 1050
F 0 "FB201" V 2826 1050 50  0000 C CNN
F 1 "742792031" V 2917 1050 50  0000 C CNN
F 2 "ETH6C16MXU:R_0805_D_Pad1.15x1.40mm_HandSolder" V 3030 1050 50  0001 C CNN
F 3 "~" H 3100 1050 50  0001 C CNN
	1    3100 1050
	0    1    1    0   
$EndComp
$Comp
L Device:C C203
U 1 1 5D81C715
P 3350 1250
F 0 "C203" H 3465 1296 50  0000 L CNN
F 1 "1u" H 3465 1205 50  0000 L CNN
F 2 "ETH6C16MXU:C_0603_B_Pad1.05x0.95mm_HandSolder" H 3388 1100 50  0001 C CNN
F 3 "~" H 3350 1250 50  0001 C CNN
	1    3350 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 1100 3350 1050
Wire Wire Line
	3350 1050 3250 1050
$Comp
L Device:C C204
U 1 1 5D81F20B
P 3800 1250
F 0 "C204" H 3915 1296 50  0000 L CNN
F 1 "100n" H 3915 1205 50  0000 L CNN
F 2 "ETH6C16MXU:C_0603_A_Pad1.05x0.95mm_HandSolder" H 3838 1100 50  0001 C CNN
F 3 "~" H 3800 1250 50  0001 C CNN
	1    3800 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 1100 3800 1050
Wire Wire Line
	3800 1050 3350 1050
Connection ~ 3350 1050
$Comp
L Device:C C205
U 1 1 5D8215D9
P 4250 1250
F 0 "C205" H 4365 1296 50  0000 L CNN
F 1 "100n" H 4365 1205 50  0000 L CNN
F 2 "ETH6C16MXU:C_0603_A_Pad1.05x0.95mm_HandSolder" H 4288 1100 50  0001 C CNN
F 3 "~" H 4250 1250 50  0001 C CNN
	1    4250 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 1100 4250 1050
Wire Wire Line
	4250 1050 3800 1050
Connection ~ 3800 1050
Wire Wire Line
	3100 2200 3100 2150
Wire Wire Line
	3100 2150 3200 2150
Wire Wire Line
	3200 2150 3200 2200
Wire Wire Line
	3200 2150 3200 1750
Wire Wire Line
	3200 1750 4650 1750
Wire Wire Line
	4650 1050 4250 1050
Connection ~ 3200 2150
Connection ~ 4250 1050
$Comp
L Device:C C206
U 1 1 5D82B9EA
P 4850 1250
F 0 "C206" H 4965 1296 50  0000 L CNN
F 1 "100n" H 4965 1205 50  0000 L CNN
F 2 "ETH6C16MXU:C_0603_A_Pad1.05x0.95mm_HandSolder" H 4888 1100 50  0001 C CNN
F 3 "~" H 4850 1250 50  0001 C CNN
	1    4850 1250
	1    0    0    -1  
$EndComp
Connection ~ 4650 1050
$Comp
L power:PWR_FLAG #FLG0201
U 1 1 5D82F1E4
P 4650 1000
F 0 "#FLG0201" H 4650 1075 50  0001 C CNN
F 1 "PWR_FLAG" H 4650 1173 50  0000 C CNN
F 2 "" H 4650 1000 50  0001 C CNN
F 3 "~" H 4650 1000 50  0001 C CNN
	1    4650 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 1000 4650 1050
Wire Wire Line
	4850 1100 4850 1050
$Comp
L Device:C C207
U 1 1 5D856848
P 7000 1250
F 0 "C207" H 7115 1296 50  0000 L CNN
F 1 "100n" H 7115 1205 50  0000 L CNN
F 2 "ETH6C16MXU:C_0603_A_Pad1.05x0.95mm_HandSolder" H 7038 1100 50  0001 C CNN
F 3 "~" H 7000 1250 50  0001 C CNN
	1    7000 1250
	1    0    0    -1  
$EndComp
Connection ~ 4850 1050
Wire Wire Line
	4650 1050 4850 1050
$Comp
L Device:R R204
U 1 1 5D83805E
P 6500 1250
F 0 "R204" H 6570 1296 50  0000 L CNN
F 1 "49R9" H 6570 1205 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6430 1250 50  0001 C CNN
F 3 "~" H 6500 1250 50  0001 C CNN
	1    6500 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R203
U 1 1 5D8377DD
P 6100 1250
F 0 "R203" H 6170 1296 50  0000 L CNN
F 1 "49R9" H 6170 1205 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6030 1250 50  0001 C CNN
F 3 "~" H 6100 1250 50  0001 C CNN
	1    6100 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R202
U 1 1 5D836A9D
P 5700 1250
F 0 "R202" H 5770 1296 50  0000 L CNN
F 1 "49R9" H 5770 1205 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 5630 1250 50  0001 C CNN
F 3 "~" H 5700 1250 50  0001 C CNN
	1    5700 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R201
U 1 1 5D8334FE
P 5300 1250
F 0 "R201" H 5370 1296 50  0000 L CNN
F 1 "49R9" H 5370 1205 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 5230 1250 50  0001 C CNN
F 3 "~" H 5300 1250 50  0001 C CNN
	1    5300 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 3200 6500 3200
Wire Wire Line
	3800 3100 6100 3100
Wire Wire Line
	3800 3000 5700 3000
Wire Wire Line
	3800 2900 5300 2900
Wire Wire Line
	4850 1050 5300 1050
Wire Wire Line
	5300 1100 5300 1050
Connection ~ 5300 1050
Wire Wire Line
	5300 1050 5700 1050
Wire Wire Line
	5700 1100 5700 1050
Connection ~ 5700 1050
Wire Wire Line
	5700 1050 6100 1050
Wire Wire Line
	1700 1750 1800 1750
Connection ~ 1800 1750
Wire Wire Line
	1800 1750 2250 1750
Wire Wire Line
	2250 1050 2900 1050
Wire Wire Line
	2900 2200 2900 1050
Connection ~ 2900 1050
Wire Wire Line
	2900 1050 2950 1050
Wire Wire Line
	4650 1750 4650 1050
Wire Wire Line
	7450 1050 7450 3000
Connection ~ 7450 3000
Wire Wire Line
	7000 1100 7000 1050
Connection ~ 7000 1050
Wire Wire Line
	7000 1050 7450 1050
Wire Wire Line
	6500 1100 6500 1050
Connection ~ 6500 1050
Wire Wire Line
	6500 1050 7000 1050
Wire Wire Line
	6100 1100 6100 1050
Connection ~ 6100 1050
Wire Wire Line
	6100 1050 6500 1050
Wire Wire Line
	1800 1450 1800 1400
Wire Wire Line
	2250 1450 2250 1400
Wire Wire Line
	3350 1450 3350 1400
Wire Wire Line
	3800 1450 3800 1400
Wire Wire Line
	4250 1450 4250 1400
Wire Wire Line
	4850 1450 4850 1400
Wire Wire Line
	7000 1450 7000 1400
Wire Wire Line
	2300 3600 1550 3600
Wire Wire Line
	2300 3500 1550 3500
Wire Wire Line
	2300 3400 1550 3400
Wire Wire Line
	2300 3300 1800 3300
Wire Wire Line
	2300 3200 1550 3200
Wire Wire Line
	2300 3100 1550 3100
Wire Wire Line
	2300 3000 1550 3000
Wire Wire Line
	2300 2900 1550 2900
Wire Wire Line
	2300 2800 1550 2800
$Comp
L Device:R R212
U 1 1 5D90AA6A
P 1450 6450
F 0 "R212" H 1520 6496 50  0000 L CNN
F 1 "10k" H 1520 6405 50  0000 L CNN
F 2 "ETH6C16MXU:R_0603_E_Pad1.05x0.95mm_HandSolder" V 1380 6450 50  0001 C CNN
F 3 "~" H 1450 6450 50  0001 C CNN
	1    1450 6450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R213
U 1 1 5D90BF82
P 1800 6450
F 0 "R213" H 1870 6496 50  0000 L CNN
F 1 "10k" H 1870 6405 50  0000 L CNN
F 2 "ETH6C16MXU:R_0603_E_Pad1.05x0.95mm_HandSolder" V 1730 6450 50  0001 C CNN
F 3 "~" H 1800 6450 50  0001 C CNN
	1    1800 6450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R214
U 1 1 5D90C23E
P 2150 6450
F 0 "R214" H 2220 6496 50  0000 L CNN
F 1 "10k" H 2220 6405 50  0000 L CNN
F 2 "ETH6C16MXU:R_0603_E_Pad1.05x0.95mm_HandSolder" V 2080 6450 50  0001 C CNN
F 3 "~" H 2150 6450 50  0001 C CNN
	1    2150 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 6300 1450 6250
Wire Wire Line
	1450 6250 1800 6250
Wire Wire Line
	2150 6250 2150 6300
Wire Wire Line
	1800 6300 1800 6250
Connection ~ 1800 6250
Wire Wire Line
	1800 6250 2150 6250
Wire Wire Line
	1450 6600 1450 7100
Wire Wire Line
	1800 6600 1800 7100
Wire Wire Line
	2150 6600 2150 7100
Text Label 4200 2900 2    50   ~ 0
ETH_TXP
Text Label 4200 3000 2    50   ~ 0
ETH_TXN
Text Label 4200 3100 2    50   ~ 0
ETH_RXP
Text Label 4200 3200 2    50   ~ 0
ETH_RXN
Wire Wire Line
	5300 1400 5300 2900
Connection ~ 5300 2900
Wire Wire Line
	5300 2900 7550 2900
Wire Wire Line
	5700 1400 5700 3000
Connection ~ 5700 3000
Wire Wire Line
	5700 3000 7350 3000
Wire Wire Line
	6100 1400 6100 3100
Connection ~ 6100 3100
Wire Wire Line
	6100 3100 7250 3100
Wire Wire Line
	6500 1400 6500 3200
Connection ~ 6500 3200
Wire Wire Line
	6500 3200 7100 3200
Wire Wire Line
	1800 1000 1800 1050
Connection ~ 1800 1050
Wire Wire Line
	1800 6200 1800 6250
Wire Wire Line
	2300 3800 1550 3800
Wire Wire Line
	2300 3900 1550 3900
NoConn ~ 2300 4200
Wire Wire Line
	2300 4100 1250 4100
$Comp
L ETH6C16MUX:SR3.3 U205
U 1 1 5D9B1A51
P 6000 4600
F 0 "U205" H 6000 5015 50  0000 C CNN
F 1 "SR3.3" H 6000 4924 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-143_Handsoldering" H 6125 4800 50  0001 C CNN
F 3 "" H 6125 4800 50  0001 C CNN
	1    6000 4600
	1    0    0    -1  
$EndComp
$Comp
L ETH6C16MUX:SR3.3 U204
U 1 1 5D9B4299
P 6000 3800
F 0 "U204" H 6000 4215 50  0000 C CNN
F 1 "SR3.3" H 6000 4124 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-143_Handsoldering" H 6125 4000 50  0001 C CNN
F 3 "" H 6125 4000 50  0001 C CNN
	1    6000 3800
	1    0    0    -1  
$EndComp
NoConn ~ 6300 3650
NoConn ~ 6300 4450
Text Label 6650 3950 2    50   ~ 0
ETH_TXP
Text Label 5350 3950 0    50   ~ 0
ETH_TXN
Text Label 6650 4750 2    50   ~ 0
ETH_RXP
Text Label 5350 4750 0    50   ~ 0
ETH_RXN
Wire Wire Line
	5700 4750 5350 4750
Wire Wire Line
	6650 4750 6300 4750
Wire Wire Line
	5700 3950 5350 3950
Wire Wire Line
	6650 3950 6300 3950
Wire Notes Line
	7950 6450 7950 5100
Wire Notes Line
	7950 4150 7950 3650
Wire Notes Line
	7950 2550 7950 550 
Text Label 1800 3300 0    50   ~ 0
ETH_RXER
Text Label 1800 3500 0    50   ~ 0
ETH_MDIO
Text Label 1800 3900 0    50   ~ 0
ETH_~INT
Text Label 1450 7100 1    50   ~ 0
ETH_RXER
Text Label 1800 7100 1    50   ~ 0
ETH_MDIO
Text Label 2150 7100 1    50   ~ 0
ETH_~INT
Text HLabel 1550 2900 0    50   BiDi ~ 0
ETH_RMII_TX1
Text HLabel 1550 2800 0    50   BiDi ~ 0
ETH_RMII_TX0
Text HLabel 1550 3000 0    50   BiDi ~ 0
ETH_RMII_TXEN
Text HLabel 1550 3100 0    50   BiDi ~ 0
ETH_RMII_RX0
Text HLabel 1550 3200 0    50   BiDi ~ 0
ETH_RMII_RX1
Text HLabel 1550 3400 0    50   BiDi ~ 0
ETH_RMII_CRS_DV
Text HLabel 1550 3500 0    50   BiDi ~ 0
ETH_RMII_MDIO
Text HLabel 1550 3600 0    50   BiDi ~ 0
ETH_RMII_MDC
Text HLabel 1550 3800 0    50   BiDi ~ 0
ETH_~RST
Text HLabel 1550 3900 0    50   BiDi ~ 0
ETH_~INT
Text Label 1250 4100 0    50   ~ 0
ETH_REFCLK_PHY_50MHZ
Text Label 5400 6600 2    50   ~ 0
ETH_REFCLK_PHY_50MHZ
$Comp
L Device:C C213
U 1 1 5DB339D8
P 2800 6900
F 0 "C213" H 2915 6946 50  0000 L CNN
F 1 "100n" H 2915 6855 50  0000 L CNN
F 2 "ETH6C16MXU:C_0603_A_Pad1.05x0.95mm_HandSolder" H 2838 6750 50  0001 C CNN
F 3 "~" H 2800 6900 50  0001 C CNN
	1    2800 6900
	1    0    0    -1  
$EndComp
Text HLabel 4650 6250 2    50   Output ~ 0
ETH_RMII_REF_CLK
$Comp
L Oscillator:ASDMB-xxxMHz U206
U 1 1 5DB0D8D2
P 3450 6600
F 0 "U206" H 3150 6850 50  0000 L CNN
F 1 "ASDM1-50.000MHZ-LC-T" H 3850 6400 50  0000 L CNN
F 2 "Oscillator:Oscillator_SMD_Abracon_ASDMB-4Pin_2.5x2.0mm" H 3450 6600 50  0001 C CNN
F 3 "https://abracon.com/Oscillators/ASDMB.pdf" H 3750 7050 50  0001 C CNN
	1    3450 6600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 6250 2800 6250
Wire Wire Line
	2800 6250 2800 6600
Wire Wire Line
	2800 6600 3050 6600
Wire Wire Line
	3550 6300 3550 6250
Wire Wire Line
	3550 6250 3550 6200
Connection ~ 3550 6250
Wire Wire Line
	2800 6750 2800 6600
Connection ~ 2800 6600
Wire Wire Line
	2800 7050 2800 7100
Wire Wire Line
	2800 7100 3550 7100
Wire Wire Line
	3550 7100 3550 6900
$Comp
L power:GND #PWR0215
U 1 1 5DBA4079
P 3100 4550
F 0 "#PWR0215" H 3100 4300 50  0001 C CNN
F 1 "GND" H 3105 4377 50  0000 C CNN
F 2 "" H 3100 4550 50  0001 C CNN
F 3 "" H 3100 4550 50  0001 C CNN
	1    3100 4550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0216
U 1 1 5DBA4651
P 4250 4550
F 0 "#PWR0216" H 4250 4300 50  0001 C CNN
F 1 "GND" H 4255 4377 50  0000 C CNN
F 2 "" H 4250 4550 50  0001 C CNN
F 3 "" H 4250 4550 50  0001 C CNN
	1    4250 4550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0210
U 1 1 5DBA4993
P 4200 3500
F 0 "#PWR0210" H 4200 3250 50  0001 C CNN
F 1 "GND" V 4205 3372 50  0000 R CNN
F 2 "" H 4200 3500 50  0001 C CNN
F 3 "" H 4200 3500 50  0001 C CNN
	1    4200 3500
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0211
U 1 1 5DBA709B
P 5700 3650
F 0 "#PWR0211" H 5700 3400 50  0001 C CNN
F 1 "GND" V 5705 3522 50  0000 R CNN
F 2 "" H 5700 3650 50  0001 C CNN
F 3 "" H 5700 3650 50  0001 C CNN
	1    5700 3650
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0213
U 1 1 5DBA763A
P 5700 4450
F 0 "#PWR0213" H 5700 4200 50  0001 C CNN
F 1 "GND" V 5705 4322 50  0000 R CNN
F 2 "" H 5700 4450 50  0001 C CNN
F 3 "" H 5700 4450 50  0001 C CNN
	1    5700 4450
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0209
U 1 1 5DBAA3D5
P 2050 2200
F 0 "#PWR0209" H 2050 1950 50  0001 C CNN
F 1 "GND" H 2055 2027 50  0000 C CNN
F 2 "" H 2050 2200 50  0001 C CNN
F 3 "" H 2050 2200 50  0001 C CNN
	1    2050 2200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0202
U 1 1 5DBAB7F8
P 1800 1450
F 0 "#PWR0202" H 1800 1200 50  0001 C CNN
F 1 "GND" H 1805 1277 50  0000 C CNN
F 2 "" H 1800 1450 50  0001 C CNN
F 3 "" H 1800 1450 50  0001 C CNN
	1    1800 1450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0203
U 1 1 5DBABCDB
P 2250 1450
F 0 "#PWR0203" H 2250 1200 50  0001 C CNN
F 1 "GND" H 2255 1277 50  0000 C CNN
F 2 "" H 2250 1450 50  0001 C CNN
F 3 "" H 2250 1450 50  0001 C CNN
	1    2250 1450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0204
U 1 1 5DBABF48
P 3350 1450
F 0 "#PWR0204" H 3350 1200 50  0001 C CNN
F 1 "GND" H 3355 1277 50  0000 C CNN
F 2 "" H 3350 1450 50  0001 C CNN
F 3 "" H 3350 1450 50  0001 C CNN
	1    3350 1450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0205
U 1 1 5DBAC1F8
P 3800 1450
F 0 "#PWR0205" H 3800 1200 50  0001 C CNN
F 1 "GND" H 3805 1277 50  0000 C CNN
F 2 "" H 3800 1450 50  0001 C CNN
F 3 "" H 3800 1450 50  0001 C CNN
	1    3800 1450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0206
U 1 1 5DBAC3F4
P 4250 1450
F 0 "#PWR0206" H 4250 1200 50  0001 C CNN
F 1 "GND" H 4255 1277 50  0000 C CNN
F 2 "" H 4250 1450 50  0001 C CNN
F 3 "" H 4250 1450 50  0001 C CNN
	1    4250 1450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0207
U 1 1 5DBACB32
P 4850 1450
F 0 "#PWR0207" H 4850 1200 50  0001 C CNN
F 1 "GND" H 4855 1277 50  0000 C CNN
F 2 "" H 4850 1450 50  0001 C CNN
F 3 "" H 4850 1450 50  0001 C CNN
	1    4850 1450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0208
U 1 1 5DBAD08C
P 7000 1450
F 0 "#PWR0208" H 7000 1200 50  0001 C CNN
F 1 "GND" H 7005 1277 50  0000 C CNN
F 2 "" H 7000 1450 50  0001 C CNN
F 3 "" H 7000 1450 50  0001 C CNN
	1    7000 1450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0212
U 1 1 5DBAD404
P 7450 4050
F 0 "#PWR0212" H 7450 3800 50  0001 C CNN
F 1 "GND" H 7455 3877 50  0000 C CNN
F 2 "" H 7450 4050 50  0001 C CNN
F 3 "" H 7450 4050 50  0001 C CNN
	1    7450 4050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0217
U 1 1 5DBAF536
P 7700 5100
F 0 "#PWR0217" H 7700 4850 50  0001 C CNN
F 1 "GND" H 7705 4927 50  0000 C CNN
F 2 "" H 7700 5100 50  0001 C CNN
F 3 "" H 7700 5100 50  0001 C CNN
	1    7700 5100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0221
U 1 1 5DBB2260
P 3550 7150
F 0 "#PWR0221" H 3550 6900 50  0001 C CNN
F 1 "GND" H 3555 6977 50  0000 C CNN
F 2 "" H 3550 7150 50  0001 C CNN
F 3 "" H 3550 7150 50  0001 C CNN
	1    3550 7150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 7150 3550 7100
Connection ~ 3550 7100
Wire Wire Line
	3850 6600 3900 6600
Connection ~ 3900 6600
Wire Wire Line
	3900 6600 4050 6600
Wire Wire Line
	4350 6600 5400 6600
Wire Wire Line
	4350 6250 4650 6250
Wire Wire Line
	3900 6250 4050 6250
Wire Wire Line
	3900 6250 3900 6600
$Comp
L Device:R R211
U 1 1 5D9C5767
P 4200 6250
F 0 "R211" V 3993 6250 50  0000 C CNN
F 1 "220" V 4084 6250 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4130 6250 50  0001 C CNN
F 3 "~" H 4200 6250 50  0001 C CNN
	1    4200 6250
	0    1    1    0   
$EndComp
$Comp
L Device:R R215
U 1 1 5D9C7133
P 4200 6600
F 0 "R215" V 3993 6600 50  0000 C CNN
F 1 "220" V 4084 6600 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4130 6600 50  0001 C CNN
F 3 "~" H 4200 6600 50  0001 C CNN
	1    4200 6600
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR0219
U 1 1 5DACAFF6
P 1800 6200
F 0 "#PWR0219" H 1800 6050 50  0001 C CNN
F 1 "+3.3V" H 1815 6373 50  0000 C CNN
F 2 "" H 1800 6200 50  0001 C CNN
F 3 "" H 1800 6200 50  0001 C CNN
	1    1800 6200
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0220
U 1 1 5DACB3A2
P 3550 6200
F 0 "#PWR0220" H 3550 6050 50  0001 C CNN
F 1 "+3.3V" H 3565 6373 50  0000 C CNN
F 2 "" H 3550 6200 50  0001 C CNN
F 3 "" H 3550 6200 50  0001 C CNN
	1    3550 6200
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0201
U 1 1 5DACB8D1
P 1800 1000
F 0 "#PWR0201" H 1800 850 50  0001 C CNN
F 1 "+3.3V" H 1815 1173 50  0000 C CNN
F 2 "" H 1800 1000 50  0001 C CNN
F 3 "" H 1800 1000 50  0001 C CNN
	1    1800 1000
	1    0    0    -1  
$EndComp
$EndSCHEMATC
