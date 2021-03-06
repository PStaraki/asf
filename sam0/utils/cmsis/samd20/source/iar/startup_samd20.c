/**
 * \file
 *
 * Copyright (c) 2015-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#include "samd20.h"

typedef void (*intfunc) (void);
typedef union { intfunc __fun; void * __ptr; } intvec_elem;

void __iar_program_start(void);
int __low_level_init(void);

void Dummy_Handler(void);
void Reset_Handler(void);

/* Cortex-M0+ core handlers */
void NMI_Handler              ( void );
void HardFault_Handler        ( void );
void SVC_Handler              ( void );
void PendSV_Handler           ( void );
void SysTick_Handler          ( void );

/* Peripherals handlers */
void PM_Handler               ( void );
void SYSCTRL_Handler          ( void );
void WDT_Handler              ( void );
void RTC_Handler              ( void );
void EIC_Handler              ( void );
void NVMCTRL_Handler          ( void );
void EVSYS_Handler            ( void );
void SERCOM0_Handler          ( void );
void SERCOM1_Handler          ( void );
void SERCOM2_Handler          ( void );
void SERCOM3_Handler          ( void );
void SERCOM4_Handler          ( void );
void SERCOM5_Handler          ( void );
void TC0_Handler              ( void );
void TC1_Handler              ( void );
void TC2_Handler              ( void );
void TC3_Handler              ( void );
void TC4_Handler              ( void );
void TC5_Handler              ( void );
void TC6_Handler              ( void );
void TC7_Handler              ( void );
void ADC_Handler              ( void );
void AC_Handler               ( void );
void DAC_Handler              ( void );
void PTC_Handler              ( void );

/* Cortex-M0+ core handlers */
#pragma weak NMI_Handler              = Dummy_Handler
#pragma weak HardFault_Handler        = Dummy_Handler
#pragma weak SVC_Handler              = Dummy_Handler
#pragma weak PendSV_Handler           = Dummy_Handler
#pragma weak SysTick_Handler          = Dummy_Handler

/* Peripherals handlers */
#pragma weak PM_Handler               = Dummy_Handler
#pragma weak SYSCTRL_Handler          = Dummy_Handler
#pragma weak WDT_Handler              = Dummy_Handler
#pragma weak RTC_Handler              = Dummy_Handler
#pragma weak EIC_Handler              = Dummy_Handler
#pragma weak NVMCTRL_Handler          = Dummy_Handler
#pragma weak EVSYS_Handler            = Dummy_Handler
#pragma weak SERCOM0_Handler          = Dummy_Handler
#pragma weak SERCOM1_Handler          = Dummy_Handler
#pragma weak SERCOM2_Handler          = Dummy_Handler
#pragma weak SERCOM3_Handler          = Dummy_Handler
#ifdef       ID_SERCOM4
#pragma weak SERCOM4_Handler          = Dummy_Handler
#endif
#ifdef       ID_SERCOM5
#pragma weak SERCOM5_Handler          = Dummy_Handler
#endif
#pragma weak TC0_Handler              = Dummy_Handler
#pragma weak TC1_Handler              = Dummy_Handler
#pragma weak TC2_Handler              = Dummy_Handler
#pragma weak TC3_Handler              = Dummy_Handler
#pragma weak TC4_Handler              = Dummy_Handler
#pragma weak TC5_Handler              = Dummy_Handler
#ifdef       ID_TC6
#pragma weak TC6_Handler              = Dummy_Handler
#endif
#ifdef       ID_TC7
#pragma weak TC7_Handler              = Dummy_Handler
#endif
#ifdef       ID_ADC
#pragma weak ADC_Handler              = Dummy_Handler
#endif
#ifdef       ID_AC
#pragma weak AC_Handler               = Dummy_Handler
#endif
#ifdef       ID_DAC
#pragma weak DAC_Handler              = Dummy_Handler
#endif
#ifdef       ID_PTC
#pragma weak PTC_Handler              = Dummy_Handler
#endif

/* Exception Table */
#pragma language = extended
#pragma segment  = "CSTACK"

/* The name "__vector_table" has special meaning for C-SPY: */
/* it is where the SP start value is found, and the NVIC vector */
/* table register (VTOR) is initialized to this address if != 0 */

#pragma section  = ".intvec"
#pragma location = ".intvec"
const DeviceVectors __vector_table[] = {
        __sfe("CSTACK"),
        (void*) Reset_Handler,
        (void*) NMI_Handler,
        (void*) HardFault_Handler,
        (void*) (0UL), /* Reserved */
        (void*) (0UL), /* Reserved */
        (void*) (0UL), /* Reserved */
        (void*) (0UL), /* Reserved */
        (void*) (0UL), /* Reserved */
        (void*) (0UL), /* Reserved */
        (void*) (0UL), /* Reserved */
        (void*) SVC_Handler,
        (void*) (0UL), /* Reserved */
        (void*) (0UL), /* Reserved */
        (void*) PendSV_Handler,
        (void*) SysTick_Handler,

        /* Configurable interrupts */
        (void*) PM_Handler,             /*  0 Power Manager */
        (void*) SYSCTRL_Handler,        /*  1 System Control */
        (void*) WDT_Handler,            /*  2 Watchdog Timer */
        (void*) RTC_Handler,            /*  3 Real-Time Counter */
        (void*) EIC_Handler,            /*  4 External Interrupt Controller */
        (void*) NVMCTRL_Handler,        /*  5 Non-Volatile Memory Controller */
        (void*) EVSYS_Handler,          /*  6 Event System Interface */
        (void*) SERCOM0_Handler,        /*  7 Serial Communication Interface 0 */
        (void*) SERCOM1_Handler,        /*  8 Serial Communication Interface 1 */
        (void*) SERCOM2_Handler,        /*  9 Serial Communication Interface 2 */
        (void*) SERCOM3_Handler,        /* 10 Serial Communication Interface 3 */
#ifdef ID_SERCOM4
        (void*) SERCOM4_Handler,        /* 11 Serial Communication Interface 4 */
#else
        (void*) (0UL), /* Reserved*/
#endif
#ifdef ID_SERCOM5
        (void*) SERCOM5_Handler,        /* 12 Serial Communication Interface 5 */
#else
        (void*) (0UL), /* Reserved*/
#endif
        (void*) TC0_Handler,            /* 13 Basic Timer Counter 0 */
        (void*) TC1_Handler,            /* 14 Basic Timer Counter 1 */
        (void*) TC2_Handler,            /* 15 Basic Timer Counter 2 */
        (void*) TC3_Handler,            /* 16 Basic Timer Counter 3 */
        (void*) TC4_Handler,            /* 17 Basic Timer Counter 4 */
        (void*) TC5_Handler,            /* 18 Basic Timer Counter 5 */
#ifdef ID_TC6
        (void*) TC6_Handler,            /* 19 Basic Timer Counter 6 */
#else
        (void*) (0UL), /* Reserved*/
#endif
#ifdef ID_TC7
        (void*) TC7_Handler,            /* 20 Basic Timer Counter 7 */
#else
        (void*) (0UL), /* Reserved*/
#endif
#ifdef ID_ADC
        (void*) ADC_Handler,            /* 21 Analog Digital Converter */
#else
        (void*) (0UL), /* Reserved*/
#endif
#ifdef ID_AC
        (void*) AC_Handler,             /* 22 Analog Comparators */
#else
        (void*) (0UL), /* Reserved*/
#endif
#ifdef ID_DAC
        (void*) DAC_Handler,            /* 23 Digital Analog Converter */
#else
        (void*) (0UL), /* Reserved*/
#endif
#ifdef ID_PTC
        (void*) PTC_Handler             /* 24 Peripheral Touch Controller */
#else
        (void*) (0UL)  /* Reserved*/
#endif
};

/**------------------------------------------------------------------------------
 * This is the code that gets called on processor reset. To initialize the
 * device.
 *------------------------------------------------------------------------------*/
int __low_level_init(void)
{
        uint32_t *pSrc = __section_begin(".intvec");

        SCB->VTOR = ((uint32_t) pSrc & SCB_VTOR_TBLOFF_Msk);

        return 1; /* if return 0, the data sections will not be initialized */
}

/**------------------------------------------------------------------------------
 * This is the code that gets called on processor reset. To initialize the
 * device.
 *------------------------------------------------------------------------------*/
void Reset_Handler(void)
{
        /* Overwriting the default value of the NVMCTRL.CTRLB.MANW bit (errata reference 13134) */
        NVMCTRL->CTRLB.bit.MANW = 1;

        __iar_program_start();
}

/**
 * \brief Default interrupt handler for unused IRQs.
 */
void Dummy_Handler(void)
{
        while (1) {
        }
}
