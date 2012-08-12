/*
 * colorspace.h
 *
 *  Created on: Aug 11, 2012
 *      Author: bogdan
 */

#ifndef COLORSPACES_H_
#define COLORSPACES_H_

#include<stdbool.h>
#include<stdint.h>
#include<stdlib.h>
#include<math.h>

/*The lower limit for R, G, B (real version), S, I*/
#define PER_LOWER_LIMIT (0.0)
/*The upper limit for R, G, B (real version), S, I*/
#define PER_UPPER_LIMIT (1.0)
/*The lower limit for H*/
#define HUE_LOWER_LIMIT (0.0)
/*The upper limit for H*/
#define HUE_UPPER_LIMIT (360.0)
/*The lower limit for R, G, B (integer version)*/
#define RGBI_LOWER_LIMIT (0U)
/*The upper limit for R, G, B (integer version)*/
#define RGBI_UPPER_LIMIT (255U)
/*The upper limit for I in YIQ*/
#define YIQ_I_UPPER_LIMIT (0.5957)
/*The lower limit for I in YIQ*/
#define YIQ_I_LOWER_LIMIT (-0.5957)
/*The upper limit for Q in YIQ*/
#define YIQ_Q_UPPER_LIMIT (0.5226)
/*The lower limit for Q in YIQ*/
#define YIQ_Q_LOWER_LIMIT (-0.5226)
/*The upper limit for U in YUV*/
#define YUV_U_UPPER_LIMIT (0.436)
/*The lower limit for U in YUV*/
#define YUV_U_LOWER_LIMIT (-0.436)
/*The upper limit for V in YUV*/
#define YUV_V_UPPER_LIMIT (0.615)
/*The lower limit for V in YUV*/
#define YUV_V_LOWER_LIMIT (-0.615)

typedef struct
{
    double R;
    double G;
    double B;
} RgbFColor;

typedef struct
{
    uint8_t R;
    uint8_t G;
    uint8_t B;
} RgbIColor;

typedef struct
{
    double H;
    double S;
    double I;
} HsiColor;

typedef struct
{
    double H;
    double S;
    double L;
} HslColor;

typedef struct
{
    double H;
    double S;
    double V;
} HsvColor;

typedef struct
{
    double Y;
    double I;
    double Q;
} YiqColor;

typedef struct
{
    double Y;
    double U;
    double V;
} YuvColor;

/*
 * Description:
 *  Checks if a value is within a specified interval
 * Parameters:
 *  value - the value who is checked
 *  lowerLimit - the lower limit of the interval
 *  upperLimit - the upper limit of the interval
 * Returns:
 *  true if the value is within the interval
 *  false if the value is not within the interval
 */bool RealIsWithinBounds(double value, double lowerLimit, double upperLimit);
/*
 * Description:
 *  Checks if a value is within a specified interval
 * Parameters:
 *  value - the value who is checked
 *  lowerLimit - the lower limit of the interval
 *  upperLimit - the upper limit of the interval
 * Returns:
 *  true if the value is within the interval
 *  false if the value is not within the interval
 */bool IntegerIsWithinBounds(uint8_t value, uint8_t lowerLimit,
        uint8_t upperLimit);
/*
 * Description:
 *  Returns the smallest of the three parameters
 * Parameters
 *  r,g,b - 3 real numbers
 * Returns
 *  The smallest real number from the set {r,g,b}
 */
double Double_GetMinimum(double r, double g, double b);
/*
 * Description:
 *  Returns the largest of the three parameters
 * Parameters
 *  r,g,b - 3 real numbers
 * Returns
 *  The largest real number from the set {r,g,b}
 */
double Double_GetMaximum(double r, double g, double b);

/*
 * Description:
 *  Checks if the RGB components are valid
 * Parameters:
 *  r,g,b - the components of an RGB model expressed
 *          as real numbers
 * Returns:
 *  true if the values are correct
 *  false if the values are incorrect
 */bool RgbF_IsValid(double r, double g, double b);
/*
 * Description:
 *  Checks if the HSI components are valid
 * Parameters:
 *  h,s,i - the components of an HSI model expressed
 *          as real numbers
 * Returns:
 *  true if the values are correct
 *  false if the values are incorrect
 */bool Hsi_IsValid(double h, double s, double i);
/*
 * Description:
 *  Checks if the RGB components are valid
 * Parameters:
 *  r,g,b - the components of an RGB model expressed
 *          as natural numbers
 * Returns:
 *  true if the values are correct
 *  false if the values are incorrect
 */bool RgbI_IsValid(uint8_t r, uint8_t g, uint8_t b);
/*
 * Description:
 *  Checks if the HSL components are valid
 * Parameters:
 *  h,s,l - the components of an HSL model expressed
 *          as real numbers
 * Returns:
 *  true if the values are correct
 *  false if the values are incorrect
 */bool Hsl_IsValid(double h, double s, double l);
/*
 * Description:
 *  Checks if the HSV components are valid
 * Parameters:
 *  h,s,v - the components of an HSV model expressed
 *          as real numbers
 * Returns:
 *  true if the values are correct
 *  false if the values are incorrect
 */bool Hsv_IsValid(double h, double s, double v);
/*
 * Description:
 *  Checks if the YIQ components are valid
 * Parameters:
 *  y,i,q - the components of an YIQ model expressed
 *          as real numbers
 * Returns:
 *  true if the values are correct
 *  false if the values are incorrect
 */bool Yiq_IsValid(double y, double i, double q);
/*
 * Description:
 *  Checks if the YUV components are valid
 * Parameters:
 *  y,u,v - the components of an YUV model expressed
 *          as real numbers
 * Returns:
 *  true if the values are correct
 *  false if the values are incorrect
 */bool Yuv_IsValid(double y, double u, double v);

/*
 * Description:
 *  Creates a RgbIColor structure
 * Parameters:
 *  r,g,b - the components of an RGB model expressed
 *          as natural numbers
 * Returns:
 *  A pointer to the RgbIColor is the parameters are
 * correct. Otherwise returns NULL.
 */
RgbIColor* RgbI_Create(uint8_t r, uint8_t g, uint8_t b);
/*
 * Description:
 *  Creates a RgbIColor structure from RGB components
 * Parameters:
 *  r,g,b - the components of an RGB model expressed
 *          as real numbers
 * Returns:
 *  A pointer to the RgbIColor is the parameters are
 * correct. Otherwise returns NULL.
 */
RgbIColor* RgbI_CreateFromRealForm(double r, double g, double b);
/*
 * Description:
 *  Creates a RgbfColor structure
 * Parameters:
 *  r,g,b - the components of an RGB model expressed
 *          as real numbers
 * Returns:
 *  A pointer to the RgbFColor is the parameters are
 * correct. Otherwise returns NULL.
 */
RgbFColor* RgbF_Create(double r, double g, double b);
/*
 * Description:
 *  Creates a RgbFColor structure from RGB components
 * Parameters:
 *  r,g,b - the components of an RGB model expressed
 *          as real numbers
 * Returns:
 *  A pointer to the RgbFColor is the parameters are
 * correct. Otherwise returns NULL.
 */
RgbFColor* RgbF_CreateFromIntegerForm(uint8_t r, uint8_t g, uint8_t b);
/*
 * Description:
 *  Creates a RgbFColor structure from HSI components
 * Parameters:
 *  h,s,i - the components of an HSI model expressed
 *          as real numbers
 * Returns:
 *  A pointer to the RgbFColor is the parameters are
 * correct. Otherwise returns NULL.
 */
RgbFColor* RgbF_CreateFromHsi(double h, double s, double i);
/*
 * Description:
 *  Creates a RgbFColor structure from HSL components
 * Parameters:
 *  h,s,l - the components of an HSL model expressed
 *          as real numbers
 * Returns:
 *  A pointer to the RgbFColor is the parameters are
 * correct. Otherwise returns NULL.
 */
RgbFColor* RgbF_CreateFromHsl(double h, double s, double l);
/*
 * Description:
 *  Creates a RgbFColor structure from HSV components
 * Parameters:
 *  h,s,v - the components of an HSV model expressed
 *          as real numbers
 * Returns:
 *  A pointer to the RgbFColor is the parameters are
 * correct. Otherwise returns NULL.
 */
RgbFColor* RgbF_CreateFromHsv(double h, double s, double v);
/*
 * Description:
 *  Creates a RgbFColor structure from YIQ components
 * Parameters:
 *  y,i,q - the components of an YIQ model expressed
 *          as real numbers
 * Returns:
 *  A pointer to the RgbFColor is the parameters are
 * correct. Otherwise returns NULL.
 */
RgbFColor* RgbF_CreateFromYiq(double y, double i, double q);
/*
 * Description:
 *  Creates a RgbFColor structure from YUV components
 * Parameters:
 *  y,u,v - the components of an YUV model expressed
 *          as real numbers
 * Returns:
 *  A pointer to the RgbFColor is the parameters are
 * correct. Otherwise returns NULL.
 */
RgbFColor* RgbF_CreateFromYuv(double y, double u, double v);
/*
 * Description:
 *  Creates a HsiColor structure
 * Parameters:
 *  h,s,i - the components of an HSI model expressed
 *          as real numbers
 * Returns:
 *  A pointer to the HsiColor is the parameters are
 * correct. Otherwise returns NULL.
 */
HsiColor* Hsi_Create(double h, double s, double i);
/* Description:
 *  Creates a HsiColor structure from RGB components
 * Parameters:
 *  r,g,b - the components of an RGB model expressed
 *          as real numbers
 * Returns:
 *  A pointer to the HsiColor is the parameters are
 * correct. Otherwise returns NULL.
 */
HsiColor* Hsi_CreateFromRgbF(double r, double g, double b);
/*
 * Description:
 *  Creates a HslColor structure
 * Parameters:
 *  h,s,l - the components of an HSL model expressed
 *          as real numbers
 * Returns:
 *  A pointer to the HslColor is the parameters are
 * correct. Otherwise returns NULL.
 */
HslColor* Hsl_Create(double h, double s, double l);
/* Description:
 *  Creates a HslColor structure from RGB components
 * Parameters:
 *  r,g,b - the components of an RGB model expressed
 *          as real numbers
 * Returns:
 *  A pointer to the HslColor is the parameters are
 * correct. Otherwise returns NULL.
 */
HslColor* Hsl_CreateFromRgbF(double r, double g, double b);
/*
 * Description:
 *  Creates a HsvColor structure
 * Parameters:
 *  h,s,v - the components of an HSV model expressed
 *          as real numbers
 * Returns:
 *  A pointer to the HsvColor is the parameters are
 * correct. Otherwise returns NULL.
 */
HsvColor* Hsv_Create(double h, double s, double v);
/* Description:
 *  Creates a HsvColor structure from RGB components
 * Parameters:
 *  r,g,b - the components of an RGB model expressed
 *          as real numbers
 * Returns:
 *  A pointer to the HsvColor is the parameters are
 * correct. Otherwise returns NULL.
 */
HsvColor* Hsv_CreateFromRgbF(double r, double g, double b);
/*
 * Description:
 *  Creates a YiqColor structure
 * Parameters:
 *  y,i,q - the components of an YIQ model expressed
 *          as real numbers
 * Returns:
 *  A pointer to the YiqColor is the parameters are
 * correct. Otherwise returns NULL.
 */
YiqColor* Yiq_Create(double y, double i, double q);
/* Description:
 *  Creates a YiqColor structure from RGB components
 * Parameters:
 *  r,g,b - the components of an RGB model expressed
 *          as real numbers
 * Returns:
 *  A pointer to the YiqColor is the parameters are
 * correct. Otherwise returns NULL.
 */
YiqColor* Yiq_CreateFromRgbF(double r, double g, double b);
/*
 * Description:
 *  Creates a YuvColor structure
 * Parameters:
 *  y,u,v - the components of an YUV model expressed
 *          as real numbers
 * Returns:
 *  A pointer to the YuvColor is the parameters are
 * correct. Otherwise returns NULL.
 */
YuvColor* Yuv_Create(double y, double u, double v);
/* Description:
 *  Creates a YuvColor structure from RGB components
 * Parameters:
 *  r,g,b - the components of an RGB model expressed
 *          as real numbers
 * Returns:
 *  A pointer to the YuvColor is the parameters are
 * correct. Otherwise returns NULL.
 */
YuvColor* Yuv_CreateFromRgbF(double r, double g, double f);

#endif
