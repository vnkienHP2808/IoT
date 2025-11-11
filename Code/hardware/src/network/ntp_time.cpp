#include <ntp_time.h>
#include "config.h"

void ntp_init() {
    configTime(7*3600, 0, "pool.ntp.org", "time.google.com");       // Đồng bộ về múi giờ GMT +7 Bangkok
    Serial.print("Syncing time");
    int tries = 0;

    while (time(nullptr) < 1600000000 && tries < 20) {
        Serial.print(".");
        delay(500);
        tries++;
    }
    Serial.println();
}

time_t_get_epoch() {
    return time(nullptr);
}

