/*!
 *****************************************************************************
 * @file:    adi_gpio_def_v1.h
 * @brief:   GPIO Device Driver definition
 * @version: $Revision: 33205 $
 * @date:    $Date: 2016-01-11 05:46:07 -0500 (Mon, 11 Jan 2016) $
 *****************************************************************************
Copyright (c) 2010-2014 Analog Devices, Inc.

All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
  - Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.
  - Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
  - Modified versions of the software must be conspicuously marked as such.
  - This software is licensed solely and exclusively for use with processors
    manufactured by or for Analog Devices, Inc.
  - This software may not be combined or merged with other code in any manner
    that would cause the software to become subject to terms and conditions
    which differ from those listed here.
  - Neither the name of Analog Devices, Inc. nor the names of its
    contributors may be used to endorse or promote products derived
    from this software without specific prior written permission.
  - The use of this software may or may not infringe the patent rights of one
    or more patent holders.  This license does not release you from the
    requirement that you obtain separate licenses from these patent holders
    to use this software.

THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES, INC. AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-
INFRINGEMENT, TITLE, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ANALOG DEVICES, INC. OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, PUNITIVE OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, DAMAGES ARISING OUT OF
CLAIMS OF INTELLECTUAL PROPERTY RIGHTS INFRINGEMENT; PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

*****************************************************************************/
#ifndef _ADI_GPIO_DEF_V1_H_
#define _ADI_GPIO_DEF_V1_H_
/*! \cond PRIVATE */

/* GPIO power-up default register values */
#define ADI_GPIO_DEFAULT_CON  (0u)    /*!< configuration register */
#define ADI_GPIO_DEFAULT_OEN  (0u)    /*!< output enable register */

/* GPIO pull-up/poll-down */
#define ADI_GPIO_DEFAULT_PE   (0u)    /*!< pull-enable register   */


#define ADI_GPIO_DEFAULT_POL  (0u)    /*!< interrupt polarity     */
#define ADI_GPIO_DEFAULT_ENA  (0u)    /*!< interrupt A enable     */
#define ADI_GPIO_DEFAULT_ENB  (0u)    /*!< interrupt B enable     */
#define ADI_GPIO_DEFAULT_STAT (0xFFu) /*!< interrupt status       */

/*! local enum for callback table indexing */
typedef enum
{
    /* Dedicated external pin interrupts... */
    ADI_GPIO_IRQ_EXT0_INDEX       = (0x0),   /*!< External interrupt 0.    */
    ADI_GPIO_IRQ_EXT1_INDEX       = (0x1),   /*!< External interrupt 1.    */
    ADI_GPIO_IRQ_EXT2_INDEX       = (0x2),   /*!< External interrupt 2.    */
    ADI_GPIO_IRQ_EXT3_INDEX       = (0x3),   /*!< External interrupt 3.    */

    /* Group interrupts */
    ADI_GPIO_IRQ_GROUPA_INDEX     = (0x4),   /*!< GroupA interrupt index.   */
    ADI_GPIO_IRQ_GROUPB_INDEX     = (0x5),   /*!< GroupB interrupt index.   */

    ADI_GPIO_NUM_INTERRUPTS       = (0x6),   /*!< Number of GPIO interrupts */

} ADI_GPIO_IRQ_INDEX;


/* General macros */
#define ADI_GPIO_EIxCFG_SHIFT_COUNT (2) /*!< number of bits to shift for each interrupt */

/*! Structure to hold callback function and parameter */
typedef struct _ADI_GPIO_CALLBACK_INFO
{
    ADI_CALLBACK         pfCallback;    /*!< Callback function pointer */
    void                 *pCBParam;      /*!< Callback parameter */
} ADI_GPIO_CALLBACK_INFO;

/*! Structure to hold callback function and parameter */
typedef struct _ADI_GPIO_DEV_DATA
{
    int32_t                 ReferenceCount;                          /*!< initialization state                  */
    ADI_GPIO_CALLBACK_INFO  CallbackTable[ADI_GPIO_NUM_INTERRUPTS];  /*!< Callback Info for External interrupts */
} ADI_GPIO_DEV_DATA;

/*! \struct ADI_GPIO_DEVICE

    GPIO instance data

    This structure contains the "state" information for the
    instance of the device.  For GPIO there is only one
    of these objects.
*/
typedef struct _ADI_GPIO_DRIVER_STRUCT
{
	ADI_GPIO_TypeDef            *pReg[ADI_GPIO_NUM_PORTS];          /*!< GPIO Ports Register base          */
	ADI_GPIO_DEV_DATA           *pData;                             /*!< Pointer to device data            */
} ADI_GPIO_DRIVER_STRUCT;


/* alias for the actual device structure */
typedef ADI_GPIO_DRIVER_STRUCT      ADI_GPIO_DRIVER;
/*! \endcond */
#endif /* _ADI_GPIO_DEF_V1_H_ */
