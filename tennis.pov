// tennis.pov
// ピク太郎（ピクトグラム男）の利用例

#include "shapes.inc"		// 基本形状の組み込み
#include "colors.inc"		// 色名の組み込み
#include "pictaro25.inc"	// ピクトグラム男の組み込み

// バイザーの定義
#declare Visor = intersection {
	object { Disk_Z translate -1*z }
	object { Disk_X translate 1*y }
	scale <1, 0.5, 1.5>*HeadR
	pigment { color DimGray }
}

// ラケットの定義
#declare Racket = union {
	object { Disk_Z translate -1*z scale <0.02, 0.02, 0.15> }
	object { torus { 0.15, 0.02 } rotate 90*z translate -0.45*z }
	pigment { color DimGray }
}

// ボールの定義
#declare Ball = object { Sphere scale 0.05 pigment { color Yellow } }

// 選手の定義（基準点：腰の中心）
#declare Athlete = union {
	union {		// 上半身
		object { Torso }	// 胴
		object {			// 頭頸部
	//		Head				// 標準の頭
			HeadNeck(0, 0, 45, Visor)	// 装具交換可能な頭
	//		Neck(Head0, 0, 0, 0)		// 頭部交換可能な首
			rotate -15*x rotate 15*y	// 頸部の動作
		}
		object { LtArm(120, 30, 0, 30, Null)	// 左腕
			rotate 0*z rotate -15*y		// 肩部の動作
		}
		object { RtArm(30, 45, 0, 90,
			object { Racket rotate -60*x })	// 右腕
			rotate -0*z rotate -15*y	// 肩部の動作
		}
			// 頸部・肩部の動作の基準点：胸の中心
			// （項垂れ・猫背・等の表現にどうぞ）
		transform { ToUpper rotate -15*y rotate -15*x }
			// 腰との連結，上体の動作
			// 上体の動作の基準点：腰の中心
	}
	union {		// 下半身
		object { Hip }		// 腰
		object { LtLeg(120, 30, 15, 0, Null) }	// 左脚
		object { RtLeg(30, 0, 0, -30, Null) }	// 右脚
	}
	// 全体の基準点変更
//	translate 0*y		// 腰の中心が原点
//	translate LegL*y	// 脚の長さだけ持ち上げ（伸ばした脚で着地）
//	translate -LtFootPos	// 左足を原点に着ける（左足で踏む）
	translate -RtFootPos	// 右足を原点に着ける（右足で踏む）
//	translate -y*LtFootPos.y	// 左足を地面に着ける（左足で着地）
//	translate -y*RtFootPos.y	// 右足を地面に着ける（右足で着地）
}
/*
■LeftArm(A, Y, Z, X, Eqp) 等の使用方法
A：肘を曲げる（腕を縮める）角度
	0 なら曲げない．
	90 なら直角に曲げ，肘を45度だけ後へ引く．
Y：肘を外へ張る（脇を開ける）角度
Z：腕を横へ開く（羽ばたく）角度
X：腕を前へ出す（腕を振る）角度
Eqp：手に持つ用具等のオブジェクト
	何か持たせる場合は object { ... }
	何も持たない場合は Null

■HeadNeck(L, R, T, Eqp) 等の使用方法
L：顔を傾げる角度	正なら右，負なら左．
R：顔を振る角度		正なら右，負なら左．
T：顔を上げる角度	正なら上，負なら下．
Eqp：頭に付ける用具等のオブジェクト
	Neck()なら頭も交換可能
*/

// 選手の配置
object { Athlete rotate  0*y translate <0, 0, 2.5> }

SetColor(NeonPink)
object { Athlete rotate  60*y translate <1.5, 0, 0> }
ResetColor()

object { Athlete pigment { color Orange } rotate -60*y translate <-2, 0, 1> }

object { Ball translate <0, 2, 0> }

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

