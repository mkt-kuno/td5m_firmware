#ifndef HardwareTimer_h
#define HardwareTimer_h

#include <Arduino.h>

#ifdef STM32F411xx
    // STM32-specific timer implementation
    class HardwareTimerWrapper {
    private:
        static void (*timer_callback)();
        static uint32_t timer_period_ms;
        static HardwareTimer *timer_instance;

    public:
        static void set(uint32_t period_ms, void (*callback)()) {
            timer_period_ms = period_ms;
            timer_callback = callback;
        }
        
        static void start() {
            timer_instance = new HardwareTimer(TIM2);
            timer_instance->setOverflow(1000000 / timer_period_ms, HERTZ_FORMAT);
            timer_instance->attachInterrupt(timer_callback);
            timer_instance->resume();
        }
        
        static void stop() {
            if (timer_instance) {
                timer_instance->pause();
            }
        }
    };

    // Static member definitions
    void (*HardwareTimerWrapper::timer_callback)() = nullptr;
    uint32_t HardwareTimerWrapper::timer_period_ms = 0;
    HardwareTimer *HardwareTimerWrapper::timer_instance = nullptr;

#else
    // AVR platforms - use MsTimer2
    #include <MsTimer2.h>
    
    class HardwareTimerWrapper {
    public:
        static void set(uint32_t period_ms, void (*callback)()) {
            MsTimer2::set(period_ms, callback);
        }
        
        static void start() {
            MsTimer2::start();
        }
        
        static void stop() {
            MsTimer2::stop();
        }
    };
#endif

#endif /*HardwareTimer_h*/