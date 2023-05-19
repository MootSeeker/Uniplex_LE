/*
 * at25qf128a.c
 *
 *  Created on: May 19, 2023
 *      Author: kevin
 */


#include "main.h"

static void flash_ready_busy( uint16_t timeout, uint16_t delay )
{
	// Local variables
	uint8_t  state = HAL_OK;  // SPI flag
	uint16_t tcount = 0;      // Timeout counter
	uint8_t  lbuf_in[3];      // Input buffer

	// Define and initialize read status command
	uint8_t lbuf_out[] = { READ_STATUS_REG_CMD, FLASH_DUMMY, FLASH_DUMMY };

	do
	{
		// Check if a delay is used
		if( delay ) HAL_Delay( delay );  // wait for delay[ms]

		// Increment timeout counter and test it
		tcount++;
		if( tcount >= timeout ) return 1;

		// Read FLASH status information
		HAL_GPIO_WritePin( FLASH_CS_GPIO_Port, FLASH_CS_Pin, GPIO_PIN_RESET );
		// Send and receive data over SPI
		state = HAL_SPI_TransmitReceive( &hspi1, lbuf_out, lbuf_in, sizeof( lbuf_out ), 100 );
		HAL_GPIO_WritePin( FLASH_CS_GPIO_Port, FLASH_CS_Pin, GPIO_PIN_SET );

		// Check possible SPI error
		if( state ) return 1;

	} while( !(lbuf_in[1] & FLASH_READ_BUSY_BIT) );
}

void at25qf128a_get_id( void )
{
	// Local variables
	uint8_t  state = HAL_OK;  // SPI flag
	uint16_t i;

	// Define and initialize initialization command
	uint8_t lbuf_out[] = { READ_ID_CMD, 0x00, 0x00, 0x00 };


	uint8_t data_rc[4];
	//Set CS Pin
	HAL_GPIO_WritePin( FLASH_CS_GPIO_Port, FLASH_CS_Pin, GPIO_PIN_RESET );

	if( HAL_SPI_Transmit(&hspi1, (uint8_t *)lbuf_out, 4, 100) == HAL_OK )
	{
		HAL_SPI_Receive(&hspi1, data_rc, 1, 100);
	}

	HAL_GPIO_WritePin( FLASH_CS_GPIO_Port, FLASH_CS_Pin, GPIO_PIN_SET );

	// If no SPI error occurred, wait until RDY/BUSY bit of status register is set to READY
	if( state == HAL_OK ) flash_ready_busy( 3, 0 );

}
