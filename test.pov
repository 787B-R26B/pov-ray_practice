#include "shapes.inc"
#include "colors.inc"
#include "textures.inc"
#include "woods.inc"

/* object {
        Cube 
        scale 0.8 
        pigment { color White }
        }
*/

// 床
object { Plane_XZ pigment { color Gray } }


//object { Cylinder_Z scale 0.1 translate <0.4, 0.2, 0.2> pigment {color White }}

object { 
cylinder { <0.5,0,-2>, <0.5,0,2>, 0.03 }
texture { pigment { color White}}
translate 0.5*y
}

object {
	cylinder { <-0.5,0,-2> ,<-0.5, 0,2>,0.03 }
	texture { pigment {color White }}
	translate 0.5*y
}

object {
	cylinder { <-0.5 ,0.5, 0> , <0.5,0.5,0>,0.03 }
	texture {pigment {color White}}
	
}

// 座標軸
merge {
	object { Cylinder_X scale 0.02 pigment { color Red } }		// x軸
	object { Cylinder_Y scale 0.02 pigment { color Green } }	// y軸
	object { Cylinder_Z scale 0.02 pigment { color Blue } }		// z軸
}

// 背景
background { color LightBlue }

// 照明
light_source {
	<10, 15, -20>			// 照明の位置
	color White*2.0			// 照明光の色
	parallel point_at <0, 0, 0>	// 照射先の位置
}

camera{
	location <10.0, 15.0, -40.0>	// カメラの位置
	look_at	<0.0, 0.80, 0.0>	// 注目先の位置
	angle 5				// カメラの視野角
}