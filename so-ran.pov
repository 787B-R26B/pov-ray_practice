#include "shapes.inc"
#include "colors.inc"
#include "pictaro25.inc"
#include "woods.inc"

/*#declare naruko = object {

}
*/

#declare Pictaro = union {
	union {
		object { Torso }
		object { Neck(Head0, 0, 0, 10) Rot2(0*x, 0*y) }	
		object { LtArm(0, 0, 0, 120, Null) Rot2(0*z, 0*y) }	
		object { RtArm(90, 90, -30, -20, Null) Rot2(0*z, 0*y) }	
		transform { ToUpper Rot2(0*y, -40*x) }
	}
	union {
		object { Hip }
		object { LtLeg(120, 10, 10, 10, Null) }
		object { RtLeg(120, 10, 10, 10, Null) }
	}
	pigment { color Orange }
	translate -LtFootPos
}

#declare mirror = object {
	box { <-4, -0.1, 0>, <4, 5, 0.1> }

    texture {
        pigment { color Black }
        finish {
            reflection { 1.0 }
            phong 0.9
        }
    }
}

object { Pictaro rotate  0*y translate <0, 0, 2.5> }

object { Pictaro pigment {color Blue} rotate 0*y translate <1.5,0,2.5> }

object { Pictaro pigment {color Red} rotate 0*y translate < -1.5, 0, 2.5 > } 

object { mirror
    translate <0, 0, 5>
	}
// 地面
object { Plane_XZ
	texture { T_Wood9
	rotate y*45
	 }
/*	pigment { color ForestGreen }
	normal { bumps 0.2 scale 0.01 }
	*/
}

background { color LightBlue }

// 照明
light_source {
	<3, 10, -20>			// 照明の位置
	color White*1.5			// 照明光の色
	parallel point_at <0, 0, 0>	// 照射先の位置
}

// カメラ
camera {
	location <1, 2.0, -10.0>	// カメラの位置
	look_at	<0.0, 1.0, 0.0>		// 注目先の位置
	angle 20			// カメラの視野角
}
