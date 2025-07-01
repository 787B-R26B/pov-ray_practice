// 簡単なノートパソコンのPOV-Rayシーン

camera {
  location <0, 5, 15>
  look_at  <0, 0, 0>
}

light_source {
  <10, 20, -20>
  color rgb <1, 1, 1>
}

// 背景色
background {
  color rgb <0.8, 0.9, 1.0>
}

// キーボード部分（底面）
box {
  <-5, 0, -3>, <5, 0.5, 3>
  texture {
    pigment { color rgb <0.2, 0.2, 0.2> }
    finish { phong 0.6 }
  }
}

// 画面部分（上部）
box {
  <-5, 0.5, -0.2>, <5, 6, 0.2>
  rotate <60, 0, 0> // 60度に傾けて開いた状態に
  translate <0, 0.5, -3>
  texture {
    pigment { color rgb <0.1, 0.1, 0.1> }
    finish { phong 0.6 }
  }
}

// 簡易な画面表示（模擬ディスプレイ）
box {
  <-4.5, 1.0, 0.01>, <4.5, 5.5, 0.02>
  rotate <60, 0, 0>
  translate <0, 0.5, -3>
  texture {
    pigment { color rgb <0.0, 0.6, 1.0> } // 青っぽい画面
    finish { diffuse 0.7 }
  }
}

