colorspace-conversions
======================

An ANSI C library for colorspace conversions.


More conversions coming based on the math from:

http://www.easyrgb.com/index.php?X=MATH


Added a Makefile to compile the examples.

Thanks go to dwhitney67 (username) for the example at:

http://ubuntuforums.org/showthread.php?t=1204739&p=7564719#post7564719


Added all conversion routine calls to main.c:

	HsiRgbExample();
	HslRgbExample();
	HsvRgbExample();
	YiqRgbExample();
	YuvRgbExample();

Added a newline (\n) at the end of the last printf in examples.c, it's neater.