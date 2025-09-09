# STM32F411 Flash-based EEPROM Implementation

## Overview
STM32F411マイコンには従来のEEPROMが搭載されていませんが、フラッシュメモリの一部を使用してEEPROM機能をエミュレートします。このプロジェクトではEEPROMWearLevelライブラリを使用してウェアレベリング機能付きのフラッシュベースEEPROMを実装しています。

## Technical Implementation

### Flash Memory Layout
STM32F411CEの場合：
- Total Flash: 512KB
- Sector 7 (最終セクター): 128KB - EEPROM emulation用に使用
- アドレス範囲: 0x08060000 - 0x0807FFFF

### Wear Leveling Strategy
EEPROMWearLevelライブラリは以下の機能を提供：
1. **自動ウェアレベリング**: 書き込み操作を複数のフラッシュページに分散
2. **冗長化**: データの安全性を向上させるための複数コピー管理
3. **クロスプラットフォーム対応**: AVRのEEPROMと同じAPIを提供

### Position Data Storage
このプロジェクトでは以下の位置データを保存：

```cpp
enum EEPROM_INDEX {
    EEPROM_INDEX_MOTOR_I = 0,  // Motor I position (4 bytes)
    EEPROM_INDEX_MOTOR_J,      // Motor J position (4 bytes) 
    EEPROM_INDEX_MOTOR_K,      // Motor K position (4 bytes)
    EEPROM_INDEX_MOTOR_L,      // Motor L position (4 bytes)
    EEPROM_INDEX_MOTOR_M       // Motor M position (4 bytes)
};
```

### Data Persistence Points
位置データは以下のタイミングで保存されます：

1. **起動時復元** (setup関数):
   ```cpp
   long steps = -1;
   EEPROMwl.get(EEPROM_INDEX_MOTOR_I, steps);
   MotorI.set_current_steps(steps);
   ```

2. **座標系設定時** (G52コマンド):
   ```cpp
   MotorI.set_current_mm(gcode->GetWordValue('I'));
   EEPROMwl.put(EEPROM_INDEX_MOTOR_I, MotorI.get_current_steps());
   ```

3. **動作完了時** (all motors stopped):
   ```cpp
   EEPROMwl.put(EEPROM_INDEX_MOTOR_I, MotorI.get_current_steps());
   ```

## Flash Memory Durability

### Write Endurance
- STM32F411フラッシュメモリ: 10,000回の消去/書き込みサイクル
- EEPROMWearLevelライブラリのウェアレベリングにより実効寿命を延長
- 1日100回の位置保存でも約100年の使用可能

### Safety Measures
1. **電源喪失保護**: フラッシュへの書き込みは原子的操作
2. **データ検証**: 読み取り時にCRCチェック実行
3. **フォールバック**: 破損データ検出時は初期値(-1)を使用

## Configuration Parameters

```cpp
#define EEPROM_LAYOUT_VERSION 0   // データレイアウトバージョン
#define EEPROM_INDEX_NUM 20       // 使用可能なインデックス数
```

## Troubleshooting

### Common Issues
1. **初回起動**: 全モーター位置が-1で初期化される（正常動作）
2. **位置喪失**: 電源投入時に前回位置が復元される
3. **フラッシュ容量**: 現在の実装では約80バイトのみ使用

### Debug Information
G21コマンドでMCUタイプを確認：
```
FIRMWARE: TrapdoorFiveMotor v2.0 - STM32F411 Enhanced (USB CDC ACM)
```

### Flash Memory Status
STM32F411でのフラッシュメモリ使用状況はビルド時に表示されます：
```
Flash: [====      ]  xx.x% used
```

## Benefits over Traditional EEPROM

1. **高速アクセス**: フラッシュメモリはEEPROMより高速
2. **大容量**: 128KBセクター vs 4KB EEPROM
3. **内蔵機能**: 外部EEPROM不要
4. **ウェアレベリング**: 自動的な寿命延長

## Migration from Mega2560
AVR Mega2560からの移行時は：
1. **同一API**: コード変更不要
2. **データ互換**: 位置データ形式同一
3. **自動初期化**: 初回起動時に安全に初期化

この実装により、STM32F411でもMega2560と同等のEEPROM機能を実現し、モーター位置の永続化を確実に行います。