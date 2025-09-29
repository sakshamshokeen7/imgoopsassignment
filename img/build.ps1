# Build script for imgoops project (PowerShell)
Param(
    [string]$Out = "app.exe"
)

# gather source .cpp files inside the "cpp files" folder
$srcFiles = Get-ChildItem -Path "cpp files" -Filter "*.cpp" | ForEach-Object { "`"$($_.FullName)`"" }
$src = $srcFiles -join ' '
$cmd = "g++ -std=c++17 -Iheaders -Wall -Wextra -g $src `"main.cpp`" -o $Out"
Write-Host "Running: $cmd"
Invoke-Expression $cmd
if ($LASTEXITCODE -eq 0) { Write-Host "Build succeeded: $Out" } else { Write-Host "Build failed with exit code $LASTEXITCODE" }
