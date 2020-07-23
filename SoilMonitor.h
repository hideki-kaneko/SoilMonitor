//--------------------------------------------------------------------------------
// @file   SoilMonitor.h
// @brief  土壌水分モニタ
//--------------------------------------------------------------------------------

class SoilMonitor
{
public:
    //--------------------------------------------------------------------------------
    explicit SoilMonitor() {}
    void setup();
    void loop();

private:
    //--------------------------------------------------------------------------------
    void drawBar_(float ratio);
    void drawText_(float ratio, int rawVal);
    float getMoistureRatio_();
    int getMoistureRawVal_();
    bool checkInterval_();
};