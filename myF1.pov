#include "F1.inc"
#include "colors.inc"
#include "shapes.inc"

// F1 マシン
merge {
  // マシン本体
  merge {
    object { AeroBody }
    object { FrontLeg2(1.0) translate <0, 0, -0.30> }
    object { RearLeg2 translate <0, 0, 0.20> }
    object { AeroNose1 }
    object { AeroSide2 }
    object { FrontWing3 translate <0, 0, -0.30> }
    object { RearWing3 }
    pigment { color Red }
  }

  // ドライバー
  merge {
    object { Driver }
    object { Helmet2 }
    object { Shield }
  }

    translate <0, 0.30, 0>
}

object{ Ground }
sky_sphere { Fine }

// 座標軸
/*
object { Cylinder_X scale 0.02 pigment { color Red } }    // x軸
object { Cylinder_Y scale 0.02 pigment { color Green } }  // y軸
object { Cylinder_Z scale 0.02 pigment { color Blue } }   // z軸
*/

// 背景
background { color LightBlue }

// 照明
light_source {
  < 100, 200,  -100>  // 照明の位置
  color White*1.0
  parallel point_at <0, 0, 0>
}

// カメラ
camera {
  location <5.0, 2.0, 8.0>  // カメラの位置
  look_at <0.0, 1.0, 0.0>    // 注目先の位置
  angle 25  		     // 視野角
}

