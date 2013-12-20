#ifndef __SIGNAL_TAP_H__
#define __SIGNAL_TAP_H__

#define ST_ID_VENDOR  0x04b4
#define ST_ID_PRODUCT 0x1004

/** start to capture the signal */
#define ST_CMD_START_CAP	0xD2
/** stop to capture the signal */
#define ST_CMD_STOP_CAP		0xD3
/** start to output the signal */
#define ST_CMD_START_OUT	0xD4
/** stop to output the signal */
#define ST_CMD_STOP_OUT		0xD5

int signal_cap(int sec, int type, char *fname);
int signal_out(char *fname);
#endif
