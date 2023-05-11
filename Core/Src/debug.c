/**
 * @file   debug.c
 *
 * @brief  	Brief description of the content of debug.c
 * @author 	mootseeker
 * @date   	May 10, 2023 - first implementation
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

#include <stdarg.h>

	/*
	 * ATTENTION
	 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	 * - For STM32-IDE: To use float values with "printf_debug", you have to select "Use float with printf
	 *   from newlib-nano" under Project -> Properties -> C/C++ Build -> Settings -> Tool Settings
	 *
	 * - Select the right UART in the header file: &huart1, ....
	 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	 */
 
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

 // ********************************************************************************
 /**
 * @brief  Static functions definitions
 *
 * Definition area for the module-specific functions (static) previously defined within "Static function
 * prototypes"
 */

 // ********************************************************************************
 /**
 * @brief  Global functions definitions
 *
 * Definition area for the global functions previously defined within "Global function prototypes"
 */

// ...........................................................................................
/**
 * @brief  Debug function: Similar to the printf command for data output via UART interface
 * @note  Selecte right UART interface
 * @param  List of parameters, same as in printf function
 * @retval none
 */
void debug_printf( const char *format, ... )
{
	// Local variables
	char buffer[ DEBUG_STRING_LEN_MAX ];  // Buffer size with reserve place
	int16_t no = 0;
	va_list args;

	// Read arguments in <format>
	va_start( args, format );

	// Execute vsnprintf function -> returns number of characters in buffer
	no = vsnprintf( buffer, DEBUG_STRING_LEN_MAX, format, args );

	// Check number of characters and if CR LF is selected
	if ( no >= 0 )
	{
		// Check numbers of characters and attach <CR>, <LF> and <\0>
		if ( no <= DEBUG_STRING_LEN_MAX - 3 )
		{
			buffer[ no++ ] = '\n';  // <LF> (0x0A)
			buffer[ no++ ] = '\r';  // <CR> (0x0D)
			buffer[ no ] = '\0';  // End of string (0x00)
		}
		else
		{
			buffer[ DEBUG_STRING_LEN_MAX - 3 ] = '\n';  // <LF> (0x0A)
			buffer[ DEBUG_STRING_LEN_MAX - 2 ] = '\r';  // <CR> (0x0D)
			buffer[ DEBUG_STRING_LEN_MAX - 1 ] = '\0';  // End of string (0x00)
		}
	}
	else
	{
		// An error occured executing vsnprintf
		sprintf( buffer, "Error in function printf_debug (debug.c)\r\n" );
		no = 42;  // Length of error text
	}
	va_end( args );  // Ends argument list

	// Send debug string over selected UART <-> UART1
	HAL_UART_Transmit( &huart2, ( uint8_t* ) buffer, no, 100 ); // Timeout = 10ms

} // End: debug_printf


//...........................................................................................................
/**
 * @brief  Debug function: Similar to the printf command for data output via UART interface
 * @note   - Select right UART interface
 * @note   - Without Carriage Return and Line Feed at the end
 * @param  List of parameters, same as in printf function
 * @retval none
 */
void debug_printf_without_cr_lf( const char *format, ... )
{
	// Local variables
	char buffer[ DEBUG_STRING_LEN_MAX ];  // Buffer size with reserve place
	int16_t no = 0;
	va_list args;

	// Read arguments in <format>
	va_start( args, format );

	// Execute vsnprintf function -> returns number of characters in buffer
	no = vsnprintf( buffer, DEBUG_STRING_LEN_MAX, format, args );
	// Check number of characters
	if ( no < 0 )
	{
		// An error occured executing vsnprintf
		sprintf( buffer, "Error in function printf_debug (debug.c)\r\n" );
		no = 42;  // Length of error text
	}
	va_end( args );  // Ends argument list

	// Send debug string over selected UART <-> UART1
	HAL_UART_Transmit( &huart2, ( uint8_t* ) buffer, no, 10 ); // Timeout = 10ms

} // End: debug_printf_without_cr_lf
