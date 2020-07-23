//--------------------------------------------------------------------------------
// @file   SoilMonitor.cpp
//--------------------------------------------------------------------------------

#pragma once
#include "SoilMonitor.h"
#include <M5StickC.h>

namespace
{
    const int cBarDivNum = 10;
}

//--------------------------------------------------------------------------------
void SoilMonitor::setup()
{
    M5.begin();
    M5.Lcd.setRotation(0);
    drawBar_(0.6f);
}
//--------------------------------------------------------------------------------
void SoilMonitor::loop()
{
}
//--------------------------------------------------------------------------------
void SoilMonitor::drawBar_(float ratio)
{
    const float height = M5.Lcd.height();
    const float width = M5.Lcd.width();
    const float lectHeight = height / cBarDivNum;
    const int barNum = static_cast<int>(cBarDivNum * ratio);

    // 枠を描画
    for (int i = 0; i < cBarDivNum; i++)
    {
        const auto color = M5.lcd.color565(255, 255, 255);
        M5.Lcd.drawRect(0, height - lectHeight * (i + 1), width, lectHeight, color);
        if (i < barNum)
        {
            const auto color2 = M5.Lcd.color565(0, 255, 0);
            M5.Lcd.drawRect(0, height - lectHeight * (i + 1), width, lectHeight, color2);
        }
    }
}
//--------------------------------------------------------------------------------