#include "shapes.inc"		
#include "colors.inc"		
#include "textures.inc"		
#include "woods.inc"

#declare Leg = intersection {
	object { Cone_Y scale <0.05, 2.0, 0.05> translate 2.0*y }
	object { Disk_Y scale 0.65*y }
	translate -0.65*y
	scale -1*y
  texture { DMFWood4 scale 0.3 rotate 91*x }
}

#declare Edge_X = object { Disk_X scale <0.55, 0.10, 0.05> }	// 前後
#declare Edge_Z = object { Disk_Z scale <0.05, 0.10, 0.4> }	// 左右
#declare Corner = object { Sphere scale <0.05, 0.1, 0.05> }	// 角

#declare Top = intersection {
	merge {
		object { Cube scale <0.55, 0.10, 0.4> }	// 本体

		object { Edge_X translate  0.4*z }	// 後端
		object { Edge_X translate -0.4*z }	// 前端
		object { Edge_Z translate  0.55*x }	// 右端
		object { Edge_Z translate -0.55*x }	// 左端

		object { Corner translate < 0.55, 0,  0.4> }	// 右後角
		object { Corner translate < 0.55, 0, -0.4> }	// 右前角
		object { Corner translate <-0.55, 0,  0.4> }	// 左後角
		object { Corner translate <-0.55, 0, -0.4> }	// 左前角
	}
	object { Cube translate 1*y }			// 上半分にスライス
  texture {DMFWood4 scale 0.3 rotate 92*y rotate 2*z translate <0.0, -0.65, 0.1>
  }
  finish { specular 0.8
           reflection 0.3
           }

}



#declare Stool_Seat = union {
  // differenceで木の円盤から中央をくり抜く
  difference {
    cylinder { <0, 0.45, 0>, <0, 0.5, 0>, 0.2 material { M_Wood } }
    cylinder { y*0.4, y*0.51, 0.08 }
  }
  // くり抜いた中央にレジンをはめ込む
  cylinder { <0, 0.45, 0>, <0, 0.5, 0>, 0.08 material { M_Resin } }
}

// 椅子の脚
#declare Stool_Leg = cylinder {
  <0, 0, 0>, <0, 0.45, 0>, 0.015
  material { M_Steel }
}

// 椅子本体の組み立て
#declare Matching_Stool = union {
  object { Stool_Seat }
  // 3本の脚を120度ずつ回転させて配置
  object { Stool_Leg rotate z*-15 translate <0.12, 0, 0> }
  object { Stool_Leg rotate z*-15 translate <0.12, 0, 0> rotate y*120 }
  object { Stool_Leg rotate z*-15 translate <0.12, 0, 0> rotate y*240 }
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

// カメラ
camera{
	location <10.0, 10.0, -15.0>	// カメラの位置
	look_at	<0.0, 0.50, 0.0>	// 注目先の位置
	angle 5				// カメラの視野角
}
