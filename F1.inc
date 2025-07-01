// 釧路高専情報工学科 体験入学 2006.11.11
// POV-Ray でオリジナル F1 マシンの CG を作ろう
//
// パーツ定義ファイル
//
// (c) 2006, yanagawa@kushiro-ct.ac.jp
//
#include "colors.inc"
#include "shapes.inc"
#include "textures.inc"
#include "stones.inc"
#include "glass.inc"

#default {
	finish { ambient 0.3 diffuse 0.7 reflection 0.2 }
	pigment { color White }
}

#declare Polished = finish {
	ambient 0.3 diffuse 0.7 reflection 0.2
}
#declare Smooth = finish {
	ambient 0.3 diffuse 0.7 reflection 0.0
}
//
// 足回り
//
#declare Tire = merge {		// タイヤ原型（半径 1m，半幅 1m）
	merge {
		difference{
			object{ Disk_X scale <1.0, 1.0, 1.0> }
			object{ Disk_X scale <2.0, 0.5, 0.5> }
		}
		torus { 0.75, 0.25 rotate 90*z translate -1*x }
		torus { 0.75, 0.25 rotate 90*z translate  1*x }
		pigment { color Gray20 }
		finish { Smooth }
	}
	object { Disk_X scale <0.8, 0.5, 0.5> texture { Silver1 } }
}
#declare Shaft = object { Disk_X texture{Silver1} }	// 車軸原型

#declare ShockL = object {				// ショック太
	Disk_X scale <0.15, 0.05, 0.05> rotate z*-45
	texture { Silver1 }
}
#declare ShockS = object {				// ショック細
	Disk_X scale <0.15, 0.025, 0.03> rotate z*-45
	texture { Silver1 }
}
#declare SusArm1 = merge {
	object { Disk_X translate -1*x		// 後
		scale <0.3, 0.025, 0.025> rotate  15*y }
	object { Disk_X translate -1*x		// 前
		scale <0.3, 0.025, 0.025> rotate -15*y }
	pigment { color Gray40 }
	finish { Smooth }
}
#declare FrontSus1 = merge {	// 左側
	object { SusArm1 translate  0.1*y }	// 上アーム
	object { SusArm1 translate -0.1*y }	// 下アーム
	object { ShockL translate -0.25*x }
	translate 0.85*x
}
#declare RearSus1 = merge {	// 左側
	object { SusArm1 translate  0.1*y }	// 上アーム
	object { SusArm1 translate -0.1*y }	// 下アーム
	object { ShockS translate <-0.15, 0.0, -0.125> }
	object { ShockS translate <-0.15, 0.0,  0.125> }
	translate 0.7*x
}
#declare FrontTire1 = merge {
	object { Tire scale <0.1, 0.3, 0.3> }
	object { Shaft scale <0.1, 0.05, 0.05> }
}
#declare RearTire1 = merge {
	object { Tire scale <0.2, 0.325, 0.325> }
}
#macro FrontLeg1(ANGLE)
merge {
	object { FrontSus1 scale -1*x }
	object { FrontSus1 }
	object { FrontTire1 translate -0.1*x rotate ANGLE*y translate -0.8*x }
	object { FrontTire1 translate  0.1*x rotate ANGLE*y translate  0.8*x }
	translate <0.0, 0.0, -1.2>
}
#end
#declare RearLeg1 = merge {
	object { RearSus1 scale -1*x }
	object { RearSus1 }
	object { Shaft scale <1.1, 0.05, 0.05> }
	object { RearTire1 translate -0.9*x }
	object { RearTire1 translate  0.9*x }
	translate <0.0, 0.025, 1.2>
}
#declare FrontLeg = object { FrontLeg1(0) }
#declare RearLeg = object { RearLeg1 }

#declare SusArm2 = merge {
	object { Disk_X scale <0.80, 0.015, 0.05> translate -0.05*z }
	object { Disk_X translate -1*x
		scale <0.3, 0.0125, 0.025> rotate  30*y
		translate  0.8*x }
	object { Disk_X translate  1*x
		scale <0.3, 0.0125, 0.025> rotate -30*y
		translate -0.8*x }
}
#declare SusArms2 = merge {
	object { SusArm2 translate  0.1*y }
	object { SusArm2 translate -0.1*y }
	pigment { color Gray40 }
	finish { Smooth }
}
#declare FrontTire2 = merge {
	object { Tire scale <0.15, 0.3, 0.3> }
	object { Shaft scale <0.15, 0.05, 0.05> }
}
#declare RearTire2 = object { Tire scale <0.2, 0.3, 0.3> }
#macro FrontLeg2(ANGLE)
merge {
	object { FrontTire2 translate -0.1*x rotate ANGLE*y translate -0.75*x }
	object { FrontTire2 translate  0.1*x rotate ANGLE*y translate  0.75*x }
	object { SusArms2 }
	translate <0.0, 0.0, -1.2>
}
#end
#declare RearLeg2 = merge {
	object { RearTire2 translate -0.8*x }
	object { RearTire2 translate  0.8*x }
	object { Shaft scale <1.0, 0.05, 0.05> }
	object { SusArms2 scale -1*z }
	translate <0.0, 0.0, 1.2>
}
//
// 車体回り（丸形）
//
#declare Pipe = difference {	// 排気管
	object { Disk_Z scale <0.05, 0.05, 0.10> texture{Silver1} }
	object { Disk_Z scale <0.04, 0.04, 0.05> translate 0.1*z
		pigment{color Gray20} finish { Smooth } }
}
#declare RoundBody = merge {		// 丸形ボディ
	difference {
		object { Disk_Z scale <0.5, 0.25, 1.75> }	// 本体
		object {					// 運転席
			Cube scale <0.3, 0.25, 0.5>
			translate <0.0, 0.25, 0.0>
			pigment{color Gray}
			finish { Smooth }
		}
	}
	difference {			// フード
		merge {
			object {				// 運転席前部
				Cone_Z scale <0.3, 0.2, -0.5>
				translate <0.0, 0.2, -1.0>
			}
			object {				// 運転席後部
				Cone_Z scale <0.3, 0.4, 0.65>
				translate <0.0, 0.2, 1.15>
			}
		}
		object { Disk_Z scale <0.5, 0.25, 2.0> }
	}
	object { Pipe translate <-0.4, 0.0, 1.70> }	// 排気管
	object { Pipe translate <-0.2, 0.0, 1.70> }
	object { Pipe translate < 0.2, 0.0, 1.70> }
	object { Pipe translate < 0.4, 0.0, 1.70> }
	//finish { Polished }
}
#declare RoundNose1 = intersection {	// ノーズキャップ
	object { Sphere scale <0.5, 0.25, 1.0> }
	object { Cube translate -1.0*z scale <0.5, 0.5, 1.0> }
	translate <0.0, 0.0, -1.75>
	//finish { Polished }
}
#declare RoundNose2 = difference {	// ノーズラジエータ
	intersection {
		object { Sphere scale <0.5, 0.25, 1.5> }
		object { Cube scale <0.5, 0.25, 0.5> translate -0.5*z }
	}
	object {
		Disk_Z scale <0.3, 0.15, 0.25> translate -1*z
		pigment {color Gray}
		finish { Smooth }
	}
	translate <0.0, 0.0, -1.75>
	//finish { Polished }
}
#declare SideGap = object {		// 運転席えぐり
	Cube scale <0.300001, 2.0, 2.0>
	pigment {color Gray}
	finish { Smooth }
}
#declare RS1inner = object {		// ラジエータ開口部
	Disk_Z scale <0.15, 0.15, 0.4>
	pigment {color Gray}
	finish { Smooth }
}
#declare RS1sub = difference {
	object { Disk_Z scale <0.2, 0.2, 0.5> }
	object { RS1inner translate -0.5*z }
	object { RS1inner translate  0.5*z }
}
#declare RoundSide1 = difference {		// 丸形コンパクト
	merge {
		object { RS1sub translate <-0.45, -0.05, 0.0> }
		object { RS1sub translate < 0.45, -0.05, 0.0> }
	}
	object { SideGap }
	//finish { Polished }
}
#declare RS2inner = object {			// ラジエータ開口部
	Disk_Z scale <0.95, 0.15, 0.4>
	pigment {color Gray}
	finish { Smooth }
}
#declare RoundSide2 = difference {		// 丸形ワイド
	object { Disk_Z scale <1.0, 0.2, 0.8> translate < 0.0, -0.05, 0.0> }
	object { RS2inner translate <0.0, -0.05, -0.8> }
	object { RS2inner translate <0.0, -0.05,  0.8> }
	object { SideGap }
	//finish { Polished }
}
//
// 車体回り（角形）
//
#declare BoxyBody = merge {		// 角形ボディ
	difference {
		object { Cube scale <0.4, 0.25, 1.75> }	// 本体
		object {				// 運転席
			Cube scale <0.3, 0.5, 0.5>
			translate <0.0, 0.25, 0.0>
			pigment{color Gray}
			finish { Smooth }
		}
	}
	intersection {			// 運転席前部フード
		object { Disk_X scale <0.3, 0.45, 2.0> translate <0.0, 0.0, 1.0> }
		object { Disk_Z scale <0.3, 0.25, 1.0> translate <0.0, 0.25, 0.0> }
		object { Cube scale <0.4, 0.25, 1.0> translate <0.0, 0.5, -1.0> }
		translate <0.0, 0.0, -0.5>
	}
	difference {			// 運転席後部フード
		intersection {
			object { Disk_X scale <0.3, 0.7, 1.0> }
			object { Disk_Z scale <0.3, 0.5, 1.0> translate <0.0, 0.25, 0.0> }
			object {
				Cube scale <0.4, 0.45, 1.0>
				translate <0.0, 0.7, 1.0>
			}
		}
		object {		// エアダクトえぐり
			Cube scale <0.1, 0.05, 0.2>
			translate <0.0, 0.6, 0.0>
			pigment{color Gray}
			finish { Smooth }
		}
		translate <0.0, 0.0, 0.5>
	}
	object { Pipe translate <-0.3, 0.1, 1.7> }	// 排気管
	object { Pipe translate <-0.2, 0.0, 1.7> }
	object { Pipe translate < 0.2, 0.0, 1.7> }
	object { Pipe translate < 0.3, 0.1, 1.7> }
	//finish { Polished }
}
#declare BoxyNose1 = intersection {	// ミドル
	object { Disk_X scale <0.4, 0.25, 1.0> }
	object { Disk_Y scale <0.4, 1.0, 1.5> }
	object { Cube translate -1*z scale <0.5, 0.5, 1.0> }
	translate <0.0, 0.0, -1.75>
	//finish { Polished }
}
#declare BoxyNose2 = intersection {	// キックダウン
	object { Disk_X scale <0.4, 0.5, 1.0> }
	object { Disk_Y scale <0.4, 1.0, 1.5> }
	object { Cube translate <0.0, 1.0, -1.0> }
	translate <0.0, -0.25, -1.75>
	//finish { Polished }
}
#declare BoxyNoseN1 = intersection {	// 巾狭ミドル
	object { Disk_X scale <0.4, 0.25, 1.0> }
	object { Disk_Y scale <0.4, 1.0, 1.0> }
	object { Cube translate -1*z scale <0.5, 0.5, 1.0> }
	translate <0.0, 0.0, -1.75>
	//finish { Polished }
}
#declare BoxyNoseN2 = intersection {	// 巾狭キックダウン
	object { Disk_X scale <0.4, 0.5, 1.0> }
	object { Disk_Y scale <0.4, 1.0, 1.0> }
	object { Cube translate <0.0, 1.0, -1.0> }
	translate <0.0, -0.25, -1.75>
	//finish { Polished }
}
#declare BoxyNoseR1 = intersection {	// 丸形アップ
	object { Sphere scale <1.5, 0.75, 10.0> translate 9*z }
	object { Cube translate -1*z scale <0.4, 0.25, 0.5> }
	translate <0.0, 0.0, -1.75>
	//finish { Polished }
}
#declare BoxyNoseR2 = intersection {	// 丸形キックダウン
	object { Sphere scale <1.5, 1.5, 10.0> translate 9.0*z }
	object { Cube translate <0, 1, -1> scale <0.4, 0.25, 0.5> }
	translate <0.0, -0.25, -1.75>
	//finish { Polished }
}

#declare BS1inner = object {
	Cube scale <0.75, 0.15, 0.4>
	pigment {color Gray}
	finish { Smooth }
}
#declare BoxySide1 = difference {		// 角形コンパクト
	object { Cube scale <0.8, 0.2, 0.5> translate <0.0, -0.05, 0.0> }
	object { BS1inner translate <0.0, -0.05, -0.5> }
	object { BS1inner translate <0.0, -0.05,  0.5> }
	object { SideGap }
	//finish { Polished }
}
#declare BS2inner = object {
	Cube scale <0.95, 0.15, 0.4>
	pigment {color Gray}
	finish { Smooth }
}
#declare BoxySide2 = difference {		// 角形ワイド
	object { Cube scale <1.0, 0.2, 0.8> translate <0.0, -0.05, 0.0> }
	object { BS2inner translate <0.0, -0.05, -0.8> }
	object { BS2inner translate <0.0, -0.05,  0.8> }
	object { SideGap }
	//finish { Polished }
}
//
// 車体回り（エアロ）
//
#declare AeroNose1 = intersection {		// アップ
	object { Disk_X scale <1.00, 0.3, 1.0> }
	object { Disk_Y scale <0.25, 1.0, 1.25> }
	object {
		Cube scale <0.25, 0.3, 1.0>
		translate <0.0, -0.3, -1.0>
	}
	translate <0.0, 0.25, -1.75>
}
#declare AeroNose2 = intersection {		// ミドル
	object { Disk_X scale <1.00, 0.15, 1.0> }
	object { Disk_Y scale <0.25, 1.0, 1.25> }
	object { Cube scale <0.25, 0.3, 1.0> translate -1.0*z }
	translate <0.0, 0.10, -1.75>
}
#declare AeroNose3 = intersection {		// キックダウン
	object { Disk_X scale <1.00, 0.3, 1.0> }
	object { Disk_Y scale <0.25, 1.0, 1.25> }
	object {
		Cube scale <0.25, 0.3, 1.0>
		translate <0.0, 0.3, -1.0>
	}
	translate <0.0, -0.05, -1.75>
}
#declare AeroNoseN1 = intersection {		// 巾狭アップ
	object { Disk_X scale <1.00, 0.3, 1.0> }
	object { Disk_Y scale <0.25, 0.3, 1.0> }
	object {
		Cube scale <1.0, 0.3, 1.0>
		translate <0.0, -0.3, -1.0>
	}
	translate <0.0, 0.25, -1.75>
}
#declare AeroNoseN2 = intersection {		// 巾狭ミドル
	object { Disk_X scale <1.00, 0.15, 1.0> }
	object { Disk_Y scale <0.25, 0.3, 1.0> }
	object { Cube scale <0.25, 0.3, 1.0> translate -1.0*z }
	translate <0.0, 0.10, -1.75>
}
#declare AeroNoseN3 = intersection {		// 巾狭キックダウン
	object { Disk_X scale <1.00, 0.3, 1.0> }
	object { Disk_Y scale <0.25, 0.3, 1.0> }
	object {
		Cube scale <1.0, 0.3, 1.0>
		translate <0.0, 0.3, -1.0>
	}
	translate <0.0, -0.05, -1.75>
}
#declare AeroBody = merge {		// 空力ボディ
	difference {
		object { Cube scale <0.4, 0.25, 1.75> }	// 本体

		object { Disk_Y scale <0.5, 1.0, 1.75>	// 前部側面えぐり
			translate <-0.75, 0.0, -1.75> }
		object { Disk_Y scale <0.5, 1.0, 1.75>
			translate < 0.75, 0.0, -1.75> }

		object {	// 運転席えぐり
			Disk_Y scale <0.3, 0.25, 0.5>
			translate <0.0, 0.25, 0.0>
			pigment{color Gray}
			finish { Smooth }
		}
		object {	// 下部ラジエータ
			Cube scale <0.21, 0.09, 0.25>
			translate <0.0, -0.14, -1.75>
			pigment{color Gray}
			finish { Smooth }
		}

		object { Sphere scale <0.35, 0.20 0.75>	// 後部上面えぐり
			translate < 0.40, 0.25, 1.75> }
		object { Sphere scale <0.35, 0.20 0.75>
			translate <-0.40, 0.25, 1.75> }
	}
	object { Pipe translate <-0.34, 0.19, 1.025> }	// 排気管
	object { Pipe translate < 0.34, 0.19, 1.025> }	// 排気管

	difference {		// 運転席後部フード
		intersection {
			object { Sphere scale <0.25, 0.75, 1.00> translate -0.35*y }
			object {
				Cube scale <0.3, 0.4, 1.0>
				translate <0.0, 0.4, 1.0>
			}
		}
		object {	// エアダクトえぐり
			Disk_Z scale <0.125, 0.1, 0.2>
			translate <0.0, 0.25, 0.0>
			pigment{color Gray}
			finish { Smooth }
		}
		translate <0.0, 0.25, 0.5>
	}
}
/*
#declare AeroBody = merge {		// 空力ボディ
	difference {
		object {	// 本体
			Cube scale <0.4, 0.25, 2.0>
		}
		object {
			Disk_X scale <1.0, 0.2, 0.4>
			translate <0.0, -0.25, -2.0>
		}
		object {	// 前部ラジエータ
			Cube scale <0.35, 0.05, 0.8>
			translate <0.0, -0.15, -2.0>
			pigment {color Gray}
			finish { Smooth }
		}
		object {	// 運転席
			Disk_Y scale <0.3, 0.25, 0.5>
			translate <0.0, 0.25, 0.0>
			pigment{color Gray}
			finish { Smooth }
		}
	}
	difference {		// 運転席後部
		intersection {
			object { Sphere scale <0.25, 0.4, 0.8> }
			object {
				Cube scale <0.3, 0.4, 0.8>
				translate <0.0, 0.4, 0.8>
			}
		}
		object {
			Disk_Z scale <0.125, 0.1, 0.2>
			translate <0.0, 0.25, 0.0>
			pigment{color Gray}
			finish { Smooth }
		}
		translate <0.0, 0.25, 0.5>
	}
	object { Pipe translate <-0.30, 0.15, 2.0> }	// 排気管
	object { Pipe translate <-0.15, 0.15, 2.0> }
	object { Pipe translate < 0.15, 0.15, 2.0> }
	object { Pipe translate < 0.30, 0.15, 2.0> }
//	finish { Polished }
}
#declare AeroNose1 = intersection {		// アップ
	object { Disk_X scale <0.4, 0.3, 0.6> }
	object { Disk_Y scale <0.4, 0.3, 0.6> }
	object {
		Cube scale <0.4, 0.3, 0.6>
		translate <0.0, -0.3, -0.6>
	}
	translate <0.0, 0.25, -2.0>
//	finish { Polished }
}
#declare AeroNose2 = intersection {		// ダウン
	object { Disk_X scale <0.4, 0.15, 0.6> }
	object { Disk_Y scale <0.4, 0.3, 0.6> }
	object {
		Cube scale <0.4, 0.3, 0.6>
		translate <0.0, 0.0, -0.6>
	}
	translate <0.0, 0.1, -2.0>
//	finish { Polished }
}
*/
#declare AS1inner = object {			// ラジエータ開口
	Cube scale <0.65, 0.2, 0.5>
	pigment {color Gray}
	finish { Smooth }
}
#declare AS1sub = object {
//	Disk_Y scale <0.4, 0.25, 0.6>
	Disk_Y scale <0.55, 0.249999, 0.6>
}
#declare AeroSide1 = difference {		// コンパクト
	merge {
		object { AS1sub translate -0.25*x }
		object { AS1sub translate  0.25*x }
	}
	object { AS1inner translate -0.6*z }
	object { AS1inner translate  0.6*z }
	object { SideGap }
	//finish { Polished }
}

#declare AS2inner = object {			// ラジエータ開口部
	Cube scale <0.85, 0.2, 0.5>
	pigment {color Gray}
	finish { Smooth }
}
#declare AS2sub = object {
//	Disk_Y scale <0.6, 0.25, 1.0>
	Disk_Y scale <0.75, 0.249999, 1.0>
}
#declare AeroSide2 = difference {		// ワイド
	merge {
		object { AS2sub translate -0.25*x }
		object { AS2sub translate  0.25*x }
	}
	object { AS2inner translate -1.0*z }
	object { AS2inner translate  1.0*z }
	object { SideGap }
	//finish { Polished }
}
//
// 空力関係
//
#declare FrontWing1 = merge {		// コンパクト
	object { Disk_X scale <0.8, 0.05, 0.15> }
	object { Disk_X scale <0.01, 0.1, 0.15> translate <-0.8, 0.0, 0.0> }
	object { Disk_X scale <0.01, 0.1, 0.15> translate < 0.8, 0.0, 0.0> }
	translate <0.0, 0.0, -2.0>
	//finish { Polished }
}
#declare FrontWing2 = merge {		// ワイド
	object { Disk_X scale <1.0, 0.05, 0.15> }
	object { Disk_X scale <0.01, 0.1, 0.15> translate <-1.0, 0.0, 0.0> }
	object { Disk_X scale <0.01, 0.1, 0.15> translate < 1.0, 0.0, 0.0> }
	translate <0.0, 0.0, -2.0>
	//finish { Polished }
}
#declare FrontWing3 = merge {		// エアロボディー用
	object { Disk_X scale <0.9, 0.05, 0.15> }
	intersection {
		merge {
			object {	// 右フィン
				Disk_X scale <0.01, 0.2, 0.30>
				translate <-0.9, 0.0, 0.15>
			}
			object {	// 左フィン
				Disk_X scale <0.01, 0.2, 0.30>
				translate < 0.9, 0.0, 0.15>
			}
		}
		object {
			Cube scale <1.0, 0.3, 0.15>
			translate <0.0, 0.25, 0.0>
		}
	}
intersection {
object { torus { 0.15 0.025 } rotate 90*x scale <1, 2, 4> }
object { Cube translate 1*y }
}
/*
	object {	// 右ステー
		Disk_Y scale <0.025, 0.15, 0.1>
		translate <-0.15, 0.15, 0.0>
	}
	object {	// 左ステー
		Disk_Y scale <0.025, 0.15, 0.1>
		translate < 0.15, 0.15, 0.0>
	}
*/
	translate <0.0, -0.2, -2.0>
	//finish { Polished }
}

#declare RearWing1 = merge {		// コンパクト
	object { Disk_X scale <0.6, 0.05, 0.2> }
	object { Disk_X scale <0.01, 0.1, 0.2> translate <-0.6, 0.0, 0.0> }
	object { Disk_X scale <0.01, 0.1, 0.2> translate < 0.6, 0.0, 0.0> }
        object { Disk_Y scale <0.05, 0.2, 0.1> translate <0.0, -0.2, 0.0> }
	translate <0.0, 0.5, 1.8>
	//finish { Polished }
}
#declare RearWing2 = merge {		// ワイド
	object { Disk_X scale <1.0, 0.05, 0.2> }
	object { Disk_X scale <0.01, 0.1, 0.2> translate <-1.0, 0.0, 0.0> }
	object { Disk_X scale <0.01, 0.1, 0.2> translate < 1.0, 0.0, 0.0> }
        object { Disk_Y scale <0.05, 0.2, 0.1> translate <-0.2, -0.2, 0.0> }
        object { Disk_Y scale <0.05, 0.2, 0.1> translate < 0.2, -0.2, 0.0> }
	translate <0.0, 0.5, 1.8>
	//finish { Polished }
}
#declare RearWing3 = merge {		// エアロボディー用
	object { Disk_X scale <0.55, 0.05, 0.2> }
	object { Cube scale <0.01, 0.3, 0.2> translate <-0.55, -0.2, 0.0> }
	object { Cube scale <0.01, 0.3, 0.2> translate < 0.55, -0.2, 0.0> }
	object { Disk_X scale <0.55, 0.05, 0.2> translate <0.0, -0.4, 0.0> }
	translate <0.0, 0.4, 1.8>
	//finish { Polished }
}

// to-do
#declare SideFin1 = intersection {
	object { Disk_X scale <1.0, 0.05, 0.4> }
	object { Disk_Y scale <1.0, 0.05, 0.4> }
	object { Disk_Z scale <1.0, 0.05, 0.4> }
	//finish { Polished }
}
#declare SideFin2 = intersection {
	object { Disk_X scale <1.0, 0.05, 0.4> }
	object { Disk_Z scale <1.0, 0.05, 0.4> }
	//finish { Polished }
}
#declare SideFin3 = intersection {
	object { Disk_X scale <1.0, 0.05, 0.4> }
	//finish { Polished }
}

//
// ドライバー関係
//
#declare Gogle = merge {
	intersection {		// フレーム
		difference {
			object { Disk_X scale <1.0, 0.035, 0.06> }
			object { Disk_X scale <2.0, 0.025, 0.05> }
			translate <0, -0.045, -0.125>
			rotate 15*x
		}
		object { Disk_Y scale <0.1, 1.0, 0.125> inverse }
		object { Disk_Y scale <0.125, 1.0, 0.15> }
		pigment { color Gray20 }
		finish { Smooth }
	}
	intersection {		// レンズ
		object { Disk_X scale <1.0, 0.034, 0.059>
			translate <0, -0.045, -0.125>
			rotate 15*x
		}
		object { Disk_Y scale <0.123, 1.0, 0.148> inverse }
		object { Disk_Y scale <0.124, 1.0, 0.149> }
		texture {T_Green_Glass}
//		material { M_Glass }
//		finish { reflection 0.3 }
		finish { conserve_energy }
	}
	translate <0.0, 0.425, 0.25>
}
#declare Shield = difference {
	difference {
		object { Disk_Y scale <0.155, 1.0, 0.180> }
		object { Disk_Y scale <0.152, 2.0, 0.177> }
		translate (-1+0.01)*y
		rotate 15*x
	}
	object { Cube translate <0, -1.055, -1> }
	object { Cube translate <0, 0, 1> rotate 15*x }
	translate <0.0, 0.425, 0.25>
	texture {T_Dark_Green_Glass}
//	material { M_Glass }
//	finish { reflection 0.3 }
	finish { conserve_energy }
}

#declare HelmetOuter = intersection {
	merge {
		object { Sphere scale <0.15, 0.15, 0.175> }
//object { Disk_X scale <0.3, 0.01, 0.01> pigment { color Gray } }
		object { Disk_Y scale <0.15, 0.05, 0.175> translate -0.05*y }
		object { Sphere scale <0.15, 0.15, 0.175> translate -0.10*y }
		rotate 15*x
	}
	object {
		Cube
		translate (1-0.15)*y
		pigment {color Gray20}
		finish { Smooth }
	}
}
#declare HelmetInner = merge {
	object {					// 頭上
		Sphere scale <0.1, 0.1, 0.125>
	}
	object {					// 頭下
		Disk_Y scale <0.1, 0.1, 0.125> translate -0.1*y
	}
	intersection {					// 顎前
		object { Disk_Y scale <0.1, 0.20, 0.175> }
		object { Cube translate <0.0, -1.0, -1.0> }
	}
	pigment { color Gray20 }
	finish { Smooth }
}
#declare Helmet1 = difference {			// ジェット型
	object { HelmetOuter }
	object { HelmetInner }
	merge {
		object { Cube translate <0, -1, -1> }
		object { Cube translate <0, -1, -1> rotate -45*x translate -0.075*y }
		rotate 15*x
		pigment {color Gray20}
		finish { Smooth }
		translate <0.0, 0.0, -0.05>
	}
	translate <0.0, 0.425, 0.25>
//	pigment {color White}
//	finish { Polished }
}
#declare Helmet2 = difference {			// フルフェイス型
	object { HelmetOuter }
	object { HelmetInner }
	difference {
		object { Cube translate <0, -1, -1> rotate 15*x }
		object { Cube scale 1 translate <0, -1.040, -1> }
		pigment {color Gray20}
		finish { Smooth }
		translate <0.0, 0.0, -0.05>
	}
	translate <0.0, 0.425, 0.25>
//	pigment {color White}
//	finish { Polished }
}

#declare StWheel = merge {
	object {		// ハンドル
		torus { 0.225 0.025 rotate 90*x }
		pigment { color Gray20 }
		finish { Smooth }
	}
	difference {		// スポーク
		object { Disk_Z scale <0.225, 0.225, 0.01> }
		object {
			Disk_Z scale <0.5, 0.2, 0.02>
			translate <0.0, 0.275, 0.0>
		}
		object {
			Disk_Z scale <0.2, 0.2, 0.02>
			translate <-0.25, -0.2, 0.0>
		}
		object {
			Disk_Z scale <0.2, 0.2, 0.02>
			translate < 0.25, -0.2, 0.0>
		}
		pigment { color Gray80 }
		finish { Smooth }
	}
	object {		// ボルト
		Disk_Z scale <0.05, 0.05, 0.025>
		pigment {color Gray20}
		finish { Smooth }
	}
	object {		// シャフト
		Disk_Z scale <0.025, 0.025, 0.1>
		translate <0.0, 0.0, -0.1>
		pigment { color Gray80 }
		finish { Smooth }
	}
}
#declare Eye = merge {
	object { Sphere scale <0.030, 0.030, 0.030>
		pigment { color White }
		finish { Smooth }
	}
	object { Sphere scale <0.008, 0.008, 0.002>
		translate -0.030*z
		pigment { color Blue }
		finish { Polished }
	}
}
#declare HeadMain = merge {
	object {		// 頭
		Sphere scale <0.1, 0.1, 0.125>
	}
	intersection {		// 顎
		object {
			Disk_Y scale <0.1, 0.15, 0.125>
		}
		object {
			Disk_X scale <0.1, 0.15, 0.125> translate -0.125*z
		}
		object {
			Cube translate <0.0, -1.0, -1.0>
		}
	}
}
#declare Head = merge {
	difference {
		object { HeadMain }
		object { Cube translate <0, -1, -1> rotate 25*x
			 translate <0.0, 0.0, -0.125 + 0.03> }
	}
	object { Eye translate <-0.035, -0.0025, -0.08> }
	object { Eye translate < 0.035, -0.0025, -0.08> }
/*
	object {		// 鼻
		Cone_Y scale <0.02, 0.03, 0.04>
		translate <0.0, -0.03, -0.125>
	}
*/
	object {		// 鼻
		Disk_Y scale <0.015, 0.04, 0.04>
		rotate 30*x
		translate <0.0, -0.04, -0.10>
	}
	object {		// 首
		Disk_Y scale <0.075, 0.1, 0.075>
		translate <0.0, -0.15, 0.0>
	}
	pigment { color Flesh }
	finish { Smooth }
	translate <0.0, 0.425, 0.0>
}

#declare Driver = merge {
	object {
		Head
	}
	object {		// 肩
		//Sphere scale <0.3, 0.1, 0.175>
		Sphere scale <0.25, 0.1, 0.175>
		translate <0.0, 0.15, 0.0>
	}
	object {		// 胴体
		//Disk_Y scale <0.3, 0.1, 0.175>
		Disk_Y scale <0.25, 0.1, 0.175>
		translate <0.0, 0.05, 0.0>
	}
	object {		// 右肩
		Sphere scale <0.08, 0.11, 0.125>
		translate <-0.25, 0.11, -0.05>
	}
	object {		// 左肩
		Sphere scale <0.08, 0.11, 0.125>
		translate < 0.25, 0.11, -0.05>
	}
	object {		// 右腕
		Disk_Z scale <0.05, 0.08, 0.3>
		//translate <-0.25, 0.10, -0.3>
		translate <-0.25, 0.08, -0.3>
	}
	object {		// 左腕
		Disk_Z scale <0.05, 0.08, 0.3>
		//translate < 0.25, 0.10, -0.3>
		translate < 0.25, 0.08, -0.3>
	}
	merge {			// 右手
		intersection {
			object { Sphere scale <0.06, 0.1, 0.10> }
			object { Cube translate 1*z }
		}
		object { Sphere scale <0.06, 0.1, 0.05> }
		translate <-0.25, 0.10, -0.6>
	}
	merge {			// 左手
		intersection {
			object { Sphere scale <0.06, 0.1, 0.10> }
			object { Cube translate 1*z }
		}
		object { Sphere scale <0.06, 0.1, 0.05> }
		translate < 0.25, 0.10, -0.6>
	}
/*
	object {		// 左手
		Sphere scale <0.06, 0.1, 0.09>
		translate < 0.25, 0.10, -0.6>
	}
*/
	object {		// ステアリングホイール
		StWheel
		translate < 0.0, 0.10, -0.6>
 	}
	translate <0.0, 0.0, 0.25>
	pigment { color Orange }
	finish { Smooth }
}

#declare Line = object {
	Cylinder_Z
	pigment {
		checker color White, color Red
		translate <0.5, 0.0, 0.0>
		scale <10.0, 1.0, 2.0>
	}
	finish { Smooth }
	scale <0.25, 0.1, 1.0>
	rotate z*180
}

#declare Fence = object {
	Plane_YZ
	double_illuminate
	clipped_by { Cylinder_Z scale 0.5 }
	pigment { color CadetBlue }
	finish {Smooth}
	translate 0.5*y
}

#declare GreenBelt = difference {
	object {
		Plane_XZ
		pigment {
//color ForestGreen
			dents
			color_map {
				[0.0 color ForestGreen]
				[0.2 color MediumForestGreen]
				[0.8 color Goldenrod]
			}
			scale 5
		}
//		finish { diffuse 0.5 specular 0.0 }
		finish { Smooth }
	}
//	clipped_by { Cylinder_Z scale 10.0 }
	object { Cylinder_Z scale 7.5 }
//	finish { Smooth }
}

//
// 地面
//
#declare Ground = merge {
	object {		// コース
		Plane_XZ
//		texture{T_Grnt18a}
		texture{T_Grnt1 finish { Smooth } }
		scale 0.01
		clipped_by { Cylinder_Z scale 7.5 }
	}
	object { GreenBelt }
	object { Line translate <-7.5, 0.0, 0.0> }
	object { Line translate < 7.5, 0.0, 0.0> }
	object { Fence translate <-20.0, 0.0, 0.0> }
	object { Fence translate < 20.0, 0.0, 0.0> }
}

//
// 空
//
#declare Sky = sky_sphere {
	pigment {
		bozo
		color_map {
			[ 0.2 color SkyBlue ]
			[ 0.8 White ]
		}
		scale <0.2, 0.05, 0.15>
	}
}

#declare Clear = sky_sphere {		// 快晴
	pigment {
		gradient y
		color_map{
			[ 0.0 color rgb <1.0, 1.0, 1.0> ]
			[ 0.3 color rgb <0.5, 0.7, 1.0> ]
		}
	}
}

#declare Fine = sky_sphere {		// 晴れ
	pigment{
		wrinkles
		color_map{
			[ 0.2 color White ]
			[ 0.8 color rgb <0.3, 0.4, 1.2>]
		}
		scale <1.0, 0.2, 1.0>
	}
}

#declare Cloudy = sky_sphere {		// 曇り
	pigment{
		wrinkles
		color_map{
			[ 0.2 color DarkSlateGray ]
			[ 0.8 color Gray80 ]
		}
		scale <1, 0.1, 1.0>
	}
}

#declare Sunset = sky_sphere {		// 夕焼け
	pigment {
		gradient y
		color_map{
			[ 0.0 color Orange ]
			[ 0.4 color rgb <0.3, 0.4, 1.2> ]
		}
	}
	pigment{
		wrinkles
		color_map{
			[ 0.3 color Gray50 filter 0.1 ]
			[ 0.7 color White filter 1.0 ]
		}
		scale <1.0, 0.2, 1.0>
	}
}

