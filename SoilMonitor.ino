//--------------------------------------------------------------------------------
// @file   SoilMonitor.ino
// @brief  土壌水分モニタ
//--------------------------------------------------------------------------------

#include <M5StickC.h>
#include "SoilMonitor.h"

SoilMonitor soilMonitor;

void setup() {
  soilMonitor.setup();
}

void loop() {
  soilMonitor.loop();
}
