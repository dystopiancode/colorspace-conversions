/*
 * colorspacebody.c
 *
 *  Created on: Aug 11, 2012
 *      Author: bogdan
 */
#include "colorspace.h"

bool RealIsWithinBounds(double value, double lowerLimit, double upperLimit)
{
    if (value >= lowerLimit && value <= upperLimit)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IntegerIsWithinBounds(uint8_t value, uint8_t lowerLimit,
        uint8_t upperLimit)
{
    if (value >= lowerLimit && value <= upperLimit)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double Double_GetMinimum(double r, double g, double b)
{
    if (r < g)
    {
        if (r < b)
        {
            return r;
        }
        else
        {
            return b;
        }
    }
    else
    {
        if (g < b)
        {
            return g;
        }
        else
        {
            return b;
        }
    }
    return 0;
}

double Double_GetMaximum(double r, double g, double b)
{
    if (r > g)
    {
        if (r > b)
        {
            return r;
        }
        else
        {
            return b;
        }
    }
    else
    {
        if (g > b)
        {
            return g;
        }
        else
        {
            return b;
        }
    }
    return 0;
}

bool RgbF_IsValid(double r, double g, double b)
{
    bool isValid = true;
    if ((RealIsWithinBounds(r, PER_LOWER_LIMIT, PER_UPPER_LIMIT) == false)
            || (RealIsWithinBounds(g, PER_LOWER_LIMIT, PER_UPPER_LIMIT) == false)
            || (RealIsWithinBounds(b, PER_LOWER_LIMIT, PER_UPPER_LIMIT) == false))
    {
        isValid = false;
    }
    return isValid;
}

bool Hsi_IsValid(double h, double s, double i)
{
    bool isValid = true;
    if ((RealIsWithinBounds(h, HUE_LOWER_LIMIT, HUE_UPPER_LIMIT) == false)
            || (RealIsWithinBounds(s, PER_LOWER_LIMIT, PER_UPPER_LIMIT) == false)
            || (RealIsWithinBounds(i, PER_LOWER_LIMIT, PER_UPPER_LIMIT) == false))
    {
        isValid = false;
    }
    return isValid;
}

bool RgbI_IsValid(uint8_t r, uint8_t g, uint8_t b)
{
    bool isValid = true;
    if ((IntegerIsWithinBounds(r, RGBI_LOWER_LIMIT, RGBI_UPPER_LIMIT) == false)
            || (IntegerIsWithinBounds(g, RGBI_LOWER_LIMIT, RGBI_UPPER_LIMIT)
                    == false)
            || (IntegerIsWithinBounds(b, RGBI_LOWER_LIMIT, RGBI_UPPER_LIMIT)
                    == false))
    {
        isValid = false;
    }
    return isValid;
}

bool Hsl_IsValid(double h, double s, double l)
{
    bool isValid = true;
    if ((RealIsWithinBounds(h, HUE_LOWER_LIMIT, HUE_UPPER_LIMIT) == false)
            || (RealIsWithinBounds(s, PER_LOWER_LIMIT, PER_UPPER_LIMIT) == false)
            || (RealIsWithinBounds(l, PER_LOWER_LIMIT, PER_UPPER_LIMIT) == false))
    {
        isValid = false;
    }
    return isValid;
}

bool Hsv_IsValid(double h, double s, double v)
{
    bool isValid = true;
    if ((RealIsWithinBounds(h, HUE_LOWER_LIMIT, HUE_UPPER_LIMIT) == false)
            || (RealIsWithinBounds(s, PER_LOWER_LIMIT, PER_UPPER_LIMIT) == false)
            || (RealIsWithinBounds(v, PER_LOWER_LIMIT, PER_UPPER_LIMIT) == false))
    {
        isValid = false;
    }
    return isValid;
}

bool Yiq_IsValid(double y, double i, double q)
{
    bool isValid = true;
    if ((RealIsWithinBounds(y, PER_LOWER_LIMIT, PER_UPPER_LIMIT) == false)
            || (RealIsWithinBounds(i, YIQ_I_LOWER_LIMIT, YIQ_I_UPPER_LIMIT)
                    == false)
            || (RealIsWithinBounds(q, YIQ_Q_LOWER_LIMIT, YIQ_Q_UPPER_LIMIT)
                    == false))
    {
        isValid = false;
    }
    return isValid;
}

bool Yuv_IsValid(double y, double u, double v)
{
    bool isValid = true;
    if ((RealIsWithinBounds(y, PER_LOWER_LIMIT, PER_UPPER_LIMIT) == false)
            || (RealIsWithinBounds(u, YUV_U_LOWER_LIMIT, YUV_U_UPPER_LIMIT)
                    == false)
            || (RealIsWithinBounds(v, YUV_V_LOWER_LIMIT, YUV_V_UPPER_LIMIT)
                    == false))
    {
        isValid = false;
    }
    return isValid;
}

