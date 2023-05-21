/*
 * at25qf128a.h
 *
 *  Created on: May 19, 2023
 *      Author: kevin
 */

#ifndef INC_AT25QF128A_H_
#define INC_AT25QF128A_H_

//...........................................................................................................
/**
 * @brief  FLASH page size
 */
#define FLASH_PAGE_256              256  // FLASH page size (256 byte)

//...........................................................................................................
/**
 * @brief  Initialization commands for FLASH AT45DB021E (128kbyte, 256 page size)
 */
#define FLASH_INIT_1               0x3D  // Byte 1
#define FLASH_INIT_2               0x2A  // Byte 2
#define FLASH_INIT_3               0x80  // Byte 3
#ifdef FLASH_PAGE_256
  #define FLASH_INIT_4             0xA6  // Byte 4 for 256 byte/page
  #define FLASH_P_SIZE              256  // Page size 256 bytes
#else
  #define FLASH_INIT_4             0xA7  // Byte 4 for 264 byte/page
  #define FLASH_P_SIZE              264  // Page size 264 byte
#endif

/**
  * @brief  N25Q128A Configuration
  */
#define N25Q128A_FLASH_SIZE                  0x1000000 /* 128 MBits => 16MBytes */
#define N25Q128A_SECTOR_SIZE                 0x10000   /* 256 sectors of 64KBytes */
#define N25Q128A_SUBSECTOR_SIZE              0x1000    /* 4096 subsectors of 4kBytes */
#define N25Q128A_PAGE_SIZE                   0x100     /* 65536 pages of 256 bytes */

#define N25Q128A_DUMMY_CYCLES_READ           8
#define N25Q128A_DUMMY_CYCLES_READ_QUAD      10

#define FLASH_TOUT_CE         250000
#define FLASH_TOUT_SE       3000
#define FLASH_TOUT_BE    800

/**
  * @brief  N25Q128A Commands
  */
/* Reset Operations */
#define RESET_ENABLE_CMD                     0x66
#define RESET_MEMORY_CMD                     0x99

/* Identification Operations */
#define READ_ID_CMD                          0x9E
#define FLASH_DEVICE_INFO                         0x9F
#define MULTIPLE_IO_READ_ID_CMD              0xAF
#define READ_SERIAL_FLASH_DISCO_PARAM_CMD    0x5A

/* Read Operations */
#define FLASH_READ_PAGE                      0x03
#define FAST_READ_CMD                        0x0B
#define DUAL_OUT_FAST_READ_CMD               0x3B
#define DUAL_INOUT_FAST_READ_CMD             0xBB
#define QUAD_OUT_FAST_READ_CMD               0x6B
#define QUAD_INOUT_FAST_READ_CMD             0xEB

/* Write Operations */
#define WRITE_ENABLE_CMD                     0x06
#define WRITE_DISABLE_CMD                    0x04

/* Register Operations */
#define FLASH_READ_STATUS                  0x05
#define WRITE_STATUS_REG_CMD                 0x01

#define READ_LOCK_REG_CMD                    0xE8
#define WRITE_LOCK_REG_CMD                   0xE5

#define READ_FLAG_STATUS_REG_CMD             0x70
#define CLEAR_FLAG_STATUS_REG_CMD            0x50

#define READ_NONVOL_CFG_REG_CMD              0xB5
#define WRITE_NONVOL_CFG_REG_CMD             0xB1

#define READ_VOL_CFG_REG_CMD                 0x85
#define WRITE_VOL_CFG_REG_CMD                0x81

#define READ_ENHANCED_VOL_CFG_REG_CMD        0x65
#define WRITE_ENHANCED_VOL_CFG_REG_CMD       0x61

/* Program Operations */
#define FLASH_WRITE_PAGE                     0x02
#define DUAL_IN_FAST_PROG_CMD                0xA2
#define EXT_DUAL_IN_FAST_PROG_CMD            0xD2
#define QUAD_IN_FAST_PROG_CMD                0x32
#define EXT_QUAD_IN_FAST_PROG_CMD            0x12

/* Erase Operations */
#define SUBSECTOR_ERASE_CMD                  0x20
#define SECTOR_ERASE_CMD                     0xD8
#define BULK_ERASE_CMD                       0xC7

#define PROG_ERASE_RESUME_CMD                0x7A
#define PROG_ERASE_SUSPEND_CMD               0x75

/* One-Time Programmable Operations */
#define READ_OTP_ARRAY_CMD                   0x4B
#define PROG_OTP_ARRAY_CMD                   0x42

/**
  * @brief  N25Q128A Registers
  */
/* Status Register */
#define N25Q128A_SR_WIP                      ((uint8_t)0x01)    /*!< Write in progress */
#define N25Q128A_SR_WREN                     ((uint8_t)0x02)    /*!< Write enable latch */
#define N25Q128A_SR_BLOCKPR                  ((uint8_t)0x5C)    /*!< Block protected against program and erase operations */
#define N25Q128A_SR_PRBOTTOM                 ((uint8_t)0x20)    /*!< Protected memory area defined by BLOCKPR starts from top or bottom */
#define N25Q128A_SR_SRWREN                   ((uint8_t)0x80)    /*!< Status register write enable/disable */

/* Nonvolatile Configuration Register */
#define N25Q128A_NVCR_LOCK                   ((uint16_t)0x0001) /*!< Lock nonvolatile configuration register */
#define N25Q128A_NVCR_DUAL                   ((uint16_t)0x0004) /*!< Dual I/O protocol */
#define N25Q128A_NVCR_QUAB                   ((uint16_t)0x0008) /*!< Quad I/O protocol */
#define N25Q128A_NVCR_RH                     ((uint16_t)0x0010) /*!< Reset/hold */
#define N25Q128A_NVCR_ODS                    ((uint16_t)0x01C0) /*!< Output driver strength */
#define N25Q128A_NVCR_XIP                    ((uint16_t)0x0E00) /*!< XIP mode at power-on reset */
#define N25Q128A_NVCR_NB_DUMMY               ((uint16_t)0xF000) /*!< Number of dummy clock cycles */

/* Volatile Configuration Register */
#define N25Q128A_VCR_WRAP                    ((uint8_t)0x03)    /*!< Wrap */
#define N25Q128A_VCR_XIP                     ((uint8_t)0x08)    /*!< XIP */
#define N25Q128A_VCR_NB_DUMMY                ((uint8_t)0xF0)    /*!< Number of dummy clock cycles */

/* Enhanced Volatile Configuration Register */
#define N25Q128A_EVCR_ODS                    ((uint8_t)0x07)    /*!< Output driver strength */
#define N25Q128A_EVCR_VPPA                   ((uint8_t)0x08)    /*!< Vpp accelerator */
#define N25Q128A_EVCR_RH                     ((uint8_t)0x10)    /*!< Reset/hold */
#define N25Q128A_EVCR_DUAL                   ((uint8_t)0x40)    /*!< Dual I/O protocol */
#define N25Q128A_EVCR_QUAD                   ((uint8_t)0x80)    /*!< Quad I/O protocol */

/* Flag Status Register */
#define N25Q128A_FSR_PRERR                   ((uint8_t)0x02)    /*!< Protection error */
#define N25Q128A_FSR_PGSUS                   ((uint8_t)0x04)    /*!< Program operation suspended */
#define N25Q128A_FSR_VPPERR                  ((uint8_t)0x08)    /*!< Invalid voltage during program or erase */
#define N25Q128A_FSR_PGERR                   ((uint8_t)0x10)    /*!< Program error */
#define N25Q128A_FSR_ERERR                   ((uint8_t)0x20)    /*!< Erase error */
#define N25Q128A_FSR_ERSUS                   ((uint8_t)0x40)    /*!< Erase operation suspended */
#define N25Q128A_FSR_READY                   ((uint8_t)0x80)    /*!< Ready or command in progress */

#define FLASH_DUMMY                0x00  // Dummy byte

//...........................................................................................................
/**
 * @brief  Macros for chip select pin
 */
// Macro: Set nFLASH_CS active low
#define mFLASH_CS_ON    ( HAL_GPIO_WritePin( FLASH_CS_GPIO_Port, FLASH_CS_Pin, GPIO_PIN_RESET) )
// Macro: Set nFLASH_CS inactive high
#define mFLASH_CS_OFF   ( HAL_GPIO_WritePin( FLASH_CS_GPIO_Port, FLASH_CS_Pin, GPIO_PIN_SET) )

//...........................................................................................................
/**
 * @brief  FLASH AT45DB021E RDY/BUSY bit mask
 */
#define FLASH_READ_BUSY_BIT        0x80  // RDY/BUSY bit mask

//...........................................................................................................
/**
 * @brief  Enumeration of different FLASH actions
*/
typedef enum {
    FLASH_NONE  = 0,  // Don't do any FLASH command
    FLASH_READ  = 1,  // Execute FLASH Read Page command
    FLASH_WRITE = 2,  // Execute FLASH Write Page command
} enFLASH_FUNCTION;

//...........................................................................................................
/**
 * @brief  Enumeration of different FLASH errors
*/
typedef enum {
    FLASH_OK        = 0,  // No error
    FLASH_ERROR     = 1,  // An error occurred
    FLASH_TIMEOUT   = 2,  // A timeout error occurred
    FLASH_SPI_ERROR = 3,  // A SPI error occurred
    FLASH_CRC_ERROR = 4,  // CRC error occurred
} enFLASH_ERRORS;

//...........................................................................................................
/**
 * @brief  Enumeration erase page after reading YES or NO
*/
typedef enum {
	FLASH_ERASE_NO  = 0,  // Don't erase page
	FLASH_ERASE_YES = 1,  // Erase page
} enFLASH_ERASE;

//...........................................................................................................
/**
 * @brief  Enumeration number of bits (read/write)
*/
typedef enum {
	BITS_8  = 0,  // 1 byte
	BITS_16 = 1,  // 2 bytes
	BITS_32 = 2,  // 4 bytes
} enFLASH_BITS;

//...........................................................................................................
/**
 * @brief  Enumeration enable/disable CRC-calc after reading page
*/
typedef enum {
	FLASH_CRC_CALC_DISABLE,  // 0:
	FLASH_CRC_CALC_ENABLE,   // 1:
} enFLASH_CRC;

//...........................................................................................................
/**
 * @brief  Structure for FLASH data access
*/
typedef struct {
    uint8_t  flash_data[FLASH_P_SIZE];  // Data array for flash data (read or write)
    uint8_t  value8;
    uint16_t value16;
} st_flash;

//...........................................................................................................
/**
 * @brief  Structure for FLASH status bits
*/
typedef struct {
    union {
        uint8_t status;   // Status register byte 1
        struct {
            uint8_t page_size   : 1;  // Page size configuration  ( 0 = 264 bytes, 1 = 256 bytes )
            uint8_t protect     : 1;  // Sector protection state  ( 0 = disabled, 1 = enabled )
            uint8_t density     : 4;  // Density code             ( 0101 = 2-Mbit, 0111 = 4-Mbit )
            uint8_t comp        : 1;  // Compare result           ( 0 = match, 1 = do not match )
            uint8_t ready_busy  : 1;  // RDY/BUSY state           ( 0 = busy, 1 = ready )
        } bits;
    } byte_1;
    union {
        uint8_t status;   // Status register byte 2
        struct {
            uint8_t res1        : 3;  // Reserved
            uint8_t sle         : 1;  // Sector lockdown enabled ( 0 = disabled, 1 = enabled )
            uint8_t res2        : 1;  // Reserved
            uint8_t epe         : 1;  // Erase/program error    ( 0 = no error detected, 1 = error detected )
            uint8_t res3        : 1;  // Reserved
            uint8_t rdy         : 1;  // RDY/BUSY state          ( 0 = busy, 1 = ready )
        } bits;
    } byte_2;
} st_flash_state;

//...........................................................................................................
/**
 * @brief  Extern declaration of the global structure "gst_flash"
*/
extern st_flash  gst_flash;



#endif /* INC_AT25QF128A_H_ */
