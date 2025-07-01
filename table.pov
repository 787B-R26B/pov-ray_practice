#include "shapes.inc"		// 基本形状の組み込み
#include "colors.inc"		// 色名の組み込み
#include "textures.inc"		// 様々なテクスチャの組み込み
#include "woods.inc"		// 木目テクスチャの組み込み

global_settings { charset utf8 }	// 日本語用の設定

// ---- パーツ定義 -----------------------------------------------------

// 脚のパーツ定義
// （同じ形を複数個使うので，定義しておくと効率的）
#declare Leg = intersection {
	object { Cone_Y scale <0.05, 2.0, 0.05> translate 2.0*y }
	object { Disk_Y scale 0.65*y }
	translate -0.65*y
	scale -1*y
  texture { DMFWood4 scale 0.3 rotate 91*x }
}

// 天板の端部のパーツ定義
// （同じ形を複数個使うので，定義しておくと効率的）
#declare Edge_X = object { Disk_X scale <0.55, 0.10, 0.05> }	// 前後
#declare Edge_Z = object { Disk_Z scale <0.05, 0.10, 0.4> }	// 左右
#declare Corner = object { Sphere scale <0.05, 0.1, 0.05> }	// 角

// 天板のパーツ定義
// （一枚だけしか使わないけど，全体の組み立てが分かり易くなるので，
// Table とは別に定義しておく）
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

// テーブルの定義
// （すべての部品を事前に定義しておいたので，コードが短く分かり易いよね？）
#declare Table = merge {
	object { Top translate 0.65*y }			// 天板

	object { Leg translate < 0.55, 0.0,  0.4> }	// 脚
	object { Leg translate < 0.55, 0.0, -0.4> }
	object { Leg translate <-0.55, 0.0,  0.4> }
	object { Leg translate <-0.55, 0.0, -0.4> }
}

/* #declare cup = difference {
    object { Disk_Y scale 0.4 translate 2*y }
    object { Disk_Y scale 0.3 translate 3*y }
    pigment {color white }
} */

// ---- シーン ---------------------------------------------------------

// テーブルの配置
object { Table }
//object { cup }
// 床
object { Plane_XZ pigment { color Gray } }

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

