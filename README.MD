# 5モータ同時ドライブgrblファームウェア
対象試験:落とし戸試験  
ボード:STM32F103C8T6 (BluePill)
モータ:5軸,各軸BHTGA-SS-50-0.5 (リニアアクチュエータ)
ドライバ:TB6600 x5

## grblファームウェア情報
uCNC v1.13.0(Grbl 1.13)  
https://github.com/Paciente8159/uCNC

### grblよく使うコマンド早見表
- G0: 早送り移動
- G1: 指定速度で移動
- G20: インチ単位指定
- G21: ミリ単位指定
- G90: 絶対位置指定
- G91: 相対位置指定
- $HX: X軸ホーム
- $HY: Y軸ホーム
- $HZ: Z軸ホーム
- $HA: A軸ホーム
- $HB: B軸ホーム
- \$\$: 設定一覧表示
- \$SS: 設定値保存
- \$SL: 設定値読み込み  

他のコマンドは[公式ドキュメント](https://github.com/Paciente8159/uCNC/wiki/)を参照してください。

## モーター情報
Model:BHTGA-SS-50-0.5  
DC Range: 24[V]  
Current(no load):　0.3[A]  
Current(loading):　2.0[A]  
MaxLoad: 90[kg]  
Range: 50[mm]  
LoadingTime: 10%の動作->90%の冷却,2分動作->18分休憩  
SPM: 2400 [step/mm]  

| No-load speed | Load speed | 推力 (Thrust) | 拉力 (Pull) | 自锁力 (Self-locking force) |
| :--- | :--- | :--- | :--- | :--- |
| 0.5mm/s (30mm/s)| 0.3mm/s | 900N | 800N | 2000N |
| 1mm/s | 0.8mm/s | 750N | 600N | 1000N |
| 1.5mm/s | 1.2mm/s | 600N | 550N | 700N |
| 2mm/s (120mm/s)| 1.6mm/s | 450N | 400N | 500N |
| 2.5mm/s | 2mm/s | 350N | 300N | 400N |
| 3mm/s | 2.5mm/s | 300N | 250N | 400N |
| 4mm/s (240mm/s)| 3.5mm/s | 200N | 150N | 300N |

SM黒:A1/A+  
SM緑:A2/A-  
SM赤:B1/B+  
SM青:B2/B-  

SW赤-青: Min Limit  
SW黒-白: Max Limit  

## ピン情報 for BluePill (STM32F103C8T6)
|HW Port|HW Pin| Function|
|---|---|---|
|B|14|X-STEP|
|B|13|X-DIR|
|B|12|X-EN|
|A|10|Y-STEP|
|A| 9|Y-DIR|
|A| 8|Y-EN|
|B| 5|Z-STEP|
|B| 4|Z-DIR|
|B| 3|Z-EN|
|B| 9|A-STEP|
|B| 8|A-DIR|
|B| 7|A-EN|
|A| 3|B-STEP|
|A| 2|B-DIR|
|A| 1|B-EN|
|B|15|X-LIM|
|A|15|Y-LIM|
|B| 6|Z-LIM|
|A| 4|A-LIM|
|A| 0|B-LIM|
|A| 5|ESTOP|

## モータドライバ情報
TB6600 MicroStep: 1/16(OFF,OFF,ON)
TB6600 Current: 2.0A-2.2A(ON,OFF,OFF)

## 設定項目
```gcode
; $$ ;View All Settings
; Mask: X(1,0b00001)Y(2,0b00010)Z(4,0b00100)A(8,0b01000)B(16,0b10000)
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
$30=1000 ;Max Spindle Speed [RPM]   (NOT USE)
$31=0 ;Min Spindle Speed [RPM]      (NOT USE)
$32=0 ;Laser Mode Enable            (NOT USE)
$100=38400; X [step/mm], 2400[step/mm] * 16microstep
$101=38400; Y [step/mm], 2400[step/mm] * 16microstep
$102=38400; Z [step/mm], 2400[step/mm] * 16microstep
$103=38400; A [step/mm], 2400[step/mm] * 16microstep
$104=38400; B [step/mm], 2400[step/mm] * 16microstep
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
```
