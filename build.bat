@echo off
echo Компиляция программы с использованием C++20...
g++ -std=c++23 -o output/program.exe %1

if %errorlevel% neq 0 (
    echo.
    echo ОШИБКА КОМПИЛЯЦИИ!
    pause
    exit /b
)

echo.
echo ===== ЗАПУСК ПРОГРАММЫ =====
program.exe
echo.
echo ============================
echo Программа завершилась с кодом %errorlevel%
pause   
