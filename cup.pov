#include "shapes.inc"
#include "colors.inc"
#include "textures.inc"

global_settings { charset utf8 }

#declare cup = difference {
  object { Disk_Y }
  object { Disk_Y scale <0.9,0.9,0.9> translate <0.0,0.0,0.3> }
  pigment { color White }
  }


merge {
  object { Cylinder_X scale 0.02 pigment { color Red } }
  object { Cylinder_Y scale 0.02 pigment { color Green } }
  object { Cylinder_Z scale 0.02 pigment { color Blue } }
  }
object { cup }
background {color LightBlue }
light_source {
  <10, 15, -20>
  color White*2.0
  parallel point_at <0, 0, 0>
}

camera {
  location <10.0, 10.0, -40.0>
  look_at <0.0, 0.50, 0.0>
  angle 5
}


