/*
 * examples.c
 *
 *  Created on: Aug 12, 2012
 *      Author: bogdan
 */
#include"examples.h"

void HsiRgbExample(void)
{
    HsiColor* hsi = NULL;
    RgbFColor* rgbF = NULL;
    RgbIColor* rgbI = NULL;

    /*HSI to RGB*/
    hsi = Hsi_Create(30.0, 0.3, 0.2);
    rgbF = RgbF_CreateFromHsi(hsi->H, hsi->S, hsi->I);
    rgbI = RgbI_CreateFromRealForm(rgbF->R, rgbF->G, rgbF->B);
    printf("\nHSI : %f %f %f", hsi->H, hsi->S, hsi->I);
    printf("\nRGBf : %f %f %f", rgbF->R, rgbF->G, rgbF->B);
    printf("\nRGBi : %d %d %d", rgbI->R, rgbI->G, rgbI->B);

    /*Frees the resources*/
    free(hsi);
    free(rgbF);
    free(rgbI);

    /*RGB to HSI*/
    rgbI = RgbI_Create(34U, 50U, 98U);
    rgbF = RgbF_CreateFromIntegerForm(rgbI->R, rgbI->G, rgbI->B);
    hsi = Hsi_CreateFromRgbF(rgbF->R, rgbF->G, rgbF->B);
    printf("\nHSI : %f %f %f", hsi->H, hsi->S, hsi->I);
    printf("\nRGBf : %f %f %f", rgbF->R, rgbF->G, rgbF->B);
    printf("\nRGBi : %d %d %d", rgbI->R, rgbI->G, rgbI->B);
}

void HslRgbExample(void)
{
    HslColor* hsl = NULL;
    RgbFColor* rgbF = NULL;
    RgbIColor* rgbI = NULL;

    /*HSI to RGB*/
    hsl = Hsl_Create(84.0, 1.0, 0.4);
    rgbF = RgbF_CreateFromHsl(hsl->H, hsl->S, hsl->L);
    rgbI = RgbI_CreateFromRealForm(rgbF->R, rgbF->G, rgbF->B);
    printf("\nHSL : %f %f %f", hsl->H, hsl->S, hsl->L);
    printf("\nRGBf : %f %f %f", rgbF->R, rgbF->G, rgbF->B);
    printf("\nRGBi : %d %d %d", rgbI->R, rgbI->G, rgbI->B);

    /*Frees the resources*/
    free(hsl);
    free(rgbF);
    free(rgbI);

    /*RGB to HSI*/
    rgbI = RgbI_Create(108U, 198U, 78U);
    rgbF = RgbF_CreateFromIntegerForm(rgbI->R, rgbI->G, rgbI->B);
    hsl = Hsl_CreateFromRgbF(rgbF->R, rgbF->G, rgbF->B);
    printf("\nHSL : %f %f %f", hsl->H, hsl->S, hsl->L);
    printf("\nRGBf : %f %f %f", rgbF->R, rgbF->G, rgbF->B);
    printf("\nRGBi : %d %d %d", rgbI->R, rgbI->G, rgbI->B);
}

void HsvRgbExample(void)
{
    HsvColor* hsv = NULL;
    RgbFColor* rgbF = NULL;
    RgbIColor* rgbI = NULL;

    /*HSI to RGB*/
    hsv = Hsv_Create(240.5, 0.316, 0.721);
    rgbF = RgbF_CreateFromHsv(hsv->H, hsv->S, hsv->V);
    rgbI = RgbI_CreateFromRealForm(rgbF->R, rgbF->G, rgbF->B);
    printf("\nHSV : %f %f %f", hsv->H, hsv->S, hsv->V);
    printf("\nRGBf : %f %f %f", rgbF->R, rgbF->G, rgbF->B);
    printf("\nRGBi : %d %d %d", rgbI->R, rgbI->G, rgbI->B);

    /*Frees the resources*/
    free(hsv);
    free(rgbF);
    free(rgbI);

    /*RGB to HSI*/
    rgbI = RgbI_Create(108U, 198U, 78U);
    rgbF = RgbF_CreateFromIntegerForm(rgbI->R, rgbI->G, rgbI->B);
    hsv = Hsv_CreateFromRgbF(rgbF->R, rgbF->G, rgbF->B);
    printf("\nHSV : %f %f %f", hsv->H, hsv->S, hsv->V);
    printf("\nRGBf : %f %f %f", rgbF->R, rgbF->G, rgbF->B);
    printf("\nRGBi : %d %d %d", rgbI->R, rgbI->G, rgbI->B);
}

void YiqRgbExample(void)
{
    YiqColor* yiq = NULL;
    RgbFColor* rgbF = NULL;
    RgbIColor* rgbI = NULL;

    /*YIQ to RGB*/
    yiq = Yiq_Create(0.4, 0.1, -0.11);
    rgbF = RgbF_CreateFromYiq(yiq->Y, yiq->I, yiq->Q);
    rgbI = RgbI_CreateFromRealForm(rgbF->R, rgbF->G, rgbF->B);
    printf("\nYIQ : %f %f %f", yiq->Y, yiq->I, yiq->Q);
    printf("\nRGBf : %f %f %f", rgbF->R, rgbF->G, rgbF->B);
    printf("\nRGBi : %d %d %d", rgbI->R, rgbI->G, rgbI->B);

    /*Frees the resources*/
    free(yiq);
    free(rgbF);
    free(rgbI);

    /*RGB to YIQ*/
    rgbI = RgbI_Create(108U, 198U, 78U);
    rgbF = RgbF_CreateFromIntegerForm(rgbI->R, rgbI->G, rgbI->B);
    yiq = Yiq_CreateFromRgbF(rgbF->R, rgbF->G, rgbF->B);
    printf("\nYIQ : %f %f %f", yiq->Y, yiq->I, yiq->Q);
    printf("\nRGBf : %f %f %f", rgbF->R, rgbF->G, rgbF->B);
    printf("\nRGBi : %d %d %d", rgbI->R, rgbI->G, rgbI->B);
}

void YuvRgbExample(void)
{
    YuvColor* yuv = NULL;
    RgbFColor* rgbF = NULL;
    RgbIColor* rgbI = NULL;

    /*YUV to RGB*/
    yuv = Yuv_Create(0.4, 0.1, -0.11);
    rgbF = RgbF_CreateFromYuv(yuv->Y, yuv->U, yuv->V);
    rgbI = RgbI_CreateFromRealForm(rgbF->R, rgbF->G, rgbF->B);
    printf("\nYIQ : %f %f %f", yuv->Y, yuv->U, yuv->V);
    printf("\nRGBf : %f %f %f", rgbF->R, rgbF->G, rgbF->B);
    printf("\nRGBi : %d %d %d", rgbI->R, rgbI->G, rgbI->B);

    /*Frees the resources*/
    free(yuv);
    free(rgbF);
    free(rgbI);

    /*RGB to YUV*/
    rgbI = RgbI_Create(108U, 198U, 78U);
    rgbF = RgbF_CreateFromIntegerForm(rgbI->R, rgbI->G, rgbI->B);
    yuv = Yuv_CreateFromRgbF(rgbF->R, rgbF->G, rgbF->B);
    printf("\nYIQ : %f %f %f", yuv->Y, yuv->U, yuv->V);
    printf("\nRGBf : %f %f %f", rgbF->R, rgbF->G, rgbF->B);
    printf("\nRGBi : %d %d %d", rgbI->R, rgbI->G, rgbI->B);
}
