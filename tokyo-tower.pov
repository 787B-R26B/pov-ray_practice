#include "colors.inc"
#include "textures.inc"

camera {
  location  <25, 30, -90> 
  look_at   <0, 15, 0>   
  angle     25            
}

light_source {
  <100, 150, -200> 
  color White     
}

plane {
  y, 0 
  pigment { color Gray70 }
}


#declare TokyoTower = union {
  cone {
    <0, 0, 0>, 6.0,  
    <0, 20, 0>, 2.5 
    pigment { color Red }
  }

  cone {
    <0, 20, 0>, 2.5,
    <0, 30, 0>, 1.0
    pigment { color Red }
  }

  cylinder {
    <0, 14, 0>,
    <0, 16, 0>, 
    3.5        
    pigment { color White }
  }

  cylinder {
    <0, 16, 0>,
    <0, 16.5, 0>,
    3.0
    pigment { color Red }
  }

  cylinder {
    <0, 30, 0>,
    <0, 38, 0>,
    0.5
    pigment { color White }
  }
  
  cylinder {
    <0, 30, 0>,
    <0, 38, 0>,
    0.3
    pigment { color Red }
  }

}

object {
  TokyoTower
}