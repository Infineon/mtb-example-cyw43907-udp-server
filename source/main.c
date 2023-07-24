/******************************************************************************
* File Name:   main.c
*
* Description: This is the source code for UDP Server Example in ModusToolbox.
*              In this example, UDP server waits for a connection with a UDP
*              client. Once a message is received from UDP client, the server
*              allows the user to send LED ON/OFF command to the UDP client and
*              the client responds by sending an acknowledgment message to the
*              server.
*
* Related Document: See README.md
*
*******************************************************************************
* $ Copyright 2021-2023 Cypress Semiconductor $
*******************************************************************************/

/* Header file includes */
#include "cyhal.h"
#include "cybsp.h"
#include "cy_retarget_io.h"

/* FreeRTOS header file. */
#include <FreeRTOS.h>
#include <task.h>

/* UDP server task header file. */
#include "udp_server.h"

/*******************************************************************************
* Macros
********************************************************************************/
/* RTOS related macros for UDP server task. */
#define UDP_SERVER_TASK_STACK_SIZE                (5 * 1024)
#define UDP_SERVER_TASK_PRIORITY                  (1)

/*******************************************************************************
* Global Variables
********************************************************************************/

/* UDP server task handle. */
TaskHandle_t server_task_handle;

/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary:
*  System entrance point. This function sets up user tasks and then starts
*  the RTOS scheduler.
*
* Parameters:
*  void
*
* Return:
*  int
*
*******************************************************************************/
int main(void)
{
    cy_rslt_t result;

    /* Initialize the device and board peripherals */
    result = cybsp_init() ;
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }

    /* Enable global interrupts */
    __enable_irq();

    /* Initialize retarget-io to use the debug UART port */
    cy_retarget_io_init(CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX, CY_RETARGET_IO_BAUDRATE);

    /* \x1b[2J\x1b[;H - ANSI ESC sequence to clear screen. */
    printf("\x1b[2J\x1b[;H");
    printf("===============================================================\n");
    printf("CYW43907 - UDP Server\n");
    printf("===============================================================\n\n");

    /* Create the task to establish a connection to a remote UDP client. */
    xTaskCreate(udp_server_task, "Network task", UDP_SERVER_TASK_STACK_SIZE, NULL,
               UDP_SERVER_TASK_PRIORITY, &server_task_handle);

    /* Start the FreeRTOS scheduler. */
    vTaskStartScheduler();

    /* Should never get here. */
    CY_ASSERT(0);

}

/* [] END OF FILE */
