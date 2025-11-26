$0=10 ;Step Pulse Time [microsec]
$1=60000 ;Step Idle Delay [msec]
$2=0 ;Step Dir Invert Mask
$3=31; Step Dir Invert Mask
$4=0 ;Step Enable Invert
$5=31; Limit Logic Invert Mask
$6=0 ;Probe Logic Invert
$10=1 ;Status Report Options
$11=0.020 ;Junction Deviation [mm]
$12=0.002 ;Arc Tolerance [mm]
$13=0 ;Report in Inches
$20=0 ;Soft Limits Enable
$21=31; Hard Limits Enable Mask
$22=31; Homing Enable Mask
$23=31; Homing Dir Invert Mask
$24=20; Homing Speed [mm/min]
$25=40; Homing Search Speed [mm/min]
$26=250 ;Homing Debounce [msec]
$27=0.5; After Home, Set Back Little Bit [mm]
$30=1000 ;Max Spindle Speed [RPM] (DON'T USE)
$31=0 ;Min Spindle Speed [RPM] (DON'T USE)
$32=0 ;Laser Mode Enable (DON'T USE)
$100=38400; X [mm/step], 2400[mm/step] * 16microstep
$101=38400; Y [mm/step], 2400[mm/step] * 16microstep
$102=38400; Z [mm/step], 2400[mm/step] * 16microstep
$103=38400; A [mm/step], 2400[mm/step] * 16microstep
$104=38400; B [mm/step], 2400[mm/step] * 16microstep
$110=80; X Max Speed[mm/min]
$111=80; Y Max Speed[mm/min]
$112=80; Z Max Speed[mm/min]
$113=80; A Max Speed[mm/min]
$114=80; B Max Speed[mm/min]
$120=1; X Accel [mm/s^2]
$121=1; Y Accel [mm/s^2]
$122=1; Z Accel [mm/s^2]
$123=1; A Accel [mm/s^2]
$124=1; B Accel [mm/s^2]
$130=50; X Max Position [mm]
$131=50; Y Max Position [mm]
$132=50; Z Max Position [mm]
$133=50; A Max Position [mm]
$134=50; B Max Position [mm]

$HX ;Home X Axis(Max 50mm Position)
G90 ;Absolute Positioning
G1 X25 F50 ;Move to X to abs 25mm at 50mm/min
G91 ;Relative Positioning
G1 X-5 F50 ;Move to X -5mm relative at 50mm/min