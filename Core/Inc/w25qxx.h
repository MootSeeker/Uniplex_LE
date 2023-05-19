/**
 * @file   w25qxx.h
 *
 * @brief  	Brief description of the content of w25qxx.h
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
 
#ifndef INC_W25QXX_H_
#define INC_W25QXX_H_

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

#define W25QXX_MANUFACTURER_GIGADEVICE 	0xC8
#define W25QXX_MANUFACTURER_WINBOND 	0xEF

#define W25QXX_DUMMY_BYTE         0xA5
#define W25QXX_GET_ID             0x9F
#define W25QXX_READ_DATA          0x03
#define W25QXX_WRITE_ENABLE       0x06
#define W25QXX_PAGE_PROGRAM       0x02
#define W25QXX_SECTOR_ERASE	      0x20
#define W25QXX_CHIP_ERASE         0xc7
#define W25QXX_READ_REGISTER_1    0x05

#define FLASH_TIMEOUT	100
 
 // ********************************************************************************
 /**
 * @brief  Enumerations
 *
 * Section for module-specific enumerations
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
	W25Q256,
	W25Q512,
} W25QXX_ID_t;


typedef enum
{
    W25QXX_OK,     	// 0
    W25QXX_ERROR,  	// 1
    W25QXX_TIMEOUT 	// 2
} W25QXX_result_t;


 
 // ********************************************************************************
 /**
 * @brief  Structures
 *
 * Section for module-specific structures
 */


typedef struct
{
	W25QXX_ID_t ID;
	uint8_t UniqID[8];
	uint16_t PageSize;
	uint32_t PageCount;
	uint32_t SectorSize;
	uint32_t SectorCount;
	uint32_t BlockSize;
	uint32_t BlockCount;
	uint32_t CapacityInKiloByte;
	uint8_t StatusRegister1;
	uint8_t StatusRegister2;
	uint8_t StatusRegister3;
	uint8_t Lock;
} st_w25qxx;



 
 // ********************************************************************************
 /**
 * @brief  Global variables
 *
 * Section for module-specific global variables
 */

extern st_w25qxx gst_w25qxx;
 
 // ********************************************************************************
 /**
 * @brief  Global function prototypes
 *
 * Section for module-specific global function prototypes
 */
 
W25QXX_result_t w25qxx_init( void );

 #endif /* END: w25qxx.h */
