#include "shapes.inc"
#include "colors.inc"

object {
        Disk_Y
        pigment { color White }
}

background { color LightBlue }

light_source {
  <10, 15, -20>
  color White*2.0
  parallel point_at <0, 0, 0>
}

camera {
        location <10.0, 10.0, -15.0>
        look_at <0.0, 0.0, 0.0>
        angle 20
}

