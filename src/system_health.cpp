#include "system_health.h"

#include "config.h"
#include "network.h"
#include "power_manager.h"

namespace {
uint32_t g_telemetrySuccessCount = 0;
uint32_t g_telemetryFailureCount = 0;
uint32_t g_lastSuccessfulTelemetryMs = 0;
}

void systemHealthBegin()
{
    g_telemetrySuccessCount = 0;
    g_telemetryFailureCount = 0;
    g_lastSuccessfulTelemetryMs = 0;
}

void recordTelemetryResult(bool success)
{
    g_lastSuccessfulTelemetryMs = millis();

    if (success)
    {
        g_telemetrySuccessCount++;
    }
    else
    {
        g_telemetryFailureCount++;
    }
}

uint32_t telemetrySuccessCount()
{
    return g_telemetrySuccessCount;
}

uint32_t telemetryFailureCount()
{
    return g_telemetryFailureCount;
}

uint32_t lastSuccessfulTelemetryMs()
{
    return g_lastSuccessfulTelemetryMs;
}

void printSystemHealth()
{
    Serial.println();
    Serial.println("[HEALTH]");

    Serial.println("telemetry_success_count=" +
                   String(telemetrySuccessCount()));
    Serial.println("telemetry_failure_count=" +
                   String(telemetryFailureCount()));
    Serial.println("last_successful_telemetry_ms=" +
                   String(lastSuccessfulTelemetryMs()));

    Serial.println("device_id=" + String(DEVICE_ID));
    Serial.println("firmware_version=" + String(FIRMWARE_VERSION));

    Serial.println("wifi_state=" +
                   String(networkIsConnected() ? "CONNECTED" : "DISCONNECTED"));

    Serial.println("rssi_dbm=" +
                   String(networkRssi()));

    Serial.println("uptime_s=" +
                   String(millis() / 1000));

    Serial.println("free_heap=" +
                   String(ESP.getFreeHeap()));

    Serial.println("reconnect_count=" +
                   String(networkReconnectCount()));

    // power_mode จะเติมหลังจากดู power_manager.h/.cpp
    // =========================================================
    // PART B - TODO
    // Extend THIS function so that it also reports:
    // device_id
    // firmware_version
    // wifi_state
    // rssi_dbm
    // uptime_s
    // free_heap
    // reconnect_count
    // power_mode
    //
    // Keep the existing telemetry fields above.
    // Do not rename this function.
    // =========================================================

    Serial.println();
}
