/*
 * handler.c
 *
 *  Created on: 05.06.2023
 *      Author: kevin
 */


#include "main.h"

st_line gst_line;
st_task gst_task;





void handler_init( void )
{
	// Local variables

	// Define struct pointer
	st_line *pst_line = &gst_line;

	// Clear Queue variables to empty
	pst_line->line_start = -1;
	pst_line->line_end = -1;
}


void handler_add_task( void )
{
	// Local variables

	// Define struct pointer
	st_line *pst_line = &gst_line;
	st_task *pst_task = &gst_task;

	// Check if Line is full
	if( LINE_FULL == handler_isLineFull( ))
	{
		debug_printf("LINE: \t Line is full, cannot add Task!");
		return; // Go out of function
	}
	else if( LINE_EMPTY == handler_isLineEmpty( )) // Reset Line if empty
	{
		pst_line->line_start = 0;
		pst_line->line_end = 0;
	}
	else // Line is not full and has one or more items
	{
		pst_line->line_end = ( pst_line->line_end + 1 ) % QUEUE_SIZE_MAX;
	}

	// Add new Task at the new end position
	pst_line->line[ pst_line->line_end ] = pst_task->task_id;
}


enTaskId handler_rem_task( enTaskId task )
{
	// Local variables
	enTaskId statId = TASK_EMPTY;	// return value to show state of Line

	// Define struct pointer
	st_line *pst_line = &gst_line;
	st_task *pst_task = &gst_task;

	// Check if Line empty
	if( LINE_EMPTY == handler_isLineEmpty( ))
	{
		debug_printf("LINE: \t Line is full, cannot add Task!");
		return statId; // No Task to delete
	}

	// Copy latest task
	pst_task->task_latest = pst_line->line[ pst_line->line_start ];

	// Check if all Tasks removed
	if( pst_line->line_start == pst_line->line_end )
	{
        // Last item in the queue to remove
        pst_line->line_start = -1;
        pst_line->line_end = -1;
	}
	else
	{
		pst_line->line_start = ( pst_line->line_start + 1 ) % QUEUE_SIZE_MAX;
	}

	return statId;
}

enLineState handler_isLineEmpty( void )
{
	st_line *pst_line = &gst_line;

	return (pst_line->line_start == -1 || pst_line->line_end == -1) ? LINE_EMPTY : LINE_FULL;
}

enLineState handler_isLineFull( void )
{
	st_line *pst_line = &gst_line;

	return ((pst_line->line_start + 1) % QUEUE_SIZE_MAX == pst_line->line_start) ? LINE_FULL : LINE_EMPTY;
}


