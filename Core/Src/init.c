/**
 * @file   init.c
 *
 * @brief  	Brief description of the content of init.c
 * @author 	kevin, Juventus Techniker Schule
 * @date   	03.06.2023 - first implementation
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
 * Copyright (c) 2023 Juventus Techniker Schule
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


// .............................................................................
/**
 * @brief 	System initialization
 *
 * @param 	none
 * @retval 	HAL status
 */
HAL_StatusTypeDef init_sys( void )
{
	// Local variables
	HAL_StatusTypeDef state = HAL_OK;  // HAL status flag
	uint8_t  ok     = FALSE;
	uint8_t  repeat = 0;
	uint32_t reset  = 0;

	// Get initial tick if debug is enabled
	#ifdef DEBUG_ON
	uint32_t init_time = HAL_GetTick( );
	#endif

	// Define structure pointers

	// Store the reason for the restart
	reset = RCC->CSR;

	// Enable Low Power mode
	HAL_PWREx_EnableLowPowerRunMode( );

    // Enable FPU settigs ...................................................................................
	#if(__FPU_PRESENT == 1) && (__FPU_USED == 1)
    SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2)); /* set CP10 and CP11 Full Access */
    uint32_t fpu = SCB_GetFPUType();
	#endif

    // Print debug information ..............................................................................
	#ifdef DEBUG_TERMINAL
    // Show Welcome Message
	debug_printf( WELCOME_MESSAGE );

	// Show Revision
	debug_printf( "-> FW-Revision: %d", REVISION );
	// Show reset source
	debug_printf( "-> Reset Value: %s", reset_cause_get_name(reset_get( )));
    // Show Clock Speed
    debug_printf( "-> Clock: %d", HAL_RCC_GetSysClockFreq() );
    // Print if FPU is enabled
    debug_printf( "-> FPU: %s", (fpu) ? "enabled" : "disabled");
    // Initialization starts here
    debug_printf( "\r\n-> Program started" );
	#endif

    // Start: Initialization .................................................................................

    // GPIO Init

    // Flash Init

    // RTC Init

    // Display Init

    // USB Communication

    // NFC Communication

    // Bluetooth Communication

    // Probe Init

    // Data Management Init

    // Interrupt management

    // Power management init ............................................................
    power_init( );

    // END: Initialization ...................................................................................

    // Print init information ................................................................................
	#ifdef DEBUG_TERMINAL
	// Print time it took
	debug_printf("--> Initialization time: %lu ms", HAL_GetTick( ) - init_time);
	// Initialization OK
	debug_printf( "-> Hardware initialized\r\n" );
	#endif

	// Retrun init value to system
	return state;
}
