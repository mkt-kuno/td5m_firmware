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
2400 [steps/mm]  

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
