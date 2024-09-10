#include <stdio.h>
#include <math.h>

#define COULOMB_CONSTANT 8.9875517923e9 // クーロン定数 (N·m²/C²)

// 原子構造体
typedef struct {
    int atomicNumber; // 原子番号
    double atomicMass; // 原子質量 (グラム/モル)
    double charge; // 電荷 (クーロン)
} Element;

// 原子核構造体
typedef struct {
    double charge; // 原子核の電荷 (クーロン)
    double mass;   // 原子核の質量 (キログラム)
} Nucleus;

// 電子構造体
typedef struct {
    double charge; // 電子の電荷 (クーロン)
    double mass;   // 電子の質量 (キログラム)
    double radius; // 電子の軌道半径 (メートル)
} Electron;

// 原子構造体
typedef struct {
    Element element; // 元素情報
    Nucleus nucleus; // 原子核
    Electron electron; // 電子
} Atom;

// 電子の運動エネルギー計算関数
double calculateKineticEnergy(Electron *e) {
    // 電子の運動エネルギーを半径と質量を用いて単純化して計算
    return 0.5 * e->mass * pow(1 / e->radius, 2);
}

// 電子のポテンシャルエネルギー計算関数
double calculatePotentialEnergy(Electron *e, Nucleus *n) {
    // クーロンの法則を用いてポテンシャルエネルギーを計算
    return -COULOMB_CONSTANT * e->charge * n->charge / e->radius;
}

// 元素情報を出力する関数
void printElementInfo(Element elem, const char* name) {
    printf("元素: %s\n", name);
    printf("原子番号: %d\n", elem.atomicNumber);
    printf("原子質量: %.3f g/mol\n", elem.atomicMass);
    printf("電荷: %.2e C\n\n", elem.charge);
}

int main() {
    // 主要な元素と微量元素の情報設定
    Element elements[] = {
        {8, 15.999, 1.602e-19},  // 酸素 (O)
        {6, 12.011, 1.602e-19},  // 炭素 (C)
        {1, 1.008, 1.602e-19},   // 水素 (H)
        {7, 14.007, 1.602e-19},  // 窒素 (N)
        {20, 40.078, 1.602e-19}, // カルシウム (Ca)
        {15, 30.974, 1.602e-19}, // リン (P)
        {19, 39.098, 1.602e-19}, // カリウム (K)
        {16, 32.06, 1.602e-19},  // 硫黄 (S)
        {11, 22.990, 1.602e-19}, // ナトリウム (Na)
        {17, 35.45, 1.602e-19},  // 塩素 (Cl)
        {12, 24.305, 1.602e-19}, // マグネシウム (Mg)
        {26, 55.845, 1.602e-19}, // 鉄 (Fe)
        {30, 65.38, 1.602e-19},  // 亜鉛 (Zn)
        {29, 63.546, 1.602e-19}, // 銅 (Cu)
        {25, 54.938, 1.602e-19}, // マンガン (Mn)
        {53, 126.90, 1.602e-19}, // ヨウ素 (I)
        {34, 78.971, 1.602e-19}, // セレン (Se)
        {42, 95.95, 1.602e-19},  // モリブデン (Mo)
        {24, 51.996, 1.602e-19}, // クロム (Cr)
        {27, 58.933, 1.602e-19}, // コバルト (Co)
        {9, 18.998, 1.602e-19}   // フッ素 (F)
    };

    // 電子の軌道半径設定 (単純化された例)
    double electronRadius = 5.29e-11; // ボーア半径 (メートル)

    // 元素の総数
    int numElements = sizeof(elements) / sizeof(elements[0]);

    // 元素の総情報出力
    printf("人間を構成する元素情報:\n\n");

    for (int i = 0; i < numElements; i++) {
        Element elem = elements[i];
        Atom atom = {elem, {elem.charge, 1.67e-27}, {-elem.charge, 9.11e-31, electronRadius}};

        // 元素情報出力
        printElementInfo(elem, "元素");

        // エネルギー計算
        double kineticEnergy = calculateKineticEnergy(&atom.electron);
        double potentialEnergy = calculatePotentialEnergy(&atom.electron, &atom.nucleus);

        // 結果出力
        printf("元素: %s\n", "元素");
        printf("電子の運動エネルギー: %.2e J\n", kineticEnergy);
        printf("電子のポテンシャルエネルギー: %.2e J\n\n", potentialEnergy);
    }

    // 元素の総数出力
    printf("総元素数: %d\n", numElements);

    return 0;
}
