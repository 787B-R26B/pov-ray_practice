#include "shapes.inc"
#include "colors.inc"
#include "pictaro25.inc"

/*#declare menko = union {

}
*/

#declare Pictaro = union {
	union {			// 上半身
		object { Torso }		// 胴
		object { Neck(Head0, 0, 0, 10) Rot2(0*x, 0*y) }	// 頭頸部
		object { LtArm(0, 0, 0, 120, Null) Rot2(0*z, 0*y) }	// 左腕
		object { RtArm(90, 90, -30, -20, Null) Rot2(0*z, 0*y) }	// 右腕
		transform { ToUpper Rot2(0*y, -40*x) }
	}
	union {			// 下半身
		object { Hip }			// 腰
		object { LtLeg(120, 10, 10, 10, Null) }	// 左脚
		object { RtLeg(120, 10, 10, 10, Null) }	// 右脚
	}
	pigment { color Orange }	// 体色変更（Chestは白のまま）
	translate -LtFootPos	// 左足を原点に着ける
}
object { Pictaro rotate  0*y translate <0, 0, 2.5> }

object { Pictaro pigment {color Blue} rotate 0*y translate <1.5,0,2.5> }

// 地面
object { Plane_XZ
	pigment { color ForestGreen }
	normal { bumps 0.2 scale 0.01 }
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
	location <0, 2.0, -10.0>	// カメラの位置
	look_at	<0.0, 1.0, 0.0>		// 注目先の位置
	angle 20			// カメラの視野角
}
