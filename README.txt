# Midterm1

在function.h裏面，我放了三個function。分別是uLCD的界面程式ulcd_display(int i)，產生三角波的wave(int i)和取樣的sampling().

在main.cpp裏，我以三顆button作爲數位訊號輸入，輸入有mypin_up、mypin_down和mypin_select功能是其對應的功能是上、下和選擇，目的是控制uLCD界面上的選項，我所設計的界面有四個頻率的選項，以select作爲int的變數，通過加減法就能控制界面的變化。
當mypin_select被觸發后，程式以所選擇的頻率作爲參數進入到wave function，產生所對應的波形。

wave產生波形的方式以hw 2的三角波作爲參考，然後更改屬於自己的波。然後以D7 pin脚是作爲這個DAC的輸出，我將這個類比訊號傳入到A0 脚位，作爲取樣的輸入。
有了類比的輸入就能做取樣和用FFT分析。

我用sampling function作爲取樣，以類比訊號的輸入然後和FFT.py一樣的sampling rate做取樣。以D13 pin脚輸出，然後接上picoscope，觀察被取樣的波。sampling rate的取法是我剛好產生一個波所需的sampling rate。
