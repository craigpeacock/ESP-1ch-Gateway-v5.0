// 1-channel LoRa Gateway for ESP8266
// Copyright (c) 2016, 2017 Maarten Westenberg version for ESP8266
// Version 5.0.9
// Date: 2018-04-07
//
// 	based on work done by Thomas Telkamp for Raspberry PI 1ch gateway
//	and many others.
//
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the MIT License
// which accompanies this distribution, and is available at
// https://opensource.org/licenses/mit-license.php
//
// Author: Maarten Westenberg (mw12554@hotmail.com)
//
// This file contains a number of compile-time settings that can be set on (=1) or off (=0)
// The disadvantage of compile time is minor compared to the memory gain of not having
// too much code compiled and loaded on your ESP8266.
//
// ----------------------------------------------------------------------------------------

// At this moment there is only one record written to the ESP8266
// filesystem. We can add more info, which makes the gateway even more usable,
// however for large data we should only append to the existing file used.
// This also means we'll have to check for available space so we won't run out of 
// storage space to quickly.
// One way would be to use let's say 10 files of each 10000 lines and when full
// delete the first file and start writing on a new one (for example)




// Definition of the configuration record that is read at startup and written
// when settings are changed.

struct espGwayConfig {
	uint16_t fcnt;				// =0 as init value	XXX Could be 32 bit in size
	uint16_t boots;				// Number of restarts made by the gateway after reset
	uint16_t resets;			// Number of statistics resets
	uint16_t views;				// Number of sendWebPage() calls
	uint16_t wifis;				// Number of WiFi Setups
	uint16_t reents;			// Number of re-entrant interrupt handler calls
	uint16_t ntpErr;			// Number of UTP requests that failed
	uint16_t ntps;

	uint32_t ntpErrTime;		// Record the time of the last NTP error
	uint8_t ch;					// index to freqs array, freqs[ifreq]=868100000 default
	uint8_t sf;					// range from SF7 to SF12
	uint8_t debug;				// range 0 to 4

	uint16_t logFileRec;		// Logging File Record number
	uint16_t logFileNo;			// Logging File Number
	uint16_t logFileNum;		// Number of log files
	
	bool cad;					// is CAD enabled?
	bool hop;					// Is HOP enabled (Note: Should be disabled)
	bool isNode;				// Is gateway node enabled
	bool refresh;				// Is WWW browser refresh enabled
	
	String ssid;				// SSID of the last connected WiFi Network
	String pass;				// Password
} gwayConfig;

// Define a log record to be written to the log file
// Keep logfiles SHORT in name! to save memory
#if STAT_LOG == 1

// We do keep admin of logfiles by number
// 
//uint32_t logFileNo = 1;		// Included in struct espGwayConfig LogFile number
//uint32_t logFileRec = 0;		// Number of records in a single logfile
//uint32_t logFileNum = 1;		// Number of log files
#define LOGFILEMAX 10
#define LOGFILEREC 100

#endif
