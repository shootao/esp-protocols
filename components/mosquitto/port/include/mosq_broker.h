/*
 * SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once
#include "mosquitto.h"
#include "esp_tls.h"

struct mosquitto__config;

/**
 * @brief Mosquitto configuration structure
 *
 * ESP port of mosquittto supports only the options in this configuration
 * structure.
 */
struct mosq_broker_config {
    char *host; /*!< Address on which the broker is listening for connections */
    int port;   /*!< Port number of the broker to listen to */
    esp_tls_cfg_server_t *tls_cfg;  /*!< ESP-TLS configuration (if TLS transport used)
                                     * Please refer to the ESP-TLS official documentation
                                     * for more details on configuring the TLS options.
                                     * You can open the respective docs with this idf.py command:
                                     * `idf.py docs -sp api-reference/protocols/esp_tls.html`
                                     */
};

/**
 * @brief Start mosquitto broker
 *
 * This API runs the broker in the calling thread and blocks until
 * the mosquitto exits.
 *
 * @param config Mosquitto configuration structure
 * @return int Exit code (0 on success)
 */
int mosq_broker_run(struct mosq_broker_config *config);

/**
 * @brief Stops running broker
 *
 * @note After calling this API, function mosq_broker_run() unblocks and returns.
 */
void mosq_broker_stop(void);
