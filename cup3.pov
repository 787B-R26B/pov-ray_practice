// POV-Rayで簡単なコップを作成するサンプルコード

#version 3.7;
global_settings{ assumed_gamma 1.0 }

#include "colors.inc"
#include "textures.inc"

// ----------------------------------------
// カメラ（視点）の設定
// ----------------------------------------
camera {
  location  <10.0, 6.0, -10.0> // カメラの位置
  look_at   <0.0, 1.5,  0.0> // カメラが見つめる中心点
  angle     35                // 画角
}

// ----------------------------------------
// 光源の設定
// ----------------------------------------
light_source {
  <15, 30, -20>
  color White
}

// ----------------------------------------
// 床（平面）の設置
/*/ ----------------------------------------

plane {
  y, 0 // y=0の位置に無限の平面を定義
  pigment {
    checker color White, color Gray70 // 白とグレーの市松模様
    scale 2
  }
}

*/
background { color LightBlue }
// ----------------------------------------
// コップの作成
// ----------------------------------------

// --- 1. ガラスの質感を定義 ---
#declare Glass_Material = material {
  texture {
    pigment { color rgbt <1, 1, 1, 0.95> } // 色(Red,Green,Blue,Transmit) Tは透明度
    finish {
      ambient 0.1
      diffuse 0.1
      specular 0.9   // ハイライトの強さ
      roughness 0.001 // ハイライトのシャープさ
      reflection {    // 反射
        0.05, 1.0
        fresnel on
      }
    }
  }
  interior {
    ior 1.5 // ガラスの屈折率 (Index of Refraction)
  }
}

// --- 2. オブジェクトの形状を定義 ---

// コップの外側の形状 (円錐台)
#declare Cup_Outer = cone {
  <0, 0, 0>, 1.2    // 底面の中心座標と半径
  <0, 3, 0>, 1.5    // 上面の中心座標と半径
}

// コップの内側の形状（くり抜くための形状）
#declare Cup_Inner = cone {
  <0, 0.2, 0>, 1.0  // 底面を少し上げ、厚みを持たせる
  <0, 3, 0>, 1.4    // 上面の半径を外側より少し小さくする
}

// --- 3. 差分演算でコップを作成 ---
difference {
  object { Cup_Outer } // このオブジェクトから
  object { Cup_Inner } // このオブジェクトをくり抜く

  // 作成したオブジェクトに質感と位置を設定
  material { Glass_Material }
  translate <0, 0.01, 0> // 床からわずかに浮かせる
}