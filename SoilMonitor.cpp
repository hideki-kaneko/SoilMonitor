//--------------------------------------------------------------------------------
// @file   SoilMonitor.cpp
//--------------------------------------------------------------------------------

#pragma once
#include "SoilMonitor.h"
#include <M5StickC.h>

namespace
{
    const int cBarDivNum = 10;
    const int cBarFillMargin = 2;
    const int cBarLevelLow = 3;
    const int cBarLevelMid = 6;
    const int cCenterTextOffsetY = -6;
}

//--------------------------------------------------------------------------------
void SoilMonitor::setup()
{
    M5.begin();
    M5.Lcd.setRotation(2);
    drawBar_(0.6f);
}
//--------------------------------------------------------------------------------
void SoilMonitor::loop()
{
    M5.Lcd.fillScreen(TFT_BLACK);
    drawBar_(mCounter / 10.f);
    delay(1000);
    mCounter = (mCounter + 1) % 10;
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
        M5.Lcd.drawRect(
            0,
            height - lectHeight * (i + 1),
            width,
            lectHeight,
            color
        );
        if (i < barNum)
        {
            uint16_t color2;
            if(i < cBarLevelLow){
                color2 = M5.Lcd.color565(255, 0, 0);
            }
            else if (i < cBarLevelMid)
            {
                color2 = M5.Lcd.color565(255, 255, 0);
            }
            else
            {
                color2 = M5.Lcd.color565(0, 255, 0);
            }
            M5.Lcd.fillRect(
                cBarFillMargin,
                height - lectHeight * (i + 1) + cBarFillMargin,
                width - cBarFillMargin * 2,
                lectHeight - cBarFillMargin * 2,
                color2
            );
        }
    }

    // 数値を描画
    M5.Lcd.setTextSize(2);
    String text = static_cast<int>(ratio * 100) + String("%");
    M5.Lcd.drawCentreString(text, width / 2.f, (height / 2.f) + cCenterTextOffsetY, 1);
}
//--------------------------------------------------------------------------------