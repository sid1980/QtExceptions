# QtExceptionsライブラリ

- [![ubuntu_ci](https://github.com/DIODEELEGIA/QtExceptions/actions/workflows/ubuntu_ci.yml/badge.svg)](https://github.com/DIODEELEGIA/QtExceptions/actions/workflows/ubuntu_ci.yml)
- [![windows_ci](https://github.com/DIODEELEGIA/QtExceptions/actions/workflows/windows_ci.yml/badge.svg)](https://github.com/DIODEELEGIA/QtExceptions/actions/workflows/windows_ci.yml)

# 備考

本ライブラリはQExceptionを用いた自作例外クラスのライブラリである。

# 使用例

---

- RunTimeErrorクラス

本例外クラスはC++stlの一つであるstd::runtime_errorクラスをQt風に書いたクラスである。

注意:whatメソッドの戻り値はQStringではなくconst char*であるためwindowsで使用する場合

日本語を使用すると文字化けを起こすためエラー内容は英語で書かねばならない。

```c++
#include <QtExceptions/qt_exceptions.hpp>
#include <QTextStream>

QTextStream qcout(stdout);

void happend()noexcept(false)
{
    auto err = QtExceptions::RunTimeError("test");
	err.raise();
}

int main()
{
	try
	{
		happend();
	}catch(const QtExceptions::RunTimeError& err)
	{
		qcout << err.what() << Qt::endl;
	}
}
```

---

## ビルドやリンク

ビルド方法

```term
cd [本ライブラリへのパス]
mkdir ./build
cd ./build
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX="path/to/install/this/library"
ninja
```


---

## インストール方法

```term
ninja install
```


---

## 詳細単体テスト方法

```term
	ctest -V
```

or

```term
	ctest QtExceptionsTest -V
```



---

## 簡易単体テスト方法

```term
	ctest
```

or

```term
	ctest QtExceptionsTest
```



---

## CMakeを用いたリンク方法

本ライブラリをCMakeを用いてリンクするにはインストール後

```CMakeLists.txt
	find_package(QtExceptions REQUIRED)
	target_link_libraries(target PRIVATE QtExceptions)
```

を使用するかインストールせずにadd_subdirectoryコマンドで本プロジェクトのディレクトリを
呼び出して上記同様target_link_librariesでリンクすればよい。

