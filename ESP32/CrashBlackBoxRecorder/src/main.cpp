#include "diagnostics.h"
#include "storage.h"

uint32_t restartCount = 0;

void setup()
{
    Serial.begin(115200);
    delay(4000);

    Diagnostics::begin();
    Storage::begin();



    Serial.println();
    Serial.println("=========================");
    Serial.println("Previous Crash Report");
    Serial.println("=========================");

    CrashData previous = Storage::loadCrashData();

    restartCount = Storage::incrementRestartCount();

    Serial.print("Firmware : ");
    Serial.println(previous.firmwareVersion);

    Serial.print("Reset Reason : ");
    Serial.println(previous.resetReason);

    Serial.print("Free Heap : ");
    Serial.println(previous.freeHeap);

    Serial.print("Uptime : ");
    Serial.print(previous.uptime);
    Serial.println(" sec");

    Serial.print("WiFi RSSI : ");
    Serial.println(previous.wifiRSSI);

    Serial.print("Restart Count : ");
    Serial.println(previous.restartCount);

    Serial.println();
}

void loop()
{
    DeviceStatus status = Diagnostics::getCurrentStatus();

    CrashData data;

    data.firmwareVersion = status.firmwareVersion;
    data.resetReason = status.resetReason;
    data.freeHeap = status.freeHeap;
    data.uptime = status.uptime;
    data.wifiRSSI = status.wifiRSSI;
    data.restartCount = restartCount;

    Storage::saveCrashData(data);

    Serial.println("=========================");
    Serial.println("Current Device Status");
    Serial.println("=========================");

    Serial.print("Firmware : ");
    Serial.println(status.firmwareVersion);

    Serial.print("Chip : ");
    Serial.println(status.chipModel);

    Serial.print("Reset Reason : ");
    Serial.println(status.resetReason);

    Serial.print("Free Heap : ");
    Serial.println(status.freeHeap);

    Serial.print("Uptime : ");
    Serial.print(status.uptime);
    Serial.println(" sec");

    Serial.print("CPU : ");
    Serial.print(status.cpuFreqMHz);
    Serial.println(" MHz");

    if (status.wifiRSSI == 0)
        Serial.println("WiFi RSSI : Not Connected");
    else
    {
        Serial.print("WiFi RSSI : ");
        Serial.print(status.wifiRSSI);
        Serial.println(" dBm");
    }

    Serial.print("Restart Count : ");
    Serial.println(restartCount);

    Serial.println();

    delay(5000);
}