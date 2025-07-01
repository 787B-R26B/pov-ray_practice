#include "shapes.inc"		// 基本形状の組み込み
#include "colors.inc"		// 色名の組み込み

global_settings { charset utf8 }	// 日本語テキスト用の設定

// モデル
object {
  Cube			// 球体（中心位置 <0,0,0>，半径 1）
 	pigment { color White }
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
camera {
	location <10.0, 10.0, -15.0>	// カメラの位置
	look_at	<0.0, 0.0, 0.0>		// 注目先の位置
	angle 20			// カメラの視野角
}

