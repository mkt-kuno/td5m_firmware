# MCU Enhancement Progress

## Changes Made

### 1. Added STM32F411 Platform Support
- Added new `[env:STM32F411]` environment in `platformio.ini`
- Platform: `ststm32` with `blackpill_f411ce` board
- Optimized library dependencies (removed MsTimer2, removed fastIO which is AVR-specific)

### 2. Cross-Platform Timer System
- Created `HardwareTimer.hpp` for cross-platform timer abstraction
- STM32F411: Uses hardware timer (TIM2) for precise timing
- AVR platforms: Falls back to MsTimer2 for compatibility
- Maintains same API interface for seamless integration

### 3. Enhanced Motor Control Efficiency
- Modified `AsyncStepper.hpp` with timer-based control inspired by Marlin/grbl
- Added `emergency_stop()` function for immediate limit switch response
- Improved step timing with `step_interval_usec` and `next_step_time`
- Optimized loop() function with timer-based scheduling

### 4. STM32F411 Pin Mapping
- Added conditional pin assignments for STM32F411
- Motor I: PA0-PA4 (pulse, dir, ena, max, min)
- Motor J: PA5-PB1
- Motor K: PB10-PB14
- Motor L: PB15-PC9
- Motor M: PC10-PD2,PA8

### 5. Enhanced Serial Communication
- Updated `AsyncSerial.hpp` with STM32F411 USART mapping
- USART2 (PA2/PA3), USART1 (PA9/PA10), USART6 (PC6/PC7)
- Maintains backward compatibility with AVR platforms

## Key Features Preserved
- ✅ Limit switch immediate stop functionality
- ✅ Freedom to move in non-prohibited directions
- ✅ Complete GCode interface (G90, G91, G52, G17, G18)
- ✅ Position tracking and EEPROM storage
- ✅ All existing API compatibility

## Architecture Improvements
- Timer-based motor control for better efficiency (like Marlin/grbl)
- Cross-platform abstraction layer
- Optimized step scheduling
- Enhanced limit switch response time

## Next Steps
- Build verification on actual hardware
- Performance testing and optimization
- Pin mapping validation for specific STM32F411 board