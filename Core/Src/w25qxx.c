/**
 * @file   w25qxx.c
 *
 * @brief  	Brief description of the content of w25qxx.c
 * @author 	mootseeker
 * @date   	19.05.2023 - first implementation
 * @version 1.0.0
 * 
 * MIT License
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Copyright (c) 2023 MootSeeker
 */
 
 // ********************************************************************************
 /**
 * @brief  Includes
 *
 * Section for module-specific include files
 * If all include files are inserted in main.h, only the file main.h must be included here
 */
 #include "main.h"
 
 // ******************************************************************************** 
 /**
 * @brief  Constant variables
 *
 * Section for module-specific constant variables (static) that are only valid within the module
 */
 
 // ********************************************************************************
 /**
 * @brief  Global variables
 *
 * Section for global variables
 */
 
st_w25qxx gst_w25qxx;

 // ********************************************************************************
 /**
 * @brief  Static variables
 *
 * Section for module-specific variables (static) that are only valid within the module
 */
 
 // ******************************************************************************** 
 /**
 * @brief  Static function prototypes
 *
 * Section for module-specific function prototypes (static) for functions that are only valid within the
 * module
 */

static W25QXX_ID_t w25qxx_get_id( void );

static W25QXX_result_t w25qxx_write( uint8_t *buf, uint32_t len );

 // ********************************************************************************
 /**
 * @brief  Static functions definitions
 *
 * Definition area for the module-specific functions (static) previously defined within "Static function
 * prototypes"
 */

static W25QXX_result_t w25qxx_write( uint8_t *buf, uint32_t len )
{
	// Local variables
	W25QXX_result_t ret = W25QXX_ERROR;

	// Transmit buffer
    if( HAL_SPI_Transmit( &hspi1, buf, len, 100 ) == HAL_OK )
    {
        ret = W25QXX_OK;
    }
    return ret;
}

static W25QXX_result_t w25qxx_read( uint8_t *buf, uint32_t len )
{
	// Local variables
	W25QXX_result_t ret = W25QXX_ERROR;

	// Receive data
	if( HAL_SPI_Receive( &hspi1, buf, len, FLASH_TIMEOUT ) == HAL_OK )
	{
		ret = W25QXX_OK;
	}
	return ret;
}



static W25QXX_ID_t w25qxx_get_id( void )
{
	W25QXX_ID_t ret = 0;
    uint8_t buf[3];

    // Set command
    buf[0] = W25QXX_GET_ID;

    // FLASH CS ON
    HAL_GPIO_WritePin( FLASH_CS_GPIO_Port, FLASH_CS_Pin, GPIO_PIN_RESET );

    if( w25qxx_write( buf, 1 ) == W25QXX_OK )
    {
        if( w25qxx_read( buf, 3 ) == W25QXX_OK )
        {
            ret = ( W25QXX_ID_t ) (( buf[ 0 ] << 16 ) | ( buf[ 1 ] << 8 ) | ( buf[ 2 ] ));
        }
    }

    // FLASH CS OFF
    HAL_GPIO_WritePin( FLASH_CS_GPIO_Port, FLASH_CS_Pin, GPIO_PIN_SET );

    return ret;
}

 // ********************************************************************************
 /**
 * @brief  Global functions definitions
 *
 * Definition area for the global functions previously defined within "Global function prototypes"
 */


W25QXX_result_t w25qxx_init( void )
{
	// Local variables
	W25QXX_result_t result = W25QXX_OK;
	W25QXX_ID_t id;

	// Get ID
	id = w25qxx_get_id( );


}
