/**
 * @file   power.c
 *
 * @brief  	Brief description of the content of power.c
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


void power_init( void )
{
	// Local variables

	// Disable battery charging module
	HAL_PWREx_DisableBatteryCharging( );

	// Reduce System voltage
	HAL_PWREx_ControlVoltageScaling( PWR_REGULATOR_VOLTAGE_SCALE2 ); //Set system voltage to 1.0V

	// Disable SRAM2 Content Retention
	HAL_PWREx_DisableSRAM2ContentRetention( );

	// Disable voltage monitoring ...................................................................
	HAL_PWREx_DisablePVM1( );
	HAL_PWREx_DisablePVM3( );
	HAL_PWREx_DisablePVM4( );
}


