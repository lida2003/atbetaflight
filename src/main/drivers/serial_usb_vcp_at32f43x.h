/*
 * This file is part of Cleanflight and Betaflight.
 *
 * Cleanflight and Betaflight are free software. You can redistribute
 * this software and/or modify this software under the terms of the
 * GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Cleanflight and Betaflight are distributed in the hope that they
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "drivers/serial.h"

#define APP_TX_DATA_SIZE 2048

typedef struct {
    serialPort_t port;

    // Buffer used during bulk writes.
    uint8_t txBuf[APP_TX_DATA_SIZE];
    uint8_t txAt;
    // Set if the port is in bulk write mode and can buffer.
    bool buffering;
} vcpPort_t;



/*
    APP RX is the circular buffer for data that is transmitted from the APP (host)
    to the USB device (flight controller).
*/
#define APP_RX_DATA_SIZE  2048
static uint8_t APP_Rx_Buffer[APP_RX_DATA_SIZE]; //接收buffer，将usb的批量读入，转为 usbvcpRead 的逐位读出
static uint32_t APP_Rx_ptr_out = 0; //serail 读出 ,后指针
static uint32_t APP_Rx_ptr_in = 0; //usb 读入，前指针




serialPort_t *usbVcpOpen(void);
struct serialPort_s;
uint32_t usbVcpGetBaudRate(struct serialPort_s *instance);
uint8_t usbVcpIsConnected(void);
