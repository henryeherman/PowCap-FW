#ifndef _FSM_H_
#define _FSM_H_

#include <stdint.h>
#include <LUFA/Drivers/Board/LEDs.h>

#define GAIN1    'g'
#define GAIN2    'G'
#define NUMBER_CMDS 5

#define VALIDCMD(c) (((c)==(GAIN1)) || ((c)==(GAIN2)))
typedef enum {WAITING_CMD,PARAM1,PARAM2,RUN} FSM_STATE;

FSM_STATE FSM_State;

typedef struct{
    int16_t command;
    char param[3];
} COMMAND; 

COMMAND cmd;

typedef void(*CMD_CALLBK)(char *param);

typedef struct{
    int16_t id; 
    CMD_CALLBK fxn;
} CALLBACK;

CALLBACK cb_command[NUMBER_CMDS];

void init_callbacks(void);

void setup_callbacks(void);

int16_t search_callback(COMMAND *cmd);

void init_FSM(void);

void init_command(COMMAND *cmd); 

void set_command(COMMAND *cmd, int16_t c);

void set_param0(COMMAND *cmd, int16_t p);

void set_param1(COMMAND *cmd, int16_t p);

void process_byte(int16_t rxbyte);

#endif

