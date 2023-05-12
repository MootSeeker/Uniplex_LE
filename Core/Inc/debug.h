/**
 * @file   debug.h
 *
 * @brief  	Brief description of the content of debug.h
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
 
#ifndef INC_DEBUG_H_
#define INC_DEBUG_H_

 // ********************************************************************************
 /**
 * @brief  Includes
 *
 * Section for module-specific include files
 * - Normally not necessary in header files
 */

 
 // ********************************************************************************
 /**
 * @brief  Macros
 *
 * Section for module-specific definitions (constants) and macros
 */

/**
 * @brief  Global release of debug information
 */
#define DEBUG_ON         // Global release of debug information

/**
 * @brief   Activate or deactivate different debug modes
 */
#ifdef DEBUG_ON
#define DEBUG_TERMINAL	   // Show debug project name
#endif

/**
 * @brief  Definitions for debug actions
 */
#define DEBUG_STRING_LEN_MAX   100  // Maximal length of debug character buffer


 
 // ********************************************************************************
 /**
 * @brief  Enumerations
 *
 * Section for module-specific enumerations
 */

/// @brief  Possible STM32 system reset causes
typedef enum
{
	RESET_CAUSE_UNKNOWN,
    RESET_CAUSE_LOW_POWER_RESET,
    RESET_CAUSE_WINDOW_WATCHDOG_RESET,
    RESET_CAUSE_INDEPENDENT_WATCHDOG_RESET,
    RESET_CAUSE_SOFTWARE_RESET,
    RESET_CAUSE_POWER_ON_POWER_DOWN_RESET,
    RESET_CAUSE_EXTERNAL_RESET_PIN_RESET,
    RESET_CAUSE_BROWNOUT_RESET,
} enReset_cause_t;

 
 // ********************************************************************************
 /**
 * @brief  Structures
 *
 * Section for module-specific structures
 */

 
 // ********************************************************************************
 /**
 * @brief  Global variables
 *
 * Section for module-specific global variables
 */

 
 // ********************************************************************************
 /**
 * @brief  Global function prototypes
 *
 * Section for module-specific global function prototypes
 */
 
/**
 * @brief  Debug function: Similar to the printf command for data output via UART interface
 * @note   - Select right UART interface!
 * @param  List of parameters, same as in printf function
 * @retval none
 */
void debug_printf( const char *format, ... );

/**
 * @brief  Debug function: Similar to the printf command for data output via UART interface
 * @note   - Select right UART interface!
 * @note   - Without Carriage Return and Line Feed at the end
 * @param  List of parameters, same as in printf function
 * @retval none
 */
void debug_printf_without_cr_lf( const char *format, ... );

/**
 * @brief  Debug function: Get Reason that reset occured
 * @note
 * @note
 * @param  none
 * @retval List of parameters, reasons
 */
enReset_cause_t reset_get( void );

/**
 * @brief  Obtain the system reset cause as an ASCII-printable name string
 * 		   from a reset cause type
 * @note
 * @param  reset_cause     The previously-obtained system reset cause
 * @retval A null-terminated ASCII name string describing the system reset cause
 */
const char * reset_cause_get_name(enReset_cause_t reset_cause);

 #endif /* END: debug.h */
