/* File automatically generated by the Crosstable compiler */
/* from the Crosstable file Crosstable.csv. */

/* BIT        ->  int       */
/* BYTE_BIT   ->  int       */
/* WORD_BIT   ->  int       */
/* DWORD_BIT  ->  int       */
/* BYTE       ->  u_int8_t  */
/* UINT       ->  u_int16_t */
/* UINTBA     ->  UINTBA    */
/* INT        ->  int16_t   */
/* INTBA      ->  INTBA     */
/* UDINT      ->  u_int32_t */
/* UDINTBADC  ->  UDINTBADC */
/* UDINTCDAB  ->  UDINTCDAB */
/* UDINTDCBA  ->  UDINTDCBA */
/* DINT       ->  int32_t   */
/* DINTBADC   ->  DINTBADC  */
/* DINTCDAB   ->  DINTCDAB  */
/* DINTDCBA   ->  DINTDCBA  */
/* REAL       ->  float     */
/* REALBADC   ->  REALBADC  */
/* REALCDAB   ->  REALCDAB  */
/* REALDCBA   ->  REALDCBA  */

#ifndef CROSSTABLE_H__
#define CROSSTABLE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>
#include "cross_table_utility.h"


#define ID_RTU3_TYPE_PORT 5020
extern u_int32_t RTU3_TYPE_PORT;
int doWrite_RTU3_TYPE_PORT(u_int32_t value);
int addWrite_RTU3_TYPE_PORT(u_int32_t value);
int getStatus_RTU3_TYPE_PORT(void);

#define ID_RTU3_BAUDRATE 5021
extern u_int32_t RTU3_BAUDRATE;
int doWrite_RTU3_BAUDRATE(u_int32_t value);
int addWrite_RTU3_BAUDRATE(u_int32_t value);
int getStatus_RTU3_BAUDRATE(void);

#define ID_RTU3_STATUS 5022
extern u_int32_t RTU3_STATUS;
int doWrite_RTU3_STATUS(u_int32_t value);
int addWrite_RTU3_STATUS(u_int32_t value);
int getStatus_RTU3_STATUS(void);

#define ID_RTU3_READS 5023
extern u_int32_t RTU3_READS;
int doWrite_RTU3_READS(u_int32_t value);
int addWrite_RTU3_READS(u_int32_t value);
int getStatus_RTU3_READS(void);

#define ID_RTU3_WRITES 5024
extern u_int32_t RTU3_WRITES;
int doWrite_RTU3_WRITES(u_int32_t value);
int addWrite_RTU3_WRITES(u_int32_t value);
int getStatus_RTU3_WRITES(void);

#define ID_RTU3_TIMEOUTS 5025
extern u_int32_t RTU3_TIMEOUTS;
int doWrite_RTU3_TIMEOUTS(u_int32_t value);
int addWrite_RTU3_TIMEOUTS(u_int32_t value);
int getStatus_RTU3_TIMEOUTS(void);

#define ID_RTU3_COMM_ERRORS 5026
extern u_int32_t RTU3_COMM_ERRORS;
int doWrite_RTU3_COMM_ERRORS(u_int32_t value);
int addWrite_RTU3_COMM_ERRORS(u_int32_t value);
int getStatus_RTU3_COMM_ERRORS(void);

#define ID_RTU3_LAST_ERROR 5027
extern u_int32_t RTU3_LAST_ERROR;
int doWrite_RTU3_LAST_ERROR(u_int32_t value);
int addWrite_RTU3_LAST_ERROR(u_int32_t value);
int getStatus_RTU3_LAST_ERROR(void);

#define ID_RTU3_WRITE_QUEUE 5028
extern u_int32_t RTU3_WRITE_QUEUE;
int doWrite_RTU3_WRITE_QUEUE(u_int32_t value);
int addWrite_RTU3_WRITE_QUEUE(u_int32_t value);
int getStatus_RTU3_WRITE_QUEUE(void);

#define ID_RTU3_BUS_LOAD 5029
extern u_int32_t RTU3_BUS_LOAD;
int doWrite_RTU3_BUS_LOAD(u_int32_t value);
int addWrite_RTU3_BUS_LOAD(u_int32_t value);
int getStatus_RTU3_BUS_LOAD(void);

#define ID_NODE_01_DEV_NODE 5172
extern u_int32_t NODE_01_DEV_NODE;
int doWrite_NODE_01_DEV_NODE(u_int32_t value);
int addWrite_NODE_01_DEV_NODE(u_int32_t value);
int getStatus_NODE_01_DEV_NODE(void);

#define ID_NODE_01_STATUS 5173
extern u_int32_t NODE_01_STATUS;
int doWrite_NODE_01_STATUS(u_int32_t value);
int addWrite_NODE_01_STATUS(u_int32_t value);
int getStatus_NODE_01_STATUS(void);

#define ID_PLC_FWrevision 5300
extern u_int16_t PLC_FWrevision;
int doWrite_PLC_FWrevision(u_int16_t value);
int addWrite_PLC_FWrevision(u_int16_t value);
int getStatus_PLC_FWrevision(void);

#define ID_PLC_HWconfig 5301
extern u_int16_t PLC_HWconfig;
int doWrite_PLC_HWconfig(u_int16_t value);
int addWrite_PLC_HWconfig(u_int16_t value);
int getStatus_PLC_HWconfig(void);

#define ID_PLC_DigDir_1 5302
extern int PLC_DigDir_1;
int doWrite_PLC_DigDir_1(int value);
int addWrite_PLC_DigDir_1(int value);
int getStatus_PLC_DigDir_1(void);

#define ID_PLC_DigDir_2 5303
extern int PLC_DigDir_2;
int doWrite_PLC_DigDir_2(int value);
int addWrite_PLC_DigDir_2(int value);
int getStatus_PLC_DigDir_2(void);

#define ID_PLC_DigDir_3 5304
extern int PLC_DigDir_3;
int doWrite_PLC_DigDir_3(int value);
int addWrite_PLC_DigDir_3(int value);
int getStatus_PLC_DigDir_3(void);

#define ID_PLC_DigDir_4 5305
extern int PLC_DigDir_4;
int doWrite_PLC_DigDir_4(int value);
int addWrite_PLC_DigDir_4(int value);
int getStatus_PLC_DigDir_4(void);

#define ID_PLC_DigDir_5 5306
extern int PLC_DigDir_5;
int doWrite_PLC_DigDir_5(int value);
int addWrite_PLC_DigDir_5(int value);
int getStatus_PLC_DigDir_5(void);

#define ID_PLC_DigDir_6 5307
extern int PLC_DigDir_6;
int doWrite_PLC_DigDir_6(int value);
int addWrite_PLC_DigDir_6(int value);
int getStatus_PLC_DigDir_6(void);

#define ID_PLC_DigDir_7 5308
extern int PLC_DigDir_7;
int doWrite_PLC_DigDir_7(int value);
int addWrite_PLC_DigDir_7(int value);
int getStatus_PLC_DigDir_7(void);

#define ID_PLC_DigDir_8 5309
extern int PLC_DigDir_8;
int doWrite_PLC_DigDir_8(int value);
int addWrite_PLC_DigDir_8(int value);
int getStatus_PLC_DigDir_8(void);

#define ID_PLC_DigOut_1 5310
extern int PLC_DigOut_1;
int doWrite_PLC_DigOut_1(int value);
int addWrite_PLC_DigOut_1(int value);
int getStatus_PLC_DigOut_1(void);

#define ID_PLC_DigOut_2 5311
extern int PLC_DigOut_2;
int doWrite_PLC_DigOut_2(int value);
int addWrite_PLC_DigOut_2(int value);
int getStatus_PLC_DigOut_2(void);

#define ID_PLC_DigOut_3 5312
extern int PLC_DigOut_3;
int doWrite_PLC_DigOut_3(int value);
int addWrite_PLC_DigOut_3(int value);
int getStatus_PLC_DigOut_3(void);

#define ID_PLC_DigOut_4 5313
extern int PLC_DigOut_4;
int doWrite_PLC_DigOut_4(int value);
int addWrite_PLC_DigOut_4(int value);
int getStatus_PLC_DigOut_4(void);

#define ID_PLC_DigOut_5 5314
extern int PLC_DigOut_5;
int doWrite_PLC_DigOut_5(int value);
int addWrite_PLC_DigOut_5(int value);
int getStatus_PLC_DigOut_5(void);

#define ID_PLC_DigOut_6 5315
extern int PLC_DigOut_6;
int doWrite_PLC_DigOut_6(int value);
int addWrite_PLC_DigOut_6(int value);
int getStatus_PLC_DigOut_6(void);

#define ID_PLC_DigOut_7 5316
extern int PLC_DigOut_7;
int doWrite_PLC_DigOut_7(int value);
int addWrite_PLC_DigOut_7(int value);
int getStatus_PLC_DigOut_7(void);

#define ID_PLC_DigOut_8 5317
extern int PLC_DigOut_8;
int doWrite_PLC_DigOut_8(int value);
int addWrite_PLC_DigOut_8(int value);
int getStatus_PLC_DigOut_8(void);

#define ID_PLC_DigIn_1 5318
extern int PLC_DigIn_1;
int doWrite_PLC_DigIn_1(int value);
int addWrite_PLC_DigIn_1(int value);
int getStatus_PLC_DigIn_1(void);

#define ID_PLC_DigIn_2 5319
extern int PLC_DigIn_2;
int doWrite_PLC_DigIn_2(int value);
int addWrite_PLC_DigIn_2(int value);
int getStatus_PLC_DigIn_2(void);

#define ID_PLC_DigIn_3 5320
extern int PLC_DigIn_3;
int doWrite_PLC_DigIn_3(int value);
int addWrite_PLC_DigIn_3(int value);
int getStatus_PLC_DigIn_3(void);

#define ID_PLC_DigIn_4 5321
extern int PLC_DigIn_4;
int doWrite_PLC_DigIn_4(int value);
int addWrite_PLC_DigIn_4(int value);
int getStatus_PLC_DigIn_4(void);

#define ID_PLC_DigIn_5 5322
extern int PLC_DigIn_5;
int doWrite_PLC_DigIn_5(int value);
int addWrite_PLC_DigIn_5(int value);
int getStatus_PLC_DigIn_5(void);

#define ID_PLC_DigIn_6 5323
extern int PLC_DigIn_6;
int doWrite_PLC_DigIn_6(int value);
int addWrite_PLC_DigIn_6(int value);
int getStatus_PLC_DigIn_6(void);

#define ID_PLC_DigIn_7 5324
extern int PLC_DigIn_7;
int doWrite_PLC_DigIn_7(int value);
int addWrite_PLC_DigIn_7(int value);
int getStatus_PLC_DigIn_7(void);

#define ID_PLC_DigIn_8 5325
extern int PLC_DigIn_8;
int doWrite_PLC_DigIn_8(int value);
int addWrite_PLC_DigIn_8(int value);
int getStatus_PLC_DigIn_8(void);

#define ID_PLC_Heartbeat 5330
extern u_int16_t PLC_Heartbeat;
int doWrite_PLC_Heartbeat(u_int16_t value);
int addWrite_PLC_Heartbeat(u_int16_t value);
int getStatus_PLC_Heartbeat(void);

#define ID_PLC_time 5390
extern float PLC_time;	/* Seconds since boot (reset each 24h) */
int doWrite_PLC_time(float value);
int addWrite_PLC_time(float value);
int getStatus_PLC_time(void);

#define ID_PLC_timeMin 5391
extern float PLC_timeMin;	/* 10 seconds window start */
int doWrite_PLC_timeMin(float value);
int addWrite_PLC_timeMin(float value);
int getStatus_PLC_timeMin(void);

#define ID_PLC_timeMax 5392
extern float PLC_timeMax;	/* 10 seconds window stop */
int doWrite_PLC_timeMax(float value);
int addWrite_PLC_timeMax(float value);
int getStatus_PLC_timeMax(void);

#define ID_PLC_timeWin 5393
extern float PLC_timeWin;	/* Graph display window */
int doWrite_PLC_timeWin(float value);
int addWrite_PLC_timeWin(float value);
int getStatus_PLC_timeWin(void);

#define ID_PLC_Version 5394
extern u_int16_t PLC_Version;	/* Run Time version */
int doWrite_PLC_Version(u_int16_t value);
int addWrite_PLC_Version(u_int16_t value);
int getStatus_PLC_Version(void);

#define ID_PLC_EngineStatus 5395
extern u_int16_t PLC_EngineStatus;	/* PLC status */
int doWrite_PLC_EngineStatus(u_int16_t value);
int addWrite_PLC_EngineStatus(u_int16_t value);
int getStatus_PLC_EngineStatus(void);

#define ID_PLC_ResetValues 5396
extern int PLC_ResetValues;	/* Diagnostic variables reset */
int doWrite_PLC_ResetValues(int value);
int addWrite_PLC_ResetValues(int value);
int getStatus_PLC_ResetValues(void);

#define ID_PLC_buzzerOn 5397
extern int PLC_buzzerOn;	/* Buzzer sound (enable = 1 disable = 0) */
int doWrite_PLC_buzzerOn(int value);
int addWrite_PLC_buzzerOn(int value);
int getStatus_PLC_buzzerOn(void);

#define ID_PLC_PLC_Version 5398
extern u_int16_t PLC_PLC_Version;	/* PLC application version */
int doWrite_PLC_PLC_Version(u_int16_t value);
int addWrite_PLC_PLC_Version(u_int16_t value);
int getStatus_PLC_PLC_Version(void);

#define ID_PLC_HMI_Version 5399
extern u_int16_t PLC_HMI_Version;	/* HMI application version */
int doWrite_PLC_HMI_Version(u_int16_t value);
int addWrite_PLC_HMI_Version(u_int16_t value);
int getStatus_PLC_HMI_Version(void);

#define ID_PLC_Year 5410
extern u_int16_t PLC_Year;	/* Currently year */
int doWrite_PLC_Year(u_int16_t value);
int addWrite_PLC_Year(u_int16_t value);
int getStatus_PLC_Year(void);

#define ID_PLC_Month 5411
extern u_int16_t PLC_Month;	/* Currently month */
int doWrite_PLC_Month(u_int16_t value);
int addWrite_PLC_Month(u_int16_t value);
int getStatus_PLC_Month(void);

#define ID_PLC_Day 5412
extern u_int16_t PLC_Day;	/* Currently day */
int doWrite_PLC_Day(u_int16_t value);
int addWrite_PLC_Day(u_int16_t value);
int getStatus_PLC_Day(void);

#define ID_PLC_Hours 5413
extern u_int16_t PLC_Hours;	/* Currently hour */
int doWrite_PLC_Hours(u_int16_t value);
int addWrite_PLC_Hours(u_int16_t value);
int getStatus_PLC_Hours(void);

#define ID_PLC_Minutes 5414
extern u_int16_t PLC_Minutes;	/* Currently minutes */
int doWrite_PLC_Minutes(u_int16_t value);
int addWrite_PLC_Minutes(u_int16_t value);
int getStatus_PLC_Minutes(void);

#define ID_PLC_Seconds 5415
extern u_int16_t PLC_Seconds;	/* Currently seconds */
int doWrite_PLC_Seconds(u_int16_t value);
int addWrite_PLC_Seconds(u_int16_t value);
int getStatus_PLC_Seconds(void);

#define ID_PLC_UPTIME_s 5416
extern u_int32_t PLC_UPTIME_s;	/* Uptime in seconds (wraps in 136 years) */
int doWrite_PLC_UPTIME_s(u_int32_t value);
int addWrite_PLC_UPTIME_s(u_int32_t value);
int getStatus_PLC_UPTIME_s(void);

#define ID_PLC_UPTIME_cs 5417
extern u_int32_t PLC_UPTIME_cs;	/* Uptime in centiseconds = 10 ms (wraps in 497 days) */
int doWrite_PLC_UPTIME_cs(u_int32_t value);
int addWrite_PLC_UPTIME_cs(u_int32_t value);
int getStatus_PLC_UPTIME_cs(void);

#define ID_PLC_WATCHDOGEN 5418
extern int PLC_WATCHDOGEN;	/* Enable Watchdog */
int doWrite_PLC_WATCHDOGEN(int value);
int addWrite_PLC_WATCHDOGEN(int value);
int getStatus_PLC_WATCHDOGEN(void);

#define ID_PLC_WATCHDOG_ms 5419
extern u_int32_t PLC_WATCHDOG_ms;	/* Reset Watchdog timer */
int doWrite_PLC_WATCHDOG_ms(u_int32_t value);
int addWrite_PLC_WATCHDOG_ms(u_int32_t value);
int getStatus_PLC_WATCHDOG_ms(void);

#define ID_PLC_PRODUCT_ID 5420
extern u_int32_t PLC_PRODUCT_ID;	/* TP/TPAC/TPLC Product ID (Hex) */
int doWrite_PLC_PRODUCT_ID(u_int32_t value);
int addWrite_PLC_PRODUCT_ID(u_int32_t value);
int getStatus_PLC_PRODUCT_ID(void);

#define ID_PLC_SERIAL_NUMBER 5421
extern u_int32_t PLC_SERIAL_NUMBER;	/* TP/TPAC/TPLC Serial Number */
int doWrite_PLC_SERIAL_NUMBER(u_int32_t value);
int addWrite_PLC_SERIAL_NUMBER(u_int32_t value);
int getStatus_PLC_SERIAL_NUMBER(void);

#define ID_PLC_HMI_PAGE 5422
extern int32_t PLC_HMI_PAGE;	/* HMI Page (page100=0x00000100) */
int doWrite_PLC_HMI_PAGE(int32_t value);
int addWrite_PLC_HMI_PAGE(int32_t value);
int getStatus_PLC_HMI_PAGE(void);

#define ID_PLC_MS_VERSION 5423
extern u_int32_t PLC_MS_VERSION;	/* Mect Suite Version installed on Target (0 if before 3.4.0) */
int doWrite_PLC_MS_VERSION(u_int32_t value);
int addWrite_PLC_MS_VERSION(u_int32_t value);
int getStatus_PLC_MS_VERSION(void);

#define ID_PLC_BEEP_VOLUME 5435
extern u_int8_t PLC_BEEP_VOLUME;	/* Beep volume (when buzzerOn) */
int doWrite_PLC_BEEP_VOLUME(u_int8_t value);
int addWrite_PLC_BEEP_VOLUME(u_int8_t value);
int getStatus_PLC_BEEP_VOLUME(void);

#define ID_PLC_TOUCH_VOLUME 5436
extern u_int8_t PLC_TOUCH_VOLUME;	/* Touch volume */
int doWrite_PLC_TOUCH_VOLUME(u_int8_t value);
int addWrite_PLC_TOUCH_VOLUME(u_int8_t value);
int getStatus_PLC_TOUCH_VOLUME(void);

#define ID_PLC_ALARM_VOLUME 5437
extern u_int8_t PLC_ALARM_VOLUME;	/* Alarm volume (when alarm) */
int doWrite_PLC_ALARM_VOLUME(u_int8_t value);
int addWrite_PLC_ALARM_VOLUME(u_int8_t value);
int getStatus_PLC_ALARM_VOLUME(void);

#define ID_PLC_BUZZER 5438
extern u_int32_t PLC_BUZZER;	/* Enable dynamic buzzer sound (0x44332211 up=0x11(%) on=0x22(cs) off=0x33(cs) rep=0x44(times)) */
int doWrite_PLC_BUZZER(u_int32_t value);
int addWrite_PLC_BUZZER(u_int32_t value);
int getStatus_PLC_BUZZER(void);

#ifdef __cplusplus
}
#endif
#endif
