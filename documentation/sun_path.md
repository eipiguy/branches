Sun Path:
- Finite, discretized path
- Inputs:
    - time sequence
    - num steps in sequence
- Outputs:
    - Compass Angle From East ( -180 deg, 180 deg )
    - Elevation Angle ( 0 deg, 90 deg )

Each position is essentially a vector. Change from format above into Cartesian coordinates. Then for each leaf you take a projection to a plane normal to that vector, and on to a line parallel to that vector. The parallel line gives depth for occlusion order, and the normal plane can be subdivided into discretized sections to form the columns of occlusion.

This must be done for each discretized part of the sun's path
