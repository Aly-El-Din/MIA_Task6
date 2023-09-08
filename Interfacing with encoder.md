# Interfacing with encoder

Created by: Aly El Din Mohamed

## How encoder works?

---

![quadrature.webp](Interfacing%20with%20encoder%20f321f395c6944ff6bc4f833c0c3dd30b/quadrature.webp)

As we could see in this image, the motor could rotate clock-wise (CW) or counter clock-wise (CCW), and we could also see the signal analogy to this motion, noticed that when it rotates in clock wise direction the pin A leads Pin B so in this pulse wave A is in high state while pin B wave is the low one.

The opposite comes true when rotating in counter clock wise direction.

It’s also obvious that when waves A and B have the opposite states, it means that the motor rotates in CW direction, while if they have the same state, so the motor rotates in CCW direction.

So now and according to the previous, we could provide a code to the Arduino.

## Code

It’s noticed that in our code we have used **#define**, and the reason behind that was not to lead to change all of pins names in the code, if we want to do so we would change only their names in the definition.

We use interrupts in two functions one of them adopts the motor rotation CW, and the other adopts rotation CCW, also we could see the 3rd parameter in **attachInterrupt** method is **CHANGE**, and we wonder why we don’t use (**FALLING** or **RISING), and the reason behind that is the resolution increases the double when we use CHANGE instead of other arguments, as CHANGE means that we would check for the rising and falling once for each pin in each pulse, which means that we check 4 times per pulse.** 

Turning to the loop block, we could see that we are computing the angle in degree metric by multiplying the counter by (-1.8) and cast it to integer.

Where counter means the resultant number of rotations of this motor, and 1.8 is got from dividing 360 by 200.