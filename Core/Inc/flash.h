/*
 * flash.h
 *
 *  Created on: 21.05.2023
 *      Author: kevin
 */

#ifndef INC_FLASH_H_
#define INC_FLASH_H_


#define W25QXX_MANUFACTURER_GIGADEVICE 0xC8
#define W25QXX_MANUFACTURER_WINBOND 0xEF

//...........................................................................................................
/**
 * @brief  Definitions for FLASH memory addresses for the bootloader and application data (STM32L431CCT6)
 *
 *         Bootloader data start from FLASH address        0x0001 0000
 *         Firmware update data start from FLASH address   0x0001 8000  // TODO >>>> adapt, if necessary
 */
// FLASH address for bootloader code (0x0000 FF00)
#define F_BOOT_CODE_PAGE            255

// Maximal numbers of firmware pages @ 256 bytes (bootloader + application)
#define F_MAX_FW_PAGES             1024

// FLASH page start address for bootloader data
#define F_BOOT_PAGE                 256

// Numbers of FLASH pages for bootloader data (256 bytes each)
#define F_BOOT_PAGE_NO              128  //// TODO >>>> adapt, if necessary

// FLASH page start address for application data
#define F_APP_PAGE               ( F_BOOT_PAGE + F_BOOT_PAGE_NO )

// Maximal numbers of pages for application data (256 bytes each)
#define F_APP_PAGE_NO            ( F_MAX_FW_PAGES - F_BOOT_PAGE_NO )  //// TODO >>>> adapt, if necessary

// Code for new firmware available
#define FW_UPDATE_CODE           0x55AA

//...........................................................................................................
/**
 * @brief  Macros for chip select pin
 */
// Macro: Set FLASH_CS active low
#define mFLASH_CS_ON    ( HAL_GPIO_WritePin( FLASH_CS_GPIO_Port, FLASH_CS_Pin, GPIO_PIN_RESET ))
// Macro: Set FLASH_CS inactive high
#define mFLASH_CS_OFF   ( HAL_GPIO_WritePin( FLASH_CS_GPIO_Port, FLASH_CS_Pin, GPIO_PIN_SET ))

//...........................................................................................................
/**
 * @brief  Definitions and macros for FLASH memory addresses and pages
 */

/**
 * @brief  FLASH addresses for all data
 */
#define F_FACTORY_PAGE                0  // FLASH page for factory data
#define F_PROPERTY_PAGE               1  // FLASH page for properties data
#define F_INTERNAL_PAGE               2  // FLASH page for internal data
#define F_CRC_PAGE                  254  // FLASH page for CRC values

/**
 * @brief  FLASH addresses for CRC values
 */
#define F_PROP_CRC_ADDR           ( (F_CRC_PAGE * FLASH_P_SIZE) + 0x0000 )  // FLASH CRC value for properties data
#define F_FACT_CRC_ADDR           ( (F_CRC_PAGE * FLASH_P_SIZE) + 0x0004 )  // FLASH CRC value for properties data
//#define F_CRC_XY                 ( F_CRC_ADDR + 0x0004 )  // FLASH CRC value for XY data

//...........................................................................................................
/**
 * @brief  Enumeration of different FLASH errors
*/
typedef enum
{
	FLASH_OK, 			// 0: No Error occurred
	FLASH_ERROR, 		// 1: Error occurred
	FLASH_TIMEOUT,		// 2: Timeout occurred
    FLASH_SPI_ERROR,  	// 3: SPI error occurred
    FLASH_CRC_ERROR,  	// 4: CRC error occurred
}enFLASH_ERRORS;

//...........................................................................................................
/**
 * @brief  Enumeration erase page after reading YES or NO
*/
typedef enum
{
	FLASH_ERASE_NO  = 0,  // Don't erase page
	FLASH_ERASE_YES = 1,  // Erase page
} enFLASH_ERASE;

//...........................................................................................................
/**
 * @brief  Enumeration number of bits (read/write)
*/
typedef enum
{
	BITS_8  = 0,  // 1 byte
	BITS_16 = 1,  // 2 bytes
	BITS_32 = 2,  // 4 bytes
} enFLASH_BITS;

//...........................................................................................................
/**
 * @brief  Enumeration enable/disable CRC-calc after reading page
*/
typedef enum
{
	FLASH_CRC_CALC_DISABLE,  // 0:
	FLASH_CRC_CALC_ENABLE,   // 1:
} enFLASH_CRC;

//...........................................................................................................
/**
 * @brief  Enumeration flash type
*/
typedef enum
{
	W25Q10 = 1,
	W25Q20,
	W25Q40,
	W25Q80,
	W25Q16,
	W25Q32,
	W25Q64,
	W25Q128,
	W25Q256,		// Used version
	W25Q512,
}enFLASH_TYPE;

typedef struct
{

}st_flash;


extern st_flash gst_flash;





#endif /* INC_FLASH_H_ */
