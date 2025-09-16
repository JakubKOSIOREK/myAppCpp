# README.md

## myApp\_C++

myApp\_C++ to prosta aplikacja okienkowa dla systemu Windows napisana w C++ z użyciem WinAPI. Aplikacja pobiera imię użytkownika, a następnie wyświetla komunikat powitalny w okienku dialogowym. Obsługuje polskie znaki i wykorzystuje domyślną czcionkę systemową Windows.

### 📌 Funkcje

* Okienkowy interfejs użytkownika (GUI) w WinAPI
* Pole tekstowe do wprowadzenia imienia
* Przycisk "OK" wywołujący okno dialogowe z powitaniem
* Obsługa polskich znaków (ą, ę, ó, ś, ł, ż, ź, ć, ń)

### 🛠 Wymagania

* Windows 10 / 11
* Visual Studio Build Tools 2022
* Kompilator Microsoft C++ (MSVC)
* VSCode (opcjonalnie, ale zalecane)

### 🏗 Instalacja środowiska

1. Pobierz i zainstaluj **Visual Studio Build Tools 2022**:
   [https://visualstudio.microsoft.com/downloads/](https://visualstudio.microsoft.com/downloads/)
2. W czasie instalacji wybierz komponenty:

   * MSVC (kompilator C++)
   * Windows 11 SDK
   * CMake (opcjonalnie)
3. Dodaj kompilator MSVC do ścieżki (jeśli nie jest automatycznie dostępny):

   ```sh
   call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" x64
   ```

### 🚀 Kompilacja i uruchomienie

#### 🔹 Kompilacja ręczna

1. Otwórz terminal `cmd` lub terminal w VSCode.
2. Przejdź do katalogu projektu:

   ```sh
   cd C:\Users\jakub\Development\myApp_C++
   ```
3. Uruchom kompilację:

   ```sh
   cl main.cpp /Fe:bin\myApp.exe /utf-8 /EHsc /DUNICODE /D_UNICODE /link /SUBSYSTEM:WINDOWS user32.lib gdi32.lib
   ```
4. Uruchom aplikację:

   ```sh
   bin\myApp.exe
   ```

#### 🔹 Kompilacja w VSCode (`Ctrl + Shift + B`)

1. Otwórz projekt w VSCode.
2. Wybierz `Terminal` → `Run Build Task` (`Ctrl + Shift + B`).
3. W terminalu powinien pojawić się komunikat `Build successful`.
4. Uruchom aplikację:

   ```sh
   bin\myApp.exe
   ```
