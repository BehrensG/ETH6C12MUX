EESchema Schematic File Version 4
LIBS:ETH6C20MUX-cache
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 6 6
Title "MCU"
Date ""
Rev "1.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_02x05_Odd_Even J601
U 1 1 5DBD02FD
P 1350 9800
F 0 "J601" H 1400 10217 50  0000 C CNN
F 1 "Conn_02x05" H 1400 10126 50  0000 C CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_2x05_P1.27mm_Vertical" H 1350 9800 50  0001 C CNN
F 3 "~" H 1350 9800 50  0001 C CNN
	1    1350 9800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 9600 950  9600
Wire Wire Line
	950  9600 950  9500
NoConn ~ 1150 9900
NoConn ~ 1150 10000
Wire Wire Line
	1150 9800 950  9800
Wire Wire Line
	950  9800 950  9700
Wire Wire Line
	950  9700 1150 9700
Wire Wire Line
	950  10050 950  9800
Connection ~ 950  9800
Wire Wire Line
	1650 9600 2250 9600
Wire Wire Line
	1650 9700 2250 9700
Wire Wire Line
	1650 9800 2250 9800
Wire Wire Line
	1650 9900 2250 9900
Wire Wire Line
	1650 10000 2250 10000
Text Label 2250 10000 2    50   ~ 0
MCU_NRST
Text Label 2250 9900 2    50   ~ 0
MCU_TDI
Text Label 2250 9600 2    50   ~ 0
MCU_TMS_SWDIO
Text Label 2250 9700 2    50   ~ 0
MCU_TCK_SWCLK
Text Label 2250 9800 2    50   ~ 0
MCU_TDO
Wire Wire Line
	3750 7400 3700 7400
Wire Wire Line
	3750 7300 3700 7300
Wire Wire Line
	3700 7100 3750 7100
Wire Wire Line
	3700 5300 3750 5300
Wire Wire Line
	3750 5700 3700 5700
Wire Wire Line
	3750 5600 3700 5600
Wire Wire Line
	3750 4200 3700 4200
Wire Wire Line
	3700 3700 3750 3700
Wire Wire Line
	3700 3600 3750 3600
Text HLabel 3700 3600 0    50   Input ~ 0
RMII_REF_CLK
Text HLabel 15600 8200 2    50   BiDi ~ 0
NRST
Text HLabel 3700 5300 0    50   BiDi ~ 0
RMII_MDC
Text HLabel 3700 4200 0    50   BiDi ~ 0
RMII_CRS_DV
Text HLabel 3700 5700 0    50   BiDi ~ 0
RMII_RXD1
Text HLabel 3700 5600 0    50   BiDi ~ 0
RMII_RXD0
Text HLabel 3700 7100 0    50   BiDi ~ 0
RMII_TXEN
Text HLabel 3700 7300 0    50   BiDi ~ 0
RMII_TX0
Wire Wire Line
	15900 6000 15150 6000
Text Label 15900 6000 2    50   ~ 0
MCU_TDO
Text Label 3000 4800 0    50   ~ 0
MCU_TMS_SWDIO
Text Label 3000 4900 0    50   ~ 0
MCU_TCK_SWCLK
Text Label 3000 5000 0    50   ~ 0
MCU_TDI
Text Label 15600 8200 2    50   ~ 0
MCU_NRST
Wire Wire Line
	3750 5000 3000 5000
Wire Wire Line
	3750 4800 3000 4800
Wire Wire Line
	3750 4900 3000 4900
Text Label 3150 3100 0    50   ~ 0
MCU_FLASH1_CS
Wire Wire Line
	3750 3100 3150 3100
Text Label 3150 6400 0    50   ~ 0
MCU_SPI3_MOSI
Text Label 3150 6300 0    50   ~ 0
MCU_SPI3_MISO
Text Label 3150 6200 0    50   ~ 0
MCU_SPI3_SCLK
Wire Wire Line
	3750 6400 3150 6400
Wire Wire Line
	3150 6200 3750 6200
Wire Wire Line
	3750 6300 3150 6300
Wire Wire Line
	9450 1100 9450 1150
$Comp
L Device:R R604
U 1 1 5D7471E3
P 15200 8000
F 0 "R604" H 15270 8046 50  0000 L CNN
F 1 "10k" H 15270 7955 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 15130 8000 50  0001 C CNN
F 3 "~" H 15200 8000 50  0001 C CNN
	1    15200 8000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C607
U 1 1 5D746777
P 15200 8400
F 0 "C607" H 15315 8446 50  0000 L CNN
F 1 "100n" H 15315 8355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 15238 8250 50  0001 C CNN
F 3 "~" H 15200 8400 50  0001 C CNN
	1    15200 8400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 8600 3350 8600
Text Label 3350 8400 0    50   ~ 0
MCU_VDDA
Wire Wire Line
	3750 8400 3350 8400
Wire Wire Line
	2750 8650 2750 8600
Wire Wire Line
	2950 8600 2950 8550
Wire Wire Line
	2500 8550 2500 8600
Wire Wire Line
	2950 8200 2950 8250
Wire Wire Line
	2500 8000 2500 8250
$Comp
L Device:C C606
U 1 1 5D63E410
P 2950 8400
F 0 "C606" H 3065 8446 50  0000 L CNN
F 1 "2u2" H 3065 8355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2988 8250 50  0001 C CNN
F 3 "~" H 2950 8400 50  0001 C CNN
	1    2950 8400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C605
U 1 1 5D63DDBE
P 2500 8400
F 0 "C605" H 2615 8446 50  0000 L CNN
F 1 "2u2" H 2615 8355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2538 8250 50  0001 C CNN
F 3 "~" H 2500 8400 50  0001 C CNN
	1    2500 8400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 8800 3750 8800
Wire Wire Line
	9450 9400 9450 9350
Wire Wire Line
	8850 9350 9050 9350
Connection ~ 8850 9350
Wire Wire Line
	8850 9300 8850 9350
Wire Wire Line
	9050 9350 9250 9350
Connection ~ 9050 9350
Wire Wire Line
	9050 9300 9050 9350
Wire Wire Line
	9250 9350 9450 9350
Connection ~ 9250 9350
Wire Wire Line
	8650 9350 8850 9350
Wire Wire Line
	9250 9300 9250 9350
Wire Wire Line
	9450 9350 9650 9350
Connection ~ 9450 9350
Wire Wire Line
	9450 9300 9450 9350
Wire Wire Line
	9650 9350 9850 9350
Connection ~ 9650 9350
Wire Wire Line
	9650 9300 9650 9350
Wire Wire Line
	9850 9350 10050 9350
Connection ~ 9850 9350
Wire Wire Line
	9850 9300 9850 9350
Wire Wire Line
	10050 9350 10250 9350
Connection ~ 10050 9350
Wire Wire Line
	10050 9300 10050 9350
Wire Wire Line
	10250 9350 10250 9300
Wire Wire Line
	8650 9300 8650 9350
Wire Wire Line
	15200 8850 15200 8800
$Comp
L Device:R R608
U 1 1 5D624628
P 15200 9000
F 0 "R608" H 15270 9046 50  0000 L CNN
F 1 "10k" H 15270 8955 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 15130 9000 50  0001 C CNN
F 3 "~" H 15200 9000 50  0001 C CNN
	1    15200 9000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 1150 8650 1150
Connection ~ 8450 1150
Wire Wire Line
	8450 1200 8450 1150
Wire Wire Line
	8650 1150 8850 1150
Connection ~ 8650 1150
Wire Wire Line
	8650 1200 8650 1150
Wire Wire Line
	8850 1150 9050 1150
Connection ~ 8850 1150
Wire Wire Line
	8850 1200 8850 1150
Wire Wire Line
	9050 1150 9250 1150
Connection ~ 9050 1150
Wire Wire Line
	9050 1200 9050 1150
Wire Wire Line
	9250 1150 9450 1150
Connection ~ 9250 1150
Wire Wire Line
	9250 1200 9250 1150
Wire Wire Line
	9450 1150 9650 1150
Connection ~ 9450 1150
Wire Wire Line
	9450 1200 9450 1150
Wire Wire Line
	9650 1150 9850 1150
Connection ~ 9650 1150
Wire Wire Line
	9650 1200 9650 1150
Wire Wire Line
	9850 1150 10050 1150
Connection ~ 9850 1150
Wire Wire Line
	9850 1200 9850 1150
Wire Wire Line
	10050 1150 10250 1150
Connection ~ 10050 1150
Wire Wire Line
	10050 1200 10050 1150
Wire Wire Line
	10250 1150 10450 1150
Connection ~ 10250 1150
Wire Wire Line
	10250 1200 10250 1150
Wire Wire Line
	10450 1150 10650 1150
Connection ~ 10450 1150
Wire Wire Line
	10450 1150 10450 1200
Wire Wire Line
	10650 1150 10650 1200
Wire Wire Line
	8250 1150 8450 1150
Wire Wire Line
	8250 1200 8250 1150
$Comp
L power:GND #PWR0617
U 1 1 5D9EC6F6
P 2750 8650
F 0 "#PWR0617" H 2750 8400 50  0001 C CNN
F 1 "GND" H 2755 8477 50  0000 C CNN
F 2 "" H 2750 8650 50  0001 C CNN
F 3 "" H 2750 8650 50  0001 C CNN
	1    2750 8650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0625
U 1 1 5D9EDB51
P 950 10050
F 0 "#PWR0625" H 950 9800 50  0001 C CNN
F 1 "GND" H 955 9877 50  0000 C CNN
F 2 "" H 950 10050 50  0001 C CNN
F 3 "" H 950 10050 50  0001 C CNN
	1    950  10050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0621
U 1 1 5DA1A7BE
P 9450 9400
F 0 "#PWR0621" H 9450 9150 50  0001 C CNN
F 1 "GND" H 9455 9227 50  0000 C CNN
F 2 "" H 9450 9400 50  0001 C CNN
F 3 "" H 9450 9400 50  0001 C CNN
	1    9450 9400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0620
U 1 1 5DA1B37D
P 15200 9150
F 0 "#PWR0620" H 15200 8900 50  0001 C CNN
F 1 "GND" H 15205 8977 50  0000 C CNN
F 2 "" H 15200 9150 50  0001 C CNN
F 3 "" H 15200 9150 50  0001 C CNN
	1    15200 9150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0616
U 1 1 5DA1D0A6
P 15200 8550
F 0 "#PWR0616" H 15200 8300 50  0001 C CNN
F 1 "GND" H 15205 8377 50  0000 C CNN
F 2 "" H 15200 8550 50  0001 C CNN
F 3 "" H 15200 8550 50  0001 C CNN
	1    15200 8550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 8200 3750 8200
Wire Wire Line
	2500 8000 3750 8000
$Comp
L power:GND #PWR0630
U 1 1 5D9EF9E4
P 3400 10950
F 0 "#PWR0630" H 3400 10700 50  0001 C CNN
F 1 "GND" H 3405 10777 50  0000 C CNN
F 2 "" H 3400 10950 50  0001 C CNN
F 3 "" H 3400 10950 50  0001 C CNN
	1    3400 10950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0628
U 1 1 5D9EF7B5
P 7500 10900
F 0 "#PWR0628" H 7500 10650 50  0001 C CNN
F 1 "GND" H 7505 10727 50  0000 C CNN
F 2 "" H 7500 10900 50  0001 C CNN
F 3 "" H 7500 10900 50  0001 C CNN
	1    7500 10900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C611
U 1 1 5D68AD99
P 1650 10700
F 0 "C611" H 1765 10746 50  0000 L CNN
F 1 "100n" H 1765 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1688 10550 50  0001 C CNN
F 3 "~" H 1650 10700 50  0001 C CNN
	1    1650 10700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 10400 6600 10450
Wire Wire Line
	3400 10500 3650 10500
Connection ~ 3400 10500
Wire Wire Line
	3400 10450 3400 10500
Wire Wire Line
	1150 10500 1650 10500
Connection ~ 1150 10500
Wire Wire Line
	1150 10550 1150 10500
Wire Wire Line
	1650 10500 2150 10500
Connection ~ 1650 10500
Wire Wire Line
	1650 10550 1650 10500
Wire Wire Line
	2150 10500 2650 10500
Connection ~ 2150 10500
Wire Wire Line
	2150 10550 2150 10500
Wire Wire Line
	2650 10500 3150 10500
Connection ~ 2650 10500
Wire Wire Line
	2650 10550 2650 10500
Wire Wire Line
	3150 10500 3400 10500
Connection ~ 3150 10500
Wire Wire Line
	3150 10550 3150 10500
Wire Wire Line
	3650 10500 4150 10500
Connection ~ 3650 10500
Wire Wire Line
	3650 10550 3650 10500
Wire Wire Line
	4150 10500 4650 10500
Connection ~ 4150 10500
Wire Wire Line
	4150 10550 4150 10500
Wire Wire Line
	4650 10500 5150 10500
Connection ~ 4650 10500
Wire Wire Line
	4650 10550 4650 10500
Wire Wire Line
	5150 10500 5650 10500
Connection ~ 5150 10500
Wire Wire Line
	5150 10550 5150 10500
Wire Wire Line
	5650 10500 6150 10500
Connection ~ 5650 10500
Wire Wire Line
	5650 10550 5650 10500
Wire Wire Line
	6150 10500 6150 10550
Wire Wire Line
	650  10500 1150 10500
Wire Wire Line
	650  10550 650  10500
Wire Wire Line
	3400 10900 3650 10900
Connection ~ 3400 10900
Wire Wire Line
	1150 10900 1650 10900
Connection ~ 1150 10900
Wire Wire Line
	1150 10850 1150 10900
Wire Wire Line
	1650 10900 2150 10900
Connection ~ 1650 10900
Wire Wire Line
	1650 10850 1650 10900
Wire Wire Line
	2150 10900 2650 10900
Connection ~ 2150 10900
Wire Wire Line
	2150 10850 2150 10900
Wire Wire Line
	2650 10900 3150 10900
Connection ~ 2650 10900
Wire Wire Line
	2650 10850 2650 10900
Wire Wire Line
	3150 10900 3400 10900
Connection ~ 3150 10900
Wire Wire Line
	3150 10850 3150 10900
Wire Wire Line
	3650 10900 4150 10900
Connection ~ 3650 10900
Wire Wire Line
	3650 10850 3650 10900
Wire Wire Line
	4150 10900 4650 10900
Connection ~ 4150 10900
Wire Wire Line
	4150 10850 4150 10900
Wire Wire Line
	4650 10900 5150 10900
Connection ~ 4650 10900
Wire Wire Line
	4650 10850 4650 10900
Wire Wire Line
	5150 10900 5650 10900
Connection ~ 5150 10900
Wire Wire Line
	5150 10850 5150 10900
Wire Wire Line
	5650 10900 6150 10900
Connection ~ 5650 10900
Wire Wire Line
	5650 10850 5650 10900
Wire Wire Line
	650  10900 650  10850
Wire Wire Line
	6150 10900 6150 10850
Wire Wire Line
	650  10900 1150 10900
$Comp
L Device:C C620
U 1 1 5D6926A7
P 6150 10700
F 0 "C620" H 6265 10746 50  0000 L CNN
F 1 "100n" H 6265 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 6188 10550 50  0001 C CNN
F 3 "~" H 6150 10700 50  0001 C CNN
	1    6150 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C619
U 1 1 5D6926A1
P 5650 10700
F 0 "C619" H 5765 10746 50  0000 L CNN
F 1 "100n" H 5765 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5688 10550 50  0001 C CNN
F 3 "~" H 5650 10700 50  0001 C CNN
	1    5650 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C618
U 1 1 5D69269B
P 5150 10700
F 0 "C618" H 5265 10746 50  0000 L CNN
F 1 "100n" H 5265 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5188 10550 50  0001 C CNN
F 3 "~" H 5150 10700 50  0001 C CNN
	1    5150 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C617
U 1 1 5D692695
P 4650 10700
F 0 "C617" H 4765 10746 50  0000 L CNN
F 1 "100n" H 4765 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4688 10550 50  0001 C CNN
F 3 "~" H 4650 10700 50  0001 C CNN
	1    4650 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C616
U 1 1 5D68E0E5
P 4150 10700
F 0 "C616" H 4265 10746 50  0000 L CNN
F 1 "100n" H 4265 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4188 10550 50  0001 C CNN
F 3 "~" H 4150 10700 50  0001 C CNN
	1    4150 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C615
U 1 1 5D68E0DF
P 3650 10700
F 0 "C615" H 3765 10746 50  0000 L CNN
F 1 "100n" H 3765 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3688 10550 50  0001 C CNN
F 3 "~" H 3650 10700 50  0001 C CNN
	1    3650 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C614
U 1 1 5D68E0D9
P 3150 10700
F 0 "C614" H 3265 10746 50  0000 L CNN
F 1 "100n" H 3265 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3188 10550 50  0001 C CNN
F 3 "~" H 3150 10700 50  0001 C CNN
	1    3150 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C613
U 1 1 5D68E0D3
P 2650 10700
F 0 "C613" H 2765 10746 50  0000 L CNN
F 1 "100n" H 2765 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2688 10550 50  0001 C CNN
F 3 "~" H 2650 10700 50  0001 C CNN
	1    2650 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C612
U 1 1 5D68AD9F
P 2150 10700
F 0 "C612" H 2265 10746 50  0000 L CNN
F 1 "100n" H 2265 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2188 10550 50  0001 C CNN
F 3 "~" H 2150 10700 50  0001 C CNN
	1    2150 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C610
U 1 1 5D689C5A
P 1150 10700
F 0 "C610" H 1265 10746 50  0000 L CNN
F 1 "100n" H 1265 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1188 10550 50  0001 C CNN
F 3 "~" H 1150 10700 50  0001 C CNN
	1    1150 10700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 10950 3400 10900
Wire Wire Line
	7500 10900 7500 10850
$Comp
L Device:C C609
U 1 1 5D679FDD
P 650 10700
F 0 "C609" H 765 10746 50  0000 L CNN
F 1 "100n" H 765 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 688 10550 50  0001 C CNN
F 3 "~" H 650 10700 50  0001 C CNN
	1    650  10700
	1    0    0    -1  
$EndComp
Connection ~ 7500 10450
Wire Wire Line
	7500 10450 7350 10450
Wire Wire Line
	7500 10550 7500 10450
$Comp
L Device:C C621
U 1 1 5D66AB98
P 7500 10700
F 0 "C621" H 7615 10746 50  0000 L CNN
F 1 "1u" H 7615 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 7538 10550 50  0001 C CNN
F 3 "~" H 7500 10700 50  0001 C CNN
	1    7500 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:Ferrite_Bead FB601
U 1 1 5D66AB8C
P 7200 10450
F 0 "FB601" V 6926 10450 50  0000 C CNN
F 1 "742792031" V 7017 10450 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 7130 10450 50  0001 C CNN
F 3 "~" H 7200 10450 50  0001 C CNN
	1    7200 10450
	0    1    1    0   
$EndComp
Wire Wire Line
	7500 10450 8050 10450
Text Label 8050 10450 2    50   ~ 0
MCU_VDDA
$Comp
L power:GND #PWR0618
U 1 1 5DCA86C4
P 3700 8800
F 0 "#PWR0618" H 3700 8550 50  0001 C CNN
F 1 "GND" V 3705 8672 50  0000 R CNN
F 2 "" H 3700 8800 50  0001 C CNN
F 3 "" H 3700 8800 50  0001 C CNN
	1    3700 8800
	0    1    1    0   
$EndComp
$Comp
L ETH6C20MUX:S25FL064L_SOIC U601
U 1 1 5D7209A3
P 1650 3300
F 0 "U601" H 1650 3865 50  0000 C CNN
F 1 "S25FL064L_SOIC" H 1650 3774 50  0000 C CNN
F 2 "Package_SO:SOIC-8_5.23x5.23mm_P1.27mm" H 1900 3900 50  0001 C CNN
F 3 "" H 1900 3900 50  0001 C CNN
	1    1650 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C603
U 1 1 5D73947C
P 2200 3300
F 0 "C603" H 2315 3346 50  0000 L CNN
F 1 "100n" H 2315 3255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2238 3150 50  0001 C CNN
F 3 "~" H 2200 3300 50  0001 C CNN
	1    2200 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 3600 2200 3450
Wire Wire Line
	2200 3150 2200 3000
Wire Wire Line
	2200 3000 2200 2900
Connection ~ 2200 3000
$Comp
L power:GND #PWR0606
U 1 1 5D766B37
P 2200 3700
F 0 "#PWR0606" H 2200 3450 50  0001 C CNN
F 1 "GND" H 2205 3527 50  0000 C CNN
F 2 "" H 2200 3700 50  0001 C CNN
F 3 "" H 2200 3700 50  0001 C CNN
	1    2200 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 3600 2200 3600
Wire Wire Line
	2050 3000 2200 3000
Wire Wire Line
	2200 3600 2200 3700
Connection ~ 2200 3600
Wire Wire Line
	1250 3400 1200 3400
Wire Wire Line
	1200 3400 1200 3600
Wire Wire Line
	1200 3600 1250 3600
Wire Wire Line
	1150 3600 1200 3600
Connection ~ 1200 3600
Text Label 550  3500 0    50   ~ 0
MCU_FLASH1_CS
Wire Wire Line
	550  3500 1250 3500
Text Label 600  3000 0    50   ~ 0
MCU_SPI3_MISO
Text Label 600  3100 0    50   ~ 0
MCU_SPI3_MOSI
Text Label 600  3200 0    50   ~ 0
MCU_SPI3_SCLK
Wire Wire Line
	1250 3200 600  3200
Wire Wire Line
	1250 3100 600  3100
Wire Wire Line
	1250 3000 1200 3000
$Comp
L ETH6C20MUX:S25FL064L_SOIC U602
U 1 1 5D7E3373
P 1650 4650
F 0 "U602" H 1650 5215 50  0000 C CNN
F 1 "S25FL064L_SOIC" H 1650 5124 50  0000 C CNN
F 2 "Package_SO:SOIC-8_5.23x5.23mm_P1.27mm" H 1900 5250 50  0001 C CNN
F 3 "" H 1900 5250 50  0001 C CNN
	1    1650 4650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C604
U 1 1 5D7E3379
P 2200 4650
F 0 "C604" H 2315 4696 50  0000 L CNN
F 1 "100n" H 2315 4605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2238 4500 50  0001 C CNN
F 3 "~" H 2200 4650 50  0001 C CNN
	1    2200 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 4950 2200 4800
Wire Wire Line
	2200 4500 2200 4350
Wire Wire Line
	2200 4350 2200 4250
Connection ~ 2200 4350
$Comp
L power:GND #PWR0609
U 1 1 5D7E3389
P 2200 5050
F 0 "#PWR0609" H 2200 4800 50  0001 C CNN
F 1 "GND" H 2205 4877 50  0000 C CNN
F 2 "" H 2200 5050 50  0001 C CNN
F 3 "" H 2200 5050 50  0001 C CNN
	1    2200 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 4950 2200 4950
Wire Wire Line
	2050 4350 2200 4350
Wire Wire Line
	2200 4950 2200 5050
Connection ~ 2200 4950
Wire Wire Line
	1250 4750 1200 4750
Wire Wire Line
	1200 4750 1200 4950
Wire Wire Line
	1200 4950 1250 4950
Wire Wire Line
	1150 4950 1200 4950
Connection ~ 1200 4950
Text Label 550  4850 0    50   ~ 0
MCU_FLASH2_CS
Wire Wire Line
	550  4850 1250 4850
Text Label 600  4350 0    50   ~ 0
MCU_SPI3_MISO
Text Label 600  4450 0    50   ~ 0
MCU_SPI3_MOSI
Text Label 600  4550 0    50   ~ 0
MCU_SPI3_SCLK
Wire Wire Line
	1250 4550 600  4550
Wire Wire Line
	1250 4450 600  4450
Wire Wire Line
	1250 4350 600  4350
Wire Wire Line
	15150 8200 15200 8200
Wire Wire Line
	15200 8250 15200 8200
Connection ~ 15200 8200
Wire Wire Line
	15200 8200 15600 8200
Wire Wire Line
	15200 8200 15200 8150
Wire Wire Line
	15200 8800 15150 8800
Wire Wire Line
	3750 3200 3150 3200
Text Label 3150 3200 0    50   ~ 0
MCU_FLASH2_CS
$Comp
L Device:R R601
U 1 1 5D958208
P 1200 2650
F 0 "R601" H 1270 2696 50  0000 L CNN
F 1 "10k" H 1270 2605 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1130 2650 50  0001 C CNN
F 3 "~" H 1200 2650 50  0001 C CNN
	1    1200 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 2800 1200 3000
Connection ~ 1200 3000
Wire Wire Line
	1200 3000 600  3000
Wire Wire Line
	3750 2500 3650 2500
Wire Wire Line
	3750 2600 3650 2600
Wire Wire Line
	3750 2700 3650 2700
Wire Wire Line
	15150 4500 15250 4500
Wire Wire Line
	15150 4600 15250 4600
Wire Wire Line
	15150 4200 15250 4200
Text HLabel 15200 6800 2    50   Output ~ 0
MODULE_DETECT0
Wire Wire Line
	15200 6700 15150 6700
$Comp
L Connector_Generic:Conn_02x01 J602
U 1 1 5E46D79D
P 8500 10600
F 0 "J602" V 8504 10680 50  0000 L CNN
F 1 "Conn_02x01" V 8595 10680 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 8500 10600 50  0001 C CNN
F 3 "~" H 8500 10600 50  0001 C CNN
	1    8500 10600
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0629
U 1 1 5E46DCED
P 8500 10900
F 0 "#PWR0629" H 8500 10650 50  0001 C CNN
F 1 "GND" H 8505 10727 50  0000 C CNN
F 2 "" H 8500 10900 50  0001 C CNN
F 3 "" H 8500 10900 50  0001 C CNN
	1    8500 10900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R609
U 1 1 5E46DFC0
P 8500 10150
F 0 "R609" H 8570 10196 50  0000 L CNN
F 1 "10k" H 8570 10105 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8430 10150 50  0001 C CNN
F 3 "~" H 8500 10150 50  0001 C CNN
	1    8500 10150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 9950 8500 10000
Wire Wire Line
	8500 10300 8500 10350
Text Label 9100 10350 2    50   ~ 0
MCU_DEFAULT
Wire Wire Line
	8500 10350 9100 10350
Connection ~ 8500 10350
Wire Wire Line
	8500 10350 8500 10400
Text Label 15750 6900 2    50   ~ 0
MCU_DEFAULT
Wire Wire Line
	15150 6900 15750 6900
NoConn ~ 3750 3500
NoConn ~ 3750 3900
NoConn ~ 3750 4000
NoConn ~ 3750 4100
NoConn ~ 3750 4300
NoConn ~ 3750 5200
NoConn ~ 3750 5400
NoConn ~ 3750 5500
NoConn ~ 3750 6900
NoConn ~ 3750 7000
NoConn ~ 3750 7200
NoConn ~ 3750 7500
$Comp
L power:+3.3V #PWR0603
U 1 1 5DAAE78E
P 1200 2500
F 0 "#PWR0603" H 1200 2350 50  0001 C CNN
F 1 "+3.3V" H 1215 2673 50  0000 C CNN
F 2 "" H 1200 2500 50  0001 C CNN
F 3 "" H 1200 2500 50  0001 C CNN
	1    1200 2500
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0604
U 1 1 5DAAEC46
P 2200 2900
F 0 "#PWR0604" H 2200 2750 50  0001 C CNN
F 1 "+3.3V" H 2215 3073 50  0000 C CNN
F 2 "" H 2200 2900 50  0001 C CNN
F 3 "" H 2200 2900 50  0001 C CNN
	1    2200 2900
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0605
U 1 1 5DAAF061
P 1150 3600
F 0 "#PWR0605" H 1150 3450 50  0001 C CNN
F 1 "+3.3V" V 1150 3750 50  0000 L CNN
F 2 "" H 1150 3600 50  0001 C CNN
F 3 "" H 1150 3600 50  0001 C CNN
	1    1150 3600
	0    -1   -1   0   
$EndComp
$Comp
L power:+3.3V #PWR0607
U 1 1 5DAB05B2
P 2200 4250
F 0 "#PWR0607" H 2200 4100 50  0001 C CNN
F 1 "+3.3V" H 2215 4423 50  0000 C CNN
F 2 "" H 2200 4250 50  0001 C CNN
F 3 "" H 2200 4250 50  0001 C CNN
	1    2200 4250
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0608
U 1 1 5DAB0A7D
P 1150 4950
F 0 "#PWR0608" H 1150 4800 50  0001 C CNN
F 1 "+3.3V" V 1150 5100 50  0000 L CNN
F 2 "" H 1150 4950 50  0001 C CNN
F 3 "" H 1150 4950 50  0001 C CNN
	1    1150 4950
	0    -1   -1   0   
$EndComp
$Comp
L power:+3.3V #PWR0619
U 1 1 5DAB2C75
P 3600 9000
F 0 "#PWR0619" H 3600 8850 50  0001 C CNN
F 1 "+3.3V" V 3615 9128 50  0000 L CNN
F 2 "" H 3600 9000 50  0001 C CNN
F 3 "" H 3600 9000 50  0001 C CNN
	1    3600 9000
	0    -1   -1   0   
$EndComp
$Comp
L power:+3.3V #PWR0623
U 1 1 5DAB40B8
P 950 9500
F 0 "#PWR0623" H 950 9350 50  0001 C CNN
F 1 "+3.3V" H 965 9673 50  0000 C CNN
F 2 "" H 950 9500 50  0001 C CNN
F 3 "" H 950 9500 50  0001 C CNN
	1    950  9500
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0627
U 1 1 5DAB6A09
P 3400 10450
F 0 "#PWR0627" H 3400 10300 50  0001 C CNN
F 1 "+3.3V" H 3415 10623 50  0000 C CNN
F 2 "" H 3400 10450 50  0001 C CNN
F 3 "" H 3400 10450 50  0001 C CNN
	1    3400 10450
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0626
U 1 1 5DABB276
P 6600 10400
F 0 "#PWR0626" H 6600 10250 50  0001 C CNN
F 1 "+3.3V" H 6615 10573 50  0000 C CNN
F 2 "" H 6600 10400 50  0001 C CNN
F 3 "" H 6600 10400 50  0001 C CNN
	1    6600 10400
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0624
U 1 1 5DABC0E7
P 8500 9950
F 0 "#PWR0624" H 8500 9800 50  0001 C CNN
F 1 "+3.3V" H 8515 10123 50  0000 C CNN
F 2 "" H 8500 9950 50  0001 C CNN
F 3 "" H 8500 9950 50  0001 C CNN
	1    8500 9950
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0615
U 1 1 5DABE118
P 15200 7850
F 0 "#PWR0615" H 15200 7700 50  0001 C CNN
F 1 "+3.3V" H 15215 8023 50  0000 C CNN
F 2 "" H 15200 7850 50  0001 C CNN
F 3 "" H 15200 7850 50  0001 C CNN
	1    15200 7850
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0601
U 1 1 5DAC12EB
P 9450 1100
F 0 "#PWR0601" H 9450 950 50  0001 C CNN
F 1 "+3.3V" H 9465 1273 50  0000 C CNN
F 2 "" H 9450 1100 50  0001 C CNN
F 3 "" H 9450 1100 50  0001 C CNN
	1    9450 1100
	1    0    0    -1  
$EndComp
NoConn ~ 15150 1700
NoConn ~ 15150 1800
NoConn ~ 15150 1900
NoConn ~ 15150 2000
NoConn ~ 15150 2100
NoConn ~ 15150 2200
NoConn ~ 15150 2300
NoConn ~ 15150 2500
NoConn ~ 15150 2600
NoConn ~ 15150 2700
NoConn ~ 15150 2800
NoConn ~ 15150 2900
NoConn ~ 15150 3000
NoConn ~ 15150 3100
NoConn ~ 15150 3200
NoConn ~ 15150 3300
NoConn ~ 15150 3400
NoConn ~ 15150 3500
NoConn ~ 15150 3600
NoConn ~ 15150 3700
NoConn ~ 15150 3800
NoConn ~ 15150 3900
NoConn ~ 15150 4000
NoConn ~ 15150 4900
NoConn ~ 15150 5900
NoConn ~ 15150 6300
NoConn ~ 15150 6400
NoConn ~ 15150 7000
NoConn ~ 15150 7100
NoConn ~ 15150 7200
NoConn ~ 15150 7400
Connection ~ 2750 8600
Wire Wire Line
	2750 8600 2950 8600
Wire Wire Line
	2500 8600 2750 8600
Text HLabel 3650 2500 0    50   Output ~ 0
RELAY1_SCLK
Text HLabel 3650 2700 0    50   Output ~ 0
RELAY1_SI
Text HLabel 3650 2600 0    50   Input ~ 0
RELAY1_SO
Text HLabel 15250 5700 2    50   Input ~ 0
RELAY1_~RST
Wire Wire Line
	15150 5700 15250 5700
Text HLabel 15250 1500 2    50   Output ~ 0
RELAY1_~CS3
Text HLabel 15250 1600 2    50   Output ~ 0
RELAY1_~CS2
Text HLabel 15250 4700 2    50   Output ~ 0
RELAY1_~CS1
Text HLabel 15250 4800 2    50   Output ~ 0
RELAY1_~CS0
NoConn ~ 3750 2000
NoConn ~ 3750 2100
NoConn ~ 3750 2200
Wire Wire Line
	15250 4800 15150 4800
Wire Wire Line
	15250 1500 15150 1500
Wire Wire Line
	15150 1600 15250 1600
Wire Wire Line
	15250 4700 15150 4700
NoConn ~ 3750 2400
Text HLabel 15250 4200 2    50   Output ~ 0
RELAY2_SCLK
Text HLabel 15250 4600 2    50   Output ~ 0
RELAY2_SI
Text HLabel 15250 4500 2    50   Input ~ 0
RELAY2_SO
Text HLabel 15250 5000 2    50   Input ~ 0
RELAY2_~RST
Text HLabel 15200 5400 2    50   Output ~ 0
RELAY2_~CS3
Text HLabel 15200 5300 2    50   Output ~ 0
RELAY2_~CS2
Text HLabel 15200 5200 2    50   Output ~ 0
RELAY2_~CS1
Text HLabel 15200 5100 2    50   Output ~ 0
RELAY2_~CS0
Wire Wire Line
	15150 5000 15250 5000
NoConn ~ 15150 4400
Wire Wire Line
	15200 5300 15150 5300
Wire Wire Line
	15150 5200 15200 5200
Wire Wire Line
	15200 5100 15150 5100
Wire Wire Line
	15200 5400 15150 5400
NoConn ~ 15150 6100
NoConn ~ 15150 6200
NoConn ~ 15150 6500
NoConn ~ 15150 6600
NoConn ~ 3750 5800
NoConn ~ 3750 5900
Wire Wire Line
	15150 6800 15200 6800
Text HLabel 15200 6700 2    50   Output ~ 0
MODULE_DETECT1
$Comp
L Device:C C608
U 1 1 5D8AB31E
P 3700 9250
F 0 "C608" H 3815 9296 50  0000 L CNN
F 1 "1u" H 3815 9205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3738 9100 50  0001 C CNN
F 3 "~" H 3700 9250 50  0001 C CNN
	1    3700 9250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 9100 3700 9000
Connection ~ 3700 9000
Wire Wire Line
	3700 9000 3750 9000
$Comp
L power:GND #PWR0622
U 1 1 5D8DB37C
P 3700 9450
F 0 "#PWR0622" H 3700 9200 50  0001 C CNN
F 1 "GND" H 3705 9277 50  0000 C CNN
F 2 "" H 3700 9450 50  0001 C CNN
F 3 "" H 3700 9450 50  0001 C CNN
	1    3700 9450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 9450 3700 9400
Text Label 3350 8600 0    50   ~ 0
MCU_VDDA
Wire Wire Line
	6600 10450 7050 10450
NoConn ~ 3750 4700
Text HLabel 3700 3700 0    50   BiDi ~ 0
RMII_MDIO
NoConn ~ 3750 3800
Text HLabel 3700 7400 0    50   BiDi ~ 0
RMII_TX1
Wire Wire Line
	3600 9000 3700 9000
$Comp
L Device:Crystal Y601
U 1 1 5DBB3F9E
P 2300 1550
F 0 "Y601" V 2254 1681 50  0000 L CNN
F 1 "NX3225GD-8MHZ-STD-CRA-3" V 2345 1681 50  0000 L CNN
F 2 "ETH6C16MXU:NX3225GD" H 2300 1550 50  0001 C CNN
F 3 "~" H 2300 1550 50  0001 C CNN
	1    2300 1550
	0    1    1    0   
$EndComp
Wire Wire Line
	3750 1600 3650 1600
Wire Wire Line
	3650 1600 3650 1700
Wire Wire Line
	3650 1700 2300 1700
Wire Wire Line
	3750 1500 3650 1500
Wire Wire Line
	3650 1500 3650 1400
Wire Wire Line
	3650 1400 2300 1400
$Comp
L Device:C C602
U 1 1 5DBEE1A1
P 2300 1900
F 0 "C602" H 2415 1946 50  0000 L CNN
F 1 "8p" H 2415 1855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2338 1750 50  0001 C CNN
F 3 "~" H 2300 1900 50  0001 C CNN
	1    2300 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C601
U 1 1 5DBFF216
P 1800 1900
F 0 "C601" H 1915 1946 50  0000 L CNN
F 1 "8p" H 1915 1855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1838 1750 50  0001 C CNN
F 3 "~" H 1800 1900 50  0001 C CNN
	1    1800 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 1750 1800 1400
Wire Wire Line
	1800 2050 1800 2100
Wire Wire Line
	1800 2100 2050 2100
$Comp
L power:GND #PWR0602
U 1 1 5DC25829
P 2050 2150
F 0 "#PWR0602" H 2050 1900 50  0001 C CNN
F 1 "GND" H 2055 1977 50  0000 C CNN
F 2 "" H 2050 2150 50  0001 C CNN
F 3 "" H 2050 2150 50  0001 C CNN
	1    2050 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 2150 2050 2100
Connection ~ 2050 2100
Wire Wire Line
	2050 2100 2300 2100
Wire Wire Line
	2300 2100 2300 2050
Wire Wire Line
	2300 1750 2300 1700
Connection ~ 2300 1700
Wire Wire Line
	1800 1400 2300 1400
Connection ~ 2300 1400
NoConn ~ 3750 4400
NoConn ~ 3750 4500
NoConn ~ 3750 4600
Text HLabel 3650 3300 0    50   Output ~ 0
RELAY1_~CS4
Wire Wire Line
	3650 3300 3750 3300
Text HLabel 15200 5500 2    50   Output ~ 0
RELAY2_~CS4
Wire Wire Line
	15200 5500 15150 5500
NoConn ~ 3750 1800
NoConn ~ 3750 1900
NoConn ~ 3750 6500
NoConn ~ 3750 6600
NoConn ~ 3750 6700
NoConn ~ 15150 5800
NoConn ~ 15150 7500
NoConn ~ 3750 2800
NoConn ~ 3750 2900
NoConn ~ 3750 3000
$Comp
L ETH6C20MUX:STM32F765ZGT6 U603
U 1 1 5D61C76C
P 9450 5250
F 0 "U603" H 4100 9150 50  0000 C CNN
F 1 "STM32F765ZGT6" H 14650 9150 50  0000 C CNN
F 2 "ETH6C16MXU:TQFP-144_20x20mm_P0.5mm" H 25350 6750 50  0001 C CNN
F 3 "" H 25350 6750 50  0001 C CNN
	1    9450 5250
	1    0    0    -1  
$EndComp
NoConn ~ 3750 2300
NoConn ~ 3750 6000
NoConn ~ 3750 6100
$EndSCHEMATC
