//******************************************************************************
// OIC - Omnidirecional Infrared Center - 2018
// IR Remote NEC Protocol
// Based on https://github.com/z3t0/Arduino-IRremote
//******************************************************************************

#ifndef IRremote_h
#define IRremote_h

#include "IRremoteInt.h"

#define DECODE_NEC           1
#define SEND_NEC             1

typedef
	enum {
		UNKNOWN,
		NEC
	}
decode_type_t;

#define DEBUG  0

#if DEBUG
#	define DBG_PRINT(...)    Serial.print(__VA_ARGS__)
#	define DBG_PRINTLN(...)  Serial.println(__VA_ARGS__)
#else
#	define DBG_PRINT(...)
#	define DBG_PRINTLN(...)
#endif

int  MATCH       (int measured, int desired) ;
int  MATCH_MARK  (int measured_ticks, int desired_us) ;
int  MATCH_SPACE (int measured_ticks, int desired_us) ;

class decode_results
{
	public:
		decode_type_t          decode_type;  // UNKNOWN, NEC, ...
		unsigned int           address;      // Used by Panasonic & Sharp [16-bits]
		unsigned long          value;        // Decoded value [max 32-bits]
		int                    bits;         // Number of bits in decoded value
		volatile unsigned int  *rawbuf;      // Raw intervals in 50uS ticks
		int                    rawlen;       // Number of records in rawbuf
		int                    overflow;     // true iff IR raw code too long
};

#define REPEAT 0xFFFFFFFF

class IRrecv
{
	public:
		IRrecv (int recvpin) ;

		int   decode (decode_results *results) ;
		void  enableIRIn ( ) ;
		bool  isIdle ( ) ;
		void  resume ( ) ;

	private:
		long  decodeHash (decode_results *results) ;
		int   compare (unsigned int oldval, unsigned int newval) ;

		bool  decodeNEC (decode_results *results) ;
};
#endif
