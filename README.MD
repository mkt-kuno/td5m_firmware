# 5モータ同時ドライブファームウェア
対象試験:落とし戸試験  
ボード:Mega2560(EEPROMを必要とするため)  
## API(GCode)
### 共通事項
XYZ系統ではなく I/J/K/L/M [mm]をモータ指定&変位量としています  
また速度指定を V/W/X/Y/Z [mm/min]としています。  
モータI[mm] -> 速度V [mm/min]  
モータM[mm] -> 速度Z [mm/min]  
例) G90 I-5 V10 -> モータIを絶対座標-5[mm]まで速度10[mm/min]で移動せよ  
例) G91 I-1 V5 -> モータIを現在座標から-1[mm]、速度5[mm/min]で移動せよ  
### G90 絶対値移動
通常のGCodeに準拠します  
### G91 インクリメンタル移動
通常のGCodeに準拠します  
### G52 ワーク位置更新
設定値を現在のワーク位置としてEEPROMに保存します  
### G17 モータ電源ON
ステッピングモータの電源をONにして  
電磁ロックを作動させます  
よほどの重荷重がかからない限り不要だと思います  
### G17 モータ電源OFF
ステッピングモータの電源をONにして  
電磁ロックを切ります  

## モーター情報
Model:BHTGA-SS-50-0.5  
DC Range: 24[V]
Current(no load):　0.3[A]
Current(loading):　2.0[A]
MaxLoad: 90[kg]
Range: 50[mm]
LoadingTime: 10%の動作90%の冷却,2分動作で18分休憩
SPM: 2400 [steps/mm]  

| 空载速度 (No-load speed) | 负载速度 (Load speed) | 推力 (Thrust) | 拉力 (Pull) | 自锁力 (Self-locking force) |
| :--- | :--- | :--- | :--- | :--- |
| 0.5mm/s | 0.3mm/s | 900N | 800N | 2000N |
| 1mm/s | 0.8mm/s | 750N | 600N | 1000N |
| 1.5mm/s | 1.2mm/s | 600N | 550N | 700N |
| 2mm/s | 1.6mm/s | 450N | 400N | 500N |
| 2.5mm/s | 2mm/s | 350N | 300N | 400N |
| 3mm/s | 2.5mm/s | 300N | 250N | 400N |
| 4mm/s | 3.5mm/s | 200N | 150N | 300N |

SM黒:A1/A+  
SM緑:A2/A-  
SM赤:B1/B+  
SM青:B2/B-  

SW赤-青: Min Limit  
SW黒-白: Max Limit  

## ピン情報
|Arduino|HW Pin|Motor|Function|
|----|----|----|----|
|29|PA7|I|Step|
|30|PC7|I|Dir|
|31|PC6|I|Ena|
|32|PC5|I|Max|
|33|PC4|I|Min|
|34|PC3|J|Step|
|35|PC2|J|Dir|
|36|PC1|J|Ena|
|37|PC0|J|Max|
|38|PD7|J|Min|
|39|PG2|K|Step|
|40|PG1|K|Dir|
|41|PG0|K|Ena|
|42|PL7|K|Max|
|43|PL6|K|Min|
|44|PL5|L|Step|
|45|PL4|L|Dir|
|46|PL3|L|Ena|
|47|PL2|L|Max|
|48|PL1|L|Min|
|49|PL0|M|Step|
|50|PB3|M|Dir|
|51|PB2|M|Ena|
|52|PB1|M|Max|
|53|PB0|M|Min|

## GRBL的設定項目(only X axis)
```gcode
$3=1 ;Step Dir X Invert
$5=1 ;Limit Logic X Invert
$21=1 ;Hard Limit X Enable
$22=1 ;Home X Enable
$23=1 ;Home X Dir Invert
$24=10;Homing Speed [mm/min]
$25=20;Homing Search Speed [mm/min]
$27=0.5;After Home, Set Back Little Bit [mm]
$100=2400;X [mm/step]
$110=30; X Max Speed[mm/min]
$120=1; X Acce [mm/s^2]
$130=50; X Max Position [mm]
```
