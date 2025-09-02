// pictaro25.inc
// ピク太郎（ピクトグラム男）パーツ定義ファイル Ver.2025.06.30
// by yanagawa@kushiro-ct.ac.jp
/* 
2022.05.06: pictao.inc 誕生．
2022.05.16: 左右足位置算出．
	例：translate -LeftFootPos で左足を原点に移動（着地）
2022.05.17: 履物基準位置変更：足先→足首
2025.06.10: 体色変更機能追加．
	SetColor()により標準色を変更可能．
	胴体部以外を pigment で一括変更可能．
2025.06.11: 頭頸部可動化．Neck()，HeadNeck()，等追加．
2025.06.23: 肩部可動化．Chest，LtArm()，等追加．
2025.06.30: 諸々変更・調整し，pictaro25.inc に改名．
*/

#include "shapes.inc"		// 基本形状の組み込み
#include "colors.inc"		// 色名の組み込み

// 原点
#local o = <0, 0, 0>;

// 色
#declare Color1 = White;	// 胴体部（ゼッケン）の色
#declare Color2 = Navy;		// 標準の体色

// 標準色の変更機能
#declare CurTex = texture { }	// 現在の標準テクスチャ設定を記録
#macro SetColor(C)	// 標準色の変更
	#default { pigment { color C }}	
#end
#macro ResetColor()	// 標準テクスチャ設定の回復
	#default { texture { CurTex } }
#end
SetColor(Color2)

// 二軸回転
#macro Rot2(A, B) transform { rotate A rotate B } #end

// 三軸回転
#macro Rot3(A, B, C) transform { rotate A rotate B rotate C} #end

// 無（持物，履物，等）
#declare Null = union { }	// Warning出るが気にすんな

// 腕の寸法
#declare ArmR1 = 0.075;	// 根本部分（肩）の半径
#declare ArmR2 = ArmR1/2;	// 先端部分（手首／拳）の半径
#declare ArmSegL = 0.30;	// 各部の長さ

// 脚・腰の寸法
#declare LegR1 = 0.10;	// 根本部分（股）の半径
#declare LegR2 = LegR1/2;	// 先端部分（足首／踵）の半径
#declare LegSegL = 0.40;	// 各部の長さ
#declare HipW = LegR1*4 + 0.0;	// 腰の幅

// 手・足の寸法
#declare HandR = ArmR2;	// 拳の半径
#declare FootR = LegR2;	// 足の半径

// 胴の寸法
#declare TorsoH = 0.45;	// 胴の上下幅（腰-鎖骨の中心間）
#declare TorsoW1 = HipW - LegR1*0.5;	// 胴下側（腰部分）の横幅
#declare TorsoW2 = HipW + ArmR1*0.5;	// 胴上側（肩・胸部分）の横幅

#declare SHR = TorsoW2/TorsoW1;	// 肩幅／腰幅比（shoulder to hip ratio）
#declare TorsoD1 = LegR1*2;	// 胴下側（腰部分）の前後幅
#declare TorsoD2 = TorsoD1*SHR;	// 胴上側（胸部分）の前後幅

#declare ChestY = TorsoH;	// 胸のy座標（肩部，頭頸部の基準点）

// 頭・首の寸法
#declare HeadR = 0.15;	// 頭の半径
#declare NeckL = 0.25;	// 首の長さ（鎖骨〜頭の中心間）
#declare NeckR = 0.075;	// 首の半径

// 身長 = HeadR + NeckL + TorsoH + LegL = 1.70 [m]

// 部品の取り付け位置
#declare LegX = HipW/2 - LegR1;		// 脚のx座標
#declare ArmX = TorsoW2/2;		// 腕のx座標

// 頭の原型（基準点：中心）
#declare Head0 = object { Sphere scale HeadR }

// テスト用の立方体形の頭（基準点：中心）
#declare HeadCube = object { Cube scale HeadR*0.7 }

// 首の原型（基準点：鎖骨の中心）
//#declare Neck0 = object { Sphere scale <NeckR, NeckL, NeckR> }
#declare Neck0 = object { Round_Cone2(y*NeckL, NeckR*0.5, o, NeckR, 1) }

// 頭頸部（基準点：鎖骨の中心）
// HeadObj：頭のオブジェクト
// L：顔を傾げる角度（lean）	正なら右，負なら左
// R：顔を振る角度（rotate）	正なら右，負なら左
// T：顔を上げる角度（tilt）	正なら上，負なら下
// Eqp：頭に付ける用具等のオブジェクト
//// 頭部交換可能バージョン
#macro Neck(HeadObj, L, R, T)
union {
	object { Neck0 pigment { color Color1 } }
	object { HeadObj Rot3(L*z, R*y, T*x) translate NeckL*y }
}
#end
//// 用具交換可能バージョン
#macro HeadNeck(L, R, T, Eqp)
	object { Neck(union { object { Head0 } object { Eqp } }, L, R, T) }
#end
//// 標準の頭頸部（固定バージョン）
#declare Head = object { HeadNeck(0, 0, 0, Head0) }

/*
// 胴（基準点：腰の中心）
#declare Torso = object {
	Round_Cone2(y*TorsoH, TorsoD2/2, y*LegR1, TorsoD1/2, 0)
	scale <TorsoW2/TorsoD2, 1, 1>
	pigment { color Color1 }
}
*/
// 胴（基準点：胸の中心）
#declare Torso = object {
	Round_Cone2(o, TorsoD2/2, -y*(TorsoH-LegR1), TorsoD1/2, 0)
	scale <TorsoW2/TorsoD2, 1, 1>
	pigment { color Color1 }
}

// 腰（基準点：腰の中心）
#declare Hip = object { Disk_X scale <HipW/2-LegR1, LegR1, LegR1> }

// 腕の部品
#declare ArmR = (ArmR1 + ArmR2)/2;	// 中央部分の半径
#declare ArmL = ArmSegL*2 + ArmR2;	// 全体の長さ
#declare ArmSeg1 = object { Round_Cone2(0*y, ArmR1, -ArmSegL*y, ArmR, 0) }	// 上腕
#declare ArmSeg2 = object { Round_Cone2(0*y, ArmR, -ArmSegL*y, ArmR2, 0) }	// 前腕

// 腕の原型（基準点：肩関節中心）
#macro Arm0(A, Eqp)
union {
	object { ArmSeg1 }		// 上腕
	union {
		object { ArmSeg2 }		// 前腕
		object { Eqp translate -ArmSegL*y }	// 持物
		rotate A*x translate -ArmSegL*y	// 肘の屈曲
	}
	rotate -x*A/2		// 上腕を後へ引き，手を真下に
}
#end
// 左右の腕（基準点：胸の中心）
// A：肘を曲げる（腕を縮める）角度
// Y：肘を外へ張る（脇を開ける）角度
// Z：腕を横へ開く（羽ばたく）角度
// X：腕を前へ出す（腕を振る）角度
// Eqp：手に持つ用具等のオブジェクト
#macro LtArm(A, Y, Z, X, Eqp)
	object { Arm0(A, Eqp) Rot3(+Y*y, +Z*z, X*x) translate < ArmX, 0, 0> }
#end
#macro RtArm(A, Y, Z, X, Eqp)
	object { Arm0(A, Eqp) Rot3(-Y*y, -Z*z, X*x) translate <-ArmX, 0, 0> }
#end
/*
使用例：
LtArm(45, 0, -45, -90, object { Null })
RtArm(0, 0, 0, 90, object { Baton rotate 45 })
*/

// 脚の部品
#declare LegR = (LegR1 + LegR2)/2;	// 中央部分の半径
#declare LegL = LegSegL*2 + LegR2;	// 全体の長さ
#declare LegSeg1 = object { Round_Cone2(0*y, LegR1, -LegSegL*y, LegR, 0) }	// 大腿
#declare LegSeg2 = object { Round_Cone2(0*y, LegR, -LegSegL*y, LegR2, 0) }	// 下腿

// 脚の原型（基準点：股関節中心）
#macro Leg0(A, Eqp)
union {
	object { LegSeg1 }		// 大腿
	union {
		object { LegSeg2 }		// 下腿
//		object { Eqp translate -(LegSegL + LegR2)*y }	// 履物
		object { Eqp translate -LegSegL*y }	// 履物	ver20220517
		rotate -x*A translate -LegSegL*y	// 膝の屈曲
	}
	rotate x*A/2		// 大腿を上げ，足を真下に
}
#end
// 左右の脚
// A：膝を曲げる（脚を縮める）角度
// Y：膝を外へ張る（足の向きを変える）角度
// Z：脚を横へ開く角度
// X：脚を前へ出す角度
// Eqp：足に履く用具等のオブジェクト
#macro LtLeg(A, Y, Z, X, Eqp)
	object { Leg0(A, Eqp) Rot3(-Y*y, +Z*z, X*x) translate +LegX*x }
	#local R1 = LegSegL*2*cos(radians(A/2));
	#local R2 = R1*cos(radians(Z));
	#local PX = R1*sin(radians(Z)) + LegX;
#local PY = R2*cos(radians(X));
	#local PZ = R2*sin(radians(X));
	#declare LtAnklePos = <PX, -PY, -PZ>;		// 左足首の位置
	#declare LtFootPos = LtAnklePos - y*FootR;	// 左足の位置
#end
#macro RtLeg(A, Y, Z, X, Eqp)
	object { Leg0(A, Eqp) Rot3(+Y*y, -Z*z, X*x) translate -LegX*x }
	#local R1 = LegSegL*2*cos(radians(A/2));
	#local R2 = R1*cos(radians(Z));
	#local PX = R1*sin(radians(Z)) + LegX;
	#local PY = R2*cos(radians(X));
	#local PZ = R2*sin(radians(X));
	#declare RtAnklePos = <-PX, -PY, -PZ>;		// 右足首の位置
	#declare RtFootPos = RtAnklePos - y*FootR;	// 右足の位置
#end

// 上体の腰への連結
#declare ToUpper = transform { translate ChestY*y }

// 腰椎の動作
// T：捻り（正：右へ，負：左へ）
// B：曲げ（正：前屈，負：後屈）
#macro Lumbar(T, B)
	transform { translate ChestY*y Rot2(T*y, -B*x) }
#end

/*
// 選手全体の組み立て例
#declare Pictaro = union {
	union {			// 上半身
		object { Torso }		// 胴
		object { Neck(Head0, 0, 0, 0) Rot2(0*x, 0*y) }	// 頭頸部
		object { LtArm(0, 0, 0, 0, Null) Rot2(0*z, 0*y) }	// 左腕
		object { RtArm(0, 0, 0, 0, Null) Rot2(0*z, 0*y) }	// 右腕
		transform { ToUpper Rot2(0*y, 0*x) }
	}
	union {			// 下半身
		object { Hip }			// 腰
		object { LtLeg(0, 0, 0, 0, Null) }	// 左脚
		object { RtLeg(0, 0, 0, 0, Null) }	// 右脚
	}
	pigment { color Orange }	// 体色変更（Chestは白のまま）
	translate -LtFootPos	// 左足を原点に着ける
}
*/

