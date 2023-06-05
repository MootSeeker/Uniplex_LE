/*
 * handler.h
 *
 *  Created on: 05.06.2023
 *      Author: kevin
 */

#ifndef INC_HANDLER_H_
#define INC_HANDLER_H_

#define QUEUE_SIZE_MAX	( 100 )


typedef enum
{
	TASK_DO_MEAUREMENT,
	TASK_SAVE_MEASUREMENT,
	TASK_GO_TO_SLEEP,
	TASK_SHOW_DISPLAY,
}enTaskHandle;

typedef enum
{
	TASK1,
	TASK2,
	TASK_NFC,
	TASK_EMPTY, 	// No Task available
}enTaskId;

typedef enum
{
	LINE_EMPTY,
	LINE_FULL,
}enLineState;

typedef struct
{
	enTaskId task_id;
	enTaskId task_latest;
}st_task;

typedef struct
{
	st_task line[QUEUE_SIZE_MAX];
	int8_t line_start;
	int8_t line_end;
}st_line;

extern st_line gst_line;
extern st_task gst_task;


void handler_init( void );
void handler_line( void );
void handler_add_task( void );
enTaskId handler_rem_task( enTaskId task );
enLineState handler_isLineEmpty( void );
enLineState handler_isLineFull( void );
enTaskId handler_getTask( st_task );

#endif /* INC_HANDLER_H_ */
