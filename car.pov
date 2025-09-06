#include "colors.inc"
#include "textures.inc"

// カメラの設定
camera {
  location <5, 3, -10>
  look_at  <0, 1, 0>
  angle 35
}

// 光源の設定
light_source { <100, 100, -100> color White }
light_source { <-100, 100, -100> color White*0.5 }

// 地面
plane { y, 0
  pigment { color Gray70 }
  finish { reflection 0.1 }
}

// 車のボディ
difference {
  box { <-2.5, 0.5, -1.2>, <2.5, 1.8, 1.2> }
  box { <-1.5, 1.2, -1.3>, <1.5, 2, 1.3> }
  box { <-3, 0.8, -0.8>, <3, 1.2, 0.8> rotate y*10 }
  
  texture {
    pigment { color Red }
    finish {
      phong 0.8
      reflection 0.3
      metallic
    }
  }
  scale <1.2, 1, 1>
}

// 窓ガラス
box { <-1.4, 1.25, -1.1>, <1.4, 1.7, 1.1>
  texture {
    pigment { color rgbt <0.1, 0.1, 0.1, 0.8> }
    finish {
      reflection 0.5
      phong 1
    }
  }
}

// タイヤ
#declare Wheel =
union {
  // タイヤ部分
  cylinder { <0, -0.2, 0>, <0, 0.2, 0>, 0.8 }

  // ホイール部分
  cylinder { <0, -0.25, 0>, <0, 0.25, 0>, 0.5 
    texture { Silver_Metal }
  }

  // タイヤ全体のテクスチャ
  texture {
    pigment { color Black }
    finish { phong 0.1 }
  }
  
  // タイヤ全体の回転
  rotate x*90
}

// タイヤの配置
object { Wheel translate <-2, 0.8, 1.2> }
object { Wheel translate <2, 0.8, 1.2> }
object { Wheel translate <-2, 0.8, -1.2> }
object { Wheel translate <2, 0.8, -1.2> }