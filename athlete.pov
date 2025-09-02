// ピク太郎（ピクトグラム男）の利用例

#include "shapes.inc"		// 基本形状の組み込み
#include "colors.inc"		// 色名の組み込み
#include "pictaro25.inc"		// ピクトグラム男の組み込み

// 選手の定義（基準点：腰）
#declare Athlete = union {
	union {				// 上体
		object { Torso }			// 胴
		object { Head translate y*HeadY }	// 頭
		object { LeftArm(60, 30, 15, 0, Null) }		// 左腕
		object { RightArm(90, 30, 15, 90, Null) }	// 右腕
		rotate -0*x		// 上体前傾
	}
	object { Hip }				// 腰
	object { LeftLeg(90, 30, 15, 0, Null) }	// 左脚
	object { RightLeg(0, 0, 0, 0, Null) }	// 右脚

//	translate 0*y		// 腰の中心が原点
	translate LegL*y	// 脚の長さだけ持ち上げ（伸ばした脚で着地）
//	translate -LeftFootPos	// 左足を原点に着ける（左足で踏む）
//	translate -RightFootPos	// 右足を原点に着ける（右足で踏む）
//	translate -y*LeftFootPos.y	// 左足を地面に着ける（左足で着地）
//	translate -y*RightFootPos.y	// 右足を地面に着ける（右足で着地）
}
/*
LeftArm(A, Y, Z, X, Eqp) 等の使用方法
A：肘を曲げる（腕を縮める）角度
	0 なら曲げない．
	90 なら直角に曲げ，肘を45度だけ後へ引く．
Y：肘を外へ張る（脇を開ける）角度
Z：腕を横へ開く（羽ばたく）角度
X：腕を前へ出す（腕を振る）角度
Eqp：手に持つ用具等のオブジェクト
	何か持たせる場合は object { ... }
	何も持たない場合は Null
*/

// 選手の配置
object { Athlete rotate   0*y translate  0*x }
object { Athlete rotate  90*y translate -1*x }
object { Athlete rotate -90*y translate  1*x }

// 地面
object { Plane_XZ
	pigment { color ForestGreen }
	normal { bumps 0.2 scale 0.01 }
}

/*
// 座標軸
union {
	object { Cylinder_X scale 0.02 pigment { color Red } }		// x軸
	object { Cylinder_Y scale 0.02 pigment { color Green } }	// y軸
	object { Cylinder_Z scale 0.02 pigment { color Blue } }		// z軸
	no_shadow
}
*/

// 背景
background { color LightBlue }

// 照明
light_source {
	<-10,  15, -20>			// 照明の位置
	color White*1.5			// 照明光の色
	parallel point_at <0, 0, 0>	// 照射先の位置
}

// カメラ
camera {
	location <-1.0, 1.5, -10.0>	// カメラの位置
	look_at	<0.0, 1.0, 0.0>		// 注目先の位置
	angle 20			// カメラの視野角
}

