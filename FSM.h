


#ifndef _FSM_H_
#define _FSM_H_

#define SET_FILTER_GAIN1    'f'
#define SET_FILTER_GAIN2    'F'


typedef enum {WAITING_CMD,PARAM1,PARAM2,RUN} FSM_STATE;

FSM_STATE FSM_State;

typedef struct{
    int16_t command;
    char param[3];
} COMMAND; 

COMMAND cmd;

void init_FSM() {
    FSM_State = WAITING;
    void init_Command(&cmd);
}

void init_Command(*COMMAND cmd) {
    cmd->command = 0;
    cmd->param[0] = '\0';
}

void setCommand(*COMMAND cmd, int16_t c) {
    
    if(VALIDCMD(c)) { 
        cmd->command = c;
        FSM_State = PARAM1;
    } else {
        FSM_State = WAITING_CMD;
        init_Command(&cmd);
    }
}

void setParam0(*COMMAND cmd, int16_t p) {
    cmd->param[0] = (char)p;
    cmd->param[1] = '\0';
    FSM_State = PARAM2;
}

void setParam1(*COMMAND cmd, int16_t p) {
    cmd->param[1] = (char)p;
    cmd->param[2] = '\0';
    FSM_State = RUN;
}

void processByte(int16_t rxbyte) {
    switch FSM_State {
    
    case WAITING_CMD:
        setCommand(&cmd, rxbyte);
    case PARAM1:
        setParam0(*COMMAND cmd, rxbyte);
    case PARAM2:
        setParam1(*COMMAND cmd, rxbyte);
    case RUN
        if(rxbyte == '\r') {
            init_Command(&cmd);
        }
    }
}

#endif

