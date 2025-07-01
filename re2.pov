// ロータリーエンジンのローター（Reuleaux三角形の近似）
camera {
  location <0, 0, -40>
  look_at  <0, 0, 0>
}

light_source {
  <50, 50, -100>
  color rgb <1, 1, 1>
}

background { color rgb <0, 0, 0> }

#declare Rotor = union {
  // 三辺を円弧で構成（Reuleaux三角形のような外形）
  difference {
    // 全体を球で削り出す
    intersection {
      sphere { <5.77, -10, 0>, 20 }
      sphere { <-5.77, -10, 0>, 20 }
      sphere { <0, 11.55, 0>, 20 }
    }
    box { <-50, -50, -5>, <50, 50, -6> } // 底面削除（厚み調整）
  }

  // 中心のシャフト
  cylinder {
    <0, 0, -2>, <0, 0, 2>, 1.5
  }

  // 材質
  pigment { color rgb <0.8, 0.2, 0.2> }
  finish { phong 0.7 reflection 0.1 }
}

object { Rotor rotate <0, 0, 0> }

