## Describe the effect each of the P, I, D components had in your implementation.

*P*: Higher P values resulted in sharper steering angles when the vehicle
strayed from the center of the lane. Higher P values also enabled to the vehicle
to properly complete sharper turns, but resulted in the car swerving back and
forth across the center line more agressively.

*I*: Higher I values enabled the vehicle to deal with a steering bias. It also
had the benefit to helping the car get around the track given that it has mostly
left hand turns.

*D*: Higher D values resulted in the vehicle swerving less.


## Describe how the final hyperparameters were chosen.

To find the hyperparameters, I recorded the average CTE across a single lap of
the track for a given set of paramater values, then adjusted each one
independently ala the "twiddle" algorithm (albeit manually making the parameter
changes each time) and measured the average CTE again, repeating the adjustments
as the average CTE improved (or reversing them if it got worse). I discovered
two interesting things during this:

1. Often I would need to change the P and D parameters together to get the avg
CTE to go down. Changing each one independently often resulted in higher error,
but making both of the changes at the same time lowered the error. This makes
some sense to me as they are related in much the same way as a spring-and-damper
system.

2. The values that had the minimum average CTE for one whole lap resulted in a
very un-human driving style, whereby the car would either drive mostly straight
and then make all turns as nearly full steering lock, or would swerve back and
forth on the turns but handle the straights well. As such, I decreased the P
value and increased the D value, which resulted in a smoother, more human-like
driving style.


## NOTE:

I added a boolean flag `FAST_MODE` that lets the throttle value go up to 1.0 if
the car is tracking straight. It results in the pretty agressive and wild turns,
but the car does get (barely!) around the track much faster with it set to
`true`.

