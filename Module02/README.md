-Fixed-point format: 00000000.000 (8 bits integer, 3 bits fraction)
-Fixed-point have no exponent (meaning we cant move the point  it fixed)
-The position of the point is decicde at design time


```
// store numbers as fixed-point with 8 fractional bits
int x = 3 << 8;   // 3.0 int we reserve 8 bits for the fractional part by shifting left 8 bits
int y = 0.5 * 256; // 0.5 float we multiply by 256 , we dont shift so we dont get in 
int result = x + y; // 3.5
```

-Float-point: "IEEE 754 single precision"
    - value=(−1)sign×1.mantissa×2exponent−bias;
    - 0 | 10000001 | 01110000000000000000000
    - signs | Exponent (8bits) | Mantissa(fraction) (23 bis)

-Float-point: "64-bit, IEEE-754 double precision"
    - value=(−1)sign×1.mantissa×2exponent−1023
    - 0 | 10000000001 | 0111000000000000000000000000000000000000000000000000
    - signs | Exponent (11 bits) | Mantissa(fraction) (52 bis)
