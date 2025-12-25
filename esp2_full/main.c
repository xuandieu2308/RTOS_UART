#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "esp_log.h"

#define UART_PORT       UART_NUM_1
#define UART_TX_PIN     17
#define UART_RX_PIN     16
#define UART_BAUDRATE   115200
#define BUF_SIZE        1024

static const char *TAG = "ESP2_FULL";

static void uart_init(void)
{
    const uart_config_t uart_config = {
        .baud_rate = UART_BAUDRATE,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };

    uart_driver_install(UART_PORT, BUF_SIZE * 2, 0, 0, NULL, 0);
    uart_param_config(UART_PORT, &uart_config);
    uart_set_pin(UART_PORT, UART_TX_PIN, UART_RX_PIN, 
                 UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
}

static void uart_tx_task(void *pvParameters)
{
    int count = 0;
    char tx_buffer[BUF_SIZE];
    while (1) {
        count++;
        snprintf(tx_buffer, BUF_SIZE, "ESP2 SEND: Hello %d\n", count);
        uart_write_bytes(UART_PORT, tx_buffer, strlen(tx_buffer));
        ESP_LOGI(TAG, "ESP2 đã gửi: %s", tx_buffer);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

static void uart_rx_task(void *pvParameters)
{
    char rx_buffer[BUF_SIZE];
    while (1) {
        int len = uart_read_bytes(UART_PORT, rx_buffer, BUF_SIZE - 1, 100 / portTICK_PERIOD_MS);
        if (len > 0) {
            rx_buffer[len] = '\0';
            ESP_LOGI(TAG, "ESP2 đã nhận: %s", rx_buffer);
        }
        vTaskDelay(50 / portTICK_PERIOD_MS);
    }
}

void app_main(void)
{
    uart_init();
    xTaskCreate(uart_tx_task, "uart_tx_task", 4096, NULL, 10, NULL);
    xTaskCreate(uart_rx_task, "uart_rx_task", 4096, NULL, 10, NULL);
}
