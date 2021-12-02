/******************************************************************************
* File Name:   udp_server.h
*
* Description: This file contains declaration of task and functions related to
*              UDP server operation.
*
*******************************************************************************
* $ Copyright 2021 Cypress Semiconductor $
*******************************************************************************/

#ifndef UDP_SERVER_H_
#define UDP_SERVER_H_

/*******************************************************************************
* Macros
********************************************************************************/
/* Wi-Fi Credentials: Modify WIFI_SSID, WIFI_PASSWORD, and WIFI_SECURITY_TYPE
 * to match your Wi-Fi network credentials.
 * Note: Maximum length of the Wi-Fi SSID and password is set to
 * CY_WCM_MAX_SSID_LEN and CY_WCM_MAX_PASSPHRASE_LEN as defined in cy_wcm.h file.
 */
#define WIFI_SSID                                 "WIFI_SSID"
#define WIFI_PASSWORD                             "WIFI_PASSWORD"

/* Security type of the Wi-Fi access point. See 'cy_wcm_security_t' structure
 * in "cy_wcm.h" for more details.
 */
#define WIFI_SECURITY_TYPE                        CY_WCM_SECURITY_WPA2_AES_PSK

/* Maximum number of connection retries to a Wi-Fi network. */
#define MAX_WIFI_CONN_RETRIES                     (10u)

/* Wi-Fi re-connection time interval in milliseconds */
#define WIFI_CONN_RETRY_INTERVAL_MSEC             (1000)

/* UDP server related macros. */
#define UDP_SERVER_PORT                           (50007)
#define UDP_SERVER_MAX_PENDING_CONNECTIONS        (3)
#define UDP_SERVER_RECV_TIMEOUT_MS                (500)

/*******************************************************************************
* Function Prototypes
********************************************************************************/
void udp_server_task(void *arg);

#endif /* UDP_SERVER_H_ */

/* [] END OF FILE */
