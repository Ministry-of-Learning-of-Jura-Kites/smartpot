#ifndef WIFI_ESP32_H
#define WIFI_ESP32_H

#include <esp_now.h>
#include <WiFi.h>

namespace WiFiWrapper
{
    bool addPeer(uint8_t *broadcastAddress)
    {
        esp_now_peer_info_t peerInfo;

        memcpy(peerInfo.peer_addr, broadcastAddress, 6);
        peerInfo.channel = WiFi.channel();
        peerInfo.ifidx = WIFI_IF_STA;
        peerInfo.encrypt = false;

        return esp_now_add_peer(&peerInfo) == ESP_OK;
    }

    void setSelfRole(bool isController)
    {
        // esp_now_set_self_role is not available in esp_now.h
    }
}

#endif // WIFI_ESP32_H