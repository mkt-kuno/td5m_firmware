# USB CDC ACM Implementation for STM32F411

このドキュメントは、TrapdoorFiveMotorファームウェアにおけるUSB CDC ACM（USB Communication Device Class - Abstract Control Model）の実装について説明します。

## 概要

STM32F411プラットフォームにおいて、従来のCH340などの外部USB-UART変換チップに依存する通信方式から、STM32F411の内蔵USB機能を使用したUSB CDC ACM通信に移行しました。

## 主要な変更点

### 1. platformio.ini の設定

```ini
[env:STM32F411]
framework = arduino
build_flags = -O3 -flto -DSERIAL_TX_BUFFER_SIZE=192 -DSTM32F411xx -DUSBCON -DUSBD_USE_CDC
monitor_speed = 115200
platform = ststm32
board = blackpill_f411ce
board_build.usb_product = "TrapdoorFiveMotor"
board_build.hwids = [["0x1EAF", "0x0004"]]
```

**追加された設定:**
- `-DUSBCON`: USB接続を有効化
- `-DUSBD_USE_CDC`: USB CDC機能を有効化
- `board_build.usb_product`: USBデバイス名を設定
- `board_build.hwids`: USB VID/PIDを設定

### 2. AsyncSerial.hpp の更新

STM32F411において、`Serial`オブジェクトがUSB CDC ACMを使用するように変更：

```cpp
#ifdef STM32F411xx
    // STM32F411 serial port mapping
    // When USB CDC is enabled, Serial uses USB CDC ACM instead of UART
    switch(num) {
        case 0:serial = &Serial;break;  // USB CDC ACM (native USB)
        case 1:serial = &Serial1;break; // USART1 (PA9/PA10) - if needed for other purposes
        case 2:serial = &Serial2;break; // USART6 (PC6/PC7) - if needed for other purposes
        default: serial = &Serial;break;
    }
#endif
```

### 3. ファームウェア識別の更新

G21コマンドでの応答に USB CDC ACM 使用を明記：

```cpp
ASerial.println("STM32F411 Enhanced (USB CDC ACM)");
```

## 利点

### 1. 外部部品の削除
- CH340、FT232RL等の外部USB-UART変換チップが不要
- 部品点数の削減とコスト削減
- 回路設計の簡素化

### 2. 性能向上
- 直接USB通信による低レイテンシ
- より高いデータ転送レート
- CPU負荷の軽減

### 3. 安定性の向上
- 外部チップの不具合やドライバー問題の排除
- より安定した通信

### 4. 開発効率
- ドライバーのインストールが不要（標準のCDCドライバーを使用）
- デバッグの簡素化

## ハードウェア要件

### STM32F411CE BlackPill
- USB-Cコネクタまたはmicro-USBコネクタ
- USB D+/D- ピンの配線
- 適切なUSBプルアップ抵抗（通常ボードに実装済み）

### ピン使用状況
USB CDC ACM使用時は以下のピンが使用されます：
- PA11: USB_DM（USB D-）
- PA12: USB_DP（USB D+）

従来のUART通信用ピン（PA2/PA3）は他の用途に使用可能です。

## 使用方法

### 1. ビルド
```bash
pio run -e STM32F411
```

### 2. フラッシュ
```bash
pio run -e STM32F411 -t upload
```

### 3. 接続
- STM32F411をUSBケーブルでPCに接続
- 自動的に仮想COMポートとして認識される
- シリアルターミナル（115200 baud）で通信開始

## トラブルシューティング

### デバイスが認識されない場合
1. USBケーブルがデータ転送対応か確認
2. STM32F411のUSB回路が正常か確認
3. PC側のUSBポートを変更して試行

### 通信が不安定な場合
1. USBケーブルの品質を確認
2. PCのUSBポートの電力供給を確認
3. 他のUSBデバイスとの干渉を確認

## 互換性

- **Windows**: Windows 10以降で標準サポート
- **Linux**: カーネル標準のCDCドライバーで動作
- **macOS**: 標準サポート

特別なドライバーのインストールは不要です。

## 従来方式との比較

| 項目 | USB CDC ACM | 外部USB-UART |
|------|-------------|--------------|
| 部品点数 | 少ない | 多い |
| レイテンシ | 低い | 高い |
| ドライバー | 不要 | 必要な場合あり |
| 安定性 | 高い | チップ依存 |
| コスト | 低い | 高い |

この実装により、TrapdoorFiveMotorはより効率的で信頼性の高い通信システムを実現しています。