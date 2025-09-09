#ifndef AsyncSerial_h
#define AsyncSerial_h

#include <Arduino.h>
#include <Print.h>
#include <RingBuf.h>

#define TX_BUFFER_SIZE 512

class AsyncSerial : public Print {
    private:
        RingBuf<unsigned char, TX_BUFFER_SIZE> tx_buf;
        HardwareSerial *serial = NULL;

    public:
        AsyncSerial(int num) {
#ifdef STM32F411xx
            // STM32F411 serial port mapping
            switch(num) {
                case 0:serial = &Serial;break;  // USART2 (PA2/PA3)
                case 1:serial = &Serial1;break; // USART1 (PA9/PA10)
                case 2:serial = &Serial2;break; // USART6 (PC6/PC7)
                default: serial = &Serial;break;
            }
#else
            // AVR serial port mapping
            switch(num) {
                case 0:serial = &Serial;break;
#if defined(__AVR_ATmega2560__)
                case 1:serial = &Serial1;break;
                case 2:serial = &Serial2;break;
                case 3:serial = &Serial3;break;
#endif
                default: serial = &Serial;break;
            }
#endif
        }

        // override function
        size_t write(uint8_t data) {
            if (tx_buf.isFull()) return 0;
            tx_buf.push(data);
            return 1;
        }

        void begin(long baud) {
            serial->begin(baud);
        }
        bool available() {
            return serial->available();
        }
        int read() {
            return serial->read();
        }

        void loop(void) {
            unsigned char c;
            if (serial->availableForWrite() && tx_buf.pop(c) ) {
                serial->print((char)c);
            }
        }   
};
#endif /*AsyncSerial_h*/