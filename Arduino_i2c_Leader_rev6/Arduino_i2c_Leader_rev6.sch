EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Arduino i2c leader lights-out"
Date ""
Rev "6"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:R R2
U 1 1 5E7D1105
P 8890 5660
F 0 "R2" H 8960 5706 50  0000 L CNN
F 1 "100K" H 8960 5615 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8820 5660 50  0001 C CNN
F 3 "~" H 8890 5660 50  0001 C CNN
	1    8890 5660
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0105
U 1 1 5E7D1118
P 8890 5810
F 0 "#PWR0105" H 8890 5560 50  0001 C CNN
F 1 "GNDD" H 8894 5655 50  0000 C CNN
F 2 "" H 8890 5810 50  0001 C CNN
F 3 "" H 8890 5810 50  0001 C CNN
	1    8890 5810
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0106
U 1 1 5E7D111E
P 9189 5709
F 0 "#PWR0106" H 9189 5459 50  0001 C CNN
F 1 "GNDD" H 9193 5554 50  0000 C CNN
F 2 "" H 9189 5709 50  0001 C CNN
F 3 "" H 9189 5709 50  0001 C CNN
	1    9189 5709
	1    0    0    -1  
$EndComp
Wire Wire Line
	9190 5304 9190 5308
$Comp
L Transistor_BJT:BC108 Q1
U 1 1 5E7D112D
P 9089 5509
F 0 "Q1" H 9280 5555 50  0000 L CNN
F 1 "BC108" H 9280 5464 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-11-3" H 9289 5434 50  0001 L CIN
F 3 "http://www.b-kainka.de/Daten/Transistor/BC108.pdf" H 9089 5509 50  0001 L CNN
	1    9089 5509
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5E110A22
P 8751 4681
F 0 "R3" V 8544 4681 50  0000 C CNN
F 1 "10K" V 8635 4681 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8681 4681 50  0001 C CNN
F 3 "~" H 8751 4681 50  0001 C CNN
	1    8751 4681
	0    1    1    0   
$EndComp
Wire Wire Line
	9202 4475 9202 4479
$Comp
L power:GNDD #PWR0102
U 1 1 5E7C6912
P 9201 4880
F 0 "#PWR0102" H 9201 4630 50  0001 C CNN
F 1 "GNDD" H 9205 4725 50  0000 C CNN
F 2 "" H 9201 4880 50  0001 C CNN
F 3 "" H 9201 4880 50  0001 C CNN
	1    9201 4880
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5E10F07F
P 8922 4833
F 0 "R4" H 8992 4879 50  0000 L CNN
F 1 "100K" H 8992 4788 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8852 4833 50  0001 C CNN
F 3 "~" H 8922 4833 50  0001 C CNN
	1    8922 4833
	1    0    0    -1  
$EndComp
Wire Wire Line
	8601 4681 8602 4681
$Comp
L Device:R R8
U 1 1 5E7C97E8
P 4540 3267
F 0 "R8" H 4610 3313 50  0000 L CNN
F 1 "100K" H 4610 3222 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 4470 3267 50  0001 C CNN
F 3 "~" H 4540 3267 50  0001 C CNN
	1    4540 3267
	1    0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 5E7CC3B9
P 4139 3268
F 0 "R7" H 4209 3314 50  0000 L CNN
F 1 "100K" H 4209 3223 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 4069 3268 50  0001 C CNN
F 3 "~" H 4139 3268 50  0001 C CNN
	1    4139 3268
	1    0    0    -1  
$EndComp
Wire Wire Line
	4539 3115 4539 2881
$Comp
L Transistor_FET:BSS138 Q4
U 1 1 5E7DCD22
P 4349 4050
F 0 "Q4" V 4598 4050 50  0000 C CNN
F 1 "BSS138" V 4689 4050 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 4549 3975 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/BS/BSS138.pdf" H 4349 4050 50  0001 L CNN
	1    4349 4050
	0    -1   1    0   
$EndComp
$Comp
L Device:R R5
U 1 1 5E7DCD2E
P 4149 4000
F 0 "R5" H 4219 4046 50  0000 L CNN
F 1 "100K" H 4219 3955 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 4079 4000 50  0001 C CNN
F 3 "~" H 4149 4000 50  0001 C CNN
	1    4149 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4549 3847 4549 3613
Wire Wire Line
	4548 3618 4820 3618
Wire Wire Line
	4820 3618 4820 2880
Wire Wire Line
	4820 2880 4818 2880
Wire Wire Line
	4548 4150 4549 4150
Connection ~ 4549 4150
Wire Wire Line
	4538 3417 4540 3417
Connection ~ 4540 3417
Text Label 5012 3415 0    50   ~ 0
HV2
Wire Wire Line
	4149 3848 4348 3848
Wire Wire Line
	4348 3848 4348 3849
Wire Wire Line
	4135 2781 4135 3114
Text GLabel 3530 3409 2    50   Input ~ 0
SDA
Text GLabel 3525 4153 2    50   Input ~ 0
SCL
Wire Wire Line
	3719 3415 3719 3414
Wire Wire Line
	3711 4151 3711 4150
$Comp
L Transistor_FET:BSS138 Q3
U 1 1 5E7C25BD
P 4339 3318
F 0 "Q3" V 4588 3318 50  0000 C CNN
F 1 "BSS138" V 4679 3318 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 4539 3243 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/BS/BSS138.pdf" H 4339 3318 50  0001 L CNN
	1    4339 3318
	0    -1   1    0   
$EndComp
Text GLabel 3530 2982 2    50   Input ~ 0
GND
Wire Wire Line
	4135 3116 4340 3116
Wire Wire Line
	3709 4151 3711 4151
Wire Wire Line
	4151 4151 4151 4150
Connection ~ 3711 4151
Wire Wire Line
	3711 4151 4151 4151
Wire Wire Line
	4136 3416 3718 3416
Wire Wire Line
	3728 2981 3728 2983
$Comp
L Device:R R6
U 1 1 5E7DCD28
P 4550 3999
F 0 "R6" H 4620 4045 50  0000 L CNN
F 1 "100K" H 4620 3954 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 4480 3999 50  0001 C CNN
F 3 "~" H 4550 3999 50  0001 C CNN
	1    4550 3999
	1    0    0    -1  
$EndComp
Text Label 5006 2776 0    50   ~ 0
LV
Text Label 5005 2876 0    50   ~ 0
HV
Text Label 5002 2982 0    50   ~ 0
GND
Wire Notes Line
	3932 4433 3932 2688
Wire Wire Line
	4132 2783 4027 2783
Wire Wire Line
	4027 2783 4027 3853
Wire Wire Line
	4027 3853 4142 3853
Wire Wire Line
	4142 3853 4142 3848
Text Label 3767 2983 0    50   ~ 0
GND
Text Label 3772 3408 0    50   ~ 0
LV2
Text Label 3747 4143 0    50   ~ 0
LV1
Wire Notes Line
	3932 2683 4977 2683
Wire Notes Line
	4977 2683 4977 4428
Wire Notes Line
	4977 4428 3927 4428
Text Label 5018 4152 0    50   ~ 0
HV1
Text Notes 4057 2658 0    50   ~ 0
Logic Level Converter
$Comp
L Freetronics:BUZZER U1
U 1 1 5E809B5F
P 6045 5120
F 0 "U1" H 5840 5039 70  0000 R CNN
F 1 "BUZZER" H 5840 5160 70  0000 R CNN
F 2 "Buzzer_Beeper:Buzzer_D14mm_H7mm_P10mm" H 5840 5221 60  0001 R CNN
F 3 "" H 5995 5070 60  0001 C CNN
	1    6045 5120
	-1   0    0    1   
$EndComp
$Comp
L power:GNDD #PWR0101
U 1 1 5E7C5455
P 8922 4981
F 0 "#PWR0101" H 8922 4731 50  0001 C CNN
F 1 "GNDD" H 8926 4826 50  0000 C CNN
F 2 "" H 8922 4981 50  0001 C CNN
F 3 "" H 8922 4981 50  0001 C CNN
	1    8922 4981
	1    0    0    -1  
$EndComp
Text Label 9365 5304 0    50   ~ 0
RESET1
Text Label 9387 4475 0    50   ~ 0
RESET2
Text Notes 7285 7240 0    50   ~ 0
1
Text Notes 7385 7240 0    50   ~ 0
1
Text Notes 8115 7640 0    50   ~ 0
03/07/2020
$Comp
L Connector:Raspberry_Pi_2_3 J3
U 1 1 5E780FD6
P 1987 3603
F 0 "J3" H 1987 5084 50  0000 C CNN
F 1 "Raspberry_Pi_2_3" H 1987 4993 50  0000 C CNN
F 2 "" H 1987 3603 50  0001 C CNN
F 3 "https://www.raspberrypi.org/documentation/hardware/raspberrypi/schematics/rpi_SCH_3bplus_1p0_reduced.pdf" H 1987 3603 50  0001 C CNN
	1    1987 3603
	1    0    0    -1  
$EndComp
Wire Wire Line
	3527 2983 3192 2983
Wire Wire Line
	3192 2983 3192 5118
Wire Wire Line
	3192 5118 1787 5118
Wire Wire Line
	1787 5118 1787 4903
Connection ~ 1787 4903
Wire Wire Line
	1787 4903 1787 4898
Wire Wire Line
	1187 3403 997  3403
Wire Wire Line
	997  3403 997  5248
Wire Wire Line
	997  5248 3057 5248
Wire Wire Line
	3057 5248 3057 4153
Wire Wire Line
	3057 4153 3522 4153
Wire Wire Line
	5756 3153 5675 3153
Wire Wire Line
	5756 3253 5599 3253
Wire Wire Line
	5599 3253 5599 2881
Wire Wire Line
	4539 2881 5599 2881
Wire Wire Line
	5757 3353 5517 3353
Wire Wire Line
	5517 3353 5517 2981
Wire Wire Line
	3728 2981 5517 2981
Wire Wire Line
	5227 4150 5227 4253
Wire Wire Line
	4549 4150 5227 4150
Wire Wire Line
	5290 3417 5290 4153
Wire Wire Line
	5290 4153 5757 4153
Wire Wire Line
	4540 3417 5290 3417
Wire Wire Line
	4135 2781 5675 2781
Text Notes 8634 2339 0    50   ~ 0
WIZ550io\n
Wire Notes Line
	9224 2359 8399 2359
Wire Notes Line
	9224 3224 9224 2359
Wire Notes Line
	8399 3224 9224 3224
Wire Notes Line
	8399 2359 8399 3224
Wire Wire Line
	8134 2949 8134 3154
$Comp
L Freetronics:M08 J1
U 1 1 5E7A0B78
P 8674 2450
F 0 "J1" H 8491 1529 50  0000 C CNN
F 1 "M08" H 8491 1613 40  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 8674 2450 60  0001 C CNN
F 3 "" H 8674 2450 60  0001 C CNN
	1    8674 2450
	1    0    0    -1  
$EndComp
Connection ~ 8374 2750
Wire Wire Line
	8374 2750 8374 2749
Wire Wire Line
	8374 2759 8374 2750
Connection ~ 8374 2850
Wire Wire Line
	8374 2850 8374 2844
Wire Wire Line
	8374 2854 8374 2850
Wire Wire Line
	9254 2859 9523 2859
Text Label 9264 2854 0    50   ~ 0
INTn
Text Label 9279 2559 0    50   ~ 0
RDY
Wire Wire Line
	9449 2559 9254 2559
Text Label 8189 2444 0    50   ~ 0
GND
Wire Wire Line
	8374 2449 7944 2449
Wire Wire Line
	8374 2949 8134 2949
Wire Wire Line
	7654 3154 8134 3154
Wire Wire Line
	8044 2654 8374 2654
Connection ~ 8044 2654
Wire Wire Line
	8044 3054 8044 2654
Wire Wire Line
	7654 3054 8044 3054
Text Label 8154 2949 0    50   ~ 0
SCSn
Text Label 8159 2654 0    50   ~ 0
MOSI
Wire Wire Line
	8039 2654 8044 2654
Wire Wire Line
	7654 2854 8374 2854
Wire Wire Line
	8099 2759 8374 2759
Wire Wire Line
	8099 2954 8099 2759
Wire Wire Line
	7654 2954 8099 2954
Text Label 8164 2759 0    50   ~ 0
MISO
Text Label 8154 2859 0    50   ~ 0
SCLK
$Comp
L Freetronics:M06 J2
U 1 1 5E7A2A00
P 8956 2457
F 0 "J2" H 8773 1736 50  0000 C CNN
F 1 "M06" H 8773 1820 40  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 8956 2457 60  0001 C CNN
F 3 "" H 8956 2457 60  0001 C CNN
	1    8956 2457
	-1   0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0104
U 1 1 5E7CB1BD
P 7947 3285
F 0 "#PWR0104" H 7947 3035 50  0001 C CNN
F 1 "GNDD" H 7951 3130 50  0000 C CNN
F 2 "" H 7947 3285 50  0001 C CNN
F 3 "" H 7947 3285 50  0001 C CNN
	1    7947 3285
	1    0    0    -1  
$EndComp
Wire Wire Line
	7944 2449 7944 3289
Wire Wire Line
	5757 3453 5525 3453
Wire Wire Line
	5525 3453 5525 4970
Wire Wire Line
	5525 4970 5995 4970
Wire Wire Line
	5227 4253 5759 4253
Wire Wire Line
	7656 2753 7945 2753
$Comp
L Freetronics:ARDUINO_SHIELD SHIELD1
U 1 1 5E7C4BBF
P 6709 3452
F 0 "SHIELD1" H 6709 5199 60  0000 C CNN
F 1 "ARDUINO_SHIELD" H 6709 5093 60  0000 C CNN
F 2 "FT:ARDUINO_SHIELD" H 6709 3252 50  0001 C CNN
F 3 "http://www.thingiverse.com/thing:9630" H 6709 5093 60  0001 C CNN
	1    6709 3452
	1    0    0    -1  
$EndComp
Wire Wire Line
	8373 3150 8191 3150
Wire Wire Line
	8191 3150 8191 4493
Wire Wire Line
	8191 4493 5675 4493
Wire Wire Line
	5675 2781 5675 3153
Connection ~ 5675 3153
Wire Wire Line
	5675 3153 5675 4493
Text Label 8213 3143 0    50   ~ 0
3V3
Wire Wire Line
	9449 2559 9449 3551
Wire Wire Line
	9449 3551 7658 3551
Wire Wire Line
	7659 4052 9523 4052
Wire Wire Line
	9523 4052 9523 2859
Connection ~ 9523 2859
Wire Wire Line
	9523 2859 9524 2859
Wire Wire Line
	7658 3652 7659 3652
Wire Wire Line
	8601 3652 8601 4681
Connection ~ 7659 3652
Wire Wire Line
	7659 3652 8601 3652
Connection ~ 8601 4681
Wire Wire Line
	7658 3752 7659 3752
Connection ~ 7659 3752
Wire Wire Line
	7659 3752 8489 3752
$Comp
L Device:R R1
U 1 1 5E7D110B
P 8739 5509
F 0 "R1" V 8532 5509 50  0000 C CNN
F 1 "10K" V 8623 5509 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8669 5509 50  0001 C CNN
F 3 "~" H 8739 5509 50  0001 C CNN
	1    8739 5509
	0    1    1    0   
$EndComp
Wire Wire Line
	8588 5509 8489 5509
Wire Wire Line
	8489 5509 8489 3752
Wire Wire Line
	7659 3952 7865 3952
Wire Wire Line
	7865 3952 7865 4970
Wire Wire Line
	7865 4970 6095 4970
$Comp
L power:GNDD #PWR0103
U 1 1 5E7C7C85
P 10076 5005
F 0 "#PWR0103" H 10076 4755 50  0001 C CNN
F 1 "GNDD" H 10080 4850 50  0000 C CNN
F 2 "" H 10076 5005 50  0001 C CNN
F 3 "" H 10076 5005 50  0001 C CNN
	1    10076 5005
	1    0    0    -1  
$EndComp
Wire Wire Line
	10075 4805 10019 4805
Wire Wire Line
	10019 4805 10019 5006
Wire Wire Line
	10019 5006 10074 5006
Wire Wire Line
	10074 5006 10074 5007
Wire Wire Line
	9202 4475 10575 4475
Wire Wire Line
	9190 5304 10575 5304
$Comp
L Transistor_BJT:BC108 Q2
U 1 1 5E10E79C
P 9101 4681
F 0 "Q2" H 9292 4727 50  0000 L CNN
F 1 "BC108" H 9292 4636 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-11-3" H 9301 4606 50  0001 L CIN
F 3 "http://www.b-kainka.de/Daten/Transistor/BC108.pdf" H 9101 4681 50  0001 L CNN
	1    9101 4681
	1    0    0    -1  
$EndComp
Wire Wire Line
	10575 4475 10575 4805
Wire Wire Line
	10575 5304 10575 5005
$Comp
L Freetronics:M02X03 JP1
U 1 1 5E9A35C1
P 10375 4805
F 0 "JP1" H 10325 5005 50  0000 C CNN
F 1 "M02X03" H 10325 4921 40  0000 C CNN
F 2 "" H 10375 4805 60  0000 C CNN
F 3 "" H 10375 4805 60  0000 C CNN
	1    10375 4805
	1    0    0    -1  
$EndComp
Wire Wire Line
	3529 3408 2931 3408
Wire Wire Line
	2931 5362 938  5362
Wire Wire Line
	938  5362 938  3203
Wire Wire Line
	938  3203 1187 3203
Connection ~ 1187 3203
Wire Wire Line
	1187 3203 1188 3203
Wire Wire Line
	2931 3408 2931 5362
Text Notes 6997 6646 0    50   ~ 0
Arduino I2C leader with WIZ550io Ethernet Interface and Logic Level Converter
$EndSCHEMATC
