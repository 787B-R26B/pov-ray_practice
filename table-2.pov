#include "shapes.inc"
#include "colors.inc"
#include "textures.inc"
#include "woods.inc"
#include "metals.inc" // 金属テクスチャ用に追記

global_settings { charset utf8 }

// ---- マテリアル定義 --------------------------------------------------
// 質感の異なる素材を material として定義します。

// ① 天然木のマテリアル（半光沢）
#declare M_Wood = material {
  texture {
    T_Wood21        // 温かみのある木目テクスチャ
    scale <0.2, 1, 1> // 木目のスケールを調整
    rotate y*90
  }
  finish {
    specular 0.4    // 適度な光沢
    roughness 0.05
    reflection 0.05 // 弱い反射
  }
}

// ② 川に見立てたレジン（樹脂）のマテリアル（透明で光沢が強い）
#declare M_Resin = material {
  texture {
    pigment {
      color rgbt <0.1, 0.4, 0.8, 0.75> // 少し青みがかった透明色 (Red, Green, Blue, Transmit)
    }
  }
  finish {
    specular 0.9    // 強い光沢
    roughness 0.001
    reflection 0.25 // 強めの反射
    ior 1.5         // 屈折率（ガラスに近い値）
  }
}

// ③ スチール製の脚のマテリアル（金属光沢）
#declare M_Steel = material {
  texture {
    pigment { color Gray20 }
  }
  finish {
    F_MetalA        // 金属的な強いハイライト
  }
}


// ---- パーツ定義 -----------------------------------------------------

// ■■■ オリジナルテーブルの定義 ■■■

// テーブルの脚（スチール製の角脚）
#declare Steel_Leg = box {
  <-0.04, 0, -0.4>, <0.04, 0.7, 0.4>
  material { M_Steel }
}

// リバーテーブルの天板
#declare River_Table_Top = union {
  // 左側のウッドスラブ
  box { <-0.6, 0.7, -0.4>, <-0.1, 0.8, 0.4> material { M_Wood } }
  // 右側のウッドスラブ
  box { < 0.1, 0.7, -0.4>, < 0.6, 0.8, 0.4> material { M_Wood } }
  // 中央のレジン（川）
  box { <-0.1, 0.7, -0.4>, < 0.1, 0.8, 0.4> material { M_Resin } }
}

// テーブル本体の組み立て
#declare River_Table = union {
  object { River_Table_Top }
  object { Steel_Leg translate x * -0.45 }
  object { Steel_Leg translate x * 0.45 }
}


// ■■■ オリジナル椅子の定義 ■■■

// 椅子の座面
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


// ---- シーン ---------------------------------------------------------

// 作成したオブジェクトの配置
object { River_Table }
object { Matching_Stool translate <-0.5, 0, -0.5> rotate y*30 }
object { Matching_Stool translate < 0.5, 0, -0.5> rotate y*20 }

// 床
plane { y, 0 pigment { checker color Gray80 color Gray90 } }

// 座標軸 (デバッグ用に残しても良い)
/*
merge {
    object { Cylinder_X scale 0.02 pigment { color Red } }
    object { Cylinder_Y scale 0.02 pigment { color Green } }
    object { Cylinder_Z scale 0.02 pigment { color Blue } }
}
*/

// 背景
background { color SkyBlue }

// 照明
light_source {
    <10, 15, -20>
    color White*1.5
}
// 影を柔らかくするための補助光
light_source {
    <-10, 5, 20>
    color White*0.5
    shadowless // この光源は影を落とさない
}


// カメラ
camera{
    location <0, 1.8, -3.0>     // カメラの位置を調整
    look_at <0.0, 0.4, 0.0>     // 注目先を少し低く調整
    angle 25                    // 視野角を調整
}