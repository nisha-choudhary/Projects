@echo off
cls
echo =================================================================================

echo ===== 1. Checking for Requirement number 3, 4 and 7 with /s option and patterns ===== 
echo ===== Command:Debug\Executive.exe test_folder *.cpp *.h *.bat /s *.txt ===== 
"Debug\Executive.exe" "test_folder" "*.cpp" "*.h" "*.bat" "/s" "*.txt"

cls
echo ===== 2. Checking for Requirement number 3 , 4 and 7 without command ======
echo ===== Command: ===== 
"Debug\Executive.exe"

cls
echo ===== 3. Checking for Requirement number 3 , 4 and 7  without pattern provided ===== 
echo ===== Command:Debug\Executive.exe test_folder "/s"  ===== 
"Debug\Executive.exe" "test_folder" "/s"

cls
echo ===== 4. Checking for Requirement number 3 , 4 and 7 With only Path given ===== 
echo ===== Command:Debug\Executive.exe test_folder ===== 
"Debug\Executive.exe" "test_folder"

cls
echo ===== 5. Checking for Requirement number 3 , 4 and 5 with /s and /d option ===== 
echo ===== Command:Debug\Executive.exe test_folder *.cpp *.h *.bat /s /d ===== 
"Debug\Executive.exe" "test_folder" "*.cpp" "*.h" "*.bat" "/s" "/d"

cls
echo ===== 6. Checking for Requirement number 3 , 4 and 7 without /s option ===== 
echo ===== Command:Debug\Executive.exe test_folder *.cpp *.h  ===== 
"Debug\Executive.exe" "test_folder" "*.cpp" "*.h" *.bat *.txt

cls
echo ===== 7. Checking for Requirement number 3, 4 , 5 , 6 and 7  ===== 
echo ===== Command:Debug\Executive.exe test_folder *.cpp *.h /s /d (/f"main") *.bat *.txt ===== 
"Debug\Executive.exe" "test_folder" "*.cpp" "*.h" "/s" "/d" "/f\"main\"" *.bat *.txt

cls
echo ===== 8. Checking for Requirement number 3, 4 , 5 , 6 and 7  Searching wrong text ===== 
echo ===== Command:Debug\Executive.exe test_folder *.cpp *.h /s /d (/f" wrong search text ") ===== 
"Debug\Executive.exe" "test_folder" "*.cpp" "*.h" "/s" "/d" "/f\" wrong search text \""

cls
echo ===== 9. Checking for Requirement number 3 , 4 and 5 without /s but /d option ===== 
echo ===== Command:Debug\Executive.exe test_folder *.cpp *.h /d *.bat *.txt ===== 
"Debug\Executive.exe" "test_folder" "*.cpp" "*.h" "/d" "*.bat" "*.txt"

cls
echo ===== 10. Checking for Requirement number 7 with no option provided (not /f and not /d) ===== 
echo ===== Command:Debug\Executive.exe test_folder *.cpp *.h *.bat *.txt ===== 
"Debug\Executive.exe" "test_folder" "*.cpp" "*.h" "*.bat" "*.txt"

cls
echo ===== 11. Checking for Requirement number 3 , 4 and 6  /f search text ===== 
echo ===== Command:Debug\Executive.exe test_folder *.cpp *.h *.bat *.txt /s (/f"main") ===== 
"Debug\Executive.exe" "test_folder" "*.cpp" "*.h" "*.bat" "*.txt" "/s" "/f\"main\""
