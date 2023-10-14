#include "StdTypes.h"
#include "DIO/DIO_Inteface.h"
#include "KeyPad/KeyPad_Cfg.h"

u8 keys[ROWS][COLS]={{'7','8','9','/'},{'4','5','6','*'},
{'1','2','3','-'},{'N','0','=','+'}};

DIO_Pin_type Rows_pins[ROWS]={PINC6,PINC7,PINB0,PINB1};

DIO_Pin_type Cols_pins[COLS]={PINC2,PINC3,PINC4,PINC5};


