#include "shapes.inc"
#include "colors.inc"

camera {
  location <0, 0, -50>
  look_at  <0, 0, 0>
}

light_source {
  <100, 100, -100>
  color rgb <1, 1, 1>
}

// トロコイド内で回転するローター（近似形）
#declare Rotor = union {
  // 三辺を円弧で構成
  difference {
    // 円弧を3つ配置して近似的にローター形状を作成
    merge {
      torus { 10, 1 rotate <0, 0, 0> translate <5.77, -10, 0> }
      torus { 10, 1 rotate <0, 0, 120> translate <-5.77, -10, 0> }
      torus { 10, 1 rotate <0, 0, 240> translate <0, 11.55, 0> }
    }
    box { <-50, -50, -5>, <50, 50, -6> } // 底を切って厚み調整
  }

  // 中央の軸
  cylinder {
    <0, 0, -2>, <0, 0, 2>, 1.5
  }

  // 色・材質
  pigment { color rgb <0.8, 0.2, 0.2> }
  finish { phong 0.8 reflection 0.1 }
}

object { Rotor }

