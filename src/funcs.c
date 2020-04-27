/*
 * funcs.c
 *
 *  Created on: 04 Şub 2019
 *      Author: FATIH
 */
#include "funcs.h"

/***********************************************************************/
/* LED control in motor drive board                                    */
/* Arguments: Switch value, LED0: bit 0, LED1: bit 1. 0: dark, 1: lit  */
/* Example: 0x3 -> LED1: ON, LED0: ON, 0x2 -> LED1: ON, LED0: OFF      */
/***********************************************************************/
void led_out( unsigned char led )
{
    led = ~led;
    //PORT7.DR.BIT.B6 = led & 0x01;
    //PORT1.DR.BIT.B0 = ( led >> 1 ) & 0x01;
    PORTA.DR.BIT.B3 = GET_BIT(led, 3);
    PORTA.DR.BIT.B2 = GET_BIT(led, 2);
    PORTA.DR.BIT.B1 = GET_BIT(led, 1);
    PORTA.DR.BIT.B0 = GET_BIT(led, 0);
}

/*
 *
 *
 *  Masked value settings X:masked (disabled) O:not masked (enabled)
#define MASK2_2 0x66 // X O O X X O O X
#define MASK2_0 0x60 // X O O X X X X X
#define MASK0_2 0x06 // X X X X X O O X
#define MASK3_3 0xe7 // O O O X X O O O
#define MASK0_3 0x07 // X X X X X O O O
#define MASK3_0 0xe0 // O O O X X X X X
#define MASK4_0 0xf0 // O O O O X X X X
#define MASK0_4 0x0f // X X X X O O O O
#define MASK4_4 0xff // O O O O O O O O
*/


void System_Init(void)
{
    // System Clock
    SYSTEM.SCKCR.BIT.ICK = 0;               //12.288*8=98.304MHz
    SYSTEM.SCKCR.BIT.PCK = 1;               //12.288*4=49.152MHz

    // Port I/O Settings
    PORT1.DDR.BYTE = 0x03;                  //P10:LED2 in motor drive board

    PORT2.DR.BYTE  = 0x08;
    PORT2.DDR.BYTE = 0x1b;                  //P24:SDCARD_CLK(o)
                                            //P23:SDCARD_DI(o)
                                            //P22:SDCARD_DO(i)
                                            //CN:P21-P20
    PORT3.DR.BYTE  = 0x01;
    PORT3.DDR.BYTE = 0x0f;                  //CN:P33-P31
                                            //P30:SDCARD_CS(o)
    //PORT4:input                           //sensor input
    //PORT5:input
    //PORT6:input

    PORT7.DDR.BYTE = 0x7e;                  //P76:LED3 in motor drive board
                                            //P75:forward reverse signal(right motor)
                                            //P74:forward reverse signal(left motor)
                                            //P73:PWM(right motor)
                                            //P72:PWM(left motor)
                                            //P71:PWM(servo motor)
                                            //P70:Push-button in motor drive board
    PORT8.DDR.BYTE = 0x07;                  //CN:P82-P80
    PORT9.DDR.BYTE = 0x7f;                  //CN:P96-P90
    PORTA.DR.BYTE  = 0x0f;                  //CN:PA5-PA4
                                            //PA3:LED3(o)
                                            //PA2:LED2(o)
                                            //PA1:LED1(o)
                                            //PA0:LED0(o)
    PORTA.DDR.BYTE = 0x3f;                  //CN:PA5-PA0
    PORTB.DDR.BYTE = 0x00;  //00            //CN:PB7-PB0
    PORTD.DDR.BYTE = 0x0f;                  //PD7:TRST#(i)
                                            //PD5:TDI(i)
                                            //PD4:TCK(i)
                                            //PD3:TDO(o)
                                            //CN:PD2-PD0
    PORTE.DDR.BYTE = 0x1b;                  //PE5:SW(i)
                                            //CN:PE4-PE0

    // Compare match timer
    MSTP_CMT0 = 0;                          //CMT Release module stop state
    MSTP_CMT2 = 0;                          //CMT Release module stop state

    ICU.IPR[0x04].BYTE  = 0x0f;             //CMT0_CMI0 Priority of interrupts
    ICU.IER[0x03].BIT.IEN4 = 1;             //CMT0_CMI0 Permission for interrupt
    CMT.CMSTR0.WORD     = 0x0000;           //CMT0,CMT1 Stop counting
    CMT0.CMCR.WORD      = 0x00C3;           //PCLK/512
    CMT0.CMCNT          = 0;
    CMT0.CMCOR          = 96;               //1ms/(1/(49.152MHz/512))
    CMT.CMSTR0.WORD     = 0x0003;           //CMT0,CMT1 Start counting

    // MTU3_3 MTU3_4 PWM mode synchronized by RESET
    MSTP_MTU            = 0;                //Release module stop state
    MTU.TSTRA.BYTE      = 0x00;             //MTU Stop counting

    MTU3.TCR.BYTE   = 0x23;                 //ILCK/64(651.04ns)
    MTU3.TCNT = MTU4.TCNT = 0;              //MTU3,MTU4TCNT clear
    MTU3.TGRA = MTU3.TGRC = PWM_CYCLE;      //cycle(16ms)
    MTU3.TGRB = MTU3.TGRD = SERVO_CENTER;   //PWM(servo motor)
    MTU4.TGRA = MTU4.TGRC = 0;              //PWM(left motor)
    MTU4.TGRB = MTU4.TGRD = 0;              //PWM(right motor)
    MTU.TOCR1A.BYTE = 0x40;                 //Selection of output level
    MTU3.TMDR1.BYTE = 0x38;                 //TGRC,TGRD buffer function
                                            //PWM mode synchronized by RESET
    MTU4.TMDR1.BYTE = 0x00;                 //Set 0 to exclude MTU3 effects
    MTU.TOERA.BYTE  = 0xc7;                 //MTU3TGRB,MTU4TGRA,MTU4TGRB permission for output

    MTU.TSTRA.BYTE  = 0x40;                 //MTU0,MTU3 count function
}


/***********************************************************************/
/* Motor speed control                                                 */
/* Arguments:   Left motor: -100 to 100, Right motor: -100 to 100      */
/*        Here, 0 is stopped, 100 is forward, and -100 is reverse.     */
/* Return value:    None                                               */
/***********************************************************************/

