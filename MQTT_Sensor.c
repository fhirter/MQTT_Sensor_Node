#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

char ssid[] = "";
char pass[] = "";

int main()
{
    stdio_init_all();

    if (cyw43_arch_init_with_country(CYW43_COUNTRY_SWITZERLAND)) {
        printf("failed to initialise\n");
        return 1;

    }
    printf("initialized\n");


    //cyw43_arch_enable_sta_mod();

    if (cyw43_arch_wifi_connect_timeout_ms(ssid, pass, CYW43_AUTH_WPA2_AES_PSK, 10000)) {
        printf("failed to connect\n");
        return 1;
    }

    printf("connected\n");

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
